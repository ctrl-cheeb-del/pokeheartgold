#ifndef OV14_R12_PRIVATE_H
#define OV14_R12_PRIVATE_H
#include "global.h"
#define P8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define P32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PP(p, o)  (*(void **)((u8 *)(p) + (o)))
extern void sub_020196E8(void *, u32, u32, u32);
extern void sub_020198FC(void *, s32, s32, s32, u8);
extern void sub_02019B1C(void *, u32, s8 *, s8 *);
extern u32 sub_02019978(void *, u32);
extern void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
extern void ov14_021E7D9C(void *, u32);
extern void ov14_021F32E0(void *);
void ov14_021E7E10(void *, u32);
void ov14_021E7E40(void *);
void ov14_021E7E64(void *);
void ov14_021E7E78(void *);
void ov14_021E7E88(void *);
void ov14_021E7E98(void *);
void ov14_021E7EC0(void *);
void ov14_021E7ED0(void *);
void ov14_021E7EE0(void *);
void ov14_021E7F4C(void *);
void ov14_021E7FB8(void *);
void ov14_021E7FEC(void *);
void ov14_021E8020(void *);
void ov14_021E8048(void *);
void ov14_021E805C(void *);
void ov14_021E8094(void *);
u32 ov14_021E80A8(void *);
u32 ov14_021E813C(void *);
#endif
