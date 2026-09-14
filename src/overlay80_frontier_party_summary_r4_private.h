#ifndef POKEHEARTGOLD_OVERLAY80_FRONTIER_PARTY_SUMMARY_R4_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY80_FRONTIER_PARTY_SUMMARY_R4_PRIVATE_H

#include "field_system.h"
#include "party_menu.h"
#include "save.h"
#include "unk_02088288.h"

typedef struct UnkStruct_ov80_02235FC8 {
    SaveData *saveData;              // 0x00
    u8 filler_04[0x94];              // 0x04
    FieldSystem *fieldSystem;        // 0x98
    u8 filler_9C[1];                 // 0x9c
    u8 unk_9D;                       // 0x9d
    u8 filler_9E[1];                 // 0x9e
    u8 unk_9F;                       // 0x9f
    u8 unk_A0;                       // 0xa0
    u8 unk_A1[2];                    // 0xa1
    u8 filler_A3[5];                 // 0xa3
    PartyMenuArgs *partyMenuArgs;    // 0xa8
    PokemonSummaryArgs *summaryArgs; // 0xac
    u16 *unk_B0;                     // 0xb0
} UnkStruct_ov80_02235FC8;           // size 0xb4

void ov80_02235FC8(SaveData *saveData);
void ov80_02235FEC(void *a0);
BOOL ov80_02235FF8(UnkStruct_ov80_02235FC8 *parent, int sel, u16 a, u16 b);
void ov80_02236040(void *a0, UnkStruct_ov80_02235FC8 *parent, u32 sel);

extern const u8 ov80_0223D4C0[20];

#endif // POKEHEARTGOLD_OVERLAY80_FRONTIER_PARTY_SUMMARY_R4_PRIVATE_H
