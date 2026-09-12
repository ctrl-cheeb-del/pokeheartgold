#include "overlay40_pc_box_grid_private.h"

void ov40_0223610C(void *p) {
    u32 i;
    void *win = (u8 *)PTR(p, 0x860) + 0xD0;
    for (i = 0; i < 9; i++) {
        ClearWindowTilemapAndCopyToVram(win);
        RemoveWindow(win);
        win = (u8 *)win + 0x10;
    }
}

void ov40_02236130(void *p) {
    void *w = PTR(p, 0x860);
    if (WindowIsInUse((u8 *)w + 0x10) == 1) {
        ClearWindowTilemapAndCopyToVram((u8 *)w + 0x10);
        RemoveWindow((u8 *)w + 0x10);
    }
}
