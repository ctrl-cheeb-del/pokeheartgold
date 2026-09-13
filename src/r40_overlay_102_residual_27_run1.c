#include "r40_overlay_102_residual_27_private.h"

void ov102_021EB170(u8 *p, int i) {
    FillWindowPixelRect(p + 0x4c, 9, 0, 0, 0xe, 0x20);
    ListMenuUpdateCursorObj(*(void **)(p + 0x80), p + 0x4c, 0, i * 16);
}
