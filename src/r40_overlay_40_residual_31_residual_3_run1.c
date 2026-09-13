#include "r40_overlay_40_residual_31_residual_3_private.h"

void ov40_02237B7C(void *p, u32 msgId) {
    void *work = PTR_AT(p, 0x860);
    void *window = (u8 *)work + 0x234;
    void *str;
    u32 x;
    FillWindowPixelBuffer(window, 0);
    str = NewString_ReadMsgData(PTR_AT(p, 0x48), msgId);
    x = ov40_022306C0(window, str);
    AddTextPrinterParameterizedWithColor(window, 0, str, x, 0, 0xff, 0xf0d00, NULL);
    String_Delete(str);
    ScheduleWindowCopyToVram(window);
}

void ov40_02237BD4(void *p) {
    void *work = PTR_AT(p, 0x860);
    void *window = (u8 *)work + 0x234;
    void *str;
    u32 x;
    InitWindow(window);
    AddWindowParameterized(PTR_AT(p, 0x24), window, 6, 0xc, 6, 8, 4, 0xe, 1);
    FillWindowPixelBuffer(window, 0);
    str = NewString_ReadMsgData(PTR_AT(p, 0x48), 0x22);
    x = (0x40 - FontID_String_GetWidthMultiline(0, str, 0)) >> 1;
    AddTextPrinterParameterizedWithColor(window, 0, str, x, 0, 0xff, 0xf0d00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);
}
