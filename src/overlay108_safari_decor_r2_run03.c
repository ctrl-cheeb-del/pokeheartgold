#include "overlay108_safari_decor_r2_private.h"

void ov108_021E8E10(void *p) {
    Thunk_G3X_Reset();
    Camera_PushLookAtToNNSGlb();
    NNS_G3dGeFlushBuffer();
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000454 = 0;
    if (U8(p, 0xf0) && U16(p, 0xd8)) {
        ov108_021E9144((u8 *)p + 0x24);
    }
    *(volatile u32 *)0x04000540 = 1;
}

void ov108_021E8E60(void *p) {
    if (U16(p, 0xd8) != 0) {
        ov108_021E90C4(p, (u8 *)p + 0x24);
    }
    Camera_Delete(PTR(p, 0));
    Heap_Free(PTR(p, 0xe8));
    Heap_Free(PTR(p, 0xec));
    NARC_Delete(PTR(p, 0x20));
    NARC_Delete(PTR(p, 0x1c));
    NARC_Delete(PTR(p, 0x18));
}

void ov108_021E8EA4(void *p, u16 a, int b) {
    if (U16(p, 0xd8) != 0) {
        ov108_021E90C4(p, (u8 *)p + 0x24);
    }
    U8(p, 0xf0) = 1;
    if (b) {
        ov108_021E8F00(p, a, b);
    }
}

void ov108_021E8ED8(void *p, u8 v) {
    U8(p, 0xf0) = v;
    if (U8(p, 0xf0) == 0) {
        Thunk_G3X_Reset();
        Camera_PushLookAtToNNSGlb();
        NNS_G3dGeFlushBuffer();
        *(volatile u32 *)0x04000540 = 1;
    }
}
