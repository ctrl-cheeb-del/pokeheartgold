#include "overlay49_animation_playback_r70_private.h"

void ov49_02265980(void *ctx, Ov49AnimationState *state, u32 index, const u8 *desc) {
    u32 offset;
    void **slot;

    if (index >= 18) {
        GF_AssertFail();
    }
    slot = (void **)state->descs;
    offset = index * 4;
    if (*(void **)((u8 *)slot + offset) != NULL) {
        GF_AssertFail();
    }
    *(void **)((u8 *)slot + offset) = (void *)desc;
    sub_020181B0((u8 *)state + 0xC + index * 0x78, (u8 *)ctx + 0x10550 + desc[0] * 0x10);
}
