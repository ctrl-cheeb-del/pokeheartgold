#include "screen_effect_step_internal.h"

void sub_02012E6C(EffectWork *work, const EffectConfig *config, s32 steps, s32 interval, u32 arg4, void *arg5, void *arg6, void *arg7) {
    s16 *buffer;

    sub_02010E64(work, config->direction, arg4, (u32)arg7);
    work->phase = 0x7FFF80;
    work->x = config->x;
    work->y = config->y;
    work->threshold = config->threshold;
    work->current = config->threshold;
    work->step = 0xFFFF / steps;
    work->steps = steps;
    work->interval = interval;
    work->counter = 0;
    work->arg5 = arg5;
    work->arg6 = arg6;
    work->unk30 = arg7;
    work->value = config->value;
    work->direction = config->direction;
    work->arg4 = arg4;
    work->armed = 1;
    sub_020131AC(work);
    SysTask_CreateOnVWaitQueue(sub_02010F00, work, 0x3FF);
    buffer = sub_02010EE0(work, 0);
    sub_02010F84(arg5, config->a, config->b, config->direction, arg4, buffer[0x180], 0, buffer[0x240], 0xC0, work->value);
    if (config->direction == 0) {
        sub_02011068(arg5, 1, arg4, work->value);
    } else {
        sub_02011068(arg5, 2, arg4, work->value);
    }
    sub_0200FF88(work->arg6, (u32)work, (u32)sub_02010C38, arg4, (enum HeapID)arg7);
}
