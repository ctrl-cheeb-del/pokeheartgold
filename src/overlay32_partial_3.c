#include "overlay32_partial_internal.h"

void ov32_0225D834(u8 *work) {
    u32 i = 0;
    Ov32Window *window;
    window = (Ov32Window *)(work + 0x24);
    do {
        RemoveWindow(window);
        i++;
        window++;
    } while (i < 18);
}
