#include "overlay40_pc_box_grid_private.h"

void ov40_02230DCC(void *p, void *str) {
    void *q = ov40_0223D540(p);
    void *tmp = String_New(0x40, WORD(q, 0x144));
    if (!FontID_String_AllCharsValid(0, str, tmp)) {
        ov40_02230E08(str, WORD(q, 0x144));
    }
    String_Delete(tmp);
}

void ov40_02230E08(void *str, u32 heapId) {
    void *msgData;
    String_SetEmpty(str);
    msgData = NewMsgDataFromNarc(1, 0x1B, 0xD, heapId);
    ReadMsgDataIntoString(msgData, 0x14C, str);
    DestroyMsgData(msgData);
}

void ov40_02230E34(void *p) {
    void *win = (u8 *)p + 0x8A4;
    void *str;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 2, 8, 0x10, 0x10, 2, 0xE, 0x12C);
    FillWindowPixelBuffer(win, 0);
    str = NewString_ReadMsgData(PTR(p, 0x48), 0xC0);
    AddTextPrinterParameterizedWithColor(win, 0, str, ov40_022306C0(win, str), 0, 0xFF, 0x10E00, NULL);
    String_Delete(str);
    ScheduleWindowCopyToVram(win);
    GfGfx_EngineATogglePlanes(4, 1);
}

void ov40_02230EB4(void *p) {
    ClearWindowTilemapAndCopyToVram((u8 *)p + 0x8A4);
    RemoveWindow((u8 *)p + 0x8A4);
    GfGfx_EngineATogglePlanes(4, 0);
}
