#include "global.h"

#include "constants/sprites.h"
#include "constants/std_script.h"

#include "field/field_effect_helpers.h"
#include "field/map_object_models.h"
#include "field/map_object_render.h"

#include "field_apricorn_regrowth.h"
#include "field_effects.h"
#include "field_emote_mark.h"
#include "field_system.h"
#include "field_time_events.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_behavior.h"
#include "map_object_behavior_internal.h"
#include "map_object_movement_commands.h"
#include "map_object_movement_commands_internal.h"
#include "map_object_movement_utilities.h"
#include "map_object_movement_utilities_internal.h"
#include "overlay_01.h"
#include "player_avatar.h"
#include "script_manager.h"
#include "sys_task_api.h"

static void MapObject_CallTypeBehaviorInit(LocalMapObject *object);
static BOOL MapObject_CallTypeBehaviorCheck(LocalMapObject *object);
static BOOL MapObject_CallTypeBehaviorUpdate(LocalMapObject *object);
static BOOL MapObject_IsOffPreviousTile(LocalMapObject *object);
static BOOL MapObject_IsOnPreviousTile(LocalMapObject *object);
static u32 GetApricornTreeSpriteId(int apricorn, int apricornCount);
static BOOL CheckSeenByNpcTrainers(FieldSystem *fieldSystem, MapObjectManager *manager, PlayerAvatar *avatar, LocalMapObject *exclude, EngageParams *out);
static void GetEngagingTrainerParams(EngageParams *out, LocalMapObject *object, int x, int z);
static int MapObject_GetTrainerSightType(LocalMapObject *object);
static int TrainerSight_FindPlayer(LocalMapObject *object, PlayerAvatar *player, int *outDir);
static int TrainerSight_GetDistanceInDirection(LocalMapObject *object, u32 direction, int range, int targetX, int targetZ, int unused);
static int TrainerSight_GetDistanceNorth(LocalMapObject *object, int range, int targetX, int targetZ, int unused);
static int TrainerSight_GetDistanceSouth(LocalMapObject *object, int range, int targetX, int targetZ, int unused);
static int TrainerSight_GetDistanceWest(LocalMapObject *object, int range, int targetX, int targetZ, int unused);
static int TrainerSight_GetDistanceEast(LocalMapObject *object, int range, int targetX, int targetZ, int unused);
static BOOL TrainerSight_IsPathBlocked(LocalMapObject *object, u32 direction, int distance);
static u32 MapObject_GetTrainerNum(LocalMapObject *object);
static LocalMapObject *MapObjectManager_FindTrainerPartner(FieldSystem *unused, MapObjectManager *manager, LocalMapObject *exclude, u32 trainerNum);
static SysTask *TrainerApproach_CreateTask(FieldSystem *fieldSystem, LocalMapObject *trainer, PlayerAvatar *player, int movement, int remaining, int unk10, int encounterType, int trainerIndex);
static BOOL TrainerApproach_GetDone(SysTask *task);
static void TrainerApproach_DestroyTask(SysTask *task);
static void TrainerApproach_Task(SysTask *task, void *data);
static BOOL TrainerApproach_UnpauseTrainer(TrainerApproachWork *work);
static BOOL TrainerApproach_FaceDirection(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitForPlayer(TrainerApproachWork *work);
static BOOL TrainerApproach_StartFace(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitFace(TrainerApproachWork *work);
static BOOL TrainerApproach_SpawnExclamation(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitExclamation(TrainerApproachWork *work);
static BOOL TrainerApproach_StartReveal(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitReveal(TrainerApproachWork *work);
static BOOL TrainerApproach_Wait(TrainerApproachWork *work);
static BOOL TrainerApproach_CheckDistance(TrainerApproachWork *work);
static BOOL TrainerApproach_StartStep(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitStep(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitArrived(TrainerApproachWork *work);
static BOOL TrainerApproach_TurnPlayer(TrainerApproachWork *work);
static BOOL TrainerApproach_WaitPlayerTurn(TrainerApproachWork *work);
static BOOL TrainerApproach_ResetTrainerMovement(TrainerApproachWork *work);
static BOOL TrainerApproach_Finish(TrainerApproachWork *work);

static const TrainerSightFunc sTrainerSightDistanceFuncs[] = {
    TrainerSight_GetDistanceNorth,
    TrainerSight_GetDistanceSouth,
    TrainerSight_GetDistanceWest,
    TrainerSight_GetDistanceEast,
};

enum TrainerApproachState {
    TRAINER_APPROACH_UNPAUSE_TRAINER,
    TRAINER_APPROACH_FACE_DIRECTION,
    TRAINER_APPROACH_WAIT_FOR_PLAYER,
    TRAINER_APPROACH_START_FACE,
    TRAINER_APPROACH_WAIT_FACE,
    TRAINER_APPROACH_SPAWN_EXCLAMATION,
    TRAINER_APPROACH_WAIT_EXCLAMATION,
    TRAINER_APPROACH_START_REVEAL,
    TRAINER_APPROACH_WAIT_REVEAL,
    TRAINER_APPROACH_WAIT,
    TRAINER_APPROACH_CHECK_DISTANCE,
    TRAINER_APPROACH_START_STEP,
    TRAINER_APPROACH_WAIT_STEP,
    TRAINER_APPROACH_WAIT_ARRIVED,
    TRAINER_APPROACH_TURN_PLAYER,
    TRAINER_APPROACH_WAIT_PLAYER_TURN,
    TRAINER_APPROACH_RESET_TRAINER_MOVEMENT,
    TRAINER_APPROACH_FINISH,
};

static const TrainerApproachStateFunc sTrainerApproachStateFuncs[] = {
    TrainerApproach_UnpauseTrainer,
    TrainerApproach_FaceDirection,
    TrainerApproach_WaitForPlayer,
    TrainerApproach_StartFace,
    TrainerApproach_WaitFace,
    TrainerApproach_SpawnExclamation,
    TrainerApproach_WaitExclamation,
    TrainerApproach_StartReveal,
    TrainerApproach_WaitReveal,
    TrainerApproach_Wait,
    TrainerApproach_CheckDistance,
    TrainerApproach_StartStep,
    TrainerApproach_WaitStep,
    TrainerApproach_WaitArrived,
    TrainerApproach_TurnPlayer,
    TrainerApproach_WaitPlayerTurn,
    TrainerApproach_ResetTrainerMovement,
    TrainerApproach_Finish,
};

void MapObject_InitTypeBehavior(LocalMapObject *object) {
    MapObject_CallTypeBehaviorInit(object);
}

BOOL MapObject_UpdateTypeBehavior(LocalMapObject *object) {
    if (!MapObject_CallTypeBehaviorCheck(object)) {
        return FALSE;
    }
    if (MapObject_CallTypeBehaviorUpdate(object)) {
        return TRUE;
    }
    return FALSE;
}

static void MapObject_CallTypeBehaviorInit(LocalMapObject *object) {
    gMapObjectTypeBehaviorInits[MapObject_GetType(object)](object);
}

static BOOL MapObject_CallTypeBehaviorCheck(LocalMapObject *object) {
    return gMapObjectTypeBehaviorChecks[MapObject_GetType(object)](object);
}

static BOOL MapObject_CallTypeBehaviorUpdate(LocalMapObject *object) {
    return gMapObjectTypeBehaviorUpdates[MapObject_GetType(object)](object);
}

static BOOL MapObject_IsOffPreviousTile(LocalMapObject *object) {
    int x = MapObject_GetXCoord(object);
    if (x != MapObject_GetPreviousXCoord(object)) {
        return TRUE;
    }
    x = MapObject_GetZCoord(object);
    if (x != MapObject_GetPreviousZCoord(object)) {
        return TRUE;
    }
    return FALSE;
}

static BOOL MapObject_IsOnPreviousTile(LocalMapObject *object) {
    int x = MapObject_GetXCoord(object);
    if (x != MapObject_GetPreviousXCoord(object)) {
        return FALSE;
    }
    x = MapObject_GetZCoord(object);
    if (x == MapObject_GetPreviousZCoord(object)) {
        return TRUE;
    }
    return FALSE;
}

void TypeBehavior_NoOpInit(LocalMapObject *object) {
}

int TypeBehavior_NoOpCheck(LocalMapObject *object) {
    return 0;
}

int TypeBehavior_NoOpUpdate(LocalMapObject *object) {
    return 0;
}

enum TrainerCheckState {
    TRAINER_CHECK_STATE_WAIT_OFF_TILE,
    TRAINER_CHECK_STATE_WAIT_ON_TILE,
    TRAINER_CHECK_STATE_WAIT_MOVEMENT,
    TRAINER_CHECK_STATE_READY,
};

enum TrainerTurnState {
    TRAINER_TURN_STATE_INIT,
    TRAINER_TURN_STATE_TURN,
    TRAINER_TURN_STATE_WAIT_TURN,
    TRAINER_TURN_STATE_PAUSE,
};

void TypeBehavior_LookSidewaysInit(LocalMapObject *object) {
    TrainerBehaviorState *state = MapObject_InitBehaviorData(object, sizeof(TrainerBehaviorState));
    state->limit = MapObject_GetParam(object, 1);
}

BOOL TypeBehavior_LookSidewaysCheck(LocalMapObject *object) {
    TrainerBehaviorState *state = MapObject_GetBehaviorData(object);
    switch (state->state) {
    case TRAINER_CHECK_STATE_WAIT_OFF_TILE:
        if (MapObject_IsOffPreviousTile(object) == TRUE) {
            state->state++;
        }
        break;
    case TRAINER_CHECK_STATE_WAIT_ON_TILE:
        if (!MapObject_IsOnPreviousTile(object)) {
            break;
        }
        state->count++;
        if (state->count < state->limit) {
            state->state = TRAINER_CHECK_STATE_WAIT_OFF_TILE;
            break;
        }
        state->state++;
    case TRAINER_CHECK_STATE_WAIT_MOVEMENT:
        if (MapObject_CheckSingleMovement(object) == TRUE) {
            break;
        }
        state->state++;
        state->count = 0;
        state->turnState = TRAINER_TURN_STATE_INIT;
    case TRAINER_CHECK_STATE_READY:
        return TRUE;
    }
    return FALSE;
}

BOOL TypeBehavior_LookSidewaysUpdate(LocalMapObject *object) {
    TrainerBehaviorState *state = MapObject_GetBehaviorData(object);
    switch (state->turnState) {
    case TRAINER_TURN_STATE_INIT: {
        FourValues dirTable = gLookSidewaysAxisByFacing;
        u32 dir = MapObject_GetFacingDirection(object);
        state->direction = dir;
        state->sequence = dirTable.values[dir];
        state->turnState++;
    }
    case TRAINER_TURN_STATE_TURN: {
        TwoByTwoValues moveTable = gLookSidewaysDirections;
        MapObject_ForceSetHeldMovement(object, GetMovementForDirection(moveTable.values[state->sequence][state->index], MOVEMENT_FACE_UP));
        state->turnState++;
    }
    case TRAINER_TURN_STATE_WAIT_TURN:
        if (!MapObject_RunForcedMovement(object)) {
            return TRUE;
        }
        state->turnState++;
    case TRAINER_TURN_STATE_PAUSE:
        state->timer++;
        if (state->timer < 8) {
            return TRUE;
        }
        state->timer = 0;
        state->turns++;
        if (state->turns < 4) {
            state->index = (state->index + 1) & 1;
            state->turnState = TRAINER_TURN_STATE_TURN;
            return TRUE;
        }
        MapObject_SetFacingDirection(object, state->direction);
        state->turnState++;
        state->turns = 0;
        state->state = TRAINER_CHECK_STATE_WAIT_OFF_TILE;
    }
    return FALSE;
}

void TypeBehavior_SpinInit(LocalMapObject *object) {
    TrainerBehaviorState *state = MapObject_InitBehaviorData(object, sizeof(TrainerBehaviorState));
    state->limit = MapObject_GetParam(object, 1);
    state->sequence = (MapObject_GetType(object) != 5);
}

BOOL TypeBehavior_SpinCheck(LocalMapObject *object) {
    TrainerBehaviorState *state = MapObject_GetBehaviorData(object);
    switch (state->state) {
    case TRAINER_CHECK_STATE_WAIT_OFF_TILE:
        if (MapObject_IsOffPreviousTile(object) == TRUE) {
            state->state++;
        }
        break;
    case TRAINER_CHECK_STATE_WAIT_ON_TILE:
        if (!MapObject_IsOnPreviousTile(object)) {
            break;
        }
        state->count++;
        if (state->count < state->limit) {
            state->state = TRAINER_CHECK_STATE_WAIT_OFF_TILE;
            break;
        }
        state->state++;
    case TRAINER_CHECK_STATE_WAIT_MOVEMENT:
        if (MapObject_CheckSingleMovement(object) == TRUE) {
            break;
        }
        state->state++;
        state->count = 0;
        state->turnState = TRAINER_TURN_STATE_INIT;
    case TRAINER_CHECK_STATE_READY:
        return TRUE;
    }
    return FALSE;
}

BOOL TypeBehavior_SpinUpdate(LocalMapObject *object) {
    DirectionMovementTable spinOrders = gTypeBehaviorSpinOrders;
    TrainerBehaviorState *state = MapObject_GetBehaviorData(object);
    int i;
    u32 dir;
    switch (state->turnState) {
    case TRAINER_TURN_STATE_INIT:
        dir = MapObject_GetFacingDirection(object);
        i = 0;
        while (i < DIR_MAX && dir != spinOrders.values[state->sequence][i]) {
            i++;
        }
        GF_ASSERT(i < DIR_MAX);
        state->direction = dir;
        state->index = (i + 1) % DIR_MAX;
        state->turnState++;
    case TRAINER_TURN_STATE_TURN:
        MapObject_ForceSetHeldMovement(object, GetMovementForDirection(spinOrders.values[state->sequence][state->index], MOVEMENT_FACE_UP));
        state->turnState++;
    case TRAINER_TURN_STATE_WAIT_TURN:
        if (!MapObject_RunForcedMovement(object)) {
            return TRUE;
        }
        state->turnState++;
    case TRAINER_TURN_STATE_PAUSE:
        state->timer++;
        if (state->timer < 8) {
            return TRUE;
        }
        state->timer = 0;
        state->turns++;
        if (state->turns < 4) {
            state->index = (state->index + 1) % DIR_MAX;
            state->turnState = TRAINER_TURN_STATE_TURN;
            return TRUE;
        }
        MapObject_SetFacingDirection(object, state->direction);
        state->turnState++;
        state->turns = 0;
        state->state = TRAINER_CHECK_STATE_WAIT_OFF_TILE;
    }
    return FALSE;
}

void ApricornTreeObject_Init(LocalMapObject *object) {
    ApricornTreeState *state = MapObject_InitDrawData(object, sizeof(ApricornTreeState));
    state->spriteId = SPRITE_BONGURI;
    state->apricorns = 0;
    MapObject_CallDrawUpdate(object);
}

void ApricornTreeObject_Update(LocalMapObject *object) {
    MapObjectSpriteState *spriteState = MapObject_GetMovementData(object);
    ApricornTreeState *state = MapObject_GetDrawData(object);
    BOOL apricorn = FieldSystem_ApricornTree_HasApricorn(MapObject_GetFieldSystem(object), object);
    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    if (state->billboard == NULL) {
        state->spriteId = GetApricornTreeSpriteId(FieldSystem_ApricornTree_TryGetApricorn(MapObject_GetFieldSystem(object), object), apricorn);
        MapObject_SetSpriteID(object, state->spriteId);
        MapObject_RequestBillboard(object, &state->billboard, state->spriteId);
    } else if (apricorn != state->apricorns) {
        MapObject_CancelAndFreeBillboard(object, &state->billboard, state->spriteId);
        state->spriteId = GetApricornTreeSpriteId(FieldSystem_ApricornTree_TryGetApricorn(MapObject_GetFieldSystem(object), object), apricorn);
        MapObject_SetSpriteID(object, state->spriteId);
        if (state->spriteId != MAP_OBJECT_GFX_ID_INVALID) {
            if (apricorn == 1) {
                ApricornRegrowth_Spawn(object);
            }
            MapObject_RequestBillboard(object, &state->billboard, state->spriteId);
        } else {
            GF_ASSERT(FALSE);
        }
        spriteState->unk2 = 0;
    }
    state->apricorns = apricorn;
    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    if (state->billboard == NULL) {
        return;
    }
    MapObject_UpdateBillboardPosition(object, state->billboard);
    if (!MapObject_IsBillboardAnimPaused(object)) {
        switch (MapObject_GetAnimation(object)) {
        case 0:
            if (BillboardObject_GetSequence(state->billboard) != 0) {
                BillboardObject_SetSequence(state->billboard, 0);
                BillboardObject_SetSequenceFrame(state->billboard, 0);
            }
            break;
        case 1:
            if (BillboardObject_GetSequence(state->billboard) != 1) {
                BillboardObject_SetSequence(state->billboard, 1);
                BillboardObject_SetSequenceFrame(state->billboard, 0);
            }
            break;
        case 2:
            if (BillboardObject_GetSequence(state->billboard) != 2) {
                BillboardObject_SetSequence(state->billboard, 2);
                BillboardObject_SetSequenceFrame(state->billboard, 0);
            }
            break;
        default:
            GF_ASSERT(FALSE);
            if (BillboardObject_GetSequence(state->billboard) != 0) {
                BillboardObject_SetSequence(state->billboard, 0);
                BillboardObject_SetSequenceFrame(state->billboard, 0);
            }
            break;
        }
        BillboardObject_AdvanceFrame(state->billboard, FX32_ONE);
    }
    MapObject_SetBillboardVisibleFromFlags(object, state->billboard);
}

void ApricornTreeObject_Delete(LocalMapObject *object) {
    ApricornTreeState *state = MapObject_GetDrawData(object);
    MapObject_CancelAndFreeBillboard(object, &state->billboard, state->spriteId);
}

void ApricornTreeObject_Pause(LocalMapObject *object) {
    ApricornTreeState *state = MapObject_GetDrawData(object);
    if (state->billboard != NULL) {
        BillboardObject_SaveState(state->billboard, &state->savedState);
    }
    MapObject_CancelAndFreeBillboard(object, &state->billboard, state->spriteId);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK21);
}

void ApricornTreeObject_Resume(LocalMapObject *object) {
    ApricornTreeState *state = MapObject_GetDrawData(object);
    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    if (state->billboard == NULL) {
        if (state->spriteId != MAP_OBJECT_GFX_ID_INVALID) {
            MapObject_RequestBillboard(object, &state->billboard, state->spriteId);
        } else {
            GF_ASSERT(FALSE);
        }
    }
    if (state->billboard == NULL) {
        return;
    }
    BillboardObject_RestoreState(state->billboard, &state->savedState);
    MapObject_UpdateBillboardPosition(object, state->billboard);
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK21);
}

BillboardObject *ApricornTreeObject_GetBillboard(LocalMapObject *object) {
    if (MapObject_IsBillboardPending(object) == TRUE) {
        GF_ASSERT(FALSE);
        return NULL;
    }
    return ((ApricornTreeState *)MapObject_GetDrawData(object))->billboard;
}

static u32 GetApricornTreeSpriteId(int apricorn, int apricornCount) {
    if (apricornCount == 0) {
        return SPRITE_BONGURI;
    }
    GF_ASSERT(apricorn != 0);
    return gApricornTreeSpriteIds[apricorn];
}

BOOL TryGetSeenByNpcTrainers(FieldSystem *fieldSystem, BOOL doublesEligible) {
    EngageParams first;
    EngageParams second;
    EngageParams partner;
    PlayerAvatar *avatar = fieldSystem->playerAvatar;
    MapObjectManager *manager = fieldSystem->mapObjectManager;

    if (!CheckSeenByNpcTrainers(fieldSystem, manager, avatar, NULL, &first)) {
        return FALSE;
    }
    if (first.isDouble == FALSE) {
        StartMapSceneScript(fieldSystem, std_trainer_approach, first.object);
        if (!doublesEligible || !CheckSeenByNpcTrainers(fieldSystem, manager, avatar, first.object, &second)) {
            FieldSystem_SetEngagedTrainer(fieldSystem, first.object, first.x, first.z, first.scriptId, first.trainerNum, 0, 0);
            return TRUE;
        }
        FieldSystem_SetEngagedTrainer(fieldSystem, first.object, first.x, first.z, first.scriptId, first.trainerNum, 2, 0);
        FieldSystem_SetEngagedTrainer(fieldSystem, second.object, second.x, second.z, second.scriptId, second.trainerNum, 2, 1);
        return TRUE;
    }
    if (first.isDouble == TRUE) {
        if (!doublesEligible) {
            return FALSE;
        }
        GetEngagingTrainerParams(&partner, MapObjectManager_FindTrainerPartner(fieldSystem, manager, first.object, first.trainerNum), first.x, first.z);
        StartMapSceneScript(fieldSystem, std_trainer_approach, first.object);
        FieldSystem_SetEngagedTrainer(fieldSystem, first.object, first.x, first.z, first.scriptId, first.trainerNum, 1, 0);
        FieldSystem_SetEngagedTrainer(fieldSystem, partner.object, partner.x, partner.z, partner.scriptId, partner.trainerNum, 1, 1);
        return TRUE;
    }
    GF_ASSERT(FALSE);
    return FALSE;
}

static BOOL CheckSeenByNpcTrainers(FieldSystem *fieldSystem, MapObjectManager *manager, PlayerAvatar *avatar, LocalMapObject *exclude, EngageParams *out) {
    int x;
    int index = 0;
    u32 direction;
    LocalMapObject *object = NULL;

    while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, MAPOBJECTFLAG_ACTIVE)) {
        if (exclude == NULL || exclude != object) {
            x = TrainerSight_FindPlayer(object, avatar, &direction);
            if (x != -1) {
                if (!TrainerFlagCheck(fieldSystem->saveData, (u16)MapObject_GetTrainerNum(object))) {
                    GetEngagingTrainerParams(out, object, x, direction);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

static void GetEngagingTrainerParams(EngageParams *out, LocalMapObject *object, int x, int z) {
    out->x = x;
    out->z = z;
    out->scriptId = MapObject_GetScriptID(object);
    out->trainerNum = ScriptNumToTrainerNum(out->scriptId);
    out->isDouble = TrainerNumIsDouble((u16)out->trainerNum);
    out->object = object;
}

static int MapObject_GetTrainerSightType(LocalMapObject *object) {
    u32 type = MapObject_GetType(object);
    switch (type) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        type = 1;
        break;
    }
    return type;
}

static int TrainerSight_FindPlayer(LocalMapObject *object, PlayerAvatar *player, int *outDir) {
    int mode = MapObject_GetTrainerSightType(object);

    if (mode == 1) {
        int x = PlayerAvatar_GetXCoord(player);
        int z = PlayerAvatar_GetZCoord(player);
        u32 dir = MapObject_GetFacingDirection(object);
        int param = MapObject_GetParam(object, 0);
        int dist = TrainerSight_GetDistanceInDirection(object, dir, param, x, z, 0);
        if (dist != -1 && !TrainerSight_IsPathBlocked(object, dir, dist)) {
            *outDir = dir;
            return dist;
        }
        return -1;
    }
    if (mode == 2) {
        int x = PlayerAvatar_GetXCoord(player);
        int z = PlayerAvatar_GetZCoord(player);
        int param = MapObject_GetParam(object, 0);
        int dir;
        for (dir = 0; dir < DIR_MAX; dir++) {
            int dist = TrainerSight_GetDistanceInDirection(object, dir, param, x, z, 0);
            if (dist != -1 && !TrainerSight_IsPathBlocked(object, dir, dist)) {
                *outDir = dir;
                return dist;
            }
        }
        return -1;
    }
    return -1;
}

static int TrainerSight_GetDistanceInDirection(LocalMapObject *object, u32 direction, int range, int targetX, int targetZ, int unused) {
    return sTrainerSightDistanceFuncs[direction](object, range, targetX, targetZ, unused);
}

static int TrainerSight_GetDistanceNorth(LocalMapObject *object, int range, int targetX, int targetZ, int unused) {
    int z, x = MapObject_GetXCoord(object);
    if (x == targetX) {
        z = MapObject_GetZCoord(object);
        if (targetZ < z && targetZ >= z - range) {
            return z - targetZ;
        }
    }
    return -1;
}

static int TrainerSight_GetDistanceSouth(LocalMapObject *object, int range, int targetX, int targetZ, int unused) {
    int z, x = MapObject_GetXCoord(object);
    if (x == targetX) {
        z = MapObject_GetZCoord(object);
        if (targetZ > z && targetZ <= z + range) {
            return targetZ - z;
        }
    }
    return -1;
}

static int TrainerSight_GetDistanceWest(LocalMapObject *object, int range, int targetX, int targetZ, int unused) {
    int x, z = MapObject_GetZCoord(object);
    if (z == targetZ) {
        x = MapObject_GetXCoord(object);
        if (targetX < x && targetX >= x - range) {
            return x - targetX;
        }
    }
    return -1;
}

static int TrainerSight_GetDistanceEast(LocalMapObject *object, int range, int targetX, int targetZ, int unused) {
    int x, z = MapObject_GetZCoord(object);
    if (z == targetZ) {
        x = MapObject_GetXCoord(object);
        if (targetX > x && targetX <= x + range) {
            return targetX - x;
        }
    }
    return -1;
}

static BOOL TrainerSight_IsPathBlocked(LocalMapObject *object, u32 direction, int distance) {
    int x;
    int y;
    int z;
    int i;

    if (distance == 0) {
        return TRUE;
    }
    x = MapObject_GetXCoord(object);
    z = MapObject_GetZCoord(object);
    y = MapObject_GetYCoord(object);
    x += GetDeltaXByFacingDirection(direction);
    z += GetDeltaYByFacingDirection(direction);
    for (i = 0; i < distance - 1; i++) {
        if ((MapObject_CheckCollisionAt(object, x, y, z, direction) & ~1) != 0) {
            return TRUE;
        }
        x += GetDeltaXByFacingDirection(direction);
        z += GetDeltaYByFacingDirection(direction);
    }
    if ((MapObject_CheckCollisionAt(object, x, y, z, direction) & ~1) == 4) {
        return FALSE;
    }
    return TRUE;
}

static u32 MapObject_GetTrainerNum(LocalMapObject *object) {
    return ScriptNumToTrainerNum(MapObject_GetScriptID(object));
}

u32 MapObjectBehavior_GetTrainerNum(LocalMapObject *object) {
    return MapObject_GetTrainerNum(object);
}

static LocalMapObject *MapObjectManager_FindTrainerPartner(FieldSystem *unused, MapObjectManager *manager, LocalMapObject *exclude, u32 trainerNum) {
    s32 index = 0;
    LocalMapObject *object;
    while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, MAPOBJECTFLAG_ACTIVE)) {
        if (object != exclude && (u32)(MapObject_GetTrainerSightType(object) - 1) <= 1 && MapObject_GetTrainerNum(object) == trainerNum) {
            return object;
        }
    }
    GF_ASSERT(FALSE);
    return NULL;
}

SysTask *TrainerApproach_Start(FieldSystem *fieldSystem, LocalMapObject *trainer, PlayerAvatar *player, int movement, int remaining, int unk10, int encounterType, int trainerIndex) {
    return TrainerApproach_CreateTask(fieldSystem, trainer, player, movement, remaining, unk10, encounterType, trainerIndex);
}

BOOL TrainerApproach_IsDone(SysTask *task) {
    GF_ASSERT(task != NULL);
    return TrainerApproach_GetDone(task);
}

void TrainerApproach_Delete(SysTask *task) {
    TrainerApproach_DestroyTask(task);
}

static SysTask *TrainerApproach_CreateTask(FieldSystem *fieldSystem, LocalMapObject *trainer, PlayerAvatar *player, int movement, int remaining, int unk10, int encounterType, int trainerIndex) {
    TrainerApproachWork *work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(TrainerApproachWork));
    SysTask *task;
    GF_ASSERT(work != NULL);
    memset(work, 0, sizeof(TrainerApproachWork));
    work->direction = movement;
    work->distance = remaining;
    work->unk10 = unk10;
    work->encounterType = encounterType;
    work->trainerIndex = trainerIndex;
    work->fieldSystem = fieldSystem;
    work->trainer = trainer;
    work->player = player;
    task = SysTask_CreateOnMainQueue(TrainerApproach_Task, work, 0xFF);
    GF_ASSERT(task != NULL);
    return task;
}

static BOOL TrainerApproach_GetDone(SysTask *task) {
    TrainerApproachWork *work = SysTask_GetData(task);
    return work->done;
}

static void TrainerApproach_DestroyTask(SysTask *task) {
    void *work = SysTask_GetData(task);
    Heap_FreeExplicit(HEAP_ID_FIELD1, work);
    SysTask_Destroy(task);
}

static void TrainerApproach_Task(SysTask *task, void *data) {
    TrainerApproachWork *work = data;
    while (sTrainerApproachStateFuncs[work->state](work) == TRUE) {}
}

static BOOL TrainerApproach_UnpauseTrainer(TrainerApproachWork *work) {
    LocalMapObject *object = work->trainer;
    if (MapObject_CheckSingleMovement(object) == TRUE) {
        MapObject_UnpauseMovement(object);
    }
    work->state = TRAINER_APPROACH_FACE_DIRECTION;
    return TRUE;
}

static BOOL TrainerApproach_FaceDirection(TrainerApproachWork *work) {
    LocalMapObject *object = work->trainer;
    if (MapObject_CheckSingleMovement(object) == TRUE) {
        return FALSE;
    }
    MapObject_SetFacingAndUpdateDraw(work->trainer, work->direction);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_MOVEMENT_PAUSED);
    work->state = TRAINER_APPROACH_WAIT_FOR_PLAYER;
    return TRUE;
}

static BOOL TrainerApproach_WaitForPlayer(TrainerApproachWork *work) {
    LocalMapObject *player = PlayerAvatar_GetMapObject(work->player);
    if (!MapObject_IsMovementPaused(player)) {
        return FALSE;
    }
    switch (MapObject_GetMovement(work->trainer)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        work->state = TRAINER_APPROACH_START_REVEAL;
        return TRUE;
    default:
        work->state = TRAINER_APPROACH_START_FACE;
        return TRUE;
    }
}

static BOOL TrainerApproach_StartFace(TrainerApproachWork *work) {
    if (!MapObject_AreBitsSetForMovementScriptInit(work->trainer)) {
        return FALSE;
    }
    GF_ASSERT(work->direction != DIR_NONE);
    MapObject_SetHeldMovement(work->trainer, GetMovementForDirection(work->direction, MOVEMENT_FACE_UP));
    work->state = TRAINER_APPROACH_WAIT_FACE;
    return FALSE;
}

static BOOL TrainerApproach_WaitFace(TrainerApproachWork *work) {
    if (!MapObject_IsMovementPaused(work->trainer)) {
        return FALSE;
    }
    work->state = TRAINER_APPROACH_SPAWN_EXCLAMATION;
    return TRUE;
}

static BOOL TrainerApproach_SpawnExclamation(TrainerApproachWork *work) {
    work->effect = EmoteMark_Spawn(work->trainer, 0, FALSE);
    work->state = TRAINER_APPROACH_WAIT_EXCLAMATION;
    return FALSE;
}

static BOOL TrainerApproach_WaitExclamation(TrainerApproachWork *work) {
    if (EmoteMark_IsDone(work->effect) == TRUE) {
        FieldEffect_Destroy(work->effect);
        work->state = TRAINER_APPROACH_WAIT;
    }
    return FALSE;
}

static BOOL TrainerApproach_StartReveal(TrainerApproachWork *work) {
    MapObject_SetHeldMovement(work->trainer, 0x65);
    work->state = TRAINER_APPROACH_WAIT_REVEAL;
    return FALSE;
}

static BOOL TrainerApproach_WaitReveal(TrainerApproachWork *work) {
    if (MapObject_IsMovementPaused(work->trainer) == TRUE) {
        work->state = TRAINER_APPROACH_WAIT;
    }
    return FALSE;
}

static BOOL TrainerApproach_Wait(TrainerApproachWork *work) {
    if (++work->timer >= 30) {
        work->timer = 0;
        work->state = TRAINER_APPROACH_CHECK_DISTANCE;
    }
    return FALSE;
}

static BOOL TrainerApproach_CheckDistance(TrainerApproachWork *work) {
    if (work->distance <= 1) {
        work->state = TRAINER_APPROACH_WAIT_ARRIVED;
        return TRUE;
    }
    work->state = TRAINER_APPROACH_START_STEP;
    return TRUE;
}

static BOOL TrainerApproach_StartStep(TrainerApproachWork *work) {
    if (MapObject_AreBitsSetForMovementScriptInit(work->trainer) == TRUE) {
        MapObject_SetHeldMovement(work->trainer, GetMovementForDirection(work->direction, MOVEMENT_STEP_UP));
        work->state = TRAINER_APPROACH_WAIT_STEP;
    }
    return FALSE;
}

static BOOL TrainerApproach_WaitStep(TrainerApproachWork *work) {
    if (!MapObject_IsMovementPaused(work->trainer)) {
        return FALSE;
    }
    work->distance--;
    work->state = TRAINER_APPROACH_CHECK_DISTANCE;
    return TRUE;
}

static BOOL TrainerApproach_WaitArrived(TrainerApproachWork *work) {
    if (++work->timer < 8) {
        return FALSE;
    }
    work->timer = 0;
    work->state = TRAINER_APPROACH_TURN_PLAYER;
    return TRUE;
}

static BOOL TrainerApproach_TurnPlayer(TrainerApproachWork *work) {
    LocalMapObject *object = PlayerAvatar_GetMapObject(work->player);
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    int tx = MapObject_GetXCoord(work->trainer);
    int tz = MapObject_GetZCoord(work->trainer);
    int direction = GetDirectionTowards(x, z, tx, tz);
    if (direction != PlayerAvatar_GetFacingDirection(work->player) && (work->trainerIndex == 0 || work->encounterType == 2)) {
        if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
            MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK7);
            MapObject_SetHeldMovement(object, GetMovementForDirection(direction, MOVEMENT_FACE_UP));
            work->state = TRAINER_APPROACH_WAIT_PLAYER_TURN;
        }
    } else {
        work->state = TRAINER_APPROACH_RESET_TRAINER_MOVEMENT;
    }
    return FALSE;
}

static BOOL TrainerApproach_WaitPlayerTurn(TrainerApproachWork *work) {
    LocalMapObject *player = PlayerAvatar_GetMapObject(work->player);
    if (!MapObject_IsMovementPaused(player)) {
        return FALSE;
    }
    MapObject_ClearHeldMovementIfActive(player);
    work->state = TRAINER_APPROACH_RESET_TRAINER_MOVEMENT;
    return TRUE;
}

static BOOL TrainerApproach_ResetTrainerMovement(TrainerApproachWork *work) {
    MapObject_ClearHeldMovementIfActive(work->trainer);
    MapObject_ChangeMovement(work->trainer, 0);
    work->state = TRAINER_APPROACH_FINISH;
    return TRUE;
}

static BOOL TrainerApproach_Finish(TrainerApproachWork *work) {
    work->done = TRUE;
    return FALSE;
}
