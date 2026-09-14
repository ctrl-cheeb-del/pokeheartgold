#include "to45_overlay28_gap07_private.h"

void ov28_0225E0F4(To45Ov28Work *work) {
    s32 x = work->x * 8 + 0x54;
    s32 y = work->y * 8 + 0x64;

    work->angles[0].target = ov28_0225DE88(ov28_0225DE78(x - work->centerX, y - work->centerY));
    work->angles[1].target = ov28_0225DE88(ov28_0225DE78(x + 10 - work->centerX, y + 12 - work->centerY));
    work->angles[2].target = ov28_0225DE88(ov28_0225DE78(x - 12 - work->centerX, y - 4 - work->centerY));
    work->angles[3].target = ov28_0225DE88(ov28_0225DE78(x - 8 - work->centerX, y - 8 - work->centerY));
    work->value = 3;
}
