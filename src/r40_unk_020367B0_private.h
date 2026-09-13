#ifndef POKEHEARTGOLD_R40_UNK_020367B0_PRIVATE_H
#define POKEHEARTGOLD_R40_UNK_020367B0_PRIVATE_H
#include "global.h"
typedef struct R40CommGlobal367 {
    u8 initialized;
    u8 updateLock;
    u8 pad02[2];
    void *allocation;
    u8 *work;
} R40CommGlobal367;
extern R40CommGlobal367 _021D4140;
int sub_02035FF0(void);
int sub_0203993C(void);
int sub_0203772C(u16);
int sub_02033FC4(u16);
void sub_02033AF0(void *ring, const void *data, int count, int tag);
void sub_020367B0(int unused, const u8 *data);
#endif
