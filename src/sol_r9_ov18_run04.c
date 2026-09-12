#include "sol_r9_ov18_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define DRAW_SCHEDULE(name, message)                                                     \
    void name(void *work, u32 index) {                                                   \
        u8 *base = (u8 *)work + 0xc;                                                     \
        u32 offset = index * 0x10;                                                       \
        FillWindowPixelBuffer(base + offset, 0);                                         \
        ov18_021F9648(base + offset, PTR(work, 0x65c), message, 0x14, 0, 0, 0x20100, 2); \
        ScheduleWindowCopyToVram(base + offset);                                         \
    }

DRAW_SCHEDULE(ov18_021EE9FC, 0xa)
DRAW_SCHEDULE(ov18_021EEA40, 0xb)
