#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_02243400(Ov70State *state) {
    extern void ov70_02241DB4(Ov70State *, int);
    ov70_02241DB4(state, 5);
    if (state->field3E >= 0) {
        state->field4C = 12;
    } else {
        state->field4C = 7;
    }
    return -1;
}

int ov70_02243420(Ov70State *state) {
    state->field4C = 8;
    return -1;
}
