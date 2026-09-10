#include "summary_transition_task_internal.h"

int sub_0208A2E0(SummarySelectionWork *work, int direction) {
    switch (work->selection->source) {
    case 0:
        return sub_0208A3F4(work, direction);
    case 1:
        return sub_0208A45C(work, direction);
    case 2:
        return sub_0208A4B8(work, direction);
    default:
        return -1;
    }
}

BOOL sub_0208A310(SummarySelectionWork *work, int index) {
    int size;
    int offset;
    u8 *base;
    u8 *mon;

    switch (work->selection->source) {
    case 0:
        size = sub_02070D90();
        base = work->selection->mons;
        offset = index * size;
        if (GetMonData(base + offset, MON_DATA_SPECIES, NULL) != 0) {
            if (GetMonData(base + offset, MON_DATA_IS_EGG, NULL) != 0) {
                return TRUE;
            }
        }
        break;
    case 1:
        if (index < work->selection->count) {
            mon = Party_GetMonByIndex(work->selection->mons, index);
            if (GetMonData(mon, MON_DATA_SPECIES, NULL) != 0) {
                if (GetMonData(mon, MON_DATA_IS_EGG, NULL) != 0) {
                    if (sub_0208A3CC(work) != TRUE) {
                        break;
                    }
                    return TRUE;
                }
                return TRUE;
            }
        }
        break;
    case 2:
        size = sub_02070D94();
        base = work->selection->mons;
        offset = index * size;
        if (GetBoxMonData(base + offset, MON_DATA_SPECIES, NULL) != 0) {
            if (GetBoxMonData(base + offset, MON_DATA_IS_EGG, NULL) != 0) {
                return TRUE;
            }
        }
        break;
    }
    return FALSE;
}
