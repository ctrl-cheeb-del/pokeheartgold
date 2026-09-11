#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E07C(R12 *w) {
    memset(w + 0x214, 0, 0x90);
    ov05_0221DF38(w, P(P(w, 0), 4), 0);
    ov05_0221DF38(w, P(P(w, 0), 0xc), 3);
}
