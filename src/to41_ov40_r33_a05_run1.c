#include "to41_ov40_r33_a05_private.h"

void ov40_0223B4BC(void *p, int mode) {
    void *w = PTR(p, 0x860);
    if (mode == 0) {
        ManagedSprite_SetDrawFlag(PTR(w, 0x134), 1);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x138), 1);
        ManagedSprite_SetPositionXY(PTR(w, 0x118), 0x20, 0xE8);
    } else {
        ManagedSprite_SetDrawFlag(PTR(w, 0x134), 0);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x138), 0);
        ManagedSprite_SetPositionXY(PTR(w, 0x118), 0x50, 0xE8);
    }
    sub_020136B4(PTR(w, 0x11C), 0x24, -8);
    sub_020136B4(PTR(w, 0x138), 0x24, -8);
}
