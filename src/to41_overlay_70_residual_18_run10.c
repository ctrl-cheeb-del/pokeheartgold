#include "to41_overlay_70_residual_18_private.h"

int ov70_0223C618(R14Work *w) {
    ov70_0223CAC4(w, 0xa, 1, 0, 0xf0f);
    ov70_02238D84(w, 0x15, 7);
    return 3;
}

int ov70_0223C640(R14Work *w) {
    ov70_022420C4(P(w, 0x11a8), 1);
    ov70_0223CD28(9);
    U32(w, 0x2c) = 8;
    return 3;
}
