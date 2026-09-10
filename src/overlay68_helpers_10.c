#include "overlay68_helpers_internal.h"

u16 ov68_021E6BEC(MoveRelearner *d) {
    MoveRelearnerArgs *args = d->args;
    return args->unk_10[args->unk_16 + args->unk_14];
}

u16 ov68_021E6BFC(MoveRelearner *d) {
    MoveRelearnerArgs *args = d->args;
    return GetMonData(args->unk_00, args->unk_1B + 0x36, NULL);
}
