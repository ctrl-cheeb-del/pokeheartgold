#include "to41_overlay_49_residual_73_private.h"

#pragma require_prototypes off

u32 ov49_02267674(void *state);
void ov49_0226789C(void *ctx, void *state, u32 i);

u32 ov49_02266E78(void *ctx, void *state) {
    VecFx32 v;
    u32 result;
    int i;
    result = ov49_02265434((u8 *)state + 0xA04, S16_AT(state, 0x956));
    ov49_02265628((u8 *)state + 0xA2C);
    S16_AT(state, 0x956)
    ++;
    ov49_02259154((void *)U32_AT(state, 8), &v);
    ov49_022655E0((u8 *)state + 0xA04, &v.x, &v.y, &v.z);
    ov49_02259148((void *)U32_AT(state, 8), &v);
    ov49_02267674(state);
    for (i = 0; i < S8_AT(state, 0x955); i++) {
        ov49_0226789C(ctx, state, i);
    }
    return result;
}
