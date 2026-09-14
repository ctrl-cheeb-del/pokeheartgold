#include "to47_overlay87_private.h"

void ov87_021E7E98(State *p) {
    u8 i;
    for (i = 0; i < 5; i++) {
        u8 *entry = (u8 *)p + i * 0x10;
        SpriteTransfer_DeleteCharTransferTask(*(void **)(entry + 0x13C));
        SpriteTransfer_DeletePlttTransferTask(*(void **)(entry + 0x140));
    }
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(*(void **)((u8 *)p + 0x12C + i * 4));
    }
    SpriteList_Delete(*(void **)p);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}
void ov87_021E7EF0(void) {
    struct X {
        u32 x[4];
    } v = *(const struct X *)ov87_021E8398;
    ObjCharTransfer_InitEx(&v, 0x00200010, 0x00200010);
    ObjPlttTransfer_Init(14, 0x7a);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}
