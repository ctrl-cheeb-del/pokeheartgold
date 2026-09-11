#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_0223D924(int value, int count, int delta) {
    value += delta;
    if (value < 0) {
        return count - 1;
    }
    if (value == count) {
        return 0;
    }
    return value;
}
