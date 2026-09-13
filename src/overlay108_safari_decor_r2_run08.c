#include "overlay108_safari_decor_r2_private.h"

void ov108_021E9A08(void *p) {
    void *bg = PTR(p, 0x438);
    FreeBgTilemapBuffer(bg, 7);
    FreeBgTilemapBuffer(PTR(p, 0x438), 6);
    FreeBgTilemapBuffer(PTR(p, 0x438), 5);
    FreeBgTilemapBuffer(PTR(p, 0x438), 4);
    FreeBgTilemapBuffer(PTR(p, 0x438), 3);
    FreeBgTilemapBuffer(PTR(p, 0x438), 2);
    FreeBgTilemapBuffer(PTR(p, 0x438), 1);
    Heap_Free(PTR(p, 0x438));
}
