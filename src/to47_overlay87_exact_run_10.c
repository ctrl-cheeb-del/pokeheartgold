#include "to47_overlay87_private.h"

void ov87_021E7324(State *p) {
    ov87_021E7264(p);
    ov87_021E7294(p);
}
void ov87_021E7334(State *p) {
    int i;
    u8 *q = (u8 *)p;
    i = 0;
    do {
        q[0x360 + i] = 0xb0;
        i++;
    } while (i < 9);
}
