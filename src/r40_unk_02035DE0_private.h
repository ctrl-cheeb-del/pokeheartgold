#ifndef SOL_R40_UNK_02035DE0_PRIVATE_H
#define SOL_R40_UNK_02035DE0_PRIVATE_H

#include "global.h"

#include "communication_manager_internal.h"

typedef struct LocalByteRing {
    u8 *data;
    s16 read;
    s16 limit;
    s16 write;
    s16 capacity;
} LocalByteRing;

void sub_02033AE0();
int _s32_div_f(int numerator, int denominator);
void sub_02035DE0(int slot);

#endif
