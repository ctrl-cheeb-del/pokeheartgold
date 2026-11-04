#include "field_footprints.h"

#include <nnsys/g3d_util_internal.h>

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "field_effects.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "render_animation.h"
#include "render_model.h"

// Footprints and tire tracks a map object leaves behind, one mark per step, held for 16 frames and then faded out.
// Kinds: 0 bank A by facing (sand, walking), 1 bank A track piece (sand, cycling), 2 bank B by facing, 3 bank B
// track piece (unused), 4 bank B by facing at bank A's offsets.

#define FOOTPRINT_MODEL_COUNT 10


struct Footprints {
    FieldEffectManager *manager;
    RenderModelStorage modelsA[FOOTPRINT_MODEL_COUNT];
    RenderModelStorage modelsB[FOOTPRINT_MODEL_COUNT];
    NNSG3dRenderObj renderObjsA[FOOTPRINT_MODEL_COUNT];
    NNSG3dRenderObj renderObjsB[FOOTPRINT_MODEL_COUNT];
};

typedef struct FootprintEffectArgs {
    u32 kind;
    RenderModelStorage *model;
    NNSG3dRenderObj *renderObj;
} FootprintEffectArgs;

typedef struct FootprintEffect {
    int state;
    int timer;
    BOOL hidden;
    int alpha;
    u32 kind;
    RenderModelStorage *model;
    NNSG3dRenderObj *renderObj;
} FootprintEffect;

static void Footprints_LoadModels(Footprints *footprints);
static void Footprints_FreeModels(Footprints *footprints);
static NNSG3dRenderObj *Footprints_GetRenderObj(Footprints *footprints, u32 kind, u32 direction, u32 prevDirection);
static RenderModelStorage *Footprints_GetModel(Footprints *footprints, u32 kind, u32 direction, u32 prevDirection);
static BOOL Footprints_Spawn(LocalMapObject *mapObject, u32 kind);
static BOOL FootprintEffect_Init(FieldEffect *effect, void *state);
static void FootprintEffect_Destroy(FieldEffect *effect, void *state);
static void FootprintEffect_Update(FieldEffect *effect, void *state);
static void FootprintEffect_Draw(FieldEffect *effect, void *state);

static const FieldEffectBasicTemplate sFootprintEffectTemplate = {
    sizeof(FootprintEffect),
    FootprintEffect_Init,
    FootprintEffect_Destroy,
    FootprintEffect_Update,
    FootprintEffect_Draw,
};

// model files of bank B (bank A below)
static const u32 sFootprintModelFilesB[FOOTPRINT_MODEL_COUNT] = {
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E,
    0x5F,
    0x60,
    0x61,
    0x62,
    0x63,
};

// model files of bank A
static const u32 sFootprintModelFilesA[FOOTPRINT_MODEL_COUNT] = {
    0x4A,
    0x4B,
    0x4C,
    0x4D,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
};

// track piece by [previous facing][facing]
static const u32 sFootprintTrackPieces[4][4] = {
    { 4, 4, 7, 6 },
    { 4, 4, 9, 8 },
    { 8, 6, 5, 5 },
    { 9, 7, 5, 5 },
};

Footprints *Footprints_New(FieldEffectManager *manager) {
    Footprints *footprints = FieldEffectManager_HeapAllocAndFill(manager, sizeof(Footprints), FALSE, 0);
    footprints->manager = manager;
    Footprints_LoadModels(footprints);
    return footprints;
}

void Footprints_Free(Footprints *footprints) {
    Footprints_FreeModels(footprints);
    FieldEffectManager_HeapFree(footprints);
}

static void Footprints_LoadModels(Footprints *footprints) {
    u32 i;

    for (i = 0; i < FOOTPRINT_MODEL_COUNT; i++) {
        FieldEffectManager_LoadRenderModel(footprints->manager, &footprints->modelsA[i], 0, sFootprintModelFilesA[i], FALSE);
        RenderObj_InitFromModel(&footprints->renderObjsA[i], &footprints->modelsA[i]);
        FieldEffectManager_LoadRenderModel(footprints->manager, &footprints->modelsB[i], 0, sFootprintModelFilesB[i], FALSE);
        RenderObj_InitFromModel(&footprints->renderObjsB[i], &footprints->modelsB[i]);
    }
}

static void Footprints_FreeModels(Footprints *footprints) {
    int i;

    for (i = 0; i < FOOTPRINT_MODEL_COUNT; i++) {
        RenderModel_Free(&footprints->modelsA[i]);
        RenderModel_Free(&footprints->modelsB[i]);
    }
}

static NNSG3dRenderObj *Footprints_GetRenderObj(Footprints *footprints, u32 kind, u32 direction, u32 prevDirection) {
    NNSG3dRenderObj *renderObj = NULL;

    switch (kind) {
    case 0:
        renderObj = &footprints->renderObjsA[direction];
        break;
    case 1:
        renderObj = &footprints->renderObjsA[sFootprintTrackPieces[prevDirection][direction]];
        break;
    case 2:
    case 4:
        renderObj = &footprints->renderObjsB[direction];
        break;
    case 3:
        renderObj = &footprints->renderObjsB[sFootprintTrackPieces[prevDirection][direction]];
        break;
    }

    GF_ASSERT(renderObj != NULL);
    return renderObj;
}

static RenderModelStorage *Footprints_GetModel(Footprints *footprints, u32 kind, u32 direction, u32 prevDirection) {
    RenderModelStorage *model = NULL;

    switch (kind) {
    case 0:
        model = &footprints->modelsA[direction];
        break;
    case 1:
        model = &footprints->modelsA[sFootprintTrackPieces[prevDirection][direction]];
        break;
    case 2:
    case 4:
        model = &footprints->modelsB[direction];
        break;
    case 3:
        model = &footprints->modelsB[sFootprintTrackPieces[prevDirection][direction]];
        break;
    }

    GF_ASSERT(model != NULL);
    return model;
}

BOOL Footprints_SpawnInSand(LocalMapObject *mapObject) {
    return Footprints_Spawn(mapObject, 0);
}

BOOL Footprints_SpawnTracksInSand(LocalMapObject *mapObject) {
    return Footprints_Spawn(mapObject, 1);
}

BOOL Footprints_SpawnInSnow(LocalMapObject *mapObject) {
    return Footprints_Spawn(mapObject, 2);
}

BOOL Footprints_SpawnOnBehavior169(LocalMapObject *mapObject) {
    return Footprints_Spawn(mapObject, 4);
}

BOOL Footprints_SpawnTracksOnBehavior169(LocalMapObject *mapObject) {
    return FALSE;
}

static BOOL Footprints_Spawn(LocalMapObject *mapObject, u32 kind) {
    VecFx32 position;
    FootprintEffectArgs args;
    int x;
    int z;
    fx32 y;
    u32 direction;
    u32 prevDirection;
    u32 priority;
    FieldEffectManager *manager;
    Footprints *footprints;

    x = MapObject_GetPreviousXCoord(mapObject);
    z = MapObject_GetPreviousZCoord(mapObject);
    y = MapObject_GetPositionVectorYCoord(mapObject);
    direction = MapObject_GetFacingDirection(mapObject);
    prevDirection = MapObject_GetPreviousFacingDirection(mapObject);
    priority = MapObject_GetPriorityPlusValue(mapObject, 2);
    manager = FieldEffectManager_GetFromMapObject(mapObject);
    footprints = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_FOOTPRINTS);
    if (MapObject_TestFlagsBits(mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        return FALSE;
    }

    args.kind = kind;
    args.renderObj = Footprints_GetRenderObj(footprints, kind, direction, prevDirection);
    args.model = Footprints_GetModel(footprints, kind, direction, prevDirection);
    SetPositionToTileCenter(x, z, &position);
    position.y = y;

    switch (kind) {
    case 0:
    case 1:
    case 4:
    case 5:
        position.y = y - FX32_CONST(8);
        if (kind == 2 || kind == 3) {
            position.z = position.z - FX32_CONST(2);
        } else {
            position.z = position.z + FX32_ONE;
        }
        break;
    case 2:
    case 3:
        position.y = y - FX32_CONST(10);
        if (kind == 2 || kind == 3) {
            position.z = position.z - FX32_CONST(2);
        } else {
            position.z = position.z + FX32_CONST(2);
        }
        break;
    }

    return (BOOL)FieldEffectManager_CreateEffect(manager, &sFootprintEffectTemplate, &position, 0, &args, priority);
}

static BOOL FootprintEffect_Init(FieldEffect *effect, void *state) {
    FootprintEffect *work = state;
    FootprintEffectArgs *args;

    work->kind = FieldEffect_GetParam(effect);
    args = FieldEffect_GetUserData(effect);
    work->renderObj = args->renderObj;
    work->model = args->model;
    work->alpha = 0x1F;
    work->kind = args->kind;
    return TRUE;
}

static void FootprintEffect_Destroy(FieldEffect *effect, void *state) {
    FootprintEffect *work = state;
}

static void FootprintEffect_Update(FieldEffect *effect, void *state) {
    FootprintEffect *work = state;
    switch (work->state) {
    case 0:
        work->timer++;
        if (work->timer >= 16) {
            work->state++;
        }
        break;
    case 1:
        work->alpha -= 2;
        if (work->alpha < 0) {
            FieldEffectManager_DestroyEffect(effect);
        }
        break;
    }
}

static void FootprintEffect_Draw(FieldEffect *effect, void *state) {
    FootprintEffect *work = state;
    VecFx32 position;

    if (!work->hidden) {
        FieldEffect_GetPosition(effect, &position);
        NNSi_G3dModifyPolygonAttrMask(work->model->model, TRUE, 0x1F << 16);
        NNS_G3dMdlSetMdlAlphaAll(work->model->model, work->alpha);
        RenderObj_DrawAt(work->renderObj, &position);
    }
}
