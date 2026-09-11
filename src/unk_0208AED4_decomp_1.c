#include "unk_0208AED4_internal.h"

int sub_0208AED4(SummaryWork8AED4 *work) {
    Sprite_SetAnimCtrlSeq(work->sprite428, 1);
    Sprite_SetDrawFlag(work->sprite42c, TRUE);
    sub_0208BCB4(work);
    sub_0208AF08(work, 1);
    return 9;
}

void sub_0208AF08(SummaryWork8AED4 *work, int value) {
    if (value == 1) {
        sub_020196E8(work->anim7d0, 0, 0, 0x12);
        Sprite_SetDrawFlag(work->sprite448, FALSE);
        sub_0208DC68(work, 1);
        return;
    }
    if (work->inner->unk18 != 0) {
        sub_020196E8(work->anim7d0, 1, 0, 0x12);
        Sprite_SetDrawFlag(work->sprite448, TRUE);
    } else {
        sub_0208AF70(work);
    }
    sub_0208DC68(work, 0);
}

void sub_0208AF70(SummaryWork8AED4 *work) {
    FillBgTilemapRect(work->bgConfig, 6, 0x3006, 0, 0x12, 0x11, 6, 0x11);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 6);
}

void sub_0208AFA0(SummaryWork8AED4 *work, int value) {
    if (work->inner->mode == 1) {
        return;
    }
    if (value == 1) {
        sub_020196E8(work->anim7d0, 2, 1, 0x10);
        sub_0208DD20(work, 1);
        return;
    }
    sub_020196E8(work->anim7d0, 3, 1, 0x10);
    sub_0208DD20(work, 0);
}
