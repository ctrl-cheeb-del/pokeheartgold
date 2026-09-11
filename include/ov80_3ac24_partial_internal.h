#ifndef PRIVATE_OV80_0223AC24_H
#define PRIVATE_OV80_0223AC24_H

#include "global.h"

typedef struct SysTask SysTask;
typedef struct Window Window;

typedef struct Ov80Fade {
    s32 value;
    s32 start;
    s32 delta;
    s32 step;
    s32 duration;
    s32 screen;
} Ov80Fade;

typedef struct Ov80Lerp {
    s32 value;
    s32 start;
    s32 delta;
    s32 step;
    s32 duration;
} Ov80Lerp;

typedef struct Ov80BoxAnim {
    Ov80Lerp x;
    Ov80Lerp y;
    Window *window;
    u8 width;
    u8 height;
    u8 active;
    u8 color;
} Ov80BoxAnim;

typedef void (*Ov80Callback)(void *);

typedef struct Ov80Row {
    u32 words[8];
} Ov80Row;

typedef struct Ov80TaskState {
    SysTask *vblankTask;
    SysTask *vwaitTask;
    u32 active;
    u32 pending;
    Ov80Callback start;
    Ov80Callback finish;
    void *arg;
    void *object;
    Ov80Row rows1[192];
    Ov80Row rows2[192];
    void *pixels;
} Ov80TaskState;

typedef struct Ov80RenderState {
    void *object;
    SysTask *task;
    u32 counter;
} Ov80RenderState;

typedef struct Ov80AsyncState {
    u32 state;
    u32 arg4;
    u32 iteration;
    u32 arg0;
    u32 arg1;
    u32 arg2;
    Ov80Fade fade1;
    Ov80Fade fade2;
    u32 *result;
} Ov80AsyncState;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
SysTask *SysTask_CreateOnVWaitQueue(void (*func)(SysTask *, void *), void *data, u32 priority);
SysTask *SysTask_CreateOnVBlankQueue(void (*func)(SysTask *, void *), void *data, u32 priority);
SysTask *SysTask_CreateOnMainQueue(void (*func)(SysTask *, void *), void *data, u32 priority);
void SysTask_Destroy(SysTask *task);
void GXx_SetMasterBrightness_(volatile u16 *reg, s32 brightness);
void FillWindowPixelRect(Window *window, u32 fill, u32 x, u32 y, u32 width, u32 height);
void *sub_02014AD8(void *arg);
void *sub_02014A08(u32 heapId, void *buf1, void *buf2);
void sub_02014A38(void *obj);
void sub_02014A4C(void *obj);
void *sub_02014A60(void *obj);
void sub_02014A8C(void *obj);
void sub_02014AA0(void);
void sub_02014AB0(void *obj, void *pixels, u32 size, u32 arg);
void sub_02014C08(void *obj);
void sub_02014C40(void *obj);
void sub_02014B08(void *obj, u32, u32, u32, u32, s16, u32, u32, u32);

#endif
