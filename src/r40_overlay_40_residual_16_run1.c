#include "r40_overlay_40_residual_16_private.h"

void ov40_0222FA2C(void *p, int target) {
    int delta = target - S32(p, 0xC);
    if (delta * delta >= 0x100) {
        S16(p, 0x10) = delta < 0 ? -1 : 1;
        S32(p, 0xC) = target;
    } else {
        S16(p, 0x10) = 0;
    }
}

void ov40_0222FA5C(void *p, void *q) {
    if (U32(q, 0x48) != 0) {
        if (S32(q, 4) < 2) {
            U32(p, 0x14) = 0;
            return;
        }
        U32(p, 0x14) = 1;
        return;
    } else {
        if (S32(q, 0x10) >= S32(q, 4)) {
            U32(p, 0x14) = 0;
            return;
        }
        U32(p, 0x14) = 1;
        return;
    }
}

void ov40_0222FA88(void *p) {
    u32 x, y;
    BOOL held;
    int hit = 0;
    held = System_GetTouchHeldCoords(&x, &y);
    if (U32(p, 0x14) != 0) {
        ManagedSprite_TickTwoFrames((void *)U32(p, 0x18));
        ManagedSprite_TickTwoFrames((void *)U32(p, 0x1C));
    }
    if (U32(p, 4) == 0 && held == 0) {
        U32(p, 4) = 0;
        U32(p, 0) = 0;
        U32(p, 8) = 0;
        U32(p, 0xC) = 0;
        S16(p, 0x10) = 0;
        return;
    }
    if (TouchscreenHitbox_TouchHeldIsIn(ov40_02244E08) || TouchscreenHitbox_TouchHeldIsIn(ov40_02244E0C)) {
        hit = 1;
    }
    if (hit) {
        if (U32(p, 4) == 0) {
            U32(p, 4) = 1;
            U32(p, 8) = x;
            U32(p, 0xC) = y;
            U32(p, 0) = 2;
        } else {
            U32(p, 0)
            --;
            ov40_0222FA2C(p, y);
        }
    } else if (U32(p, 4) != 0) {
        U32(p, 4) = 0;
        U32(p, 0) = 0;
        U32(p, 8) = 0;
        U32(p, 0xC) = 0;
    }
}
