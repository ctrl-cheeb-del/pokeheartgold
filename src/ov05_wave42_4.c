#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E274(R12 *w) {
    T12 t = *(const T12 *)ov05_0221EAEC;
    u32 i;
    ov05_0221CD24(w, &t, 31);
    ov05_0221E2D8(w);
    ov05_0221E390(w);
    ov05_0221E42C(w);
    ov05_0221E4C8(w);
    for (i = 0; i < 6; i++) {
        ov05_0221E110(w, i);
    }
    ov05_0221E564(w, 16);
    U32(w, 0x210) = 30;
}
