#ifndef POKEHEARTGOLD_OVERLAY14_INPUT_DISPATCH_R22_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_INPUT_DISPATCH_R22_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov14DispatchEntry {
    u32 (*init)(void *);
    void (*exit)(void *);
    u32 next;
} Ov14DispatchEntry;

extern const Ov14DispatchEntry ov14_021F7D50[];
extern const u8 ov14_021F7D1C[];
extern const u8 ov14_021F7D2C[];
extern const u8 ov14_021F7D3C[];
extern u8 gSystem[];
extern void ov14_021E9434(void *);

extern u32 OverlayManager_Run(void *);
extern void OverlayManager_Delete(void *);
extern void PlaySE(u32);
extern void ov14_021F0BF4(void *);
extern void ov14_021F685C(void *, u32, u32, u32);
extern void ov14_021F43F4(void *, u32);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021E7588(void *, u32);
extern void ov14_021F01D8(void *, u32);
extern u32 ov14_021F0234(void *, void *, u32);
extern void ov14_021E637C(void *);
extern void System_GetTouchNewCoords(u32 *, u32 *);
extern u32 System_GetTouchNew(void);
extern u32 GridInputHandler_GetNextInput(void *);
extern u32 ov14_021E8544(void *);
extern void ov14_021E84A4(void *);
extern void ov14_021E8248(void *);
extern void ov14_021E82A8(void *);
extern void ov14_021E8328(void *);
extern void ov14_021E884C(void *);
extern void ov14_021E765C(void *);
extern void ov14_021E76B8(void *);
extern void ov14_021EA180(void *);
extern void ov14_021F08F0(void *);
extern void GridInputHandler_SetNextInput(void *, u32);
extern void GridInputHandler_SetButtonInputMode(void *, u32);
extern void ov14_021F6688(void *, u32);
extern void ov14_021F5EE4(void *, const void *, u32);
extern void ov14_021E8434(void *);
extern void ov14_021E8740(void *);
extern void ov14_021E8664(void *);
extern void ov14_021E87F4(void *);
extern void ov14_021E83C4(void *);
extern void ov14_021E8610(void *);
extern void ov14_021E86E0(void *);
extern void ov14_021E8874(void *);
extern void ov14_021E82FC(void *);
extern void ov14_021E892C(void *);
extern u32 ov14_021E6070(void *, u32, u32, u32);
extern void *ov14_021E60C0(void *, u32, u32);
extern void *ov14_021E6094(void *, u32, u32, void *);
extern u32 ov14_021E64D0(void *);
extern u32 ov14_021E9554(void *);
extern void ov14_021EA1F0(void *);
extern void ov14_021F0B70(void *);
extern void ov14_021F0BB4(void *);
extern void ov14_021F3F6C(void *);
extern void ov14_021F4720(void *);
extern void ov14_021F4848(void *);
extern void ov14_021F48B4(void *);
extern void ov14_021F57B8(void *);
extern void ov14_021F5FBC(void *, u32);
extern void ov14_021F7AC4(void *, u32, u32);
extern s32 ov14_021F6A14(void);
extern s32 ov14_021F6F94(void *);
extern u32 ov14_021F1128(void *);
extern u32 ov14_021F028C(void *, u32);
extern u32 ov14_021F0314(void *, u32);
extern u32 ov14_021F2270(void *, u32, u32);
extern u32 ov14_021F2330(void *, u32, u32);
extern u32 ov14_021F039C(void *, u32);
extern u32 ov14_021F0530(void *, u32);
extern u32 ov14_021F0244(void *, u32);
extern u32 ov14_021F40E8(void *, u32);
extern void ov14_021F2ED0(void *, u32, u32, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F3844(void *, u32);
extern void ov14_021F396C(void *, u32, u32);
extern void ov14_021F39D0(void *);
extern void ov14_021F3B3C(void *);
extern u32 Bag_TakeItem(void *, u32, u32, u32);
extern void *GridInputHandler_GetDpadBox(void *, u32);
extern void DpadMenuBox_GetPosition(void *, u8 *, u8 *);
extern void ManagedSprite_SetPositionXY(void *, s32, s32);
extern void ov14_021F6844(void *, u32, u32);
extern void ov14_021F6AC0(void *, u32, u32);
extern s32 _s32_div_f(s32, s32);

u32 ov14_021EB290(void *);
u32 ov14_021EB2A8(void *);
void ov14_021EB2EC(void *);
u32 ov14_021EB388(void *);
u32 ov14_021EB7B0(void *);
void ov14_021EB7E4(void *);
void ov14_021EB8C0(void *);
void ov14_021EBAEC(void *);
void ov14_021EBB3C(void *);

#endif
