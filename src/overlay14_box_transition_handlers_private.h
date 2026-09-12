#ifndef POKEHEARTGOLD_OVERLAY14_BOX_TRANSITION_HANDLERS_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_TRANSITION_HANDLERS_PRIVATE_H
#include "global.h"
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021F34C8(void *, u32, u32);
extern u32 ov14_021E6480(void *, u32);
extern void PlaySE(u32);
extern void ov14_021F67B0(void *, u32, u32);
extern void ov14_021F685C(void *, u32, u32, u32);
extern void *Party_GetMonByIndex(void *, u32);
extern u32 GetMonData(void *, u32, void *);
extern u32 ItemIdIsMail(u32);
extern void ov14_021F43F4(void *, u32);
extern void *ov14_021E60C0(void *, u32, u32);
extern u32 GetBoxMonData(void *, u32, void *);
extern u32 ov14_021F0254(void *, u32);
extern void ov14_021E7278(void *);
extern u32 ov14_021F3380(void *);
extern void ov14_021F33E8(void *);
extern void ov14_021E7264(void *);
extern void ov14_021E6100(void *, u32, u32);
extern void ov14_021F6654(void *, u32);
extern void ov14_021E765C(void *);
extern void ov14_021F4958(void *, u32);
extern void ov14_021F4A20(void *, u32);
extern void ov14_021E8248(void *);
extern void ov14_021E82A8(void *);
extern void ov14_021E8328(void *);
extern void GridInputHandler_SetNextInput(void *, u32);
extern void GridInputHandler_SetButtonInputMode(void *, u32);
extern void ov14_021F08BC(void *);
extern u32 ov14_021F0234(void *, void *, u32);
extern void ov14_021F08F0(void *);
extern void ov14_021F57B8(void *);
extern void ov14_021E7588(void *, u32);
extern u32 ov14_021F33B0(void *);
extern void ov14_021F33FC(void *);
extern void ov14_021F3F6C(void *);
extern void ov14_021E8824(void *);
extern void ov14_021F40E8(void *, u32);
extern void ov14_021E9450(void);
extern void ov14_021E9194(void);
u32 ov14_021EBF9C(void *);
u32 ov14_021EC0EC(void *);
u32 ov14_021EC128(void *);
u32 ov14_021EC13C(void *);
u32 ov14_021EC150(void *);
u32 ov14_021EC23C(void *);
u32 ov14_021EC2A4(void *);
u32 ov14_021EC2EC(void *);
u32 ov14_021EC300(void *);
#endif
