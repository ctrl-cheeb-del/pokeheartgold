#include "r40_overlay_71_residual_16_private.h"

void ov71_02248140(void *task, u8 *ctx) {
    if (--*(int *)(ctx + 0x10) > 0) {
        *(int *)(ctx + 4) += *(int *)(ctx + 0xc);
        G2x_SetBlendBrightness_((volatile u16 *)0x04000050, 1, *(int *)(ctx + 4) >> 12);
    } else {
        G2x_SetBlendBrightness_((volatile u16 *)0x04000050, 1, *(int *)(ctx + 8) >> 12);
        ov71_02248120(*(void **)ctx);
    }
}
