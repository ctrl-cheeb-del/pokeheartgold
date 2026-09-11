#include "overlay96_ui_helpers_private.h"

void *ov96_021EE740(enum HeapID heapId) {
    u8 *p = Heap_Alloc(heapId, 0x38);
    MI_CpuFill8(p, 0, 0x38);
    *(u32 *)(p + 0x14) = heapId;
    return p;
}
