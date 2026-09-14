#ifndef TO45_OVERLAY02_RESIDUAL23_PRIVATE_H
#define TO45_OVERLAY02_RESIDUAL23_PRIVATE_H

#include "global.h"

#include "math_util.h"
#include "sprite.h"

#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern const VecFx32 ov02_02253354;
extern const VecFx32 ov02_0225336C;
extern const VecFx32 ov02_02253378;

void *sub_02068D74(void *);
void *ov02_0224B298(void *, void *);
void *ov01_021FCD2C(void *, int);
void ov01_021FCD8C(void *, int, fx32, int);
void ov02_0224B2C0(void *);
void ov02_0224B2CC(void *);
void ov02_0224B6B0(void *, int);
void sub_0205F484(void *);

void ov02_0224ADF0(void *);
int ov02_0224AF70(void *);
int ov02_0224B0E0(void *);
int ov02_0224B158(void *);

#endif
