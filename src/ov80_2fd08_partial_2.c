#include "ov80_2fd08_partial_internal.h"

void ov80_02230424(void *work) {
    u8 *p = work;
    if (p != NULL) {
        if (*(void **)(p + 0x4D4) != NULL) {
            Heap_Free(*(void **)(p + 0x4D4));
        }
        if (*(void **)(p + 0x4D8) != NULL) {
            Heap_Free(*(void **)(p + 0x4D8));
        }
        MI_CpuFill8(p, 0, 0x708);
        Heap_Free(p);
    }
}

void ov80_02230460(void *work, void *source) {
    u8 *cursor = work;
    int i;
    for (i = 0; i < 6; i++) {
        *(u16 *)(cursor + 0x4DC) = ov80_02230484(source, (u8)i);
        cursor += 2;
    }
}

int ov80_02230484(void *source, u32 index) {
    if (index >= 6) {
        GF_AssertFail();
        return 0;
    }
    return *(u16 *)((u8 *)source + 0x10 + index * 2);
}
