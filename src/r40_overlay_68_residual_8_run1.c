#include "r40_overlay_68_residual_8_private.h"

void ov68_021E6234(MoveRelearner *d, u32 windowNo, u32 fontId, u32 color, u32 align, u8 y) {
    u8 textWidth;
    u8 x;

    switch (align) {
    case 0:
        x = 0;
        break;
    case 1:
        textWidth = FontID_String_GetWidth(fontId, d->unk_100, 0);
        x = (u8)(GetWindowWidth(&d->windows[windowNo]) * 8) - textWidth;
        break;
    case 2:
        textWidth = FontID_String_GetWidth(fontId, d->unk_100, 0);
        x = ((s32)(u8)(GetWindowWidth(&d->windows[windowNo]) * 8) - textWidth) / 2;
        break;
    default:
        break;
    }

    AddTextPrinterParameterizedWithColor(&d->windows[windowNo], fontId, d->unk_100, x, y, 0xff, color, NULL);
}

void ov68_021E62D4(MoveRelearner *d, u32 msgId, s32 value, u32 digits, u8 mode) {
    void *str = NewString_ReadMsgData(d->msgData, msgId);

    BufferIntegerAsString(d->msgFmt, 0, value, digits, mode, 1);
    StringExpandPlaceholders(d->msgFmt, d->unk_100, str);
    String_Delete(str);
}
