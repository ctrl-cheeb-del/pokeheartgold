#include "to45_overlay49_r73_private.h"

#pragma require_prototypes off

u32 ov49_0226676C(void *ctx, void *state) {
    int i;
    int current;
    u32 result;

    current = (S16_AT(state, 2) * 3) / 32;
    if (current != S16_AT(state, 0x954)) {
        S16_AT(state, 0x954) = current;
        if ((u32)S16_AT(state, 0x956) > (u32)current) {
            if (current != 0) {
                sub_020182A0(&OV49_R73_ENTRIES(state)[current - 1], 0);
            }
            sub_020182A0(&OV49_R73_ENTRIES(state)[current], 1);
        }
    }
    if (S16_AT(state, 2) < 32) {
        S16_AT(state, 2)
        ++;
    }
    result = 0;
    for (i = 0; i < S16_AT(state, 0x956); i++) {
        if (sub_020182A4(&OV49_R73_ENTRIES(state)[i])) {
            if (i == S16_AT(state, 0x956) - 1) {
                result = ov49_02265B28(ctx, state, i, 0);
            } else {
                ov49_02265B14(ctx, state, i, 0);
            }
        }
    }
    return result;
}
