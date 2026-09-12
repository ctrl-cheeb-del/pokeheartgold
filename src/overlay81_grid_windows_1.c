#include "overlay81_grid_windows_internal.h"

void ov81_022413F4(void *work, int unused) {
    u32 x;
    u32 y;

    ov81_02243228(OV81_GRID_PTR(work, 0x464), unused, &x, &y);
    ov81_02242DAC(OV81_GRID_PTR(work, 0x388), x, y);
}

void ov81_0224141C(void *work, int unused) {
    u32 x;
    u32 y;

    ov81_02243228(OV81_GRID_PTR(work, 0x464), unused, &x, &y);
    ov81_02242DE4(OV81_GRID_PTR(work, 0x38C), 3);
    ov81_02242DAC(OV81_GRID_PTR(work, 0x38C), x, y);
}

void ov81_02241450(void *work) {
    ov81_02243140(OV81_GRID_PTR(work, 0x4C), OV81_GRID_PTR(work, 0x3DC), 0);
    ScheduleWindowCopyToVram((u8 *)work + 0x100);
    ScheduleWindowCopyToVram((u8 *)work + 0x130);
    if (!ov81_02242F40(OV81_GRID_PTR(work, 0x360 + OV81_GRID_U32(work, 0x468) * 4))) {
        ScheduleWindowCopyToVram((u8 *)work + 0x110);
    } else {
        ScheduleWindowCopyToVram((u8 *)work + 0x120);
    }
    GridInputHandler_SetNextInput(OV81_GRID_PTR(work, 0x464), 6);
    ov81_0224141C(work, 6);
    ov81_02243270(OV81_GRID_PTR(work, 0x464), 1);
    ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 1);
    ov81_02242E08(OV81_GRID_PTR(work, 0x388), 1);
}

void ov81_022414E0(void *work) {
    ov81_022431E0(OV81_GRID_PTR(work, 0x4C), 0);
    GridInputHandler_SetNextInput(OV81_GRID_PTR(work, 0x464), (u8)OV81_GRID_U32(work, 0x468));
    ov81_02243270(OV81_GRID_PTR(work, 0x464), 0);
    ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 0);
    ov81_02242E08(OV81_GRID_PTR(work, 0x388), 0);
}
