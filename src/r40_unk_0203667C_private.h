#ifndef POKEHEARTGOLD_UNK_0203667C_PRIVATE_H
#define POKEHEARTGOLD_UNK_0203667C_PRIVATE_H
#include "global.h"
typedef struct CommManager3667C {
    u8 initialized;
    u8 updateLock;
    u8 pad02[2];
    void *allocation;
    u8 *work;
} CommManager3667C;
extern CommManager3667C _021D4140;
extern u8 _0210F900[2];
int sub_0203993C(void);
int sub_02033FC4(u16 value);
int sub_02034044(int value);
int sub_020373B4(u16 slot);
BOOL sub_02036630(void);
int sub_02035FF0(void);
BOOL sub_02036438(int slot);
BOOL ov00_021E602C(void *data, int size);
int sub_02033298(void);
void sub_02036F30(u8 *packet);
void sub_02036508(void);
void sub_0203667C(void);
#endif
