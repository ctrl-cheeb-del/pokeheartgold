#include "overlay_27_helpers_internal.h"

BOOL ov27_0225A2C8(Ov27Work *work) {
    return TRUE;
}

void ov27_0225A2CC(SysTask *task, void *unused) {
    Ov27Work *work = SysTask_GetData(task);
    GF_ASSERT(work != NULL);
    work->unk51C.raw |= 0x20;
}

void ov27_0225A2EC(SysTask *task, s32 a1) {
    Ov27Work *work = SysTask_GetData(task);
    GF_ASSERT(work != NULL);
    GF_ASSERT(a1 == 1 || a1 == 2);
    work->unk51C.b.bits6_7 = a1;
}
