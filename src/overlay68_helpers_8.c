#include "overlay68_helpers_internal.h"

u32 ov68_021E6678(MoveRelearner *d) {
    u16 *p = d->args->unk_10;
    u32 i;
    for (i = 0; i < 256; i++) {
        if (p[i] == 0xFFFF) {
            break;
        }
    }
    return i;
}
