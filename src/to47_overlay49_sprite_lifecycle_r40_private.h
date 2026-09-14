#ifndef TO47_OVERLAY49_SPRITE_LIFECYCLE_R40_PRIVATE_H
#define TO47_OVERLAY49_SPRITE_LIFECYCLE_R40_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

typedef struct Ov49PositionR40 {
    s16 x;
    s16 y;
} Ov49PositionR40;

void *ov49_0225DBF8(void *);
void ov49_0225D1C4(void *, Ov49PositionR40);

#endif
