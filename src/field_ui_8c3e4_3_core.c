#include "field_ui_8c3e4_3_core_internal.h"

void sub_0208C8C8(SummaryState *state, int window, int firstMsg, int secondMsg, int thirdMsg, u16 firstValue, u16 secondValue, volatile u8 digits, u8 width, u8 y) {
    Window *target = &PTR(state, 0x224, Window)[window];
    u32 textWidth;
    u16 x;
    u16 end;

    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), firstMsg, PTR(state, 0x7ac, String));
    textWidth = FontID_String_GetWidth(0, PTR(state, 0x7ac, String), 0);
    x = width - textWidth / 2;
    end = x + textWidth;
    AddTextPrinterParameterizedWithColor(target, 0, PTR(state, 0x7ac, String), x, y, 0xff, 0x10200, 0);
    sub_0208C87C(state, secondMsg, firstValue, digits, 0);
    textWidth = FontID_String_GetWidth(0, PTR(state, 0x7ac, String), 0);
    AddTextPrinterParameterizedWithColor(target, 0, PTR(state, 0x7ac, String), x - textWidth, y, 0xff, 0x10200, 0);
    sub_0208C87C(state, thirdMsg, secondValue, digits, 0);
    AddTextPrinterParameterizedWithColor(target, 0, PTR(state, 0x7ac, String), end, y, 0xff, 0x10200, 0);
}

void sub_0208C9A4(SummaryState *state) {
    sub_0208C850(state, 0, 7, 0xe0f00, 0);
    sub_0208C850(state, 1, 0x17, 0xe0f00, 0);
    sub_0208C850(state, 2, 0x6d, 0xe0f00, 0);
    sub_0208C850(state, 3, 0x7e, 0xe0f00, 0);
    sub_0208C850(state, 4, 0x80, 0xe0f00, 0);
    if (*(u32 *)((u8 *)PTR(state, 0x22c, void) + 0x34) != 0) {
        sub_0208C850(state, 5, 0x9d, 0xe0f00, 0);
    } else {
        FillWindowPixelBuffer((Window *)&state->raw[0x54], 0);
    }
    sub_0208C850(state, 6, 4, 0xe0f00, 0);
    sub_0208C850(state, 7, 8, 0xe0f00, 0);
    sub_0208C850(state, 8, 0xa, 0xe0f00, 0);
    sub_0208C850(state, 9, 0xc, 0xe0f00, 0);
    sub_0208C850(state, 0xa, 0xd, 0xe0f00, 0);
    sub_0208C850(state, 0xb, 0xf, 0xe0f00, 0);
    sub_0208C850(state, 0xc, 0x11, 0xe0f00, 0);
    sub_0208C850(state, 0xd, 0x13, 0xe0f00, 0);
    sub_0208C850(state, 0xf, 0x6e, 0xe0f00, 0);
    sub_0208C7F8(state, 0x10, 0x6f, 0, 0);
    sub_0208C7F8(state, 0x11, 0x70, 1, 0);
    sub_0208C7F8(state, 0x12, 0x71, 3, 0);
    sub_0208C7F8(state, 0x13, 0x72, 4, 0);
    sub_0208C7F8(state, 0x14, 0x73, 2, 0);
    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0x74, PTR(state, 0x7ac, String));
    AddTextPrinterParameterizedWithColor((Window *)&state->raw[0x154], 0, PTR(state, 0x7ac, String), 3, 0, 0xff, 0xe0f00, 0);
    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0x92, PTR(state, 0x7ac, String));
    AddTextPrinterParameterizedWithColor((Window *)&state->raw[0x174], 4, PTR(state, 0x7ac, String), 0, 0, 0xff, 0xe0f00, 0);
    sub_0208C850(state, 0x18, 0x95, 0xe0f00, 0);
    sub_0208C850(state, 0x19, 0x93, 0xe0f00, 0);
    sub_0208C850(state, 0x1a, 0x94, 0xe0f00, 0);
    sub_0208C850(state, 0x1b, 0xa2, 0xe0f00, 2);
    sub_0208C850(state, 0x1c, 0xa0, 0x10200, 2);
    sub_0208C850(state, 0x1d, 0xb6, 0x10200, 0);
    sub_0208C850(state, 0x1e, 0xb3, 0xe0f00, 0);
}

void sub_0208CBD4(SummaryState *state) {
    FillBgTilemapRect(PTR(state, 0, void), 1, 0, 0, 0, 0x20, 2, 0x10);
    FillBgTilemapRect(PTR(state, 0, void), 1, 0, 0, 2, 0x12, 0x16, 0x10);
    FillBgTilemapRect(PTR(state, 0, void), 4, 0, 0, 1, 0x12, 0x17, 0x10);
    switch (S8(state, 0x7bc)) {
    case 0:
        sub_0208CC88(state);
        sub_0208D0A4(state);
        break;
    case 1:
        sub_0208D178(state);
        sub_0208D474(state);
        break;
    case 2:
        sub_0208D520(state);
        sub_0208D6B8(state);
        break;
    case 3:
        sub_0208D728(state);
        break;
    }
}

void sub_0208CC88(SummaryState *state) {
    ScheduleWindowCopyToVram((Window *)&state->raw[0x174]);
    if ((U32(state, 0x280) << 3) >> 31) {
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[4]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0x74]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0x84]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0x94]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0xa4]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0xb4]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0xc4]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0xd4]);
        ClearWindowTilemapAndScheduleTransfer((Window *)&state->raw[0xe4]);
        ClearWindowTilemapAndScheduleTransfer(&PTR(state, 0x224, Window)[0]);
        ClearWindowTilemapAndScheduleTransfer(&PTR(state, 0x224, Window)[1]);
        ClearWindowTilemapAndScheduleTransfer(&PTR(state, 0x224, Window)[2]);
        ClearWindowTilemapAndScheduleTransfer(&PTR(state, 0x224, Window)[3]);
        ClearWindowTilemapAndScheduleTransfer(&PTR(state, 0x224, Window)[4]);
        ClearWindowTilemapAndScheduleTransfer(&PTR(state, 0x224, Window)[5]);
        return;
    }

    ScheduleWindowCopyToVram((Window *)&state->raw[4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0x74]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0x84]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0x94]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0xa4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0xb4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0xc4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0xd4]);
    ScheduleWindowCopyToVram((Window *)&state->raw[0xe4]);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[0], 0);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[1], 0);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[2], 0);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[3], 0);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[4], 0);
    FillWindowPixelBuffer(&PTR(state, 0x224, Window)[5], 0);

    {
        int dexNo = Pokedex_ConvertToCurrentDexNo(*(void **)((u8 *)PTR(state, 0x22c, void) + 0x1c), U16(state, 0x23c));
        if (dexNo != 0) {
            sub_0208C87C(state, 9, dexNo, 3, 2);
        } else {
            ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), 0x16, PTR(state, 0x7ac, String));
        }
    }
    if (((U32(state, 0x280) << 2) >> 31) == 0) {
        sub_0208C778(state, PTR(state, 0x224, Window), 0x10200, 2);
    } else {
        sub_0208C778(state, PTR(state, 0x224, Window), 0x50600, 2);
    }
    {
        int x = FontID_String_GetCenterAlignmentX(0, PTR(state, 0x230, String), 0, 0x48);
        AddTextPrinterParameterizedWithColor(&PTR(state, 0x224, Window)[1], 0, PTR(state, 0x230, String), x, 0, 0xff, 0x10200, 0);
    }
    {
        if (U8(state, 0x274) == 0) {
            int x = FontID_String_GetCenterAlignmentX(0, PTR(state, 0x238, String), 0, 0x48);
            AddTextPrinterParameterizedWithColor(&PTR(state, 0x224, Window)[2], 0, PTR(state, 0x238, String), x, 0, 0xff, 0x30400, 0);
        } else {
            int x = FontID_String_GetCenterAlignmentX(0, PTR(state, 0x238, String), 0, 0x48);
            AddTextPrinterParameterizedWithColor(&PTR(state, 0x224, Window)[2], 0, PTR(state, 0x238, String), x, 0, 0xff, 0x50600, 0);
        }
    }
    sub_0208C87C(state, 0x10, (u16)U32(state, 0x244), 5, 2);
    sub_0208C778(state, &PTR(state, 0x224, Window)[3], 0x10200, 2);
    sub_0208C87C(state, 0x12, U32(state, 0x248), 7, 0);
    sub_0208C778(state, &PTR(state, 0x224, Window)[4], 0x10200, 1);
    if (LEVEL(state).value < 100) {
        sub_0208C87C(state, 0x15, U32(state, 0x250) - U32(state, 0x248), 7, 0);
    } else {
        sub_0208C87C(state, 0x15, 0, 7, 0);
    }
    sub_0208C778(state, &PTR(state, 0x224, Window)[5], 0x10200, 1);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[0]);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[1]);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[2]);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[3]);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[4]);
    ScheduleWindowCopyToVram(&PTR(state, 0x224, Window)[5]);
}

void sub_0208CFB4(Window *window, void *mon, int unchanged) {
    Unk0208E600Result *result = sub_0208E600(mon, unchanged, 0x13);
    if (result->s1 != NULL) {
        AddTextPrinterParameterizedWithColor(window, 0, result->s1, 6, (result->x1 - 1) * 16, 0xff, 0x10200, 0);
    }
    if (result->s2 != NULL) {
        AddTextPrinterParameterizedWithColor(window, 0, result->s2, 6, (result->x2 - 1) * 16, 0xff, 0x10200, 0);
    }
    if (result->s3 != NULL) {
        AddTextPrinterParameterizedWithColor(window, 0, result->s3, 6, (result->x3 - 1) * 16, 0xff, 0x10200, 0);
    }
    if (result->s4 != NULL) {
        AddTextPrinterParameterizedWithColor(window, 0, result->s4, 6, (result->x4 - 1) * 16, 0xff, 0x10200, 0);
    }
    FillBgTilemapRect((void *)window->raw[0], 1, 0, 0x10, 5, 2, 0x12, 0);
    sub_0208E994(result);
}
