#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E5D2C(R99 *w) {
    u8 i;
    NARC_Delete(P(w, 8));
    for (i = 0; i < 8; i++) {
        FreeBgTilemapBuffer(P(w, 4), _021E954C[i]);
    }
    Heap_Free(P(w, 4));
}
