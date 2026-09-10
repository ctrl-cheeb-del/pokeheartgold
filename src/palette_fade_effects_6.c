#include "palette_fade_effects_internal.h"

SysTask *sub_020110C4(void *work) {
    return SysTask_CreateOnVWaitQueue((SysTaskFunc)sub_02011104, work, 0x3FF);
}

void sub_020110DC(void *a0, u8 *work, u32 heapId) {
    sub_0200FF88(a0, (u32)work, (u32)sub_02011130, work[0x309], heapId);
}

void sub_020110F4(void *a0, u8 *work, u32 heapId) {
    sub_0200FFB4(a0, work[0x309], heapId);
}

void sub_02011104(SysTask *task, u8 *work) {
    int i;
    for (i = 0; i < 2; i++) {
        memcpy(work + 0xC0, work, 0xC0);
        work += 0x184;
    }
    SysTask_Destroy(task);
}
