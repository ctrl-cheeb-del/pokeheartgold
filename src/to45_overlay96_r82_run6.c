#include "to45_overlay96_r82_private.h"

void ov96_0220329C(void *a, s32 values[][5], void *c, void *d, Ov96Out82 *out) {
    u8 *idx = ov96_021E60D8(a, c, d);
    out->unk04 = (double)(float)values[0][idx[4]] / 10.0;
    out->unk08 = (double)(float)values[1][idx[0]] / 10.0;
    out->unk10 = values[2][idx[4]];
    out->unk0C = (float)values[3][idx[3]];
    out->unk14 = 0;
    out->unk18 = 0;
    out->unk19 = 0;
    out->unk16 = 120;
}
