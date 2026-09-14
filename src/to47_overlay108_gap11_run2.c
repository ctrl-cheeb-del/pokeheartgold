#include "to47_overlay108_gap11_private.h"

void ov108_021EA260(void *work) {
    int selected;
    int x;

    FillWindowPixelBuffer((u8 *)work + 0x494, 0);
    selected = U8(work, 0x432);
    ReadMsgDataIntoString(PTR(work, 0x30C), U8(PTR(work, 0x334), selected * 5) + 0xE, PTR(work, 0x318));
    x = 0x70 - FontID_String_GetWidth(4, PTR(work, 0x318), 0);
    AddTextPrinterParameterizedWithColor((u8 *)work + 0x494, 4, PTR(work, 0x318), x / 2, 0, 0xFF, 0x10200, 0);
    ScheduleWindowCopyToVram((u8 *)work + 0x494);
    ClearWindowTilemapAndScheduleTransfer((u8 *)work + 0x484);
}
