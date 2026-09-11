#ifndef TO30_SOL_R5_UNK_02012204_PRIVATE_H
#define TO30_SOL_R5_UNK_02012204_PRIVATE_H

#include "global.h"

#include "heap.h"
#include "sys_task_api.h"

typedef struct AllocationList {
    void *allocation;
    int count;
} AllocationList;

typedef struct VectorRecord {
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 copy[4];
    u8 padding20[0x10];
} VectorRecord;

typedef struct VectorListWork {
    u8 padding00[0xC];
    VectorRecord *vectors;
    int count;
} VectorListWork;

typedef struct FadeWork {
    u8 padding00[4];
    u32 arg2;
    u32 arg3;
    u32 state;
    u32 arg10;
    void *allocation;
    void *arg18;
    void *arg1C;
    enum HeapID heapId;
} FadeWork;

typedef struct ShortVector4 {
    u16 start;
    u16 end;
    u8 a;
    u8 b;
    u16 value;
} ShortVector4;

typedef struct Interpolation {
    s32 value;
    s32 start;
    s32 delta;
} Interpolation;

typedef struct EffectWork {
    u8 padding00[8];
    u32 screen;
    Interpolation interp;
    s32 steps;
    s32 currentStep;
    s32 interval;
    s32 counter;
    u32 value;
    enum HeapID heapId;
    void *arg5;
    void *arg6;
} EffectWork;

void *sub_02010EE0(void *, int);
void sub_02010A8C(void *, const void *);
void sub_02010EC8(void *);
void sub_02010E64(void *, int, u32, u32);
void sub_02010F00(SysTask *, void *);
void sub_02010C38(void);
void sub_02010F34(u32, void *, int);
void sub_02010F84(void *, u8, u8, u32, u32, s32, s32, s32, s32, u32);
void sub_02011068(void *, int, u32, u32);
void sub_0200FF88(void *, u32, u32, u32, enum HeapID);
void sub_0200FFB4(void *, int, enum HeapID);
void sub_020124AC(void *);
void sub_020124B0(EffectWork *);
void sub_020125D4(Interpolation *, int, int);

void sub_02012204(VectorListWork *);
void sub_02012238(VectorListWork *, VectorRecord *);
void sub_02012290(VectorListWork *);
void sub_020122B8(FadeWork *, const ShortVector4 *);
BOOL sub_020122F8(FadeWork *);
void sub_02012358(EffectWork *, const ShortVector4 *, u32, u32, u32, void *, void *, enum HeapID);
BOOL sub_02012454(EffectWork *);

#endif
