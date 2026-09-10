#include "global.h"

#include "sprite.h"
#include "unk_0200B150.h"
typedef struct OamInstance {
    u32 data[7];
} OamInstance;
typedef struct OamManager {
    OamInstance main;
    OamInstance sub;
    enum HeapID heapID;
} OamManager;
extern OamManager *_021D0EB0;
BOOL NNS_G2dGetNewOamManagerInstance(OamInstance *, u16, u16, u16, u16, int);
void NNS_G2dApplyAndResetOamManagerBuffer(OamInstance *);
BOOL NNS_G2dEntryOamManagerOamWithAffineIdx(OamInstance *, const GXOamAttr *, u16);
u16 NNS_G2dEntryOamManagerAffine(OamInstance *, const MtxFx22 *);
void sub_02025C54(NNSG2dRenderSurface *, NNSG2dViewRect *, NNSG2dOamRegisterFunction, NNSG2dAffineRegisterFunction, NNSG2dRndCellCullingFunction, NNS_G2D_VRAM_TYPE, NNSG2dRendererInstance *);
BOOL sub_02025C98(const NNSG2dCellData *, const MtxFx32 *, const NNSG2dViewRect *);
void OamManager_Create(int first, int count, int affineFirst, int affineCount, int subFirst, int subCount, int subAffineFirst, int subAffineCount, enum HeapID heapID);
void sub_0200B194(int first, int count, int affineFirst, int affineCount, int subFirst, int subCount, int subAffineFirst, int subAffineCount, enum HeapID heapID);
void OamManager_ApplyAndResetBuffers(void);
void OamManager_Free(void);
void sub_0200B27C(NNSG2dRenderSurface *surface, NNSG2dViewRect *rect, NNS_G2D_VRAM_TYPE type, NNSG2dRendererInstance *instance);
void thunk_ClearMainOAM(enum HeapID heapID);
void thunk_ClearSubOAM(enum HeapID heapID);
BOOL sub_0200B2F0(const GXOamAttr *oam, u16 affine, BOOL doubleAffine);
BOOL sub_0200B310(const GXOamAttr *oam, u16 affine, BOOL doubleAffine);
u16 sub_0200B334(const MtxFx22 *matrix);
u16 sub_0200B358(const MtxFx22 *matrix);
void OamManager_Create(int first, int count, int affineFirst, int affineCount, int subFirst, int subCount, int subAffineFirst, int subAffineCount, enum HeapID heapID) {
    int adjustedFirst = first;
    int adjustedAffine;
    if (first < 4) {
        adjustedFirst = 4;
        if (count > 124) {
            first = adjustedFirst - first;
            count -= first;
        }
    }
    if (affineFirst < 1) {
        adjustedAffine = 1;
        if (affineCount > 30) {
            affineFirst = adjustedAffine - affineFirst;
            affineCount -= affineFirst;
        }
    } else {
        adjustedAffine = affineFirst;
    }
    sub_0200B194(adjustedFirst, count, adjustedAffine, affineCount, subFirst, subCount, subAffineFirst, subAffineCount, heapID);
}
void sub_0200B194(int first, int count, int affineFirst, int affineCount, int subFirst, int subCount, int subAffineFirst, int subAffineCount, enum HeapID heapID) {
    GF_ASSERT(_021D0EB0 == NULL);
    _021D0EB0 = Heap_Alloc(heapID, sizeof(OamManager));
    GF_ASSERT(_021D0EB0 != NULL);
    _021D0EB0->heapID = heapID;
    if (!NNS_G2dGetNewOamManagerInstance(&_021D0EB0->main, (u16)first, (u16)count, (u16)affineFirst, (u16)affineCount, 0)) {
        GF_ASSERT(FALSE);
    }
    if (!NNS_G2dGetNewOamManagerInstance(&_021D0EB0->sub, (u16)subFirst, (u16)subCount, (u16)subAffineFirst, (u16)subAffineCount, 1)) {
        GF_ASSERT(FALSE);
    }
}
void OamManager_ApplyAndResetBuffers(void) {
    if (_021D0EB0) {
        NNS_G2dApplyAndResetOamManagerBuffer(&_021D0EB0->main);
        NNS_G2dApplyAndResetOamManagerBuffer(&_021D0EB0->sub);
    }
}
void OamManager_Free(void) {
    GF_ASSERT(_021D0EB0 != NULL);
    thunk_ClearMainOAM(_021D0EB0->heapID);
    thunk_ClearSubOAM(_021D0EB0->heapID);
    Heap_Free(_021D0EB0);
    _021D0EB0 = NULL;
}
void sub_0200B27C(NNSG2dRenderSurface *surface, NNSG2dViewRect *rect, NNS_G2D_VRAM_TYPE type, NNSG2dRendererInstance *instance) {
    GF_ASSERT(_021D0EB0 != NULL);
    if (type == 1) {
        sub_02025C54(surface, rect, sub_0200B2F0, sub_0200B334, sub_02025C98, type, instance);
    } else {
        sub_02025C54(surface, rect, sub_0200B310, sub_0200B358, sub_02025C98, type, instance);
    }
}
void thunk_ClearMainOAM(enum HeapID heapID) {
    ClearMainOAM(heapID);
}
void thunk_ClearSubOAM(enum HeapID heapID) {
    ClearSubOAM(heapID);
}
BOOL sub_0200B2F0(const GXOamAttr *oam, u16 affine, BOOL doubleAffine) {
    BOOL result = NNS_G2dEntryOamManagerOamWithAffineIdx(&_021D0EB0->main, oam, affine);
    GF_ASSERT(result);
    return result;
}
BOOL sub_0200B310(const GXOamAttr *oam, u16 affine, BOOL doubleAffine) {
    BOOL result = NNS_G2dEntryOamManagerOamWithAffineIdx(&_021D0EB0->sub, oam, affine);
    GF_ASSERT(result);
    return result;
}
u16 sub_0200B334(const MtxFx22 *matrix) {
    u16 result = NNS_G2dEntryOamManagerAffine(&_021D0EB0->main, matrix);
    GF_ASSERT(result != 0xFFFE);
    return result;
}
u16 sub_0200B358(const MtxFx22 *matrix) {
    u16 result = NNS_G2dEntryOamManagerAffine(&_021D0EB0->sub, matrix);
    GF_ASSERT(result != 0xFFFE);
    return result;
}
