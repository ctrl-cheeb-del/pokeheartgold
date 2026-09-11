#include <string.h>

#include "unk02012204_sol_partial_internal.h"

void sub_02012204(VectorListWork *work) {
    s32 i;
    s32 offset;

    memset((u8 *)sub_02010EE0(work, 0) + 0x300, 0, 0x300);
    i = work->count - 1;
    if (i >= 0) {
        offset = i * sizeof(VectorRecord);
        do {
            sub_02012238(work, (VectorRecord *)((u8 *)work->vectors + offset));
            offset -= sizeof(VectorRecord);
            i--;
        } while (i >= 0);
    }
}
