#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_02239954(Ov70State *state) {
    int gender = PlayerProfile_GetTrainerGender(*(void **)((u8 *)state->field00 + 0x1C));
    ov70_02241004(state, gender);
    state->state = 8;
    state->field11DC = 0;
    return 3;
}

int ov70_0223997C(Ov70State *state) {
    if (state->field11DC != 0) {
        state->state = 9;
    }
    return 3;
}
