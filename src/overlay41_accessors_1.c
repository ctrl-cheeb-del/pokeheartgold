#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_022499B4(Ov41List *list, s32 count, u32 heapId) {
    u32 size = count << 4;
    list->nodes = Heap_Alloc(heapId, size);
    if (list->nodes == NULL) GF_AssertFail();
    memset(list->nodes, 0, size);
    list->count = count;
}

void ov41_022499DC(Ov41List *list) {
    Heap_Free(list->nodes);
    list->nodes = NULL;
    list->count = 0;
}
