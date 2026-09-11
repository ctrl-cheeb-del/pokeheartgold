#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

BOOL ov70_0223E4DC(void *party, int unused, int value) {
    if (ov70_0223E490(value) && Party_GetCount(party) < 2) {
        return FALSE;
    }
    return TRUE;
}
