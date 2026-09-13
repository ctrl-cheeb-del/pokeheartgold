#include "r40_overlay_68_residual_16_private.h"

void ov68_021E7898(MoveRelearner *d, u32 enabled) {
    if (enabled == TRUE) {
        GridInputHandler_SetEnabledFlag(d->unk_1C8, 7);
        ScheduleWindowCopyToVram(&d->windows[8]);
        ov68_021E66A0(d, 15, 20, 8, 4, 8, 12);
        d->unk_1CE = 1;
    } else {
        GridInputHandler_ClearEnabledFlag(d->unk_1C8, 7);
        ClearWindowTilemapAndScheduleTransfer(&d->windows[8]);
        ov68_021E66A0(d, 15, 20, 8, 4, 0, 12);
        d->unk_1CE = 0;
    }
}

void ov68_021E7910(MoveRelearner *d) {
    if (d->unk_1B8 < 4) {
        GridInputHandler_ClearEnabledFlag(d->unk_1C8, 4);
        GridInputHandler_ClearEnabledFlag(d->unk_1C8, 5);
        return;
    }

    if (d->args->unk_16 == 0) {
        GridInputHandler_ClearEnabledFlag(d->unk_1C8, 5);
    } else {
        GridInputHandler_SetEnabledFlag(d->unk_1C8, 5);
    }

    if (d->args->unk_16 + 4 >= d->unk_1B8) {
        GridInputHandler_ClearEnabledFlag(d->unk_1C8, 4);
    } else {
        GridInputHandler_SetEnabledFlag(d->unk_1C8, 4);
    }
}

void ov68_021E797C(MoveRelearner *d, s32 direction) {
    ManagedSprite_SetAnimateFlag(d->sprites[1], TRUE);
    ManagedSprite_SetAnimateFlag(d->sprites[0], TRUE);
    ManagedSprite_SetAnimationFrame(d->sprites[1], 0);
    ManagedSprite_SetAnimationFrame(d->sprites[0], 0);

    if (direction > 0) {
        if (d->args->unk_16 + 4 < d->unk_1B8) {
            ManagedSprite_SetAnim(d->sprites[0], 1);
        } else {
            ManagedSprite_SetAnim(d->sprites[0], 3);
        }
        ManagedSprite_SetAnim(d->sprites[1], 4);
    } else {
        if (d->args->unk_16 == 0) {
            ManagedSprite_SetAnim(d->sprites[1], 7);
        } else {
            ManagedSprite_SetAnim(d->sprites[1], 5);
        }
        ManagedSprite_SetAnim(d->sprites[0], 0);
    }
}
