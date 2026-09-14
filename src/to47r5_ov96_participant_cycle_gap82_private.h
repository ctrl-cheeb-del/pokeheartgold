#ifndef OV96_R82_GAP1_PRIVATE_H
#define OV96_R82_GAP1_PRIVATE_H

#include <nitro/code16.h>

#include "global.h"

#include "assert.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

u8 ov96_02200EF4(void *a, u8 *work, u16 c);
void ov96_02200F84(void *a, u8 *work, u8 index, u16 c);

#endif
