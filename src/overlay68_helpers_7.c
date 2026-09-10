#include "overlay68_helpers_internal.h"

u32 ov68_021E61EC(MoveRelearner *d) {
    sub_020880CC(1, HEAP_ID_66);
    d->state = 9;
    return 0;
}

void ov68_021E6204(MoveRelearner *d) {
    u16 move = ov68_021E6BEC(d);
    if (move != 0xFFFF) {
        ov68_021E68D4(d, move);
    } else {
        ov68_021E68D4(d, -2);
    }
    ov68_021E70BC(d);
}
