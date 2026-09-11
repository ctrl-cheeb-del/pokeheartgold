#ifndef OVERLAY14_BOX_UI_ACTIONS_INTERNAL_H
#define OVERLAY14_BOX_UI_ACTIONS_INTERNAL_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern void sub_020196E8(void *, int, int, int);
extern void sub_0201980C(void *, int);
extern void sub_020198FC(void *, int, int, int, u8);
extern u32 sub_02019978(void *, int);
extern u32 sub_020199E4(void *, int);
extern void sub_02019B1C(void *, int, s8 *, s8 *);
extern void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u8);
extern void ScheduleSetBgPosText(void *, int, int, int);
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern int Party_GetCount(void *);
extern u32 System_GetTouchHeldCoords(u32 *, u32 *);
extern void ManagedSprite_SetPositionXY(void *, s16, s16);
extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern u32 GridInputHandler_IsButtonInputMode(void *);
extern void GridInputHandler_SetButtonInputMode(void *, u32);
extern void *OverlayManager_New(const void *, void *, u32);
extern void HandleLoadOverlay(u32, s32);
extern void UnloadOverlayByID(u32);
extern void PCStorage_SetBoxModified(void *, u32);
extern u32 PCStorage_FindFirstEmptySlot(void *, int *, int *);
extern void PCStorage_GetBoxName(void *, u32, void *);
extern void PCStorage_SetBoxName(void *, u32, void *);
extern u16 BagView_GetItemId(void *);
extern void *Bag_CreateView(void *, const u8 *, u32);
extern void *Save_Bag_Get(void *);
extern void *NamingScreen_CreateArgs(u32, u32, u32, u32, void *, void *);
extern void NamingScreen_DeleteArgs(void *);
extern void *Save_PlayerData_GetProfile(void *);
extern u32 SaveArray_IsNatDexEnabled(void *);
extern void *Save_SpecialRibbons_Get(void *);
extern void sub_0208AD34(void *, void *);
extern void sub_02089D40(void *, const void *);
extern void *sub_02088288(void *);
extern void *sub_0208828C(void *);
extern void sub_0207789C(void *, void *, u32, u32, void *);

extern const u8 ov14_021F7BF0[];
extern const u8 ov14_021F7C08[];
extern const u8 ov14_021F7D0C[];
extern const u8 ov14_021F7D14[];
extern const u8 gOverlayTemplate_PokemonSummary[];
extern const u8 gOverlayTemplate_NamingScreen[];
extern const u8 ov15_022008B8[];

extern void ov14_021E5F4C(void *);
extern void *ov14_021E60C0(void *, u32, u32);
extern u32 ov14_021E6070(void *, u32, u32, u32);
extern u32 ov14_021E65C4(void *);
extern u32 ov14_021E66F4(void *);
extern u32 ov14_021E6814(void *);
extern void ov14_021E6CF8(void *, u32, u32);
extern u32 ov14_021E70B0(void *, u32);
extern void ov14_021E70E0(void *, u32);
extern void ov14_021E7148(void *, void *);
extern void ov14_021E7588(void *, u32);
extern u32 ov14_021E7960(s16, s16);
extern u32 ov14_021E79AC(s16, s16, const void *);
extern u32 ov14_021E79D8(s16, s16);
extern void ov14_021E7EE0(void *);
extern void ov14_021E7FB8(void *);
extern void ov14_021E7FEC(void *);
extern u32 ov14_021E80A8(void *);
extern void ov14_021E821C(void *);
extern void ov14_021E827C(void *);
extern void ov14_021F3210(void *, s32);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021F34C8(void *, u32, u32);
extern void ov14_021F4174(void *);
extern void ov14_021F40E8(void *, u32);
extern void ov14_021F4720(void *);
extern void ov14_021F47B8(void *, u32);
extern void ov14_021F4848(void *);
extern void ov14_021F48B4(void *);
extern void ov14_021F57B8(void *);
extern void ov14_021F5EB4(void *, u32);
extern void ov14_021F5EC4(void *, u32);
extern void ov14_021F6070(void *);
extern void ov14_021F69F0(void *, u32);

FS_EXTERN_OVERLAY(OVY_15);

void ov14_021E8294(void *p);
void ov14_021E82A8(void *p);
void ov14_021E82BC(void *p);
void ov14_021E82DC(void *p);
void ov14_021E82FC(void *p);
void ov14_021E8314(void *p);
void ov14_021E8328(void *p);
u32 ov14_021E834C(void *p);
void ov14_021E8368(void *p);
void ov14_021E8394(void *p);
void ov14_021E83C4(void *p);
void ov14_021E83F4(void *p);
void ov14_021E8434(void *p);
void ov14_021E84A4(void *p);
u32 ov14_021E8514(void *p);
u32 ov14_021E8544(void *p);
void ov14_021E8560(void *p);
void ov14_021E8588(void *p);
void ov14_021E85AC(void *p);
void ov14_021E85BC(void *p);
void ov14_021E85D0(void *p);
u32 ov14_021E85E4(void *p);
void ov14_021E8600(void *p);
void ov14_021E8610(void *p);
void ov14_021E8620(void *p);
void ov14_021E8634(void *p);
u32 ov14_021E8648(void *p);
void ov14_021E8664(void *p);
void ov14_021E86E0(void *p);
void ov14_021E8704(void *p);
void ov14_021E8718(void *p);
void ov14_021E8740(void *p);
void ov14_021E875C(void *p);
void ov14_021E87BC(void *p);
void ov14_021E87F4(void *p);
void ov14_021E8824(void *p);
void ov14_021E884C(void *p);
void ov14_021E8874(void *p);
void ov14_021E88A4(void *p);
void ov14_021E88BC(void *p);
void ov14_021E88F8(void *p);
void ov14_021E892C(void *p);
void ov14_021E8944(void *p);
void ov14_021E895C(void *p, u32 mask);
u32 ov14_021E89B8(void *p);
u32 ov14_021E8A7C(void *p);
u32 ov14_021E8ACC(void *p);
u32 ov14_021E8B1C(void *p);
u32 ov14_021E8B3C(void *p);
u32 ov14_021E8B80(void *p);
u32 ov14_021E8BA4(void *p);
u32 ov14_021E8D20(void *p);
u32 ov14_021E8FD4(void *p);
u32 ov14_021E9194(void *p);
u32 ov14_021E91E0(void *p);
u32 ov14_021E9234(void *p);
u32 ov14_021E92AC(void *p);
u32 ov14_021E9370(void *p);
u32 ov14_021E9434(void *p);
u32 ov14_021E9450(void *p);

#endif
