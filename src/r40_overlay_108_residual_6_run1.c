#include "r40_overlay_108_residual_6_private.h"

u32 ov108_021E6894(SafariAreaCustomizer *work) {
    u32 keys = gSystem.newKeys;
    u8 column;
    u8 row;

    if (keys & 2) {
        ov108_021E6850(work);
        work->unk0C = 2;
        PlaySE(0x5DC);
        return 4;
    }
    if (keys & 1) {
        if (work->unk184E0 >= 6 || work->unk184DF == work->unk184E0) {
            ov108_021E6850(work);
            work->unk0C = 2;
            PlaySE(0x5DC);
            return 4;
        }
        PlaySE(0x69C);
        return 3;
    }
    if (!(keys & 0xF0)) {
        return 0;
    }

    column = (s32)work->unk184E0 % 3;
    row = (s32)work->unk184E0 / 3;
    if (row < 2) {
        if (keys & 0x10) {
            column = (column + 1) % 3;
        } else if (keys & 0x20) {
            column = (column + 2) % 3;
        }
    }
    if (keys & 0x40) {
        row = (row + 2) % 3;
    } else if (keys & 0x80) {
        row = (row + 1) % 3;
    }
    work->unk184E0 = row * 3 + column;
    if (row < 2 || (gSystem.newKeys & 0xC0)) {
        PlaySE(0x5E5);
    }
    ov108_021E78F4(work, 0, work->unk184E0);
    return 0;
}

u32 ov108_021E69A0(SafariAreaCustomizer *work) {
    int hit = TouchscreenHitbox_FindRectAtTouchNew(ov108_021EA760);

    if (hit == -1) {
        return 0;
    }
    if (hit == 6) {
        u16 value = 0xFFFE;
        if (!DoesPixelAtScreenXYMatchPtrVal(work->bgConfig, 3, gSystem.touchX, gSystem.touchY, &value)) {
            return 0;
        }
        work->unk184E0 = 6;
        ov108_021E6850(work);
        work->unk0C = 2;
        PlaySE(0x5DC);
        return 4;
    }
    if (work->unk184DF == hit) {
        ov108_021E6850(work);
        work->unk0C = 2;
        PlaySE(0x5DC);
        return 4;
    }
    work->unk184E0 = hit;
    ov108_021E78F4(work, 0, work->unk184E0);
    PlaySE(0x69C);
    return 3;
}
