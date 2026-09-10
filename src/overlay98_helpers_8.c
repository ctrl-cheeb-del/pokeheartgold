#include "overlay_98_helpers_internal.h"

void ov98_0221F090(void) {
    sub_0200FBF4(0, 0);
    sub_0200FBF4(1, 0);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    reg_GX_POWCNT &= 0xFFFF7FFF;
    ov98_0221F174();
}

void ov98_0221F0EC(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
}

u32 ov98_0221F120(u32 value, u32 digit) {
    u32 remainder;
    GF_ASSERT(digit != 0 && digit < 5);
    remainder = value % ov98_0221F1E4[digit];
    digit--;
    return remainder / ov98_0221F1E4[digit];
}

u8 ov98_0221F150(s32 value) {
    u8 count = 0;
    if (value == 0) {
        return 1;
    }
    while (1) {
        if (value == 0) {
            break;
        }
        value /= 10;
        count++;
    }
    return count;
}

void ov98_0221F174(void) {
    GraphicsBanks banks = ov98_0221F248;
    GfGfx_SetBanks(&banks);
}
