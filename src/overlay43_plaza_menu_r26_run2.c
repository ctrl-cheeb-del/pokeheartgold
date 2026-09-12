#include "overlay43_plaza_menu_r26_private.h"

void ov43_0222D610(void *p, void *unused, void *work) {
    int i;
    int j;
    u8 *row;

    i = 0;
    row = p;
    row += 0x14;
    for (; i < 3; i++, row += 0x4C) {
        for (j = 0; j < 8; j++) {
            ov43_0222DED0(row, j);
        }
        ov43_0222DE10(row);
    }
    ov43_0222DDD0(p, work);
    ov43_0222DD88((u8 *)p + 0xF8);
}
