#include "r40_overlay_90_residual_3_private.h"

void ov90_02258938(Ov90Work3 *arg) {
    u8 *work = (u8 *)arg;
    int i;
    u8 *entry;
    SysTask_Destroy(*(void **)(work + 0x5EC));
    SysTask_Destroy(*(void **)(work + 0x5F0));
    ov90_0225A108(work + 0x2E4);
    ov90_0225A340(work + 0x1CC);
    i = 0;
    i = 0;
    if (i < work[0x10]) {
        entry = work + 0x204;
        do {
            ov90_02259EAC(entry);
            i++;
            entry += 0x38;
        } while (i < work[0x10]);
    }
    ov90_02259434(work + 0x4C);
    ov90_02259784(work);
    ov90_022591D4(work + 0x3C);
    ov90_02258E10(work + 0x1B0);
    ov90_02259158(work + 0x84);
    ov90_02259084(work + 0x30);
    Heap_Free(work);
}
