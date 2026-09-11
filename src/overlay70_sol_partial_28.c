#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_02240838(Ov70State *state) {
    ov70_02238D84(state, 37, 30);
    ov70_02240D44(state, 33, 36);
    return 3;
}
