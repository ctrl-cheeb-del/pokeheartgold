#include "r40_overlay_35_private.h"

void ov35_02259D80(Ov35State *state, u32 event) {
    switch (event) {
    case 0:
        break;
    case 1:
        state->unk04 = 1;
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        if (state->unk02 == 2 && state->callback != NULL) {
            state->callback(state->callbackArg);
        }
        break;
    case 5:
        break;
    }
}

u8 ov35_02259DB8(Ov35State *state) {
    return state->unk03;
}
