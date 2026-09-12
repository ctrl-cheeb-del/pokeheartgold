#include "wireless_trade_select_partial_private.h"

void ov65_0221BFBC(void *p, u32 a, u32 b, u32 c, u32 i, void *sprite) {
    GX_LoadOBJ(PTR(p, 0x14), (i * 16 + 0x92) * 32, 0x200);
    Sprite_SetPalOffset(sprite, GetMonIconPaletteEx(a, b, c) + 10);
}
