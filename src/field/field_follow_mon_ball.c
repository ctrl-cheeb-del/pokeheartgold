#include "field_follow_mon_ball.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_3d_model.h"
#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"
#include "field/field_follow_mon.h"
#include "field/map_object_billboard_motion.h"

#include "field_effects.h"
#include "field_system.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "vram_transfer_manager.h"

// The following Pokemon's Poke Ball: a ball model and a burst model with one animation, both kept loaded.
// When it is recalled, a large Pokemon is also pulled towards the tile it faces.

#define FOLLOW_MON_BALL_SHRINK_FRAMES 4


enum FollowMonBallReleaseState {
    BALL_RELEASE_STATE_WAIT,
    BALL_RELEASE_STATE_OPEN,
    BALL_RELEASE_STATE_BURST,
};

enum FollowMonBallBurstState {
    BALL_BURST_STATE_START,
    BALL_BURST_STATE_BURST,
};

enum FollowMonBallRecallState {
    BALL_RECALL_STATE_START,
    BALL_RECALL_STATE_SHRINK,
    BALL_RECALL_STATE_SHOW_BALL,
};

struct FollowMonBall {
    FieldEffectManager *manager;
    NNSFndAllocator allocator;
    void *ballFile;
    void *burstFile;
    Field3dModel ballModel;
    Field3dModel burstModel;
    Field3dObject ball;
    Field3dObject burst;
    Field3DModelAnimation burstAnimation;
};

typedef struct FollowMonBallEffectArgs {
    VecFx32 position;
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    FollowMonBall *ball;
    LocalMapObject *mapObject;
    u16 unk_1C;
    u16 unk_1E;
    s8 unk_20;
} FollowMonBallEffectArgs;

typedef struct FollowMonBallEffect {
    int state;
    u32 spriteId;
    u32 objectId;
    u32 mapId;
    int timer;
    BOOL onGround;
    FollowMonBallEffectArgs args;
    fx32 *coordinate; // the follower's x or z being pulled, NULL if it is not a large one
    fx32 originalCoordinate;
    int coordinateStep;
    VecFx32 position;
} FollowMonBallEffect;

static void FollowMonBall_LoadModels(FollowMonBall *ball);
static void FollowMonBall_FreeModels(FollowMonBall *ball);
static BOOL FollowMonBallEffect_InitBurst(FieldEffect *effect, void *state);
static void FollowMonBallEffect_Destroy(FieldEffect *effect, void *state);
static void FollowMonBallEffect_UpdateRelease(FieldEffect *effect, void *state);
static void FollowMonBallEffect_DrawRelease(FieldEffect *effect, void *state);
static void FollowMonBallEffect_UpdateBurst(FieldEffect *effect, void *state);
static void FollowMonBallEffect_DrawBurst(FieldEffect *effect, void *state);
static BOOL FollowMonBallEffect_InitRecallWhite(FieldEffect *effect, void *state);
static void FollowMonBallEffect_UpdateRecallWhite(FieldEffect *effect, void *state);
static void FollowMonBallEffect_DrawBall(FieldEffect *effect, void *state);
static BOOL FollowMonBallEffect_InitRecall(FieldEffect *effect, void *state);
static void FollowMonBallEffect_UpdateRecall(FieldEffect *effect, void *state);
static void FollowMonBall_GetPullCoordinate(u32 direction, VecFx32 *position, fx32 **coordinate);
static int FollowMonBall_GetPullStep(u32 direction);

static u16 sFollowMonWhitePalette[32] = {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
};

static const VecFx32 sFollowMonBallRecallWhiteScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static const VecFx32 sFollowMonBallRecallScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static const FieldEffectBasicTemplate sFollowMonBallReleaseTemplate = {
    sizeof(FollowMonBallEffect),
    FollowMonBallEffect_InitBurst,
    FollowMonBallEffect_Destroy,
    FollowMonBallEffect_UpdateRelease,
    FollowMonBallEffect_DrawRelease,
};

static const FieldEffectBasicTemplate sFollowMonBallBurstTemplate = {
    sizeof(FollowMonBallEffect),
    FollowMonBallEffect_InitBurst,
    FollowMonBallEffect_Destroy,
    FollowMonBallEffect_UpdateBurst,
    FollowMonBallEffect_DrawBurst,
};

static const FieldEffectBasicTemplate sFollowMonBallRecallWhiteTemplate = {
    sizeof(FollowMonBallEffect),
    FollowMonBallEffect_InitRecallWhite,
    FollowMonBallEffect_Destroy,
    FollowMonBallEffect_UpdateRecallWhite,
    FollowMonBallEffect_DrawBall,
};

static const FieldEffectBasicTemplate sFollowMonBallRecallTemplate = {
    sizeof(FollowMonBallEffect),
    FollowMonBallEffect_InitRecall,
    FollowMonBallEffect_Destroy,
    FollowMonBallEffect_UpdateRecall,
    FollowMonBallEffect_DrawBall,
};

FollowMonBall *FollowMonBall_New(FieldEffectManager *manager) {
    FollowMonBall *ball = FieldEffectManager_HeapAllocAndFill(manager, sizeof(FollowMonBall), FALSE, 0);
    ball->manager = manager;
    HeapExp_FndInitAllocator(&ball->allocator, HEAP_ID_FIELD1, 32);
    FollowMonBall_LoadModels(ball);
    return ball;
}

void FollowMonBall_Free(FollowMonBall *ball) {
    FollowMonBall_FreeModels(ball);
    FieldEffectManager_HeapFree(ball);
}

static void FollowMonBall_LoadModels(FollowMonBall *ball) {
    ball->ballFile = FieldEffectManager_LoadNarcMember(ball->manager, 0x81, FALSE);
    Field3dModel_LoadFromData(&ball->ballModel, ball->ballFile);
    Field3dObject_InitFromModel(&ball->ball, &ball->ballModel);
    ball->burstFile = FieldEffectManager_LoadNarcMember(ball->manager, 0x68, FALSE);
    Field3dModel_LoadFromData(&ball->burstModel, ball->burstFile);
    Field3dObject_InitFromModel(&ball->burst, &ball->burstModel);
    Field3dModelAnimation_LoadFromFilesystem(&ball->burstAnimation, &ball->burstModel, NARC_a_1_0_3, 0xA4, HEAP_ID_FIELD1, &ball->allocator);
    Field3dObject_AddAnimation(&ball->burst, &ball->burstAnimation);
}

static void FollowMonBall_FreeModels(FollowMonBall *ball) {
    Field3dModel_UnloadKeepData(&ball->ballModel);
    FieldEffectManager_HeapFree(ball->ballFile);
    Field3dModel_UnloadKeepData(&ball->burstModel);
    FieldEffectManager_HeapFree(ball->burstFile);
    Field3dModelAnimation_Unload(&ball->burstAnimation, &ball->allocator);
}

FieldEffect *FollowMonBall_Spawn(LocalMapObject *mapObject, enum FollowMonBallKind kind) {
    VecFx32 position;
    FollowMonBallEffectArgs args;
    u32 priority;
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);

    MapObject_CopyPositionVector(mapObject, &args.position);
    args.position.z += 6 * FX32_ONE;
    args.unk_1C = 0;
    args.unk_1E = 0;
    args.unk_20 = -1;
    args.manager = manager;
    args.fieldSystem = FieldEffectManager_GetFieldSystem(manager);
    args.ball = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_FOLLOW_MON_BALL);
    args.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    priority = MapObject_GetPriorityPlusValue(mapObject, 2);
    if (kind == FOLLOW_MON_BALL_RELEASE) {
        return FieldEffectManager_CreateEffect(manager, &sFollowMonBallReleaseTemplate, &position, 1, &args, priority);
    }
    if (kind == FOLLOW_MON_BALL_RECALL_WHITE) {
        return FieldEffectManager_CreateEffect(manager, &sFollowMonBallRecallWhiteTemplate, &position, 1, &args, priority);
    }
    if (kind == FOLLOW_MON_BALL_BURST) {
        return FieldEffectManager_CreateEffect(manager, &sFollowMonBallBurstTemplate, &position, 1, &args, priority);
    }
    return FieldEffectManager_CreateEffect(manager, &sFollowMonBallRecallTemplate, &position, 1, &args, priority);
}

static BOOL FollowMonBallEffect_InitBurst(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    FollowMonBallEffectArgs *args = FieldEffect_GetUserData(effect);
    work->state = 0;
    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    position = work->args.position;
    work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
    FieldEffect_SetPosition(effect, &position);
    Field3dObject_SetPos(&work->args.ball->ball, &position);
    Field3dObject_SetPos(&work->args.ball->burst, &position);
    Field3dObject_SetActiveFlag(&work->args.ball->burst, FALSE);
    return TRUE;
}

static void FollowMonBallEffect_Destroy(FieldEffect *effect, void *state) {
}

static void FollowMonBallEffect_UpdateRelease(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    LocalMapObject *mapObject = work->args.mapObject;
    VecFx32 position;
    VecFx32 ground;
    if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (!work->onGround) {
        FieldEffect_GetPosition(effect, &position);
        ground = work->args.position;
        work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &ground);
        if (work->onGround == TRUE) {
            position.y = ground.y;
            FieldEffect_SetPosition(effect, &position);
        }
    }
    switch (work->state) {
    case BALL_RELEASE_STATE_WAIT:
        if (++work->timer >= 2) {
            work->state = BALL_RELEASE_STATE_OPEN;
        }
        break;
    case BALL_RELEASE_STATE_OPEN:
        Field3dObject_SetActiveFlag(&work->args.ball->ball, FALSE);
        Field3dObject_SetActiveFlag(&work->args.ball->burst, TRUE);
        FollowMon_HideUntilStep(mapObject, FALSE);
        MapObject_CallDrawUpdate(mapObject);
        Field3dModelAnimation_FrameSet(&work->args.ball->burstAnimation, 0);
        work->state = BALL_RELEASE_STATE_BURST;
    case BALL_RELEASE_STATE_BURST:
        if (Field3dModelAnimation_FrameAdvanceAndCheck(&work->args.ball->burstAnimation, FX32_ONE)) {
            FieldEffectManager_DestroyEffect(effect);
        }
        break;
    }
}

static void FollowMonBallEffect_DrawRelease(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    if (!MapObject_CheckSpriteIDAndMap(work->args.mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    FieldEffect_GetPosition(effect, &position);
    Field3dObject_Draw(&work->args.ball->ball);
    Field3dObject_Draw(&work->args.ball->burst);
}

static void FollowMonBallEffect_UpdateBurst(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    VecFx32 ground;
    if (!MapObject_CheckSpriteIDAndMap(work->args.mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (!work->onGround) {
        FieldEffect_GetPosition(effect, &position);
        ground = work->args.position;
        work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &ground);
        if (work->onGround == TRUE) {
            position.y = ground.y;
            FieldEffect_SetPosition(effect, &position);
        }
    }
    switch (work->state) {
    case BALL_BURST_STATE_START:
        Field3dObject_SetActiveFlag(&work->args.ball->ball, FALSE);
        Field3dObject_SetActiveFlag(&work->args.ball->burst, TRUE);
        Field3dModelAnimation_FrameSet(&work->args.ball->burstAnimation, 0);
        work->state = BALL_BURST_STATE_BURST;
    case BALL_BURST_STATE_BURST:
        if (Field3dModelAnimation_FrameAdvanceAndCheck(&work->args.ball->burstAnimation, FX32_ONE)) {
            FieldEffectManager_DestroyEffect(effect);
        }
        break;
    }
}

static void FollowMonBallEffect_DrawBurst(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    if (!MapObject_CheckSpriteIDAndMap(work->args.mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    FieldEffect_GetPosition(effect, &position);
    Field3dObject_Draw(&work->args.ball->burst);
}

static BOOL FollowMonBallEffect_InitRecallWhite(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    FollowMonBallEffectArgs *args = FieldEffect_GetUserData(effect);
    work->state = BALL_RECALL_STATE_START;
    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    position = work->args.position;
    work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
    FieldEffect_SetPosition(effect, &position);
    Field3dObject_SetPos(&work->args.ball->ball, &position);
    Field3dObject_SetActiveFlag(&work->args.ball->ball, FALSE);
    return TRUE;
}

static void FollowMonBallEffect_UpdateRecallWhite(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    LocalMapObject *owner = work->args.mapObject;
    VecFx32 position;
    VecFx32 ground;
    VecFx32 scale;
    LocalMapObject *mapObject;
    BillboardObject *billboard;
    u32 plttKey;
    u32 plttKey2;
    u32 direction;

    if (!MapObject_CheckSpriteIDAndMap(owner, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (!work->onGround) {
        FieldEffect_GetPosition(effect, &position);
        ground = work->args.position;
        work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &ground);
        if (work->onGround == TRUE) {
            position.y = ground.y;
            FieldEffect_SetPosition(effect, &position);
        }
    }
    switch (work->state) {
    case BALL_RECALL_STATE_START:
        mapObject = FollowMon_GetMapObject(work->args.fieldSystem);
        billboard = MapObjectManager_GetFollowMonBillboard(work->args.fieldSystem->mapObjectManager);
        plttKey = BillboardObject_GetPlttKey(billboard);
        plttKey2 = BillboardObject_GetPlttKey(billboard);
        GF_CreateNewVramTransferTask(NNS_GFD_DST_3D_TEX_PLTT, (u16)plttKey2 << 3, sFollowMonWhitePalette, ((plttKey & 0xFFFF0000) >> 16) << 3);
        if (FollowMonObject_IsLarge(mapObject)) {
            direction = (u8)MapObject_GetFacingDirection(mapObject);
            MapObject_CopyPositionVector(mapObject, &work->position);
            FollowMonBall_GetPullCoordinate(direction, &work->position, &work->coordinate);
            work->originalCoordinate = *work->coordinate;
            work->coordinateStep = FollowMonBall_GetPullStep(direction);
        } else {
            work->coordinate = NULL;
        }
        ++work->state;
    case BALL_RECALL_STATE_SHRINK:
        scale = sFollowMonBallRecallWhiteScale;
        ++work->timer;
        scale.x = FX32_ONE / work->timer;
        scale.y = FX32_ONE / work->timer;
        BillboardObject_SetScale(MapObjectManager_GetFollowMonBillboard(work->args.fieldSystem->mapObjectManager), &scale);
        if (work->coordinate) {
            mapObject = FollowMon_GetMapObject(work->args.fieldSystem);
            {
                s32 timer = work->timer;
                s32 step = work->coordinateStep;
                *work->coordinate = ((timer * (step << FX32_SHIFT)) / 4) + work->originalCoordinate;
            }
            MapObject_SetPositionVector(mapObject, &work->position);
        }
        if (work->timer >= FOLLOW_MON_BALL_SHRINK_FRAMES) {
            ++work->state;
            Field3dObject_SetActiveFlag(&work->args.ball->ball, TRUE);
            MapObject_SetInvisible(owner, TRUE);
            work->timer = 0;
            return;
        }
        break;
    case BALL_RECALL_STATE_SHOW_BALL:
        if (++work->timer >= FOLLOW_MON_BALL_SHRINK_FRAMES) {
            FieldEffectManager_DestroyEffect(effect);
        }
        break;
    }
}

static void FollowMonBallEffect_DrawBall(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    if (!MapObject_CheckSpriteIDAndMap(work->args.mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    FieldEffect_GetPosition(effect, &position);
    Field3dObject_Draw(&work->args.ball->ball);
}

static BOOL FollowMonBallEffect_InitRecall(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    VecFx32 position;
    FollowMonBallEffectArgs *args = FieldEffect_GetUserData(effect);
    work->state = BALL_RECALL_STATE_START;
    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    position = work->args.position;
    FieldEffect_SetPosition(effect, &position);
    Field3dObject_SetPos(&work->args.ball->ball, &position);
    Field3dObject_SetActiveFlag(&work->args.ball->ball, FALSE);
    return TRUE;
}

static void FollowMonBallEffect_UpdateRecall(FieldEffect *effect, void *state) {
    FollowMonBallEffect *work = state;
    LocalMapObject *mapObject = work->args.mapObject;
    if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    switch (work->state) {
    case BALL_RECALL_STATE_START: {
        LocalMapObject *followMon = FollowMon_GetMapObject(work->args.fieldSystem);
        u8 direction;
        MapObjectManager_GetFollowMonBillboard(work->args.fieldSystem->mapObjectManager);
        if (FollowMonObject_IsLarge(followMon)) {
            direction = MapObject_GetFacingDirection(followMon);
            MapObject_CopyPositionVector(followMon, &work->position);
            FollowMonBall_GetPullCoordinate(direction, &work->position, &work->coordinate);
            work->originalCoordinate = *work->coordinate;
            work->coordinateStep = FollowMonBall_GetPullStep(direction);
        } else {
            work->coordinate = NULL;
        }
        work->state++;
    }
    case BALL_RECALL_STATE_SHRINK: {
        VecFx32 scale = sFollowMonBallRecallScale;
        work->timer++;
        scale.x = FX32_ONE / work->timer;
        scale.y = FX32_ONE / work->timer;
        BillboardObject_SetScale(MapObjectManager_GetFollowMonBillboard(work->args.fieldSystem->mapObjectManager), &scale);
        if (work->coordinate) {
            LocalMapObject *followMon = FollowMon_GetMapObject(work->args.fieldSystem);
            s32 delta = work->timer * (s32)((u32)work->coordinateStep << FX32_SHIFT);
            *work->coordinate = work->originalCoordinate + delta / 4;
            MapObject_SetPositionVector(followMon, &work->position);
        }
        if (work->timer >= FOLLOW_MON_BALL_SHRINK_FRAMES) {
            work->state++;
            Field3dObject_SetActiveFlag(&work->args.ball->ball, TRUE);
            FollowMon_HideUntilStep(mapObject, TRUE);
            work->timer = 0;
        }
    } break;
    case BALL_RECALL_STATE_SHOW_BALL:
        work->timer++;
        if (work->timer >= 16) {
            FieldEffectManager_DestroyEffect(effect);
        }
        break;
    }
}

// The coordinate of position a large following Pokemon is pulled along: z when facing north or south, x
// when facing west or east.
static void FollowMonBall_GetPullCoordinate(u32 direction, VecFx32 *position, fx32 **coordinate) {
    switch (direction) {
    case DIR_NORTH:
    case DIR_SOUTH:
        *coordinate = &position->z;
        break;
    case DIR_WEST:
    case DIR_EAST:
        *coordinate = &position->x;
        break;
    }
}

static int FollowMonBall_GetPullStep(u32 direction) {
    switch (direction) {
    case DIR_NORTH:
        return -1;
    case DIR_SOUTH:
        return 1;
    case DIR_WEST:
        return -10;
    case DIR_EAST:
        return 10;
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
}
