#include "overlay96_course_scene_emitter_tick_private.h"

int ov96_02208B34(u8 *work) {
    s32 total;
    int result = 4;

    if (work[0x559] == 4) {
        return 0;
    }

    work[0x556]++;
    if (work[0x556] >= work[0x557]) {
        U32_AT(work, 0x550) = 1;
        work[0x556] = 0;
    }

    if (U32_AT(work, 0x550) != 0) {
        total = work[0x558] + work[0x555];
        GF_ASSERT(total >= work[0x558]);
        ov96_02208BB8(work, (u8)total);
        result = (u8)total;
        work[0x555]++;
        if (work[0x555] >= work[0x554]) {
            work[0x555] = 0;
            U32_AT(work, 0x550) = 0;
        }
    }
    return result;
}
