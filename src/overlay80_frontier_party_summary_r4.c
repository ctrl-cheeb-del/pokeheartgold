#include "global.h"

#include "frontier/frontier.h"

#include "bag.h"
#include "error_handling.h"
#include "field_system.h"
#include "heap.h"
#include "mail.h"
#include "overlay80_frontier_party_summary_r4_private.h"
#include "party.h"
#include "party_menu.h"
#include "player_data.h"
#include "pokedex_util.h"
#include "save.h"
#include "save_special_ribbons.h"
#include "unk_02088288.h"

typedef struct UnkStruct_ov80_0223DD50 {
    UnkStruct_ov80_02235FC8 *unk_00;
    u8 filler_04[0xC];
} UnkStruct_ov80_0223DD50;

extern BOOL sub_02096A34(UnkStruct_ov80_02235FC8 *parent);
extern BOOL sub_02096AAC(UnkStruct_ov80_02235FC8 *parent, u16 a);
extern BOOL sub_02096AF4(UnkStruct_ov80_02235FC8 *parent, u16 a, u16 b);
extern BOOL sub_02096BF8(UnkStruct_ov80_02235FC8 *parent, u16 a);
extern BOOL sub_02096C40(UnkStruct_ov80_02235FC8 *parent, u16 a);
extern const u8 ov80_0223C040[];

void ov80_0223608C(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId);
void ov80_022362B8(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId);
void ov80_02236330(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId);
void ov80_0223641C(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId);

UnkStruct_ov80_0223DD50 ov80_0223DD50;

void ov80_02235FC8(SaveData *saveData) {
    ov80_0223DD50.unk_00 = Heap_Alloc(HEAP_ID_FIELD2, sizeof(UnkStruct_ov80_02235FC8));
    MI_CpuFill8(ov80_0223DD50.unk_00, 0, sizeof(UnkStruct_ov80_02235FC8));
    ov80_0223DD50.unk_00->saveData = saveData;
}

void ov80_02235FEC(void *a0) {
    if (a0 != NULL) {
        Heap_Free(a0);
    }
}

BOOL ov80_02235FF8(UnkStruct_ov80_02235FC8 *parent, int sel, u16 a, u16 b) {
    switch (sel) {
    case 0:
        return sub_02096A34(parent);
    case 1:
        return sub_02096AAC(parent, a);
    case 2:
        return sub_02096AF4(parent, a, b);
    case 3:
        break;
    case 4:
        return sub_02096BF8(parent, a);
    case 5:
        return sub_02096C40(parent, a);
    }
}

void ov80_02236040(void *a0, UnkStruct_ov80_02235FC8 *parent, u32 sel) {
    FieldSystem *fieldSystem = parent->fieldSystem;
    switch (sel) {
    case 0:
        ov80_0223608C(a0, parent, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 1:
        ov80_022362B8(a0, parent, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 2:
        ov80_02236330(a0, parent, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 3:
        ov80_0223641C(a0, parent, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 4:
        break;
    }
}

void ov80_0223608C(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId) {
    u8 i;

    parent->partyMenuArgs = Heap_Alloc(HEAP_ID_FIELD2, sizeof(PartyMenuArgs));
    MI_CpuClearFast(parent->partyMenuArgs, sizeof(PartyMenuArgs));
    parent->partyMenuArgs->party = SaveArray_Party_Get(parent->saveData);
    parent->partyMenuArgs->bag = Save_Bag_Get(parent->saveData);
    parent->partyMenuArgs->mailbox = Save_Mailbox_Get(parent->saveData);
    parent->partyMenuArgs->options = Save_PlayerData_GetOptionsAddr(parent->saveData);
    parent->partyMenuArgs->unk_25 = 0;
    if (parent->unk_A0 == 1) {
        parent->partyMenuArgs->context = PARTY_MENU_CONTEXT_17;
    } else if (parent->unk_A0 == 5) {
        parent->partyMenuArgs->context = PARTY_MENU_CONTEXT_BATTLE_HALL;
    } else if (parent->unk_A0 == 4) {
        parent->partyMenuArgs->context = PARTY_MENU_CONTEXT_23;
    } else if (parent->unk_A0 == 6) {
        parent->partyMenuArgs->context = PARTY_MENU_CONTEXT_23;
    } else {
        GF_AssertFail();
    }
    parent->partyMenuArgs->fieldSystem = fieldSystem;
    parent->partyMenuArgs->partySlot = parent->unk_9F;
    for (i = 0; i < 2; i++) {
        parent->partyMenuArgs->selectedOrder[i] = parent->unk_A1[i];
    }
    if (parent->unk_A0 == 1) {
        parent->partyMenuArgs->minMonsToSelect = 2;
        parent->partyMenuArgs->maxMonsToSelect = 2;
        parent->partyMenuArgs->maxLevel = 100;
    } else if (parent->unk_A0 == 5) {
        parent->partyMenuArgs->minMonsToSelect = 1;
        parent->partyMenuArgs->maxMonsToSelect = 1;
        parent->partyMenuArgs->maxLevel = 30;
    } else if (parent->unk_A0 == 4) {
        parent->partyMenuArgs->minMonsToSelect = 2;
        parent->partyMenuArgs->maxMonsToSelect = 2;
        parent->partyMenuArgs->maxLevel = 100;
    } else if (parent->unk_A0 == 6) {
        parent->partyMenuArgs->minMonsToSelect = 2;
        parent->partyMenuArgs->maxMonsToSelect = 2;
        parent->partyMenuArgs->maxLevel = 100;
    } else {
        GF_AssertFail();
    }
    parent->partyMenuArgs->menuInputStatePtr = &fieldSystem->menuInputState;
    Frontier_LaunchApplication(a0, &gOverlayTemplate_PartyMenu, parent->partyMenuArgs, 0, NULL);
}

void ov80_022362B8(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId) {
    switch (parent->partyMenuArgs->partySlot) {
    case 7:
        *parent->unk_B0 = 4;
        parent->unk_9D = 4;
        break;
    case 6:
        *parent->unk_B0 = 4;
        parent->unk_9D = 4;
        break;
    default:
        MI_CpuCopy8(parent->partyMenuArgs->selectedOrder, parent->unk_A1, 2);
        parent->unk_9F = parent->partyMenuArgs->partySlot;
        Heap_Free(parent->partyMenuArgs);
        parent->partyMenuArgs = NULL;
        *parent->unk_B0 = 2;
        parent->unk_9D = 2;
        break;
    }
}

void ov80_02236330(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId) {
    parent->summaryArgs = Heap_AllocAtEnd(heapId, sizeof(PokemonSummaryArgs));
    MI_CpuFill8(parent->summaryArgs, 0, sizeof(PokemonSummaryArgs));
    parent->summaryArgs->options = Save_PlayerData_GetOptionsAddr(parent->saveData);
    parent->summaryArgs->party = SaveArray_Party_Get(parent->saveData);
    parent->summaryArgs->natDexEnabled = SaveArray_IsNatDexEnabled(parent->saveData);
    parent->summaryArgs->unk2C = sub_02088288(parent->saveData);
    parent->summaryArgs->unk11 = 1;
    parent->summaryArgs->partySlot = parent->unk_9F;
    parent->summaryArgs->partyCount = Party_GetCount(parent->summaryArgs->party);
    parent->summaryArgs->moveToLearn = 0;
    parent->summaryArgs->unk12 = 0;
    parent->summaryArgs->ribbons = Save_SpecialRibbons_Get(parent->saveData);
    parent->summaryArgs->isFlag982Set = sub_0208828C(parent->saveData);
    sub_02089D40(parent->summaryArgs, ov80_0223C040);
    sub_0208AD34(parent->summaryArgs, Save_PlayerData_GetProfile(parent->saveData));
    Frontier_LaunchApplication(a0, &gOverlayTemplate_PokemonSummary, parent->summaryArgs, 0, NULL);
}

void ov80_0223641C(void *a0, UnkStruct_ov80_02235FC8 *parent, FieldSystem *fieldSystem, enum HeapID heapId) {
    parent->unk_9F = parent->summaryArgs->partySlot;
    Heap_Free(parent->summaryArgs);
    parent->summaryArgs = NULL;
    *parent->unk_B0 = 0;
    parent->unk_9D = 0;
}

const u8 ov80_0223D4C0[20] __attribute__((aligned(4))) = {
    0x00,
    0x0A,
    0x0B,
    0x0D,
    0x0C,
    0x0F,
    0x01,
    0x03,
    0x04,
    0x02,
    0x0E,
    0x06,
    0x05,
    0x07,
    0x10,
    0x11,
    0x08,
    0xFE,
    0xFE,
    0x09,
};
