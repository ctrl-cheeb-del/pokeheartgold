#include "ov83_wave42_private.h"

void ov83_0223FA00(void *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x7a8), 0x22, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    if (ov80_02237D8C(U8(p, 9)) == 0) {
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x23, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    } else {
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x24, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    }
}

void ov83_0223FA74(void) {
    void *d;
    void *a = GfGfxLoader_GetPlttData(0xb7, 0x9c, &d, 0x6b);
    DC_FlushRange(PTR(d, 0xc), 0xe0);
    GX_LoadBGPltt(PTR(d, 0xc), 0, 0xe0);
    Heap_Free(a);
}

void ov83_0223FAA8(void *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x7a8), 0x22, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x2a, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
}

void ov83_0223FAF0(void) {
    void *d;
    void *a = GfGfxLoader_GetPlttData(0xb7, 0x9c, &d, 0x6b);
    DC_FlushRange(PTR(d, 0xc), 0x80);
    GX_LoadBGPltt(PTR(d, 0xc), 0, 0x80);
    Heap_Free(a);
}

void ov83_0223FB24(void *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x7a8), 0x22, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x2b, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
}

void ov83_0223FB6C(void *p) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x7a8), 0x22, PTR(p, 0x4c), 2, 0, 0, 1, 0x6b);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x26, PTR(p, 0x4c), 2, 0, 0, 1, 0x6b);
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x7a8), 0x28, PTR(p, 0x4c), 6, 0, 0, 1, 0x6b);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x29, PTR(p, 0x4c), 6, 0, 0, 1, 0x6b);
}

void ov83_0223FBEC(void *p, int bg) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x7a8), 0x28, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x7a8), 0x93, PTR(p, 0x4c), bg, 0, 0, 1, 0x6b);
    GfGfxLoader_GXLoadPalFromOpenNarc(PTR(p, 0x7a8), 0xbe, 4, 0, 0, 0x6b);
}

int ov83_0223FC48(void *p, void *w, int msg, int x, int y, int speed, u8 fg, u8 sh, u8 bg, u8 font) {
    int ret;
    FillWindowPixelBuffer(w, bg);
    ReadMsgDataIntoString(PTR(p, 0x20), msg, PTR(p, 0x2c));
    StringExpandPlaceholders(PTR(p, 0x24), PTR(p, 0x28), PTR(p, 0x2c));
    ret = AddTextPrinterParameterizedWithColor(w, font, PTR(p, 0x28), x, y, speed, ((fg & 0xff) << 16) | ((sh & 0xff) << 8) | (bg & 0xff), 0);
    ScheduleWindowCopyToVram(w);
    return ret;
}

int ov83_0223FCB4(void *p, void *w, int msg, int x, int y, int speed, u8 fg, u8 sh, u8 bg, u8 font) {
    int ret;
    ReadMsgDataIntoString(PTR(p, 0x20), msg, PTR(p, 0x2c));
    StringExpandPlaceholders(PTR(p, 0x24), PTR(p, 0x28), PTR(p, 0x2c));
    ret = AddTextPrinterParameterizedWithColor(w, font, PTR(p, 0x28), x, y, speed, ((fg & 0xff) << 16) | ((sh & 0xff) << 8) | (bg & 0xff), 0);
    ScheduleWindowCopyToVram(w);
    return ret;
}

int ov83_0223FD14(void *p, int msg, u8 color) {
    int r = ov83_0223FC48(p, (u8 *)p + 0xb0, msg, 1, 1, 0xff, 1, 2, 0xf, color);
    ScheduleWindowCopyToVram((u8 *)p + 0xb0);
    return r;
}
