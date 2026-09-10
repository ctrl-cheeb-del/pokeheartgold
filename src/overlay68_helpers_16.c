#include "overlay68_helpers_internal.h"

u32 ov68_021E7A90(MoveRelearner *d, void *a1) {
    Ov68Sub1D0 *p = &d->unk_1D0;
    p->unk_0 = 0x18;
    p->unk_1 = 0x14;
    p->unk_2 = 8;
    p->unk_3 = 4;
    p->unk_4 = 0;
    p->unk_6 = 0;
    p->unk_8 = a1;
    return 13;
}

u32 ov68_021E7AB4(MoveRelearner *d, void *a1) {
    Ov68Sub1D0 *p = &d->unk_1D0;
    p->unk_0 = 15;
    p->unk_1 = 0x14;
    p->unk_2 = 8;
    p->unk_3 = 4;
    p->unk_4 = 0;
    p->unk_6 = 0;
    p->unk_8 = a1;
    return 13;
}
