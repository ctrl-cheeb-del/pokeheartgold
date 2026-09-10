#include "overlay39_helpers_internal.h"

u32 ov39_02227D44(Ov39Work *work, u32 **out) {
    *out = &work->unk17C;
    return work->unk17C;
}

void ov39_02227D50(Ov39Cb *cb, int a1) {
    cb->fn(cb->arg, a1);
}
