#include "overlay_93_arm_opus_partial_internal.h"
#include <nitro/code32.h>

s32 ov93_0225F8AC(Ov93Work *work, s32 mode) {
    s32 base;
    s32 cur;

    if (mode == 1) {
        return 0;
    }
    base = work->f21c;
    cur = work->f224;
    if (cur < base - 0x10) {
        return 1;
    }
    if (cur > base + 0x10) {
        return 2;
    }
    return 0;
}
