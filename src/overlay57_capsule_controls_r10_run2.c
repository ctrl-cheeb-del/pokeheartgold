#include "overlay57_capsule_controls_r10_private.h"

int ov57_0223B2EC(void *w) {
    int selection = ov57_0223B578(w);
    if (selection < 0) {
        return 3;
    }
    return ov57_0223B1A4(w, (u8)selection);
}

int ov57_0223B308(void *w) {
    ov57_0223B12C(w);
    if (U32(w, 0x40c) == 0) {
        return ov57_0223B3F8(w);
    }
    return ov57_0223B45C(w);
}
