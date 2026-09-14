#ifndef POKEHEARTGOLD_OVERLAY_81_RESIDUAL_2_HEAD_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_81_RESIDUAL_2_HEAD_PRIVATE_H

#include "global.h"

#define BIT(x, n) ((u32)(x) << (31 - (n)) >> 31)

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern void Pokepic_SetAttr(void *, int, int);
extern u32 Options_GetFrame(void *options);
extern void sub_020196E8(void *, int, int, int);

extern void ov81_02240F38(u8 *work, int value);
extern void *ov81_02243370(void *, void *);
extern void *ov81_02243398(void *, void *);
extern void ov81_0224185C(void *);
extern void ov81_02241A98(void *);
extern void ov81_02243228(void *, u32, u32 *, u32 *);
extern void ov81_02241C84(u32, u32, u32 *, u32 *);
extern void *ov81_02242D18(void *, int, int, int, int, int, int);
extern void *ov81_02242CBC(void *, int, int, int, int, int, int);
extern void ov81_02241D38(void *);
extern void ov81_02241F50(void *);
extern void ov81_02242058(void *, int);
extern void ov81_022420B4(void *);
extern void ov81_02242218(void *, void *, u32, int);
extern void ov81_022423D0(void *, void *);
extern void ov81_02242420(void *, int);
extern void ov81_022408C4(void *, void *, int, int, int);
extern void ov81_02243028(void *, u32);
extern int ov81_0224086C(void *, int);
extern void ov81_02242D94(void *, u32, u32);
extern void ov81_02240658(void *, int);
extern void ov81_0224174C(void *);
extern void ov81_022417B4(void *);
extern void ov81_02242E08(void *, int);
extern void ov81_022419E0(void *);
extern void *ov81_022412C4(void *, int);
extern void ov81_02242EB8(void *, int);
extern void ov81_02242F48(void *);
extern void ov81_02242FB0(void *, int);
extern void ov81_02242F94(void *, int);

void ov81_0223E8BC(u8 *p);
void ov81_0223EA98(u8 *p);
void ov81_0223EBE4(u8 *p);

#endif
