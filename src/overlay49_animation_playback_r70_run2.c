#include "overlay49_animation_playback_r70_private.h"

void ov49_02265B14(void *ctx, Ov49AnimationState *state, u32 index, u32 animation) {
    ov49_02265B3C(ctx, state, index, animation, 0x2000);
}

BOOL ov49_02265B28(void *ctx, Ov49AnimationState *state, u32 index, u32 animation) {
    return ov49_02265B94(ctx, state, index, animation, 0x2000);
}

void ov49_02265B3C(void *ctx, Ov49AnimationState *state, u32 index, u32 animation, s32 step) {
    const u8 *desc = state->descs[index];
    s32 duration = sub_020181A4((u8 *)ctx + 0x106DC + desc[2 + animation] * 0x14);
    s32 next = state->frames[index][animation] + step;

    if (next < duration) {
        state->frames[index][animation] = next;
    } else {
        state->frames[index][animation] = (state->frames[index][animation] + 0x2000) % duration;
    }
}
