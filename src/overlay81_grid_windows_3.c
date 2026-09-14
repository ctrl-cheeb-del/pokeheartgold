#include "bg_window.h"
#include "overlay81_grid_windows_internal.h"
#include "unk_02019BA4.h"

void ov81_0224185C(void *work) {
    FillWindowPixelBuffer((Window *)((u8 *)work + 0x100), 2);
    FillWindowPixelBuffer((Window *)((u8 *)work + 0x140), 2);
    FillWindowPixelBuffer((Window *)((u8 *)work + 0x130), 2);
    FillWindowPixelBuffer((Window *)((u8 *)work + 0xF0), 2);

    ov81_022430B4((u8 *)work + 0x100, OV81_GRID_PTR(work, 0x1C), 0x14, GetWindowWidth((Window *)((u8 *)work + 0x100)) * 8 / 2, 0, 4, 0xF0E02, 2);
    ov81_022430B4((u8 *)work + 0x140, OV81_GRID_PTR(work, 0x1C), 0x15, GetWindowWidth((Window *)((u8 *)work + 0x140)) * 8 / 2, 0, 4, 0xF0E02, 2);
    ov81_022430B4((u8 *)work + 0x130, OV81_GRID_PTR(work, 0x1C), 0x16, GetWindowWidth((Window *)((u8 *)work + 0x130)) * 8 / 2, 0, 4, 0xF0E02, 2);
    ov81_022430B4((u8 *)work + 0xF0, OV81_GRID_PTR(work, 0x1C), 0x13, GetWindowWidth((Window *)((u8 *)work + 0xF0)) * 8 / 2, 0, 4, 0xF0E02, 2);

    CopyWindowPixelsToVram_TextMode((Window *)((u8 *)work + 0x100));
    CopyWindowPixelsToVram_TextMode((Window *)((u8 *)work + 0x140));
    CopyWindowPixelsToVram_TextMode((Window *)((u8 *)work + 0x130));
    CopyWindowPixelsToVram_TextMode((Window *)((u8 *)work + 0xF0));
}

void ov81_02241980(void *work) {
    ov81_022431E0(OV81_GRID_PTR(work, 0x4C), 2);
    ov81_02243140(OV81_GRID_PTR(work, 0x4C), OV81_GRID_PTR(work, 0x3DC), 1);
    ScheduleWindowCopyToVram((Window *)((u8 *)work + 0x150));
    ScheduleWindowCopyToVram((Window *)((u8 *)work + 0x160));
    GridInputHandler_SetNextInput(OV81_GRID_PTR(work, 0x464), 6);
    ov81_0224141C(work, 6);
    ov81_022433FC(OV81_GRID_PTR(work, 0x464), 1, OV81_GRID_U8(work, 9));
    ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 1);
}

void ov81_022419E0(void *work) {
    ov81_022431E0(OV81_GRID_PTR(work, 0x4C), 1);
    ov81_02243140(OV81_GRID_PTR(work, 0x4C), OV81_GRID_PTR(work, 0x3DC), 2);
    ScheduleWindowCopyToVram((Window *)((u8 *)work + 0xE0));
    ScheduleWindowCopyToVram((Window *)((u8 *)work + 0xF0));
    GridInputHandler_SetNextInput(OV81_GRID_PTR(work, 0x464), (u8)OV81_GRID_U32(work, 0x468));
    ov81_022433FC(OV81_GRID_PTR(work, 0x464), 0, OV81_GRID_U8(work, 9));
    ov81_02242D88(OV81_GRID_PTR(work, 0x38C), 0);
}
