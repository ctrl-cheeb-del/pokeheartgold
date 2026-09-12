#include "overlay89_r11_private.h"

void ov89_0225B298(void *unused, u8 *work) {
    int i;
    u8 *p;

    p = work;
    i = 0;
    p += 0x94;
    do {
        sub_020181EC(p);
        i++;
        p += 0x78;
    } while (i < 3);
    sub_020181EC(work + 0x1C);
}
