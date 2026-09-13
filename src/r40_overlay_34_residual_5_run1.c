#include "r40_overlay_34_residual_5_private.h"

void ov34_0225DE04(Ov34State *state) {
    U16_AT(state, 0x284) = S32_AT(PTR_AT(state, 0x270), 0x348);
    if (U16_AT(state, 0x284) > 3 && U16_AT(state, 0x286) <= 3) {
        U16_AT(state, 0x28A) = 1;
        U16_AT(state, 0x288) = U16_AT(state, 0x284) - 3;
    }
    Sprite_SetDrawFlag(PTR_AT(state, 0x1A0), U16_AT(state, 0x28A));
    if (U16_AT(state, 0x28A) != 0 && ov34_0225E5E4(state) == (void *)1) {
        ov34_0225DDB8(PTR_AT(state, 0x1A0), 0x30 + (U16_AT(state, 0x288) * 0x60) / (U16_AT(state, 0x284) - 3));
    }
    U16_AT(state, 0x286) = U16_AT(state, 0x284);
}
