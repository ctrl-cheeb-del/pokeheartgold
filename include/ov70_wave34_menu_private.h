#ifndef OV70_WAVE34_MENU_PRIVATE_H
#define OV70_WAVE34_MENU_PRIVATE_H

#include "global.h"

typedef struct PlayerProfile PlayerProfile;
typedef struct Pokemon Pokemon;
typedef struct BoxPokemon BoxPokemon;

typedef struct Ov70MenuState {
    void *bg;
    void *windows;
    void *unk08;
    void *sprite;
    u8 pad10[0x0c];
    void *messageData;
    u8 pad20[0x18];
    void *printer;
    s16 selection;
    s16 unk3e;
    s16 unk40;
    s16 result42;
    s8 result44;
    s8 result45;
    u8 pad46[2];
    s32 cursor;
    s32 cursorLimit;
    u8 pad50[4];
    void *arg54;
    u16 mode58;
    u8 pad5a[4];
    void *arg60;
    u8 pad64[0x1a];
    u8 savedCursor;
} Ov70MenuState;

typedef struct Ov70Outer {
    void *party;
    u8 pad04[4];
    void *pcStorage;
} Ov70Outer;

typedef struct Ov70Transfer {
    Ov70Outer *outer;
    u8 pad04[0x20];
    u32 sourceKind;
    u8 pad28[0xa0];
    u16 name[8];
    u8 padd8[0x48];
    u8 version;
    u8 language;
    u8 pad122[0x0a];
    u32 box;
    u32 slot;
    u8 pad134[0xcc];
    Pokemon *mon;
    u8 pad204[0xfec];
    void *heap1;
} Ov70Transfer;

typedef struct Ov70ChoiceEntry {
    s32 threshold;
    u32 unk04;
} Ov70ChoiceEntry;

extern u8 gSystem[];
extern const u8 ov70_02245DC0[];
extern const u8 ov70_02245E26[];
extern const u8 ov70_02245E3E[];
extern const u8 ov70_02245E5E[];
extern const u8 *const ov70_02245E84[];
extern const u8 ov70_02245EA8[];
extern const u8 ov70_02245ED0[];
extern const u8 ov70_02245F28[];
extern const Ov70ChoiceEntry ov70_02245F5C[];
extern int (*const ov70_022466F8[])(Ov70MenuState *);

void Heap_Free(void *);
void *Heap_Alloc(u32, u32);
PlayerProfile *PlayerProfile_New(u32);
void PlayerProfile_Init(PlayerProfile *);
void Save_Profile_PlayerName_Set(PlayerProfile *, const u16 *);
void PlayerProfile_SetVersion(PlayerProfile *, u8);
void PlayerProfile_SetLanguage(PlayerProfile *, u8);
void GF_AssertFail(void);
void *Party_GetMonByIndex(void *, int);
void CopyPokemonToPokemon(void *, void *);
void PCStorage_DeleteBoxMonByIndexPair(void *, int, int);
BOOL PCStorage_FindFirstEmptySlot(void *, int *, int *);
BoxPokemon *Mon_GetBoxMon(Pokemon *);
BOOL PCStorage_PlaceMonInBoxFirstEmptySlot(void *, int, BoxPokemon *);
void *sub_0201956C(void *, int, int, u32);
void sub_020195F4(void *, int, int, int, int);
void sub_020195C0(void *);
void sub_02019934(void *);
void ov70_02238E58(void *);
void ov70_02238F9C(void *, int, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void *MessagePrinter_New(int, int, int, u32);
void MessagePrinter_Delete(void *);
int TouchscreenHitbox_FindRectAtTouchNew(const void *);
void PlaySE(u32);

int ov70_02241808(Ov70Transfer *);
PlayerProfile *ov70_0224182C(Ov70Transfer *);
void *ov70_02241868(Ov70Transfer *, int);
void ov70_022418A4(Ov70Transfer *);
void ov70_0224212C(Ov70MenuState *);
int ov70_02242144(Ov70MenuState *);
int ov70_02242164(Ov70MenuState *, int);
int ov70_02242364(Ov70MenuState *, int);
void ov70_022420C4(Ov70MenuState *, int);
Ov70MenuState *ov70_02242014(void *, int, void *);
int ov70_022421D0(Ov70MenuState *, const u8 *);
int ov70_02242390(Ov70MenuState *, u32);

#endif
