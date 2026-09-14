#ifndef TO45_OVERLAY28_GAP07_PRIVATE_H
#define TO45_OVERLAY28_GAP07_PRIVATE_H

#include "global.h"

#include "sprite.h"

typedef struct To45Ov28Angle {
    u32 previous;
    u32 target;
    u32 current;
} To45Ov28Angle;

typedef struct To45Ov28Work {
    u8 pad_000[0x190];
    Sprite *sprites[4];
    u8 pad_1A0[0x68];
    s16 x;
    s16 y;
    s32 detected;
    s32 mode;
    s32 centerX;
    s32 centerY;
    To45Ov28Angle angles[4];
    u16 value : 15;
    u16 flag : 1;
    s16 counter;
} To45Ov28Work;

extern const u8 ov28_0225EA90[];

u16 ov28_0225DE78(s32 x, s32 y);
u16 ov28_0225DE88(u16 angle);
void ov28_0225E0F4(To45Ov28Work *work);
void ov28_0225E374(To45Ov28Work *work, u16 *first, u16 *second);
void ov28_0225E3BC(To45Ov28Work *work);

#endif
