#include "trainer_ai_tail_helpers_r12_private.h"

BOOL ov10_0222036C(void *battleSystem, TrainerAITailState *state, int battler) {
    u8 *battlerData;
    int i;
    u8 sum;

    sum = 0;
    i = 0;
    battlerData = state->data + battler * 0xC0 + i;

    for (; i < 8; i++) {
        if (*(s8 *)&battlerData[0x2D58] > 6) {
            sum += *(s8 *)&battlerData[0x2D58] - 6;
        }
        battlerData++;
    }
    return sum >= 4;
}
