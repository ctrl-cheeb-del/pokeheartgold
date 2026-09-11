#include "overlay70_ui_helpers_private.h"

int ov70_0223EFB8(u8 *work) {
    ov70_0223E8E8(work, 11, 1, 0, 0xF0F);
    ov70_02238D84(work, 0x10, 11);
    return 3;
}

int ov70_0223EFE0(u8 *work) {
    ov70_022420C4(*(void **)(work + 0x11A8), 2);
    *(u16 *)(work + 0x118) = 0xFFFF;
    *(u32 *)(work + 0x2C) = 12;
    return 3;
}
