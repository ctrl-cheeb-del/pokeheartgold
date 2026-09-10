#include "field_ui_8c3e4_internal.h"

void sub_0208D474(SummaryState *state) {
    if (U8((SummaryState *)PTR(state, 0x22c, void), 0x12) != 2) {
        ScheduleWindowCopyToVram((Window *)&state->raw[0x44]);
    }
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x80), 0);
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x90), 0);
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xa0), 0);
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xb0), 0);
    sub_0208D884(state, 0);
    sub_0208D884(state, 1);
    sub_0208D884(state, 2);
    sub_0208D884(state, 3);
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x80));
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x90));
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0xa0));
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0xb0));
    ScheduleWindowCopyToVram((Window *)&state->raw[0x174]);
}
