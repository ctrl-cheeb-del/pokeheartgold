#include "overlay18_pokedex_status_sprites_r11_private.h"

void ov18_021F2C10(PokedexAppData *pokedexApp, int sprite, int mode) {
    if (pokedexApp->unk_1859 == 0) {
        ov18_021F118C(pokedexApp, sprite, 7);
    } else {
        ov18_021F118C(pokedexApp, sprite, 5);
    }
    if (pokedexApp->unk_1859 == ov18_021F8950(pokedexApp, mode)) {
        ov18_021F118C(pokedexApp, sprite + 1, 10);
    } else {
        ov18_021F118C(pokedexApp, sprite + 1, 8);
    }
}

void ov18_021F2C5C(PokedexAppData *pokedexApp, int sprite, BOOL mode) {
    ov18_021F118C(pokedexApp, sprite, ov18_021F2C74(pokedexApp, mode));
}

int ov18_021F2C74(PokedexAppData *pokedexApp, BOOL mode) {
    u32 value = ov18_021F891C(pokedexApp, mode);
    u32 i = 0;

    do {
        if (value <= ov18_021FA398[i]) {
            break;
        }
        i++;
    } while (i < 12);
    return i + 11;
}

u32 ov18_021F2C98(PokedexAppData *pokedexApp, int index) {
    ManagedSprite *sprite = *(ManagedSprite **)((u8 *)pokedexApp + 0x670 + index * sizeof(ManagedSprite *));

    return (ov18_021FA310 + 1)[ManagedSprite_GetActiveAnim(sprite)];
}
