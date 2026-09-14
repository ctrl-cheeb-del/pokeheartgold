#include "to47_overlay108_gap11_private.h"

void ov108_021E9F20(void *work, int index) {
    int width;

    Sprite_SetAnimCtrlSeq(PTR(work, 0x448), index + 2);
    Sprite_ResetAnimCtrlState(PTR(work, 0x448));
    FillWindowPixelBuffer((u8 *)work + 0x474, 0);
    width = FontID_String_GetWidth(4, PTR(work, 0x330), 0);
    AddTextPrinterParameterizedWithColor((u8 *)work + 0x474, 4, PTR(work, 0x330), (u32)(0x30 - width) / 2, 4, 0xFF, ov108_021EAAA4[index], 0);
    ScheduleWindowCopyToVram((u8 *)work + 0x474);
}

void ov108_021E9F94(void *work, int which) {
    void *tiles = PTR(work, which == 0 ? 0x524 : 0x52C);
    FillBgTilemapRect(PTR(work, 0x438), 5, 0, 0, 5, 0x20, 0xE, 0x11);
    FillBgTilemapRect(PTR(work, 0x438), 6, 0, 0, 5, 0x20, 0xE, 0x11);
    CopyToBgTilemapRect(PTR(work, 0x438), 7, 0, 0, 0x20, 0x18, (u8 *)tiles + 0xC, 0, 0, (u8)(U16(tiles, 0) >> 3), (u8)(U16(tiles, 2) >> 3));
    ScheduleBgTilemapBufferTransfer(PTR(work, 0x438), 5);
    ScheduleBgTilemapBufferTransfer(PTR(work, 0x438), 6);
    ScheduleBgTilemapBufferTransfer(PTR(work, 0x438), 7);
}
