#include "r40_overlay_34_residual_2_candidate_private.h"

void ov34_0225D650(BgConfig *bgConfig, void *windowData, Window *lastWindow) {
    u32 x1;
    u32 x2;
    u32 y2;
    u32 tile;
    u32 tileInit;
    int i;
    int palette;
    u8 *windows;
    x1 = 0xA0;
    x2 = 0xD0;
    y2 = 5;
    tileInit = 0x265;
    windows = windowData;
    i = 0;
    palette = 3;
    tile = tileInit;
    for (; i < 3; i++) {
        AddWindowParameterized(bgConfig, (Window *)windows, i + 4, 1, palette, 8, 2, 12, x1);
        FillWindowPixelBuffer((Window *)windows, 0);
        CopyWindowToVram((Window *)windows);
        AddWindowParameterized(bgConfig, (Window *)(windows + 0x10), i + 4, 2, y2, 0x1B, 5, 12, x2);
        FillWindowPixelBuffer((Window *)(windows + 0x10), 0);
        CopyWindowToVram((Window *)(windows + 0x10));
        AddWindowParameterized(bgConfig, (Window *)(windows + 0x20), i + 4, 12, palette, 0xF, 2, 12, tile);
        FillWindowPixelBuffer((Window *)(windows + 0x20), 0);
        CopyWindowToVram((Window *)(windows + 0x20));
        x1 += 0x10;
        x2 += 0x87;
        y2 += 7;
        palette += 7;
        tile += 0x1E;
        windows += 0x38;
    }
    AddWindowParameterized(bgConfig, lastWindow, 4, 8, 0, 7, 2, 12, 0x2BF);
    FillWindowPixelBuffer(lastWindow, 0);
}
