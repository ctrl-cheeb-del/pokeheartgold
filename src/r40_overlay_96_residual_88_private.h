#ifndef OVERLAY96_R40_RESIDUAL88_PRIVATE_H
#define OVERLAY96_R40_RESIDUAL88_PRIVATE_H

#include "global.h"

typedef struct Ov96AnimRecordR40 {
    u32 unk0;
    s32 value;
} Ov96AnimRecordR40;

#define R40_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

#endif
