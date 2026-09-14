#include "to47_overlay83_hp_action_r4_private.h"

int ov83_02240FAC(u8 *work, u32 selected, u32 action)
{
    u32 slot;
    u32 hp;
    u32 barPalette;
    void *mon;
    u32 maxHp;
    u32 spritePalette;

    slot = ov83_02247768(O83_U8(work, 0x14), selected);
    mon = Party_GetMonByIndex(O83_PTR(work, 0x7A4), slot);
    hp = GetMonData(mon, 0xA3, NULL);
    maxHp = GetMonData(mon, 0xA4, NULL);
    barPalette = ov83_022411B0(work, CalculateHpBarColor(hp, maxHp, 0x30));
    spritePalette = ov83_022411DC(work, CalculateHpBarColor(hp, maxHp, 0x30));

    switch (action) {
    case 4:
    case 8:
        O83_U8(work, 0xE) &= ~4;
        return 1;
    case 1:
    case 2:
    case 3:
        if (O83_FLAGS(work)->bit2 == 0) {
            s16 x;
            O83_U8(work, 0xE) |= 4;
            if (ov80_02237D8C(O83_U8(work, 9)) == 0) {
                x = 0x40;
            } else {
                x = 0x20;
            }
            O83_PTR(work, 0x75C) = ov83_02247454(work + 0x518, 0, 0, 0, 8, x + slot * 0x40, 0x3E, 0, 0);
        }
        if (O83_PTR(work, 0x75C) != NULL && ov83_02247624(O83_PTR(work, 0x75C)) == 0) {
            ov83_0224753C(O83_PTR(work, 0x75C));
            O83_PTR(work, 0x75C) = NULL;
        }
        if (O83_PTR(work, 0x75C) == NULL) {
            hp = GetMonData(mon, 0xA3, NULL);
            ov83_02240238(work, work + 0x80, slot, hp);
            if (O83_U8(work, 0xD) == slot) {
                ov83_02241E18(work);
                ov83_022421E0(work, 0);
            }
            ov83_022475D4(O83_PTR(work, 0x768 + slot * 4), spritePalette);
            ov83_02247600(O83_PTR(work, 0x73C + slot * 4), (u8)barPalette);
            O83_U8(work, 0xE) &= ~4;
            return 1;
        }
        break;
    case 6:
    case 7:
        if (O83_FLAGS(work)->bit2 == 0) {
            s16 x;
            O83_U8(work, 0xE) |= 4;
            if (ov80_02237D8C(O83_U8(work, 9)) == 0) {
                x = 0x40;
            } else {
                x = 0x20;
            }
            O83_PTR(work, 0x75C) = ov83_02247454(work + 0x518, 0, 0, 0, 0x10, x + slot * 0x40, 0x3E, 0, 0);
        }
        if (ov83_02247624(O83_PTR(work, 0x75C)) == 0) {
            ov83_0224753C(O83_PTR(work, 0x75C));
            O83_PTR(work, 0x75C) = NULL;
            O83_U8(work, 0xE) &= ~4;
            return 1;
        }
        break;
    case 9:
        O83_U8(work, 0xE) &= ~4;
        return 1;
    case 10:
        O83_U8(work, 0xE) &= ~4;
        return 1;
    }
    return 0;
}

int ov83_022411B0(void *value, u32 choice)
{
    switch (choice) {
    case 4:
        return 1;
    case 3:
        return 2;
    case 2:
        return 3;
    case 1:
        return 4;
    default:
        return (int)value;
    }
}

int ov83_022411DC(void *value, u32 choice)
{
    switch (choice) {
    case 4:
        return 15;
    case 3:
        return 15;
    case 2:
        return 14;
    case 1:
        return 13;
    default:
        return (int)value;
    }
}

void ov83_02241208(u8 *work, int delta)
{
    s8 selected = O83_S8(work, 0xD) + delta;
    void *mon;

    if (selected < 0) {
        selected = O83_U8(work, 0x14) - 1;
    } else if (selected >= O83_U8(work, 0x14)) {
        selected = 0;
    }
    O83_U8(work, 0xD) = selected;
    ov83_02240DB0(work);
    mon = Party_GetMonByIndex(O83_PTR(work, 0x7A4), ov83_02247768(O83_U8(work, 0x14), O83_U8(work, 0xD)));
    ov83_0223FD4C(work, work + 0x90, mon);
}

void ov83_02241254(u8 *work, int delta)
{
    s8 selected = O83_S8(work, 0xD) + delta;
    void *mon;

    if (selected < 0) {
        selected = O83_U8(work, 0x14) - 1;
    } else if (selected >= O83_U8(work, 0x14)) {
        selected = 0;
    }
    O83_U8(work, 0xD) = selected;
    ov83_02240DB0(work);
    mon = Party_GetMonByIndex(O83_PTR(work, 0x7A4), ov83_02247768(O83_U8(work, 0x14), O83_U8(work, 0xD)));
    ov83_0223FF44(work, work + 0x90, mon);
}
