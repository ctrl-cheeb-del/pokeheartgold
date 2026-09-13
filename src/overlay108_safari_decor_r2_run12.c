#include "overlay108_safari_decor_r2_private.h"

void ov108_021EA2EC(void *p, u32 i) {
    int anim;
    void *ctx = p;
    s16 x, y;
    if (i >= 6) {
        x = 0xe0;
        y = 0xb4;
        anim = 1;
    } else {
        x = ((s32)i % 2) * 0x80;
        y = (i / 2 + 1) * 0x28;
        anim = 0;
    }
    Sprite_SetPositionXY(PTR(ctx, 0x444), x, y);
    Sprite_SetAnimCtrlSeq(PTR(ctx, 0x444), anim);
}
