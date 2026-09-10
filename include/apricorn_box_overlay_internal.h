#ifndef OV58_PRIVATE_H
#define OV58_PRIVATE_H

#include "global.h"

#include "constants/pokemon.h"

#include "apricorn_internal.h"
#include "bag.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "mail.h"
#include "menu_input_state.h"
#include "overlay_58.h"
#include "overlay_manager.h"
#include "party.h"
#include "party_menu.h"
#include "player_data.h"
#include "pokemon_mood.h"
#include "save.h"
#include "screen_fade.h"
#include "system.h"
#include "unk_02031B0C.h"

// No tracked definition found for the Apricorn Box application work block.
// Derived from OverlayManager_CreateAndGetData(man, 0x20, ...) + MI_CpuFill8(.., 0x20).
typedef struct ApricornBoxApp {
    /* 0x00 */ enum HeapID heapId;
    /* 0x04 */ ApricornBoxArgs *args;
    /* 0x08 */ OverlayManager *child;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ PartyMenuArgs *partyMenuArgs;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u8 unk_1A[2];
    /* 0x1C */ u8 unk_1C;
} ApricornBoxApp;

// No tracked definition: output block of sub_02031DA0.
typedef struct ApricornJuiceEntry {
    u16 stat : 4;
    u16 unk_04 : 4;
    u16 amount : 8;
} ApricornJuiceEntry;

typedef struct ApricornJuiceData {
    /* 0x00 */ ApricornJuiceEntry entries[2];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u8 statOverride[2];
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u8 penaltyStat;
    /* 0x0B */ u8 unk_0B;
} ApricornJuiceData;

void sub_0200FBF4(PMLCDTarget screen, u16 color);

#endif // OV58_PRIVATE_H
