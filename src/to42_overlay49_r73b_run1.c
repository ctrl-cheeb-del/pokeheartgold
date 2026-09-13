#include "to42_overlay49_r73b_private.h"

#pragma require_prototypes off

void ov49_02267D00(void *ctx, void *state) {
    int i;
    U16_AT(state, 0xD0C) = 1;
    U16_AT(state, 0xD0E) = 0;
    for (i = 0; i < 2; i++) {
        sub_020182A0(&OV49_ENTRIES(state)[i + 0x10], 1);
    }
}

void ov49_02267D34(void *ctx, void *state) {
    int i;
    if (U16_AT(state, 0xD0C) != 0) {
        if (U16_AT(state, 0xD0E) < 13) {
            U16_AT(state, 0xD0E)
            ++;
        } else {
            U16_AT(state, 0xD0C) = 0;
        }
        for (i = 0; i < 2; i++) {
            if (U16_AT(state, 0xD0E) < 13) {
                ov49_02265B14(ctx, state, i + 0x10, 0);
            } else {
                sub_020182A0(&OV49_ENTRIES(state)[i + 0x10], 0);
            }
        }
    }
}
