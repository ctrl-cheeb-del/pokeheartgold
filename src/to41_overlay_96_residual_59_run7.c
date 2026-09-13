#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

u8 ov96_021F65D8(Ov96R59Cnt *c) {
    if (c->unk24 < 5) {
        c->unk24++;
    }
    c->unk20 = c->unk20 + c->unk24;
    if (c->unk20 > 999) {
        c->unk20 = 999;
    }
    return (u8)c->unk24;
}
