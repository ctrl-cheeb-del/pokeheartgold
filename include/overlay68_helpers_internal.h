#ifndef OV68_PRIVATE_H
#define OV68_PRIVATE_H

#include "global.h"

#include "constants/heap.h"

typedef struct Window {
    u8 dummy[0x10];
} Window;
typedef struct BgConfig BgConfig;

typedef struct MoveRelearnerArgs {
    /* 0x00 */ void *unk_00;
    /* 0x04 */ u8 unk_04[0x0C - 0x04];
    /* 0x0C */ void *unk_0C;
    /* 0x10 */ u16 *unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u8 unk_18[0x1A - 0x18];
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 unk_1B;
} MoveRelearnerArgs;

typedef struct Ov68Sub1D0 {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 unk_2;
    /* 0x3 */ u8 unk_3;
    /* 0x4 */ u16 unk_4;
    /* 0x6 */ u16 unk_6;
    /* 0x8 */ void *unk_8;
} Ov68Sub1D0;

typedef struct Ov68Pokepic {
    /* 0x00 */ void *camera;
    /* 0x04 */ void *pokepicMan;
    /* 0x08 */ u8 unk_08[0x1C - 0x08];
} Ov68Pokepic;

typedef struct MoveRelearner {
    /* 0x000 */ MoveRelearnerArgs *args;
    /* 0x004 */ BgConfig *bgConfig;
    /* 0x008 */ Window windows[15];
    /* 0x0F8 */ void *msgData;
    /* 0x0FC */ void *msgFmt;
    /* 0x100 */ void *unk_100;
    /* 0x104 */ void *unk_104;
    /* 0x108 */ void *unk_108;
    /* 0x10C */ u8 unk_10C[0x110 - 0x10C];
    /* 0x110 */ void *unk_110;
    /* 0x114 */ u8 unk_114[0x118 - 0x114];
    /* 0x118 */ void *unk_118;
    /* 0x11C */ void *unk_11C;
    /* 0x120 */ void *unk_120;
    /* 0x124 */ void *sprites[12];
    /* 0x154 */ Ov68Pokepic pokepic;
    /* 0x170 */ u8 unk_170[0x1B0 - 0x170];
    /* 0x1B0 */ u32 state;
    /* 0x1B4 */ void *unk_1B4;
    /* 0x1B8 */ u8 unk_1B8;
    /* 0x1B9 */ u8 unk_1B9;
    /* 0x1BA */ u8 unk_1BA;
    /* 0x1BB */ u8 unk_1BB[0x1C0 - 0x1BB];
    /* 0x1C0 */ void *unk_1C0;
    /* 0x1C4 */ u8 unk_1C4[0x1C8 - 0x1C4];
    /* 0x1C8 */ void *unk_1C8;
    /* 0x1CC */ u8 unk_1CC[0x1CE - 0x1CC];
    /* 0x1CE */ u16 unk_1CE;
    /* 0x1D0 */ Ov68Sub1D0 unk_1D0;
} MoveRelearner;

void Heap_Free(void *ptr);
void ListMenuItems_Delete(void *items);
void GridInputHandler_Free(void *h);
void ClearFrameAndWindow2(void *window, BOOL dont_copy);
void ClearWindowTilemapAndScheduleTransfer(void *window);
u32 GetMonData(void *mon, int field, void *dest);
void sub_020880CC(u8 a0, u32 heapId);
BOOL TextPrinterCheckActive(u8 printerId);
BOOL IsPaletteFadeFinished(void);
void YesNoPrompt_Destroy(void *prompt);
void RemoveWindow(void *window);
void FontID_Release(u32 fontId);
void Camera_Delete(void *camera);
void PokepicManager_Delete(void *man);
void DoScheduledBgGpuUpdates(BgConfig *bgConfig);
void PokepicManager_HandleLoadImgAndOrPltt(void *man);
void GF_RunVramTransferTasks(void);
void SpriteSystem_TransferOam(void);
void Sprite_DeleteAndFreeResources(void *sprite);
void SpriteSystem_FreeResourcesAndManager(void *a, void *b);
void SpriteSystem_Free(void *a);

void ov68_021E6C14(MoveRelearner *d, u32 a1);
void ov68_021E6C74(MoveRelearner *d);
u32 ov68_021E7B94(MoveRelearner *d);
u32 ov68_021E6CD8(MoveRelearner *d);
u16 ov68_021E6BEC(MoveRelearner *d);
void ov68_021E68D4(MoveRelearner *d, s32 a1);
void ov68_021E70BC(MoveRelearner *d);
void ov68_021E7A18(MoveRelearner *d, u32 a1);

void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
void *MessageFormat_New(u32 heapId);
void *String_New(u32 size, u32 heapId);
void *NewString_ReadMsgData(void *msgData, u32 msgId);
void DestroyMsgData(void *msgData);
void MessageFormat_Delete(void *fmt);
void String_Delete(void *str);
void GfGfx_EngineBTogglePlanes(u32 planes, u32 toggle);
void FreeBgTilemapBuffer(BgConfig *bgConfig, u32 layer);
void Heap_FreeExplicit(u32 heapId, void *ptr);
void MenuInputStateMgr_SetState(void *a, void *b);
void TextFlags_SetCanTouchSpeedUpPrint(BOOL flag);
void GF_DestroyVramTransferManager(void);
void Main_SetVBlankIntrCB(void *cb, void *arg);
BOOL GF_IsAnySEPlaying(void);
BOOL IsFanfarePlaying(void);
void PlaySE(u32 seq);
void PlayFanfare(u32 seq);
BOOL IsSEPlaying(u32 seq);

void ov68_021E5B14(MoveRelearner *d);
void ov68_021E5F18(MoveRelearner *d);
void ov68_021E5EBC(MoveRelearner *d);
void ov68_021E5CD8(BgConfig *bgConfig);
u32 ov68_021E6C8C(u32 a0, u32 a1);

void ov68_021E7614(void);
u32 ov68_021E7B8C(MoveRelearner *d);
u32 ov68_021E6D40(MoveRelearner *d);
u32 ov68_021E6D4C(MoveRelearner *d);
u32 ov68_021E6D58(MoveRelearner *d);
u32 ov68_021E6DD0(MoveRelearner *d);
void ov68_021E5E38(MoveRelearner *d);
void ov68_021E68C4(MoveRelearner *d);
void ov68_021E7604(MoveRelearner *d);
u32 ov68_021E6D64(MoveRelearner *d);
u32 ov68_021E6D80(MoveRelearner *d);
u32 ov68_021E6D9C(MoveRelearner *d);
u32 ov68_021E6DB8(MoveRelearner *d);
u16 ov68_021E6BFC(MoveRelearner *d);
u32 ov68_021E61A0(MoveRelearner *d);
u32 ov68_021E61EC(MoveRelearner *d);
u32 ov68_021E74C0(MoveRelearner *d);
u32 ov68_021E6058(MoveRelearner *d);
u32 ov68_021E5F50(MoveRelearner *d);
u32 ov68_021E6D00(MoveRelearner *d);
u32 ov68_021E6D20(MoveRelearner *d);
u32 ov68_021E7B6C(MoveRelearner *d);
u32 ov68_021E7A90(MoveRelearner *d, void *a1);
u32 ov68_021E7AB4(MoveRelearner *d, void *a1);
u32 ov68_021E6678(MoveRelearner *d);
void ov68_021E5E94(MoveRelearner *d);
void ov68_021E7388(Ov68Pokepic *p);
void ov68_021E6E84(MoveRelearner *d);
void ov68_021E5B6C(MoveRelearner *d);
void ov68_021E6204(MoveRelearner *d);
u32 ov68_021E61B8(MoveRelearner *d);

#endif
