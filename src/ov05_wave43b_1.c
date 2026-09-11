#include "ov05_wave42_private.h"
typedef struct T12 {
    u32 a[6];
} T12;

void ov05_0221E8A8(R12 *w, void *a, void *b, void *c, void *d, u32 index) {
    R12 *base = w + 0x10;
    u32 off = index * 64;
    FillWindowPixelBuffer(base + off, 0);
    FillWindowPixelBuffer(base + off + 0x10, 0);
    FillWindowPixelBuffer(base + off + 0x20, 0);
    FillWindowPixelBuffer(base + off + 0x30, 0);
    ov05_0221E624(w, a, b, c, d, index);
    ov05_0221E714(w, a, b, c, d, index);
    ov05_0221E74C(w, a, b, c, d, index);
    ov05_0221E7B8(w, index);
    ScheduleWindowCopyToVram(base + off);
    ScheduleWindowCopyToVram(base + off + 0x10);
    ScheduleWindowCopyToVram(base + off + 0x20);
    ScheduleWindowCopyToVram(base + off + 0x30);
}

void ov05_0221E944(R12 *w) {
    void *msg = NewMsgDataFromNarc(0, 0x1b, 0x12c, U32(P(w, 0), 0x24));
    void *printer = MessagePrinter_New(15, 14, 0, U32(P(w, 0), 0x24));
    void *fmt = MessageFormat_New(U32(P(w, 0), 0x24));
    void *str = String_New(32, U32(P(w, 0), 0x24));
    u32 i = 0;
    R12 *p = w;
    do {
        if (U16(p, 0x218) != 0) {
            ov05_0221E8A8(w, msg, printer, fmt, str, i);
        }
        i++;
        p += 24;
    } while (i < 6);
    String_Delete(str);
    DestroyMsgData(msg);
    MessagePrinter_Delete(printer);
    MessageFormat_Delete(fmt);
}
