#include "to47_overlay87_private.h"

void ov87_021E7244(State *p, int a, int b) {
    BufferIntegerAsString(*(void **)((u8 *)p + 0x3c), a, b, 1, 0, 1);
}
void ov87_021E725C(void *a, void *b, u32 v) {
    *((u8 *)a + 8) = 0;
    *(u32 *)b = v;
}
void ov87_021E7264(State *p) {
    int i = 0;
    u8 idx;
    do {
        do {
            idx = (u8)((s32)LCRandom() % 9);
        } while (((Cells360 *)p)->cells[idx] != 0xb0);
        ((Cells360 *)p)->cells[idx] = 4;
        i++;
    } while (i < 2);
}
