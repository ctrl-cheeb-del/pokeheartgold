#include "overlay68_helpers_internal.h"

void ov68_021E6C74(MoveRelearner *d) {
    ClearFrameAndWindow2(&d->windows[6], TRUE);
    ClearWindowTilemapAndScheduleTransfer(&d->windows[6]);
}

u32 ov68_021E6C8C(u32 a0, u32 a1) {
    switch (a1) {
    case 1:
        return GF_IsAnySEPlaying();
    case 2:
        return IsFanfarePlaying();
    case 3:
        PlaySE(0x5E6);
        break;
    case 4:
        PlayFanfare(0x4A0);
        break;
    case 5:
        return IsSEPlaying(0x5E6);
    }
    return 0;
}

u32 ov68_021E6CD8(MoveRelearner *d) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if (!GetMonData(d->args->unk_00, i + 0x36, NULL)) {
            break;
        }
    }
    return i;
}

u32 ov68_021E6D00(MoveRelearner *d) {
    ov68_021E6C14(d, 3);
    d->args->unk_1B = ov68_021E6CD8(d);
    d->state = 5;
    return 2;
}

u32 ov68_021E6D20(MoveRelearner *d) {
    ov68_021E6C74(d);
    if (d->unk_1CE == 0) {
        ov68_021E7A18(d, 5);
    }
    return 1;
}

u32 ov68_021E6D40(MoveRelearner *d) {
    d->args->unk_1A = 1;
    return 8;
}

u32 ov68_021E6D4C(MoveRelearner *d) {
    ov68_021E6C74(d);
    return 1;
}

u32 ov68_021E6D58(MoveRelearner *d) {
    d->state = 10;
    return 0;
}

u32 ov68_021E6D64(MoveRelearner *d) {
    ov68_021E6C14(d, 7);
    d->unk_1BA = 3;
    d->state = 3;
    return 2;
}

u32 ov68_021E6D80(MoveRelearner *d) {
    ov68_021E6C14(d, 8);
    d->state = 8;
    d->args->unk_1A = 1;
    return 2;
}

u32 ov68_021E6D9C(MoveRelearner *d) {
    ov68_021E6C14(d, 4);
    d->unk_1BA = 2;
    d->state = 3;
    return 2;
}

u32 ov68_021E6DB8(MoveRelearner *d) {
    ov68_021E6C14(d, 5);
    d->state = 6;
    return 2;
}

u32 ov68_021E6DD0(MoveRelearner *d) {
    d->state = 10;
    return 0;
}
