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

void ov96_021FC320(Ov96R75Work *work) {
    int i;

    work->spriteList = G2dRenderer_Init(0x24, work->renderer, work->heapId);
    for (i = 0; i < 6; i++) {
        work->managers[i] = Create2DGfxResObjMan(1, i, work->heapId);
    }
    work->resources[0] = AddCharResObjFromNarc(work->managers[0], 0x9C, 0x18, 0, 0x80, 2, work->heapId);
    work->resources[1] = AddPlttResObjFromNarc(work->managers[1], 0x9C, 0x15, 0, 0x80, 2, 1, work->heapId);
    work->resources[2] = AddCellOrAnimResObjFromNarc(work->managers[2], 0x9C, 0x17, 0, 0x80, 2, work->heapId);
    work->resources[3] = AddCellOrAnimResObjFromNarc(work->managers[3], 0x9C, 0x16, 0, 0x80, 3, work->heapId);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(work->resources[0]);
    SpriteTransfer_CreateExtPlttTransferTask(work->resources[1]);
    GfGfxLoader_GXLoadPal(0x14, sub_02074490(), 5, 0x60, 0, work->heapId);
}

void ov96_021FC404(u8 *work) {
    CreateSpriteResourcesHeader(work + 0x160, 0x80, 0x80, 0x80, 0x80, -1, -1, 0, 0, *(void **)(work + 0x130), *(void **)(work + 0x134), *(void **)(work + 0x138), *(void **)(work + 0x13C), NULL, NULL);
}
