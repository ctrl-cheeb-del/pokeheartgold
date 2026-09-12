#ifndef TO37_OV49_R67_PRIVATE_H
#define TO37_OV49_R67_PRIVATE_H

#include <string.h>

#include "global.h"

#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

#pragma require_prototypes off

void *Heap_Alloc(u32, u32);
void *NARC_New(u32, u32);
void *ov49_02258D70(void *, u32);
s64 _ll_mul(s64, s64);

typedef struct Ov49Interpolation {
    s32 duration;
    s32 x;
    s32 y;
    s32 z;
    s32 deltaX;
    s32 startX;
    s32 deltaY;
    s32 startY;
    s32 deltaZ;
    s32 startZ;
} Ov49Interpolation;

#endif
