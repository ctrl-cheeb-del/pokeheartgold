#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221DE38(R12 *w) {
    ov05_0221DDEC(w, w + 0x544, 1);
    ov05_0221DDEC(w, w + 0x844, 2);
    ScheduleBgTilemapBufferTransfer(P(w, 0xc), 1);
    ScheduleBgTilemapBufferTransfer(P(w, 0xc), 2);
}
