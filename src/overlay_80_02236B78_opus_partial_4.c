#include "overlay_80_02236B78_opus_partial_internal.h"

u16 ov80_022372B4(Ov80FrontierWork *work) {
    u16 ret = work->unk0E;
    if (ov80_02237254(work->unk04) == TRUE) {
        if (work->unk57E > work->unk0E) {
            ret = work->unk57E;
        }
    }
    return ret;
}
