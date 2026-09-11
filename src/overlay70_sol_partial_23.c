#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

BOOL ov70_0223E76C(void *mon) {
    u16 item = GetMonData(mon, 6, NULL);
    if (ItemIdIsMail(item)) {
        return TRUE;
    }
    return FALSE;
}
