#include "overlay88_window_internal.h"

void ov88_02259244(void *a, void *b, void *c, void *d, u32 tick) {
    int mode;
    if ((tick & 7) != 0) {
        return;
    }
    tick >>= 3;
    if ((tick & 1) == 0) {
        mode = 2;
    } else {
        mode = 0;
    }
    ov88_0225918C(a, b, c, d, mode);
}
