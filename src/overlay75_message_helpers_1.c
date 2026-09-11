#include "overlay75_message_helpers_internal.h"

void ov75_022494CC(W *w, void *msgData, u32 msgId, u32 speed) {
    void *tmp = NewString_ReadMsgData(msgData, msgId);
    StringExpandPlaceholders(w->fmt, w->expanded, tmp);
    String_Delete(tmp);
    FillWindowPixelBuffer(w->win48, 0xf);
    DrawFrameAndWindow2(w->win48, 0, 1, 10);
    w->printer = AddTextPrinterParameterized(w->win48, 1, w->expanded, 0, 0, speed, 0);
    w->state90 = 0;
    if (speed == 0xff || speed == 0) {
        w->printer = 0xff;
    }
}

BOOL ov75_02249534(u32 id) {
    if (id == 0xff || TextPrinterCheckActive(id) == 0) {
        return FALSE;
    }
    return TRUE;
}
