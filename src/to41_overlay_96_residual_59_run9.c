#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void ov96_021F6BB0(Ov96R59Work *w) {
    int i;
    u32 *t;
    Ov96R59Entry *e;
    t = w->unk1A0;
    e = (Ov96R59Entry *)((u8 *)w + 0xfac);
    for (i = 0; i < 3; i++) {
        if (e[i].unk14 == 0) {
            e[i].unk08 = t[t[0x380 + i]];
        }
    }
}

void ov96_021F6BE4(Ov96R59Slots *w, int slot, int idx, fx32 val) {
    int i;
    for (i = 0; i < 0x80; i++) {
        w->unk3A0[slot][i] = 0;
    }
    w->unk3A0[slot][idx] = val;
    ov96_021F6B50(idx, w->unk3A0[slot][idx], w->unk3A0[slot]);
}

void ov96_021F6C18(void *a) {
    ov96_021EB2BC(a, 0xa8, 3, 0x65, 3);
    ov96_021EB2F4(a, 0xa8, 0, 0x65, 3, 4);
    ov96_021EB334(a, 0xa8, 2, 0x65);
    ov96_021EB36C(a, 0xa8, 1, 0x65);
}
