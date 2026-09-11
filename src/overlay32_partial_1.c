#include "overlay32_partial_internal.h"

void ov32_0225D5CC(void *unused, void *task) {
    u8 *work = SysTask_GetData(task);
    ov32_0225DDAC(work);
    ov32_0225DAC0(work);
    ov32_0225D834(work);
    ov32_0225D76C(work);
    ov32_0225D6C4(*(void **)work);
    FontID_Release(4);
    DestroySysTaskAndEnvironment(task);
    Heap_Destroy(8);
}

int ov32_0225D608(void) {
    return TRUE;
}
