#include "overlay_80_022310C4_opus_partial_internal.h"

void ov80_022314A0(TrHouse *s) {
    if (s != NULL) {
        if (s->party != NULL) {
            Heap_Free(s->party);
        }
        if (s->unkD8C != NULL) {
            Heap_Free(s->unkD8C);
        }
        MI_CpuFill8(s, 0, sizeof(TrHouse));
        Heap_Free(s);
    }
}

void ov80_022314DC(TrHouse *s, TrHouseSrc *src) {
    s->unk6F2 = ov80_02231518(src, 0);
    s->unk6F5 = s->unk6F2;
    s->unk6F4 = ov80_02237920(s->unk6F2);
    if (s->unk6F5 >= 0x11) {
        s->unk6F5 = 0x11;
    }
}

u16 ov80_02231518(TrHouseSrc *src, u32 unused) {
    return src->unk6;
}
