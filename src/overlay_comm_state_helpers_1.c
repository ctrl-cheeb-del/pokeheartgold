#include "overlay_comm_state_helpers_internal.h"

int sub_02088D48(SummaryMoveWork *work) {
    u32 keys;
    int index;

    keys = gSystem.newKeys;

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

int sub_02088E98(SummaryMoveWork *work) {
    int index;

    if (gSystem.newKeys & 0x40) {
        if (sub_0208A71C(work, -1) == TRUE) {
            PlaySE(0x5DC);
            sub_0208A79C(work);
        }
        return 6;
    }
    if (gSystem.newKeys & 0x80) {
        if (sub_0208A71C(work, 1) == TRUE) {
            PlaySE(0x5DC);
            sub_0208A79C(work);
        }
        return 6;
    }
    if (gSystem.newKeys & 1) {
        sub_0208AFA0(work, 1);
        Sprite_SetDrawFlag(work->sprite42C, FALSE);
        if (work->selectionLow != work->selectionHigh) {
            PlaySE(0x5DD);
            sub_0208A834(work);
            sub_0208BB24(work, work->selectionLow, work->selectionHigh);
            sub_0208DB64(work);
            sub_0208A79C(work);
        } else {
            PlaySE(0x5DC);
        }
        return 5;
    }
    if (gSystem.newKeys & 2) {
        PlaySE(0x940);
        sub_0208AFA0(work, 1);
        Sprite_SetDrawFlag(work->sprite42C, FALSE);
        return sub_0208B044(work, 5);
    }
    index = sub_0208ADDC(work);
    if (index == 4) {
        PlaySE(0x940);
        sub_0208AFA0(work, 1);
        Sprite_SetDrawFlag(work->sprite42C, FALSE);
        return sub_0208B044(work, 5);
    }
    if (index != -1 && work->moves[index] != 0) {
        sub_0208AFA0(work, 1);
        Sprite_SetDrawFlag(work->sprite42C, FALSE);
        if (index != work->selectionHigh) {
            work->selectionLow = index;
            PlaySE(0x5DD);
            sub_0208A834(work);
            sub_0208BB24(work, work->selectionLow, work->selectionHigh);
            sub_0208DB64(work);
            sub_0208A79C(work);
        } else {
            PlaySE(0x5DC);
        }
        return 5;
    }
    return 6;
}

int sub_02089028(SummaryMoveWork *work) {
    u32 keys;
    int index;

    keys = gSystem.newKeys;

    if (keys & 0x40) {
        if (sub_0208A71C(work, -1) == TRUE) {
            PlaySE(0x5DC);
            sub_0208A79C(work);
        }
        return 8;
    }
    if (keys & 0x80) {
        if (sub_0208A71C(work, 1) == TRUE) {
            PlaySE(0x5DC);
            sub_0208A79C(work);
        }
        return 8;
    }
    if (keys & 1) {
        PlaySE(0x5DD);
        index = work->selectionLow;
        if (index == 4) {
            work->menu->cursor = 4;
            work->menu->flag = 0;
            return 0x15;
        }
        if (MoveIsHM(work->moves[index]) == TRUE && work->menu->value != 0) {
            thunk_Sprite_SetDrawFlag(work->sprite44C, FALSE);
            sub_0208DBF0(work);
            return 8;
        }
        return sub_0208AED4(work);
    }
    if (keys & 2) {
        PlaySE(0x940);
        work->menu->cursor = 4;
        work->menu->flag = 1;
        return sub_0208B044(work, 0x15);
    }

    index = sub_0208AE48(work);
    switch (index) {
    case -1:
        break;
    case 4:
        if (work->menu->value != 0) {
            PlaySE(0x5DD);
            work->selectionLow = 4;
            sub_0208A79C(work);
        }
        break;
    case 5:
        PlaySE(0x940);
        work->selectionLow = 5;
        work->menu->cursor = 4;
        work->menu->flag = 0;
        return sub_0208B044(work, 0x15);
    default:
        if (MoveIsHM(work->moves[index]) == TRUE && work->menu->value != 0) {
            PlaySE(0x5DD);
            work->selectionLow = index;
            thunk_Sprite_SetDrawFlag(work->sprite44C, FALSE);
            sub_0208BBDC(work);
            sub_0208DBF0(work);
            return 8;
        }
        if (work->moves[index] != 0) {
            PlaySE(0x5DD);
            work->selectionLow = index;
            sub_0208A79C(work);
            return sub_0208AED4(work);
        }
        break;
    }
    return 8;
}

int sub_02089208(SummaryMoveWork *arg) {
    struct System *system = &gSystem;
    SummaryMoveWork *work = arg;
    u32 keys;
    int input;

    keys = system->newKeys;

    if (keys & 1) {
        PlaySE(0x5DD);
        work->menu->cursor = work->selectionLow;
        work->menu->flag = 0;
        return sub_0208B068(work, 0x15);
    }
    if (keys & 2) {
        PlaySE(0x940);
        Sprite_SetAnimCtrlSeq(work->sprite428, 0);
        Sprite_SetDrawFlag(work->sprite42C, FALSE);
        sub_0208AF08(work, 0);
        return sub_0208B044(work, 8);
    }
    input = sub_0208AE88(work);
    if (input != -1) {
        switch (input) {
        case 0:
            PlaySE(0x5DD);
            work->menu->cursor = work->selectionLow;
            work->menu->flag = 0;
            return sub_0208B068(work, 0x15);
        case 1:
            PlaySE(0x940);
            Sprite_SetAnimCtrlSeq(work->sprite428, 0);
            Sprite_SetDrawFlag(work->sprite42C, FALSE);
            sub_0208AF08(work, 0);
            return sub_0208B044(work, 8);
        default:
            break;
        }
    }
    return 9;
}
