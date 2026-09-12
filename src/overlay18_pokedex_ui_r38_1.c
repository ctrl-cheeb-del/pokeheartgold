#include "global.h"

#include "application/pokedex/pokedex_internal.h"

#include "sprite_system.h"

void ov18_021F118C(PokedexAppData *pokedexApp, int index, int animation);
void ov18_021F11C0(PokedexAppData *pokedexApp, int index, int draw);
void ov18_021F38F0(PokedexAppData *pokedexApp, int index, u16 value);
void ov18_021F39C4(PokedexAppData *pokedexApp, int index, u16 value);
void ov18_021F3A64(PokedexAppData *pokedexApp, u32 value, int index);
u32 ov18_021F3AB0(PokedexAppData *pokedexApp, int index);
void ov18_021F3560(PokedexAppData *pokedexApp, u32 first, u32 second, int weight);
void ov18_021F3618(PokedexAppData *pokedexApp, int state);
void ov18_021F34C4(PokedexAppData *pokedexApp, int state);
void ov18_021F34EC(PokedexAppData *pokedexApp, int state);
void ov18_021F3544(PokedexAppData *pokedexApp, int draw);

#define SPRITE_AT(app, offset, index) (*(ManagedSprite **)((u8 *)(app) + (offset) + (index) * 4))

void ov18_021F3560(PokedexAppData *pokedexApp, u32 first, u32 second, int weight) {
    if (weight == FALSE) {
        ov18_021F36D4(pokedexApp, ov18_021F3AD0(pokedexApp, second), 5, TRUE);
        ov18_021F36D4(pokedexApp, ov18_021F3AD0(pokedexApp, first), 11, FALSE);
        ov18_021F38F0(pokedexApp, 6, pokedexApp->unk_1850[second].unk_0);
        ov18_021F38F0(pokedexApp, 12, pokedexApp->unk_1850[first].unk_0);
    } else {
        ov18_021F37D4(pokedexApp, ov18_021F3AD0(pokedexApp, second), 5, TRUE);
        ov18_021F37D4(pokedexApp, ov18_021F3AD0(pokedexApp, first), 11, FALSE);
        ov18_021F39C4(pokedexApp, 6, pokedexApp->unk_1850[second].unk_2);
        ov18_021F39C4(pokedexApp, 12, pokedexApp->unk_1850[first].unk_2);
    }
    ov18_021F3A64(pokedexApp, second, 1);
    ov18_021F3A64(pokedexApp, first, 3);
}

void ov18_021F3618(PokedexAppData *pokedexApp, int state) {
    switch (state) {
    case 0:
        ov18_021F34EC(pokedexApp, TRUE);
        ov18_021F3544(pokedexApp, FALSE);
        break;
    case 1:
        ov18_021F34EC(pokedexApp, FALSE);
        ov18_021F3544(pokedexApp, FALSE);
        break;
    case 2:
        ov18_021F34C4(pokedexApp, TRUE);
        ov18_021F3544(pokedexApp, TRUE);
        ov18_021F118C(pokedexApp, 5, 0x43);
        ov18_021F118C(pokedexApp, 11, 0x44);
        ov18_021F3560(pokedexApp, pokedexApp->dexSearchCriteria[4], pokedexApp->dexSearchCriteria[5], FALSE);
        break;
    case 3:
        ov18_021F34C4(pokedexApp, TRUE);
        ov18_021F3544(pokedexApp, TRUE);
        ov18_021F118C(pokedexApp, 5, 0x29);
        ov18_021F118C(pokedexApp, 11, 0x2A);
        ov18_021F3560(pokedexApp, pokedexApp->dexSearchCriteria[6], pokedexApp->dexSearchCriteria[7], TRUE);
        break;
    default:
        ov18_021F34C4(pokedexApp, TRUE);
        ov18_021F3544(pokedexApp, FALSE);
        break;
    }
}

void ov18_021F36D4(PokedexAppData *pokedexApp, int xPos, int index, int moveCursor) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x670, index), &x, &y);
    if (xPos == 0) {
        xPos = x;
    } else if ((u32)xPos < 0x34) {
        xPos = 0x34;
    } else if ((u32)xPos > 0xCC) {
        xPos = 0xCC;
    }

    ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x670, index), &x, &y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x670, index), xPos, y);
    ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x674, index), &x, &y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x674, index), xPos - 0x14, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x678, index), xPos - 0xC, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x67C, index), xPos + 4, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x680, index), xPos + 0xC, y);

    if (moveCursor == TRUE) {
        ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x670, 0), &x, &y);
        ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x670, 0), xPos, y);
    }
}

void ov18_021F37D4(PokedexAppData *pokedexApp, int xPos, int index, int moveCursor) {
    s16 x;
    s16 y;

    ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x670, index), &x, &y);
    if (xPos == 0) {
        xPos = x;
    } else if ((u32)xPos < 0x34) {
        xPos = 0x34;
    } else if ((u32)xPos > 0xCC) {
        xPos = 0xCC;
    }

    ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x670, index), &x, &y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x670, index), xPos, y);
    ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x674, index), &x, &y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x674, index), xPos - 0x14, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x678, index), xPos - 0xC, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x67C, index), xPos - 4, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x680, index), xPos + 4, y);
    ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x684, index), xPos + 0x14, y);

    if (moveCursor == TRUE) {
        ManagedSprite_GetPositionXY(SPRITE_AT(pokedexApp, 0x670, 0), &x, &y);
        ManagedSprite_SetPositionXY(SPRITE_AT(pokedexApp, 0x670, 0), xPos, y);
    }
}

void ov18_021F38F0(PokedexAppData *pokedexApp, int index, u16 value) {
    u32 display;
    u32 integral;
    u32 fractional;

    if (value == 999) {
        display = 1188;
    } else {
        display = (((u32)10000 * value) / 254 + 5) / 10;
    }

    integral = display / 12;
    fractional = display % 12;
    if (integral >= 10) {
        ov18_021F118C(pokedexApp, index, integral / 10 + 0x2B);
        ov18_021F11C0(pokedexApp, index, TRUE);
    } else {
        ov18_021F11C0(pokedexApp, index, FALSE);
    }
    ov18_021F118C(pokedexApp, index + 1, integral % 10 + 0x2B);
    ov18_021F11C0(pokedexApp, index + 1, TRUE);
    ov18_021F118C(pokedexApp, index + 2, fractional / 10 + 0x2B);
    ov18_021F11C0(pokedexApp, index + 2, TRUE);
    ov18_021F118C(pokedexApp, index + 3, fractional % 10 + 0x2B);
    ov18_021F11C0(pokedexApp, index + 3, TRUE);
    ov18_021F11C0(pokedexApp, index + 4, FALSE);
}
