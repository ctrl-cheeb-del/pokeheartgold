#include "field/field_follow_mon.h"

#include "global.h"

#include "constants/global_fieldmap.h"
#include "constants/movements.h"
#include "constants/scrcmd.h"
#include "constants/sprites.h"

#include "field/field_effect_helpers.h"
#include "field/map_object_billboard_motion.h"
#include "field/map_object_models.h"
#include "field/map_object_render.h"
#include "field/map_object_render_internal.h"
#include "field/resource_bank.h"

#include "field_follow_mon_ball.h"
#include "field_system.h"
#include "field_terrain.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_follow_internal.h"
#include "map_object_movement_commands.h"
#include "map_object_movement_commands_internal.h"
#include "overlay_01.h"
#include "overlay_25.h"
#include "palette.h"
#include "party.h"
#include "player_avatar.h"
#include "poke_overlay.h"
#include "scrcmd.h"
#include "script.h"
#include "script_manager.h"
#include "script_pokemon_util.h"
#include "sys_task_api.h"
#include "task.h"
#include "texture_animation.h"
#include "vram_transfer_manager.h"

FS_EXTERN_OVERLAY(OVY_25);

// MapObject_GetParam(object, 1) of a following Pokemon: three nibbles of its tp_param entry.
#define FOLLOW_MON_PARAM_SHAPE 1
// MapObject_GetParam(object, 2) of a following Pokemon, bit 0.
#define FOLLOW_MON_PARAM_FLAGS 2

#define BILLBOARD_SEQUENCE_FOLLOW_MON     21
#define BILLBOARD_SEQUENCE_FOLLOW_MON_ALT 22

// A billboard sequence from the sequence bank: count frames, then count u8s, then count u8 flags.
typedef struct BillboardSequenceData {
    int count;
    u16 frames[1];
} BillboardSequenceData;

typedef struct HopHeightTable {
    fx32 heights[3][16];
} HopHeightTable;

typedef struct HopOffsets {
    u8 offsets[8];
} HopOffsets;

typedef struct HopMovements {
    u32 movements[2];
} HopMovements;

typedef struct HopTable {
    HopOffsets yOffsets;
    HopMovements movements;
} HopTable;

typedef struct SepiaBillboardTransfer {
    NNSG3dResFileHeader *file;
    void *texture;
    u16 palette[16];
} SepiaBillboardTransfer;

typedef struct FollowMonHopIntoBall {
    u8 state;
    u8 step;
    u8 timer;
    u8 movement;
    u8 unk_04[64];
    BOOL toLeft;
} FollowMonHopIntoBall;

typedef struct FollowMonRecall {
    int timer;
    u16 palette[32];
} FollowMonRecall;

typedef struct FollowMonFlash {
    s8 blend;
    u8 step;
    u8 delay;
    u8 period;
    u16 original[32];
    u16 blended[32];
} FollowMonFlash;

extern const MovementList gFollowMonFastMovements;
extern const MovementList gFollowMonSlowMovements;
extern const MovementList gFollowMonStepMovements;
extern const MovementList gFollowMonRunMovements;
extern const HopHeightTable gFollowMonHopHeights;
extern const HopOffsets gFollowMonHopIntoBallZOffsets;

const HopTable sFollowMonHopIntoBallTable = {
    { 1, 2, 2, 3, 3, 2, 2, 0 },
    { 14, 12 }
};

static void SepiaBillboardTransfer_FreeWhenDone(SysTask *task, void *data);
static BOOL Task_FollowMonHopIntoBall(TaskManager *taskMan);
static u32 FollowMonHopIntoBall_GetSide(FieldSystem *fieldSystem, FollowMonHopIntoBall *env);
static BOOL Task_FollowMonRecall(TaskManager *taskMan);
static BOOL Task_FollowMonHideForFieldMove(TaskManager *taskMan);
static BOOL Task_FollowMonFlash(TaskManager *taskMan);

static u8 FollowMon_GetShapeParamHigh(LocalMapObject *object);
static void MapObject_StepTowards(LocalMapObject *target, LocalMapObject *object);
static int SpriteId_GetModelNo(u32 spriteId);
BOOL ScrCmd_TrainerHouseBattle(ScriptContext *ctx) {
    u16 trainerNum = FieldSystem_VarGet(ctx->fieldSystem, ScriptReadHalfword(ctx));
    FSOverlayID overlay = FS_OVERLAY_ID(OVY_25);
    HandleLoadOverlay(overlay, OVY_LOAD_ASYNC);
    TrainerHouse_StartBattle(ctx->fieldSystem, trainerNum);
    UnloadOverlayByID(overlay);
    return TRUE;
}

// On leaving a map: FollowMon_RecreateForMap re-creates or drops the following Pokemon on the next one.
void FollowMon_MarkForRecreate(FieldSystem *fieldSystem) {
    fieldSystem->followMon.recreatePending = TRUE;
}

// The next faster movement in direction after movement (8-11, then steps 12-15, runs 16-19, 20-23).
u32 FollowMon_GetFasterMovement(u32 direction, u32 movement) {
    MovementList slow = gFollowMonSlowMovements;
    MovementList step = gFollowMonStepMovements;
    MovementList run = gFollowMonRunMovements;
    MovementList fast = gFollowMonFastMovements;
    u8 i;
    for (i = 0; i < DIR_MAX; i++) {
        if (movement == slow.movements[i]) {
            return step.movements[direction];
        }
    }
    for (i = 0; i < DIR_MAX; i++) {
        if (movement == step.movements[i]) {
            return run.movements[direction];
        }
    }
    for (i = 0; i < DIR_MAX; i++) {
        if (movement == run.movements[i]) {
            return fast.movements[direction];
        }
    }
    GF_ASSERT(FALSE);
    return 0;
}

fx32 FollowMon_GetHopHeight(LocalMapObject *object) {
    HopHeightTable table = gFollowMonHopHeights;
    LocalMapObject *mapObject = object;
    u8 row = FollowMon_GetShapeParamHigh(mapObject);
    s32 index;
    u8 column;
    if (row != 0) {
        return 0;
    }
    column = FollowPlayerMovement_GetHopSpeed(mapObject);
    if (column == 0) {
        return 0;
    }
    index = FollowPlayerMovement_GetHopFrame(mapObject);
    GF_ASSERT(index < 16);
    column--;
    return table.heights[column][index];
}

BOOL MapObject_IsShinyPokemon(LocalMapObject *object) {
    u32 id = MapObject_GetID(object);
    if (id != obj_partner_poke && id != obj_daycare_poke_1 && id != obj_daycare_poke_2) {
        return FALSE;
    }
    return MapObject_GetParam(object, FOLLOW_MON_PARAM_FLAGS) & 1;
}

BOOL MapObject_HasFollowMonSprite(LocalMapObject *object) {
    int spriteId = MapObject_GetSpriteID(object);
    return spriteId >= SPRITE_FOLLOWER_MON && spriteId <= SPRITE_FOLLOWER_MON_6;
}

static u8 FollowMon_GetShapeParamHigh(LocalMapObject *object) {
    u16 shape = MapObject_GetParam(object, FOLLOW_MON_PARAM_SHAPE);
    if (MapObject_GetID(object) != obj_partner_poke) {
        return 0;
    }
    return ((u8)shape >> 4) & 0xF;
}

u8 FollowMon_GetShapeParamLow(LocalMapObject *object) {
    u16 shape = MapObject_GetParam(object, FOLLOW_MON_PARAM_SHAPE);
    if (MapObject_GetID(object) != obj_partner_poke) {
        return 0;
    }
    return (u8)shape & 0xF;
}

// Nonzero for a large following Pokemon (its own billboards, pulled while it shrinks into its ball).
u8 FollowMonObject_IsLarge(LocalMapObject *object) {
    u16 shape = MapObject_GetParam(object, FOLLOW_MON_PARAM_SHAPE);
    if (MapObject_GetID(object) != obj_partner_poke) {
        return 0;
    }
    return (shape >> 8) & 0xF;
}

// The tile behind the object.
void MapObject_GetCoordsBehind(LocalMapObject *object, int *x, int *z) {
    u8 direction = MapObject_GetFacingDirection(object);
    *x = MapObject_GetXCoord(object);
    *z = MapObject_GetZCoord(object);
    switch (direction) {
    case DIR_NORTH:
        (*z)++;
        break;
    case DIR_SOUTH:
        (*z)--;
        break;
    case DIR_WEST:
        (*x)++;
        break;
    case DIR_EAST:
        (*x)--;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

// The tile behind the object's previous position.
void MapObject_GetPreviousCoordsBehind(LocalMapObject *object, int *x, int *z) {
    u8 direction = MapObject_GetFacingDirection(object);
    *x = MapObject_GetPreviousXCoord(object);
    *z = MapObject_GetPreviousZCoord(object);
    switch (direction) {
    case DIR_NORTH:
        (*z)++;
        break;
    case DIR_SOUTH:
        (*z)--;
        break;
    case DIR_WEST:
        (*x)++;
        break;
    case DIR_EAST:
        (*x)--;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

// The metatile behavior of a tile next to the object: 0/1 the tile north/south of it, 2/3 east/west of it,
// 4/5 south-east/south-west of it.
u32 MapObject_GetAdjacentTileBehavior(LocalMapObject *object, u32 direction) {
    FieldSystem *fieldSystem = MapObject_GetFieldSystem(object);
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    switch (direction) {
    case 0:
        z--;
        break;
    case 1:
        z++;
        break;
    case 3:
        x--;
        break;
    case 2:
        x++;
        break;
    case 4:
        x++;
        z++;
        break;
    case 5:
        x--;
        z++;
        break;
    }
    return GetMetatileBehavior(fieldSystem, x, z);
}

// Puts object one tile from anchor in direction, facing facing.
void MapObject_SetPositionNextTo(LocalMapObject *anchor, LocalMapObject *object, u32 direction, u32 facing) {
    VecFx32 position;
    MapObject_CopyPositionVector(anchor, &position);
    switch (direction) {
    case DIR_NORTH:
        position.z -= FX32_ONE * 16;
        break;
    case DIR_SOUTH:
        position.z += FX32_ONE * 16;
        break;
    case DIR_EAST:
        position.x += FX32_ONE * 16;
        break;
    case DIR_WEST:
        position.x -= FX32_ONE * 16;
        break;
    }
    MapObject_SetPositionFromVectorAndDirection(object, &position, facing);
}

void FollowMon_SpawnReleaseBall(LocalMapObject *object) {
    FollowMonBall_Spawn(object, FOLLOW_MON_BALL_RELEASE);
}

void FollowMon_MoveToPlayer(FieldSystem *fieldSystem, u8 direction) {
    VecFx32 position;
    LocalMapObject *followMon;
    if (FollowMon_IsActive(fieldSystem)) {
        followMon = FollowMon_GetMapObject(fieldSystem);
        MapObject_CopyPositionVector(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), &position);
        MapObject_SetPositionFromVectorAndDirection(followMon, &position, direction);
    }
}

BOOL FollowMon_CheckVisibleFlag(FieldSystem *fieldSystem) {
    return MapObject_CheckInvisible(FollowMon_GetMapObject(fieldSystem));
}

void FollowMon_SetNoBallEffect(FieldSystem *fieldSystem) {
    FollowPlayerMovement_DisableBallEffect(FollowMon_GetMapObject(fieldSystem));
}

void FollowMon_SetAltSequenceFrameFlags(MapObjectManager *manager) {
    MapObjectRender *render = MapObjectManager_GetRender(manager);
    BillboardSequenceData *sequence = ResourceBank_Get(render->sequenceBank, BILLBOARD_SEQUENCE_FOLLOW_MON_ALT);
    int count = sequence->count, i;
    u8 *flags = (u8 *)(sequence->frames + count);
    flags += count;
    for (i = 0; i < count; i++) {
        flags[i] = 1;
    }
}

void FollowMonBillboard_SetResource(BOOL alternate, LocalMapObject *object, BillboardObject *billboard) {
    BillboardResource resource;
    MapObjectManager *manager = MapObject_GetManager(object);
    u32 spriteId = MapObject_GetSpriteID(object);
    MapObjectRender_GetBillboardResource(manager, spriteId, &resource);
    {
        u32 id = MapObject_GetID(object);
        if (id != obj_partner_poke && id != obj_daycare_poke_1 && id != obj_daycare_poke_2) {
            return;
        }
        FollowMonBillboard_InitSequence(alternate, object, billboard, &resource);
        BillboardObject_SetResource(billboard, &resource);
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(MapObject_GetFacingDirection(object)));
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
}

void FollowMonBillboard_InitSequence(BOOL alternate, LocalMapObject *object, BillboardObject *billboard, BillboardResource *resource) {
    MapObjectRender *render = MapObjectManager_GetRender(MapObject_GetManager(object));
    BillboardSequenceData *sequence = ResourceBank_Get(render->sequenceBank, alternate ? BILLBOARD_SEQUENCE_FOLLOW_MON_ALT : BILLBOARD_SEQUENCE_FOLLOW_MON);
    BillboardGfxSequence_Init(sequence, &resource->gfxSequence);
}

// Reloads the billboard's palette from the object's model file in sepia and re-uploads its texture.
void MapObject_SetBillboardSepia(BOOL unused, LocalMapObject *object, BillboardObject *billboard) {
    SepiaBillboardTransfer *transfer = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(SepiaBillboardTransfer));
    NNSG3dResTex *texture;
    void *palette;
    u32 texKey;
    int member;
    MI_CpuFill8(transfer, 0, 4);
    member = SpriteId_GetModelNo(((u32)MapObject_GetParam(object, FOLLOW_MON_PARAM_FLAGS) << 15) >> 16);
    transfer->file = NARC_AllocAndReadWholeMember(MapObjectManager_GetMapModelNarc(MapObject_GetManager(object)), member, HEAP_ID_FIELD2);
    texture = NNS_G3dGetTex(transfer->file);
    palette = Texture_GetPaletteData(texture, 0);
    transfer->texture = Texture_GetImageData(texture, 0);
    MIi_CpuCopy16(palette, transfer->palette, sizeof(transfer->palette));
    TintPalette_GrayScale(transfer->palette, 16);
    TintPalette_CustomTone(transfer->palette, 16, 256, 180, 0);
    GF_CreateNewVramTransferTask(NNS_GFD_DST_3D_TEX_PLTT, NNS_GfdGetPlttKeyAddr(BillboardObject_GetPlttKey(billboard)), transfer->palette, sizeof(transfer->palette));
    texKey = BillboardObject_GetTexKey(billboard);
    GF_CreateNewVramTransferTask(NNS_GFD_DST_3D_TEX_VRAM, NNS_GfdGetTexKeyAddr(BillboardObject_GetTexKey(billboard)), transfer->texture, ((texKey & 0x7FFF0000) >> 16) * 16);
    SysTask_CreateOnVWaitQueue(SepiaBillboardTransfer_FreeWhenDone, transfer, 0);
}

// Frees the sepia transfer once the VRAM transfers are done.
static void SepiaBillboardTransfer_FreeWhenDone(SysTask *task, void *data) {
    SepiaBillboardTransfer *transfer = data;
    if (GF_GetNumPendingVramTransferTasks() == 0) {
        SysTask_Destroy(task);
        Heap_Free(transfer->file);
        Heap_Free(transfer);
    }
}

// The player's step (movement from x, z) for the following Pokemon to repeat.
void FollowMon_QueuePlayerStep(int movement, int x, int z, FollowMon *followMon) {
    followMon->queuedMovement = movement;
    followMon->queuedX = x;
    followMon->queuedZ = z;
    if (followMon->queuedStepState == 3) {
        followMon->queuedStepState = 2;
    } else if (followMon->queuedStepState == 0) {
        followMon->queuedStepState = 1;
    }
}

// On entering a map: re-creates the following Pokemon next to the player, or removes it where it may not follow.
void FollowMon_RecreateForMap(FieldSystem *fieldSystem) {
    if (fieldSystem->followMon.recreatePending) {
        if (!fieldSystem->followMon.active) {
            int x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
            int z = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
            u32 direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
            FollowMon_InitMapObject(fieldSystem->mapObjectManager, x, z, direction, fieldSystem->location->mapId);
            {
                u8 active = fieldSystem->followMon.active;
                LocalMapObject *mapObject = fieldSystem->followMon.mapObject;
                if (active == TRUE) {
                    FollowMonBillboard_ResetPalette(mapObject);
                }
            }
        } else {
            int species = FollowMon_GetSpecies(fieldSystem->followMon.mapObject);
            if (!FollowMon_GetPermissionBySpeciesAndMap(species, fieldSystem->location->mapId)) {
                MapObject_Remove(fieldSystem->followMon.mapObject);
                fieldSystem->followMon.active = FALSE;
            }
        }
    }
    fieldSystem->followMon.recreatePending = FALSE;
}

void FollowMon_SetHeight(FieldSystem *fieldSystem, fx32 y) {
    VecFx32 position;
    LocalMapObject *mapObject;
    if (FollowMon_IsActive(fieldSystem)) {
        mapObject = FollowMon_GetMapObject(fieldSystem);
        MapObject_CopyPositionVector(mapObject, &position);
        position.y = y;
        MapObject_SetPositionVector(mapObject, &position);
    }
}

// Lets the following Pokemon finish its current movement (pausing it again if it was paused).
enum WaitFollowMonMovementState {
    WAIT_MOVEMENT_STATE_START,
    WAIT_MOVEMENT_STATE_WAIT_AND_PAUSE,
    WAIT_MOVEMENT_STATE_WAIT,
};

enum FollowMonHopState {
    HOP_STATE_START,
    HOP_STATE_WAIT_STOP,
    HOP_STATE_MOVE_ASIDE,
    HOP_STATE_FACE_UP,
    HOP_STATE_JUMP,
    HOP_STATE_SPAWN_BALL,
    HOP_STATE_WAIT_BALL,
    HOP_STATE_END,
};

enum FollowMonRecallState {
    RECALL_STATE_START,
    RECALL_STATE_WAIT_STOP,
    RECALL_STATE_SPAWN_BALL,
    RECALL_STATE_WAIT_BALL,
    RECALL_STATE_END,
};

enum FollowMonHideState {
    HIDE_STATE_RESET,
    HIDE_STATE_STEP_TO_PLAYER,
    HIDE_STATE_FACE_LIKE_PLAYER,
    HIDE_STATE_WAIT,
    HIDE_STATE_HIDE,
    HIDE_STATE_SPAWN_BALL,
    HIDE_STATE_END,
};

enum FollowMonFlashState {
    FLASH_STATE_LOAD_PALETTE,
    FLASH_STATE_FADE_TO_WHITE,
    FLASH_STATE_FADE_BACK,
    FLASH_STATE_END,
};

BOOL Task_WaitFollowMonMovement(TaskManager *taskMan) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskMan);
    u32 *state = TaskManager_GetStatePtr(taskMan);
    LocalMapObject *mapObject;
    if (!FollowMon_IsActive(fieldSystem)) {
        return TRUE;
    }
    mapObject = fieldSystem->followMon.mapObject;
    switch (*state) {
    case WAIT_MOVEMENT_STATE_START:
        if (MapObject_CheckMovementPaused(mapObject)) {
            MapObject_UnpauseMovement(mapObject);
            *state = WAIT_MOVEMENT_STATE_WAIT_AND_PAUSE;
        } else {
            *state = WAIT_MOVEMENT_STATE_WAIT;
        }
        break;
    case WAIT_MOVEMENT_STATE_WAIT_AND_PAUSE:
        if (MapObject_IsMovementPaused(mapObject) && MapObject_AreBitsSetForMovementScriptInit(mapObject)) {
            MapObject_PauseMovement(mapObject);
            return TRUE;
        }
        break;
    case WAIT_MOVEMENT_STATE_WAIT:
        if (MapObject_IsMovementPaused(mapObject) && MapObject_AreBitsSetForMovementScriptInit(mapObject)) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void FollowMon_StartHopIntoBall(FieldSystem *fieldSystem) {
    FollowMonHopIntoBall *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FollowMonHopIntoBall));
    env->state = HOP_STATE_START;
    env->step = 0;
    env->timer = 0;
    env->movement = 0;
    TaskManager_Call(fieldSystem->taskman, Task_FollowMonHopIntoBall, env);
}

static BOOL Task_FollowMonHopIntoBall(TaskManager *taskMan) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskMan);
    FollowMonHopIntoBall *env = TaskManager_GetEnvironment(taskMan);
    LocalMapObject *mapObject;
    HopMovements movements;
    HopOffsets zOffsets, yOffsets;
    VecFx32 position, scale;
    int delta;
    switch (env->state) {
    case HOP_STATE_START:
        if (!FollowMon_IsActive(fieldSystem)) {
            Heap_Free(env);
            return TRUE;
        }
        if (FollowMon_CheckVisibleFlag(fieldSystem)) {
            Heap_Free(env);
            return TRUE;
        }
        MapObject_UnpauseMovement(FollowMon_GetMapObject(fieldSystem));
        env->state++;
    case HOP_STATE_WAIT_STOP:
        if (MapObject_IsMovementPaused(FollowMon_GetMapObject(fieldSystem))) {
            env->state = FollowMonHopIntoBall_GetSide(fieldSystem, env);
        }
        break;
    case HOP_STATE_MOVE_ASIDE: {
        movements = sFollowMonHopIntoBallTable.movements;
        mapObject = FollowMon_GetMapObject(fieldSystem);
        if (!MapObject_IsMovementPaused(mapObject)) {
            break;
        }
        MapObject_SetHeldMovement(mapObject, movements.movements[env->movement++]);
        if (env->movement >= 2) {
            env->state++;
        }
        break;
    }
    case HOP_STATE_FACE_UP:
        mapObject = FollowMon_GetMapObject(fieldSystem);
        if (!MapObject_IsMovementPaused(mapObject)) {
            break;
        }
        MapObject_SetHeldMovement(mapObject, MOVEMENT_FACE_UP);
        env->state++;
        break;
    case HOP_STATE_JUMP: {
        zOffsets = gFollowMonHopIntoBallZOffsets;
        yOffsets = sFollowMonHopIntoBallTable.yOffsets;
        mapObject = FollowMon_GetMapObject(fieldSystem);
        delta = FX32_ONE * 2;
        if (!env->toLeft) {
            delta *= -1;
        }
        MapObject_CopyPositionVector(mapObject, &position);
        position.z -= ((s8)zOffsets.offsets[env->step]) * FX32_ONE;
        position.x += delta;
        position.y += ((s8)yOffsets.offsets[env->step]) * FX32_ONE;
        MapObject_SetPositionVector(mapObject, &position);
        env->step++;
        if (env->step >= 8) {
            env->state++;
        }
        break;
    }
    case HOP_STATE_SPAWN_BALL:
        FollowMonBall_Spawn(FollowMon_GetMapObject(fieldSystem), FOLLOW_MON_BALL_RECALL);
        env->state++;
        break;
    case HOP_STATE_WAIT_BALL: {
        env->timer++;
        if (env->timer < 20) {
            break;
        }
        FollowMon_MoveToPlayer(fieldSystem, DIR_NORTH);
        scale = gFollowMonHopIntoBallScale;
        BillboardObject_SetScale(MapObjectManager_GetFollowMonBillboard(fieldSystem->mapObjectManager), &scale);
        FollowMon_SetReleaseBallPending(fieldSystem->followMon.mapObject, 1);
        env->state++;
        break;
    }
    case HOP_STATE_END:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

// Which side of the player the following Pokemon is on: below it (it moves aside first), or left/right of it.
static u32 FollowMonHopIntoBall_GetSide(FieldSystem *fieldSystem, FollowMonHopIntoBall *env) {
    int playerX = MapObject_GetXCoord(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar));
    int playerZ = MapObject_GetZCoord(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar));
    int x = MapObject_GetXCoord(FollowMon_GetMapObject(fieldSystem));
    int z = MapObject_GetZCoord(FollowMon_GetMapObject(fieldSystem));
    if (x == playerX && z == playerZ + 1) {
        env->toLeft = TRUE;
        return HOP_STATE_MOVE_ASIDE;
    }
    if (x == playerX + 1 && z == playerZ) {
        env->toLeft = FALSE;
        return HOP_STATE_FACE_UP;
    }
    if (x + 1 == playerX && z == playerZ) {
        env->toLeft = TRUE;
        return HOP_STATE_FACE_UP;
    }
    GF_ASSERT(FALSE);
    return HOP_STATE_MOVE_ASIDE;
}

// Puts the following Pokemon into its Poke Ball (it turns white and shrinks); FALSE if there is nothing to do.
BOOL FollowMon_StartRecall(FieldSystem *fieldSystem) {
    FollowMonRecall *env;
    if (!FollowMon_IsActive(fieldSystem)) {
        return FALSE;
    }
    if (FollowMon_CheckVisibleFlag(fieldSystem)) {
        FollowMon_Hide(fieldSystem);
        FollowMon_MoveToPlayer(fieldSystem, DIR_NORTH);
        return FALSE;
    }
    env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FollowMonRecall));
    env->timer = 0;
    TaskManager_Call(fieldSystem->taskman, Task_FollowMonRecall, env);
    return TRUE;
}

static BOOL Task_FollowMonRecall(TaskManager *taskMan) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskMan);
    FollowMonRecall *env = TaskManager_GetEnvironment(taskMan);
    u32 *state = TaskManager_GetStatePtr(taskMan);
    switch (*state) {
    case RECALL_STATE_START:
        MapObject_UnpauseMovement(FollowMon_GetMapObject(fieldSystem));
        (*state)++;
    case RECALL_STATE_WAIT_STOP:
        if (MapObject_IsMovementPaused(FollowMon_GetMapObject(fieldSystem))) {
            (*state)++;
        }
        break;
    case RECALL_STATE_SPAWN_BALL: {
        LocalMapObject *mapObject = FollowMon_GetMapObject(fieldSystem);
        int member = SpriteId_GetModelNo(MapObject_GetSpriteID(mapObject));
        NNSG3dResFileHeader *file = NARC_AllocAndReadWholeMember(MapObjectManager_GetMapModelNarc(fieldSystem->mapObjectManager), member, HEAP_ID_FIELD2);
        NNSG3dResTex *texture = NNS_G3dGetTex(file);
        MIi_CpuCopy16((u16 *)((u8 *)texture + texture->plttInfo.ofsPlttData), env->palette, sizeof(env->palette));
        Heap_Free(file);
        FollowMonBall_Spawn(mapObject, FOLLOW_MON_BALL_RECALL_WHITE);
        (*state)++;
        break;
    }
    case RECALL_STATE_WAIT_BALL:
        env->timer++;
        if (env->timer >= 20) {
            VecFx32 scale;
            BillboardObject *billboard;
            u32 plttKey, plttAddr;
            FollowMon_MoveToPlayer(fieldSystem, DIR_NORTH);
            scale = gFollowMonRecallScale;
            billboard = MapObjectManager_GetFollowMonBillboard(fieldSystem->mapObjectManager);
            BillboardObject_SetScale(billboard, &scale);
            plttKey = BillboardObject_GetPlttKey(billboard);
            plttAddr = BillboardObject_GetPlttKey(billboard);
            GF_CreateNewVramTransferTask(NNS_GFD_DST_3D_TEX_PLTT, NNS_GfdGetPlttKeyAddr(plttAddr), env->palette, ((plttKey & 0xFFFF0000) >> 16) << 3);
            FollowMon_Hide(fieldSystem);
            FollowMon_SetPendingHop(FollowMon_GetMapObject(fieldSystem), 0);
            (*state)++;
        }
        break;
    case RECALL_STATE_END:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void FollowMon_StartHideForFieldMove(TaskManager *taskMan) {
    int *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(int));
    *env = 0;
    TaskManager_Call(taskMan, Task_FollowMonHideForFieldMove, env);
}

static BOOL Task_FollowMonHideForFieldMove(TaskManager *taskMan) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskMan);
    int *timer = TaskManager_GetEnvironment(taskMan);
    u32 *state = TaskManager_GetStatePtr(taskMan);
    switch (*state) {
    case HIDE_STATE_RESET:
        FollowPlayerMovement_Reset(fieldSystem->followMon.mapObject);
        MapObject_CallDrawUpdate(fieldSystem->followMon.mapObject);
        ++*state;
        break;
    case HIDE_STATE_STEP_TO_PLAYER:
        if (MapObject_AreBitsSetForMovementScriptInit(fieldSystem->followMon.mapObject) == TRUE) {
            MapObject_StepTowards(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), fieldSystem->followMon.mapObject);
            ++*state;
        }
        break;
    case HIDE_STATE_FACE_LIKE_PLAYER:
        if (MapObject_AreBitsSetForMovementScriptInit(fieldSystem->followMon.mapObject) == TRUE) {
            MapObject_SetFacingDirection(fieldSystem->followMon.mapObject, MapObject_GetFacingDirection(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar)));
            ++*state;
        }
        break;
    case HIDE_STATE_WAIT:
        if (++*timer > 10) {
            ++*state;
        }
        break;
    case HIDE_STATE_HIDE:
        if (MapObject_AreBitsSetForMovementScriptInit(fieldSystem->followMon.mapObject) == TRUE) {
            FollowMon_SetInvisibleFlag(fieldSystem->followMon.mapObject, FALSE);
            MapObject_SetHeldMovement(fieldSystem->followMon.mapObject, GetMovementForDirection(MapObject_GetFacingDirection(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar)), 52));
            ++*state;
        }
        break;
    case HIDE_STATE_SPAWN_BALL:
        if (MapObject_AreBitsSetForMovementScriptInit(fieldSystem->followMon.mapObject) == TRUE) {
            FollowMonBall_Spawn(fieldSystem->followMon.mapObject, FOLLOW_MON_BALL_BURST);
            FollowMon_Hide(fieldSystem);
            ++*state;
        }
        break;
    case HIDE_STATE_END:
        Heap_Free(timer);
        return TRUE;
    }
    return FALSE;
}

// Starts object walking one tile towards target.
static void MapObject_StepTowards(LocalMapObject *target, LocalMapObject *object) {
    int targetX = MapObject_GetXCoord(target);
    int targetZ = MapObject_GetZCoord(target);
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    int dx = targetX - x;
    int dz = targetZ - z;
    MapObject_GetFacingDirection(target);
    if (dx < 0) {
        MapObject_SetHeldMovement(object, 10);
    } else if (dx > 0) {
        MapObject_SetHeldMovement(object, 11);
    } else if (dz < 0) {
        MapObject_SetHeldMovement(object, 8);
    } else if (dz > 0) {
        MapObject_SetHeldMovement(object, 9);
    }
}

static int SpriteId_GetModelNo(u32 spriteId) {
    int modelNo = GetMoveModelNoBySpriteId(spriteId);
    if (modelNo < 0) {
        GF_ASSERT(FALSE);
        modelNo = 0;
    }
    return modelNo;
}

void FollowMon_SetFacingDirection(FieldSystem *fieldSystem, u32 direction) {
    if (FollowMon_IsActive(fieldSystem)) {
        MapObject_SetFacingDirection(fieldSystem->followMon.mapObject, direction);
    }
}

// Fades the following Pokemon's palette to white and back, step per change every period + 1 frames.
BOOL FollowMon_StartFlash(FieldSystem *fieldSystem, u8 step, u8 period) {
    FollowMonFlash *env;
    if (!FollowMon_IsActive(fieldSystem)) {
        return FALSE;
    }
    if (FollowMon_CheckVisibleFlag(fieldSystem)) {
        return FALSE;
    }
    if (step == 0) {
        return FALSE;
    }
    env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FollowMonFlash));
    MI_CpuFill8(env, 0, sizeof(FollowMonFlash));
    env->step = step;
    env->period = period;
    TaskManager_Call(fieldSystem->taskman, Task_FollowMonFlash, env);
    return TRUE;
}

static BOOL Task_FollowMonFlash(TaskManager *taskMan) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskMan);
    FollowMonFlash *env = TaskManager_GetEnvironment(taskMan);
    u32 *state = TaskManager_GetStatePtr(taskMan);
    switch (*state) {
    case FLASH_STATE_LOAD_PALETTE: {
        int member = SpriteId_GetModelNo(MapObject_GetSpriteID(FollowMon_GetMapObject(fieldSystem)));
        NNSG3dResFileHeader *file = NARC_AllocAndReadWholeMember(MapObjectManager_GetMapModelNarc(fieldSystem->mapObjectManager), member, HEAP_ID_FIELD2);
        NNSG3dResTex *texture = NNS_G3dGetTex(file);
        MIi_CpuCopy16((u16 *)((u8 *)texture + texture->plttInfo.ofsPlttData), env->original, sizeof(env->original));
        Heap_Free(file);
        (*state)++;
        break;
    }
    case FLASH_STATE_FADE_TO_WHITE:
        if (env->delay) {
            env->delay--;
        } else {
            BillboardObject *billboard;
            u32 plttKey, plttAddr;
            env->blend += env->step;
            if (env->blend >= 16) {
                env->blend = 16;
                (*state)++;
            }
            BlendPalette(env->original, env->blended, 32, env->blend, 0xFFFF);
            billboard = MapObjectManager_GetFollowMonBillboard(fieldSystem->mapObjectManager);
            plttKey = BillboardObject_GetPlttKey(billboard);
            plttAddr = BillboardObject_GetPlttKey(billboard);
            GF_CreateNewVramTransferTask(NNS_GFD_DST_3D_TEX_PLTT, NNS_GfdGetPlttKeyAddr(plttAddr), env->blended, ((plttKey & 0xFFFF0000) >> 16) * 8);
            env->delay = env->period;
        }
        break;
    case FLASH_STATE_FADE_BACK:
        if (env->delay) {
            env->delay--;
        } else {
            BillboardObject *billboard;
            u32 plttKey, plttAddr;
            env->blend -= env->step;
            if (env->blend <= 0) {
                (*state)++;
            }
            BlendPalette(env->original, env->blended, 32, env->blend, 0xFFFF);
            billboard = MapObjectManager_GetFollowMonBillboard(fieldSystem->mapObjectManager);
            plttKey = BillboardObject_GetPlttKey(billboard);
            plttAddr = BillboardObject_GetPlttKey(billboard);
            GF_CreateNewVramTransferTask(NNS_GFD_DST_3D_TEX_PLTT, NNS_GfdGetPlttKeyAddr(plttAddr), env->blended, ((plttKey & 0xFFFF0000) >> 16) * 8);
            env->delay = env->period;
        }
        break;
    case FLASH_STATE_END:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

BOOL FollowMon_IsNextToPlayer(FieldSystem *fieldSystem) {
    LocalMapObject *player, *followMon;
    int x, z, followX, followZ;
    if (!FollowMon_IsVisible(fieldSystem)) {
        return FALSE;
    }
    player = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    followMon = fieldSystem->followMon.mapObject;
    x = MapObject_GetXCoord(player);
    z = MapObject_GetZCoord(player);
    followX = MapObject_GetXCoord(followMon);
    followZ = MapObject_GetZCoord(followMon);
    if (x == followX) {
        if (z + 1 == followZ || z - 1 == followZ) {
            return TRUE;
        }
    } else if (z == followZ) {
        if (x + 1 == followX || x - 1 == followX) {
            return TRUE;
        }
    }
    return FALSE;
}

u8 FieldSystem_GetLeadMonIndex(FieldSystem *fieldSystem) {
    return GetIdxOfFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
}
