#ifndef OV41_R17_PRIVATE_H
#define OV41_R17_PRIVATE_H

#include "global.h"

#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

extern u8 gSystem[];

extern void *PokepicManager_Create(u32 heapId);
extern void PokepicManager_Delete(void *manager);
extern void PokepicManager_SetCharBaseAddrAndSize(void *, u32, u32);
extern void PokepicManager_SetPlttBaseAddrAndSize(void *, u32, u32);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void *GF2dGfxRawResMan_Create(u32 count, u32 heapId);
extern void GF2dGfxRawResObj_Destroy(void *manager);

extern void ov41_02246130(void *work);
extern void ov41_02246170(void *work);
extern void ov41_022463B0(void *work, void *data);
extern void ov41_02246250(void *work, void *data);
extern void ov41_022463D4(void *data);

extern void Heap_Create();
extern void Heap_Destroy();
extern void *OverlayManager_CreateAndGetData();
extern void *OverlayManager_GetData();
extern void *OverlayManager_GetArgs();
extern void OverlayManager_FreeData();
extern void Main_SetVBlankIntrCB();
extern void HBlankInterruptDisable(void);
extern u32 MenuInputStateMgr_GetState();
extern void MenuInputStateMgr_SetState();
extern void sub_020210BC(void);
extern void sub_02021148();
extern u32 sub_02021238(void);
extern void ov41_02247478(void);
extern void ov41_02248E84();
extern void ov41_022499B4();
extern void *ov41_02245EA0();
extern void ov41_02247288();
extern void ov41_02247334();
extern void ov41_02247480();
extern void ov41_022474D4();
extern void ov41_0224765C();
extern void ov41_02248F18();
extern void *YesNoPrompt_Create();
extern void YesNoPrompt_Destroy();
extern void *AllocWindows();
extern void WindowArray_Delete();
extern void Sound_SetSceneAndPlayBGM();
extern void GameStats_AddScore();
extern void ov41_022479A8();
extern void ov41_022476A8();
extern void ov41_02248F6C();
extern void ov41_02247568();
extern void ov41_022474C4();
extern void ov41_02247310();
extern void ov41_022473F0();
extern void ov41_02245ECC();
extern void ov41_022499DC();
extern void ov41_02247274();
extern void BeginNormalPaletteFade();
extern u32 IsPaletteFadeFinished(void);
extern void TextFlags_SetCanTouchSpeedUpPrint();
extern u32 ov41_0224AC40();
extern u32 TextPrinterCheckActive();
extern void ov41_0224AC80();
extern void ov41_0224AC08();
extern void ov41_022476B8();
extern void ov41_02248E44();
extern void ov41_02247D44();
extern void ov41_0224ABF0();
extern void ov41_02247578();
extern void ov41_0224B4E8();
extern void ov41_02247828();
extern void ov41_02247D64();
extern u32 ov41_02247B7C();
extern void ov41_0224B50C();
extern u32 ov41_02247DF8();
extern void ov41_0224B518();
extern void ov41_0224726C();

void ov41_02246CC0(void *work, u32 heapId, u32 texSize, u32 plttSize);
void ov41_02246D2C(void *work);
void ov41_02246D54(void *work, u32 count1, u32 count2, u32 heapId);
void ov41_02246DA8(void *work);
BOOL ov41_02246DE0(void *manager, int *state);
BOOL ov41_02246F08(void *manager, int *state);
BOOL ov41_02247150(void *manager, int *state);
void ov41_02247240(void *work);

#endif
