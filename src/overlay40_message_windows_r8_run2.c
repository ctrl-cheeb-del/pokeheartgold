#include "global.h"

extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);

void ov40_0222E4A4(void *);

void ov40_0222E4A4(void *p) {
    int i;
    void *win;

    win = p;
    i = 0;
    win = (u8 *)win + 0xC;
    for (; i < 8; i++) {
        ClearWindowTilemapAndCopyToVram(win);
        RemoveWindow(win);
        win = (u8 *)win + 0x10;
    }
}
