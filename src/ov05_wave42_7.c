#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E714(R12 *w, u32 unused, void *a, u32 unused2, u32 unused3, u32 index) {
    void *win = w + 0x10 + ((index * 4 + 1) * 16);
    sub_0200CE7C(a, 1, *(u8 *)(w + index * 24 + 0x220), 3, 0, win, 0, 2);
}

void ov05_0221E74C(R12 *w, u32 unused, void *a, u32 unused2, u32 unused3, u32 index) {
    void *win = w + 0x10 + ((index * 4 + 2) * 16);
    PrintUIntOnWindow(a, U16(w, index * 24 + 0x21a), 3, 1, win, 0, 2);
    sub_0200CDAC(a, 0, win, 24, 2);
    PrintUIntOnWindow(a, U16(w, index * 24 + 0x21c), 3, 0, win, 32, 2);
}
