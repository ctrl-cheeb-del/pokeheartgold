#ifndef WIRELESS_CONNECT_TICK_R40_PRIVATE_H
#define WIRELESS_CONNECT_TICK_R40_PRIVATE_H
#include "global.h"
typedef struct NetworkState {
    u16 localId;
    u16 pad;
    int state;
    u8 *work;
} NetworkState;
extern NetworkState _021D4134;
int sub_02033298(int);
int sub_020347CC(void);
void sub_020353B8(void);
int sub_020338F4(void);
int sub_0203567C(void);
u32 sub_020332AC(void);
void sub_020399DC(u32);
void sub_020350D4(void);
int sub_020338D0(void);
u16 sub_02033468(void);
u16 WM_GetNextTgid(void);
void sub_020352D8(void);
int sub_0203993C(void);
int sub_02033FC4(u16);
u32 sub_02035724(u32);
BOOL sub_02033668(int, u16, u16, int, u32, u32);
void sub_0203540C(int, u8 *);
#endif
