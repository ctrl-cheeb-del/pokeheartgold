#include "field_hidden_object_cover.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_manager.h"

#include "field_effects.h"
#include "map_object.h"
#include "map_object_follow.h"
#include "map_object_movement_utilities.h"
#include "player_avatar.h"
#include "render_animation.h"
#include "render_model.h"

struct HiddenObjectCover {
    FieldEffectManager *manager;
    RenderModel models[4];
    NNSG3dRenderObj renderObjs[4];
};

typedef struct HiddenObjectCoverEffectArgs {
    int coverIndex;
    FieldEffectManager *manager;
    HiddenObjectCover *cover;
    LocalMapObject *mapObject;
    NNSG3dRenderObj *renderObj;
} HiddenObjectCoverEffectArgs;

typedef struct HiddenObjectCoverEffect {
    int unk_00;
    BOOL unk_04;
    u32 localMapObjectId;
    u32 mapId;
    HiddenObjectCoverEffectArgs args;
} HiddenObjectCoverEffect;

static void HiddenObjectCover_LoadModels(HiddenObjectCover *cover);
static void HiddenObjectCover_FreeModels(HiddenObjectCover *cover);
static BOOL HiddenObjectCoverEffect_Init(FieldEffect *effect, void *state);
static void HiddenObjectCoverEffect_Destroy(FieldEffect *effect, void *state);
static void HiddenObjectCoverEffect_Update(FieldEffect *effect, void *state);
static void HiddenObjectCoverEffect_Draw(FieldEffect *effect, void *state);

static const int sHiddenObjectCoverModelFiles[4] = { 0x64, 0x65, 0x66, 0x67 };
static const FieldEffectBasicTemplate sHiddenObjectCoverEffectTemplate = {
    sizeof(HiddenObjectCoverEffect),
    HiddenObjectCoverEffect_Init,
    HiddenObjectCoverEffect_Destroy,
    HiddenObjectCoverEffect_Update,
    HiddenObjectCoverEffect_Draw,
};

HiddenObjectCover *HiddenObjectCover_New(FieldEffectManager *manager) {
    HiddenObjectCover *cover = FieldEffectManager_HeapAllocAndFill(manager, sizeof(HiddenObjectCover), FALSE, 0);
    cover->manager = manager;
    HiddenObjectCover_LoadModels(cover);
    return cover;
}

void HiddenObjectCover_Free(HiddenObjectCover *cover) {
    HiddenObjectCover_FreeModels(cover);
    FieldEffectManager_HeapFree(cover);
}

static void HiddenObjectCover_LoadModels(HiddenObjectCover *cover) {
    for (int i = 0; i < 4; i++) {
        FieldEffectManager_LoadRenderModel(cover->manager, &cover->models[i], 0, sHiddenObjectCoverModelFiles[i], FALSE);
        RenderObj_InitFromModel(&cover->renderObjs[i], &cover->models[i]);
    }
}

static void HiddenObjectCover_FreeModels(HiddenObjectCover *cover) {
    for (int i = 0; i < 4; i++) {
        RenderModel_Free(&cover->models[i]);
    }
}

static NNSG3dRenderObj *HiddenObjectCover_GetRenderObj(HiddenObjectCover *cover, int index) {
    return &cover->renderObjs[index];
}

FieldEffect *HiddenObjectCover_Spawn(LocalMapObject *mapObject, int coverType) {
    VecFx32 position;
    HiddenObjectCoverEffectArgs args;

    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);
    FieldSystem *fieldSystem = FieldEffectManager_GetFieldSystem(manager);

    int x = MapObject_GetXCoord(mapObject);
    int z = MapObject_GetZCoord(mapObject);

    SetPositionToTileCenter(x, z, &position);
    FieldSystem_SnapToTerrainHeight(fieldSystem, &position);

    args.coverIndex = coverType;
    args.manager = manager;

    HiddenObjectCover *cover = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_HIDDEN_OBJECT_COVER);
    args.cover = cover;
    args.mapObject = mapObject;
    args.renderObj = HiddenObjectCover_GetRenderObj(cover, coverType);

    u32 priority = MapObject_GetPriorityPlusValue(mapObject, 2);
    return FieldEffectManager_CreateEffect(manager, &sHiddenObjectCoverEffectTemplate, &position, 0, &args, priority);
}

static BOOL HiddenObjectCoverEffect_Init(FieldEffect *effect, void *state) {
    HiddenObjectCoverEffect *coverEffect = state;
    HiddenObjectCoverEffectArgs *args = FieldEffect_GetUserData(effect);
    LocalMapObject *mapObject = args->mapObject;

    coverEffect->args = *args;
    coverEffect->localMapObjectId = MapObject_GetID(mapObject);
    coverEffect->mapId = MapObject_GetMapID(mapObject);
    return TRUE;
}

static void HiddenObjectCoverEffect_Destroy(FieldEffect *effect, void *state) {
    HiddenObjectCoverEffect *coverEffect = state;
    LocalMapObject *mapObject = coverEffect->args.mapObject;

    if (MapObject_CheckIDAndMap(mapObject, coverEffect->localMapObjectId, coverEffect->mapId) == TRUE) {
        HiddenObjectMovement_SetCoverEffect(mapObject, NULL);
    }
}

static void HiddenObjectCoverEffect_Update(FieldEffect *effect, void *state) {
    HiddenObjectCoverEffect *coverEffect = state;
}

static void HiddenObjectCoverEffect_Draw(FieldEffect *effect, void *state) {
    HiddenObjectCoverEffect *coverEffect = state;
    VecFx32 translation;

    if (coverEffect->unk_04 != TRUE) {
        FieldEffect_GetPosition(effect, &translation);
        RenderObj_DrawAt(coverEffect->args.renderObj, &translation);
    }
}
