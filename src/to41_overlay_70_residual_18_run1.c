#include "to41_overlay_70_residual_18_private.h"

void ov70_0223AE40(R14Work *w) {
    int i;

    RemoveWindow(w + 0xf18);
    ClearWindowTilemapAndCopyToVram(w + 0xf68);
    ClearWindowTilemapAndCopyToVram(w + 0xf58);
    RemoveWindow(w + 0xf68);
    RemoveWindow(w + 0xf58);
    for (i = 0, w += 0x1058; i < 16; i++, w += 0x10) {
        ClearWindowTilemapAndCopyToVram(w);
        RemoveWindow(w);
    }
}
