#include "field_overlay_effects_internal.h"

void ov01_021F00DC(SysTask *task, void *v) {
    u8 *p = v;
    *(void **)(p + 0x28) = SysTask_CreateOnVWaitQueue((void (*)(SysTask *, Interp *))ov01_021F010C, p, 1 << 10);
    *(void **)(p + 0x24) = ov01_021FB530(*(void **)(p + 0x20), ov01_021F01D0, p);
    SysTask_Destroy(task);
}
