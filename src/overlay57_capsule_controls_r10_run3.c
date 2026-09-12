#include "overlay57_capsule_controls_r10_private.h"

int ov57_0223B3A4(void *w, int selection) {
    switch (selection) {
    case 12:
        return ov57_0223B32C(w, 0);
    case 13:
        return ov57_0223B32C(w, 1);
    default:
        break;
    }
    U32(w, 0x3f0) = selection;
    ov57_0223B504(w, 1, 0);
    if (U32(w, 0x40c) == 0) {
        PlaySE(0x5dc);
    } else {
        return ov57_0223B32C(w, 1);
    }
    return 1;
}
