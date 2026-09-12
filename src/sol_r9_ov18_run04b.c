#include "sol_r9_ov18_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov18_021EEBE4(void *work, u32 index) {
    u8 *base = (u8 *)work + 0xc;
    u32 offset = index * 0x10;
    u32 message;
    FillWindowPixelBuffer(base + offset, 0);
    message = LanguageToDexFlag(U8(work, 0x185c));
    ov18_021F9648(base + offset, PTR(work, 0x65c), message + 0x7a, 0x38, 0, 0, 0x20100, 2);
    ScheduleWindowCopyToVram(base + offset);
}
