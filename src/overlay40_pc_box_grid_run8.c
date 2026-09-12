#include "overlay40_pc_box_grid_private.h"

void ov40_02232F50(void *p) {
    void *w = PTR(p, 0x860);
    u32 v = WORD(p, WORD(p, 0x86C) * 4 + 0x88C);
    WORD(w, 0x10) = v;
    WORD(w, 0x9C) = v;
    WORD(w, 0xA0) = WORD(p, WORD(p, 0x86C) * 4 + 0x87C);
}

void ov40_02232F88(void *p) {
    void *w = PTR(p, 0x860);
    void *win = (u8 *)w + 0x178;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 6, 8, 3, 0x10, 2, 0xE, 1);
    ov40_02232FEC(p, 0x79);
}

void ov40_02232FCC(void *p) {
    void *w = PTR(p, 0x860);
    ClearWindowTilemapAndCopyToVram((u8 *)w + 0x178);
    RemoveWindow((u8 *)w + 0x178);
}

void ov40_02232FEC(void *p, u32 msgId) {
    void *w = PTR(p, 0x860);
    void *win = (u8 *)w + 0x178;
    void *str;
    FillWindowPixelBuffer(win, 0);
    str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
    AddTextPrinterParameterizedWithColor(win, 0, str, ov40_022306C0(win, str), 0, 0xFF, 0xF0D00, NULL);
    String_Delete(str);
    ScheduleWindowCopyToVram(win);
}
