#include "overlay_27_helpers_internal.h"

void ov27_0225A66C(Ov27Work *work) {
    s32 v = ov27_0225A594(work);
    if (work->unk510 != v) {
        ov27_0225A61C(work, v);
        work->unk510 = v;
    }
}
