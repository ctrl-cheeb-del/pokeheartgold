#include "to47_overlay49_window_menu_private.h"

void ov49_0225B0E0(void *window, void **bgConfig, int unused, int x, u8 y, u8 width, u8 height) {
    AddWindowParameterized(*bgConfig, window, 1, x, y, width, height, 5, 0xCA);
    DrawFrameAndWindow1(window, 1, 0x55, 3);
    FillWindowPixelBuffer(window, 0xF);
    ScheduleWindowCopyToVram(window);
}

void ov49_0225B124(void *window) {
    if (WindowIsInUse(window) == 1) {
        sub_0200E5D4(window, 1);
        ClearWindowTilemapAndScheduleTransfer(window);
        RemoveWindow(window);
    }
}

void ov49_0225B148(void *window, void *str, int x, int y) {
    AddTextPrinterParameterizedWithColor(window, 0, str, x, y, 0xFF, 0x1020F, NULL);
    ScheduleWindowCopyToVram(window);
}

void ov49_0225B178(void *window, int x, int y, int width, u16 height) {
    FillWindowPixelRect(window, 0xF, x, y, width, height);
}

void ov49_0225B198(void *menu, void *ctx, int heapId) {
    void *text;
    if (*(void **)menu != NULL) {
        GF_AssertFail();
    }
    *(void **)menu = ListMenuItems_New(2, heapId);
    text = ov49_0225B388(ctx, 1, 0x43);
    ListMenuItems_AddItem(*(void **)menu, text, 0);
    text = ov49_0225B388(ctx, 1, 0x42);
    ListMenuItems_AddItem(*(void **)menu, text, 1);
    *(Ov49MenuTemplate *)((u8 *)menu + 4) = ov49_022697AC;
    *(u16 *)((u8 *)menu + 0x14) = 2;
    *(void **)((u8 *)menu + 4) = *(void **)menu;
}
