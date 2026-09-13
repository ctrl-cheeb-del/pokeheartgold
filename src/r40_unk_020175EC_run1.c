#include "r40_unk_020175EC_private.h"

void sub_020175EC(Unk020175ECState *state) {
    void *b;
    void *a;
    void *newValue;
    u8 data[4];
    int result;

    sub_02017280(state, &data[0]);
    if (data[0] == 0x14) {
        sub_02017294(state, &data[3]);
        b = state->entries[data[3]];
        sub_0201726C(state, &a);
    } else if (data[0] == 0x15) {
        sub_020172B4(state, &data[3], &data[2]);
        b = state->entries[data[3]];
        a = state->entries[data[2]];
    } else {
        GF_AssertFail();
    }
    sub_02017280(state, &data[1]);
    if (data[1] > 0x11) {
        GF_AssertFail();
    }
    result = sub_02017470(&b, &a);
    sub_02017280(state, &data[0]);
    if (data[0] == 0x14) {
        sub_02017294(state, &data[3]);
        sub_0201726C(state, &newValue);
    } else if (data[0] == 0x15) {
        sub_020172B4(state, &data[3], &data[2]);
        newValue = state->entries[data[2]];
    } else {
        GF_AssertFail();
    }
    if (data[1] == result) {
        state->entries[data[3]] = newValue;
    }
}
