#include "overlay_27_helpers_internal.h"

void ov27_0225A7B0(Ov27Work *work) {
    if (sub_0203DF8C(work->unk10) == 1) {
        ov27_0225A66C(work);
    }
    if (((work->unk51C.raw << 27) >> 28) == 0) {
        ov27_0225AAD4(work);
    }
}

void ov27_0225A7DC(Ov27Work *work) {
    GF_ASSERT(work->unk14 < 7);
    ov27_0225B398(work, work->unk14);
    ov27_0225A690(work, 0);
}
