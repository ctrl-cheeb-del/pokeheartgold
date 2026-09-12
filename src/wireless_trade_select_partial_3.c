#include "wireless_trade_select_partial_private.h"

void ov65_0221CCB0(void *p) {
    int i;
    u8 *cur;
    u32 offset;

    SpriteTransfer_DeleteCharTransferTask(PTR(p, 0x2dc));
    SpriteTransfer_DeleteCharTransferTask(PTR(p, 0x2ec));
    SpriteTransfer_DeletePlttTransferTask(PTR(p, 0x2e0));
    SpriteTransfer_DeletePlttTransferTask(PTR(p, 0x2f0));
    offset = 0xb3 * 4;
    i = 0;
    cur = p;
    while (i < 4) {
        Destroy2DGfxResObjMan(PTR(cur, offset));
        i++;
        cur += 4;
    }
    SpriteList_Delete(PTR(p, 0x1a0));
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}

void ov65_0221CD0C(Ov65WorkPartial *work) {
    int i;

    i = 0;
    if (Party_GetCount(work->party1) > 0) {
        do {
            Heap_Free(work->first[i]);
            i++;
        } while (i < Party_GetCount(work->party1));
    }
    i = 0;
    if (Party_GetCount(work->party2) > 0) {
        do {
            Heap_Free(work->second[i]);
            i++;
        } while (i < Party_GetCount(work->party2));
    }
}
