#include "overlay88_window_internal.h"

void ov88_02259280(u8 *out, void *a, void *b, void *c) {
    int i;
    for (i = 0; i < 4; i++) {
        int n = ov45_0222DDE4(a, b, i);
        if (n != 20) {
            if (ov45_0222AB28(c, n) == 1) {
                out[i] = 9;
            } else {
                out[i] = 5;
            }
        }
    }
}
