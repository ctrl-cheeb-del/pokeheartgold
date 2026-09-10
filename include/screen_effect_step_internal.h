#ifndef POKEHEARTGOLD_SCREEN_EFFECT_STEP_INTERNAL_H
#define POKEHEARTGOLD_SCREEN_EFFECT_STEP_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "sys_task_api.h"

typedef struct {
    s16 x;
    s16 y;
    u32 threshold;
    u8 direction;
    u8 a;
    u8 b;
    u8 value;
} EffectConfig;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    s32 x;
    s32 y;
    s32 phase;
    s32 threshold;
    s32 current;
    s32 step;
    s32 steps;
    s32 interval;
    s32 counter;
    void *unk30;
    u32 value;
    u32 direction;
    u32 arg4;
    u32 armed;
    void *arg5;
    void *arg6;
} EffectWork;

typedef struct {
    u8 value;
} ByteRegister;

extern void sub_02010E64(void *, u8, u32, u32);
extern void *sub_02010EE0(void *, u32);
extern void sub_02010F00(SysTask *, void *);
extern void sub_02010C38(void);
extern void sub_02010F84(void *, u8, u8, u8, u32, s32, s32, s32, s32, u32);
extern void sub_02011068(void *, u32, u32, u32);
extern void sub_0200FF88(void *, u32, u32, u32, enum HeapID);
extern void sub_020131AC(void *);

void sub_02013004(s32 unused, s32 color, s32 centerY, s32 sampleY, s32 angle1, s32 angle2, s32 *out1, s32 *out2);
s8 sub_0201333C(BOOL screen);
void sub_02012E6C(EffectWork *work, const EffectConfig *config, s32 steps, s32 interval, u32 arg4, void *arg5, void *arg6, void *arg7);

#endif
