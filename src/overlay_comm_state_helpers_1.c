#include "overlay_comm_state_helpers_internal.h"

int sub_02088D48(SummaryMoveWork *work) {
    u32 keys = gSystem.newKeys;
    int index;

    if (keys & 0x40) {
        if (sub_0208A71C(work, -1) == TRUE) {
            PlaySE(0x5DC);
            sub_0208A79C(work);
        }
        return 5;
    }
    if (keys & 0x80) {
        if (sub_0208A71C(work, 1) == TRUE) {
            PlaySE(0x5DC);
            sub_0208A79C(work);
        }
        return 5;
    }
    if ((keys & 1) && work->menu->mode != 1) {
        PlaySE(0x5DD);
        return sub_0208B08C(work, 7);
    }
    if (keys & 2) {
        PlaySE(0x940);
        sub_0208AFA0(work, 0);
        return sub_0208B044(work, 4);
    }
    index = sub_0208AE08(work);
    if (index == 4) {
        if (work->menu->mode != 1) {
            PlaySE(0x5DD);
            return sub_0208B08C(work, 7);
        }
    } else if (index == 5) {
        PlaySE(0x940);
        sub_0208AFA0(work, 0);
        return sub_0208B044(work, 4);
    } else if (index != -1 && work->moves[index] != 0) {
        work->selectionLow = index;
        PlaySE(0x5DC);
        sub_0208A79C(work);
        return 5;
    }
    return 5;
}

int sub_02088E68(SummaryMoveWork *work) {
    sub_0208AFA0(work, 0);
    sub_0208BC78(work);
    work->selectionHigh = work->selectionLow;
    return 6;
}
