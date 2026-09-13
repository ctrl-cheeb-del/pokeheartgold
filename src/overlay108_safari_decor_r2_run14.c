#include "overlay108_safari_decor_r2_private.h"

void ov108_021EA5E4(void *task, void *d) {
    u8 old = U8(d, 9);
    U8(d, 9) = old + 1;
    if (old >= 2) {
        ov108_021EA040(PTR(d, 4));
        ov108_021EA47C(PTR(d, 4));
        ov108_021EA2EC(PTR(d, 4), U8(PTR(d, 4), 0x431));
        U32(PTR(d, 0), 0)
        --;
        Heap_Free(d);
        SysTask_Destroy(task);
    }
}

void ov108_021EA624(void *p) {
    U8(p, 0x434) = 1;
    ov108_021E8ED8((u8 *)p + 0x338, 0);
}
