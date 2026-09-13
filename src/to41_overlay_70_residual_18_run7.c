#include "to41_overlay_70_residual_18_private.h"

void ov70_0223BC2C(R14Work *w) {
    int i;
    R14Work *p;
    RemoveWindow(w + 0x1198);
    RemoveWindow(w + 0xf18);
    for (i = 0, p = w + 0x1058; i < 9; i++, p += 0x10) {
        RemoveWindow(p);
    }
    for (i = 0, p = w + 0x1178; i < 2; i++, p += 0x10) {
        RemoveWindow(p);
    }
}

void ov70_0223BC7C(R14Work *w) {
    P(w, 0xbbc) = String_New(0xb4, 0x3d);
    P(w, 0xbc0) = NewString_ReadMsgData(P(w, 0xba0), 0x2a);
    P(w, 0x11c4) = Heap_Alloc(0x3d, 0x30);
    MIi_CpuClearFast(0, (u32 *)P(w, 0x11c4), 0x30);
    P(P(w, 0x11c4), 0x14) = ov70_0223F684(0x3d);
    ov70_0223F948(w + 0x1234);
}

void ov70_0223BCD0(R14Work *w) {
    Heap_Free(P(P(w, 0x11c4), 0x14));
    Heap_Free(P(w, 0x11c4));
    String_Delete(P(w, 0xbbc));
    String_Delete(P(w, 0xbc0));
}

int ov70_0223BD04(R14Work *w) {
    if (U32(w, 0x24) == 0xf) {
        ov70_0223CAC4(w, 0x20, 0, 0, 0xf0f);
        if (GX_GetMasterBrightness() == -16) {
            BeginNormalPaletteFade(0, 1, 1, 0, 0x10, 1, 0x3d);
            U32(w, 0x2c) = 0x1e;
        } else {
            U32(w, 0x2c) = 1;
        }
    } else {
        ov70_0223CAC4(w, 8, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 1);
    }
    Sprite_SetDrawFlag(P(w, 0xf10), 1);
    return 3;
}

int ov70_0223BD80(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(ov70_022456C8);
}
