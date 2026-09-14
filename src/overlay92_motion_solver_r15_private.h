#ifndef TO45_OVERLAY92_R15_PRIVATE_H
#define TO45_OVERLAY92_R15_PRIVATE_H

#include "global.h"

#define F32_AT(p, o) (*(float *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) ((void *)((u8 *)(p) + (o)))

typedef struct Vec4f {
    float v[4];
} Vec4f;

typedef struct Ov92R15Work {
    u8 pad000[0x1f8];
    u32 counter;
    float x;
    float y;
    float deltaX;
    float deltaY;
} Ov92R15Work;

fx32 FX_Sqrt(fx32 x);
fx64c FX_SinFx64c(fx32 x);
fx64c FX_CosFx64c(fx32 x);
int ov92_02260628(void *arg);

#endif
