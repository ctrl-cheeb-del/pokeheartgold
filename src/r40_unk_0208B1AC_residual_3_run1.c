#include "r40_unk_0208B1AC_residual_3_private.h"

void sub_0208B4EC(SummaryWork *work) {
    if (work->value == 7) {
        Sprite_SetDrawFlag(work->sprite454, 0);
        Sprite_SetDrawFlag(work->sprite524, 0);
        return;
    }
    if (work->value != 0) {
        Sprite_SetDrawFlag(work->sprite524, 0);
        Sprite_SetDrawFlag(work->sprite454, 1);
        Sprite_SetAnimCtrlSeq(work->sprite454, work->value);
        return;
    }
    Sprite_SetDrawFlag(work->sprite524, 1);
    Sprite_SetDrawFlag(work->sprite454, 0);
}
