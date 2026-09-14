#include "to45_overlay65_r15_private.h"

void ov65_0221FAE0(void *windows) {
    int i;
    for (i = 0; i < 14; i++) {
        RemoveWindow((u8 *)windows + (i + 7) * 0x10);
    }
    for (i = 0; i < 8; i++) {
        RemoveWindow((u8 *)windows + (i + 0x1A) * 0x10);
    }
    RemoveWindow(windows);
    RemoveWindow((u8 *)windows + 0x10);
    RemoveWindow((u8 *)windows + 0x60);
    RemoveWindow((u8 *)windows + 0x150);
    RemoveWindow((u8 *)windows + 0x160);
    RemoveWindow((u8 *)windows + 0x170);
    RemoveWindow((u8 *)windows + 0x190);
}
