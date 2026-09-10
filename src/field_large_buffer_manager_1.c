#include "field_large_buffer_manager_internal.h"

void ov01_021FACB4(OverlayBuffersPrivate *buffers) {
    u8 i;
    for (i = 0; i < 4; i++) {
        buffers->primary[i] = NULL;
        if (buffers->secondary[i] != NULL) {
            Heap_Free(buffers->secondary[i]);
            buffers->secondary[i] = NULL;
        }
    }
    Heap_Free(buffers);
}

void ov01_021FACE4(u32 index, OverlayBuffersPrivate *buffers, void **out) {
    *out = buffers->primary[index];
}

void ov01_021FACEC(u32 index, OverlayBuffersPrivate *buffers, void **out) {
    *out = buffers->secondary[index];
}

void ov01_021FACF8(u32 index, u32 primarySize, u32 secondarySize, OverlayBuffersPrivate *buffers) {
    MI_CpuFill8(buffers->primary[index], 0, primarySize);
    MI_CpuFill8(buffers->secondary[index], 0, secondarySize);
}
