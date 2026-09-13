#include "r40_unk_02011130_residual_3_private.h"

void sub_02011918(LocalFadeEffect *work, const LocalFadeParam *param, u32 repeats, u32 delay, u32 screen, u32 arg5, u32 arg6, u32 heapId) {
    s16 *buffer;
    int step;

    step = sub_02010A6C(param->start, param->end, repeats);
    sub_02010E64(work, param->direction, screen, heapId);
    work->current = param->start << 7;
    work->initial = param->initial;
    work->increment = param->increment;
    work->step = step;
    work->repeats = repeats;
    work->delay = delay;
    work->counter = 0;
    work->arg5 = arg5;
    work->arg6 = arg6;
    work->heapId = heapId;
    work->value = param->value;
    sub_02011AD8(work);
    SysTask_CreateOnVWaitQueue(sub_02010F00, work, 0x3FF);
    buffer = sub_02010EE0(work, 0);
    sub_02010F84(arg5, param->x, param->y, param->direction, screen, buffer[0x180], 0, buffer[0x240], 0xC0, work->value);
    if (param->direction == 0) {
        sub_02011068(arg5, 1, screen, work->value);
    } else {
        sub_02011068(arg5, 2, screen, work->value);
    }
    sub_0200FF88(work->arg6, work, sub_02010C38, screen, heapId);
}
