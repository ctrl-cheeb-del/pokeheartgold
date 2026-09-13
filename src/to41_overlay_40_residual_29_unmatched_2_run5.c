#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

void ov40_02236EB4(void *p) {
    void *win;
    const Ov40WinTemplate *t = ov40_022452B4;
    const u32 *fills = ov40_02245290;
    int baseTile = 0x101;
    int i;
    for (i = 0, win = (u8 *)PTR(p, 0x860) + 0x1B4; i < 3; i++) {
        InitWindow(win);
        AddWindowParameterized(PTR(p, 0x24), win, 2, t->x, t->y, t->width, t->height, 0xE, baseTile);
        FillWindowPixelBuffer(win, (u8)*fills);
        ScheduleWindowCopyToVram(win);
        baseTile += t->width * t->height;
        win = (u8 *)win + 0x10;
        t++;
        fills++;
    }
}

void ov40_02236F38(void *p) {
    void *win;
    const Ov40WinTemplate *t = ov40_022452DC;
    int baseTile = 1;
    u32 i;
    for (i = 0, win = (u8 *)PTR(p, 0x860) + 0x234; i < 6; i++) {
        void *str;
        int x;
        InitWindow(win);
        AddWindowParameterized(PTR(p, 0x24), win, 6, t->x, t->y, t->width, t->height, 0xE, baseTile);
        str = NewString_ReadMsgData(PTR(p, 0x48), i + 0x3C);
        x = ov40_022306C0(win, str);
        FillWindowPixelBuffer(win, 0);
        AddTextPrinterParameterizedWithColor(win, 0, str, x, 0, 0xFF, 0xF0D00, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
        baseTile += t->width * t->height;
        win = (u8 *)win + 0x10;
        t++;
    }
}

void ov40_02236FE0(void *p) {
    u32 i;
    void *win;
    for (i = 0, win = (u8 *)PTR(p, 0x860) + 0x234; i < 6; i++) {
        ClearWindowTilemapAndCopyToVram(win);
        RemoveWindow(win);
        win = (u8 *)win + 0x10;
    }
}

void ov40_02237008(void *p) {
    int i;
    void *win;
    for (i = 0, win = (u8 *)PTR(p, 0x860) + 0x1B4; i < 3; i++) {
        ClearWindowTilemapAndCopyToVram(win);
        RemoveWindow(win);
        win = (u8 *)win + 0x10;
    }
}
