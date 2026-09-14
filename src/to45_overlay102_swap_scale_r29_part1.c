#include "overlay102_swap_scale_r29_private.h"

void ov102_021EB530(Ov102Owner *work, u16 selection) {
    VecFx32 scale;

    scale.z = 0;
    if (selection == 1 || selection != 2) {
        scale.x = 55 << 14;
        scale.y = 30 << 14;
    } else {
        scale.x = 55 << 14;
        scale.y = 9 << 16;
    }
    Sprite_SetMatrix(work->sprite, &scale);
    Sprite_SetAnimCtrlSeq(work->sprite, 2);
}
