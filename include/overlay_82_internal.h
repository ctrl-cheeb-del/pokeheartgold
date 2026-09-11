#ifndef OV82_PRIVATE_H
#define OV82_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "heap.h"

FS_EXTERN_OVERLAY(OVY_80);

typedef struct Ov82Work {
    /* 0x000 */ void *unk000;
    /* 0x004 */ void *unk004;
    /* 0x008 */ u8 unk008;
    /* 0x009 */ u8 unk009;
    /* 0x00a */ u8 unk00A;
    /* 0x00b */ u8 unk00B;
    /* 0x00c */ u8 unk00C;
    /* 0x00d */ u8 unk00D;
    /* 0x00e */ u8 unk00E;
    /* 0x00f */ u8 unk00F;
    /* 0x010 */ u16 unk010;
    /* 0x012 */ u16 unk012;
    /* 0x014 */ s16 unk014;
    /* 0x016 */ u8 unk016;
    /* 0x017 */ u8 unk017;
    /* 0x018 */ u8 unk018;
    /* 0x019 */ u8 unk019;
    /* 0x01a */ u8 unk01A;
    /* 0x01b */ u8 unk01B;
    /* 0x01c */ u16 unk01C;
    /* 0x01e */ u8 unk01E;
    /* 0x01f */ u8 unk01F;
    /* 0x020 */ u8 pad020[4];
    /* 0x024 */ void *unk024;
    /* 0x028 */ u8 pad028[0x20];
    /* 0x048 */ BgConfig *bgConfig;
    /* 0x04c */ Window windows[4];
    /* 0x08c */ void *yesNo;
    /* 0x090 */ u8 unk090;
    /* 0x091 */ u8 pad091[7];
    /* 0x098 */ void *unk098;
    /* 0x09c */ void *options;
    /* 0x0a0 */ void *saveData;
    /* 0x0a4 */ void *unk0A4;
    /* 0x0a8 */ void *spriteList;
    /* 0x0ac */ u8 pad0AC[0x158];
    /* 0x204 */ void *unk204;
    /* 0x208 */ void *unk208;
    /* 0x20c */ u32 unk20C;
    /* 0x210 */ u16 *unk210;
    /* 0x214 */ void *party;
    /* 0x218 */ void *unk218;
    /* 0x21c */ void *unk21C;
    /* 0x220 */ u8 pad220[4];
    /* 0x224 */ u16 unk224;
    /* 0x226 */ u16 unk226;
    /* 0x228 */ u16 unk228;
    /* 0x22a */ u16 unk22A;
    /* 0x22c */ u8 pad22C[0x50];
    /* 0x27c */ u8 unk27C;
    /* 0x27d */ u8 unk27D;
    /* 0x27e */ u8 pad27E[6];
} Ov82Work;

typedef struct Ov82Args {
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ void *unk08;
    /* 0x0c */ void *unk0C;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ void *unk14;
    /* 0x18 */ u16 unk18;
    /* 0x1a */ u8 pad1A[2];
} Ov82Args;

/* library externs */
void HandleLoadOverlay(FSOverlayID ovyId, s32 loadType);
void UnloadOverlayByID(FSOverlayID ovyId);
void *OverlayManager_CreateAndGetData(void *man, u32 size, enum HeapID heapId);
void *OverlayManager_GetData(void *man);
void OverlayManager_FreeData(void *man);
Ov82Args *OverlayManager_GetArgs(void *man);
BOOL OverlayManager_Run(void *man);
void *Save_PlayerData_GetOptionsAddr(void *saveData);
void TextFlags_SetCanTouchSpeedUpPrint(BOOL flag);
void SpriteList_RenderAndAnimateSprites(void *list);
void FillBgTilemapRect(BgConfig *bgConfig, u8 bgId, u16 fill, u8 x, u8 y, u8 width, u8 height, u8 palette);
void BeginNormalPaletteFade(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, enum HeapID heapId);
BOOL IsPaletteFadeFinished(void);

/* cross-module externs */
BOOL ov80_0223792C(u32 a0);
void sub_02096910(Ov82Work *work);
void sub_02037BEC(void);
void sub_02037AC0(u32 a0);
BOOL sub_02037B38(u32 a0);

/* siblings still in assembly */
void ov82_0223E9B0(void);
void ov82_0223E9E8(Ov82Work *work);
void ov82_0223E8C4(Ov82Work *work);
void ov82_0223E974(Ov82Work *work);
void ov82_0223F834(Ov82Work *work);
void ov82_0223F2F8(Ov82Work *work, int *state, u32 next);
BOOL ov82_0223E7E8(Ov82Work *work);
BOOL ov82_0223E820(Ov82Work *work);
BOOL ov82_0223E888(Ov82Work *work);
void ov82_0223F040(Ov82Work *work, Window *window, u32 a2, u32 a3, u32 a4, u32 a5);
void ov82_0223F134(Ov82Work *work, Window *window);
void ov82_0223EFCC(Ov82Work *work, Window *window, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void ov82_0223F1AC(Ov82Work *work, Window *window, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void ov82_0223EECC(Ov82Work *work, u32 a1);

void StopSE(u32 seId, u32 fadeout);
void PlaySE(u32 seId);
u32 Options_GetFrame(void *options);
u32 sub_0203769C(void);
void sub_020379A0(u32 a0);
u32 ov82_0223F6C4(u32 a0);
BOOL ov82_0223F6E8(Ov82Work *work, u32 a1, u32 a2);
void ov82_0223F948(s32 a0);
void ov82_0223FCB0(void *a0);
void ov82_0223FD78(Window *window, u32 frame);
void ov80_0222A7CC(void *a0, u32 a1);
u8 ov82_0223EF7C(Ov82Work *work, u32 a1, u32 a2);
void ov82_0223F5E0(BgConfig *bgConfig, u32 a1, u32 a2);
void ov82_0223F90C(Ov82Work *work);
void ov82_0223F84C(Ov82Work *work);
u32 ov82_0223FE18(void *yesNo);
void ov82_0223F8E4(Ov82Work *work);

/* this module */
BOOL ov82_0223DD60(void *man, int *state);
BOOL ov82_0223DE20(void *man, int *state);
BOOL ov82_0223DF74(void *man);
BOOL ov82_0223DFBC(Ov82Work *work);
void ov82_0223E070(Ov82Work *work);
void ov82_0223E0B0(Ov82Work *work);
void ov82_0223E140(BgConfig *bgConfig, u8 bgId, u8 x, u8 y, u8 w, u8 h, u16 tile, u32 palette);
BOOL ov82_0223E2A4(Ov82Work *work);
BOOL ov82_0223E2EC(Ov82Work *work);
BOOL ov82_0223E5D4(Ov82Work *work);

#endif
