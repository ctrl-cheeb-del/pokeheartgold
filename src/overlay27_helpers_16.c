#include "overlay_27_helpers_internal.h"

BOOL ov27_0225C418(Ov27Work *work) {
    return TRUE;
}

void ov27_0225C41C(SysTask *task, void *a1, void *a2) {
    Ov27Work *work = SysTask_GetData(task);
    work->unk39C = a1;
    work->unk3A0 = a2;
}
