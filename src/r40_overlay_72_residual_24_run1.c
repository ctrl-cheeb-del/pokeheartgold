#include "r40_overlay_72_residual_24_private.h"

void ov72_0223A460(void *work, int message) {
    void *string = String_New(0x100, 0x43);

    ReadMsgDataIntoString(PTR_AT(work, 0xbdc), message, string);
    StringExpandPlaceholders(PTR_AT(work, 0xbd0), PTR_AT(work, 0xbf0), string);
    FillWindowPixelBuffer((u8 *)work + 0xe58, 0xf);
    DrawFrameAndWindow1((u8 *)work + 0xe58, 1, 0x1f, 0xb);
    U32_AT(work, 0xbf4) = AddTextPrinterParameterized((u8 *)work + 0xe58, 1, PTR_AT(work, 0xbf0), 0, 0, 0, NULL);
    String_Delete(string);
}

void ov72_0223A4DC(void *work, int message, int unused) {
    if (message == -1) {
        message = 11;
    }
    BufferIntegerAsString(PTR_AT(work, 0xbd0), 0, unused, 5, 2, 1);
    ClearFrameAndWindow2((u8 *)work + 0xe18, 1);
    ov72_0223A460(work, message);
}
