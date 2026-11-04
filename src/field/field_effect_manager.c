#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/area_light.h"
#include "field/field_effect_manager_internal.h"

#include "billboard_lists.h"
#include "field_effects.h"
#include "field_system.h"
#include "gf_3d_render.h"
#include "map_object.h"
#include "render_animation.h"
#include "render_model.h"

static const VecFx32 sBillboardDefaultScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static void FieldEffectManager_InitRenderer(FieldEffectManager *manager, u32 id);
static void FieldEffectManager_OpenNarc(FieldEffectManager *manager);
static void FieldEffectManager_CloseNarc(FieldEffectManager *manager);
static void FieldEffectManager_ClearRenderers(FieldEffectManager *manager);
static void FieldEffectManager_AddRenderer(FieldEffectManager *manager, u32 id);
static void FieldEffectManager_FreeRenderer(FieldEffectManager *manager, FieldEffectRendererEntry *entry);
static void FieldEffectManager_FreeRenderers(FieldEffectManager *manager);
static FieldEffectRendererEntry *FieldEffectManager_GetFreeRendererEntry(FieldEffectManager *manager);
static FieldEffectRendererEntry *FieldEffectManager_FindRendererEntry(FieldEffectManager *manager, u32 id);
static void FieldEffectRendererEntry_Clear(FieldEffectRendererEntry *entry);
static void FieldEffectRendererEntry_Set(FieldEffectRendererEntry *entry, u32 id, void *data);
static BOOL FieldEffectRendererEntry_IsFree(FieldEffectRendererEntry *entry);
static const FieldEffectRendererTemplate *FieldEffect_GetRendererTemplate(u32 id);
static void FieldEffectManager_InitEffects(FieldEffectManager *manager);
static void FieldEffectManager_FreeEffects(FieldEffectManager *manager);
static void FieldEffectManager_DrawEffects(FieldEffectManager *manager);
static void FieldEffectManager_CreateGfx(FieldEffectManager *manager, enum HeapID heapID, u32 recordCount, u32 resourceCount, u32 sequenceCount, u32 resCount, int resourceHeapSize, int sequenceHeapSize, int unusedHeapSize);
static void FieldEffectManager_FreeGfx(FieldEffectManager *manager);
static void FieldEffectGfx_InitRecords(FieldEffectManager *manager, FieldEffectGfx *gfx, u32 count);
static void FieldEffectGfx_FreeRecords(FieldEffectGfx *gfx);
static void FieldEffectGfx_ReleaseRecord(FieldEffectGfx *gfx, u32 id);
static BillboardResource *FieldEffectGfx_AddRecord(FieldEffectGfx *gfx, u32 id, void *modelFile, const BillboardGfxSequence *gfxSequence, NNSG3dResTex *texture, GF_3DGfxRawResObj *texObj, const BillboardSequenceRange *ranges);
static BillboardResource *FieldEffectGfx_GetRecord(FieldEffectGfx *gfx, u32 id);
static void FieldEffectManager_ScheduleTexTransfer(FieldEffectManager *manager, int id, GF_3DGfxRawResMan *resMan);
static void FieldEffectTexTransfer_LoadVramTask(SysTask *task, void *data);
static void FieldEffectTexTransfer_FreeHeaderTask(SysTask *task, void *data);
static void FieldEffectManager_InitModel(FieldEffectManager *manager, NNSG3dRenderObj *renderObj, NNSG3dResMdl **ppMdl, NNSG3dResFileHeader **ppRes);

FieldEffectManager *FieldEffectManager_New(FieldSystem *fieldSystem, u32 rendererCount, enum HeapID heapID) {
    FieldEffectManager *manager = Heap_Alloc(heapID, sizeof(FieldEffectManager));
    memset(manager, 0, sizeof(FieldEffectManager));
    manager->heapID = heapID;
    manager->rendererCount = rendererCount;
    manager->fieldSystem = fieldSystem;
    manager->renderers = Heap_Alloc(heapID, rendererCount * sizeof(FieldEffectRendererEntry));
    FieldEffectManager_ClearRenderers(manager);
    FieldEffectManager_OpenNarc(manager);
    return manager;
}

void FieldEffectManager_InitAnimManagerList(FieldEffectManager *manager, u32 animManagerCount) {
    manager->animManagerCount = animManagerCount;
    FieldEffectManager_InitEffects(manager);
}

void FieldEffectManager_InitGfx(FieldEffectManager *manager, enum HeapID heapID, u32 recordCount, u32 resourceCount, u32 sequenceCount, u32 resCount, int resourceHeapSize, int sequenceHeapSize, int unusedHeapSize) {
    FieldEffectManager_CreateGfx(manager, heapID, recordCount, resourceCount, sequenceCount, resCount, resourceHeapSize, sequenceHeapSize, unusedHeapSize);
}

static void FieldEffectManager_InitRenderer(FieldEffectManager *manager, u32 id) {
    if (FieldEffectManager_FindRendererEntry(manager, id) != NULL) {
        GF_ASSERT(FALSE);
        return;
    }
    FieldEffectManager_AddRenderer(manager, id);
}

void FieldEffectManager_InitRenderers(FieldEffectManager *manager, const u32 *ids) {
    while (*ids != FIELD_EFFECT_RENDERER_INVALID) {
        FieldEffectManager_InitRenderer(manager, *ids);
        ids++;
    }
}

void FieldEffectManager_Render(FieldEffectManager *manager) {
    FieldEffectManager_DrawEffects(manager);
}

void FieldEffectManager_Free(FieldEffectManager *manager) {
    FieldEffectManager_FreeEffects(manager);
    FieldEffectManager_FreeRenderers(manager);
    FieldEffectManager_FreeGfx(manager);
    FieldEffectManager_CloseNarc(manager);
    Heap_Free(manager->renderers);
    Heap_Free(manager);
}

void *FieldEffectManager_HeapAlloc(FieldEffectManager *manager, u32 size, BOOL atEnd) {
    if (atEnd == FALSE) {
        return Heap_Alloc(manager->heapID, size);
    }
    return Heap_AllocAtEnd(manager->heapID, size);
}

void *FieldEffectManager_HeapAllocAndFill(FieldEffectManager *manager, u32 size, BOOL atEnd, int fill) {
    void *ptr = FieldEffectManager_HeapAlloc(manager, size, atEnd);
    memset(ptr, fill, size);
    return ptr;
}

void FieldEffectManager_HeapFree(void *ptr) {
    Heap_Free(ptr);
}

void *FieldEffectManager_GetRendererData(FieldEffectManager *manager, u32 id) {
    FieldEffectRendererEntry *entry = FieldEffectManager_FindRendererEntry(manager, id);
    if (entry == NULL) {
        GF_ASSERT(FALSE);
        return NULL;
    }
    return entry->data;
}

FieldSystem *FieldEffectManager_GetFieldSystem(FieldEffectManager *manager) {
    return manager->fieldSystem;
}

FieldEffectManager *FieldEffectManager_GetFromMapObject(LocalMapObject *mapObject) {
    return MapObject_GetFieldSystem(mapObject)->fieldEffectManager;
}

enum HeapID FieldEffectManager_GetHeapID(FieldEffectManager *manager) {
    return manager->heapID;
}

static void FieldEffectManager_OpenNarc(FieldEffectManager *manager) {
    manager->narc = NARC_New(NARC_a_1_0_3, FieldEffectManager_GetHeapID(manager));
}

static void FieldEffectManager_CloseNarc(FieldEffectManager *manager) {
    NARC_Delete(manager->narc);
}

u32 FieldEffectManager_GetNarcMemberSize(FieldEffectManager *manager, u32 fileId) {
    return NARC_GetMemberSize(manager->narc, fileId);
}

void FieldEffectManager_ReadNarcMember(FieldEffectManager *manager, u32 fileId, void *dest) {
    NARC_ReadWholeMember(manager->narc, fileId, dest);
}

void *FieldEffectManager_LoadNarcMember(FieldEffectManager *manager, u32 fileId, BOOL atEnd) {
    void *data = FieldEffectManager_HeapAlloc(manager, NARC_GetMemberSize(manager->narc, fileId), atEnd);
    NARC_ReadWholeMember(manager->narc, fileId, data);
    return data;
}

static void FieldEffectManager_ClearRenderers(FieldEffectManager *manager) {
    u32 i = manager->rendererCount;
    FieldEffectRendererEntry *entry = manager->renderers;
    while (i != 0) {
        FieldEffectRendererEntry_Clear(entry);
        entry++;
        i--;
    }
}

static void FieldEffectManager_AddRenderer(FieldEffectManager *manager, u32 id) {
    void *data = FieldEffect_GetRendererTemplate(id)->init(manager);
    FieldEffectRendererEntry_Set(FieldEffectManager_GetFreeRendererEntry(manager), id, data);
}

static void FieldEffectManager_FreeRenderer(FieldEffectManager *manager, FieldEffectRendererEntry *entry) {
    FieldEffect_GetRendererTemplate(entry->id)->free(entry->data);
    FieldEffectRendererEntry_Clear(entry);
}

static void FieldEffectManager_FreeRenderers(FieldEffectManager *manager) {
    u32 i = manager->rendererCount;
    FieldEffectRendererEntry *entry = manager->renderers;
    while (i != 0) {
        if (!FieldEffectRendererEntry_IsFree(entry)) {
            FieldEffectManager_FreeRenderer(manager, entry);
        }
        entry++;
        i--;
    }
}

static FieldEffectRendererEntry *FieldEffectManager_GetFreeRendererEntry(FieldEffectManager *manager) {
    u32 i = manager->rendererCount;
    FieldEffectRendererEntry *entry = manager->renderers;
    while (i != 0) {
        if (FieldEffectRendererEntry_IsFree(entry) == TRUE) {
            return entry;
        }
        entry++;
        i--;
    }
    GF_ASSERT(FALSE);
    return NULL;
}

static FieldEffectRendererEntry *FieldEffectManager_FindRendererEntry(FieldEffectManager *manager, u32 id) {
    u32 i = manager->rendererCount;
    FieldEffectRendererEntry *entry = manager->renderers;
    while (i != 0) {
        if (entry->id == id) {
            return entry;
        }
        entry++;
        i--;
    }
    return NULL;
}

static void FieldEffectRendererEntry_Clear(FieldEffectRendererEntry *entry) {
    entry->id = FIELD_EFFECT_RENDERER_INVALID;
    entry->data = NULL;
}

static void FieldEffectRendererEntry_Set(FieldEffectRendererEntry *entry, u32 id, void *data) {
    entry->id = id;
    entry->data = data;
}

static BOOL FieldEffectRendererEntry_IsFree(FieldEffectRendererEntry *entry) {
    if (entry->id == FIELD_EFFECT_RENDERER_INVALID) {
        return TRUE;
    }
    return FALSE;
}

static const FieldEffectRendererTemplate *FieldEffect_GetRendererTemplate(u32 id) {
    const FieldEffectRendererTemplate *renderer = gFieldEffectRenderers;
    while (renderer->id != FIELD_EFFECT_RENDERER_INVALID) {
        if (renderer->id == id) {
            return renderer;
        }
        renderer++;
    }
    GF_ASSERT(FALSE);
    return NULL;
}

static void FieldEffectManager_InitEffects(FieldEffectManager *manager) {
    manager->effects = FieldEffectPool_New(manager->heapID, manager->animManagerCount);
}

static void FieldEffectManager_FreeEffects(FieldEffectManager *manager) {
    if (manager->effects != NULL) {
        FieldEffectPool_Delete(manager->effects);
        manager->effects = NULL;
    }
}

static void FieldEffectManager_DrawEffects(FieldEffectManager *manager) {
    if (manager->effects != NULL) {
        FieldEffectPool_DrawAll(manager->effects);
    }
}

FieldEffect *FieldEffectManager_CreateEffect(FieldEffectManager *manager, const FieldEffectBasicTemplate *template, const VecFx32 *position, int parameter, void *userData, u32 priority) {
    FieldEffect *effect = FieldEffectPool_AddBasicEffect(manager->effects, template, position, parameter, userData, priority);
    GF_ASSERT(effect != NULL);
    return effect;
}

void FieldEffectManager_DestroyEffect(FieldEffect *effect) {
    FieldEffect_Destroy(effect);
}

static void FieldEffectManager_CreateGfx(FieldEffectManager *manager, enum HeapID heapID, u32 recordCount, u32 resourceCount, u32 sequenceCount, u32 resCount, int resourceHeapSize, int sequenceHeapSize, int unusedHeapSize) {
    BillboardCreateParams params;
    FieldEffectGfx *gfx = FieldEffectManager_HeapAllocAndFill(manager, sizeof(FieldEffectGfx), FALSE, 0);
#pragma unused(unusedHeapSize)
    manager->gfx = gfx;
    gfx->heapID = heapID;
    gfx->recordCount = recordCount;
    gfx->resourceCount = resourceCount;
    gfx->sequenceCount = sequenceCount;
    gfx->resCount = resCount;
    gfx->resourceBank = ResourceBank_Create(heapID, HEAP_ID_68, resourceHeapSize, resourceCount);
    gfx->sequenceBank = ResourceBank_Create(heapID, HEAP_ID_69, sequenceHeapSize, sequenceCount);
    gfx->resMan = GF3dGfxRawResMan_Create(resCount, heapID);
    FieldEffectGfx_InitRecords(manager, gfx, recordCount);
    params.count = recordCount;
    params.heapId = FieldEffectManager_GetHeapID(manager);
    gfx->billboards = Billboard_Create(&params);
}

static void FieldEffectManager_FreeGfx(FieldEffectManager *manager) {
    FieldEffectGfx *gfx = manager->gfx;
    if (gfx != NULL) {
        Billboard_Delete(gfx->billboards);
        FieldEffectGfx_FreeRecords(gfx);
        ResourceBank_Destroy(gfx->resourceBank);
        ResourceBank_Destroy(gfx->sequenceBank);
        GF3dGfxRawResMan_Destroy(gfx->resMan);
        FieldEffectManager_HeapFree(gfx);
        manager->gfx = NULL;
    }
}

BillboardObject *FieldEffectManager_CreateBillboard(FieldEffectManager *manager, BillboardResource *resource, const VecFx32 *position) {
    BillboardObjectCreateParams params;
    BillboardObject *billboard;
    params.billboard = manager->gfx->billboards;
    params.resource = resource;
    params.position = *position;
    params.scale = sBillboardDefaultScale;
    billboard = BillboardObject_Create(&params);
    GF_ASSERT(billboard != NULL);
    if (billboard != NULL) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(BillboardObject_GetModel(billboard), TRUE);
        AreaLight_ClearMaterialModifyFlags(BillboardObject_GetModel(billboard));
    }
    return billboard;
}

BillboardObject *FieldEffectManager_CreateBillboardFromRecord(FieldEffectManager *manager, u32 id, const VecFx32 *position) {
    return FieldEffectManager_CreateBillboard(manager, FieldEffectGfx_GetRecord(manager->gfx, id), position);
}

static inline FieldEffectGfx *FieldEffectManager_GetGfx(FieldEffectManager *manager) {
    return manager->gfx;
}

BillboardResource *FieldEffectManager_AddRecord(FieldEffectManager *manager, u32 id, int resourceId, int sequenceId, int resId, int noTexKeys, const BillboardSequenceRange *ranges) {
    BillboardGfxSequence sequence;
    int seqId = sequenceId;
    FieldEffectGfx *gfx = FieldEffectManager_GetGfx(manager);
    void *data = ResourceBank_Get(gfx->resourceBank, resourceId);
    GF_3DGfxRawResObj *texObj;
    NNSG3dResTex *tex;
    BillboardResource *record;
    BillboardGfxSequence_Init(ResourceBank_Get(gfx->sequenceBank, seqId), &sequence);
    texObj = GF3dGfxRawResMan_GetObjById(gfx->resMan, resId);
    GF_ASSERT(texObj);
    tex = GF3dGfxRawResObj_GetTex(texObj);
    if (noTexKeys == TRUE) {
        texObj = NULL;
    }
    record = FieldEffectGfx_AddRecord(gfx, id, data, &sequence, tex, texObj, ranges);
    GF_ASSERT(record);
    return record;
}

static void FieldEffectGfx_InitRecords(FieldEffectManager *manager, FieldEffectGfx *gfx, u32 count) {
    BillboardResource *records = FieldEffectManager_HeapAlloc(manager, count * sizeof(BillboardResource), FALSE);
    FieldEffectRecordSlot *slots;
    gfx->records = records;
    slots = FieldEffectManager_HeapAlloc(manager, count * sizeof(FieldEffectRecordSlot), FALSE);
    gfx->slots = slots;
    do {
        slots->id = FIELD_EFFECT_RECORD_SLOT_FREE;
        slots->record = records;
        slots++;
        records++;
    } while (--count != 0);
}

static void FieldEffectGfx_FreeRecords(FieldEffectGfx *gfx) {
    FieldEffectManager_HeapFree(gfx->slots);
    FieldEffectManager_HeapFree(gfx->records);
}

static void FieldEffectGfx_ReleaseRecord(FieldEffectGfx *gfx, u32 id) {
    u32 i = gfx->recordCount;
    FieldEffectRecordSlot *slot = gfx->slots;
    do {
        if (slot->id == id) {
            slot->id = FIELD_EFFECT_RECORD_SLOT_FREE;
            return;
        }
        slot++;
    } while (--i != 0);
    GF_ASSERT(FALSE);
}

static BillboardResource *FieldEffectGfx_AddRecord(FieldEffectGfx *gfx, u32 id, void *modelFile, const BillboardGfxSequence *gfxSequence, NNSG3dResTex *texture, GF_3DGfxRawResObj *texObj, const BillboardSequenceRange *ranges) {
    BillboardResource *record = NULL;
    u32 count = gfx->recordCount;
    FieldEffectRecordSlot *slots = gfx->slots;
    u32 i;
    FieldEffectRecordSlot *slot;
    i = count;
    slot = slots;
    do {
        if (slot->id == id) {
            return slot->record;
        }
        slot++;
    } while (--i);
    i = count;
    slot = slots;
    do {
        if (slot->id == FIELD_EFFECT_RECORD_SLOT_FREE) {
            slot->id = id;
            record = slot->record;
            break;
        }
        slot++;
    } while (--i);
    GF_ASSERT(record != NULL);
    memset(record, 0, sizeof(BillboardResource));
    record->modelFile = modelFile;
    record->gfxSequence = *gfxSequence;
    record->texture = texture;
    if (texObj != NULL) {
        record->texKey = GF3dGfxRawResObj_GetTexKey(texObj);
        record->tex4x4Key = GF3dGfxRawResObj_GetTex4x4Key(texObj);
        record->plttKey = GF3dGfxRawResObj_GetPlttKey(texObj);
    }
    record->ranges = ranges;
    return record;
}

static BillboardResource *FieldEffectGfx_GetRecord(FieldEffectGfx *gfx, u32 id) {
    u32 i = gfx->recordCount;
    FieldEffectRecordSlot *slot = gfx->slots;
    do {
        if (slot->id == id) {
            return slot->record;
        }
        slot++;
    } while (--i != 0);
    GF_ASSERT(FALSE);
    return NULL;
}

void FieldEffectManager_ReleaseRecord(FieldEffectManager *manager, u32 id) {
    FieldEffectGfx_ReleaseRecord(manager->gfx, id);
}

void FieldEffectManager_LoadBillboardResource(FieldEffectManager *manager, int id, int fileId) {
    ResourceBank_LoadFromNarc(manager->gfx->resourceBank, id, manager->narc, fileId, FALSE);
}

void *FieldEffectManager_GetBillboardResource(FieldEffectManager *manager, int id) {
    return ResourceBank_Get(manager->gfx->resourceBank, id);
}

void FieldEffectManager_FreeBillboardResource(FieldEffectManager *manager, int id) {
    ResourceBank_Free(manager->gfx->resourceBank, id);
}

void FieldEffectManager_LoadBillboardSequence(FieldEffectManager *manager, int id, int fileId) {
    ResourceBank_LoadFromNarc(manager->gfx->sequenceBank, id, manager->narc, fileId, FALSE);
}

void FieldEffectManager_FreeBillboardSequence(FieldEffectManager *manager, int id) {
    ResourceBank_Free(manager->gfx->sequenceBank, id);
}

void FieldEffectManager_LoadTexResource(FieldEffectManager *manager, int id, u32 fileId, BOOL copyWithoutTex) {
    FieldEffectGfx *gfx = manager->gfx;
    void *data = FieldEffectManager_LoadNarcMember(manager, fileId, TRUE);
    GF_ASSERT(GF3dGfxRawResMan_AllocObjAndKeys(gfx->resMan, data, id, copyWithoutTex, FieldEffectManager_GetHeapID(manager)) != NULL);
    FieldEffectManager_ScheduleTexTransfer(manager, id, gfx->resMan);
}

void FieldEffectManager_FreeTexResource(FieldEffectManager *manager, int id) {
    GF3dGfxRawResMan_FreeObjById(manager->gfx->resMan, id);
}

// Uploads the texture in the next VBlank, then drops its CPU copy.
static void FieldEffectManager_ScheduleTexTransfer(FieldEffectManager *manager, int id, GF_3DGfxRawResMan *resMan) {
    FieldEffectTexTransfer *transfer = FieldEffectManager_HeapAlloc(manager, sizeof(FieldEffectTexTransfer), TRUE);
    transfer->state = 1;
    transfer->id = id;
    transfer->resMan = resMan;
    SysTask_CreateOnVBlankQueue(FieldEffectTexTransfer_LoadVramTask, transfer, 0xFF);
    SysTask_CreateOnVWaitQueue(FieldEffectTexTransfer_FreeHeaderTask, transfer, 0xFF);
}

static void FieldEffectTexTransfer_LoadVramTask(SysTask *task, void *data) {
    FieldEffectTexTransfer *transfer = data;
    GF3dGfxRawResMan_LoadObjTexById(transfer->resMan, transfer->id);
    transfer->state = 1;
    SysTask_Destroy(task);
}

static void FieldEffectTexTransfer_FreeHeaderTask(SysTask *task, void *data) {
    FieldEffectTexTransfer *transfer = data;
    if (transfer->state == 1) {
        GF3dGfxRawResMan_FreeObjVramAndSecondaryHeaderById(transfer->resMan, transfer->id);
        FieldEffectManager_HeapFree(transfer);
        SysTask_Destroy(task);
    }
}

void FieldEffectManager_LoadRenderModel(FieldEffectManager *manager, RenderModel *model, int index, int fileId, BOOL atEnd) {
    RenderModel_LoadFromNarc(model, index, manager->narc, fileId, manager->heapID, atEnd);
    RenderModel_BindTexturesOnVBlank(model);
}

void FieldEffectManager_LoadRenderAnimation(FieldEffectManager *manager, RenderAnimation *animation, int index, int fileId, BOOL atEnd) {
    RenderAnimation_LoadFromNarc(animation, index, manager->narc, fileId, manager->heapID, atEnd);
}

void FieldEffectManager_InitRenderAnimation(FieldEffectManager *manager, RenderAnimation *animation, RenderModel *model, RenderAnimation *source, int unused) {
    RenderAnimation_InitForModel(animation, model, source, unused, manager->heapID);
}

static void FieldEffectManager_InitModel(FieldEffectManager *manager, NNSG3dRenderObj *renderObj, NNSG3dResMdl **ppMdl, NNSG3dResFileHeader **ppRes) {
    NNSG3dResTex *tex = NNS_G3dGetTex(*ppRes);
    if (tex != NULL && !GF3dRender_ResTexIsLoaded(tex)) {
        DC_FlushRange(*ppRes, (*ppRes)->fileSize);
        if (!NNS_G3dResDefaultSetup(*ppRes)) {
            GF_ASSERT(FALSE);
        }
    }
    *ppMdl = NNS_G3dGetMdlByIdx(NNS_G3dGetMdlSet(*ppRes), 0);
    GF_ASSERT(ppMdl != NULL);
    NNS_G3dRenderObjInit(renderObj, *ppMdl);
}

void FieldEffectManager_LoadModel(FieldEffectManager *manager, u32 fileId, BOOL atEnd, NNSG3dRenderObj *renderObj, NNSG3dResMdl **ppMdl, NNSG3dResFileHeader **ppRes) {
    *ppRes = FieldEffectManager_LoadNarcMember(manager, fileId, atEnd);
    FieldEffectManager_InitModel(manager, renderObj, ppMdl, ppRes);
}

NNSG3dResTex *FieldEffectManager_GetTexture(FieldEffectManager *manager, u32 id) {
    NNSG3dResTex *tex;
    GF_3DGfxRawResObj *texObj = GF3dGfxRawResMan_GetObjById(manager->gfx->resMan, id);
    tex = NULL;
    GF_ASSERT(texObj);
    if (texObj != NULL) {
        tex = GF3dGfxRawResObj_GetTex(texObj);
    }
    return tex;
}
