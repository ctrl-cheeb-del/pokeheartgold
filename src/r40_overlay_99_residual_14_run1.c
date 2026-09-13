#include "r40_overlay_99_residual_14_private.h"

int ov99_021E94CC(void *ctx, int idx, int slot, int arg) {
    if (ctx == NULL) {
        GF_AssertFail();
    }
    if ((u32)slot >= 5) {
        GF_AssertFail();
    }
    return ov98_0221F01C(ov99_021E9430(ctx, (u8)idx, arg), slot);
}
