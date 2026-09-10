#include "pokepic_animation_decode_internal.h"

u32 sub_02017470(const s32 *a, const s32 *b) {
    s32 difference = *a - *b;
    if (difference < 0) {
        return 0xf;
    }
    if (difference > 0) {
        return 0x10;
    }
    return 0x11;
}

void sub_02017488(AnimState *state) {
    Pokepic_AddAttr(state->pic, 1, -state->scaleY / 8);
}

void sub_020174A4(AnimState *state) {
    sub_020174BC(state);
    state->complete = 1;
    state->stopped = 1;
}

void sub_020174B4(AnimState *state) {
    state->complete = 1;
}

void sub_020174BC(AnimState *state) {
    Pokepic_SetAttr(state->pic, 0, state->baseX);
    Pokepic_SetAttr(state->pic, 1, state->baseY);
    Pokepic_SetAttr(state->pic, 9, 0);
    Pokepic_SetAttr(state->pic, 10, 0);
    Pokepic_SetAttr(state->pic, 12, 0x100);
    Pokepic_SetAttr(state->pic, 13, 0x100);
}
