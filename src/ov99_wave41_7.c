#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E6400(R99 *w) {
    u8 i;
    void *a = ov98_0221E5C0(P(w, 0x14));
    void *b = ov98_0221E5D0(P(w, 0x14));
    for (i = 0; i < 3; i++) {
        ov98_0221E784(a, b, ov99_021E9650 + i * 16, 1);
    }
}
