#include "ov70_wave39_menu_private.h"

int ov70_02243700(void *w) {
    Sprite_SetDrawFlag(PTR(w, 0x10), 0);
    Sprite_SetDrawFlag(PTR(w, 0x14), 0);
    ov70_02241DB4(w, 0);
    ListMenuItems_Delete(PTR(w, 0x34));
    if (S16(w, 0x3c) > 8) {
        GF_AssertFail();
    }
    U32(w, 0x4c) = ov70_02245F5C[S16(w, 0x3c)].a == 1 ? 7 : 11;
    return -1;
}

int ov70_02243750(void *w) {
    ov70_02241DB4(w, 0);
    ListMenuItems_Delete(PTR(w, 0x34));
    return S16(w, 0x40);
}

int ov70_02243768(void *w) {
    int n;
    ov70_02242D44(w, 6, 0x20);
    sub_020198FC(PTR(w, 0x1c), 0, -4, 0, 4);
    U32(w, 0x4c) = 1;
    U32(w, 0x50) = 17;
    U32(w, 0x48) = 10;
    S16(w, 0x3c) = -1;
    n = U32(w, 0x48);
    ov70_02238F9C(PTR(w, 0xc), (ov70_02245DF8[n * 2] + 16) * 8, ov70_02245DF9[n * 2] * 8);
    Sprite_SetAnimCtrlSeq(PTR(w, 0xc), 0x31);
    return -1;
}
