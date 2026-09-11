#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_02238E44(void) {
    return 3 - ov00_021EC9D4();
}

void ov70_02238E50(Ov70State *state, u32 a, u32 b) {
    state->field18 = a;
    state->field24 = b;
}

void ov70_02238E58(Ov70State *state) {
    state->field20 = state->field14;
    state->field14 = state->field18;
}

int ov70_02238E64(Ov70State *state) {
    return Options_GetTextFrameDelay(*(void **)((u8 *)state->field00 + 0x24));
}
