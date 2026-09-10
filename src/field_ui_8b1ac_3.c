#include "field_ui_8b1ac_internal.h"

void sub_0208B55C(u8 *work) {
    u16 i;
    sub_0208BA60(work);
    for (i = 0; i < 4; i++) {
        u16 move = *(u16 *)(work + 0x264 + i * 2);
        if (move != 0) {
            sub_0208BA88(work, (u8)(i + 13), (u8)(i + 5), (u8)GetMoveAttr(move, 3));
        }
    }
    sub_0208BE70(work);
}
