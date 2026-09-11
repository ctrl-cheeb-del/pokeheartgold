#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_02240884(Ov70State *state) {
    s32 *counter = (s32 *)((u8 *)state + 0x11C0);
    (*counter)--;
    if (*counter == 0) {
        state->state = 32;
    }
    return 3;
}
