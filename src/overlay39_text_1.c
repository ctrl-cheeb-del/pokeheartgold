#include "overlay39_text_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

int ov39_02228964(u8 *window, void *arg1, int arg2, int alignment, int unused, void *string) {
    int x = arg2;
    switch (alignment) {
    case 1:
        x = ((window[7] << 3) - FontID_String_GetWidth(string, arg1, 0)) / 2;
        break;
    case 2:
        x = (window[7] << 3) - FontID_String_GetWidth(string, arg1, 0);
        break;
    }
    return x;
}

void ov39_0222899C(void *window, void *string, int spacing, int y, int alignment, u32 color) {
    int x = ov39_02228964(window, string, spacing, alignment, color, (void *)1);
    AddTextPrinterParameterizedWithColor(window, 1, string, x, y, 0, color, NULL);
}

void ov39_022289D0(u8 *work, int message) {
    void *tmp = String_New(0x100, 0x7C);
    ReadMsgDataIntoString(PTR(work, 0x2C), message, tmp);
    StringExpandPlaceholders(PTR(work, 0x20), PTR(work, 0x3C), tmp);
    FillWindowPixelBuffer(work + 0x64, 0xF);
    DrawFrameAndWindow1(work + 0x64, 1, 0x1F, 0xB);
    AddTextPrinterParameterized(work + 0x64, 1, PTR(work, 0x3C), 0, 0, 0, NULL);
    U32(work, 0x40) = 0xFF;
    String_Delete(tmp);
}

void ov39_02228A34(u8 *work, int value, int number) {
    if (value == -1) {
        value = 0xB;
    }
    BufferIntegerAsString(PTR(work, 0x20), 0, number, 5, 2, 1);
    ClearFrameAndWindow2(work + 0x44, 1);
    ov39_022289D0(work, value);
}
