#include "r46_overlay48_r2_private.h"

u32 ov48_0225909C(void *work) {
    Ov48WorkR2 *w = work;
    u32 result;
    u32 coord[3];

    ov48_02259DA0(&w->flags);
    if ((w->flags & 2) != 0) {
        PlaySE(0x5DD);
        return 2;
    }

    if ((gSystem.newKeys & 0x400) != 0) {
        if (ov48_02259188(work, coord) == TRUE && ov48_0225A244(w->coordState, coord) == FALSE && ov48_0225A20C(w->coordState, coord) != FALSE) {
            ov48_022593B4(work, coord[1], coord[2]);
            PlaySE(0x5D6);
        }
    } else {
        result = ov48_02258D54(work, gSystem.newKeys, gSystem.heldKeys);
    }

    return result;
}

void ov48_02259130(void *work, void **args) {
    u32 index;
    u32 x;
    u32 y;

    if (ov48_022593B4(work, U32AT(work, 0x14), U32AT(work, 0x18)) != FALSE) {
        return;
    }

    index = ov48_0225B13C(*args);
    if (index == 0x32) {
        return;
    }

    x = ov45_0222D6B0(*args, index);
    y = ov45_0222D6D4(*args, index);
    if (ov48_022593B4(work, x, y) != TRUE) {
        GF_AssertFail();
    }
}
