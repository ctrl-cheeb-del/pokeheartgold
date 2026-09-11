#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

void ov70_02238D60(Ov70State *state) {
    TouchscreenListMenu_Destroy(*(void **)((u8 *)state + 0x11D0));
    TouchscreenListMenuSpawner_Destroy(*(void **)((u8 *)state + 0x11CC));
    ov70_02238FE0();
}

void ov70_02238D84(Ov70State *state, u32 a, u32 b) {
    state->state = a;
    state->field30 = b;
}
