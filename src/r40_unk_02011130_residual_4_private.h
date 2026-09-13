#ifndef SOL_R40_UNK_02011130_RESIDUAL_4_PRIVATE_H
#define SOL_R40_UNK_02011130_RESIDUAL_4_PRIVATE_H

#include "global.h"

typedef struct CircleFadeWork {
    u8 padding00[0x0c];
    int center;
    int value;
    int radius;
} CircleFadeWork;

extern s16 *sub_02010EE0(void *work, int index);
extern u32 FX_Sqrt(u32 value);
void sub_02011A44(int diameter, int value, int a, int b, int *left, int *right);
void sub_02011AD8(CircleFadeWork *work);

#endif
