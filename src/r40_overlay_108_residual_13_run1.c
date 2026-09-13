#include "r40_overlay_108_residual_13_private.h"

void ov108_021E78F4(SafariAreaCustomizer *work, u32 index, u32 animation) {
    s16 x;
    s16 y;
    int sequence = 0;

    if (animation >= 6) {
        x = 0xE0;
        y = 0xB4;
        sequence = 1;
    } else if (index != 1) {
        x = ((s32)animation % 3) * 0x48 + 0x38;
        y = ((s32)animation / 3) * 0x48 + 0x38;
        if (index == 2) {
            y += 0xC0;
        } else if (index == 3) {
            sequence = 2;
        } else if (index == 0 && work->mode == 2) {
            sequence = 3;
        }
    } else {
        x = ((s32)animation % 3) * 0x50 + 0x30;
        y = ((s32)animation / 3) * 0x48 + 0x38;
    }
    Sprite_SetPositionXY(work->sprites[index], x, y);
    ov108_021E78C0(work, index, sequence, TRUE);
}
