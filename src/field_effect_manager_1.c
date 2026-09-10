#include "field_effect_manager_internal.h"

// ---- external prototypes (declared locally; see report.md for proposals) ----
void *NARC_New(int narcId, enum HeapID heapID);
void NARC_Delete(void *narc);
u32 NARC_GetMemberSize(void *narc, u32 fileId);
void NARC_ReadWholeMember(void *narc, u32 fileId, void *dest);
void *MapObject_GetFieldSystem(void *mapObject);
void *sub_020689C8(enum HeapID heapID, u32 count);
void sub_020689F8(void *manager);
void sub_02068BAC(void *manager);
void *sub_02068B0C(void *manager, const void *tmpl, void *pos, int param, void *userData, u32 priority);
void sub_02068B48(int a0);
void *sub_020237EC(const FieldEffectAnimReq *req);
void sub_02023874(void *a0);
void *sub_02023D44(const FieldEffectModelReq *req);
NNSG3dResMdl *sub_02023F90(void *a0);
void sub_02026E18(void *a0, FieldEffectMtx *out);
void *ov01_021FC4C4(enum HeapID heapID, int a1, int a2, int a3);
void ov01_021FC520(void *a0);
void *ov01_021FC5A4(void *a0, int a1);
void *ov01_021FC588(void *a0, int a1);
void ov01_021FC5CC(void *a0, int a1, void *narc, int a3, int a4);
void ov01_021EA3B0(NNSG3dResMdl *mdl);
void NNS_G3dMdlSetMdlFogEnableFlagAll(NNSG3dResMdl *mdl, int flag);
void sub_020696C4(void *a0, int a1, void *resMan, int a2, enum HeapID heapID, int a3);
void sub_02069714(void *a0);
void sub_020697DC(void *a0, int a1, void *resMan, int a2, enum HeapID heapID, int a3);
void sub_02069894(void *a0, int a1, int a2, int a3, enum HeapID heapID);
void *GF3dGfxRawResMan_Create(int num, enum HeapID heapID);
void GF3dGfxRawResMan_Destroy(void *man);
void *GF3dGfxRawResMan_AllocObjAndKeys(void *man, void *res, int id, BOOL copyWithoutTex, enum HeapID heapID);
void GF3dGfxRawResMan_FreeObjById(void *man, int id);
void *GF3dGfxRawResMan_GetObjById(void *man, int id);
NNSG3dResTex *GF3dGfxRawResObj_GetTex(void *obj);
void GF3dGfxRawResMan_LoadObjTexById(void *man, int id);
void GF3dGfxRawResMan_FreeObjVramAndSecondaryHeaderById(void *man, int id);
u32 GF3dGfxRawResObj_GetTexKey(void *obj);
u32 GF3dGfxRawResObj_GetTex4x4Key(void *obj);
u32 GF3dGfxRawResObj_GetPlttKey(void *obj);
BOOL GF3dRender_ResTexIsLoaded(NNSG3dResTex *tex);
struct SysTask *SysTask_CreateOnVBlankQueue(FieldEffectTaskFunc func, void *data, u32 priority);
struct SysTask *SysTask_CreateOnVWaitQueue(FieldEffectTaskFunc func, void *data, u32 priority);
void SysTask_Destroy(struct SysTask *task);

// ---- this module ----
FieldEffectManager *FieldEffectManager_New(void *fieldSystem, u32 rendererCount, enum HeapID heapID);
void FieldEffectManager_InitAnimManagerList(FieldEffectManager *manager, u32 animManagerCount);
void ov01_021F1390(FieldEffectManager *manager, enum HeapID heapID, u32 a2, u32 a3, u32 a4, u32 a5, int a6, int a7, int a8);
void ov01_021F13B0(FieldEffectManager *manager, u32 id);
void FieldEffectManager_InitRenderers(FieldEffectManager *manager, const u32 *ids);
void FieldEffectManager_Render(FieldEffectManager *manager);
void FieldEffectManager_Free(FieldEffectManager *manager);
void *ov01_021F141C(FieldEffectManager *manager, u32 size, int atEnd);
void *ov01_021F1430(FieldEffectManager *manager, u32 size, int atEnd, int fill);
void ov01_021F1448(void *ptr);
void *ov01_021F1450(FieldEffectManager *manager, u32 id);
void *ov01_021F1468(FieldEffectManager *manager);
FieldEffectManager *ov01_021F146C(void *mapObject);
enum HeapID ov01_021F1478(FieldEffectManager *manager);
void ov01_021F147C(FieldEffectManager *manager);
void ov01_021F1490(FieldEffectManager *manager);
u32 ov01_021F149C(FieldEffectManager *manager, u32 fileId);
void ov01_021F14A8(FieldEffectManager *manager, u32 fileId, void *dest);
void *ov01_021F14B4(FieldEffectManager *manager, u32 fileId, int atEnd);
void ov01_021F14DC(FieldEffectManager *manager);
void ov01_021F14F4(FieldEffectManager *manager, u32 id);
void ov01_021F151C(FieldEffectManager *manager, FieldEffectEntry *entry);
void ov01_021F1538(FieldEffectManager *manager);
FieldEffectEntry *ov01_021F1560(FieldEffectManager *manager);
FieldEffectEntry *ov01_021F1588(FieldEffectManager *manager, u32 id);
void ov01_021F15A0(FieldEffectEntry *entry);
void ov01_021F15AC(FieldEffectEntry *entry, u32 id, void *data);
BOOL ov01_021F15B4(FieldEffectEntry *entry);
const FieldEffectRenderer *ov01_021F15C4(u32 id);
void ov01_021F15EC(FieldEffectManager *manager);
void ov01_021F15FC(FieldEffectManager *manager);
void ov01_021F1610(FieldEffectManager *manager);
void *ov01_021F1620(FieldEffectManager *manager, const void *tmpl, void *pos, int param, void *userData, u32 priority);
void ov01_021F1640(int a0);
void ov01_021F1648(FieldEffectManager *manager, enum HeapID heapID, u32 a2, u32 a3, u32 a4, u32 a5, int a6, int a7, int a8);
void ov01_021F16B8(FieldEffectManager *manager);
void *ov01_021F16EC(FieldEffectManager *manager, void *a1, const VecFx32 *position);
void *ov01_021F1740(FieldEffectManager *manager, u32 id, const VecFx32 *position);
FieldEffectRecord *ov01_021F1758(FieldEffectManager *manager, u32 key, int a2, int a3, int objId, int a5, int a6);
void ov01_021F17BC(FieldEffectManager *manager, FieldEffectGfx *gfx, u32 count);
void ov01_021F17F0(FieldEffectGfx *gfx);
void ov01_021F1804(FieldEffectGfx *gfx, u32 id);
FieldEffectRecord *ov01_021F1824(FieldEffectGfx *gfx, u32 key, void *a2, const FieldEffectMtx *src, void *tex, void *obj, int a6);
FieldEffectRecord *ov01_021F18A8(FieldEffectGfx *gfx, u32 id);
void ov01_021F18C8(FieldEffectManager *manager, u32 id);
void ov01_021F18D4(FieldEffectManager *manager, int a1, int a2);
void *ov01_021F18F0(FieldEffectManager *manager, int a1);
void *ov01_021F18FC(FieldEffectManager *manager, int a1);
void ov01_021F1908(FieldEffectManager *manager, int a1, int a2);
void *ov01_021F1924(FieldEffectManager *manager, int a1);
void ov01_021F1930(FieldEffectManager *manager, int id, u32 fileId, BOOL copyWithoutTex);
void ov01_021F1970(FieldEffectManager *manager, int id);
void ov01_021F197C(FieldEffectManager *manager, int id, void *resMan);
void ov01_021F19B4(struct SysTask *task, void *data);
void ov01_021F19D0(struct SysTask *task, void *data);
void ov01_021F19F4(FieldEffectGfx *gfx, void *a1, int a2, int a3, int a4);
void ov01_021F1A18(FieldEffectGfx *gfx, void *a1, int a2, int a3, int a4);
void ov01_021F1A34(FieldEffectGfx *gfx, void *a1, int a2, int a3, int a4);
void ov01_021F1A48(FieldEffectManager *manager, NNSG3dRenderObj *renderObj, NNSG3dResMdl **ppMdl, void **ppRes);
void ov01_021F1AB8(FieldEffectManager *manager, u32 fileId, int atEnd, NNSG3dRenderObj *renderObj, NNSG3dResMdl **ppMdl, void **ppRes);
NNSG3dResTex *ov01_021F1AD4(FieldEffectManager *manager, int id);

extern const VecFx32 ov01_02206988;

FieldEffectManager *FieldEffectManager_New(void *fieldSystem, u32 rendererCount, enum HeapID heapID) {
    FieldEffectManager *manager = Heap_Alloc(heapID, sizeof(FieldEffectManager));
    memset(manager, 0, sizeof(FieldEffectManager));
    manager->heapID = heapID;
    manager->count = rendererCount;
    manager->fieldSystem = fieldSystem;
    manager->entries = Heap_Alloc(heapID, rendererCount * sizeof(FieldEffectEntry));
    ov01_021F14DC(manager);
    ov01_021F147C(manager);
    return manager;
}

void FieldEffectManager_InitAnimManagerList(FieldEffectManager *manager, u32 animManagerCount) {
    manager->animManagerCount = animManagerCount;
    ov01_021F15EC(manager);
}

void ov01_021F1390(FieldEffectManager *manager, enum HeapID heapID, u32 a2, u32 a3, u32 a4, u32 a5, int a6, int a7, int a8) {
    ov01_021F1648(manager, heapID, a2, a3, a4, a5, a6, a7, a8);
}

void ov01_021F13B0(FieldEffectManager *manager, u32 id) {
    if (ov01_021F1588(manager, id) != NULL) {
        GF_AssertFail();
        return;
    }
    ov01_021F14F4(manager, id);
}

void FieldEffectManager_InitRenderers(FieldEffectManager *manager, const u32 *ids) {
    while (*ids != 0x17) {
        ov01_021F13B0(manager, *ids);
        ids++;
    }
}

void FieldEffectManager_Render(FieldEffectManager *manager) {
    ov01_021F1610(manager);
}

void FieldEffectManager_Free(FieldEffectManager *manager) {
    ov01_021F15FC(manager);
    ov01_021F1538(manager);
    ov01_021F16B8(manager);
    ov01_021F1490(manager);
    Heap_Free(manager->entries);
    Heap_Free(manager);
}

void *ov01_021F141C(FieldEffectManager *manager, u32 size, int atEnd) {
    if (atEnd == 0) {
        return Heap_Alloc(manager->heapID, size);
    }
    return Heap_AllocAtEnd(manager->heapID, size);
}

void *ov01_021F1430(FieldEffectManager *manager, u32 size, int atEnd, int fill) {
    void *ptr = ov01_021F141C(manager, size, atEnd);
    memset(ptr, fill, size);
    return ptr;
}

void ov01_021F1448(void *ptr) {
    Heap_Free(ptr);
}

void *ov01_021F1450(FieldEffectManager *manager, u32 id) {
    FieldEffectEntry *entry = ov01_021F1588(manager, id);
    if (entry == NULL) {
        GF_AssertFail();
        return NULL;
    }
    return entry->data;
}

void *ov01_021F1468(FieldEffectManager *manager) {
    return manager->fieldSystem;
}

FieldEffectManager *ov01_021F146C(void *mapObject) {
    return *(FieldEffectManager **)((u8 *)MapObject_GetFieldSystem(mapObject) + 0x44);
}

enum HeapID ov01_021F1478(FieldEffectManager *manager) {
    return manager->heapID;
}

void ov01_021F147C(FieldEffectManager *manager) {
    manager->narc = NARC_New(0x67, ov01_021F1478(manager));
}

void ov01_021F1490(FieldEffectManager *manager) {
    NARC_Delete(manager->narc);
}

u32 ov01_021F149C(FieldEffectManager *manager, u32 fileId) {
    return NARC_GetMemberSize(manager->narc, fileId);
}

void ov01_021F14A8(FieldEffectManager *manager, u32 fileId, void *dest) {
    NARC_ReadWholeMember(manager->narc, fileId, dest);
}

void *ov01_021F14B4(FieldEffectManager *manager, u32 fileId, int atEnd) {
    void *ptr = ov01_021F141C(manager, NARC_GetMemberSize(manager->narc, fileId), atEnd);
    NARC_ReadWholeMember(manager->narc, fileId, ptr);
    return ptr;
}

void ov01_021F14DC(FieldEffectManager *manager) {
    u32 i = manager->count;
    FieldEffectEntry *entry = manager->entries;
    while (i != 0) {
        ov01_021F15A0(entry);
        entry++;
        i--;
    }
}

void ov01_021F14F4(FieldEffectManager *manager, u32 id) {
    void *data = ov01_021F15C4(id)->init(manager);
    ov01_021F15AC(ov01_021F1560(manager), id, data);
}

void ov01_021F151C(FieldEffectManager *manager, FieldEffectEntry *entry) {
    ov01_021F15C4(entry->id)->free(entry->data);
    ov01_021F15A0(entry);
}

void ov01_021F1538(FieldEffectManager *manager) {
    u32 i = manager->count;
    FieldEffectEntry *entry = manager->entries;
    while (i != 0) {
        if (!ov01_021F15B4(entry)) {
            ov01_021F151C(manager, entry);
        }
        entry++;
        i--;
    }
}

FieldEffectEntry *ov01_021F1560(FieldEffectManager *manager) {
    u32 i = manager->count;
    FieldEffectEntry *entry = manager->entries;
    while (i != 0) {
        if (ov01_021F15B4(entry) == TRUE) {
            return entry;
        }
        entry++;
        i--;
    }
    GF_AssertFail();
    return NULL;
}

FieldEffectEntry *ov01_021F1588(FieldEffectManager *manager, u32 id) {
    u32 i = manager->count;
    FieldEffectEntry *entry = manager->entries;
    while (i != 0) {
        if (entry->id == id) {
            return entry;
        }
        entry++;
        i--;
    }
    return NULL;
}

void ov01_021F15A0(FieldEffectEntry *entry) {
    entry->id = 0x17;
    entry->data = NULL;
}

void ov01_021F15AC(FieldEffectEntry *entry, u32 id, void *data) {
    entry->id = id;
    entry->data = data;
}

BOOL ov01_021F15B4(FieldEffectEntry *entry) {
    if (entry->id == 0x17) {
        return TRUE;
    }
    return FALSE;
}

const FieldEffectRenderer *ov01_021F15C4(u32 id) {
    const FieldEffectRenderer *renderer = ov01_02208C5C;
    while (renderer->id != 0x17) {
        if (renderer->id == id) {
            return renderer;
        }
        renderer++;
    }
    GF_AssertFail();
    return NULL;
}

void ov01_021F15EC(FieldEffectManager *manager) {
    manager->effectManager = sub_020689C8(manager->heapID, manager->animManagerCount);
}

void ov01_021F15FC(FieldEffectManager *manager) {
    if (manager->effectManager != NULL) {
        sub_020689F8(manager->effectManager);
        manager->effectManager = NULL;
    }
}

void ov01_021F1610(FieldEffectManager *manager) {
    if (manager->effectManager != NULL) {
        sub_02068BAC(manager->effectManager);
    }
}

void *ov01_021F1620(FieldEffectManager *manager, const void *tmpl, void *pos, int param, void *userData, u32 priority) {
    void *effect = sub_02068B0C(manager->effectManager, tmpl, pos, param, userData, priority);
    GF_ASSERT(effect != NULL);
    return effect;
}

void ov01_021F1640(int a0) {
    sub_02068B48(a0);
}

void ov01_021F1648(FieldEffectManager *manager, enum HeapID heapID, u32 a2, u32 a3, u32 a4, u32 a5, int a6, int a7, int a8) {
    FieldEffectAnimReq req;
    FieldEffectGfx *gfx = ov01_021F1430(manager, sizeof(FieldEffectGfx), 0, 0);
#pragma unused(a8)
    manager->gfx = gfx;
    gfx->heapID = heapID;
    gfx->count = a2;
    gfx->unk6 = a3;
    gfx->unk8 = a4;
    gfx->unkA = a5;
    gfx->unk10 = ov01_021FC4C4(heapID, 0x44, a6, a3);
    gfx->unk14 = ov01_021FC4C4(heapID, 0x45, a7, a4);
    gfx->resMan = GF3dGfxRawResMan_Create(a5, heapID);
    ov01_021F17BC(manager, gfx, a2);
    req.count = a2;
    req.heapID = ov01_021F1478(manager);
    gfx->unkC = sub_020237EC(&req);
}

void ov01_021F16B8(FieldEffectManager *manager) {
    FieldEffectGfx *gfx = manager->gfx;
    if (gfx != NULL) {
        sub_02023874(gfx->unkC);
        ov01_021F17F0(gfx);
        ov01_021FC520(gfx->unk10);
        ov01_021FC520(gfx->unk14);
        GF3dGfxRawResMan_Destroy(gfx->resMan);
        ov01_021F1448(gfx);
        manager->gfx = NULL;
    }
}

void *ov01_021F16EC(FieldEffectManager *manager, void *a1, const VecFx32 *position) {
    FieldEffectModelReq req;
    void *model;
    req.unk0 = manager->gfx->unkC;
    req.unk4 = a1;
    req.position = *position;
    req.scale = ov01_02206988;
    model = sub_02023D44(&req);
    GF_ASSERT(model != NULL);
    if (model != NULL) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(sub_02023F90(model), 1);
        ov01_021EA3B0(sub_02023F90(model));
    }
    return model;
}

void *ov01_021F1740(FieldEffectManager *manager, u32 id, const VecFx32 *position) {
    return ov01_021F16EC(manager, ov01_021F18A8(manager->gfx, id), position);
}
