#include "render_window_internal.h"

void sub_0200F43C(void *task, void *data) {
    Heap_Free(data);
    SysTask_Destroy(task);
}

void sub_0200F450(void *data) {
    u8 *byte = (u8 *)data + 0x488;
    SysTask_CreateOnVWaitQueue(sub_0200F43C, data, 0);
    *byte = (*byte & ~3) | 1;
}

void sub_0200F478(void *data) {
    u8 *byte = (u8 *)data + 0x488;
    SysTask_CreateOnVWaitQueue(sub_0200F43C, data, 0);
    *byte = (*byte & ~3) | 2;
}
