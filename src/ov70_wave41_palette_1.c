#include "ov70_wave41_palette_private.h"

void ov70_022444E4(void *unused, void *w) {
    if (PTR(w, 4) == 0) {
        return;
    }
    U8(w, 0x32b) ^= 1;
    if (U8(w, 0x32b) & 1) {
        return;
    }
    if (U32(w, 0x32c) <= 1) {
        GX_LoadBGPltt((u8 *)w + 0x88 + S16(w, 0x328) * 0x20, 0, 0x20);
    }
    if (U32(w, 0x32c) == 0 || U32(w, 0x32c) == 2) {
        GXS_LoadBGPltt((u8 *)w + 0x88 + S16(w, 0x328) * 0x20, 0, 0x20);
    }
    if (S8(w, 0x32a) == 0) {
        S16(w, 0x328)
        ++;
        if (S16(w, 0x328) >= 0x15) {
            S16(w, 0x328) = 0x13;
            S8(w, 0x32a) ^= 1;
        }
    } else {
        S16(w, 0x328)
        --;
        if (S16(w, 0x328) < 0) {
            S16(w, 0x328) = 1;
            S8(w, 0x32a) ^= 1;
        }
    }
}

void ov70_0224458C(void *w) {
    AddWindowParameterized(PTR(w, 4), (u8 *)w + 0xf48, 0, 4, 4, 0x17, 0x10, 0xd, 0x94);
    FillWindowPixelBuffer((u8 *)w + 0xf48, 0);
    AddWindowParameterized(PTR(w, 4), (u8 *)w + 0xf38, 0, 4, 1, 0x18, 2, 0xd, 0x204);
    FillWindowPixelBuffer((u8 *)w + 0xf38, 0);
    ov70_02245050((u8 *)w + 0xf38, PTR(w, 0xbc0), 0, 1, 1, 0xf0e00);
    AddWindowParameterized(PTR(w, 4), (u8 *)w + 0xf18, 0, 2, 0x13, 0x1b, 4, 0xd, 0x28);
    FillWindowPixelBuffer((u8 *)w + 0xf18, 0);
}

void ov70_02244644(void *w) {
    RemoveWindow((u8 *)w + 0xf18);
    RemoveWindow((u8 *)w + 0xf38);
    RemoveWindow((u8 *)w + 0xf48);
}

void ov70_02244670(void *w) {
    PTR(w, 0xbbc) = String_New(0xb4, 0x3d);
    PTR(w, 0xbec) = String_New(0x100, 0x3d);
    PTR(w, 0xbc0) = NewString_ReadMsgData(PTR(w, 0xba0), 0x1f);
}
