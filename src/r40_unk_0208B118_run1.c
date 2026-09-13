#include "r40_unk_0208B118_private.h"

void sub_0208B118(SummaryWorkB118 *work) {
    if (sub_0208A2E0(work, -1) != -1) {
        sub_020196E8(work->anim7D0, 5, 0x18, 5);
    } else {
        FillBgTilemapRect(work->bgConfig, 6, 1, 0x18, 5, 6, 3, 0x10);
        ScheduleBgTilemapBufferTransfer(work->bgConfig, 6);
    }

    if (sub_0208A2E0(work, 1) != -1) {
        sub_020196E8(work->anim7D0, 6, 0x18, 0xD);
    } else {
        FillBgTilemapRect(work->bgConfig, 6, 1, 0x18, 0xD, 6, 3, 0x10);
        ScheduleBgTilemapBufferTransfer(work->bgConfig, 6);
    }
}
