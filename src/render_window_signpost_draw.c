#include "render_window_signpost_private.h"

void sub_0200EF84(Window *window, u16 baseTile, u8 palette) {
    u16 row;
    u8 bgId = GetWindowBgId(window);
    u16 x = GetWindowX(window) - 7;
    u32 y = GetWindowY(window);

    for (row = 0; row < 4; row++) {
        u16 col;
        for (col = 0; col < 6; col++) {
            FillBgTilemapRect(window->bgConfig, bgId, baseTile + row * 6 + col, (u8)(x + col), y + row, 1, 1, palette);
        }
    }
}

void DrawFrameAndWindow3(Window *window, BOOL dontCopy, u16 baseTile, u8 palette, u8 type) {
    u32 bgId = GetWindowBgId(window);

    if (type <= 1) {
        u32 x = GetWindowX(window);
        u32 y = GetWindowY(window);
        u32 width = GetWindowWidth(window);
        u32 height = GetWindowHeight(window);
        sub_0200ECBC(window->bgConfig, bgId, x, y, width, height, palette, baseTile);
        sub_0200EF84(window, (u16)(baseTile + 0x1e), palette);
    } else {
        u32 x = GetWindowX(window);
        u32 y = GetWindowY(window);
        u32 width = GetWindowWidth(window);
        u32 height = GetWindowHeight(window);
        sub_0200E6B4(window->bgConfig, bgId, x, y, width, height, palette, baseTile);
    }
    if (dontCopy == FALSE) {
        CopyWindowToVram(window);
    }
    TextPrinter_SetDownArrowBaseTile(baseTile);
}
