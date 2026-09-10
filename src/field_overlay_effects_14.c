#include "field_overlay_effects_internal.h"

void ov01_021F0DB0(SysTask *task, Interp *p) {
    GXx_SetMasterBrightness_(0x0400006C, p->value);
    SysTask_Destroy(task);
}

SysTask *ov01_021F0DC8(void *p) {
    return SysTask_CreateOnVWaitQueue(ov01_021F0DB0, p, 1 << 10);
}
