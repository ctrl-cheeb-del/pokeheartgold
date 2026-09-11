#ifndef POKEHEARTGOLD_OVERLAY14_PC_BOX_MOVE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_PC_BOX_MOVE_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

#define SPRITE(q, i)  PTR_AT((u8 *)(q) + (i) * 4, 0x2FC)
#define TBL4094(q, i) U8_AT((u8 *)(q) + (i), 0x4094)

#define MON_DATA_MOOD 187

typedef struct PartyExtraSub {
    u8 unk_00[5];
} PartyExtraSub;

typedef struct PalFade {
    u8 isBg : 1;
    u8 index : 7;
    u8 palA : 4;
    u8 palB : 4;
    u8 state;
    u8 timer;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} PalFade;

typedef struct BoxMoveEntry {
    void *mon;
    u32 from;
    u32 to;
    u32 active;
    u32 dx;
    u32 dy;
    s16 sx;
    s16 sy;
    s16 px;
    s16 py;
} BoxMoveEntry;

typedef struct BoxMoveWork {
    BoxMoveEntry entries[7];
    u32 timer;
    u32 from;
    u32 to;
    u32 sel;
} BoxMoveWork;

typedef struct YesNoTemplate {
    void *bgConfig;
    int bgId;
    int tileStart;
    u32 plttSlot;
    u8 x;
    u8 y;
    u8 ignoreTouchFlag : 4;
    u8 initialCursorPos : 4;
    u8 shapeParam;
} YesNoTemplate;

extern void YesNoPrompt_InitFromTemplate(void *, const YesNoTemplate *);
extern void BgTilemapRectChangePalette(void *, u32, u32, u32, u32, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void ManagedSprite_SetPaletteOverride(void *, u32);
extern void ManagedSprite_SetPositionXY(void *, s32, s32);
extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern u32 GridInputHandler_IsButtonInputMode(void *);
extern void MenuInputStateMgr_SetState(void *, u32);
extern u32 GetBoxMonData(void *, u32, void *);
extern void SetBoxMonData(void *, u32, void *);
extern u32 GetMonData(void *, u32, void *);
extern void SetMonData(void *, u32, void *);
extern void *Mon_GetBoxMon(void *);
extern void Mon_UpdateShayminForm(void *, u32);
extern void BoxMon_UpdateShayminForm(void *, u32);
extern void BoxMon_UpdateArceusForm(void *);
extern void BoxMon_UpdateGiratinaForm(void *);
extern void CopyBoxPokemonToPokemon(void *, void *);
extern void CopyPokemonToPokemon(void *, void *);
extern u32 ItemIdIsMail(u16);
extern void *Heap_AllocAtEnd(u32, u32);
extern u32 Party_GetCount(void *);
extern void *Party_GetMonByIndex(void *, u32);
extern void Party_AddMon(void *, void *);
extern void Party_RemoveMon(void *, u32);
extern void Party_GetMonAprijuiceModifiers(void *, PartyExtraSub *, u32);
extern void Party_SetMonAprijuiceModifiers(void *, const PartyExtraSub *, u32);
extern void Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(void *, u32, void *);
extern void *PCStorage_GetMonByIndexPair(void *, u32, u32);
extern void PCStorage_DeleteBoxMonByIndexPair(void *, u32, u32);
extern void PCStorage_PlaceMonInBoxByIndexPair(void *, u32, u32, void *);
extern void PCStorage_PlaceMonInBoxFirstEmptySlot(void *, u32, void *);
extern void PCStorage_SwapMonsInBoxByIndexPair(void *, u32, u32, u32);
extern void PCStorage_SetBoxModified(void *, u32);
extern u32 PCStorage_CountMonsAndEggsInBox(void *, u32);

extern const u16 ov14_021F7BC0[];

extern u32 ov14_021E7588(void *, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F2ED0(void *, u32, u32, u32);
extern void ov14_021F2F88(u32, s16 *, s16 *, u32);
extern void ov14_021F3190(void *, u32, u32);
extern void ov14_021F31E0(void *, u32, u32);
extern void ov14_021F4940(void *, u32, s16 *, s16 *);
extern void ov14_021F4958(void *, u32);
extern void ov14_021F4A20(void *, u32);

#endif
