#include "trainer_ai_tail_helpers_r12_private.h"

u8 ov10_0221EF34(TrainerAITailState *state, u32 battler) {
    switch (battler) {
    case 1:
        return state->data[0x3CF];
    case 0:
    default:
        return state->data[0x3D0];
    case 3:
        return state->data[0x3CF] ^ 2;
    case 2:
        return state->data[0x3D0] ^ 2;
    }
}
