#include "overlay_80_022310C4_opus_partial_internal.h"

void ov80_022319B0(TrHouse *s) {
    s32 i;

    if (s->kind == 2) {
        return;
    }
    for (i = 0; i < 0x11; i++) {
        if (sub_02030BD0(i, s->unk704[s->kind]) < 0xA) {
            break;
        }
    }
    if (i == 0x11) {
        for (i = 0; i < 0x11; i++) {
            sub_02030BF4(i, s->unk704[s->kind], 9);
        }
    }
}

void ov80_02231A04(TrHouse *s) {
    s->unkC = ov80_02237A40(ov80_022379C8(s));
}
