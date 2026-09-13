#include "to41_overlay_70_residual_18_private.h"

int ov70_0223C8B0(R14Work *w) {
    P(w, 0x11c8) = ov70_02238C14(P(w, 4), 0xc, 0x120, 3, 1);
    U32(w, 0x2c) = 0x18;
    return 3;
}

int ov70_0223C8DC(R14Work *w) {
    int result = ov70_02238C8C(w);

    if (result == 1) {
        YesNoPrompt_Destroy(P(w, 0x11c8));
        U32(w, 0x2c) = 2;
        ov70_02238E50(w, 1, 0);
        ov70_02241234(w);
        U32(w, 0x128) = 0;
    } else if (result == 2) {
        YesNoPrompt_Destroy(P(w, 0x11c8));
        U32(w, 0x2c) = 0;
    }
    return 3;
}
