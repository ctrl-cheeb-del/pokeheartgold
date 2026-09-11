#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E6144(R99 *w, u32 show) {
    s32 i;
    void *obj = P(w, 0x10);
    for (i = 0; i < 3; i++) {
        if (show) {
            ov98_0221EE28(obj, i + 14, ov99_021E5C4C(P(w, 0), (u8)U32(w, 0x88), (u8)i));
        } else {
            ov98_0221EE84(obj, i + 14);
        }
    }
}
