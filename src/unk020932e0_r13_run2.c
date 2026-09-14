#include "unk020932e0_r13_private.h"

void sub_020955EC(Residual13Work *work) {
    VecFx32 matrix;
    int value;
    u8 remainder;

    work->selection++;
    if (work->selection == work->selectionCount) {
        work->selection = 0;
    }
    Sprite_SetAnimCtrlSeq(work->sprite8B8, 3);
    sub_020943EC(work);
    PlaySE(0x5DC);
    if (work->selection == 0x12) {
        if (sub_02095DD8(work->cursor) == 2) {
            remainder = sub_02095DE8(work->cursor) % 6;
            sub_02095D40(work->cursor, 6, remainder);
            matrix.x = (remainder * 24 + 20) << FX32_SHIFT;
            matrix.y = 0x28000;
            matrix.z = 0;
            Sprite_SetMatrix(work->sprite8C0, &matrix);
        }
    } else if (sub_02095DD8(work->cursor) == 6) {
        value = sub_02095DE8(work->cursor);
        sub_02095D40(work->cursor, 2, value);
    }
}
