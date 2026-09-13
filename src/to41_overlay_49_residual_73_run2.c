#include "to41_overlay_49_residual_73_private.h"

#pragma require_prototypes off

u32 ov49_02267674(void *state);
void ov49_0226789C(void *ctx, void *state, u32 i);

void ov49_02267A84(void *ctx, void *state, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        VecFx32 v;
        ov49_02265980(ctx, state, i, &ov49_0226A70C[i]);
        ov49_02259154((void *)U32_AT(state, 8), &v);
        v.y += 0x8000;
        v.z += 0x6000;
        sub_020182A8(&OV49_ENTRIES(state)[i], v.x, v.y, v.z);
        sub_020182A0(&OV49_ENTRIES(state)[i], 0);
    }
    U8_AT(state, 0x954) = count;
}
