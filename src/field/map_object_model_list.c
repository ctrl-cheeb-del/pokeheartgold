#include "field/map_object_model_list.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"

#include "field_effects.h"
#include "map_object.h"
#include "render_animation.h"
#include "render_model.h"

// Map objects whose sprite is drawn as a 3D model (gates and the like): one model per sprite id, loaded
// up front (MapObjectModelList_Init), drawn by an effect that follows the object.

#define MAP_OBJECT_MODEL_FREE 0xFFFF


typedef struct MapObjectModel {
    u32 spriteId; // MAP_OBJECT_MODEL_FREE: free
    RenderModel model;
    NNSG3dRenderObj renderObj;
} MapObjectModel;

struct MapObjectModelList {
    FieldEffectManager *manager;
    u32 count;
    MapObjectModel *models;
};

typedef struct MapObjectModelEffectArgs {
    u32 spriteId;
    FieldEffectManager *manager;
    LocalMapObject *mapObject;
} MapObjectModelEffectArgs;

typedef struct MapObjectModelEffect {
    int unused;
    u32 objectId;
    u32 mapId;
    VecFx32 offset;
    NNSG3dRenderObj *renderObj;
    MapObjectModelEffectArgs args;
} MapObjectModelEffect;

typedef struct MapObjectModelFile {
    u32 spriteId;
    int fileId;
} MapObjectModelFile;

static void MapObjectModel_Load(MapObjectModel *model, u32 spriteId, int fileId, FieldEffectManager *manager);
static void MapObjectModel_Free(MapObjectModel *model);
static void MapObjectModelList_FreeModels(MapObjectModelList *list);
static MapObjectModel *MapObjectModelList_Find(MapObjectModelList *list, u32 spriteId);
static void MapObjectModelList_AllocModels(FieldEffectManager *manager, u32 count);
static void MapObjectModelList_AddModel(FieldEffectManager *manager, u32 spriteId, int fileId);
static NNSG3dRenderObj *MapObjectModelList_GetRenderObj(FieldEffectManager *manager, u32 spriteId);
static BOOL MapObjectModelEffect_Init(FieldEffect *effect, void *state);
static void MapObjectModelEffect_Destroy(FieldEffect *effect, void *state);
static void MapObjectModelEffect_Update(FieldEffect *effect, void *state);
static void MapObjectModelEffect_Draw(FieldEffect *effect, void *state);

static const FieldEffectBasicTemplate sMapObjectModelEffectTemplate = {
    sizeof(MapObjectModelEffect),
    MapObjectModelEffect_Init,
    MapObjectModelEffect_Destroy,
    MapObjectModelEffect_Update,
    MapObjectModelEffect_Draw,
};

static const MapObjectModelFile sMapObjectModelFiles[12] = {
    { 0xB7,  0x54 },
    { 0x100, 0x6B },
    { 0x101, 0x6C },
    { 0xFD,  0x6D },
    { 0xFB,  0x6E },
    { 0xFC,  0x6F },
    { 0xFE,  0x70 },
    { 0xFF,  0x71 },
    { 0x120, 0x72 },
    { 0x123, 0x74 },
    { 0x124, 0x73 },
    { 0x121, 0x75 },
};

MapObjectModelList *MapObjectModelList_New(FieldEffectManager *manager) {
    MapObjectModelList *list = FieldEffectManager_HeapAllocAndFill(manager, sizeof(MapObjectModelList), FALSE, 0);
    list->manager = manager;
    return list;
}

void MapObjectModelList_Free(MapObjectModelList *list) {
    MapObjectModelList_FreeModels(list);
    if (list->models != NULL) {
        FieldEffectManager_HeapFree(list->models);
    }
    FieldEffectManager_HeapFree(list);
}

static void MapObjectModel_Load(MapObjectModel *model, u32 spriteId, int fileId, FieldEffectManager *manager) {
    model->spriteId = spriteId;
    FieldEffectManager_LoadRenderModel(manager, &model->model, 0, fileId, FALSE);
    RenderObj_InitFromModel(&model->renderObj, &model->model);
}

static void MapObjectModel_Free(MapObjectModel *model) {
    model->spriteId = MAP_OBJECT_MODEL_FREE;
    RenderModel_Free(&model->model);
}

static void MapObjectModelList_FreeModels(MapObjectModelList *list) {
    u32 count = list->count;
    u32 i = 0;
    MapObjectModel *model = list->models;
    for (; i < count; i++) {
        if (model->spriteId != MAP_OBJECT_MODEL_FREE) {
            MapObjectModel_Free(model);
        }
        model++;
    }
}

static MapObjectModel *MapObjectModelList_Find(MapObjectModelList *list, u32 spriteId) {
    u32 count = list->count;
    MapObjectModel *model = list->models;
    do {
        if (model->spriteId == spriteId) {
            return model;
        }
        model++;
    } while (--count != 0);
    return NULL;
}

static void MapObjectModelList_AllocModels(FieldEffectManager *manager, u32 count) {
    MapObjectModelList *list = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_MAP_OBJECT_MODEL_LIST);
    GF_ASSERT(count != 0);
    list->count = count;
    MapObjectModel *model = FieldEffectManager_HeapAllocAndFill(manager, count * sizeof(MapObjectModel), FALSE, 0);
    list->models = model;
    do {
        model->spriteId = MAP_OBJECT_MODEL_FREE;
        model++;
    } while (--count != 0);
}

static void MapObjectModelList_AddModel(FieldEffectManager *manager, u32 spriteId, int fileId) {
    MapObjectModelList *list = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_MAP_OBJECT_MODEL_LIST);
    if (MapObjectModelList_Find(list, spriteId) == NULL) {
        MapObjectModel *model = MapObjectModelList_Find(list, MAP_OBJECT_MODEL_FREE);
        if (model == NULL) {
            GF_ASSERT(FALSE);
            return;
        }
        MapObjectModel_Load(model, spriteId, fileId, manager);
    }
}

static NNSG3dRenderObj *MapObjectModelList_GetRenderObj(FieldEffectManager *manager, u32 spriteId) {
    MapObjectModelList *list = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_MAP_OBJECT_MODEL_LIST);
    MapObjectModel *model = MapObjectModelList_Find(list, spriteId);
    GF_ASSERT(model != NULL);
    return &model->renderObj;
}

FieldEffect *MapObjectModel_CreateEffect(LocalMapObject *mapObject, const VecFx32 *offset) {
    MapObjectModelEffectArgs args;

    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);
    args.spriteId = MapObject_GetSpriteID(mapObject);
    args.manager = manager;
    args.mapObject = mapObject;
    u32 priority = MapObject_GetPriorityPlusValue(mapObject, 2);
    return FieldEffectManager_CreateEffect(manager, &sMapObjectModelEffectTemplate, offset, 0, &args, priority);
}

static BOOL MapObjectModelEffect_Init(FieldEffect *effect, void *state) {
    MapObjectModelEffect *work = state;
    MapObjectModelEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->renderObj = MapObjectModelList_GetRenderObj(work->args.manager, work->args.spriteId);
    work->mapId = MapObject_CheckFlag25(work->args.mapObject) == TRUE ? MapObject_GetFlag25MapID(work->args.mapObject) : MapObject_GetMapID(work->args.mapObject);
    FieldEffect_GetPosition(effect, &work->offset);
    return TRUE;
}

static void MapObjectModelEffect_Destroy(FieldEffect *effect, void *state) {
    MapObjectModelEffect *work = state;
}

static void MapObjectModelEffect_Update(FieldEffect *effect, void *state) {
    MapObjectModelEffect *work = state;
    VecFx32 position;
    VecFx32 facing;

    LocalMapObject *mapObject = work->args.mapObject;
    if (!MapObject_CheckIDAndMap(mapObject, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    MapObject_CopyPositionVector(mapObject, &position);
    MapObject_CopyFacingVector(mapObject, &facing);
    position.x += facing.x + work->offset.x;
    position.y += facing.y + work->offset.y;
    position.z += facing.z + work->offset.z;
    FieldEffect_SetPosition(effect, &position);
}

static void MapObjectModelEffect_Draw(FieldEffect *effect, void *state) {
    MapObjectModelEffect *work = state;
    VecFx32 position;

    FieldEffect_GetPosition(effect, &position);
    RenderObj_DrawAt(work->renderObj, &position);
}

void MapObjectModelList_Init(FieldEffectManager *manager) {
    const MapObjectModelFile *file = sMapObjectModelFiles;
    u32 i = NELEMS(sMapObjectModelFiles);
    MapObjectModelList_AllocModels(manager, i);
    do {
        MapObjectModelList_AddModel(manager, file->spriteId, file->fileId);
        file++;
    } while (--i != 0);
}
