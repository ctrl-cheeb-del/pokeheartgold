#include "r40_overlay_45_thumb_residual_14_private.h"

extern BOOL ov45_0222BE74(void *state);
extern void ov45_0222BE94(void *state);

BOOL ov45_0222B048(u8 *state, u32 index) {
    GF_ASSERT(index < 20);
    if (state[0x1CC + index] >= 6) {
        return FALSE;
    }
    return TRUE;
}

BOOL ov45_0222B06C(u8 *state) {
    if (state[0x1C6] == 4) {
        return TRUE;
    }
    if (ov45_0222BE74(state + 0x1C0) == FALSE) {
        return TRUE;
    }
    return FALSE;
}

void ov45_0222B094(u8 *state) {
    ov45_0222BE94(state + 0x1C0);
}
