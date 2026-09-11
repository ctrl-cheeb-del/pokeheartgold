#include "overlay115_remaining_internal.h"

void ov115_0225F020(Ov115Work *work, void *a, void *b, void *c, void *d) {
    int i;

    work->delay = 0;
    work->count = 0;
    for (i = 0; i < 4; i++) {
        work->sprites[i] = ov01_021F0718(a, b, c, d, 0, 0);
        Sprite_SetDrawFlag(work->sprites[i], 0);
        Sprite_SetAnimActiveFlag(work->sprites[i], 1);
        if (i != 3) {
            Sprite_SetAffineOverwriteMode(work->sprites[i], 2);
            Sprite_SetAnimCtrlSeq(work->sprites[i], 1);
            ov01_021EFE70(&work->motion[i], FX32_CONST(2), FX32_CONST(1), 6);
        } else {
            ov01_021EFE70(&work->motion[i], FX32_CONST(1), FX32_CONST(1), 6);
        }
    }
}
