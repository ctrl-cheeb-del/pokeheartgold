#include "r40_overlay_40_residual_41_unmatched_4_private.h"

void ov40_022443B4(void *p) {
    void *w = PTR(p, 0x860);
    void *win = (u8 *)w + 0x10;
    void *str;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 6, 4, 6, 0xA, 2, 0xE, 1);
    FillWindowPixelBuffer(win, 0);
    str = NewString_ReadMsgData(PTR(p, 0x48), 0x82);
    AddTextPrinterParameterizedWithColor(win, 0, str, ov40_022306C0(win, str), 0, 0xFF, 0xF0D00, NULL);
    String_Delete(str);
    ScheduleWindowCopyToVram(win);
    win = (u8 *)w + 0x20;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 6, 0x12, 6, 0xA, 2, 0xE, 0x15);
    FillWindowPixelBuffer(win, 0);
    str = NewString_ReadMsgData(PTR(p, 0x48), 0x83);
    AddTextPrinterParameterizedWithColor(win, 0, str, ov40_022306C0(win, str), 0, 0xFF, 0xF0D00, NULL);
    String_Delete(str);
    ScheduleWindowCopyToVram(win);
}
