#include "overlay40_message_windows_internal.h"

void ov40_02230398(void *work) {
    int i;
    void *window = work;

    i = 0;
    window = (u8 *)window + 0x3C;
    do {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        i++;
        window = (u8 *)window + 0x10;
    } while (i < 5);
}

BOOL ov40_022303B8(void *work) {
    switch (sub_0203088C(work, 3, 0)) {
    case 0xE:
    case 0x11:
    case 0x14:
    case 0x17:
    case 0x1A:
    case 0x1D:
    case 0x20:
        return TRUE;
    default:
        return FALSE;
    }
}
