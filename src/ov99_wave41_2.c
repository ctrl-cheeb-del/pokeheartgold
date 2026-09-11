#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

u8 ov99_021E5C20(R99 *w, s32 i, u32 j) {
    const u8 *p;
    if (w == NULL) {
        GF_AssertFail();
    }
    if (i >= 10) {
        GF_AssertFail();
    }
    if (j >= 4) {
        GF_AssertFail();
    }
    p = ov99_021E9600 + i * 4;
    return p[j];
}

u16 ov99_021E5C4C(R99 *w, u32 i, u32 j) {
    R99 *p;
    if (w == NULL) {
        GF_AssertFail();
    }
    if (j >= 3) {
        GF_AssertFail();
    }
    if (i >= 5) {
        GF_AssertFail();
    }
    p = P(w, 0);
    p += i * 44;
    p += j * 12;
    return ((Ov99Bits *)p)->value;
}
