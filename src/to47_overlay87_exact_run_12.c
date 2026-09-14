#include "to47_overlay87_private.h"

void ov87_021E7550(State *p) {
    int i;
    u8 *q;
    i = 0;
    if (i < *(u16 *)((u8 *)p + 0x3b8)) {
        q = (u8 *)p;
        do {
            ov87_021E7590(p, (u8) * (u16 *)(q + 0x3ba), (u8) * (u16 *)(q + 0x3bc));
            i++;
            q += 8;
        } while (i < *(u16 *)((u8 *)p + 0x3b8));
    }
}
