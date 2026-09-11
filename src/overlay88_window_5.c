#include "overlay88_window_internal.h"

void ov88_022594E0(void *p) {
    int i;
    u8 *a = p;
    u8 *w = a;
    i = 0;
    w += 0x60;
    {
        u8 *q = a;
        while (i < 3) {
            if (*a == 1) {
                ov88_022595F8(q, w);
            }
            i++;
            a += 0x20;
            w += 0x10;
            q += 0x20;
        }
    }
}

void ov88_02259508(void *p, void *bg, int row, int heap) {
    *(u8 *)p = 0;
    *(u16 *)((u8 *)p + 2) = 0;
    *(void **)((u8 *)p + 8) = String_New(0x100, heap);
    *((u8 *)p + 1) = row + 7;
    AddWindowParameterized(*(void **)bg, (u8 *)p + 0xC, 3, 0, 0, 0xB4, 2, 7, 0);
}
