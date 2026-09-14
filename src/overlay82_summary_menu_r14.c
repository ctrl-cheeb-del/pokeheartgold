#include "global.h"

#include "bg_window.h"
#include "heap.h"
#include "msgdata.h"
#include "party.h"
#include "pokedex_util.h"
#include "text.h"
#include "unk_02088288.h"

typedef struct Ov82Work {
    u8 pad000[0x9C];
    Options *options;
    SaveData *saveData;
    PokemonSummaryArgs *unk0A4;
    u8 pad0A8[0x16C];
    Party *party;
    void *unk218;
} Ov82Work;

extern const u8 _0223FE20[];

extern u8 ov80_02237920(u8 index);
extern u32 sub_02030BD0(u8 index, void *party);
extern u8 ov82_0223F6C4(u8 index);
extern void ov82_0223F10C(Ov82Work *work, Window *window, u32 value, u32 x, u32 y);

void ov82_0223F134(Ov82Work *work, Window *window);
void ov82_0223F1AC(Ov82Work *work, Window *window, u32 x, u32 y, u8 fg, u8 shadow, u8 bg, u8 font);
void ov82_0223F224(Ov82Work *work);

void ov82_0223F134(Ov82Work *work, Window *window) {
    int row;
    int base;
    int y;

    row = 0;
    base = 0;
    y = 4;
    do {
        int column = 0;
        int x = 0x12;
        do {
            int index = column + base;
            u32 kind = ov80_02237920((u8)index);
            if (kind != 0xFE && kind != 9) {
                u8 value = (u8)(sub_02030BD0(ov82_0223F6C4((u8)index), work->unk218) + 1);
                if (value > 10) {
                    value = 10;
                }
                ov82_0223F10C(work, window, value, x, y);
            }
            column++;
            x += 0x40;
        } while (column < 4);
        base += 4;
        y += 0x24;
        row++;
    } while (row < 5);
}

void ov82_0223F1AC(Ov82Work *work, Window *window, u32 x, u32 y, u8 fg, u8 shadow, u8 bg, u8 font) {
    MsgData *msgData;
    String *string;

    FillWindowPixelBuffer(window, bg);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 0x1B9, HEAP_ID_105);
    string = NewString_ReadMsgData(msgData, 0x25);
    FillWindowPixelBuffer(window, 0xF);
    AddTextPrinterParameterizedWithColor(window, font, string, x, y, 0, MAKE_TEXT_COLOR(fg, shadow, bg), NULL);
    String_Delete(string);
    DestroyMsgData(msgData);
    CopyWindowToVram(window);
}

void ov82_0223F224(Ov82Work *work) {
    work->unk0A4 = Heap_Alloc(HEAP_ID_105, sizeof(PokemonSummaryArgs));
    memset(work->unk0A4, 0, sizeof(PokemonSummaryArgs));
    work->unk0A4->party = work->party;
    work->unk0A4->unk11 = 1;
    work->unk0A4->options = work->options;
    work->unk0A4->unk12 = 1;
    work->unk0A4->partyCount = Party_GetCount(work->party);
    work->unk0A4->partySlot = 0;
    work->unk0A4->moveToLearn = 0;
    work->unk0A4->natDexEnabled = SaveArray_IsNatDexEnabled(work->saveData);
    work->unk0A4->unk2C = sub_02088288(work->saveData);
    work->unk0A4->ribbons = Save_SpecialRibbons_Get(work->saveData);
    work->unk0A4->isFlag982Set = 0;
    sub_02089D40(work->unk0A4, _0223FE20);
    sub_0208AD34(work->unk0A4, Save_PlayerData_GetProfile(work->saveData));
}
