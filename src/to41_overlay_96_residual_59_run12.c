#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void ov96_021F7130(Ov96R59Ball *a) {
    fx32 v = a->unk18;
    if (v == 0) {
        return;
    }
    if (v > 0) {
        v -= 0x2000;
        a->unk18 = v;
        if (v < 0) {
            a->unk18 = 0;
        }
    } else if (v < 0) {
        v += 0x2000;
        a->unk18 = v;
        if (v > 0) {
            a->unk18 = 0;
        }
    }
}

void ov96_021F715C(void *a0, Ov96R59Triple *t, void *a2, Ov96R59Dst *d) {
    u8 idx = ov96_021E5F24(a0);
    Ov96R59Sel *s = ov96_021E60D8(a0, idx, a2);
    d->unk2C = t->a[s->unk02];
    d->unk30 = t->b[s->unk03];
    d->unk34 = t->c[s->unk04];
}
