#include "to41_overlay_70_residual_18_private.h"

int ov70_0223C19C(R14Work *w) {
    if (U32(w, 0x128) == 0) {
        ov70_0223CAC4(w, 0xe, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 1);
        PlaySE(0x5f3);
    } else {
        ov70_0223CAC4(w, 0x1e, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 0x13);
        U32(w, 0x11c0) = 0;
    }
    return 3;
}

int ov70_0223C1F8(R14Work *w) {
    S32(w, 0x11c0)
    ++;
    if (S32(w, 0x11c0) > 0x2d) {
        ov70_0223CAC4(w, 0x20, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 1);
        U16(w, 0x11de) = 1;
    }
    return 3;
}

int ov70_0223C23C(R14Work *w) {
    U16(w, 0xb90) = 0;
    ov70_0223CAC4(w, 0x26, 1, 0, 0xf0f);
    ov70_02238D84(w, 0x15, 1);
    PlaySE(0x5f3);
    return 3;
}

int ov70_0223C274(R14Work *w) {
    ov70_0223CAC4(w, 0x99, 4, 0, 0xf0f);
    ov70_02238D84(w, 0x16, 0x1c);
    U32(w, 0x11c0) = 0;
    PlaySE(0x5f3);
    return 3;
}

int ov70_0223C2B0(R14Work *w) {
    ov70_0223CAC4(w, 0x9e, 4, 0, 0xf0f);
    ov70_02238D84(w, 0x16, 2);
    ov70_02238E50(w, 0, 0);
    PlaySE(0x5f3);
    return 3;
}

u8 *ov70_0223C2EC(R14Work *w) {
    u8 *p = P(w, 0x11c4);
    if (U32(p, 0x24) == 0) {
        return P(p, 0x28);
    }
    return (u8 *)P(p, 0x2c) + 4;
}
