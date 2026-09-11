#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_022396CC(Ov70State *state) {
    if (IsPaletteFadeFinished()) {
        state->state = 5;
    }
    return 3;
}

int ov70_022396E0(Ov70State *state) {
    if (IsPaletteFadeFinished()) {
        state->state = 5;
    }
    return 3;
}
