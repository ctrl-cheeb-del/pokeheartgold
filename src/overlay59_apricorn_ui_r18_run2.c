#include "overlay59_apricorn_ui_r18_private.h"

void ov59_02238AB0(u8 *work, int show) {
    int i;
    u8 *spriteCursor;

    if (show) {
        GfGfxLoader_LoadScrnDataFromOpenNarc(R18_PTR(work, 0x290), 6, R18_PTR(work, 0x54), 1, 0, 0, 0, R18_U32(work, 0));
        ov59_02238A04(work, R18_U8(work, 0x4E));
        ov59_02238834(work, 0, 0);
        ov59_02238834(work, 1, 0);
        FillWindowPixelBuffer(work + 0x178, 0);
        AddTextPrinterParameterizedWithColor(work + 0x178, 0, R18_PTR(work + R18_U8(work, 0x4D) * 4, 0xD0), 0, 0, 0xFF, 0x10200, 0);
        ScheduleWindowCopyToVram(work + 0x178);
        ReadMsgDataIntoString(R18_PTR(work, 0x5C), 0x1A, R18_PTR(work, 0x68));
        FillWindowPixelBuffer(work + 0x1C8, 0);
        AddTextPrinterParameterizedWithColor(work + 0x1C8, 0, R18_PTR(work, 0x68), 2, 0, 0xFF, 0x10200, 0);
        ScheduleWindowCopyToVram(work + 0x1C8);
    } else {
        FillBgTilemapRect(R18_PTR(work, 0x54), 1, 0, 0, 0, 0x20, 0x18, 0x11);
        FillBgTilemapRect(R18_PTR(work, 0x54), 0, 0, 0, 0, 0x20, 0x18, 0x11);
        ScheduleBgTilemapBufferTransfer(R18_PTR(work, 0x54), 1);
        ScheduleBgTilemapBufferTransfer(R18_PTR(work, 0x54), 0);
    }
    spriteCursor = work;
    i = 9;
    spriteCursor += 0x24;
    do {
        Sprite_SetDrawFlag(R18_PTR(spriteCursor, 0x254), show);
        Sprite_SetAnimActiveFlag(R18_PTR(spriteCursor, 0x254), FALSE);
        i++;
        spriteCursor += 4;
    } while (i <= 14);
    if (R18_U8(work + R18_U8(work, 0x4D), 0x1A) < 10) {
        Sprite_SetAnimCtrlSeq(R18_PTR(work, 0x288), 0x19);
        Sprite_SetAnimCtrlSeq(R18_PTR(work, 0x28C), 0x1B);
    } else {
        Sprite_SetAnimCtrlSeq(R18_PTR(work, 0x288), 0x18);
        Sprite_SetAnimCtrlSeq(R18_PTR(work, 0x28C), 0x1A);
    }
}
