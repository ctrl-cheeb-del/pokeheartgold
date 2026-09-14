#include "to47_overlay87_private.h"

void ov87_021E6760(State *p) {
    int i;
    u8 *q = (u8 *)p;
    for (i = 0; i < 4; i++, q += 4) {
        void *x = *(void **)(q + 0x32c);
        if (x) {
            ov87_021E7FC0(x);
        }
    }
}
