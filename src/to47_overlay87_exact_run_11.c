#include "to47_overlay87_private.h"

void ov87_021E7460(State *p, int bg, int a, int b, u8 c) {
    BgTilemapRectChangePalette(*(void **)((u8 *)p + 0x58), bg, 0, 0, b, c, a);
    ScheduleBgTilemapBufferTransfer(*(void **)((u8 *)p + 0x58), bg);
}
u8 ov87_021E7490(State *p) {
    u8 i, n;
    n = 0;
    i = n;
    do {
        if (*((u8 *)p + 0x394 + i) == 1) {
            n++;
        }
        i++;
    } while (i < 9);
    return n;
}
void ov87_021E74B8(State *p) {
    u8 i = 0;
    do {
        *((u8 *)p + 0x394 + i) = 0;
        i++;
    } while (i < 9);
}
void ov87_021E74D4(State *p) {
    u8 i = 0;
    do {
        *((u8 *)p + 0x3a5 + i) = 0;
        i++;
    } while (i < 9);
}
