#include "ov70_wave39_menu_private.h"

int ov70_02243848(void *w) {
    ov70_02241DB4(w, 6);
    Sprite_SetDrawFlag(PTR(w, 0xc), 0);
    if (S16(w, 0x3c) < 0) {
        if (S16(w, 0x3c) == -1) {
            return -2;
        }
        if (S16(w, 0x3c) == -2) {
            return 0;
        }
    } else {
        if (S16(w, 0x3c) > 8) {
            GF_AssertFail();
        }
        if (ov70_02245F5C[S16(w, 0x3c)].a == 1) {
            S16(w, 0x3e) = 0;
            sub_020198FC(PTR(w, 0x1c), 0, -4, 0, 3);
            if (PTR(w, 0x18)) {
                Sprite_SetDrawFlag(PTR(w, 0x18), 0);
            }
            Sprite_SetAnimCtrlSeq(PTR(w, 0xc), 0x32);
            U32(w, 0x4c) = 2;
            U32(w, 0x50) = 24;
        } else {
            U32(w, 0x4c) = 20;
        }
    }
    return -1;
}

int ov70_022438D4(void *w) {
    int n;
    u8 x, y;
    ov70_02242D44(w, 6, 0x10);
    Sprite_SetAnimCtrlSeq(PTR(w, 0xc), 0x3d);
    Sprite_SetDrawFlag(PTR(w, 0xc), 1);
    n = S16(w, 0x3c);
    x = ov70_02245DF8[n * 2];
    y = ov70_02245DF9[n * 2];
    U32(w, 0x48) = n;
    ov70_02238F9C(PTR(w, 0xc), (x + 16) * 8, y * 8);
    if (PTR(w, 0x18)) {
        Sprite_SetDrawFlag(PTR(w, 0x18), 1);
    }
    U32(w, 0x4c) = 17;
    return -1;
}
