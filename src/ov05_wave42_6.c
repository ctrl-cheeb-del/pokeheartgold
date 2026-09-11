#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E5E4(R12 *w) {
    const u8 *tpl = ov05_0221ECE4;
    R12 *win = w;
    u32 i = 0;
    win += 0x10;
    do {
        AddWindow(P(w, 0xc), win, tpl);
        i++;
        tpl += 8;
        win += 16;
    } while (i < 24);
}

void ov05_0221E60C(R12 *w) {
    u32 i = 0;
    R12 *win = w + 0x10;
    do {
        RemoveWindow(win);
        i++;
        win += 16;
    } while (i < 24);
}
