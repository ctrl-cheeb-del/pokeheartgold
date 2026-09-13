#include "to41_overlay_96_residual_93_private.h"

u32 ov96_0220AD34(u8 *p) {
    if (!p) {
        GF_AssertFail();
    }
    return (u32)((s32)(U32(p, 0x180) << 28)) >> 28;
}
