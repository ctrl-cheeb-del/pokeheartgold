#include "render_window_internal.h"

void DrawFrameAndWindow2(void *window, BOOL copy, u32 baseTile, u32 color) {
    sub_0200E948(window, baseTile, color);
    if (copy == 0) {
        CopyWindowToVram(window);
    }
    TextPrinter_SetDownArrowBaseTile(baseTile);
}
