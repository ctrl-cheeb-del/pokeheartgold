#include "global.h"

#include "r40_overlay_103_residual_12_private.h"

u32 ov103_021ED9AC(R40Ov103Work12 *work) {
    if (work->ptr24 == 0) {
        work->next28 = 0x15;
        return 0;
    }
    ov103_021EDC68(work, 0xB, work->value22, work->flags21_low);
    work->state18 = 3;
    return 6;
}
