#include "overlay43_plaza_menu_r26_private.h"

void ov43_0222DACC(void *p) {
    int i;
    u8 *window;

    i = 0;
    window = (u8 *)p + 0x118;
    for (; i < 8; i++, window += 0x10) {
        ClearWindowTilemapAndScheduleTransfer(window);
    }
}
