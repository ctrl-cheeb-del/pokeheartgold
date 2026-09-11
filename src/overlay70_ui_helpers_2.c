#include "overlay70_ui_helpers_private.h"

int ov70_0223EEE8(u8 *work) {
    ov70_0223E8E8(work, 10, 1, 0, 0xF0F);
    ov70_02238D84(work, 0x10, 8);
    return 3;
}

int ov70_0223EF10(u8 *work) {
    *(u16 *)(work + 0x118) = 0xFFFF;
    ov70_022420C4(*(void **)(work + 0x11A8), 1);
    *(u32 *)(work + 0x2C) = 9;
    return 3;
}
