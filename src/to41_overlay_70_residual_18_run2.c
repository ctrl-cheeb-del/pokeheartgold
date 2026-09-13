#include "to41_overlay_70_residual_18_private.h"

void ov70_0223AF30(R14Work *w) {
    String_Delete(P(w, 0xbc4));
    String_Delete(P(w, 0xbc8));
    String_Delete(P(w, 0xbbc));
}

int ov70_0223AF5C(R14Work *w) {
    Sprite_SetDrawFlag(P(w, 0xf10), 0);
    if (U32(w, 0x24) == 0x10) {
        BeginNormalPaletteFade(0, 1, 1, 0, 0x10, 1, 0x3d);
        U32(w, 0x2c) = 7;
    } else {
        U32(w, 0x2c) = 1;
        Sprite_SetDrawFlag(P(w, 0xf0c), 1);
    }
    return 3;
}
