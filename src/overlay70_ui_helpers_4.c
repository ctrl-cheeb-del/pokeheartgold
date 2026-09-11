#include "overlay70_ui_helpers_private.h"

int ov70_0223F0B4(u8 *work) {
    ov70_0223E8E8(work, 0x17, 1, 0, 0xF0F);
    ov70_02238D84(work, 0x10, 14);
    return 3;
}

int ov70_0223F0DC(u8 *work) {
    void *prompt = ov70_02238C14(*(void **)(work + 4), 12, 0x11A, 3, 0);
    *(void **)(work + 0x11C8) = prompt;
    *(u32 *)(work + 0x2C) = 15;
    return 3;
}
