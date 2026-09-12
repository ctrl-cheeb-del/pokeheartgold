#include "overlay40_pc_box_wallpaper_private.h"

void ov40_0224428C(void *w, int a) {
    void *win = (u8 *)w + 0x8A4;
    ov40_0222C6C8(w, 2, a);
    InitWindow(win);
    AddWindowParameterized(PTR(w, 0x24), win, 2, 1, 0x13, 0x1E, 4, 0xE, 0x12C);
}

void ov40_022442CC(void *w) {
    ClearWindowTilemapAndCopyToVram((u8 *)w + 0x8A4);
    RemoveWindow((u8 *)w + 0x8A4);
    GfGfx_EngineATogglePlanes(4, 0);
}
