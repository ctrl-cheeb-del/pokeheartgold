#include "overlay73_text_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov73_021E9F34(void *p, void *msgData, int msgNo, int speed) {
    void *str = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(PTR(p, 0xBD0), PTR(p, 0xBE0), str);
    FillWindowPixelBuffer((u8 *)p + 0xDD8, 15);
    DrawFrameAndWindow2((u8 *)p + 0xDD8, 0, 1, 14);
    U32(p, 0xBF4) = AddTextPrinterParameterized((u8 *)p + 0xDD8, 1, PTR(p, 0xBE0), 0, 0, speed, NULL);
    String_Delete(str);
}

int ov73_021E9F9C(void *p) {
    void *x = ov73_021E6A70(-U32(p, 0xF14), U32(p, 0xF18));
    ov73_021EA218(p, x, -U32(p, 0xF14));
    U32(p, 0x1C) = 0x38;
    return 3;
}

int ov73_021E9FC8(void *p) {
    if ((gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B)) {
        sub_0200E5D4((u8 *)p + 0xE18, 0);
        U32(p, 0x1C) = 0;
    }
    return 3;
}

void ov73_021E9FF8(void *p, void *msgData, int msgNo, int speed) {
    ReadMsgDataIntoString(msgData, msgNo, PTR(p, 0xBE0));
    FillWindowPixelBuffer((u8 *)p + 0xDD8, 15);
    DrawFrameAndWindow2((u8 *)p + 0xDD8, 0, 1, 14);
    U32(p, 0xBF4) = AddTextPrinterParameterized((u8 *)p + 0xDD8, 1, PTR(p, 0xBE0), 0, 0, speed, NULL);
}

int ov73_021EA050(const u8 *window, const void *str, int x, int mode, int unused, int fontId) {
    int width;
    switch (mode) {
    case 1:
        width = FontID_String_GetWidth(fontId, str, 0);
        x = ((window[7] << 3) - width) / 2;
        break;
    case 2:
        width = FontID_String_GetWidth(fontId, str, 0);
        x = (window[7] << 3) - width;
        break;
    }
    return x;
}

void ov73_021EA088(void *window, const void *str, int x, int y, int mode, u32 color) {
    x = ov73_021EA050(window, str, x, mode, color, 1);
    AddTextPrinterParameterizedWithColor(window, 1, str, x, y, 0, color, NULL);
}

void ov73_021EA0BC(void *window, const void *str, int x, int y, int mode, u32 color) {
    x = ov73_021EA050(window, str, x, mode, color, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, x, y, 0, color, NULL);
}

void ov73_021EA0F0(void *window, void *str, int number, int digits) {
    FillWindowPixelBuffer(window, 15);
    String16_FormatInteger(str, number, digits, 2, 1);
    ov73_021EA0BC(window, str, 0, 1, 1, 0x10200);
}
