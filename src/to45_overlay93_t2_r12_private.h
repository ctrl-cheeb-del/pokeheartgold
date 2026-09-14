#ifndef TO45_SOL_R4_OV93_R12_PRIVATE_H
#define TO45_SOL_R4_OV93_R12_PRIVATE_H

#include "global.h"

#include "math_util.h"
#include "sprite_system.h"

#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(ManagedSprite **)((u8 *)(p) + (o)))

extern const u8 ov93_02262CC4[];

void ov93_0226249C(void *sys, void *slot, void *sub);
u32 ov93_02261744(void *sys, void *work, void *slot);

#endif
