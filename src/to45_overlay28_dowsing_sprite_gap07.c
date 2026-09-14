#include "to45_overlay28_gap07_private.h"

void ov28_0225E374(To45Ov28Work *work, u16 *first, u16 *second) {
    if (work->counter > ov28_0225EA90[work->mode * 2]) {
        work->counter = ov28_0225EA90[work->mode * 2];
    }
    *first = (work->counter / 10) & 1;
    *second = work->counter / 20;
}

void ov28_0225E3BC(To45Ov28Work *work) {
    u32 i;
    u16 first;
    u16 second;

    if (work->counter == 0) {
        for (i = 0; i < 4; i++) {
            Sprite_SetDrawFlag(work->sprites[i], FALSE);
        }
        return;
    }
    ov28_0225E374(work, &first, &second);
    for (i = 0; i < 4; i++) {
        Sprite_SetPalIndexRespectVramOffset(work->sprites[i], second + 1);
        Sprite_SetAnimCtrlSeq(work->sprites[i], first);
        Sprite_SetDrawFlag(work->sprites[i], TRUE);
    }
}
