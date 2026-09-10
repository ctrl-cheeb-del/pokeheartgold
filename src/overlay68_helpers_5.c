#include "overlay68_helpers_internal.h"

u32 ov68_021E6058(MoveRelearner *d) {
    if (TextPrinterCheckActive(d->unk_1B9) == 0) {
        return d->state;
    } else {
        return 2;
    }
}
