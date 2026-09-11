#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

u16 ov99_021E5B90(R99 *w, s32 i) {
    if (w == NULL) {
        GF_AssertFail();
    }
    if (i >= 5) {
        GF_AssertFail();
    }
    return U16((R99 *)P(w, 0) + i * 44, 6);
}

BOOL ov99_021E5BB4(R99 *w, s32 i) {
    if (w == NULL) {
        GF_AssertFail();
    }
    return ov99_021E5B90(w, i) != 0;
}
