#include "to41_overlay_70_residual_18_private.h"

int ov70_0223B788(R14Work *w) {
    U32(w, 0x1208) = 0;
    ov70_0224212C(P(w, 0x11a8));
    ov70_0223BAAC(w);
    ov70_0223BCD0(w);
    ov70_0223BC2C(w);
    ov70_0223B8B4(P(w, 4));
    Sprite_SetDrawFlag(P(w, 0xf10), 0);
    ov70_02238E58(w);
    return 1;
}
