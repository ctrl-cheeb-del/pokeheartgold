#include "trainer_ai_tail_helpers_r12_private.h"

BOOL ov10_0221F5F4(TrainerAITailState *state, int battler) {
    u8 *battlerData = &state->data[battler * 0xC0];

    if ((*(u32 *)&battlerData[0x2DC0] & 0x20) && ((*(u32 *)&battlerData[0x2DC8] << 17) >> 30) == 0) {
        (&state->data[battler])[0x21A4] = 6;
        return TRUE;
    }
    return FALSE;
}
