#include "r40_overlay_90_residual_2_private.h"

u8 ov90_0225888C(u8 *ctx, u32 i) {
    if (i >= ctx[8]) {
        GF_AssertFail();
    }
    return ctx[4 + i];
}
