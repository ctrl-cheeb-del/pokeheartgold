#include "r40_overlay_73_residual_4_private.h"

int ov73_021E6444(void *p, int result) {
    sub_020398D4(0, 1);
    if (sub_0203769C() == 0) {
        if (sub_02037454() >= 2) {
            ov73_021E756C(p, 2, 0);
        }
    } else {
        ov73_021E756C(p, 8, 0);
    }
    ov73_021E670C(p, 3);
    return result;
}

int ov73_021E6484(void *p, int result) {
    ov73_021E6508(p);
    if (sub_0203769C() == 0) {
        if (ov73_021E7340() != 1) {
            ov73_021E7468(p);
        }
    } else {
        ov73_021E7468(p);
    }
    return result;
}

int ov73_021E64B0(void *p) {
    if (U32(p, 0x314) == 1) {
        if (System_GetTouchHeld()) {
            return 0;
        }
        if (U32(gSystem, 0x44) != 0) {
            U32(p, 0x314) = 0;
            return 1;
        }
    } else {
        if (U32(gSystem, 0x44) != 0) {
            return 0;
        }
        if (System_GetTouchHeld()) {
            U32(p, 0x314) = 1;
            return 0;
        }
    }
    return 0;
}
