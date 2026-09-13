#include "global.h"

#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/binres/res_struct_accessor_inline.h>
typedef struct PairList {
    void *items;
    u16 capacity;
    volatile u16 count;
} PairList;
typedef struct Pair {
    u32 key;
    u32 value;
} Pair;
typedef struct InlinePairList {
    u8 pad[0xe];
    volatile u16 count;
    struct {
        u32 value, key;
    } pair[1];
} InlinePairList;
typedef struct Manager {
    void *r0, *r4, *r8, *rC;
    u8 *entries;
    u32 count;
    u8 rest[0x14];
} Manager;
extern void GF_AssertFail(void);
extern void *_022577C0;
extern void ov45_0222F154(u32);
extern void ov45_02230ACC(void *);
extern void ov45_02230CB0(void *);
extern void ov45_02230DF4(void *);
extern void BillboardLists_Draw(void);
extern BOOL ov45_02230A58(void *);
extern BOOL ov45_02230AA4(void *);
extern void ov45_02230AC0(void *);
typedef struct ResourceConfig {
    u16 unused;
    u16 id : 15;
    u16 hasTexture : 1;
} ResourceConfig;
typedef struct BillboardParams {
    u32 count;
    u32 heapId;
} BillboardParams;
extern u16 ov45_02254C38[];
extern ResourceConfig ov45_02254C48[];
extern void ov45_02230AB4(void *);
extern void ov45_0222D740(void *);
extern void ov45_022309E8(void *, void *, u32, u32);
extern void *sub_020237EC(void *);
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void *GF2dGfxRawResMan_Create(int, u32);
extern void *GF3dGfxRawResMan_Create(int, u32);
extern void *GF2dGfxRawResMan_AllocObj(void *, void *, int);
extern void *GF3dGfxRawResMan_AllocObj(void *, void *, int, BOOL, u32);
extern void GF3dGfxRawResObj_AllocVramAndGetKeys(void *);
extern void GF3dGfxRawResObj_LoadTex(void *);
extern void GF3dGfxRawResObj_FreeVramAndSecondaryHeader(void *);
extern void BillboardLists_Create(int, u32);
extern void *GfGfxLoader_LoadFromOpenNarc(void *, s32, BOOL, u32, BOOL);
extern u32 NNS_G3dMdlGetMdlLightEnableFlag(void *, u32);
extern void *NARC_New(u32, u32);
extern void NARC_Delete(void *);
void ov45_02230394(u32, u8 *);
u32 ov45_022303BC(InlinePairList *, u32);
void ov45_022303E4(PairList *, u32, u32);
void ov45_022303FC(PairList *);
void ov45_0223040C(PairList *, const void *, u32);
BOOL ov45_02230434(PairList *, u32);
u32 ov45_0223045C(PairList *, u32);
void ov45_0223048C(void *, const void *);
Manager *ov45_02230498(u32, BOOL, u32, u32);
void ov45_02230638(Manager *);
void ov45_02230680(Manager *);
void ov45_022306B4(Manager *);
void ov45_02230394(u32 a, u8 *p) {
    if (p[0x69e] == 1) {
        ov45_0222F154(a);
    } else if (a == 0) {
        ((u8 *)_022577C0)[0x69f] = 1;
    }
}
u32 ov45_022303BC(InlinePairList *l, u32 key) {
    u32 result = 0;
    s32 i = 0;
    if ((s32)l->count > 0) {
        InlinePairList *p = l;
        do {
            if (key == p->pair[0].key) {
                result = p->pair[0].value;
            }
            i++;
            p = (InlinePairList *)((u8 *)p + 8);
        } while (i < l->count);
    }
    return result;
}
void ov45_022303E4(PairList *l, u32 n, u32 heap) {
    l->items = Heap_Alloc(heap, n * 8);
    l->capacity = n;
    l->count = 0;
}
void ov45_022303FC(PairList *l) {
    Heap_Free(l->items);
    l->items = NULL;
}
void ov45_0223040C(PairList *l, const void *src, u32 n) {
    if (n >= l->capacity) {
        GF_AssertFail();
    }
    if (n >= l->capacity) {
        n = l->capacity;
    }
    MIi_CpuCopy32((const u32 *)src, (u32 *)l->items, n * 8);
    l->count = n;
}
BOOL ov45_02230434(PairList *l, u32 key) {
    s32 i = 0;
    if ((s32)l->count > i) {
        Pair *p = l->items;
        do {
            if (key == p->key) {
                return TRUE;
            }
            i++;
            p++;
        } while (i < l->count);
    }
    return FALSE;
}
u32 ov45_0223045C(PairList *l, u32 key) {
    s32 i = 0;
    if ((s32)l->count > 0) {
        Pair *walk;
        Pair *base;
        base = l->items;
        walk = base;
        do {
            if (key == walk->key) {
                return base[i].value;
            }
            i++;
            walk++;
        } while (i < l->count);
    }
    return 0;
}
void ov45_0223048C(void *dst, const void *src) {
    memcpy(dst, src, 0x2d8);
}
Manager *ov45_02230498(u32 count, BOOL mode, u32 heapId, u32 loadHeapId) {
    Manager *manager;
    s32 i;
    u32 offset;
    void *narc1;
    void *narc2;
    void *file;
    void *object;
    BillboardParams params;
    BOOL skip;

    manager = Heap_Alloc(heapId, 0x30);
    memset(manager, 0, 0x30);
    manager->entries = Heap_Alloc(heapId, count * 0x90);
    manager->count = count;
    i = 0;
    if (i < manager->count) {
        offset = 0;
        do {
            ov45_02230AB4(manager->entries + offset);
            i++;
            offset += 0x90;
        } while (i < manager->count);
    }

    manager->r0 = GF2dGfxRawResMan_Create(1, heapId);
    manager->r4 = GF2dGfxRawResMan_Create(2, heapId);
    manager->r8 = GF3dGfxRawResMan_Create(0x14, heapId);
    BillboardLists_Create(1, heapId);
    params.count = count;
    params.heapId = heapId;
    manager->rC = sub_020237EC(&params);

    narc1 = NARC_New(0x51, heapId);
    narc2 = NARC_New(0xd1, heapId);
    file = GfGfxLoader_LoadFromOpenNarc(narc2, 0x7f, FALSE, loadHeapId, FALSE);
    GF2dGfxRawResMan_AllocObj(manager->r0, file, 0x7f);
    ov45_0222D740(file);
    *(u32 *)((u8 *)manager + 0x2c) = NNS_G3dMdlGetMdlLightEnableFlag(NNS_G3dGetMdlByIdx(NNS_G3dGetMdlSet(file), 0), 0);

    for (i = 0; i < 2; i++) {
        file = GfGfxLoader_LoadFromOpenNarc(narc1, ov45_02254C38[i], FALSE, loadHeapId, FALSE);
        GF2dGfxRawResMan_AllocObj(manager->r4, file, ov45_02254C38[i]);
    }

    if (mode == FALSE) {
        skip = TRUE;
    } else {
        skip = FALSE;
    }
    {
        ResourceConfig *config = ov45_02254C48;
        s32 resourceIndex = 0;
        do {
            if (skip != resourceIndex) {
                BOOL copyWithoutTex = config->hasTexture == 0;
                file = GfGfxLoader_LoadFromOpenNarc(narc1, config->id, FALSE, loadHeapId, FALSE);
                object = GF3dGfxRawResMan_AllocObj(manager->r8, file, config->id, copyWithoutTex, loadHeapId);
                if (copyWithoutTex == TRUE) {
                    GF3dGfxRawResObj_AllocVramAndGetKeys(object);
                    GF3dGfxRawResObj_LoadTex(object);
                    GF3dGfxRawResObj_FreeVramAndSecondaryHeader(object);
                }
            }
            config++;
            resourceIndex++;
        } while (resourceIndex < 0x14);
    }

    ov45_022309E8((u8 *)manager + 0x18, narc2, 0x80, loadHeapId);
    NARC_Delete(narc1);
    NARC_Delete(narc2);
    return manager;
}
void ov45_02230638(Manager *m) {
    extern void ov45_02230A44(void *);
    extern void GF3dGfxRawResMan_FreeAllObjs(void *);
    extern void GF2dGfxRawResMan_FreeAllObjs(void *);
    extern void sub_02023874(void *);
    extern void BillboardLists_Delete(void);
    extern void GF3dGfxRawResMan_Destroy(void *);
    extern void GF2dGfxRawResObj_Destroy(void *);
    ov45_02230A44(m->rest);
    GF3dGfxRawResMan_FreeAllObjs(m->r8);
    GF2dGfxRawResMan_FreeAllObjs(m->r0);
    GF2dGfxRawResMan_FreeAllObjs(m->r4);
    sub_02023874(m->rC);
    BillboardLists_Delete();
    GF3dGfxRawResMan_Destroy(m->r8);
    GF2dGfxRawResObj_Destroy(m->r0);
    GF2dGfxRawResObj_Destroy(m->r4);
    Heap_Free(m->entries);
    Heap_Free(m);
}
void ov45_02230680(Manager *m) {
    u32 off, i;
    i = 0;
    if (i < m->count) {
        off = i;
        do {
            ov45_02230ACC(m->entries + off);
            ov45_02230CB0(m->entries + off);
            ov45_02230DF4(m->entries + off);
            i++;
            off += 0x90;
        } while (i < m->count);
    }
}
void ov45_022306B4(Manager *m) {
    u32 off, i;
    BillboardLists_Draw();
    if (ov45_02230A58(m->rest)) {
        i = 0;
        if (i < m->count) {
            off = i;
            do {
                if (ov45_02230AA4(m->entries + off) == 1) {
                    ov45_02230AC0(m->entries + off);
                }
                i++;
                off += 0x90;
            } while (i < m->count);
        }
    }
}
