#include "overlay75_flow_r39_private.h"

void ov75_02248034(void *p) {
    void *source[1];
    void *line;
    int i;
    int y;
    void *window;

    FillWindowPixelBuffer((u8 *)p + 0xC4, 0xF);
    source[0] = NewString_ReadMsgData(PTR_AT(p, 0x34), 0x2C);
    line = String_New(String_GetLength(source[0]), 0x74);
    i = S32_AT(p, 0xAC);
    if (i < S32_AT(p, 0xAC) + 6) {
        window = (y = 0, (u8 *)p + 0xC4);
        do {
            String_GetLineN(line, source[0], i);
            AddTextPrinterParameterized(window, 0, line, 4, y, 0xFF, 0);
            i++;
            y += 0x10;
        } while (i < S32_AT(p, 0xAC) + 6);
    }
    String_Delete(source[0]);
    String_Delete(line);
    CopyWindowToVram((u8 *)p + 0xC4);
}
