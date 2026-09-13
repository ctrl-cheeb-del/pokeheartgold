#include "r40_overlay_40_residual_27_unmatched_1_private.h"

void ov40_02230CDC(void *p, int group, u32 index, u32 mode) {
    WORD(p, 0x504) = WORD(p, 4);
    WORD(p, 0x508) = WORD(p, 8);
    WORD(p, 0x50C) = WORD(PTR(p, 0x10), 0);
    WORD(p, 0x514) = 0;
    WORD(p, 0x518) = 0;
    PTR(p, 0x510) = ov40_022309DC(p, group, index, mode);
    WORD(p, 0x51C) = 1;
    WORD(PTR(p, 0x10), 0) = 0x12;
}
