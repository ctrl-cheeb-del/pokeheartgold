#include "network_library_init_internal.h"

int sub_02039FD8(enum HeapID heapID) {
    void *allocation;
    int result;

    allocation = Heap_Alloc(heapID, 0x720);
    result = DWC_Init((void *)(((u32)allocation + 31) & ~31));
    Heap_Free(allocation);
    return result;
}
