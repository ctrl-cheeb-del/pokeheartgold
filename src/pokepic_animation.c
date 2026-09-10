#include "pokepic_animation_internal.h"

PicManager *sub_02016EDC(enum HeapID heapId, int count, int flag) {
    PicManager *mgr = Heap_Alloc(heapId, sizeof(PicManager));
    int i;
    mgr->flag = flag;
    mgr->count = count;
    mgr->heapId = heapId;
    mgr->entries = Heap_Alloc(heapId, count * sizeof(PicEntry));
    MI_CpuFill8(mgr->entries, 0, count * sizeof(PicEntry));
    for (i = 0; i < count; i++) {
        mgr->entries[i].state = 1;
    }
    return mgr;
}

void sub_02016F2C(PicManager *mgr) {
    Heap_Free(mgr->entries);
    Heap_Free(mgr);
}
