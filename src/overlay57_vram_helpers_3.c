#include "overlay57_vram_helpers_private.h"

void ov57_02238D80(void *work) {
    R20_U32(work, 0x40c) = ((u32)R20_U8(R20_PTR(work, 0x24c), 0x27) << 24) >> 25;
    TouchscreenListMenu_Destroy(R20_PTR(work, 0x24c));
    ListMenuItems_Delete(R20_PTR(work, 0x1bc));
}

void ov57_02238DAC(s32 value, s16 *x, s16 *y) {
    s32 column = value % 4;
    *x = column * 0x38 + 0x28;
    *y = (value >> 2) * 0x35 + 0x1b;
}
