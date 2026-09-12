#include "overlay57_capsule_controls_r10_private.h"

int ov57_0223B12C(void *w) {
    if (U32(w, 0x40c) == 1) {
        if (System_GetTouchHeld()) {
            return 0;
        }
        if (U32(gSystem, 0x44) != 0) {
            U32(w, 0x40c) = 0;
            return 1;
        }
    } else {
        if (U32(gSystem, 0x44) != 0) {
            return 0;
        }
        if (System_GetTouchHeld()) {
            U32(w, 0x40c) = 1;
            return 0;
        }
    }
    return 0;
}

void ov57_0223B180(void *w) {
    ov57_0223B12C(w);
    if (U32(w, 0x40c) == 0) {
        ov57_0223B288(w);
    } else {
        ov57_0223B2EC(w);
    }
}

int ov57_0223B1A4(void *w, int selection) {
    switch (selection) {
    case 12:
        PlaySE(0x5dd);
        ov57_02237E88(PTR(w, 0), 0);
        return 5;
    case 13:
        ov57_02239728((u8 *)w + 0x11c, 3, 8, 0);
        ov57_02238C30(PTR(w, 0xe4), (u8 *)w + 0xfc, 1, w, U32(w, 0x3ec));
        PlaySE(0x5dc);
        return 4;
    default:
        break;
    }
    ov57_02238134();
    ov57_0223853C(w);
    ov57_022394AC(w);
    U32(w, 0x3ec) = selection;
    ov57_0223B504(w, 0, 1);
    ov57_022383AC(w);
    ov57_02237F3C(w);
    ov57_022383D0(w, 1);
    ov57_02237F14(w);
    if (U32(w, 0x40c) == 0) {
        PlaySE(0x5dc);
    } else {
        ov57_02239728((u8 *)w + 0x11c, 3, 8, 0);
        ov57_02238C30(PTR(w, 0xe4), (u8 *)w + 0xfc, 1, w, U32(w, 0x3ec));
        PlaySE(0x5dc);
        return 4;
    }
    return 3;
}
