#ifndef TO40_SOL_R38_OVERLAY92_R10_PRIVATE_H
#define TO40_SOL_R38_OVERLAY92_R10_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

void ov92_0225DDD8(void *p, u16 x, u16 y, u32 animation, u32 palette, u32 resourceId);

void ov92_0225E360(void *work);
ManagedSprite *ov92_0225E7E4(void *work, u16 x, u16 y);

#endif
