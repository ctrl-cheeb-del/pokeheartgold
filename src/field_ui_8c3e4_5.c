#include "field_ui_8c3e4_internal.h"

void sub_0208D6B8(SummaryState *state) {
    ScheduleWindowCopyToVram((Window *)&state->raw[0x1e4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0x1d4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0x174]);
    FillWindowPixelBuffer(PTR(state, 0x224, Window), 0);
    sub_0208C87C(state, 0xb7, U8(state, 0x7c6), 3, 0);
    sub_0208C778(state, PTR(state, 0x224, Window), 0x10200, 0);
    ScheduleWindowCopyToVram(PTR(state, 0x224, Window));
    BgCommitTilemapBufferToVram(PTR(state, 0, void), 4);
}

void sub_0208D728(SummaryState *state) {
    u8 mode = U8((SummaryState *)PTR(state, 0x22c, void), 0x12);
    if (mode == 3) {
    } else if (mode != 4) {
        return;
    }
    {
        FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x10), 0);
        ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0xa5, PTR(state, 0x7ac, String));
        sub_0208C778(state, (Window *)((u8 *)PTR(state, 0x224, Window) + 0x10), 0xe0f00, 0);
        ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), U8(state, 0x27b) + 0xa6, PTR(state, 0x7ac, String));
        AddTextPrinterParameterizedWithColor((Window *)((u8 *)PTR(state, 0x224, Window) + 0x10), 0, PTR(state, 0x7ac, String), 0, 0x10, 0xff, 0x10200, 0);
        ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x10));
    }
}

void sub_0208D7C4(SummaryState *state) {
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x10), 0);
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x20), 0);
    if (U8(state, 0x7c4) + U8(state, 0x7c5) * 9 < U8(state, 0x7c6)) {
        int msgNo = GetRibbonAttr(U8(state, 0x7c7), 3);
        ReadMsgDataIntoString(PTR(state, 0x7a4, MsgData), msgNo, PTR(state, 0x7ac, String));
        sub_0208C778(state, (Window *)((u8 *)PTR(state, 0x224, Window) + 0x10), 0xe0f00, 0);
        msgNo = GetRibbonDescGmm(*(void **)((u8 *)PTR(state, 0x22c, void) + 0x20), U8(state, 0x7c7));
        ReadMsgDataIntoString(PTR(state, 0x7a4, MsgData), msgNo, PTR(state, 0x7ac, String));
        sub_0208C778(state, (Window *)((u8 *)PTR(state, 0x224, Window) + 0x20), 0x10200, 0);
    }
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x10));
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x20));
}
