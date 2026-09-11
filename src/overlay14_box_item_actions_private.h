#ifndef OVERLAY14_BOX_ITEM_ACTIONS_PRIVATE_H
#define OVERLAY14_BOX_ITEM_ACTIONS_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    u8 lo : 1;
    u8 hi : 7;
} Bits17;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Bits44;

#define BF17(p, o) (*(Bits17 *)((u8 *)PTR_AT((p), 0x34) + (o)))
#define BF44(p, o) (*(Bits44 *)((u8 *)PTR_AT((p), 0x34) + (o)))
#define WQ8(p, o)  (*(u8 *)((u8 *)PTR_AT((p), 0x34) + (o)))
#define CELL(p)    PTR_AT(PTR_AT((p), 0x34), 0x2f0)

extern void PlaySE(u16);
extern void Heap_Free(void *);
extern void *Save_Bag_Get(void *);
extern u32 Bag_AddItem(void *, u16, u16, u32);
extern u32 GridInputHandler_GetNextInput(void *);
extern u32 GridInputHandler_IsButtonInputMode(void *);
extern void GridInputHandler_SetButtonInputMode(void *, u32);
extern void sub_02019B1C(void *, u32, s8 *, s8 *);
extern void sub_02019B44(void *, u32, u16 *, u16 *);
extern u8 sub_02019B10(void *, u32);

extern int ov14_021E6070(void *, int, int, int);
extern void *ov14_021E60C0(void *, int, int);
extern void ov14_021E6094(void *, int, int, void *);
extern u32 ov14_021E64D0(void *);
extern void ov14_021E71E8(void *);
extern u32 ov14_021E7588(void *, u32);
extern void ov14_021E75F4(void *, u32);
extern void ov14_021E76B8(void *);
extern void ov14_021E884C(void *);
extern void ov14_021E88F8(void *);
extern u32 ov14_021F0204(void *, u32);
extern u32 ov14_021F0244(void *, u32);
extern u32 ov14_021F0254(void *, u32);
extern void ov14_021F0AD8(void *);
extern void ov14_021F0C88(void *);
extern u32 ov14_021F1100(void *, u32);
extern u32 ov14_021F15C8(void *, u32);
extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F2ED0(void *, int, int, int);
extern void ov14_021F3354(void *);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021F391C(void *, u32);
extern u32 ov14_021F40DC(void *);
extern u32 ov14_021F40E8(void *, u32);
extern void ov14_021F43F4(void *, u32);
extern void ov14_021F6654(void *, u32);
extern void ov14_021F66E8(void *, int, int);
extern void ov14_021F673C(void *, int, int);
extern void ov14_021F675C(void *, int);
extern void ov14_021F685C(void *, u32, u32, u32);
extern void ov14_021F68C0(void *, u32, u32);
extern u32 ov14_021F7340(void *);
extern u32 ov14_021F7B7C(void *);

u32 ov14_021F1F44(void *p);
u32 ov14_021F2010(void *p);
u32 ov14_021F2020(void *p);
u32 ov14_021F20C4(void *p);
u32 ov14_021F20F4(void *p);
u32 ov14_021F21B4(void *p);
u32 ov14_021F21D0(void *p);
u32 ov14_021F2270(void *p, u32 a1, u32 a2);
u32 ov14_021F2330(void *p, u32 a1, u32 a2);
u32 ov14_021F23F0(void *p, u32 a1, u32 a2);
u32 ov14_021F2490(void *p, u32 a1, u32 a2);
void ov14_021F2534(void *p);
u32 ov14_021F2574(void *p);
u32 ov14_021F259C(void *p);
void ov14_021F25C4(void *p);
void ov14_021F25D4(void *p);
u32 ov14_021F25E4(void *p);

#endif
