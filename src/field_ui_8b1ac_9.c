#include "field_ui_8b1ac_internal.h"

void sub_0208BF9C(u8 *work) {
    void *data = *(void **)(work + 0x22C);
    if (((u8 *)data)[0x11] == 2) {
        Sprite_SetPositionXY(*(void **)(work + 0x528), 0xD7, 0x50);
        Sprite_SetPositionXY(*(void **)(work + 0x52C), 0xD7, 0x50);
    }
}

void sub_0208BFD0(u8 *work) {
    void *mon;
    if ((*(u8 **)(work + 0x22C))[0x11] != 2) {
        return;
    }
    mon = sub_0208A520(work);
    if (*(u32 *)(work + 0x7D4) == 0) {
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x528), 1);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x52C), 0);
        sub_0208BE00(work, mon, 0x49);
        thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x528), Boxmon_GetIconPalette(mon) + 12);
    } else {
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x528), 0);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x52C), 1);
        sub_0208BE00(work, mon, 0x4A);
        thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x52C), Boxmon_GetIconPalette(mon) + 12);
    }
    *(u32 *)(work + 0x7D4) ^= 1;
}

void sub_0208C068(u8 *work) {
    if (*(s8 *)(work + 0x7BC) == 1) {
        Sprite_SetPositionXY(*(void **)(work + 0x450), 0xA0, 0x10);
    } else {
        Sprite_SetPositionXY(*(void **)(work + 0x450), 0x20, 0x44);
    }
    thunk_Sprite_SetDrawFlag(*(void **)(work + 0x450), 1);
}

s16 sub_0208C0A4(int scale, s16 current, s16 target) {
    u32 delta;
    if (target > current) {
        delta = ((u32)((target - current) * (scale + 44)) << 16) / 300;
        delta >>= 16;
        return target - (s16)delta;
    }
    delta = ((u32)((current - target) * (scale + 44)) << 16) / 300;
    delta >>= 16;
    return target + (s16)delta;
}

void sub_0208C0E8(u8 *work) {
    s16 x;
    x = sub_0208C0A4(work[0x275], 0x58, 0x58);
    Sprite_SetPositionXY(*(void **)(work + 0x4C0), x, sub_0208C0A4(work[0x275], 0x31, 0x49));
    x = sub_0208C0A4(work[0x276], 0x6E, 0x58);
    Sprite_SetPositionXY(*(void **)(work + 0x4C4), x, sub_0208C0A4(work[0x276], 0x41, 0x49));
    x = sub_0208C0A4(work[0x277], 0x67, 0x58);
    Sprite_SetPositionXY(*(void **)(work + 0x4C8), x, sub_0208C0A4(work[0x277], 0x5C, 0x49));
    x = sub_0208C0A4(work[0x278], 0x48, 0x57);
    Sprite_SetPositionXY(*(void **)(work + 0x4CC), x, sub_0208C0A4(work[0x278], 0x5C, 0x49));
    x = sub_0208C0A4(work[0x279], 0x41, 0x57);
    Sprite_SetPositionXY(*(void **)(work + 0x4D0), x, sub_0208C0A4(work[0x279], 0x41, 0x49));
    Sprite_SetDrawFlag(*(void **)(work + 0x4C0), 1);
    Sprite_SetDrawFlag(*(void **)(work + 0x4C4), 1);
    Sprite_SetDrawFlag(*(void **)(work + 0x4C8), 1);
    Sprite_SetDrawFlag(*(void **)(work + 0x4CC), 1);
    Sprite_SetDrawFlag(*(void **)(work + 0x4D0), 1);
}

void sub_0208C208(u8 *work) {
    Sprite_SetDrawFlag(*(void **)(work + 0x4C0), 0);
    Sprite_SetDrawFlag(*(void **)(work + 0x4C4), 0);
    Sprite_SetDrawFlag(*(void **)(work + 0x4C8), 0);
    Sprite_SetDrawFlag(*(void **)(work + 0x4CC), 0);
    Sprite_SetDrawFlag(*(void **)(work + 0x4D0), 0);
}

void sub_0208C250(u8 *work, int ribbon, int index) {
    int attr = GetRibbonAttr(ribbon, 1);
    SpriteSystem_ReplaceCharResObj(*(void **)(work + 0x3FC), *(void **)(work + 0x400), 0x27, attr, 0, index + 0x19);
    attr = GetRibbonAttr(ribbon, 2);
    thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x404 + (index + 0x36) * 4), attr + 7);
}
