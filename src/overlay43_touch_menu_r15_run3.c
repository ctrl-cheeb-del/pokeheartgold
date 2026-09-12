#include "overlay43_touch_menu_r15_private.h"

void ov43_0222BFD4(u8 *state, void *arg1, void *ctx, int arg3) {
    int selector;

    if (U16_AT(state, 0xb2) == 2) {
        selector = 2;
    } else {
        selector = 1;
    }
    ov43_0222C378(state, arg1, ctx, S16_AT(state, 0), S16_AT(state, 4), selector, arg3);
    ov43_0222C844(state + 8, ctx, 10);
    ov43_0222AD20(ctx, 0);
    PlaySE(0x5e1);
}
