#include "to47_overlay87_private.h"

void ov87_021E6DBC(State *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 0x23, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
    GfGfxLoader_LoadScrnDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 0x25, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
}
void ov87_021E6E00(State *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 0x26, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
    GfGfxLoader_LoadScrnDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 0x28, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
}
void ov87_021E6E44(void) {
    void *d;
    void *h = GfGfxLoader_GetPlttData(0xcf, 0x22, &d, 0x7a);
    DC_FlushRange(*((void **)d + 3), 0xa0);
    GXS_LoadBGPltt(*((void **)d + 3), 0, 0xa0);
    Heap_Free(h);
}
void ov87_021E6E78(void) {
    void *d;
    void *h = GfGfxLoader_GetPlttData(0xcf, 0, &d, 0x7a);
    DC_FlushRange(*((void **)d + 3), 0x180);
    GX_LoadBGPltt(*((void **)d + 3), 0, 0x180);
    Heap_Free(h);
}
void ov87_021E6EB0(State *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 4, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
    GfGfxLoader_LoadScrnDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 6, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
}
void ov87_021E6EF4(State *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 7, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
    GfGfxLoader_LoadScrnDataFromOpenNarc(*(void **)((u8 *)p + 0x380), 9, *(void **)((u8 *)p + 0x58), bg, 0, 0, 0, 0x7a);
}
