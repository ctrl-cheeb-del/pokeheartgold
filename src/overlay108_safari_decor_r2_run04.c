#include "overlay108_safari_decor_r2_private.h"

void ov108_021E9198(void *p, void *model, void *out, int id) {
    PTR(out, 0) = GfGfxLoader_LoadFromOpenNarc(PTR(p, 0x20), id, 0, U32(p, 0x14), 0);
    PTR(out, 4) = NNS_G3dGetAnmByIdx(PTR(out, 0), 0);
    PTR(out, 8) = NNS_G3dAllocAnmObj((NNSFndAllocator *)((u8 *)p + 4), PTR(out, 4), (NNSG3dResMdl *)PTR(model, 8));
    NNS_G3dAnmObjInit((NNSG3dAnmObj *)PTR(out, 8), PTR(out, 4), (NNSG3dResMdl *)PTR(model, 8), (NNSG3dResTex *)PTR(model, 0xc));
}

void ov108_021E91D4(void *p, void *a) {
    if (PTR(a, 0)) {
        NNS_G3dFreeAnmObj((NNSFndAllocator *)((u8 *)p + 4), (NNSG3dAnmObj *)PTR(a, 8));
        Heap_Free(PTR(a, 0));
        MI_CpuFill8(a, 0, 0x14);
    }
}

void ov108_021E91F8(void *p, void *a) {
    NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)((u8 *)p + 0x10), (NNSG3dAnmObj *)PTR(a, 8));
}

void ov108_021E9204(void *p, void *a) {
    NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)((u8 *)p + 0x10), (NNSG3dAnmObj *)PTR(a, 8));
}

void ov108_021E9210(void *p) {
    s32 r = ((s32)U32(p, 0xc) + 0x1000) % (s32)(U16(PTR(PTR(p, 8), 8), 4) << 12);
    U32(p, 0xc) = r;
    U32(PTR(p, 8), 0) = r;
}
