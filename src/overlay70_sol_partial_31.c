#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

void ov70_02240D44(Ov70State *state, u16 a, u16 b) {
    state->field11D4 = a;
    state->field11D6 = b;
}

BOOL ov70_02240D54(Ov70State *state) {
    if (!sub_0202DB54(*(void **)state->field00) && *(u16 *)((u8 *)state + 0x36) != 0) {
        return TRUE;
    }
    return FALSE;
}
