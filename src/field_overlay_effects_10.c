#include "field_overlay_effects_internal.h"

void *ov01_021F0848(int heap) {
    void *p = Heap_Alloc(heap, 0x30);
    memset(p, 0, 0x30);
    return p;
}

void ov01_021F0860(void *p) {
    Heap_Free(p);
}

void ov01_021F0868(void *v, s32 a, s32 b, s32 c, s32 d, s32 duration, void *window, int width, int height, u8 fill) {
    u8 *p = v;
    if (p[0x2E]) {
        GF_ASSERT(FALSE);
    }
    ov01_021EFE34((Interp *)p, a, b, duration);
    ov01_021EFE34((Interp *)(p + 0x14), c, d, duration);
    *(void **)(p + 0x28) = window;
    p[0x2C] = width;
    p[0x2D] = height;
    p[0x2F] = fill;
    p[0x2E] = 1;
}
