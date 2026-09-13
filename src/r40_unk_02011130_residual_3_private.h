#ifndef SOL_R40_UNK_02011130_RESIDUAL_3_PRIVATE_H
#define SOL_R40_UNK_02011130_RESIDUAL_3_PRIVATE_H

#include "global.h"

#include "sys_task_api.h"

typedef struct LocalFadeParam {
    s16 start;
    s16 end;
    s16 initial;
    s16 increment;
    u8 direction;
    u8 x;
    u8 y;
    u8 value;
} LocalFadeParam;

typedef struct LocalFadeEffect {
    u8 allocationList[0xC];
    int current;
    int initial;
    int increment;
    int step;
    int repeats;
    int delay;
    int counter;
    u32 heapId;
    u32 value;
    u32 arg5;
    u32 arg6;
} LocalFadeEffect;

int sub_02010A6C(int start, int end, int divisor);
void sub_02010E64(void *, int, u32, u32);
void sub_02011AD8(void *);
void sub_02010F00(SysTask *, void *);
s16 *sub_02010EE0(void *, int);
void sub_02010F84(u32, u8, u8, int, u32, int, int, int, int, u32);
void sub_02011068(u32, int, u32, u32);
void sub_02010C38(void);
void sub_0200FF88(u32, void *, void (*)(void), u32, u32);
void sub_02011918(LocalFadeEffect *, const LocalFadeParam *, u32, u32, u32, u32, u32, u32);

#endif
