#include "overlay70_ui_helpers_private.h"

int ov70_0223F1B8(u8 *work) {
    if (!TextPrinterCheckActive(*(u32 *)(work + 0xBF0)))
        *(u32 *)(work + 0x2C) = *(u32 *)(work + 0x30);
    return 3;
}

void ov70_0223F1D8(void *dst, MsgData *msg, int msgId, int a3, int a4, int a5) {
    String *str;
    if (msgId != 0) {
        str = NewString_ReadMsgData(msg, msgId);
        ov70_02245084(dst, str, 0, a4, a3, a5);
        String_Delete(str);
    }
}

void ov70_0223F20C(Window *window, MsgData *msg, int msgId, int color, int value) {
    String *str;
    if (msgId != 0) {
        str = NewString_ReadMsgData(msg, msgId);
        AddTextPrinterParameterizedWithColor(window, 0, str, 0, color, 0xFF, value, NULL);
        String_Delete(str);
    }
}
