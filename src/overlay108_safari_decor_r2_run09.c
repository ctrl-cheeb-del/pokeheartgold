#include "overlay108_safari_decor_r2_private.h"

void ov108_021E9BD4(void *p) {
    G2x_SetBlendAlpha_(0x04000050, 0, 0, 31, 0);
    Heap_Free(PTR(p, 0x528));
    Heap_Free(PTR(p, 0x520));
    Heap_Free(PTR(p, 0x518));
}

void ov108_021E9C14(void *p) {
    ov108_021E8CD4((u8 *)p + 0x338, U8(p, 0x42c), PTR(p, 0));
}

void ov108_021E9C2C(void *p) {
    ov108_021E8E60((u8 *)p + 0x338);
}
