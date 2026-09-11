#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

int ov70_0224304C(Ov70State *state) {
    if (!sub_020199E4(*(void **)((u8 *)state + 0x1C), 0)) {
        state->field4C = *(s32 *)((u8 *)state + 0x50);
    }
    return -1;
}

int ov70_02243068(Ov70State *state) {
    if (!sub_020199E4(*(void **)((u8 *)state + 0x1C), 0)) {
        sub_0201980C(*(void **)((u8 *)state + 0x1C), 0);
        state->field4C = *(s32 *)((u8 *)state + 0x50);
    }
    return -1;
}
