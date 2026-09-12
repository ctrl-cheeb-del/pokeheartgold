#include "sol_r9_ov18_private.h"

void ov18_021EE3FC(void *work) {
    u32 first;
    u32 second;
    ov18_021EE35C(work, ov18_021F9F3C, 0x14);
    ov18_021EE508(work, 0, 0);
    ov18_021EE508(work, 1, 1);
    ov18_021EE5FC(work);
    first = ov18_021F8824(work);
    second = ov18_021F8838(work);
    ov18_021EE6BC(work, second, first);
    ov18_021EE8B8(work, second, first);
}
