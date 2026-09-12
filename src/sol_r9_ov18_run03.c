#include "sol_r9_ov18_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))

void ov18_021EE5E4(void *work, u32 index, u32 value) {
    ov18_021EE520(work, index, value);
    ScheduleWindowCopyToVram((u8 *)work + 0xc + index * 0x10);
}

void ov18_021EE5FC(void *work) {
    ov18_021EE5E4(work, U8(work, 0x185d) + 2, U16(work, 0x102c));
    ov18_021EE5E4(work, U8(work, 0x185d) + 4, U16(work, 0x102e));
    U8(work, 0x185d) ^= 1;
}
