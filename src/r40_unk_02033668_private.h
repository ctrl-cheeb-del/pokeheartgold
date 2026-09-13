#ifndef POKEHEARTGOLD_UNK_02033668_PRIVATE_H
#define POKEHEARTGOLD_UNK_02033668_PRIVATE_H
#include "global.h"
typedef struct WirelessGlobal33668 {
    void *unk0;
    u8 *work;
} WirelessGlobal33668;
extern WirelessGlobal33668 _021D4124;
int sub_0203993C(void);
BOOL sub_020340C4(int value);
void sub_02033664(void);
int WM_SetLifeTime(void (*callback)(void), u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
void sub_02032844(int state);
BOOL sub_02032874(void);
BOOL sub_02032E9C(void);
BOOL sub_02033668(int mode, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5);
BOOL sub_0203373C(int mode, const void *data);
#endif
