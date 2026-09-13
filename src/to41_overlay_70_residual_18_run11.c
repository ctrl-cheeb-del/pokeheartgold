#include "to41_overlay_70_residual_18_private.h"

int ov70_0223C6F0(R14Work *w) {
    ov70_0223CAC4(w, 0xb, 1, 0, 0xf0f);
    ov70_02238D84(w, 0x15, 0xa);
    return 3;
}

int ov70_0223C718(R14Work *w) {
    U16(w, 0x118) = 0xffff;
    ov70_022420C4(P(w, 0x11a8), 2);
    ov70_0223CD28(9);
    U32(w, 0x2c) = 0xb;
    return 3;
}
