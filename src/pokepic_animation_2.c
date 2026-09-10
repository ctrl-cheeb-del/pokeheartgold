#include "pokepic_animation_internal.h"

u32 sub_02017068(PicManager *mgr, u32 index) {
    GF_ASSERT(index < mgr->count);
    return mgr->entries[index].state;
}

void sub_02017088(PicManager *mgr, u32 index) {
    if (mgr->entries[index].task != NULL) {
        SysTask_Destroy(mgr->entries[index].task);
        mgr->entries[index].task = NULL;
        mgr->entries[index].state = 1;
        mgr->entries[index].active = 0;
        Heap_Free(mgr->entries[index].data);
    }
}

void sub_020170C4(SysTask *task, PicEntry *entry) {
    if (entry->delay == 0) {
        sub_020170FC(entry);
    } else {
        entry->delay--;
    }
    if (entry->done != 0) {
        entry->state = 1;
        entry->active = 0;
        SysTask_Destroy(task);
        entry->task = NULL;
        Heap_Free(entry->data);
    }
}
