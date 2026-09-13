#include "global.h"

#include "r40_overlay_103_residual_4_private.h"
#define PTR(c, o) (*(void **)((c) + (o)))

void ov103_021ECD68(R40Ov103Work4 *work) {
    u32 i;
    void *first;
    PTR(work->ctx, 4) = sub_0201956C(PTR(work->ctx, 0), 2, 11, 0x9D);
    for (i = 0; i < 10; i++) {
        sub_020195F4(PTR(work->ctx, 4), i, 2, 14, 4);
    }
    sub_020195F4(PTR(work->ctx, 4), 10, 1, 14, 4);
    sub_02019688(PTR(work->ctx, 4), 0, 0xFC, 3, 1);
    first = sub_02019B08(PTR(work->ctx, 4), 0);
    for (i = 1; i <= 10; i++) {
        MI_CpuCopy8(first, sub_02019B08(PTR(work->ctx, 4), i), 0x70);
    }
    for (i = 0; i < 10; i++) {
        sub_020196E8(PTR(work->ctx, 4), i, (s8)((i & 1) * 16 + 1), (s8)((i >> 1) * 4));
    }
}
