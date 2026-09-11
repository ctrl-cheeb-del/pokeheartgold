#include "ov83_wave42_private.h"

int ov83_0223FF20(void *p, void *w, int msg, int x, u16 y) {
    return ov83_0223FCB4(p, w, msg, x, y, 0xff, 1, 2, 0, 0);
}

void ov83_0223FF44(void *p, void *w, void *mon) {
    FillWindowPixelBuffer(w, 0);
    ov83_0223FFD8(p, w, 0, 0x60, 0x64, mon, 0x36, 0x3a, 0x42);
    ov83_0223FFD8(p, w, 1, 0x61, 0x64, mon, 0x37, 0x3b, 0x43);
    ov83_0223FFD8(p, w, 2, 0x62, 0x64, mon, 0x38, 0x3c, 0x44);
    ov83_0223FFD8(p, w, 3, 0x63, 0x64, mon, 0x39, 0x3d, 0x45);
    ScheduleWindowCopyToVram(w);
}

void ov83_0223FFD8(void *p, void *w, int idx, int msg, int fallback, void *mon, int field1, int field2, int field3) {
    u32 v;
    u16 y;
    v = GetMonData(mon, field1, 0);
    BufferMoveName(PTR(p, 0x24), idx, v);
    y = (u16)(idx * 24 + 12);
    U8(p, 0xa) = ov83_0223FCB4(p, w, msg, 24, y, 0xff, 1, 2, 0, 0);
    v = GetMonData(mon, field2, 0);
    ov83_02240C48(p, 4, v, 3, 1);
    v = GetMonData(mon, field3, 0);
    ov83_02240C48(p, 5, v, 3, 0);
    U8(p, 0xa) = ov83_0223FCB4(p, w, fallback, 0x60, y, 0xff, 1, 2, 0, 0);
}
