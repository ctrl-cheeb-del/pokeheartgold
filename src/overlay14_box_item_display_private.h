#ifndef POKEHEARTGOLD_OVERLAY14_BOX_ITEM_DISPLAY_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_ITEM_DISPLAY_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern u32 ov14_021F5404(void *, void *);
extern void sub_02019A60(void *, u32, void *);
extern void ov14_021E88A4(void *);
extern void ov14_021E8944(void *);
extern void ov14_021F36DC(void *, void *, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F3D70(void *, void *);
extern void ov14_021F5368(void *, void *);
extern void ov14_021E895C(void *, u32);
extern u32 ov14_021F5564(void *, u32);
extern void ov14_021F38B0(void *, u32);
extern void *ov14_021E60C0(void *, u32, u32);
extern u32 AcquireBoxMonLock(void *);
extern void *ov14_021E7358(void *);
extern void ov14_021E7468(void *);
extern u32 ReleaseBoxMonLock(void *, u32);
extern void ov14_021F53C0(void *);

void ov14_021E7470(void *, void *);
void ov14_021E74F0(void *, void *);
BOOL ov14_021E7588(void *, u32);
void ov14_021E75F4(void *, u32);
void ov14_021E765C(void *);

#endif
