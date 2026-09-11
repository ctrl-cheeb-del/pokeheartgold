#ifndef POKEHEARTGOLD_OVERLAY14_BOX_ACTIONS_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY14_BOX_ACTIONS_INTERNAL_H

#include "global.h"

/* House style, copied verbatim from include/overlay_14_sol_partial_internal.h */
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

/* ---- non-overlay externals (global.h does not reach these headers) ---- */
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void *AllocMonZeroed(u32);
extern u32 GetMonData(void *, s32, void *);
extern s32 Party_GetCount(void *);
extern void *Party_GetMonByIndex(void *, s32);
extern u32 ItemIdIsMail(u16);
extern void PlaySE(u32);
extern u32 System_GetTouchNew(void);
extern s32 PCStorage_CountMonsInBox(void *, u32);
extern s32 PCStorage_CountEmptySpotsInBox(void *, u32);
extern s32 PCStorage_CountMonsAndEggsInBox(void *, u32);
extern u32 PCStorage_IsBonusWallpaperUnlocked(void *, u32);
extern s32 GridInputHandler_GetNextInput(void *);
extern void GridInputHandler_SetNextInput(void *, s32);
extern void GridInputHandler_SetNextLastUnk0FInputs(void *, s32, s32, s32);
extern u32 GridInputHandler_IsButtonInputMode(void *);
extern void GridInputHandler_SetButtonInputMode(void *, u32);
extern const void *GridInputHandler_GetDpadBox(void *, s32);
extern void DpadMenuBox_GetPosition(const void *, u8 *, u8 *);
extern void ManagedSprite_SetPositionXY(void *, s32, s32);

/* ---- overlay_14 helpers defined elsewhere ---- */
extern u32 ov14_021E6070(void *, u32, u32, u32);
extern u32 ov14_021E6480(void *, u32);
extern void ov14_021E76B8(void *);
extern void ov14_021E783C(void *, u32, u32);
extern u32 ov14_021E7930(void *, u32);
extern void ov14_021E7E64(void *);
extern void ov14_021E7E78(void *);
extern void ov14_021E7E88(void *);
extern void ov14_021E8020(void *);
extern void ov14_021E805C(void *);
extern void ov14_021E81A8(void *, u32);
extern void ov14_021E8234(void *);
extern void ov14_021E8248(void *);
extern void ov14_021E8294(void *);
extern void ov14_021E82A8(void *);
extern void ov14_021E82DC(void *);
extern void ov14_021E8314(void *);
extern void ov14_021E8328(void *);
extern void ov14_021E8368(void *);
extern void ov14_021E83F4(void *);
extern void ov14_021E8434(void *);
extern void ov14_021E84A4(void *);
extern u32 ov14_021E8544(void *);
extern void ov14_021E85D0(void *);
extern u32 ov14_021E85E4(void *);
extern void ov14_021E8634(void *);
extern u32 ov14_021E8648(void *);
extern void ov14_021E86E0(void *);
extern void ov14_021E8704(void *);
extern void ov14_021E8824(void *);
extern void ov14_021E884C(void *);
extern u32 ov14_021EC710(void *);
extern void ov14_021ED5B0(void *);
extern u32 ov14_021F0234(void *, void *, u32);
extern u32 ov14_021F0254(void *, u32);
extern u32 ov14_021F027C(void *, u32);
extern u32 ov14_021F2270(void *, u32, u32);
extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F2DE8(void *, u32);
extern void ov14_021F3044(void *);
extern void ov14_021F30B0(void *);
extern void ov14_021F311C(void *);
extern void ov14_021F3190(void *, u32, u32);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021F34C8(void *, u32, u32);
extern void ov14_021F3F6C(void *);
extern void ov14_021F43F4(void *, u32);
extern void ov14_021F4530(void *);
extern void ov14_021F459C(void *);
extern void ov14_021F462C(void *);
extern void ov14_021F4720(void *);
extern void ov14_021F4848(void *);
extern void ov14_021F48B4(void *);
extern void ov14_021F49E0(void *);
extern void ov14_021F57B8(void *);
extern void ov14_021F58B8(void *);
extern void ov14_021F5EC4(void *, u32);
extern void ov14_021F604C(void *);
extern void ov14_021F63A8(void *);
extern void ov14_021F63B8(void *);
extern void ov14_021F63F0(void *);
extern void ov14_021F6408(void *, u32);
extern void ov14_021F6654(void *, u32);
extern void ov14_021F6704(void *, u32, u32);
extern void ov14_021F685C(void *, u32, u32, u32);
extern void ov14_021F6928(void *, u32, u32);
extern void ov14_021F6AC0(void *, u32, u32);

/* ---- state callbacks (address-taken only) ---- */
extern void ov14_021E8BA4(void *);
extern void ov14_021E8D20(void *);
extern void ov14_021E8FD4(void *);
extern void ov14_021E92AC(void *);
extern void ov14_021E9370(void *);
extern void ov14_021E9434(void *);
extern void ov14_021E9450(void *);
extern void ov14_021E94A8(void *);
extern void ov14_021E94BC(void *);
extern void ov14_021E952C(void *);
extern void ov14_021E954C(void *);
extern void ov14_021E9554(void *);
extern void ov14_021E9590(void *);
extern void ov14_021E95B4(void *);
extern void ov14_021E9920(void *);
extern void ov14_021E9970(void *);
extern void ov14_021E9A24(void *);
extern void ov14_021E9C88(void *);
extern void ov14_021EA068(void *);
extern void ov14_021EA0B8(void *);

#endif
