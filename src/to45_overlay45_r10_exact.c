#include "to45_overlay45_r10_private.h"

u32 ov45_0222A9CC(Overlay45Residual10State *state) {
    u32 result;
    u32 i;

    if (state->state_038 >= 2) {
        if (ov45_0222CD04(state->value_03A) != 0xFFFF) {
            for (i = 0; i < 16; i++) {
                if (ov45_02254A84[i].value == state->value_03A) {
                    result = ov45_02254A84[i].value;
                }
            }
        } else {
            result = 1;
        }
    } else {
        result = state->state_038;
    }
    return result;
}

u32 ov45_0222AA10(Overlay45Residual10State *state) {
    if (ov45_0222AA28(state) == TRUE) {
        return state->mode_039;
    }
    return 2;
}

BOOL ov45_0222AA28(Overlay45Residual10State *state) {
    switch (state->mode_039) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        return TRUE;
    default:
        return FALSE;
    }
}
