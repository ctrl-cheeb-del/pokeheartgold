#include "palette_fade_state_internal.h"

void ResetVisibleHardwareWindows(int screen) {
    sub_020131F4(0, screen);
}

void SetMasterBrightnessNeutral(int screen) {
    SetMasterBrightness(screen, 0);
}

void sub_0200FBF4(int screen, u16 color) {
    if (color == 0xffff) {
        color = _021D1034.color;
    }
    SetMasterBrightness(screen, color == 0x7fff ? 16 : -16);
}

void sub_0200FC20(u16 color) {
    int brightness;
    if (color == 0xffff) {
        color = _021D1034.color;
    }
    brightness = color == 0x7fff ? 16 : -16;
    SetMasterBrightness(0, brightness);
    SetMasterBrightness(1, brightness);
    _021D1034.color = color;
}

void sub_0200FC60(int screen, u16 color) {
    if (color == 0xffff) {
        color = _021D1034.color;
    }
    if (screen == 0) {
        GX_LoadBGPltt(&color, 0, 2);
    } else {
        GXS_LoadBGPltt(&color, 0, 2);
    }
    sub_02013424(_021D0F80, 1, screen);
    sub_02013440(_021D0F80, 0x3f, 0, 0, screen);
    sub_02013488(_021D0F80, 0, 0, 0, 0, 0, screen);
    sub_02013468(_021D0F80, 0x20, 0, screen);
}

void sub_0200FCDC(u16 color) {
    GX_LoadBGPltt(&color, 0, 2);
    GXS_LoadBGPltt(&color, 0, 2);
}

void SetMasterBrightness(int screen, int brightness) {
    if (screen == 0) {
        GXx_SetMasterBrightness_((vu16 *)0x0400006c, brightness);
    } else {
        GXx_SetMasterBrightness_((vu16 *)0x0400106c, brightness);
    }
}

void HandleEndFade(void *arg) {
    u8 *fade = arg;
    *(u16 *)(fade + 0x14c) = 0;
    *(u16 *)(fade + 0x150) = sub_0201002C(fade);
    if (*(u32 *)(fade + 0xc) != 0) {
        sub_02010094(fade + 0x14);
        if (*(u32 *)(fade + 0x3c) == 0) {
            _021D1034.mainDone = 0;
        }
    }
    if (*(u32 *)(fade + 0x10) != 0) {
        sub_02010094(fade + 0x44);
        if (*(u32 *)(fade + 0x3c) == 0) {
            _021D1034.subDone = 0;
        }
    }
    sub_020100C4(fade);
}
