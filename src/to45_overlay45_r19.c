#include "global.h"

#include "to45_overlay45_r19_private.h"

void ov45_0222BD4C(Ov45R19State *state) {
    state->value = 0;
    state->mode = 0;
    state->byte_0A = 0;
    ov45_0222BE54(state);
}

void ov45_0222BD5C(Ov45R19State *state) {
    state->value = 0;
    state->mode = 4;
    ov45_0222BE54(state);
    state->byte_0A = 0;
}

BOOL ov45_0222BD74(Ov45R19State *state, u32 index) {
    GF_ASSERT(index < 20);
    return (state->flags & (1 << index)) != 0;
}

void ov45_0222BD94(Ov45R19State *state, u32 index) {
    GF_ASSERT(index < 20);
    state->flags |= 1 << index;
}

void ov45_0222BDB0(Ov45R19State *state, u32 index) {
    GF_ASSERT(index < 20);
    state->flags &= ~(1 << index);
}

void ov45_0222BDCC(Ov45R19State *state, u32 index) {
    int value;

    GF_ASSERT(index < 20);
    value = state->counters[index] + 1;
    if (value <= 6) {
        state->counters[index] = value;
    }
}

void ov45_0222BDE8(Ov45R19State *state, u32 index) {
    GF_ASSERT(index < 20);
    state->counters[index] = 0;
}
