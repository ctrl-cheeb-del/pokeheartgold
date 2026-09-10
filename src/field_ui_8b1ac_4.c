#include "field_ui_8b1ac_internal.h"

void sub_0208B714(u8 *work) {
    int i;
    u8 *ptr;
    i = 0;
    ptr = work;
    for (; i < 25; i++) {
        Sprite_SetDrawFlag(*(void **)(ptr + 0x540), 0);
        ptr += 4;
    }
    for (i = 0; i < 5; i++) {
        Sprite_SetDrawFlag(*(void **)(work + 0x5A4), 0);
        work += 4;
    }
}

void sub_0208B74C(u8 *work) {
    int i;
    for (i = 0; i < 6; i++) {
        Sprite_SetDrawFlag(*(void **)(work + 0x5B8), 0);
        Sprite_SetAnimActiveFlag(*(void **)(work + 0x5B8), 1);
        Sprite_SetDrawPriority(*(void **)(work + 0x5B8), 6 - i);
        work += 4;
    }
}
