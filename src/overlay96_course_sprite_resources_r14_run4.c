#include "global.h"

#include "overlay96_course_sprite_resources_r14_private.h"

void ov96_02204320(int radius, VecFx32 *vec) {
    MtxFx43 mtx;
    u16 angle = (u16)(0xb6 * (radius - (LCRandom() % (radius * 2))));
    MTX_RotY43(&mtx, FX_SinIdx(angle), FX_CosIdx(angle));
    MTX_MultVec43(vec, &mtx, vec);
}

void *ov96_02204364(enum HeapID heapId, u8 index) {
    void *p = Heap_Alloc(heapId, 0xcc);
    MI_CpuFill8(p, 0, 0xcc);
    U8_AT(p, 0xc4) = index;
    U8_AT(p, 0xc9) = 4 - index;
    U8_AT(p, 0xc8) = U8_AT(p, 0xc9);
    U8_AT(p, 0xc7) = 0x28;
    U8_AT(p, 0xc6) = U8_AT(p, 0xc7);
    return p;
}
