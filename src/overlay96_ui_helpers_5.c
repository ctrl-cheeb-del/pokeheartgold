#include "overlay96_ui_helpers_private.h"

void ov96_021EE944(u8 *p) {
    if (*(u32 *)(p + 0x2C) != (u32)-1) RemoveTextPrinter((u8)*(u32 *)(p + 0x2C));
    if (*(void **)(p + 0x18) != NULL) {
        ClearFrameAndWindow2(p + 0x18, 0);
        ClearWindowTilemapAndCopyToVram(p + 0x18);
        RemoveWindow(p + 0x18);
    }
}

void *ov96_021EE97C(u8 *p) {
    if (p == NULL) GF_AssertFail();
    if (*(void **)(p + 4) == NULL) GF_AssertFail();
    return *(void **)(p + 4);
}

void ov96_021EE994(u8 *p) {
    if (p == NULL) GF_AssertFail();
    if (*(void **)(p + 0x30) != NULL) GF_AssertFail();
    *(void **)(p + 0x30) = WaitingIcon_New(p + 0x18, 0x3D2);
}

void ov96_021EE9BC(u8 *p) {
    if (p == NULL) GF_AssertFail();
    if (*(void **)(p + 0x30) == NULL) GF_AssertFail();
    sub_0200F450(*(void **)(p + 0x30));
}

void ov96_021EE9D8(void *bg, int palette, enum HeapID heapId) {
    LoadFontPal0(4, 0x1C0, heapId);
    LoadUserFrameGfx2(bg, palette, 0x3D2, 0xD, 0, heapId);
}
