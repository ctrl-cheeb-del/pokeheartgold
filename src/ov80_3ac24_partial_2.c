#include "ov80_3ac24_partial_internal.h"

void ov80_0223AC24(u32 arg0, u32 arg1, u32 arg2, u32 *result, u32 arg4);
void ov80_0223AC68(SysTask *task, void *data);
void ov80_0223AD5C(u32 screen, s32 brightness);
void ov80_0223AD7C(Ov80Fade *fade, s32 start, s32 end, s32 screen, s32 duration);
BOOL ov80_0223AD88(Ov80Fade *fade);
void ov80_0223ADA4(SysTask *task, void *data);
void ov80_0223ADB8(Ov80Fade *fade, s32 start, s32 end, s32 duration);
BOOL ov80_0223ADC8(Ov80Fade *fade);
Ov80BoxAnim *ov80_0223ADF4(u32 heapId);
void ov80_0223AE0C(Ov80BoxAnim *anim);
void ov80_0223AE14(Ov80BoxAnim *anim, s32 x0, s32 x1, s32 y0, s32 y1, s32 duration, Window *window, u32 width, u32 height, u8 color);
BOOL ov80_0223AE6C(Ov80BoxAnim *anim);
void ov80_0223AED4(Window *window, s32 left, s32 bottom, s32 top, s32 right, u8 color);
void **ov80_0223AF30(u32 heapId);
void ov80_0223AF60(void **pool);
void ov80_0223AF80(void *data, u8 arg1, u8 arg2, void *arg3, u8 arg4);
void ov80_0223AFC4(void);
void ov80_0223B1D4(void);
SysTask *ov80_0223B3EC(void *data);
void ov80_0223B400(SysTask *task, void *data);
void ov80_0223B424(Ov80RenderState *state, void *arg);
void ov80_0223B440(Ov80RenderState *state, u32, u32, u32, u32, s16, u32, u32, u32);
void ov80_0223B468(SysTask *task, void *data);
void ov80_0223B484(SysTask *task, void *data);
void ov80_0223B4A0(Ov80TaskState *state, void *arg, Ov80Callback start, Ov80Callback finish);
void ov80_0223B4E0(Ov80TaskState *state);
void ov80_0223B504(Ov80TaskState *state);
void ov80_0223B528(Ov80TaskState *state);
void ov80_0223B53C(Ov80TaskState *state);
Ov80TaskState *ov80_0223B544(void *pixels, const Ov80Row *rows, u32 heapId);
void ov80_0223B5E8(Ov80TaskState *state);
void ov80_0223B60C(Ov80TaskState *state);

SysTask *ov80_0223B3EC(void *data) {
    return SysTask_CreateOnVBlankQueue(ov80_0223B400, data, 1024);
}

void ov80_0223B400(SysTask *task, void *data) {
    Ov80RenderState *state = data;
    if (state->counter >= 2) {
        sub_02014C08(state->object);
        state->counter = 0;
    }
    sub_02014C40(state->object);
    state->counter++;
}

void ov80_0223B424(Ov80RenderState *state, void *arg) {
    state->object = sub_02014AD8(arg);
    state->counter = 0;
    state->task = ov80_0223B3EC(state);
}

void ov80_0223B440(Ov80RenderState *state, u32 a1, u32 a2, u32 a3, u32 a4, s16 a5, u32 a6, u32 a7, u32 a8) {
    sub_02014B08(state->object, a1, a2, a3, a4, a5, a6, a7, a8);
}

void ov80_0223B468(SysTask *task, void *data) {
    Ov80TaskState *state = data;
    if (state->active != 0) {
        state->pending = 1;
        state->start(state->arg);
    } else {
        sub_02014AA0();
    }
}

void ov80_0223B484(SysTask *task, void *data) {
    Ov80TaskState *state = data;
    if (state->active != 0 && state->pending != 0) {
        state->finish(state->arg);
        state->pending = 0;
    }
}

void ov80_0223B4A0(Ov80TaskState *state, void *arg, Ov80Callback start, Ov80Callback finish) {
    GF_ASSERT(state != NULL);
    state->active = 1;
    state->pending = 0;
    state->arg = arg;
    state->start = start;
    state->finish = finish;
    state->vwaitTask = SysTask_CreateOnVWaitQueue(ov80_0223B468, state, 0);
    state->vblankTask = SysTask_CreateOnVBlankQueue(ov80_0223B484, state, 0);
}

void ov80_0223B4E0(Ov80TaskState *state) {
    GF_ASSERT(state != NULL);
    if (state->vwaitTask != NULL) {
        SysTask_Destroy(state->vwaitTask);
    }
    if (state->vblankTask != NULL) {
        SysTask_Destroy(state->vblankTask);
    }
    sub_02014AA0();
}

void ov80_0223B504(Ov80TaskState *state) {
    void *obj = sub_02014A60(state->object);
    sub_02014AA0();
    sub_02014AB0(obj, state->pixels, 0x20, 1);
}

void ov80_0223B528(Ov80TaskState *state) {
    sub_02014A8C(state->object);
    ov80_0223B504(state);
}

void ov80_0223B53C(Ov80TaskState *state) {
    ov80_0223B504(state);
}

Ov80TaskState *ov80_0223B544(void *pixels, const Ov80Row *rows, u32 heapId) {
    Ov80TaskState *state = Heap_Alloc(heapId, sizeof(Ov80TaskState));
    int i;
    memset(state, 0, sizeof(Ov80TaskState));
    GF_ASSERT(state != NULL);
    state->object = sub_02014A08(heapId, state->rows1, state->rows2);
    GF_ASSERT(state->object != NULL);
    state->pixels = pixels;
    for (i = 0; i < 192; i++) {
        state->rows1[i] = *rows;
        state->rows2[i] = *rows;
    }
    ov80_0223B4A0(state, state, (Ov80Callback)ov80_0223B528, (Ov80Callback)ov80_0223B53C);
    return state;
}

void ov80_0223B5E8(Ov80TaskState *state) {
    GF_ASSERT(state != NULL);
    ov80_0223B4E0(state);
    if (state->object != NULL) {
        sub_02014A38(state->object);
    }
    Heap_Free(state);
}

void ov80_0223B60C(Ov80TaskState *state) {
    GF_ASSERT(state != NULL);
    sub_02014A4C(state->object);
}
