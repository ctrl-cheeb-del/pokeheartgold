#include "overlay81_grid_windows_internal.h"

void ov81_02241650(void *work, int selection) {
    u32 x;
    u32 y;

    ov81_02243228(OV81_GRID_PTR(work, 0x464), selection, &x, &y);
    if (selection == 3) {
        ov81_02242D88(OV81_GRID_PTR(work, 0x388), 0);
        ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 1);
        ov81_02242DE4(OV81_GRID_PTR(work, 0x38C), 6);
        ov81_02242DAC(OV81_GRID_PTR(work, 0x38C), x, y);
    } else {
        ov81_02242D88(OV81_GRID_PTR(work, 0x388), 1);
        ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 0);
        ov81_02242DAC(OV81_GRID_PTR(work, 0x388), x, y);
    }
}

void ov81_022416CC(void *work, int selection) {
    u32 x;
    u32 y;

    ov81_02243228(OV81_GRID_PTR(work, 0x464), selection, &x, &y);
    if ((u32)(selection - 4) <= 1) {
        ov81_02242D88(OV81_GRID_PTR(work, 0x388), 0);
        ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 1);
        ov81_02242DE4(OV81_GRID_PTR(work, 0x38C), 6);
        ov81_02242DAC(OV81_GRID_PTR(work, 0x38C), x, y);
    } else {
        ov81_02242D88(OV81_GRID_PTR(work, 0x388), 1);
        ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 0);
        ov81_02242DAC(OV81_GRID_PTR(work, 0x388), x, y);
    }
}

void ov81_0224174C(void *work) {
    ov81_022431E0(OV81_GRID_PTR(work, 0x4C), 3);
    ov81_02243140(OV81_GRID_PTR(work, 0x4C), OV81_GRID_PTR(work, 0x3DC), 0);
    ScheduleWindowCopyToVram((u8 *)work + 0x100);
    ScheduleWindowCopyToVram((u8 *)work + 0x140);
    ScheduleWindowCopyToVram((u8 *)work + 0x130);
    GridInputHandler_SetNextInput(OV81_GRID_PTR(work, 0x464), 4);
    ov81_0224141C(work, 4);
    ov81_02243314(OV81_GRID_PTR(work, 0x464), 1, OV81_GRID_U8(work, 9));
    ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 1);
}

void ov81_022417B4(void *work) {
    ov81_022431E0(OV81_GRID_PTR(work, 0x4C), 0);
    ov81_02243140(OV81_GRID_PTR(work, 0x4C), OV81_GRID_PTR(work, 0x3DC), 3);
    ScheduleWindowCopyToVram((u8 *)work + 0xF0);
    GridInputHandler_SetNextInput(OV81_GRID_PTR(work, 0x464), (u8)OV81_GRID_U32(work, 0x468));
    ov81_02243314(OV81_GRID_PTR(work, 0x464), 0, OV81_GRID_U8(work, 9));
    ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 0);
}

void ov81_02241804(void *work) {
    int selection = GridInputHandler_GetNextInput(OV81_GRID_PTR(work, 0x464));

    ov81_02243140(OV81_GRID_PTR(work, 0x4C), OV81_GRID_PTR(work, 0x3DC), 3);
    ScheduleWindowCopyToVram((u8 *)work + 0xF0);
    if (selection == 3) {
        ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 1);
    }
}
