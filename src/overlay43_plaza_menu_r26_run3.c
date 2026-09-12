#include "overlay43_plaza_menu_r26_private.h"

void ov43_0222D87C(void *p, void *work) {
    int i;
    u8 *row = p;
    u8 *window;

    i = 0;
    row += 0x14;
    for (; i < 3; i++, row += 0x4C) {
        ov43_0222DF90(row, work);
    }
    i = 0;
    window = (u8 *)p + 0x118;
    for (; i <= 5; i++, window += 0x10) {
        ClearWindowTilemapAndScheduleTransfer(window);
    }
    ov43_0222AA70(work);
}
