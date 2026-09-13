#ifndef SOL_R40_UNK_02037334_PRIVATE_H
#define SOL_R40_UNK_02037334_PRIVATE_H

#include "global.h"

typedef struct CommManager37334 {
    u8 pad00[8];
    u8 *work;
} CommManager37334;

extern CommManager37334 _021D4140;
int sub_0203993C(void);
int sub_02033FC4(u16 mode);
void sub_02033C28(void *ring);
int sub_02033BC4(void *ring);
void sub_020371C4(void *ring, int index, void *buffer, void *dest);
void sub_02037334(void);

#endif
