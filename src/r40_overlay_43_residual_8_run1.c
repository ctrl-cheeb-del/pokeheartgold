#include "r40_overlay_43_residual_8_private.h"

void ov43_0222ACDC(u8 *ctx) {
    int i;
    Sprite_Delete(*(void **)(ctx + 0x1fc));
    for (i = 0; i < 2; i++, ctx += 4) {
        Sprite_Delete(*(void **)(ctx + 0x1f4));
    }
}

void ov43_0222AD00(u8 *ctx, int flag) {
    int i;
    for (i = 0; i < 2; i++, ctx += 4) {
        Sprite_SetDrawFlag(*(void **)(ctx + 0x1f4), flag);
    }
}

void ov43_0222AD20(u8 *ctx, int flag) {
    int i;
    for (i = 0; i < 2; i++, ctx += 4) {
        Sprite_SetAnimActiveFlag(*(void **)(ctx + 0x1f4), flag);
    }
}

void ov43_0222AD40(u8 *ctx, u8 index, int offset) {
    u8 seq = index * 2;
    if (index >= 2) {
        index -= 2;
    }
    Sprite_SetAnimActiveFlag(*(void **)(ctx + 0x1f4 + index * 4), 1);
    Sprite_SetAnimCtrlSeq(*(void **)(ctx + 0x1f4 + index * 4), seq + 5 + offset);
    Sprite_ResetAnimCtrlState(*(void **)(ctx + 0x1f4 + index * 4));
}
