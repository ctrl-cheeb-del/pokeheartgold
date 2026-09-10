#include "field_context_access_internal.h"

void *sub_020691A8(u32 heapId) {
    void *p = Heap_Alloc(heapId, 0x66c);
    memset(p, 0, 0x66c);
    return p;
}

void *sub_020691C4(u32 heapId) {
    void *p = Heap_Alloc(heapId, 0x67c);
    memset(p, 0, 0x67c);
    return p;
}

void sub_020691E0(void *p) {
    Heap_Free(p);
}
