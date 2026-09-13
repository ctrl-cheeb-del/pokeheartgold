#include "to41_overlay_70_residual_18_private.h"

int ov70_0223C4B0(R14Work *w) {
    if (U32(w, 0xf14) == 0) {
        BeginNormalPaletteFade(3, 0, 0, 0, 6, 1, 0x3d);
    }
    U32(w, 0x2c) = 0;
    return 4;
}

int ov70_0223C4E4(R14Work *w) {
    ov70_0223CAC4(w, 9, 1, 0, 0xf0f);
    ov70_02238D84(w, 0x15, 4);
    return 3;
}

int ov70_0223C50C(R14Work *w) {
    ov70_022420C4(P(w, 0x11a8), 0);
    ov70_0223CD28(9);
    U32(w, 0x2c) = 5;
    return 3;
}
