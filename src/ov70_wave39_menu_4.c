#include "ov70_wave39_menu_private.h"

int ov70_02243AC4(void *w) {
    ov70_02241DB4(w, 5);
    Sprite_SetDrawFlag(PTR(w, 0xc), 0);
    if (S16(w, 0x3e) < 0) {
        U32(w, 0x4c) = 19;
    } else {
        sub_020198FC(PTR(w, 0x1c), 0, -4, 0, 3);
        if (PTR(w, 0x18)) {
            Sprite_SetDrawFlag(PTR(w, 0x18), 0);
        }
        Sprite_SetAnimCtrlSeq(PTR(w, 0xc), 0x32);
        U32(w, 0x4c) = 2;
        U32(w, 0x50) = 24;
    }
    return -1;
}
