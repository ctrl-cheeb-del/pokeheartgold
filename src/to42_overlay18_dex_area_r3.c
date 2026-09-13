#include "to42_overlay18_dex_area_r3_private.h"

void ov18_021F0940(PokedexAppData *pokedexApp) {
    u32 i;
    int idx;

    for (i = 0; i < 6; i++) {
        FillWindowPixelBuffer(&pokedexApp->windows[i + 10], 0);
        idx = pokedexApp->unk_18C5 + i - 2;
        if (idx >= 0 && idx < pokedexApp->numSeenForms) {
            ov18_021EE3AC(pokedexApp, pokedexApp->msgData, i + 10, ov18_021F09D8(pokedexApp, idx), 0, 0, 4, 0xF0C00, 0);
        }
        CopyWindowPixelsToVram_TextMode(&pokedexApp->windows[i + 10]);
        sub_020196E8(pokedexApp->unk_0008, i + 0x11, (s8)GetWindowX(&pokedexApp->windows[i + 10]), (s8)GetWindowY(&pokedexApp->windows[i + 10]));
    }
}

u32 ov18_021F09D8(PokedexAppData *pokedexApp, int idx) {
    String *str;

    switch (pokedexApp->curSpecies) {
    case 0xC9:
        return 0x79;
    case 0x1A6:
    case 0x1A7:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0x74;
    case 0x19C:
    case 0x19D:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0x76;
    case 0x182:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0x91;
    case 0x1EC:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0x95;
    case 0x1E7:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0x97;
    case 0x1DF:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0x99;
    case 0x15F:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0xA0;
    case 0x1A5:
        return (pokedexApp->seenForms[idx] ^ 0x80) + 0xA4;
    case 0xAC:
        if ((pokedexApp->seenForms[idx] ^ 0x80) == 0) {
            return 0x72;
        }
        if ((pokedexApp->seenForms[idx] ^ 0x80) == 1) {
            return 0x73;
        }
        return 0xA6;
    default:
        if (pokedexApp->seenForms[idx] == 1) {
            return 0x72;
        }
        if (pokedexApp->seenForms[idx] == 2) {
            return 0x73;
        }
        str = ov18_021E590C(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
        BufferString(pokedexApp->msgFormat, 0, str, 2, 1, 2);
        String_Delete(str);
        return 0x9F;
    }
}

void ov18_021F0B70(PokedexAppData *pokedexApp, int a1) {
    u32 i;
    s8 x;
    s8 y;

    for (i = 0; i < 6; i++) {
        sub_02019B1C(pokedexApp->unk_0008, i + 0x11, &x, &y);
        if (y == -2 || y == 0x10) {
            break;
        }
    }
    FillWindowPixelBuffer(&pokedexApp->windows[i + 10], 0);
    if (a1 < 0) {
        sub_020196E8(pokedexApp->unk_0008, i + 0x11, 8, 0x10);
        if (pokedexApp->unk_18C5 + 2 < pokedexApp->numSeenForms) {
            ov18_021EE3AC(pokedexApp, pokedexApp->msgData, i + 10, ov18_021F09D8(pokedexApp, pokedexApp->unk_18C5 + 2), 0, 0, 4, 0xF0C00, 0);
        }
    } else {
        sub_020196E8(pokedexApp->unk_0008, i + 0x11, 8, -2);
        if (pokedexApp->unk_18C5 - 2 >= 0) {
            ov18_021EE3AC(pokedexApp, pokedexApp->msgData, i + 10, ov18_021F09D8(pokedexApp, pokedexApp->unk_18C5 - 2), 0, 0, 4, 0xF0C00, 0);
        }
    }
    CopyWindowPixelsToVram_TextMode(&pokedexApp->windows[i + 10]);
}

void ov18_021F0C50(PokedexAppData *pokedexApp) {
    String *str;

    FillWindowPixelBuffer(&pokedexApp->windows[0], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[4], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[1], 0);
    ov18_021F9648(&pokedexApp->windows[0], pokedexApp->msgData, 0xAA, 0, 0, 4, 0x20100, 0);
    if (pokedexApp->numSeenForms != 1) {
        ov18_021F9648(&pokedexApp->windows[4], pokedexApp->msgData, 0xA8, 0, 0, 4, 0xF0C00, 0);
    }
    str = ov18_021E590C(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
    BufferString(pokedexApp->msgFormat, 0, str, 2, 1, 2);
    String_Delete(str);
    ov18_021EE3AC(pokedexApp, pokedexApp->msgData, 1, 0xA7, 0x48, 0, 0, 0x20100, 1);
    ScheduleWindowCopyToVram(&pokedexApp->windows[0]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[4]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[1]);
}

void ov18_021F0D2C(PokedexAppData *pokedexApp) {
    FillWindowPixelBuffer(&pokedexApp->windows[2], 0);
    ov18_021EE3AC(pokedexApp, pokedexApp->msgData, 2, ov18_021F09D8(pokedexApp, pokedexApp->unk_18C5), 0x3C, 0, 0, 0x20100, 2);
    ScheduleWindowCopyToVram(&pokedexApp->windows[2]);
}

void ov18_021F0D7C(PokedexAppData *pokedexApp) {
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[0]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[1]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[2]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[4]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[10]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[11]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[12]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[13]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[14]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[15]);
}

void ov18_021F0DD0(PokedexAppData *pokedexApp) {
    String *str;

    ov18_021F0D7C(pokedexApp);
    FillWindowPixelBuffer(&pokedexApp->windows[0], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[3], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[5], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[8], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[9], 0);
    ov18_021F9648(&pokedexApp->windows[0], pokedexApp->msgData, 0xAA, 0, 0, 4, 0x20100, 0);
    str = ov18_021E590C(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
    BufferString(pokedexApp->msgFormat, 0, str, 2, 1, 2);
    String_Delete(str);
    ov18_021EE3AC(pokedexApp, pokedexApp->msgData, 3, 0xA9, 0x48, 0, 0, 0x20100, 2);
    ov18_021F9648(&pokedexApp->windows[5], pokedexApp->msgData, 0xAA, 0x18, 0, 0, 0x50900, 2);
    ov18_021F9648(&pokedexApp->windows[8], pokedexApp->msgData, 0xAB, 0x30, 4, 4, 0xF0C00, 2);
    ov18_021F9648(&pokedexApp->windows[9], pokedexApp->msgData, 0xAC, 0x30, 4, 4, 0xF0C00, 2);
    ScheduleWindowCopyToVram(&pokedexApp->windows[0]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[3]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[5]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[8]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[9]);
    ov18_021F0F68(pokedexApp, 6, pokedexApp->unk_18C5);
    ov18_021F0F68(pokedexApp, 7, pokedexApp->unk_18C6);
}
