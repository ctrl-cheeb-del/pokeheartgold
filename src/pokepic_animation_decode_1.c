#include "pokepic_animation_decode_internal.h"

void sub_020172C8(AnimState *state, u8 *first, s32 *out1, s32 *out2) {
    u8 args[4];
    sub_02017294(state, first);
    sub_02017280(state, &args[0]);
    if (args[0] == 0x12) {
        sub_02017294(state, &args[2]);
        *out1 = state->variables[args[2]];
        sub_0201726C(state, out2);
    } else if (args[0] == 0x13) {
        sub_020172B4(state, &args[2], &args[1]);
        *out1 = state->variables[args[2]];
        *out2 = state->variables[args[1]];
    } else {
        GF_AssertFail();
    }
}

void sub_0201733C(AnimState *state, u8 *first, s32 *out1, s32 *out2) {
    u8 args[4];
    sub_02017294(state, first);
    sub_02017280(state, &args[1]);
    sub_02017280(state, &args[0]);
    if (args[1] == 0x12) {
        sub_0201726C(state, out1);
    } else if (args[1] == 0x13) {
        sub_02017294(state, &args[3]);
        *out1 = state->variables[args[3]];
    } else {
        GF_AssertFail();
    }
    if (args[0] == 0x12) {
        sub_0201726C(state, out2);
    } else if (args[0] == 0x13) {
        sub_02017294(state, &args[2]);
        *out2 = state->variables[args[2]];
    } else {
        GF_AssertFail();
    }
}
