#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_022408BC(Ov70State *state) {
    if (Save_WriteFileAsync(*(void **)((u8 *)state->field00 + 0x20)) == 2) {
        state->state = state->field11D6;
        ov70_02238F80(state);
    }
    return 3;
}

int ov70_022408E0(Ov70State *state) {
    SetAllPCBoxesModified(state);
    Save_PrepareForAsyncWrite(*(void **)((u8 *)state->field00 + 0x20), 2);
    state->state = 35;
    return 3;
}
