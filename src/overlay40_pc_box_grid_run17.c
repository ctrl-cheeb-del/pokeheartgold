#include "overlay40_pc_box_grid_private.h"

void ov40_02235994(void) {
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}

void ov40_022359B4(void *p, int a) {
    void *w = PTR(p, 0x860);
    if (a == 0) {
        ManagedSprite_SetDrawFlag(PTR(w, 0x1B8), 1);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x1BC), 1);
        ManagedSprite_SetPositionXY(PTR(w, 0x19C), 0x20, 0xE8);
    } else {
        ManagedSprite_SetDrawFlag(PTR(w, 0x1B8), 0);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x1BC), 0);
        ManagedSprite_SetPositionXY(PTR(w, 0x19C), 0x50, 0xE8);
    }
    sub_020136B4(PTR(w, 0x1A0), 0x24, -8);
    sub_020136B4(PTR(w, 0x1BC), 0x24, -8);
}
