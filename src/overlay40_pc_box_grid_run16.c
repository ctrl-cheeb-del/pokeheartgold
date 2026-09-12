#include "overlay40_pc_box_grid_private.h"

void ov40_0223584C(void *p) {
    void *w = PTR(p, 0x860);
    ClearWindowTilemapAndCopyToVram((u8 *)w + 0xD0);
    RemoveWindow((u8 *)w + 0xD0);
}

void ov40_02235868(void *p, u32 msgId) {
    void *win = (u8 *)PTR(p, 0x860) + 0xD0;
    void *str;
    FillWindowPixelBuffer(win, 0);
    str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
    AddTextPrinterParameterizedWithColor(win, 0, str, ov40_022306C0(win, str), 0, 0xFF, 0xF0D00, NULL);
    String_Delete(str);
    ScheduleWindowCopyToVram(win);
}

void ov40_022358C0(void *p) {
    void *win = (u8 *)PTR(p, 0x860) + 0xD0;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 6, 8, 3, 0x10, 2, 0xE, 1);
    ov40_02235868(p, 0x79);
}

void ov40_02235900(void *p) {
    volatile u32 *a = (volatile u32 *)0x027E0000;
    if (PTR(PTR(p, 0x860), 0x228) != NULL) {
        ov41_0224B5C8(PTR(PTR(p, 0x860), 0x228));
    }
    GF_RunVramTransferTasks();
    PaletteData_PushTransparentBuffers(PTR(p, 0x28));
    DoScheduledBgGpuUpdates(PTR(p, 0x24));
    a[0x3FF8 / 4] |= 1;
}
