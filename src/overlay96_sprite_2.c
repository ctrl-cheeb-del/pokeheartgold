#include "heap.h"
#include "math_util.h"
#include "overlay96_sprite_internal.h"

void *ov96_021FC188(int heapId) {
    u8 *work = Heap_Alloc((enum HeapID)heapId, 0x244);
    MIi_CpuClearFast(0, (u32 *)work, 0x244);
    *(int *)work = heapId;
    return work;
}
