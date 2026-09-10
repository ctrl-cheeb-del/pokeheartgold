#include "field_overlay_effects_internal.h"

void ov01_021F0330(SysTask *task, void *v) {
    u8 *p = v;
    *(void **)(p + 0x40) = SysTask_CreateOnVWaitQueue((void (*)(SysTask *, Interp *))ov01_021F0360, p, 1 << 10);
    *(void **)(p + 0x3C) = ov01_021FB530(*(void **)(p + 0x38), ov01_021F03C8, p);
    SysTask_Destroy(task);
}
