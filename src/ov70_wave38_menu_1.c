#include "ov70_wave38_menu_private.h"

int ov70_0224308C(void *w) {
    ov70_02242D44(w, 4, 0x20);
    Sprite_SetAnimCtrlSeq(PTR(w, 0xc), 0x3d);
    ov70_02238F9C(PTR(w, 0xc), 0x88, 0x28);
    sub_020198FC(PTR(w, 0x1c), 0, -4, 0, 4);
    U32(w, 0x4c) = 1;
    U32(w, 0x50) = 5;
    S16(w, 0x3c) = -1;
    return -1;
}

int ov70_022430CC(void *w) {
    u32 r = ov70_022421D0(w, (u8 *)w + 0x64);
    if (r == (u32)-2) {
        goto cancel;
    }
    if (r > 8) {
        goto done;
    }
    Sprite_SetDrawFlag(PTR(w, 0xc), 0);
    U32(w, 0x4c) = 6;
    S16(w, 0x3c) = r;
    goto done;
cancel:
    Sprite_SetDrawFlag(PTR(w, 0xc), 0);
    sub_020198FC(PTR(w, 0x1c), 0, 4, 0, 4);
    U32(w, 0x4c) = 3;
    U32(w, 0x50) = 6;
    S16(w, 0x3c) = -1;
done:
    return -1;
}

int ov70_02243120(void *w) {
    int state;
    ov70_02241DB4(w, 4);
    Sprite_SetDrawFlag(PTR(w, 0xc), 0);
    if (S16(w, 0x3c) < 0) {
        goto negative;
    }
    if (S16(w, 0x3c) > 8) {
        GF_AssertFail();
    }
    if (ov70_02245F5C[S16(w, 0x3c)].a == 1) {
        S16(w, 0x3e) = 0;
        state = 12;
    } else {
        state = 8;
    }
    goto common;
negative:
    return -2;
common:
    U32(w, 0x4c) = state;
    return -1;
}
