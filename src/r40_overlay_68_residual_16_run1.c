#include "r40_overlay_68_residual_16_private.h"

void ov68_021E7618(MoveRelearner *d, s32 selection, u32 direction) {
    ov68_021E7898(d, 0);
    ov68_021E7A18(d, 5);

    if (selection <= 3) {
        PlaySE(0x5dd);
        d->args->unk_14 = selection;
        if (d->args->unk_16 + d->args->unk_14 < d->unk_1B8) {
            ov68_021E68D4(d, ov68_021E6BEC(d));
        } else {
            ov68_021E68D4(d, -2);
        }
    } else if (selection == 6) {
        if (direction == 3 && d->args->unk_16 + 4 < d->unk_1B8) {
            PlaySE(0x5dd);
            selection = 3;
            GridInputHandler_SetNextInput(d->unk_1C8, selection);
            d->args->unk_16++;
            ov68_021E67E0(d);
            ov68_021E68D4(d, ov68_021E6BEC(d));
            ov68_021E7910(d);
            ov68_021E797C(d, 1);
        } else if (direction == 0) {
            if (d->args->unk_16 != 0) {
                PlaySE(0x5dd);
                d->args->unk_16--;
                ov68_021E67E0(d);
                ov68_021E68D4(d, ov68_021E6BEC(d));
                ov68_021E7910(d);
                ov68_021E797C(d, -1);
            }
            selection = 0;
            GridInputHandler_SetNextInput(d->unk_1C8, selection);
        } else {
            PlaySE(0x5dd);
            ov68_021E68D4(d, -2);
        }
    } else {
        PlaySE(0x5dd);
    }
    ov68_021E73A4(d, (u8)selection, 3);
}
