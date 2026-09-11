#include "overlay70_sol_partial_internal.h"

#define DEFINE_PRINTER_WAIT(name)                    \
    int name(Ov70State *state) {                     \
        u32 printer = *(u32 *)((u8 *)state + 0xBF0); \
        if (!TextPrinterCheckActive(printer)) {      \
            state->state = state->field30;           \
        }                                            \
        return 3;                                    \
    }

void ov70_0223F948(Ov70PairArrays *data) {
    int i;
    for (i = 0; i < 10; i++) {
        data->a[i] = 0;
        data->b[i] = 0;
    }
    data->first = 0;
    data->second = 0;
}

void ov70_0223F960(Ov70PairArrays *data, int i, u16 a, u16 b) {
    data->a[i] = a;
    data->b[i] = b;
}
