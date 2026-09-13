#ifndef OV48_RESIDUAL27_PRIVATE_H
#define OV48_RESIDUAL27_PRIVATE_H

#include "global.h"

typedef struct Ov48R27Motion {
    s16 x;
    s16 y;
    s16 step;
    s16 angle;
    u16 wrapX;
    u16 wrapY;
    const s16 *bounds;
} Ov48R27Motion;

void ov48_0225AFB4(Ov48R27Motion *motion, void *target);
void ov48_0225AEDC(Ov48R27Motion *motion);
void ov48_0225B010(u8 *work, u32 index);

#endif
