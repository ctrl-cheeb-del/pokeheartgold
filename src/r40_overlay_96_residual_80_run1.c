#include "r40_overlay_96_residual_80_private.h"

void ov96_02200BD8(void *work, s32 index) {
    void *string;

    FillWindowPixelBuffer((u8 *)work + 0xc, 0);
    BufferString(PTR(work, 0x30), 0, PTR(work, 0x170 + index * 4), 2, 1, 2);
    string = ReadMsgData_ExpandPlaceholders(PTR(work, 0x30), PTR(work, 0x2c), 0x9a, U32_AT(work, 0));
    AddTextPrinterParameterizedWithColor((u8 *)work + 0xc, 0, string, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(string);
    CopyWindowToVram((u8 *)work + 0xc);
}

void ov96_02200C40(void *work) {
    void *string;

    FillWindowPixelBuffer((u8 *)work + 0x1c, 0);
    string = NewString_ReadMsgData(PTR(work, 0x2c), 0x131);
    AddTextPrinterParameterizedWithColor((u8 *)work + 0x1c, 0, string, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(string);
    CopyWindowToVram((u8 *)work + 0x1c);
}
