#include "overlay_02_legendary_internal.h"

void ov02_02245B80(void *task) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_02245B9C(field);
    TaskManager_Call(task, ov02_02245BC8, env);
}

void *ov02_02245B9C(void *field) {
    void *p = Heap_Alloc(4, 0xD0);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0xD0);
    *(void **)((u8 *)p + 4) = field;
    *(u32 *)p = 4;
    return p;
}
