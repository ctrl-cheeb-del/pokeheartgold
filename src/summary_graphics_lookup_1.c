#include "summary_graphics_lookup_internal.h"

void *sub_02087FD4(int index) {
    if (index >= 7) {
        GF_ASSERT(index < 7);
        return *(void **)(_02103754 + 0x64);
    }
    return _021037B8[index].value;
}

const void *sub_02087FF8(void *work, int index) {
    if (index == 0 && sub_02087E1C(work) == 0) {
        return _0210357C;
    }
    if (index == 3 && sub_02087E1C(work) == 0) {
        return _02102DC0;
    }
    return sub_02087FD4(index);
}

void sub_02088030(SummaryTableWork *work) {
    int i = 0;
    SummaryTableEntry *entry = work->entries;

    work->activeCount = 0;
    while (i < 5) {
        if (entry->value != NULL) {
            work->activeCount++;
        }
        i++;
        entry++;
    }
}
