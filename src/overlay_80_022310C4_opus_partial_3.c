#include "overlay_80_022310C4_opus_partial_internal.h"

u8 ov80_022317C0(TrHouse *s) {
    s->idx++;
    return s->idx;
}

u8 ov80_022317CC(TrHouse *s) {
    return s->idx;
}

void ov80_022317D0(TrHouse *s, u32 a) {
    TrHouseWork work;
    Heap_Free(ov80_02229F04(&work, s->unk18[(u8)(a + s->idx * 2)], 0xB, 0xCC));
    ov80_0222A30C((u8)work.unk4);
}

void ov80_02231804(TrHouse *s) {
    sub_02030C34(s->unk704[s->kind]);
    ov80_0223157C(s, 1);
}

void ov80_02231828(TrHouse *s) {
    s->unk6 = 1;
    if (s->unkA < 0x12) {
        s->unkA++;
    }
    s->idx = 0;
    ov80_0223157C(s, 0);
}

void ov80_02231844(void *a, u32 kind, u32 c) {
    switch (kind) {
    case 0:
        ov80_0222AF10(a);
        break;
    case 1:
        ov80_0222AF54(a);
        break;
    case 2:
        ov80_0222AFB8(a);
        break;
    case 3:
        ov80_0222B024(a, c);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        ov80_0222B070(a);
        break;
    }
}

u8 ov80_02231888(TrHouse *s) {
    u8 kind = s->kind;
    u16 count = s->unkA;
    u8 ret;

    if (kind <= 1) {
        if (count >= 0x12) {
            ret = 0xC;
        } else {
            ret = ov80_0223BDFC[count];
        }
    } else {
        if (count >= 0x12) {
            ret = 0x17;
        } else {
            ret = ov80_0223BE10[count];
        }
    }
    if (kind == 0) {
        if (s->unk8 == 0x32 || s->unk8 == 0xAA) {
            ret = 0x14;
        }
    } else if (kind == 2) {
        ret = 0xC;
    }
    return ret;
}
