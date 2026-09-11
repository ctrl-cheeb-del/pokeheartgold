#include "overlay75_message_helpers_internal.h"

void ov75_022496B8(W *w, u32 msg) {
    void *s = String_New(0x100, 0x74);
    ReadMsgDataIntoString(w->msg, msg, s);
    StringExpandPlaceholders(w->fmt, w->str40, s);
    FillWindowPixelBuffer(w->win68, 0xf);
    DrawFrameAndWindow1(w->win68, 1, 0x1f, 0xb);
    AddTextPrinterParameterized(w->win68, 1, w->str40, 0, 0, 0, 0);
    w->printer = 0xff;
    String_Delete(s);
}

void ov75_0224971C(W *w, s32 mode, s32 value) {
    if (mode == -1) {
        mode = 0xb;
    }
    BufferIntegerAsString(w->fmt, 0, value, 5, 2, 1);
    ClearFrameAndWindow2(w->win48, 1);
    ov75_022496B8(w, mode);
}
