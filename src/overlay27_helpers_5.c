#include "overlay_27_helpers_internal.h"

void ov27_0225A86C(Ov27Work *work) {
    ov27_0225A61C(work, ov27_0225A594(work));
    ov27_0225B398(work, -1);
    CopyWindowToVram(&work->window3D0);
    ov27_0225A690(work, 1);
}
