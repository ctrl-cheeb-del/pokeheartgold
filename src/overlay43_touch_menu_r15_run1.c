#include "overlay43_touch_menu_r15_private.h"

int ov43_0222BC78(u8 *state, u8 *list, void *ctx, int input) {
    int col;
    int row;
    u32 count;

    if (input == 0) {
        PlaySE(0x5dd);
        ov43_0222C890(state + 8, ctx, S16_AT(state, 4), 1);
        return 3;
    }
    if (input == 5) {
        col = S16_AT(state, 4);
        if (col == 8) {
            PlaySE(0x5dd);
            ov43_0222C890(state + 8, ctx, S16_AT(state, 4), 1);
            return 3;
        }
        row = S16_AT(state, 0);
        count = U32_AT(list, 0x10);
        if (count <= (u32)(col + row * 8)) {
            return 0;
        }
        PlaySE(0x5dd);
        ov43_0222C890(state + 8, ctx, S16_AT(state, 4), 1);
        return 4;
    } else if (input == 1) {
        ov43_0222AD40(ctx, 0, 1);
        return 1;
    } else if (input == 2) {
        ov43_0222AD40(ctx, 1, 1);
        return 2;
    }
    return 0;
}
