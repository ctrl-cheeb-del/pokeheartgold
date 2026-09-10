#include "overlay68_helpers_internal.h"

u32 ov68_021E7B6C(MoveRelearner *d) {
    ov68_021E6C14(d, 2);
    d->unk_1BA = 1;
    d->state = 3;
    return 2;
}

u32 ov68_021E7B8C(MoveRelearner *d) {
    return ov68_021E7B94(d);
}

u32 ov68_021E7B94(MoveRelearner *d) {
    u8 v;
    if (ov68_021E6CD8(d) < 4) {
        ov68_021E6C14(d, 1);
        v = 0;
    } else {
        ov68_021E6C14(d, 4);
        v = 2;
    }
    d->unk_1BA = v;
    d->state = 3;
    return 2;
}
