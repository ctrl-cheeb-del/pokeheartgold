#include "to45_overlay18_r20_private.h"

void ov18_021F47C0(u32 value, u32 *flags) {
    if (value == 0x6A) {
        *flags |= 1;
    } else if (value == 0x78 || (value - 0xED) <= 2) {
        *flags |= 2;
    } else if (value == 0x7B || value == 0xB0) {
        *flags |= 4;
    }
}

void ov18_021F47F8(PokedexAppData *pokedexApp, u32 flags, int index) {
    if (flags & 1) {
        ov18_021F1294(pokedexApp, index, 0x94, 0x4C, 2);
        ov18_021F118C(pokedexApp, index, 0);
        ov18_021F11C0(pokedexApp, index, 1);
        index++;
    }
    if (flags & 2) {
        ov18_021F1294(pokedexApp, index, 0xEC, 0x4C, 2);
        ov18_021F118C(pokedexApp, index, 0);
        ov18_021F11C0(pokedexApp, index, 1);
        index++;
    }
    if (flags & 4) {
        ov18_021F1294(pokedexApp, index, 0xE4, 0x5C, 2);
        ov18_021F118C(pokedexApp, index, 0);
        ov18_021F11C0(pokedexApp, index, 1);
        ov18_021F1294(pokedexApp, index + 1, 0xDC, 0x7C, 2);
        ov18_021F118C(pokedexApp, index + 1, 0);
        ov18_021F11C0(pokedexApp, index + 1, 1);
    }
}

void ov18_021F48AC(PokedexAppData *pokedexApp, u32 oldFlags, u32 newFlags, int index, u32 palette) {
    if (oldFlags & 1) {
        if (newFlags & 1) {
            ov18_021F11C0(pokedexApp, index, 0);
        } else {
            ov18_021F11C0(pokedexApp, index, 1);
            ManagedSprite_SetPaletteOverride(((void **)((u8 *)pokedexApp + 0x670))[index], palette);
        }
        index++;
    }
    if (oldFlags & 2) {
        if (newFlags & 2) {
            ov18_021F11C0(pokedexApp, index, 0);
        } else {
            ov18_021F11C0(pokedexApp, index, 1);
            ManagedSprite_SetPaletteOverride(((void **)((u8 *)pokedexApp + 0x670))[index], palette);
        }
        index++;
    }
    if (oldFlags & 4) {
        if (newFlags & 4) {
            ov18_021F11C0(pokedexApp, index, 0);
            ov18_021F11C0(pokedexApp, index + 1, 0);
        } else {
            ov18_021F11C0(pokedexApp, index, 1);
            ov18_021F11C0(pokedexApp, index + 1, 1);
            ManagedSprite_SetPaletteOverride(((void **)((u8 *)pokedexApp + 0x670))[index], palette);
            ManagedSprite_SetPaletteOverride(((void **)((u8 *)pokedexApp + 0x674))[index], palette);
        }
    }
}

BOOL ov18_021F4974(PokedexAppData *pokedexApp, u32 start, s32 x, s32 y) {
    u32 i;
    u32 end;
    s16 pos[2];
    u8 *walker;

    i = start;
    end = start + 4;
    if (i < end) {
        walker = (u8 *)pokedexApp + i * 4;
        do {
            if (ManagedSprite_GetDrawFlag(PTR_AT(walker, 0x670)) != 0) {
                ov18_021F12C8(pokedexApp, i, &pos[1], &pos[0], 2);
                if (x >= pos[1] - (s32)((u32)ov18_021FA3B0[0] >> 1) && x < pos[1] + (s32)((u32)ov18_021FA3B0[0] >> 1)
                    && y >= pos[0] - (s32)((u32)ov18_021FA3B0[1] >> 1) && y < pos[0] + (s32)((u32)ov18_021FA3B0[1] >> 1)) {
                    return TRUE;
                }
            }
            i++;
            walker += 4;
        } while (i < end);
    }
    return FALSE;
}
