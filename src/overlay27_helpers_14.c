#include "overlay_27_helpers_internal.h"

void ov27_0225C0E0(Ov27Work *work) {
    u32 v = (work->unk51C.raw << 27) >> 28;
    if (v == 1) {
        ov27_0225C044(work);
        return;
    }
    if (v == 2) {
        ov27_0225C088(work);
        return;
    }
    if (v == 3) {
        ov27_0225C06C(work);
    }
}
