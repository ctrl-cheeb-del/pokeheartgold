#include "r40_overlay_85_residual_10_private.h"

int ov85_021E6594(u8 *ctx) {
    void *p = *(void **)(ctx + 0xcc);
    GameStats_Inc(*(void **)((u8 *)p + 0x28), 0x78);
    p = *(void **)(ctx + 0xcc);
    GameStats_AddScore(*(void **)((u8 *)p + 0x28), 0x22);
    ov85_021E7194(ctx, 0xb);
    sub_02037AC0(0xca);
    gSystem[0x6c] = 1;
    *(int *)ctx = 0x2c;
    return 0;
}

int ov85_021E65D4(u8 *ctx) {
    if (sub_02037B38(0xca)) {
        ov85_021E86CC(ctx, *(void **)(*(u8 **)(ctx + 0x28) + 0xc));
        sub_02039EAC(ctx + 4);
        *(void **)(ctx + 0xdc8) = WaitingIcon_New(ctx + 0xca8, 0xa);
        *(int *)ctx = 0x2d;
    }
    return 0;
}

int ov85_021E6610(u8 *ctx) {
    void *p = *(void **)(ctx + 0xcc);
    if (sub_02039EB4(*(void **)((u8 *)p + 0x1c), 2, ctx + 4)) {
        gSystem[0x6c] = 0;
        sub_0200F450(*(void **)(ctx + 0xdc8));
        *(int *)ctx = 0x30;
    }
    return 0;
}
