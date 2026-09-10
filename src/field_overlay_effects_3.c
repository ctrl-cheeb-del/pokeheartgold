#include "field_overlay_effects_internal.h"

void ov01_021EFF90(int screen, s32 brightness) {
    if (screen == 1) {
        GXx_SetMasterBrightness_(0x0400006C, brightness);
    } else {
        GXx_SetMasterBrightness_(0x0400106C, brightness);
    }
}

void ov01_021EFFB0(Interp *p, s32 start, s32 end, s32 screen, s32 duration) {
    p->screen = screen;
    ov01_021EFE34(p, start, end, duration);
}

BOOL ov01_021EFFBC(Interp *p) {
    BOOL ret = ov01_021EFE44(p);
    SysTask_CreateOnVWaitQueue(ov01_021EFFD8, p, 10);
    return ret;
}

void ov01_021EFFD8(SysTask *task, Interp *p) {
    ov01_021EFF90(p->screen, p->value);
    SysTask_Destroy(task);
}
