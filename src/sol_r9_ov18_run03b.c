#include "sol_r9_ov18_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov18_021EE6BC(void *work, u32 value, u32 other) {
    ov18_021EE71C(work, 7);
    ov18_021EE75C(work, value, 8);
    ov18_021EE7DC(work, value, 9);
    ov18_021EE834(work, value, other, 10);
}

void ov18_021EE6EC(void *work, u32 value, u32 other) {
    ov18_021EE71C(work, 0x51);
    ov18_021EE75C(work, value, 0x52);
    ov18_021EE7DC(work, value, 0x53);
    ov18_021EE834(work, value, other, 0x54);
}

void ov18_021EE71C(void *work, u32 index) {
    u8 *base = (u8 *)work + 0xc;
    u32 offset = index * 0x10;
    FillWindowPixelBuffer(base + offset, 0);
    ov18_021F9648(base + offset, PTR(work, 0x65c), 8, 0, 0, 4, 0x20100, 0);
    ScheduleWindowCopyToVram(base + offset);
}
