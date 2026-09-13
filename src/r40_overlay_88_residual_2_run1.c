#include "r40_overlay_88_residual_2_private.h"

void ov88_02258A70(u8 *ctx, u32 arg) {
    ov88_02258F60(ctx + 0x154, ctx + 0x14c, ctx + 8);
    ov88_02259104(ctx + 0x160, ctx + 0x14c, ctx + 8, *(u32 *)ctx, arg);
    ov88_022594E0(ctx + 0x164);
    ov88_02259800(ctx + 0x200);
    ov88_02258B14(ctx + 8);
}

void ov88_02258ABC(u8 *ctx, int heap) {
    *(void **)(ctx + 0x140) = NARC_New(0xc6, heap);
    GF_CreateVramTransferManager(0x30, heap);
    GfGfx_SetBanks(ov88_02259958);
    ov88_02258B34(ctx, heap);
    ov88_02258C98(ctx, heap);
}
