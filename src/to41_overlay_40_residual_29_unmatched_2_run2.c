#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

void ov40_022368EC(void *p, int a) {
    void *w = PTR(p, 0x860);
    if (a == 0) {
        ManagedSprite_SetDrawFlag(PTR(w, 0x368), 1);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x36C), 1);
        ManagedSprite_SetPositionXY(PTR(w, 0x34C), 0x20, 0xE8);
    } else {
        ManagedSprite_SetDrawFlag(PTR(w, 0x368), 0);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x36C), 0);
        ManagedSprite_SetPositionXY(PTR(w, 0x34C), 0x50, 0xE8);
    }
    sub_020136B4(PTR(w, 0x350), 0x24, -8);
    sub_020136B4(PTR(w, 0x36C), 0x24, -8);
}
