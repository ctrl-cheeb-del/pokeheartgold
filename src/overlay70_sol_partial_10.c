#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

void ov70_0223963C(Ov70State *state) {
    String_Delete(*(void **)((u8 *)state + 0xBBC));
    String_Delete(*(void **)((u8 *)state + 0xBC0));
}
