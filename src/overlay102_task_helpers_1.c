#include "overlay102_task_helpers_private.h"
#define R16_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define R16_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define R16_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

BOOL ov102_021EC2EC(ScrollTask102 *work) {
    switch (work->state) {
    case 0:
        work->task = ov102_021E93D4((void (*)(void *, void *))ov102_021EC338, work, 0);
        work->state++;
        break;
    case 1:
        if (work->frames == 0) {
            SysTask_Destroy(work->task);
            work->state++;
            return TRUE;
        }
        break;
    case 2:
        return TRUE;
    }
    return FALSE;
}

void ov102_021EC338(void *task, ScrollTask102 *work) {
    if (work->frames != 0) {
        work->position += work->step;
        BgSetPosTextAndCommit(work->bg, work->layer, work->axis, work->position >> 12);
        work->frames--;
    } else {
        BgSetPosTextAndCommit(work->bg, work->layer, work->axis, work->target);
    }
}

void ov102_021EC37C(BlendTask102 *work, u32 plane1, u32 plane2, s32 start, s32 target, s32 frames) {
    work->plane1 = plane1;
    work->plane2 = plane2;
    work->frames = frames;
    work->value = start;
    work->step = _s32_div_f(target - start, frames);
    work->target = target;
    work->done = 0;
    work->task = ov102_021E93D4((void (*)(void *, void *))ov102_021EC3D4, work, 0);
}

BOOL ov102_021EC3AC(BlendTask102 *work) {
    if (work->done == 0) {
        if (work->frames == 0) {
            SysTask_Destroy(work->task);
            work->done++;
            return TRUE;
        }
    } else {
        return TRUE;
    }
    return FALSE;
}

void ov102_021EC3D4(void *task, BlendTask102 *work) {
    s32 value;
    if (work->frames != 0) {
        work->value += work->step;
        value = work->value >> 3;
        work->frames--;
    } else {
        value = work->target >> 3;
    }
    if (value > 16) value = 16;
    G2x_SetBlendAlpha_(0x04000050, work->plane1, work->plane2, value, 16 - value);
}

void ov102_021EC410(BlendTask102 *work, u32 plane, s32 start, s32 target, s32 frames) {
    G2x_SetBlendBrightness_((volatile u16 *)0x04000050, plane, start);
    work->plane1 = plane;
    work->frames = frames;
    work->value = start << 12;
    work->target = target << 12;
    work->step = _s32_div_f(work->target - work->value, frames);
    work->done = 0;
    work->task = ov102_021E93D4((void (*)(void *, void *))ov102_021EC478, work, 0);
}

BOOL ov102_021EC450(BlendTask102 *work) {
    if (work->done == 0) {
        if (work->frames == 0) {
            SysTask_Destroy(work->task);
            work->done++;
            return TRUE;
        }
    } else {
        return TRUE;
    }
    return FALSE;
}

void ov102_021EC478(void *task, BlendTask102 *work) {
    s32 value;
    if (work->frames != 0) {
        work->value += work->step;
        value = work->value >> 12;
        work->frames--;
    } else {
        value = work->target >> 12;
    }
    G2x_SetBlendBrightness_((volatile u16 *)0x04000050, work->plane1, value);
}
