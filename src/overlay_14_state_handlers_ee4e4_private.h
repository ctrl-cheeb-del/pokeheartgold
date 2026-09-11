#ifndef OVERLAY_14_STATE_HANDLERS_EE4E4_PRIVATE_H
#define OVERLAY_14_STATE_HANDLERS_EE4E4_PRIVATE_H

#include "global.h"

#include "system.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

u32 ov14_021EE5E8(void *p);
u32 ov14_021EE684(void *p);
u32 ov14_021EE728(void *p);
u32 ov14_021EEC9C(void *p);
u32 ov14_021EEE94(void *p);
u32 ov14_021EEED4(void *p);
u32 ov14_021EEF34(void *p);
u32 ov14_021EF190(void *p);
u32 ov14_021EF1EC(void *p);
u32 ov14_021EF8AC(void *p);
u32 ov14_021EF920(void *p);
u32 ov14_021F00BC(void *p);
u32 ov14_021F0120(void *p);
u32 ov14_021F0164(void *p);
u32 ov14_021F01D8(void *p, u32 v);
u32 ov14_021F0204(void *p, u32 v);

extern void Heap_Free(void *);
extern void PlaySE(u32);
extern u32 PCStorage_CountMonsAndEggsInBox(void *, u32);
extern void GridInputHandler_SetButtonInputMode(void *, u32);

extern u32 ov14_021F0234(void *, void *, u32);
extern void ov14_021F685C(void *, u32, u32, u32);
extern void ov14_021F4CA0(void *);
extern void ov14_021F6AC0(void *, u32, u32);
extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F3F6C(void *);
extern void ov14_021F40E8(void *, u32);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021E8588(void *);
extern void ov14_021E8314(void *);
extern void ov14_021E8048(void *);
extern void ov14_021E8328(void *);
extern void ov14_021E88F8(void *);
extern void ov14_021F6654(void *, u32);
extern void ov14_021F08BC(void *);
extern void ov14_021F5EB4(void *, u32);
extern u32 ov14_021E7588(void *, u32);
extern void ov14_021F40DC(void *);
extern void ov14_021F68C0(void *, u32, u32);
extern void ov14_021F6724(void *, u32);

extern void ov14_021E98AC(void *);
extern void ov14_021E99F0(void *);
extern void ov14_021E952C(void *);
extern void ov14_021E9234(void *);
extern void ov14_021E95B4(void *);

extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern void GridInputHandler_SetNextInput(void *, u32);
extern void *GridInputHandler_GetDpadBox(void *, u32);
extern void DpadMenuBox_GetPosition(const void *, u8 *, u8 *);
extern void ManagedSprite_SetPositionXY(void *, s32, s32);
extern void sub_020197F4(void *, u32);
extern void ov14_021F6688(void *, u32);
extern u32 ov14_021F2A04(void *, u32);
extern void ov14_021F391C(void *, u32);
extern void ov14_021F34C8(void *, u32, u32);
extern void ov14_021F6768(void *, u32, u32);
extern void ov14_021F1F38(void *);
extern void ov14_021E637C(void *);
extern void ov14_021E6548(void *, u32, u32);
extern void ov14_021F08F0(void *);
extern void ov14_021E8094(void *);
extern void ov14_021E8248(void *);
extern void ov14_021E82A8(void *);
extern void ov14_021E954C(void *);
extern void ov14_021E94BC(void *);

extern u32 ItemIdIsMail(u32);
extern void ov14_021F6730(void *, u32);
extern void ov14_021F2DE8(void *, u32);
extern u32 ov14_021E7930(void *, u32);
extern void ov14_021E783C(void *, u32, u32);
extern void ov14_021E92AC(void *);
extern void ov14_021E9370(void *);

extern void ov14_021F6678(void *, u32);
extern u32 ov14_021F0254(void *, u32);

/* --- round 3 additions (this worker) --- */
extern u32 ov14_021F6A14(void); /* zero-arg: called with no r0 setup */
extern u32 ov14_021F6A34(void); /* zero-arg */
extern u32 ov14_021F74B0(void *);
extern u32 ov14_021F70C0(void *);
extern u32 ov14_021F7A50(void *);
extern u32 ov14_021F7B7C(void *);
/* CORRECTION: the shared internal header declares ov14_021F7AC4 as 1-arg;
   this object calls it with three (work, slot, input). */
extern void ov14_021F7AC4(void *, u32, u32);
extern u32 ov14_021E8544(void *);
extern u32 ov14_021E85E4(void *);
extern u32 ov14_021E8648(void *);
extern void ov14_021E84A4(void *);
extern void ov14_021E8620(void *);
extern void ov14_021E8634(void *);
extern void ov14_021EA674(void *);
extern u32 ov14_021F18B0(void *, u32);
extern u32 ov14_021F1808(void *, u32);
extern u32 ov14_021F19F0(void *, u32);
extern u32 ov14_021F1B4C(void *, u32);
extern u32 ov14_021F1C4C(void *, u32);
extern u32 ov14_021F1128(void *);
extern void ov14_021F1004(void *, s32);
extern u32 ov14_021F028C(void *, u32);
extern u32 ov14_021F0314(void *, u32);
extern u32 ov14_021F0D34(void *, u32);
extern u32 ov14_021F0D58(void *, u32);
extern u32 ov14_021F0EE8(void *, u32);
extern u32 ov14_021F0244(void *, u32);
extern u32 ov14_021F2330(void *, u32, u32);
extern u32 ov14_021F2490(void *, u32, u32);
extern u32 ov14_021F2270(void *, u32, u32);
extern void ov14_021F6408(void *, u32);
extern void ov14_021F40DC(void *);
extern int ov14_021E6070(void *, int, int, int);

extern u32 GridInputHandler_IsButtonInputMode(void *);
extern u32 GridInputHandler_GetNextInput(void *);
extern void ov14_021E765C(void *);
extern void ov14_021E76B8(void *);

extern BOOL System_GetTouchNewCoords(u32 *x, u32 *y);

extern u32 ov14_021F2A44(void *, u32);
extern void ov14_021F5FBC(void *, u32);
extern void sub_0201980C(void *, u32);
extern void ov14_021E9450(void *);

extern int ov14_021E6094(void *, int, int, void *);
extern void ov14_021E60C0(void *, u32, u32);
extern u32 ov14_021E64D0(void);
extern void ov14_021F2ED0(void *, u32, u32, u32);
extern void ov14_021F3844(void *, u32);
extern void ov14_021F39D0(void *);
extern u32 sub_020199E4(void *, u32);
extern void ov14_021EA728(void *);
extern void ov14_021EA928(void *);

extern void ov14_021F39A0(void *, u32, u32);
extern u32 ov14_021F5564(void *, u32);
extern void sub_02019A60(void *, u32, void *);
extern void ov14_021F38B0(void *, u32);
extern void ov14_021E88BC(void *);
extern void ov14_021E7EE0(void *);
extern void ov14_021E9970(void *);
extern void ov14_021EAA04(void *);
extern void ov14_021E9518(void *);
extern void ov14_021EAF08(void *);
extern u32 ov14_021F6A24(void);
extern u32 ov14_021F75C8(void *);
extern u32 ov14_021F1D6C(void *, u32);
extern u32 ov14_021F1CDC(void *, u32);

#endif
