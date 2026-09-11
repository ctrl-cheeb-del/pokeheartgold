#include "overlay95_window_internal.h"

void ov95_021E5BBC(void *bg, void *palette, int frame) {
    LoadUserFrameGfx2(bg, 1, 0x14, 0xF, (u8)frame, 0x46);
    PaletteData_LoadNarc(palette, 0x26, sub_0200E640(frame), 0x46, 0, 0x20, 0xC0);
    LoadUserFrameGfx1(bg, 1, 0x32, 0xD, 0, 0x46);
    PaletteData_LoadNarc(palette, 0x26, sub_0200E3D8(), 0x46, 0, 0x20, 0xD0);
    PaletteData_LoadNarc(palette, 0x10, 8, 0x46, 0, 0x20, 0xE0);
}

void ov95_021E5C44(void *bg, void *window, int x, int y, int width, int height, int palette, int baseTile, int arg8) {
    InitWindow(window);
    AddWindowParameterized(bg, window, (u8)x, (u8)y, (u8)width, (u8)height, (u8)palette, (u8)arg8, (u16)baseTile);
    DrawFrameAndWindow2(window, 1, 0x14, 0xC);
    FillWindowPixelBuffer(window, 0xF);
    CopyWindowToVram(window);
}

int ov95_021E5CAC(void *window, int messageId, void *pokemon, int y) {
    void *msgData;
    void *format;
    void *template;
    void *dest;
    int printer;
    FillWindowPixelBuffer(window, 0xF);
    msgData = NewMsgDataFromNarc(0, 0x1B, 0xBB, 0x46);
    format = MessageFormat_New(0x46);
    template = NewString_ReadMsgData(msgData, messageId);
    dest = String_New(0xFF, 0x46);
    BufferBoxMonSpeciesName(format, 0, Mon_GetBoxMon(pokemon));
    StringExpandPlaceholders(format, dest, template);
    printer = AddTextPrinterParameterized(window, 1, dest, 0, 0, y, NULL);
    DestroyMsgData(msgData);
    String_Delete(dest);
    String_Delete(template);
    MessageFormat_Delete(format);
    return printer;
}
