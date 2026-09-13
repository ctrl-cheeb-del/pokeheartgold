#include "r40_overlay_43_residual_23_private.h"

BOOL ov43_0222CE14(void *unused, int *state) {
    if (TouchscreenHitbox_FindHitboxAtTouchNew(ov43_0222ED7A) == 0) {
        *state = 1;
        return TRUE;
    }
    ov43_0222A320(state);
    if (*(u32 *)((u8 *)&gSystem + 0x48) & 3) {
        return TRUE;
    }
    return FALSE;
}
