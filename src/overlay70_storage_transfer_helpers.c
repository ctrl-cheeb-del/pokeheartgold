#include "overlay70_storage_transfer_helpers_private.h"

int ov70_022408FC(Ov70Work *work) {
    if (Save_WriteFileAsync(work->unk00->unk20) == 2) {
        ov70_02238E50(work, 1, 0);
        ov70_02238F80(work);
        ov70_02244FA4(work, work->ptrBA0, work->unk28, 1, 0xf0f);
        ov70_02238D84(work, 0x25, 0x1c);
    }
    return 3;
}

int ov70_02240948(Ov70Work *work) {
    ov70_02238F80(work);
    sub_0203A914();
    if (work->unk11FC == 1) {
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x3d);
    } else {
        BeginNormalPaletteFade(3, 0, 0, 0, 6, 1, 0x3d);
    }
    work->state2c = 0;
    return 4;
}

int ov70_022409A0(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        work->state2c = *(u32 *)((u8 *)work + 0x30);
    }
    return 3;
}

void ov70_022409C0(Ov70Work *work, int update) {
    void *mon;

    if (work->unk120 != 0x12) {
        mon = AllocMonZeroed(0x3d);
        CopyBoxPokemonToPokemon(PCStorage_GetMonByIndexPair(work->unk00->unk0c, work->unk120, work->unk122), mon);
        sub_0202DB70(work->unk00->unk00, mon, work->unk120);
        PCStorage_DeleteBoxMonByIndexPair(work->unk00->unk0c, work->unk120, work->unk122);
        Heap_Free(mon);
    } else {
        mon = Party_GetMonByIndex(work->unk00->unk08, work->unk122);
        Pokemon_RemoveCapsule(mon);
        sub_0202DB70(work->unk00->unk00, mon, work->unk120);
        Party_RemoveMon(work->unk00->unk08, work->unk122);
        if (!Party_HasMon(work->unk00->unk08, 0x1b9)) {
            Chatot_Invalidate(Save_Chatot_Get(work->unk00->unk20));
        }
    }
    if (update) {
        sub_0202DB5C(work->unk00->unk00, 1);
    }
}

void ov70_02240A7C(Ov70Work *work, void *mon, int box, int update) {
    int slot;
    int count;
    u8 value;
    void *vars;

    GetMonData(mon, 6, NULL);
    UpdatePokedexWithReceivedSpecies(work->unk00->unk20, mon);
    box = 0x12;
    if (Party_GetCount(work->unk00->unk08) == 6) {
        box = 0;
    }
    if (update) {
        value = 0x46;
        if (GetMonData(mon, 5, NULL) == 0x1ed) {
            if (GetMonData(mon, 0x6e, NULL) != 0 || (GetMonData(mon, 0x99, NULL) == 0x56 && GetMonData(mon, 0x6e, NULL) == 0)) {
                vars = Save_VarsFlags_Get(work->unk00->unk20);
                if (Save_VarsFlags_GetVar404C(vars) == 0) {
                    Save_VarsFlags_SetVar404C(vars, 1);
                }
            }
        }
        SetMonData(mon, 9, &value);
        SetMonData(mon, 0x6f, NULL);
        ov70_02240CA0(work->unk00->unk00, 0);
    }
    if (box == 0x12) {
        Party_AddMon(work->unk00->unk08, mon);
        count = Party_GetCount(work->unk00->unk08);
        work->unk134 = 0x12;
        work->unk138 = count - 1;
    } else {
        slot = 0;
        PCStorage_FindFirstEmptySlot(work->unk00->unk0c, &box, &slot);
        PCStorage_PlaceMonInBoxFirstEmptySlot(work->unk00->unk0c, box, Mon_GetBoxMon(mon));
        work->unk134 = box;
        work->unk138 = slot;
    }
    sub_0202DB5C(work->unk00->unk00, 0);
}

void ov70_02240B9C(Ov70Work *work, void *mon, int box) {
    int slot;
    int count;
    u8 value;
    void *vars;

    UpdatePokedexWithReceivedSpecies(work->unk00->unk20, mon);
    box = 0x12;
    if (Party_GetCount(work->unk00->unk08) == 6) {
        box = 0;
    }
    if (GetMonData(mon, 5, NULL) == 0x1ed) {
        if (GetMonData(mon, 0x6e, NULL) != 0 || (GetMonData(mon, 0x99, NULL) == 0x56 && GetMonData(mon, 0x6e, NULL) == 0)) {
            vars = Save_VarsFlags_Get(work->unk00->unk20);
            if (Save_VarsFlags_GetVar404C(vars) == 0) {
                Save_VarsFlags_SetVar404C(vars, 1);
            }
        }
    }
    value = 0x46;
    SetMonData(mon, 9, &value);
    SetMonData(mon, 0x6f, NULL);
    if (box == 0x12) {
        Party_AddMon(work->unk00->unk08, mon);
        count = Party_GetCount(work->unk00->unk08);
        work->unk134 = 0x12;
        work->unk138 = count - 1;
    } else {
        slot = 0;
        PCStorage_FindFirstEmptySlot(work->unk00->unk0c, &box, &slot);
        PCStorage_PlaceMonInBoxFirstEmptySlot(work->unk00->unk0c, box, Mon_GetBoxMon(mon));
        work->unk134 = box;
        work->unk138 = slot;
    }
    ov70_02240CA0(work->unk00->unk00, 1);
}

void ov70_02240CA0(void *saveData, int which) {
    u32 date[4];
    u32 extra[3];
    u32 value;

    ov00_021ECB94(date, extra);
    value = (date[0] << 24) | ((date[1] << 24) >> 8) | ((date[2] << 24) >> 16) | date[3];
    if (which == 1) {
        sub_0202DB98(saveData, value);
    } else {
        sub_0202DB88(saveData, value);
    }
}

void ov70_02240CE4(void *history, void *mon) {
    u8 *p = mon;
    sub_02039FB8(history, p[0x11e], p[0x11f], p[0x123]);
}

int ov70_02240D00(Ov70Work *work, void *mon) {
    if (ov70_0223E76C(mon) && Party_GetCount(work->unk00->unk08) == 6) {
        return 2;
    }
    if (work->unk11F8 == 0x21c && Party_GetCount(work->unk00->unk08) == 6) {
        return 1;
    }
    return 0;
}
