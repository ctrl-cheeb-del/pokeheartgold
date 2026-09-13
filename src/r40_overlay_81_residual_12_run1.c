#include "r40_overlay_81_residual_12_private.h"

void ov81_02241A38(u8 *p) {
    int v = GridInputHandler_GetNextInput(*(void **)(p + 0x464));
    ov81_02243140(*(void **)(p + 0x4c), *(void **)(p + 0x3dc), 2);
    ScheduleWindowCopyToVram(p + 0xe0);
    ScheduleWindowCopyToVram(p + 0xf0);
    if ((u32)v >= 4) {
        ov81_02242D88(*(void **)(p + 0x38c), 1);
    }
}
