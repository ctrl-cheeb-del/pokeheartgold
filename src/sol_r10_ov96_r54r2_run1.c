#include "sol_r10_ov96_r54r2_private.h"

void ov96_021F295C(int count, void *bg) {
    int i;

    for (i = 1; i <= count; i++) {
        ov96_021F2984((u8)i, bg);
    }
    ScheduleBgTilemapBufferTransfer(bg, 1);
}

void ov96_021F2984(u32 index, void *bg) {
    int fill;
    int y;

    if (index >= 1 && index <= 6) {
        y = (index - 1) * 2 + 0x12;
        fill = 2;
    } else if (index >= 0x10 && index <= 0x1c) {
        y = 0x1a - (index - 0x10) * 2;
        fill = 0x14;
    } else if (index >= 0x26 && index < 0x2b) {
        y = (index - 0x26) * 2 + 4;
        fill = 2;
    } else if (index >= 7 && index <= 0xf) {
        y = 0x1c;
        fill = (index - 7) * 2 + 4;
    } else {
        y = 2;
        fill = 0x12 - (index - 0x1d) * 2;
    }
    FillBgTilemapRect(bg, 1, 0, y, fill, 2, 2, 0x10);
}
