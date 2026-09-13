#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void *ov96_021F74A4(enum HeapID heapId) {
    u8 *p = Heap_Alloc(heapId, 0x330);
    MI_CpuFill8(p, 0, 0x330);
    *(u32 *)(p + 0x32c) = 0;
    return p;
}
