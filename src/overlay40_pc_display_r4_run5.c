#include "overlay40_pc_display_r4_private.h"

void ov40_0222CF94(void *p) {
    int i;
    u8 *row = (u8 *)p + 0x534;

    for (i = 0; i < 5; i++, row += 0x28) {
        Sprite_DeleteAndFreeResources(PTR(row, 0));
        Sprite_DeleteAndFreeResources(PTR(row, 0xC8));
    }
}

void ov40_0222CFBC(void *p, int draw) {
    int i;
    u8 *row = p;

    for (i = 0; i < 5; i++, row += 0x28) {
        if (WORD(row, 0x540) == 0) {
            TextOBJ_SetSpritesDrawFlag(PTR(row, 0x548), 0);
            ManagedSprite_SetDrawFlag(PTR(row, 0x534), 0);
        } else {
            TextOBJ_SetSpritesDrawFlag(PTR(row, 0x548), draw);
            ManagedSprite_SetDrawFlag(PTR(row, 0x534), draw);
        }
        if (WORD(row, 0x608) == 0) {
            TextOBJ_SetSpritesDrawFlag(PTR(row, 0x610), 0);
            ManagedSprite_SetDrawFlag(PTR(row, 0x5FC), 0);
        } else {
            TextOBJ_SetSpritesDrawFlag(PTR(row, 0x610), draw);
            ManagedSprite_SetDrawFlag(PTR(row, 0x5FC), draw);
        }
    }
}
