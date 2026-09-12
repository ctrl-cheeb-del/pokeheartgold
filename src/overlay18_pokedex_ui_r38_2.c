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

void ov18_021F3A64(PokedexAppData *pokedexApp, u32 value, int index) {
    if (value == 0) {
        ov18_021F118C(pokedexApp, index, 0x3A);
        ov18_021F118C(pokedexApp, index + 1, 0x35);
    } else if (value == 0x98) {
        ov18_021F118C(pokedexApp, index, 0x38);
        ov18_021F118C(pokedexApp, index + 1, 0x37);
    } else {
        ov18_021F118C(pokedexApp, index, 0x38);
        ov18_021F118C(pokedexApp, index + 1, 0x35);
    }
}

u32 ov18_021F3AB0(PokedexAppData *pokedexApp, int index) {
    s16 x;
    s16 y;
    ManagedSprite *sprite = *(ManagedSprite **)((u8 *)pokedexApp + 0x670 + index * 4);

    ManagedSprite_GetPositionXY(sprite, &x, &y);
    return x - 0x34;
}
