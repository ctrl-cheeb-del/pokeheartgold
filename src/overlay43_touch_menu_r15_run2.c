#include "overlay43_touch_menu_r15_private.h"

int ov43_0222BEEC(u8 *state, void *list, void *ctx, int *touched) {
    u32 hit;
    int delta;

    hit = TouchscreenHitbox_FindHitboxAtTouchNew(ov43_0222EF60);
    if (hit == (u32)-1) {
        return 0;
    }
    if (hit <= 8) {
        *touched = 1;
        S16_AT(state, 4) = hit;
        PlaySE(0x5e5);
        ov43_0222C844(state + 8, ctx, S16_AT(state, 4));
        return ov43_0222BC78(state, list, ctx, 5);
    }
    if (hit == 9) {
        delta = -1;
    } else if (hit == 10) {
        delta = 1;
    } else {
        delta = (s8)((hit - 11) - S16_AT(state, 0));
    }
    if (delta == 0) {
        return 0;
    }
    *touched = 1;
    S16_AT(state, 2) = S16_AT(state, 0);
    S16_AT(state, 0) += delta;
    if (delta >= 0) {
        S16_AT(state, 0) %= 4;
        return ov43_0222BC78(state, list, ctx, 2);
    }
    if (S16_AT(state, 0) < 0) {
        S16_AT(state, 0) += 4;
    }
    return ov43_0222BC78(state, list, ctx, 1);
}
