#include "field_ui_8c3e4_internal.h"

void sub_0208DAD4(SummaryState *state) {
    ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0x184]);
    ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0x194]);
    ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0x1a4]);
    ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xd0));
    ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xe0));
    ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xf0));
}

void sub_0208DB1C(SummaryState *state) {
    if (U16((SummaryState *)PTR(state, 0x22c, void), 0x18) != 0) {
        FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xc0), 0);
        sub_0208D884(state, 4);
        ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0xc0));
    } else {
        ScheduleWindowCopyToVram((Window *)&state->raw[0x174]);
    }
}

void sub_0208DB58(SummaryState *state) {
    ScheduleBgTilemapBufferTransfer(PTR(state, 0, void), 1);
}

void sub_0208DB64(SummaryState *state) {
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[8 + SEL(state).low], 0);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[8 + SEL(state).high], 0);
    sub_0208D884(state, SEL(state).low);
    sub_0208D884(state, SEL(state).high);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[8 + SEL(state).low]);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[8 + SEL(state).high]);
}

void sub_0208DBF0(SummaryState *state) {
    Window *window;
    if (S8(state, 0x7bc) == 1) {
        ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xd0));
        ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xe0));
        ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xf0));
        window = (Window *)((u8 *)PTR(state, 0x224, Window) + 0xf0);
    } else {
        window = (Window *)((u8 *)PTR(state, 0x224, Window) + 0x50);
    }
    FillWindowPixelBuffer(window, 0);
    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0x9c, PTR(state, 0x7ac, String));
    sub_0208C778(state, window, 0x10200, 0);
    ScheduleWindowCopyToVram(window);
}

void sub_0208DC68(SummaryState *state, int show) {
    if (show == 1) {
        FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x100), 0);
        ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0xc1, PTR(state, 0x7ac, String));
        AddTextPrinterParameterizedWithColor((Window *)((u8 *)PTR(state, 0x224, Window) + 0x100), 4, PTR(state, 0x7ac, String), 0, 0, 0xff, 0xe0f00, 0);
        ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xc0));
        ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x100));
    } else {
        ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x100));
        if (U16((SummaryState *)PTR(state, 0x22c, void), 0x18) != 0) {
            FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0xc0), 0);
            sub_0208D884(state, 4);
            ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0xc0));
        }
    }
}

void sub_0208DD20(SummaryState *state, int show) {
    if (show == 1) {
        FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x110), 0);
        ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0xc2, PTR(state, 0x7ac, String));
        AddTextPrinterParameterizedWithColor((Window *)((u8 *)PTR(state, 0x224, Window) + 0x110), 4, PTR(state, 0x7ac, String), 0, 0, 0xff, 0xe0f00, 0);
        ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x110));
    } else {
        ClearWindowTilemapAndScheduleTransfer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x110));
    }
}

void sub_0208DDA0(SummaryState *state, int selection) {
    int msgNo;
    Window *window;
    switch (selection) {
    case 0:
        msgNo = 0xac;
        break;
    case 1:
        msgNo = 0xae;
        break;
    case 2:
        msgNo = 0xaf;
        break;
    case 3:
        msgNo = 0xb0;
        break;
    case 4:
        msgNo = 0xad;
        break;
    case 0xfe:
        msgNo = 0xb1;
        break;
    default:
        msgNo = 0xb2;
        break;
    }
    window = (Window *)((u8 *)PTR(state, 0x224, Window) + 0x20);
    DrawFrameAndWindow2(window, 1, 0x3e2, 0xd);
    FillWindowPixelBuffer(window, 15);
    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), msgNo, PTR(state, 0x7ac, String));
    AddTextPrinterParameterizedWithColor(window, 1, PTR(state, 0x7ac, String), 0, 0, 0xff, 0x1020f, 0);
    ScheduleWindowCopyToVram(window);
}
