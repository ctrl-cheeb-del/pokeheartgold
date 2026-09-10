#include "field_overlay_effects_internal.h"

void ov01_021F0E74(void) {
    u8 *p = *(u8 **)ov01_02209B64;
    if (!p) {
        GF_ASSERT(FALSE);
    }
    (*(u8 **)ov01_02209B64)[3] = 1;
}

u8 ov01_021F0E90(void) {
    u8 *p = *(u8 **)ov01_02209B64;
    if (!p) {
        GF_ASSERT(FALSE);
    }
    return (*(u8 **)ov01_02209B64)[2];
}

void ov01_021F0EAC(void) {
    void *p = *(void **)ov01_02209B64;
    if (p) {
        sub_0201543C(p);
    }
}

void ov01_021F0EC0(void) {
    u8 *p = *(u8 **)ov01_02209B64;
    if (!p) {
        GF_ASSERT(FALSE);
    }
    sub_02014F84();
    ov01_021F1210(*(void **)(*(u8 **)ov01_02209B64 + 4));
    ov01_021E631C(*(void **)(*(u8 **)ov01_02209B64 + 4), 1);
    ov01_021E6340(*(void **)(*(u8 **)ov01_02209B64 + 4), 1);
    Heap_Free(*(void **)ov01_02209B64);
    *(void **)ov01_02209B64 = NULL;
}
