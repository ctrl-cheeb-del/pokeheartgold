#include "r40_overlay_14_residual_40_private.h"
#define SUB(ctx) (*(void **)(*(u8 **)((ctx) + 0x34) + 0x2f0))

void ov14_021F263C(u8 *ctx) {
    ov14_021E84A4(SUB(ctx));
    ov14_021E8248(SUB(ctx));
    ov14_021E82A8(SUB(ctx));
    ov14_021E8328(SUB(ctx));
    ov14_021E884C(*(void **)(ctx + 0x34));
    ov14_021F40E8(ctx, 0);
    ov14_021F0234(ctx, ov14_021EA180, 0x4a);
}

void ov14_021F2690(u8 *ctx) {
    if (ctx[0x2b] == 0) {
        ov14_021E76B8(ctx);
    } else {
        ov14_021F40E8(ctx, 0);
    }
    ov14_021F0C0C(ctx);
}

void ov14_021F26B4(u8 *ctx) {
    ov14_021E84A4(SUB(ctx));
    ov14_021E8328(SUB(ctx));
    ov14_021E884C(*(void **)(ctx + 0x34));
    ov14_021F40E8(ctx, 0);
    ov14_021F0234(ctx, ov14_021EA180, 0x4c);
}

void ov14_021F26F0(u8 *ctx) {
    ov14_021E76B8(ctx);
    ov14_021F0B34(ctx);
}
