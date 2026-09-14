#include "overlay49_heap_buffer_r47.h"

void *ov49_0225EF40(Ov49Buffer *, u32);
void ov49_0225EF68(Ov49Buffer *);

void *ov49_0225EF40(Ov49Buffer *buffer, u32 size) {
    GF_ASSERT(buffer->data == NULL);
    buffer->data = Heap_Alloc(buffer->heapId, size);
    memset(buffer->data, 0, size);
    return buffer->data;
}

void ov49_0225EF68(Ov49Buffer *buffer) {
    GF_ASSERT(buffer->data != NULL);
    Heap_Free(buffer->data);
    buffer->data = NULL;
}
