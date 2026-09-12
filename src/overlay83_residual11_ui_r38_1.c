#include "overlay83_r38_private.h"

void ov83_022407FC(void *p) {
    int width;

    FillWindowPixelBuffer((u8 *)p + 0x3D0, 0);
    ov83_02240C48(p, 0, S16_AT(p, 0x862) + 1, 1, 0);
    ov83_02240C48(p, 1, (U8_AT(p, 0x861) - 1) / 6 + 1, 1, 0);
    width = GetWindowWidth((u8 *)p + 0x3D0) * 8 / 2;
    ov83_02241DD8(p, (u8 *)p + 0x3D0, PTR_AT(p, 0x20), 0x67, width, 0, 0, 0x10200, 2);
    ScheduleWindowCopyToVram((u8 *)p + 0x3D0);
}

void ov83_0224088C(void *p) {
    int width;

    FillWindowPixelBuffer((u8 *)p + 0x3E0, 0);
    width = GetWindowWidth((u8 *)p + 0x3E0);
    ov83_022479E4((u8 *)p + 0x3E0, PTR_AT(p, 0x20), 0x69, width * 8 / 2, 0, 0, 0x10200, 2);
    ScheduleWindowCopyToVram((u8 *)p + 0x3E0);
}

void ov83_022408E0(void *p, u16 item) {
    u16 index;
    int value;

    FillWindowPixelBuffer((u8 *)p + 0x420, 0);
    index = S16_AT(p, 0x862) * 6 + item;
    ov83_0224755C(PTR_AT(p, 0x79C), 0);
    if (item < 6 && index < U8_AT(p, 0x861)) {
        value = ov83_02240F48(p, index, U8_AT(p, 0x13));
        ov83_022479E4((u8 *)p + 0x420, PTR_AT(p, 0x1C), value, 0, 0, 0, 0x10200, 0);
        ov83_02247264((u8 *)p + 0x518, 3, value);
        ov83_022472A0((u8 *)p + 0x518, 3, value);
        ov83_0224755C(PTR_AT(p, 0x79C), 1);
    }
    ScheduleWindowCopyToVram((u8 *)p + 0x420);
}
