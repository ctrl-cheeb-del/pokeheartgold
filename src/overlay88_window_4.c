#include "overlay88_window_internal.h"

void ov88_022593D0(void *p) {
    int i;
    u8 *window;
    Heap_Free(*(void **)((u8 *)p + 0x94));
    String_Delete(*(void **)((u8 *)p + 0x90));
    window = p;
    i = 0;
    window += 0x60;
    while (i < 3) {
        RemoveWindow(window);
        ov88_0225954C(p);
        i++;
        window += 0x10;
        p = (u8 *)p + 0x20;
    }
}
