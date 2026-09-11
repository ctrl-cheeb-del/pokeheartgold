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

void ov80_0223AC24(u32 arg0, u32 arg1, u32 arg2, u32 *result, u32 arg4) {
    Ov80AsyncState *state = Heap_Alloc(11, sizeof(Ov80AsyncState));
    memset(state, 0, sizeof(Ov80AsyncState));
    SysTask_CreateOnMainQueue(ov80_0223AC68, state, 5);
    state->result = result;
    if (result != NULL) {
        *result = 0;
    }
    state->arg0 = arg0;
    state->arg1 = arg1;
    state->arg2 = arg2;
    state->arg4 = arg4;
}

void ov80_0223AC68(SysTask *task, void *data) {
    Ov80AsyncState *state = data;
    switch (state->state) {
    case 0:
        if (state->arg0 == 1) {
            ov80_0223AD7C(&state->fade2, 0, state->arg2, 2, 8);
        } else if (state->arg0 == 2) {
            ov80_0223AD7C(&state->fade2, 0, state->arg2, 1, 8);
        }
        state->state++;
        break;
    case 1:
        ov80_0223AD7C(&state->fade1, 0, state->arg1, state->arg0, 3);
        state->state++;
        break;
    case 2:
        if (ov80_0223AD88(&state->fade1)) {
            state->state++;
        }
        break;
    case 3:
        ov80_0223AD7C(&state->fade1, state->arg1, 0, state->arg0, 3);
        state->state++;
        break;
    case 4:
        if (ov80_0223AD88(&state->fade1)) {
            state->iteration++;
            if (state->iteration == state->arg4) {
                state->state = 5;
            } else {
                state->state = 1;
            }
        }
        break;
    case 5:
        state->state = 0;
        state->iteration = 0;
        if (state->result != NULL) {
            *state->result = 1;
        }
        SysTask_Destroy(task);
        Heap_Free(state);
        return;
    }
    ov80_0223AD88(&state->fade2);
}

void ov80_0223AD5C(u32 screen, s32 brightness) {
    if (screen == 1) {
        GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, brightness);
    } else {
        GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, brightness);
    }
}

void ov80_0223AD7C(Ov80Fade *fade, s32 start, s32 end, s32 screen, s32 duration) {
    fade->screen = screen;
    ov80_0223ADB8(fade, start, end, duration);
}

BOOL ov80_0223AD88(Ov80Fade *fade) {
    BOOL result = ov80_0223ADC8(fade);
    SysTask_CreateOnVWaitQueue(ov80_0223ADA4, fade, 10);
    return result;
}

void ov80_0223ADA4(SysTask *task, void *data) {
    Ov80Fade *fade = data;
    ov80_0223AD5C(fade->screen, fade->value);
    SysTask_Destroy(task);
}

void ov80_0223ADB8(Ov80Fade *fade, s32 start, s32 end, s32 duration) {
    fade->value = start;
    fade->start = start;
    fade->delta = end - start;
    fade->duration = duration;
    fade->step = 0;
}

BOOL ov80_0223ADC8(Ov80Fade *fade) {
    s32 value = fade->delta * fade->step / fade->duration;
    value += fade->start;
    fade->value = value;
    if (fade->step + 1 <= fade->duration) {
        fade->step++;
        return FALSE;
    }
    fade->step = fade->duration;
    return TRUE;
}

Ov80BoxAnim *ov80_0223ADF4(u32 heapId) {
    Ov80BoxAnim *anim = Heap_Alloc(heapId, sizeof(Ov80BoxAnim));
    memset(anim, 0, sizeof(Ov80BoxAnim));
    return anim;
}

void ov80_0223AE0C(Ov80BoxAnim *anim) {
    Heap_Free(anim);
}

void ov80_0223AE14(Ov80BoxAnim *anim, s32 x0, s32 x1, s32 y0, s32 y1, s32 duration, Window *window, u32 width, u32 height, u8 color) {
    GF_ASSERT(anim->active == 0);
    ov80_0223ADB8((Ov80Fade *)&anim->x, x0, x1, duration);
    ov80_0223ADB8((Ov80Fade *)&anim->y, y0, y1, duration);
    anim->window = window;
    anim->width = width;
    anim->height = height;
    anim->color = color;
    anim->active = 1;
}

BOOL ov80_0223AE6C(Ov80BoxAnim *anim) {
    BOOL result;
    s32 left, top, right, bottom;
    u32 width, height;
    if (anim->active == 0) {
        return TRUE;
    }
    result = ov80_0223ADC8((Ov80Fade *)&anim->x);
    ov80_0223ADC8((Ov80Fade *)&anim->y);
    width = anim->width;
    left = (s16)(anim->x.value - (width >> 1));
    height = anim->height;
    right = (s16)(left + width);
    top = (s16)(anim->y.value - (height >> 1));
    bottom = (s16)(top + height);
    ov80_0223AED4(anim->window, top, bottom, left, right, anim->color);
    return result;
}

void ov80_0223AED4(Window *window, s32 left, s32 bottom, s32 top, s32 right, u8 color) {
    if (right > 0 && bottom > 0 && top != right && left != bottom) {
        if (top < 0) {
            top = 0;
        }
        if (right > 256) {
            right = 256;
        }
        if (left < 0) {
            left = 0;
        }
        if (bottom > 256) {
            bottom = 256;
        }
        FillWindowPixelRect(window, color, (u16)top, (u16)left, (u16)(right - top), (u16)(bottom - left));
    }
}

void **ov80_0223AF30(u32 heapId) {
    void **pool = Heap_Alloc(heapId, 0x190);
    int i;
    memset(pool, 0, 0x190);
    for (i = 0; i < 96; i++) {
        pool[i + 1] = ov80_0223ADF4(heapId);
    }
    return pool;
}

void ov80_0223AF60(void **pool) {
    int i;
    for (i = 0; i < 96; i++) {
        ov80_0223AE0C(pool[i + 1]);
    }
    Heap_Free(pool);
}

void ov80_0223AF80(void *data, u8 arg1, u8 arg2, void *arg3, u8 arg4) {
    u8 *bytes = data;
    *(void **)bytes = arg3;
    bytes[0x18c] = arg4;
    bytes[0x189] = arg1;
    bytes[0x18a] = arg2;
    bytes[0x184] = 0;
    bytes[0x185] = 0;
    bytes[0x186] = 0;
    bytes[0x187] = 0;
    bytes[0x188] = 0;
    bytes[0x18b] = 0;
    bytes[0x18d] = 1;
}
