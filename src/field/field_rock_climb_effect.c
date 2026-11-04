#include "field_rock_climb_effect.h"

#include <string.h>

#include "global.h"

#include "constants/field/field_effect_renderer.h"
#include "constants/global_fieldmap.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "field_effects.h"
#include "geometry_math.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "render_animation.h"
#include "render_model.h"

// The rock the player climbs on with Rock Climb: one model, loaded while any
// effect uses it, placed on the tile ahead and turned to the climbing direction; once the climb starts
// (RockClimbEffect_SetFollow) it rides along with the map object.

struct RockClimb {
    int refCount;
    BOOL loaded;
    u8 unk_08[8];
    FieldEffectManager *manager;
    RenderModel model;
    NNSG3dRenderObj renderObj;
};

typedef struct RockClimbEffectArgs {
    u32 direction;
    FieldEffectManager *manager;
    FieldSystem *fieldSystem;
    RockClimb *rockClimb;
    LocalMapObject *mapObject;
} RockClimbEffectArgs;

typedef struct RockClimbEffect {
    BOOL hidden;
    u32 direction;
    int timer;
    BOOL follow;
    RockClimbEffectArgs args;
} RockClimbEffect;

static void RockClimb_Retain(RockClimb *rockClimb);
static void RockClimb_Release(RockClimb *rockClimb);
static void RockClimb_LoadGfx(RockClimb *rockClimb);
static void RockClimb_FreeGfx(RockClimb *rockClimb);
static void RockClimb_LoadGfxIfUnused(RockClimb *rockClimb);
static void RockClimb_FreeGfxIfUnused(RockClimb *rockClimb);
static BOOL RockClimbEffect_Init(FieldEffect *effect, void *state);
static void RockClimbEffect_Destroy(FieldEffect *effect, void *state);
static void RockClimbEffect_Update(FieldEffect *effect, void *state);
static void RockClimbEffect_Draw(FieldEffect *effect, void *state);

static const VecFx32 sRockClimbScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static const FieldEffectBasicTemplate sRockClimbEffectTemplate = {
    sizeof(RockClimbEffect),
    RockClimbEffect_Init,
    RockClimbEffect_Destroy,
    RockClimbEffect_Update,
    RockClimbEffect_Draw,
};

RockClimb *RockClimb_New(FieldEffectManager *manager) {
    RockClimb *rockClimb = FieldEffectManager_HeapAllocAndFill(manager, sizeof(RockClimb), FALSE, 0);
    rockClimb->manager = manager;
    return rockClimb;
}

void RockClimb_Free(RockClimb *rockClimb) {
    RockClimb_FreeGfx(rockClimb);
    FieldEffectManager_HeapFree(rockClimb);
}

static void RockClimb_Retain(RockClimb *rockClimb) {
    ++rockClimb->refCount;
}

static void RockClimb_Release(RockClimb *rockClimb) {
    rockClimb->refCount--;
    GF_ASSERT(rockClimb->refCount >= 0);
}

static void RockClimb_LoadGfx(RockClimb *rockClimb) {
    if (!rockClimb->loaded) {
        FieldEffectManager_LoadRenderModel(rockClimb->manager, &rockClimb->model, 0, 0x57, TRUE);
        RenderObj_InitFromModel(&rockClimb->renderObj, &rockClimb->model);
        rockClimb->loaded = TRUE;
    }
}

static void RockClimb_FreeGfx(RockClimb *rockClimb) {
    if (rockClimb->loaded == TRUE) {
        rockClimb->loaded = FALSE;
        RenderModel_Free(&rockClimb->model);
    }
}

static void RockClimb_LoadGfxIfUnused(RockClimb *rockClimb) {
    if (rockClimb->refCount == 0) {
        RockClimb_LoadGfx(rockClimb);
    }
}

static void RockClimb_FreeGfxIfUnused(RockClimb *rockClimb) {
    if (rockClimb->refCount == 0) {
        RockClimb_FreeGfx(rockClimb);
    }
}

FieldEffect *RockClimbEffect_Create(LocalMapObject *mapObject, int x, int z, int direction, BOOL follow) {
    RockClimbEffectArgs args;
    VecFx32 position = { 0, 0, 0 };
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);
    u32 priority;

    args.direction = direction;
    args.manager = manager;
    args.fieldSystem = MapObject_GetFieldSystem(mapObject);
    args.rockClimb = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_ROCK_CLIMB);
    args.mapObject = mapObject;
    if (!follow) {
        position.x = (x << 16) + FX32_CONST(8);
        position.z = (z << 16) + FX32_CONST(8);
        FieldSystem_SnapToTerrainHeight(args.fieldSystem, &position);
    } else {
        MapObject_CopyPositionVector(mapObject, &position);
    }
    priority = MapObject_GetPriorityPlusValue(mapObject, 2);
    return FieldEffectManager_CreateEffect(manager, &sRockClimbEffectTemplate, &position, follow, &args, priority);
}

void RockClimbEffect_SetFollow(FieldEffect *effect, BOOL follow) {
    RockClimbEffect *work = FieldEffect_GetState(effect);
    work->follow = follow;
}

static BOOL RockClimbEffect_Init(FieldEffect *effect, void *state) {
    RockClimbEffect *work = state;
    RockClimbEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->direction = args->direction;
    work->follow = FieldEffect_GetParam(effect);
    RockClimb_LoadGfxIfUnused(work->args.rockClimb);
    RockClimb_Retain(work->args.rockClimb);
    return TRUE;
}

static void RockClimbEffect_Destroy(FieldEffect *effect, void *state) {
    RockClimbEffect *work = state;
    RockClimb_Release(work->args.rockClimb);
    RockClimb_FreeGfxIfUnused(work->args.rockClimb);
}

static void RockClimbEffect_Update(FieldEffect *effect, void *state) {
    RockClimbEffect *work = state;
    VecFx32 offset;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;

    if (work->follow) {
        memset(&offset, 0, sizeof(offset));
        MapObject_SetDrawOffset(mapObject, &offset);
        MapObject_CopyPositionVector(mapObject, &position);
        FieldEffect_SetPosition(effect, &position);
    }
}

static void RockClimbEffect_Draw(FieldEffect *effect, void *state) {
    RockClimbEffect *work = state;
    MtxFx33 rotation;
    VecFx32 position;
    VecFx32 scale;
    NNSG3dRenderObj *renderObj;
    int angle;

    if (work->hidden == TRUE) {
        return;
    }
    work->timer++;
    angle = 0;
    scale = sRockClimbScale;
    renderObj = &work->args.rockClimb->renderObj;
    switch (work->direction) {
    case DIR_NORTH:
        angle = 180;
        break;
    case DIR_SOUTH:
        break;
    case DIR_WEST:
        angle = 270;
        break;
    case DIR_EAST:
        angle = 90;
        break;
    }
    Math_CalcRotationMatrixXYZDeg(&rotation, 0, angle, 0);
    FieldEffect_GetPosition(effect, &position);
    RenderObj_Draw(renderObj, &position, &scale, &rotation);
}
