#include "field_ui_8c3e4_internal.h"

int sub_0208C73C(SummaryState *state) {
    void *mon = PTR(state, 0x22c, void);
    if (U32(state, 0x244) == *(u32 *)((u8 *)mon + 0xc) && U8(state, 0x274) == *((u8 *)mon + 0x10) && String_Compare(PTR(state, 0x238, String), PTR(state, 0x7b0, String)) == 0) {
        return 1;
    }
    return 0;
}

void sub_0208C778(SummaryState *state, Window *window, u32 color, int alignment) {
    int x;
    switch (alignment) {
    case 0:
        x = 0;
        break;
    case 1: {
        u8 width = FontID_String_GetWidth(0, PTR(state, 0x7ac, String), 0);
        x = (u8)((u8)(GetWindowWidth(window) * 8) - width);
        break;
    }
    case 2: {
        u8 width = FontID_String_GetWidth(0, PTR(state, 0x7ac, String), 0);
        x = (u8)(((u8)(GetWindowWidth(window) * 8) - width) / 2);
        break;
    }
    default:
        x = alignment;
        break;
    }
    AddTextPrinterParameterizedWithColor(window, 0, PTR(state, 0x7ac, String), x, 0, 0xff, color, 0);
}

void sub_0208C7F8(SummaryState *state, int window, int msgNo, int stat, int speed) {
    u32 color = 0xe0f00;
    int mod = gNatureStatMods[U8(state, 0x263)][stat];
    if (mod < 0) {
        color = 0xe0800;
    } else if (mod > 0) {
        color = 0xe0700;
    }
    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), msgNo, PTR(state, 0x7ac, String));
    {
        Window *windows = (Window *)&state->raw[4];
        sub_0208C778(state, &windows[window], color, speed);
    }
}

void sub_0208C850(SummaryState *state, int window, int msgNo, u32 color, int speed) {
    Window *windows;
    ReadMsgDataIntoString(PTR(state, 0x7a0, MsgData), msgNo, PTR(state, 0x7ac, String));
    windows = (Window *)&state->raw[4];
    sub_0208C778(state, &windows[window], color, speed);
}

void sub_0208C87C(SummaryState *state, int msgNo, int value, int digits, u8 mode) {
    String *temp = NewString_ReadMsgData(PTR(state, 0x7a0, MsgData), msgNo);
    BufferIntegerAsString(PTR(state, 0x7a8, void), 0, value, digits, mode, 1);
    StringExpandPlaceholders(PTR(state, 0x7a8, void), PTR(state, 0x7ac, String), temp);
    String_Delete(temp);
}
