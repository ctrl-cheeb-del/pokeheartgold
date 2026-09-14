#include "to47_overlay49_transition_r66.h"

struct Overlay45State {
    u8 data[0x600];
};

struct Ov49Transition {
    u16 active;
    u16 value;
    u16 target;
    u16 initial;
    u32 current;
};

void GF_AssertFail(void);
u8 ov45_0222B034(Overlay45State *);
void ov45_0222AED8(Overlay45State *, u16);

void ov49_02265274(Ov49Transition *state, Overlay45State *object, u16 value, u16 target);
void ov49_0226529C(Ov49Transition *state, Overlay45State *object);

void ov49_02265274(Ov49Transition *state, Overlay45State *object, u16 value, u16 target) {
    if (state->active != 0) {
        GF_AssertFail();
    }
    state->active = 1;
    state->value = value;
    state->target = target;
    state->initial = ov45_0222B034(object);
}

void ov49_0226529C(Ov49Transition *state, Overlay45State *object) {
    if (state->active != 0) {
        state->current = ov45_0222B034(object);
        if (state->current == state->target) {
            ov45_0222AED8(object, state->value);
            state->active = 0;
            return;
        }
        if (state->current != state->initial) {
            state->active = 0;
        }
    }
}
