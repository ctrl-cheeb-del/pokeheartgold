#ifndef POKEHEARTGOLD_OVERLAY14_BOX_NAVIGATION_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_NAVIGATION_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F5EB4(void *, u32);
extern void ov14_021E8328(void *);
extern void ov14_021E8248(void *);
extern void ov14_021E82A8(void *);
extern void ov14_021F6AC0(void *, u32, u32);
extern u32 ov14_021F0234(void *, void *, u32);
extern u32 ov14_021E7930(void *, u32);
extern void ov14_021F4428(void *);
extern void ov14_021F4530(void *);
extern void ov14_021F459C(void *);
extern void ov14_021F58B8(void *);
extern void ov14_021E87BC(void *);
extern void ov14_021E81B4(void *);
extern void ov14_021F6094(void *);
extern void ov14_021E8560(void *);
extern void ov14_021F6844(void *, u32, u32);
extern int GridInputHandler_HandleInput_AllowHold(void *);
extern void PlaySE(u32);
extern void ov14_021F129C(void *, u32);
extern void ov14_021F1228(void *, s32);
extern u32 ov14_021F131C(void *);
extern u32 ov14_021F0244(void *, u32);
extern u32 ov14_021F2270(void *, u32, u32);
extern void ov14_021E8588(void *);
extern void ov14_021E81D8(void *);

extern void ov14_021E95B4(void);
extern void ov14_021E94BC(void);
extern void ov14_021E9660(void);
extern void ov14_021E95C8(void);
extern void ov14_021E9604(void);
extern void ov14_021E96A8(void);

u32 ov14_021ED6D0(void *);
u32 ov14_021ED760(void *);
u32 ov14_021ED7B8(void *);
u32 ov14_021ED7DC(void *);
u32 ov14_021ED820(void *);
u32 ov14_021ED920(void *);
u32 ov14_021ED940(void *);

#endif
