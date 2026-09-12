#include "overlay40_residual31_private.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

void ov40_02237C54(void *p) {
    void *inner = PTR(p, 0x860);
    ClearWindowTilemapAndCopyToVram((u8 *)inner + 0x234);
    RemoveWindow((u8 *)inner + 0x234);
}

void ov40_02237C74(void *p) {
    int i = 0;
    void *inner = PTR(p, 0x860);
    void *window = (u8 *)inner + 0x234;
    for (; i < 2; i++, window = (u8 *)window + 0x10) {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
    }
}
