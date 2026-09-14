#include "to47_overlay49_state_reset_r7p2_private.h"

void ov49_02258EEC(void *arg0, Ov49Res7P2State *state, int index)
{
    if (index >= 10) {
        GF_AssertFail();
    }
    if (ov49_02269698[state->unk0B] != NULL) {
        ov49_02269698[state->unk0B](state, arg0);
    }
    state->unk08 = 0;
    state->unk0A = 0;
    state->unk0B = index;
    memset(state->unk0C, 0, sizeof(state->unk0C));
    state->unk24 = ov49_022696C0[index];
}
