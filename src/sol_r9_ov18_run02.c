#include "sol_r9_ov18_private.h"

void ov18_021EE508(void *work, u32 index, u32 value) {
    ov18_021EE44C(work, index, value);
    ScheduleWindowCopyToVram((u8 *)work + 0xc + index * 0x10);
}
