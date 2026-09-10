#include "field_effect_dispatch_internal.h"

void ov01_02205EE0(void *taskman) {
    u32 *env = Heap_AllocAtEnd(0xb, 4);
    *env = 0;
    TaskManager_Call(taskman, ov01_02205F00, env);
}
