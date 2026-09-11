#include "ov83_wave39_safe_private.h"

void ov83_02247264(void *p, int resId, int item) {
    void *res = SpriteResourceCollection_Find(PTR(p, 0x12c), resId);
    int idx = GetItemIndexMapping(item, 1);
    ReplaceCharResObjFromNarc(PTR(p, 0x12c), res, 0x12, idx, 0, 0x6b);
    SpriteTransfer_ReplaceCharData(res);
}

void ov83_022472A0(void *p, int resId, int item) {
    void *res = SpriteResourceCollection_Find(PTR(p, 0x130), resId);
    int idx = GetItemIndexMapping(item, 2);
    ReplacePlttResObjFromNarc(PTR(p, 0x130), res, 0x12, idx, 0, 0x6b);
    SpriteTransfer_ReplacePlttData(res);
}

void ov83_022472DC(void) {
    SolXferTemplate t = ov83_0224817C;
    ObjCharTransfer_InitEx(&t, 0x10, 0x00100010);
    ObjPlttTransfer_Init(0x20, 0x6b);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

void ov83_02247314(void *p) {
    void *n = NARC_New(0x15, 0x6b);
    PTR(p, 0x14c) = AddCharResObjFromOpenNarc(PTR(p, 0x12c), n, sub_0207CA9C(), 0, 1, 1, 0x6b);
    PTR(p, 0x150) = AddPlttResObjFromNarc(PTR(p, 0x130), 0x15, sub_0207CAA0(), 0, 1, 1, 1, 0x6b);
    PTR(p, 0x154) = AddCellOrAnimResObjFromOpenNarc(PTR(p, 0x134), n, sub_0207CAA4(), 0, 1, 2, 0x6b);
    PTR(p, 0x158) = AddCellOrAnimResObjFromOpenNarc(PTR(p, 0x138), n, sub_0207CAA8(), 0, 1, 3, 0x6b);
    NARC_Delete(n);
}
