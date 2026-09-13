#include "r40_overlay_69_residual_2_private.h"
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov69_021E60F8(void) {
    GraphicsBanks banks = ov69_021E77B8;
    GfGfx_SetBanks(&banks);
}

void ov69_021E6118(void) {
    GraphicsModes modes = ov69_021E7688;
    SetBothScreensModesAndDisable(&modes);
}
