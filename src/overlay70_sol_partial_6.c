#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

void ov70_02238F04(Ov70State *state) {
    if (state->field3A != 0) {
        state->field3A--;
    }
}

void ov70_02238F10(Ov70State *state) {
    state->field11FA = 1;
    state->field11F8 = 0;
}
