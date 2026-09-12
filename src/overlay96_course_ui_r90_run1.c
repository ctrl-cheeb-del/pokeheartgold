#include "overlay96_course_ui_r90_private.h"

void ov96_02207BE4(void *work) {
    if (OV96_R90_BYTE(work, 0x512) >= 4) {
        void *base = OV96_R90_PTR(OV96_R90_PTR(work, 0x1C), 0x14);
        u32 offset = OV96_R90_BYTE(work, 0x511) << 11;
        DC_FlushRange((u8 *)base + offset, 0x800);
        GX_LoadBG0Char((u8 *)base + offset, 0x1800, 0x800);
        OV96_R90_BYTE(work, 0x512) = 0;
        OV96_R90_BYTE(work, 0x511) = (OV96_R90_BYTE(work, 0x511) + 1) % 6;
    } else {
        OV96_R90_BYTE(work, 0x512)
        ++;
    }
}

void ov96_02207C38(int x, int y, int seq, BOOL player) {
    if (x >= 0 && x < 256 && y >= 0 && y < 192) {
        sub_0200606C((u16)seq, player ? 3 : 4);
    }
}
