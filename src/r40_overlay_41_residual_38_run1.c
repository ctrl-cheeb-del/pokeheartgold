#include "r40_overlay_41_residual_38_private.h"

void ov41_02248A6C(u8 *ctx) {
    int zero;
    Heap_Free(*(void **)ctx);
    zero = 0;
    *(void **)ctx = NULL;
    ctx[0] = zero;
    ctx[1] = zero;
    ctx[2] = zero;
    ctx[3] = zero;
    ctx[4] = zero;
    ctx[5] = zero;
    ctx[6] = zero;
    ctx[7] = zero;
    ctx[8] = zero;
    ctx[9] = zero;
    ctx[10] = zero;
    ctx[11] = zero;
}

void *ov41_02248A94(Ov41Ctx *ctx) {
    Ov41Ref ref = ctx->refs[ctx->selected];
    return ref.base + ref.index * 16;
}

void *ov41_02248ABC(Ov41Ctx *ctx, int row, int item) {
    Ov41Ref ref = ctx->refs[row];
    return ref.base + item * 16;
}
