#include "r40_overlay_75_residual_10_private.h"

BOOL ov75_02248584(Ov75Residual10State *state) {
    int input;

    if (ov75_02249534(state->printer) == 1) {
        return FALSE;
    }

    switch (state->state) {
    case 0:
        state->state++;
        break;
    case 1:
        ov75_022494CC(state, state->message34, 0xB, 1, 0xF0F);
        state->state++;
        break;
    case 2:
        state->prompt = ov75_02247890(state->context, 0x234, 0);
        state->state++;
        break;
    case 3:
        input = YesNoPrompt_HandleInput(state->prompt);
        if (input == 1) {
            YesNoPrompt_Destroy(state->prompt);
            state->state++;
        } else if (input == 2) {
            YesNoPrompt_Destroy(state->prompt);
            ov75_02247854(state, 0x22, 0);
        }
        break;
    case 4:
        if (sub_0203A05C(((Ov75Residual10Work *)state->work)->saveData) == 0) {
            ov75_02246BCC(state->work, 5, 0);
            ov75_02246BE0(state->work, 0xC);
            state->next = 0x1D;
            return FALSE;
        }
        ov75_02247854(state, 0x22, 0xC);
        break;
    }

    return FALSE;
}

BOOL ov75_02248684(Ov75Residual10State *state) {
    int input = YesNoPrompt_HandleInput(state->prompt);

    if (input == 1) {
        YesNoPrompt_Destroy(state->prompt);
        ov75_022494CC(state, state->message2C, 1, 1, 0xF0F);
        ov75_02247854(state, 0x22, 0xC);
        ov75_0224785C(state);
    } else if (input == 2) {
        YesNoPrompt_Destroy(state->prompt);
        sub_0203957C();
        ov75_02246BCC(state->work, 6, 0);
        state->next = 0x1D;
    }

    return FALSE;
}

BOOL ov75_022486EC(Ov75Residual10State *state) {
    ov75_022494CC(state, state->message30, 0x1A, 1, 0xF0F);
    ov75_02247854(state, 0x22, 0xA);
    return FALSE;
}
