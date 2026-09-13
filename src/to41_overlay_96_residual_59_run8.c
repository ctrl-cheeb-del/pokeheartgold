#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void ov96_021F6B28(Ov96R59Ball *a, Ov96R59Ball *b) {
    fx32 v;
    if (b->unk08 > 0) {
        v = a->unk08 + a->unk18;
        a->unk1C = v;
        if (v < 0x20000) {
            a->unk1C = 0x20000;
        } else if (v > 0xdf000) {
            a->unk1C = 0xdf000;
        }
    }
}
