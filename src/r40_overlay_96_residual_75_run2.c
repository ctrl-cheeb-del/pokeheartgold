#include "r40_overlay_96_residual_75_private.h"

extern void CreateSpriteResourcesHeader(void *, s32, s32, s32, s32, s32, s32, s32, s32, void *, void *, void *, void *, void *, void *);
extern void *G2dRenderer_Init(u32 count, void *renderer, u32 heapId);
extern void *Create2DGfxResObjMan(u32 count, u32 type, u32 heapId);
extern void *AddCharResObjFromNarc(void *, u32, u32, u32, u32, u32, u32);
extern void *AddPlttResObjFromNarc(void *, u32, u32, u32, u32, u32, u32, u32);
extern void *AddCellOrAnimResObjFromNarc(void *, u32, u32, u32, u32, u32, u32);
extern void SpriteTransfer_CreateCharTransferTask_AllocAtEnd(void *);
extern void SpriteTransfer_CreateExtPlttTransferTask(void *);
extern u32 sub_02074490(void);
extern void GfGfxLoader_GXLoadPal(u32, u32, u32, u32, u32, u32);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void *ov96_021EB3E4(void *a0, int a1, int a2, int a3, u8 a4);
extern void ov96_021EB52C(void *a0, u32 a1, u32 a2);
extern void ov96_021EB630(void *a0, u32 a1);

void ov96_021FC5E0(Ov96R75Template *out, u8 *work, void *unused, u32 priority) {
    u32 zero = 0;

    out->spriteList = *(void **)(work + 4);
    out->header = work + 0x160;
    out->x = 0xF0000;
    out->y = 0xE000;
    out->z = zero;
    out->scaleX = 0x1000;
    out->scaleY = 0x1000;
    out->scaleZ = 0x1000;
    out->rotation = zero;
    out->affine = 2;
    out->priority = priority;
    out->heapId = *(u32 *)work;
}

void *ov96_021FC618(u32 heapId) {
    void *ret = Heap_Alloc(heapId, 0x84);
    MI_CpuFill8(ret, 0, 0x84);
    return ret;
}
