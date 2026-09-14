#include "to45_overlay49_r73_private.h"

#pragma require_prototypes off

u32 ov49_02266A88(void *ctx, void *state) {
    u32 r = ov49_02267E18((u8 *)state + 0x954, S16_AT(state, 2));
    S16_AT(state, 2) = S16_AT(state, 2) + 1;
    if (r == 2) {
        return 1;
    }
    return 0;
}

u32 ov49_02266AB0(void *ctx, void *state) {
    u32 r = ov49_02267E18((u8 *)state + 0x954, S16_AT(state, 2));
    S16_AT(state, 2) = S16_AT(state, 2) + 1;
    if (r == 1) {
        ov49_02267D00(ctx, state);
    }
    ov49_02267D34(ctx, state);
    if (r == 2) {
        return 1;
    }
    return 0;
}

u32 ov49_02266AF0(void *ctx, void *state) {
    int i;
    if (ov49_02258F70(*(void **)((u8 *)state + 8)) == 1) {
        return 0;
    }
    for (i = 0; i < 0x12; i++) {
        if (ov49_02265968(state, i) == 1) {
            ov49_022659D0(ctx, state, i);
        }
    }
    return 1;
}
