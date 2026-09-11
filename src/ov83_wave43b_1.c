#include "ov83_wave42_private.h"

void ov83_0223FD4C(void *p, void *w, void *mon) {
    u32 v;
    FillWindowPixelBuffer(w, 0);
    v = GetMonData(mon, 6, 0);
    BufferItemName(PTR(p, 0x24), 0, v);
    ov83_0223FF20(p, w, 0x46, 1, 8);
    ov83_0223FF20(p, w, 0x47, 0x40, 8);
    v = GetMonNature(mon);
    BufferNatureName(PTR(p, 0x24), 0, v);
    ov83_0223FF20(p, w, 0x48, 1, 0x18);
    ov83_0223FF20(p, w, 0x49, 0x40, 0x18);
    v = GetMonData(mon, 0xa, 0);
    BufferAbilityName(PTR(p, 0x24), 0, v);
    ov83_0223FF20(p, w, 0x4a, 1, 0x28);
    ov83_0223FF20(p, w, 0x4b, 0x40, 0x28);
    v = GetMonData(mon, 0xa5, 0);
    ov83_02240C48(p, 0, v, 3, 1);
    ov83_0223FF20(p, w, 0x4c, 1, 0x38);
    ov83_0223FF20(p, w, 0x4d, 0x38, 0x38);
    v = GetMonData(mon, 0xa6, 0);
    ov83_02240C48(p, 0, v, 3, 1);
    ov83_0223FF20(p, w, 0x4e, 0x58, 0x38);
    ov83_0223FF20(p, w, 0x4f, 0x90, 0x38);
    v = GetMonData(mon, 0xa8, 0);
    ov83_02240C48(p, 0, v, 3, 1);
    ov83_0223FF20(p, w, 0x50, 1, 0x48);
    ov83_0223FF20(p, w, 0x51, 0x38, 0x48);
    v = GetMonData(mon, 0xa9, 0);
    ov83_02240C48(p, 0, v, 3, 1);
    ov83_0223FF20(p, w, 0x52, 0x58, 0x48);
    ov83_0223FF20(p, w, 0x53, 0x90, 0x48);
    v = GetMonData(mon, 0xa7, 0);
    ov83_02240C48(p, 0, v, 3, 1);
    ov83_0223FF20(p, w, 0x54, 1, 0x58);
    ov83_0223FF20(p, w, 0x55, 0x38, 0x58);
    ScheduleWindowCopyToVram(w);
}
