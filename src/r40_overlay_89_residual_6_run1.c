#include "r40_overlay_89_residual_6_private.h"

void ov89_0225A1D8(void *state, int index) {
    u16 *unfaded = PaletteData_GetUnfadedBuf(PTR(state, 0xc), (PaletteBufferId)2);
    u16 *faded = PaletteData_GetFadedBuf(PTR(state, 0xc), (PaletteBufferId)2);
    MIi_CpuCopy16((u16 *)((u8 *)unfaded + 0x22), (u16 *)((u8 *)faded + 0x22), 0xc);
    index += 0x11;
    BlendPalette(unfaded + index, faded + index, 1, 6, 0);
}

void ov89_0225A21C(void *state) {
    int i;
    u8 *p = state;
    for (i = 0; i < 3; i++, p += 4) {
        ManagedSprite *sprite = *(ManagedSprite **)(p + 0x990);
        if (sprite != NULL) {
            if (!ManagedSprite_IsAnimated(sprite)) {
                Sprite_DeleteAndFreeResources(*(ManagedSprite **)(p + 0x990));
                *(ManagedSprite **)(p + 0x990) = NULL;
            } else {
                Sprite_TickFrame(*(Sprite **)*(ManagedSprite **)(p + 0x990));
            }
        }
    }
}
