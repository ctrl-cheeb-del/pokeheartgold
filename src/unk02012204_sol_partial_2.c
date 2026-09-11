#include <string.h>

#include "unk02012204_sol_partial_internal.h"

void sub_02012290(VectorListWork *work) {
    int i;
    for (i = 0; i < work->count; i++) {
        sub_02010A8C(&work->vectors[i], &work->vectors[i].copy);
    }
}

void sub_020122B8(FadeWork *fade, const ShortVector4 *param) {
    fade->allocation = Heap_Alloc(fade->heapId, sizeof(EffectWork));
    memset(fade->allocation, 0, sizeof(EffectWork));
    sub_02012358(fade->allocation, param, fade->arg2, fade->arg3, fade->arg10, fade->arg18, fade->arg1C, fade->heapId);
    fade->state++;
}

BOOL sub_020122F8(FadeWork *fade) {
    EffectWork *work = fade->allocation;
    BOOL done = FALSE;

    switch (fade->state) {
    case 1:
        if (sub_02012454(work) == TRUE) {
            sub_02010F34(work->value, work->arg5, fade->arg10);
            fade->state++;
        }
        break;
    case 2:
        sub_020124AC(work);
        sub_02010EC8(work);
        Heap_Free(fade->allocation);
        fade->allocation = NULL;
        fade->state++;
        done = TRUE;
        break;
    case 3:
        done = TRUE;
        break;
    default:
        GF_AssertFail();
        break;
    }
    return done;
}

void sub_02012358(EffectWork *work, const ShortVector4 *param, u32 arg2, u32 arg3, u32 arg10, void *arg5, void *arg6, enum HeapID heapId) {
    s16 *buffer0;
    s16 *buffer1;

    work->interp.value = 0;
    work->interp.start = param->start;
    work->interp.delta = param->end - param->start;
    sub_02010E64(work, 2, arg10, heapId);
    work->steps = arg2;
    work->currentStep = 0;
    work->interval = arg3;
    work->counter = 0;
    work->arg5 = arg5;
    work->arg6 = arg6;
    work->heapId = heapId;
    work->value = param->value;
    sub_020125D4(&work->interp, work->currentStep, work->steps);
    sub_020124B0(work);
    SysTask_CreateOnVWaitQueue(sub_02010F00, work, 0x3FF);

    buffer0 = sub_02010EE0(work, 0);
    buffer1 = sub_02010EE0(work, 1);
    sub_02010F84(arg5, param->a, param->b, 0, arg10, buffer0[0x180], 0, buffer0[0x240], 0xC0, work->value);
    sub_02010F84(arg5, param->a, param->b, 1, arg10, buffer1[0x180], 0, buffer1[0x240], 0xC0, work->value);
    sub_02011068(arg5, 3, arg10, work->value);
    sub_0200FF88(work->arg6, (u32)work, (u32)sub_02010C38, arg10, heapId);
}

BOOL sub_02012454(EffectWork *work) {
    s32 next;

    work->counter++;
    if (work->counter >= work->interval) {
        work->counter = 0;
        next = work->currentStep + 1;
        if (next <= work->steps) {
            work->currentStep = next;
            sub_020125D4(&work->interp, work->currentStep, work->steps);
            sub_020124B0(work);
            SysTask_CreateOnVWaitQueue(sub_02010F00, work, 0x3FF);
        } else {
            sub_0200FFB4(work->arg6, work->screen, work->heapId);
            return TRUE;
        }
    }
    return FALSE;
}
