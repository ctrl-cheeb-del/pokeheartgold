#include "ov70_wave34_menu_private.h"

int ov70_02241808(Ov70Transfer *work) {
    Heap_Free(*(void **)((u8 *)work + 0x11f0));
    Heap_Free(*(void **)((u8 *)work + 0x130));
    ov70_02238E58(work);
    return 1;
}

PlayerProfile *ov70_0224182C(Ov70Transfer *work) {
    PlayerProfile *profile = PlayerProfile_New(0x3d);
    PlayerProfile_Init(profile);
    Save_Profile_PlayerName_Set(profile, (u16 *)((u8 *)work + 0x10c));
    PlayerProfile_SetVersion(profile, *((u8 *)work + 0x122));
    PlayerProfile_SetLanguage(profile, *((u8 *)work + 0x123));
    return profile;
}

void *ov70_02241868(Ov70Transfer *work, int kind) {
    if (kind == 9) {
        return (u8 *)work + 0x260 + work->box * 0x124;
    }
    if (kind == 10) {
        return (u8 *)work + 0x13c;
    }
    if (kind == 8) {
        return (u8 *)work + 0x13c;
    }
    GF_AssertFail();
    return NULL;
}

void ov70_022418A4(Ov70Transfer *work) {
    int kind = *(u32 *)((u8 *)work + 0x24);
    void *dest = ov70_02241868(work, kind);
    if (*(u32 *)((u8 *)work + 0x134) == 0x12) {
        CopyPokemonToPokemon(dest, Party_GetMonByIndex(*(void **)(*(u8 **)work + 8), *(u32 *)((u8 *)work + 0x138)));
    } else {
        int box = 0;
        int slot = 0;
        PCStorage_DeleteBoxMonByIndexPair(*(void **)(*(u8 **)work + 0xc), *(u32 *)((u8 *)work + 0x134), *(u32 *)((u8 *)work + 0x138));
        PCStorage_FindFirstEmptySlot(*(void **)(*(u8 **)work + 0xc), &box, &slot);
        PCStorage_PlaceMonInBoxFirstEmptySlot(*(void **)(*(u8 **)work + 0xc), box, Mon_GetBoxMon(dest));
    }
}
