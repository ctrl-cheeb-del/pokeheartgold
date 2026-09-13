#include "r40_unk_020172C8_private.h"

void sub_020173C8(AnimState *state, u8 *outDestIndex, s32 *outRadians, s32 *outAmplitude) {
    u8 radiansIndex, amplitudeIndex, offsetIndex, readType;
    s32 radians, offset;

    sub_020172B4(state, outDestIndex, &radiansIndex);
    radians = state->variables[radiansIndex];
    sub_02017280(state, &readType);

    if (readType == 0x14) {
        sub_0201726C(state, outAmplitude);
    } else if (readType == 0x15) {
        sub_02017294(state, &amplitudeIndex);
        *outAmplitude = state->variables[amplitudeIndex];
    } else {
        GF_AssertFail();
    }

    sub_02017280(state, &readType);

    if (readType == 0x14) {
        sub_0201726C(state, &offset);
    } else if (readType == 0x15) {
        sub_02017294(state, &offsetIndex);
        offset = state->variables[offsetIndex];
    } else {
        GF_AssertFail();
    }

    *outRadians = radians + offset;
    *outRadians %= 0x10000;
}
