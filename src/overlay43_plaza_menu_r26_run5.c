#include "overlay43_plaza_menu_r26_private.h"

void ov43_0222DB28(void *p, void *work, int index) {
    int sequence;

    if (WORD(p, 0x10) == 1) {
        sequence = 2;
        Sprite_SetPositionXY(PTR(work, 0x1FC), index * 0x20 + 0x10, 0xB0);
    } else if (index == 2) {
        sequence = 2;
        Sprite_SetPositionXY(PTR(work, 0x1FC), 0xF0, 0xB0);
    } else {
        sequence = 1;
        Sprite_SetPositionXY(PTR(work, 0x1FC), index * 0x70 + 0x38, 0xB0);
    }
    ov43_0222AD74(work, 1, sequence);
}
