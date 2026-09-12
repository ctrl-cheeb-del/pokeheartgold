#ifndef POKEHEARTGOLD_OVERLAY14_BOX_INPUT_STATE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_INPUT_STATE_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern void GridInputHandler_SetButtonInputMode(void *, u32);
extern void GridInputHandler_SetNextInput(void *, u32);
extern u32 GridInputHandler_GetNextInput(void *);
extern void GridInputHandler_SetNextInput(void *, u32);
extern void *Party_GetMonByIndex(void *, u32);
extern u32 GetMonData(void *, u32, void *);
extern u32 ItemIdIsMail(u16);

extern void PlaySE(u32);
extern u32 ov14_021E6070(void *, u32, u32, u32);
extern u32 ov14_021E6480(void *, u32);
extern void ov14_021E637C(void *);
extern void ov14_021E6548(void *, u32, u32);
extern void ov14_021E7588(void *, u32);
extern void ov14_021E765C(void *);
extern void ov14_021E76B8(void *);
extern void ov14_021E7E98(void *);
extern void ov14_021E7EC0(void *);
extern void ov14_021E7EE0(void *);
extern void ov14_021E7F4C(void *);
extern void ov14_021E81A8(void *, u32);
extern void ov14_021E8248(void *);
extern void ov14_021E82A8(void *);
extern void ov14_021E8328(void *);
extern void ov14_021E8620(void *);
extern void ov14_021E94BC(void *);
extern u32 ov14_021E9518(void *);
extern u32 ov14_021F0234(void *, void *, u32);
extern void ov14_021F08F0(void *);
extern u32 ov14_021F0CD8(void *);
extern u32 ov14_021F1058(void *, u32);
extern void ov14_021F1580(void *, u32);
extern void ov14_021F2FDC(void *);
extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021F43F4(void *, u32);
extern void ov14_021F5C84(void *, u32);
extern void ov14_021F5E94(void *, u32);
extern void ov14_021F5EB4(void *, u32);
extern void ov14_021F5EC4(void *, u32);
extern void ov14_021F57B8(void *);
extern void ov14_021F63A8(void *);
extern void ov14_021F63B8(void *);
extern void ov14_021F63F0(void *);
extern void ov14_021F6408(void *, u32);
extern void ov14_021F6654(void *, u32);
extern void ov14_021F6688(void *, u32);
extern void ov14_021F67B0(void *, u32, u32);
extern void ov14_021F685C(void *, u32, u32, u32);
extern void ov14_021F6AC0(void *, u32, u32);

u32 ov14_021EC354(void *);
u32 ov14_021EC3A8(void *);
u32 ov14_021EC710(void *);
u32 ov14_021EC730(void *);
u32 ov14_021EC7D4(void *);
u32 ov14_021EC854(void *);
u32 ov14_021ECDA8(void *);
u32 ov14_021ED1AC(void *);
u32 ov14_021ED1E8(void *);
u32 ov14_021ED258(void *);

#endif
