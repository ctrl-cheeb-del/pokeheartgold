#include "field_overlay_effects_internal.h"

void *ov01_021F0B44(void) {
    void *p = Heap_Alloc(4, 0xE8);
    memset(p, 0, 0xE8);
    return p;
}

void ov01_021F0B5C(void *p) {
    if (*(void **)((u8 *)p + 0xE0)) {
        ov01_021F0CDC(p);
    }
    Heap_Free(p);
}
