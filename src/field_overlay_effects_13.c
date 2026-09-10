#include "field_overlay_effects_internal.h"

void ov01_021F0C40(SysTask *task, void *v) {
    u8 *p = v;
    *(void **)(p + 0xDC) = ov01_021FB530(*(void **)(p + 0xD8), ov01_021F0CA8, p);
    *(void **)(p + 0xE0) = SysTask_CreateOnVWaitQueue((void (*)(SysTask *, Interp *))ov01_021F0C7C, p, 1 << 10);
    SysTask_Destroy(task);
}

void ov01_021F0C7C(SysTask *task, void *v) {
    Interp *p = v;
    switch (p->screen) {
    case 0:
        if (ov01_021EFE44(p) == TRUE) {
            p->screen++;
        }
        break;
    case 1:
        ov01_021F0CDC(p);
        break;
    }
}

void ov01_021F0CA8(SysTask *task, void *v) {
    u8 *p = v;
    s32 line = *(vu16 *)0x04000006;
    s32 value;
    if (line >= 192) {
        return;
    }
    value = *(s32 *)p - p[0x18 + line];
    if (value < 0) {
        value = 0;
    }
    *(vu16 *)0x04000040 = (u16)(0xFF | ((value << 8) & 0xFF00));
    *(vu16 *)0x04000044 = 192;
}
