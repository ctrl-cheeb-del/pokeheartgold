#include "overlay81_box_runtime_r2_private.h"

void ov81_0223EF5C(u8 *p) {
    Pokepic_SetAttr(PTR(p + p[0x11] * 4, 0x1AC), 6, 1);
    FillWindowPixelBuffer(p + 0x50 + (p[0x11] + 2) * 0x10, 0);
    ScheduleWindowCopyToVram(p + 0x50 + (p[0x11] + 2) * 0x10);
    p[0x11]--;
    ov81_022408A0(p, 0, p[0x11] + 1);
    p[0x10] = ov81_0224086C(p, 0);
    ov81_02242F54(PTR(p + U16(p + p[0x11] * 2, 0x3C8) * 4, 0x360));
    ov81_02242FB0((void **)PTR(p + U16(p + p[0x11] * 2, 0x3C8) * 4, 0x360), 1);
    ov81_02242F94((void **)PTR(p + U16(p + p[0x11] * 2, 0x3C8) * 4, 0x360), 0);
    U16(p + p[0x11] * 2, 0x3C8) = 0;
    ov81_02241C0C(p);
    ov81_02241FEC(p);
    ov81_0224218C(p);
    ov81_02242300(p, GridInputHandler_GetNextInput(PTR(p, 0x464)), 6);
}

void ov81_0223F038(u8 *p) {
    u32 selected;

    ov81_02242F48(PTR(p + U32(p, 0x468) * 4, 0x360));
    ov81_02242FB0((void **)PTR(p + U32(p, 0x468) * 4, 0x360), 0);
    ov81_02242F94((void **)PTR(p + U32(p, 0x468) * 4, 0x360), 1);
    U16(p + p[0x11] * 2, 0x3C8) = U32(p, 0x468);
    p[0x11]++;
    selected = p[0x11];
    if (selected != ov81_02240F18(p[9])) {
        ov81_022408A0(p, 0, selected + 1);
        p[0x10] = ov81_0224086C(p, 0);
    }
    ov81_02241FEC(p);
    ov81_0224218C(p);
}

void ov81_0223F0BC(u8 *p) {
    int count;
    int i;

    ov81_02242F54(PTR(p + U32(p, 0x468) * 4, 0x360));
    ov81_02242FB0((void **)PTR(p + U32(p, 0x468) * 4, 0x360), 1);
    ov81_02242F94((void **)PTR(p + U32(p, 0x468) * 4, 0x360), 0);
    if (p[0x11] >= 2 && U16(p, 0x3C8) == U32(p, 0x468)) {
        U16(p, 0x3C8) = U16(p, 0x3CA);
        ov81_02241E68(p, 0, U16(p, 0x3C8), 0);
        Pokepic_SetAttr(PTR(p, 0x1AC), 6, 0);
    }
    p[0x11]--;
    U16(p + p[0x11] * 2, 0x3C8) = 0;
    count = ov81_02240F18(p[9]);
    for (i = 0; i < count; i++) {
        FillWindowPixelBuffer(p + 0x50 + (i + 2) * 0x10, 0);
    }
    ov81_022408A0(p, 0, p[0x11] + 1);
    p[0x10] = ov81_0224086C(p, 0);
    ov81_02241C0C(p);
    ov81_02241FEC(p);
    ov81_0224218C(p);
    ov81_02242300(p, U32(p, 0x468), 6);
}
