#include "r40_overlay_14_residual_64_private.h"

void ov14_021F69F0(u8 *p, int i) {
    u32 o = i * 16;
    sub_0200E948(*(u8 **)(p + 0x34) + 0x30 + o, 0x38e, 10);
    ScheduleWindowCopyToVram(*(u8 **)(p + 0x34) + 0x30 + o);
}
