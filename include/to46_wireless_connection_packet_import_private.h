#ifndef UNK_02034C20_PRIVATE_H
#define UNK_02034C20_PRIVATE_H

#include "global.h"

typedef struct Work34C20 {
    u8 padding000[0x54];
    u8 packet[0xC0];
    u8 records[16][0xC0];
    u8 paddingD14[0x30];
    u16 slots[16];
    u8 paddingD64[0x10];
    u8 changed;
    u8 paddingD75[0x20];
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 flag2 : 1;
    u8 flag3 : 1;
    u8 flag4 : 1;
    u8 flag5 : 1;
    u8 pending : 1;
    u8 flag7 : 1;
} Work34C20;

typedef struct NetworkState34C20 {
    u16 localId;
    u16 padding02;
    int state;
    Work34C20 *work;
} NetworkState34C20;

extern NetworkState34C20 _021D4134;
int sub_0203993C(void);
int sub_02039954(void);
BOOL sub_0203401C(int value);
BOOL sub_02034BF8(const u8 *a, const u8 *b, int size);
void MI_CpuCopy8(const void *src, void *dst, u32 size);

void sub_02034C20(u8 *data);
void sub_02034C94(void);

#endif
