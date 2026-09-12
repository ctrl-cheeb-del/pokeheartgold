#include "overlay80_frontier_setup_r22_private.h"

void ov80_022372D8(u32 a, int n, u32 c, u32 d, u16 *out) {
    int i;
    u32 cl;
    u16 *dst;
    const u16 *t1;
    const u16 *t2;

    i = 0;
    cl = ov80_022379C0(c);
    dst = out + (d & 0x7f) * 2;
    t1 = &ov80_0223C698[(u8)cl * 8];
    t2 = &ov80_0223C608[a * 4];
    do {
        u16 r = LCRandom() % 12;
        if (r < 8) {
            *dst = t1[r];
        } else {
            *dst = t2[r - 8];
        }
        i++;
        dst++;
    } while (i < n);
}
