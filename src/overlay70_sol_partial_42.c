#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_02244834(Ov70State *state) {
    sub_0203946C(state);
    ov00_021EC8D8();
    ov70_02238E50(state, 0, 0);
    state->state = 19;
    return 3;
}
