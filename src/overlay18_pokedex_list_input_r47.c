#include "overlay18_pokedex_list_input_r47_private.h"

u32 ov18_021F7974(PokedexAppData *pokedexApp, int mode) {
    u32 x;
    u32 y;
    u32 input;

    if (System_GetTouchNewCoords(&x, &y) == TRUE) {
        int hit = TouchscreenHitbox_FindRectAtTouchNew(ov18_021FB8A4);
        if (hit == -1) {
            return -1;
        }

        input = ov18_021FB84C[hit];
        if (input == 0) {
            u8 selection;

            x -= 27;
            y -= 4;
            selection = x / 40 + 5 * (y / 40);
            if (selection == pokedexApp->unk_185A) {
                if (pokedexApp->unk_185A == 0 && pokedexApp->unk_1859 == 0) {
                    PlaySE(0x8E9);
                    return 2;
                }
                return 4;
            }
            pokedexApp->unk_185A = selection;
            PlaySE(0x8E9);
        } else if (input == 2) {
            PlaySE(0x8E9);
        } else if (input == 5) {
            PlaySE(0x940);
        }
        return input;
    }

    if (gSystem.newAndRepeatedKeys & 0x40) {
        if (pokedexApp->unk_185A < 5) {
            return 10;
        }
        pokedexApp->unk_185A -= 5;
        PlaySE(0x8E8);
        return 0;
    }
    if (gSystem.newAndRepeatedKeys & 0x80) {
        if (pokedexApp->unk_185A >= 10 && pokedexApp->unk_185A < 15) {
            return 12;
        }
        pokedexApp->unk_185A += 5;
        PlaySE(0x8E8);
        return 0;
    }
    if (gSystem.newAndRepeatedKeys & 0x20) {
        if (pokedexApp->unk_185A != 0) {
            pokedexApp->unk_185A--;
            PlaySE(0x8E8);
            return 0;
        }
        if (pokedexApp->unk_1859 != 0) {
            pokedexApp->unk_185A = 14;
            return 9;
        }
        return -1;
    }
    if (gSystem.newAndRepeatedKeys & 0x10) {
        int selection = pokedexApp->unk_185A + 1;

        if (selection != 15) {
            pokedexApp->unk_185A = selection;
            PlaySE(0x8E8);
            return 0;
        }
        if (pokedexApp->unk_1859 + 1 <= ov18_021F8950(pokedexApp, mode)) {
            pokedexApp->unk_185A = 0;
            return 11;
        }
        return -1;
    }
    if (gSystem.newKeys & 1) {
        return 4;
    }
    if (gSystem.newKeys & 2) {
        PlaySE(0x940);
        return 6;
    }
    if (gSystem.newKeys & 0x400) {
        return 3;
    }
    if (gSystem.newKeys & 0x800) {
        PlaySE(0x8E9);
        return 2;
    }
    if (gSystem.newAndRepeatedKeys & 0x200) {
        return 9;
    }
    if (gSystem.newAndRepeatedKeys & 0x100) {
        return 11;
    }
    if (gSystem.newKeys & 4) {
        return 8;
    }
    return -1;
}

void ov18_021F7B74(PokedexAppData *work) {
    if (work->unk_1864 != NULL) {
        GridInputHandler_Free(work->unk_1864);
        work->unk_1864 = NULL;
    }
}
