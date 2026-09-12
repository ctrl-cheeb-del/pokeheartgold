#include "overlay40_palette_resources_r7_private.h"

void ov40_0222DD08(u8 *work) {
    PaletteData_BlendPalettes(*(void **)(work + 0x28), 2, 0xFFFF, 0, *(u32 *)(work + 0x58));
    PaletteData_BlendPalettes(*(void **)(work + 0x28), 0, 0xFFFF, 0, *(u32 *)(work + 0x58));
    PaletteData_BlendPalettes(*(void **)(work + 0x28), 3, 0xFFFF, 0, *(u32 *)(work + 0x58));
    PaletteData_BlendPalettes(*(void **)(work + 0x28), 1, 0xFFFF, 0, *(u32 *)(work + 0x58));
}
