#include "palette_fade_effects_internal.h"

void sub_02010EC8(AllocationList *list) {
    sub_02010ED0(list);
}

void sub_02010ED0(AllocationList *list) {
    Heap_Free(list->allocation);
    list->allocation = 0;
}

void *sub_02010EE0(AllocationList *list, int index) {
    if (list->count <= index) {
        GF_AssertFail();
    }
    return (u8 *)list->allocation + 0x604 * index;
}

void sub_02010F00(SysTask *task, AllocationList *list) {
    int i;
    for (i = 0; i < list->count; i++) {
        void *entry = sub_02010EE0(list, i);
        memcpy(entry, (u8 *)entry + 0x300, 0x300);
    }
    SysTask_Destroy(task);
}
