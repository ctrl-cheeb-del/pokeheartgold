#include "trainer_card_main_22_private.h"

void ov51_021E7CA4(TrainerCardMainState22 *work) {
    u8 i;
    for (i = 0; i < 16; i++) {
        Heap_Free(work->rawPalettes[i]);
    }
    SpriteTransfer_DeleteCharTransferTask(work->resourceObjects[0][0]);
    SpriteTransfer_DeleteCharTransferTask(work->resourceObjects[1][0]);
    SpriteTransfer_DeletePlttTransferTask(work->resourceObjects[0][1]);
    SpriteTransfer_DeletePlttTransferTask(work->resourceObjects[1][1]);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(work->resourceManagers[0][i]);
        Destroy2DGfxResObjMan(work->resourceManagers[1][i]);
    }
    G2dRenderer_SetSubSurfaceCoords(&work->renderer, 0, 0xC0000);
    SpriteList_Delete(work->spriteList);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | 0x10;
}
