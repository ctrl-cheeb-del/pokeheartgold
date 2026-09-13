#include "to42_overlay49_r73a_private.h"

#pragma require_prototypes off

void ov49_02267074(void *ctx, void *state) {
    VecFx32 v;
    ov49_02259154((void *)U32_AT(state, 8), &v);
    ov49_0226540C((u8 *)state + 0xA04, v.x, v.x, v.y, v.y - 0x2000, v.z, v.z, 1);
    U16_AT(state, 0x956) = 0;
    U8_AT(state, 0x954) = 0;
}

u32 ov49_022670B8(void *ctx, void *state) {
    if (U8_AT(state, 0x965) == 0) {
        return ov49_022670D4(ctx, state);
    }
    return ov49_02267328(ctx, state);
}
