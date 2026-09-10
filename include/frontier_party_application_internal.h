#ifndef POKEHEARTGOLD_FRONTIER_PARTY_APPLICATION_INTERNAL_H
#define POKEHEARTGOLD_FRONTIER_PARTY_APPLICATION_INTERNAL_H
#include "global.h"

#include "bag.h"
#include "field_system.h"
#include "heap.h"
#include "party.h"
#include "party_menu.h"
#include "player_data.h"
#include "pokedex_util.h"
#include "save_special_ribbons.h"
#include "save_trainer_card.h"
#include "task.h"
#include "unk_02088288.h"

typedef struct SummaryWaitEnv {
    u32 result;
    u32 state;
    u8 context;
    u8 summaryMode;
    u8 minMons;
    u8 maxMons;
    u8 maxLevel;
    u8 partySlot;
    u8 selectedOrder[6];
    void **runningApp;
} SummaryWaitEnv;

extern const u8 _020FE4B0[];

u32 sub_02066EDC(SummaryWaitEnv *env, FieldSystem *fieldSystem, enum HeapID heapId);
u32 sub_02066F90(SummaryWaitEnv *env, FieldSystem *fieldSystem);
u32 sub_02066FEC(SummaryWaitEnv *env, FieldSystem *fieldSystem, enum HeapID heapId);
void sub_0206759C(SaveData *saveData, int days);

#endif
