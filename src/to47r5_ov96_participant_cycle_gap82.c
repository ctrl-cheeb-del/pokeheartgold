#include "to47r5_ov96_participant_cycle_gap82_private.h"

u8 ov96_02200EF4(void *a, u8 *work, u16 c) {
    u8 ret = 4;

    if (work[0x3E5] == 4) {
        return 0;
    }
    work[0x3E2]++;
    if (work[0x3E2] >= work[0x3E3]) {
        U32_AT(work, 0x3DC) = 1;
        work[0x3E2] = 0;
    }
    if (U32_AT(work, 0x3DC) != 0) {
        int index = work[0x3E4] + work[0x3E1];
        GF_ASSERT(index >= work[0x3E4]);
        ov96_02200F84(a, work, index, c);
        ret = index;
        work[0x3E1]++;
        if (work[0x3E1] >= work[0x3E0]) {
            work[0x3E1] = 0;
            U32_AT(work, 0x3DC) = 0;
        }
    }
    return ret;
}
