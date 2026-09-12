#include "overlay96_course_ui_r108_private.h"

extern const Ov96R108GraphicsModes ov96_0221D28C;
extern const Ov96R108BgTemplate ov96_0221D30C;
extern const Ov96R108BgTemplate ov96_0221D328;
extern const Ov96R108BgTemplate ov96_0221D344;
extern const Ov96R108BgTemplate ov96_0221D29C;
extern const Ov96R108BgTemplate ov96_0221D2B8;
extern const Ov96R108BgTemplate ov96_0221D2D4;
extern const Ov96R108BgTemplate ov96_0221D2F0;

extern void SetBothScreensModesAndDisable(const void *);
extern void InitBgFromTemplate(void *, int, const void *, int);
extern void BgClearTilemapBufferAndCommit(void *, int);
extern void GfGfx_EngineATogglePlanes(int, int);
extern u32 GfGfxLoader_LoadCharData(u32, s32, void *, u32, u32, u32, BOOL, u32);
extern void GfGfxLoader_LoadScrnData(u32, s32, void *, u32, u32, u32, BOOL, u32);
extern void GfGfxLoader_GXLoadPal(u32, s32, u32, u32, u32, u32);
extern void ov96_022146C0(void *);

void ov96_022118C4(void *bg) {
    Ov96R108GraphicsModes modes;
    Ov96R108BgTemplate t0;
    Ov96R108BgTemplate t1;
    Ov96R108BgTemplate t2;
    Ov96R108BgTemplate t3;
    Ov96R108BgTemplate t4;
    Ov96R108BgTemplate t5;
    Ov96R108BgTemplate t6;

    modes = ov96_0221D28C;
    SetBothScreensModesAndDisable(&modes);
    t0 = ov96_0221D30C;
    InitBgFromTemplate(bg, 0, &t0, 0);
    BgClearTilemapBufferAndCommit(bg, 0);
    t1 = ov96_0221D328;
    InitBgFromTemplate(bg, 1, &t1, 0);
    BgClearTilemapBufferAndCommit(bg, 1);
    t2 = ov96_0221D344;
    InitBgFromTemplate(bg, 2, &t2, 0);
    BgClearTilemapBufferAndCommit(bg, 2);
    t3 = ov96_0221D29C;
    InitBgFromTemplate(bg, 3, &t3, 0);
    BgClearTilemapBufferAndCommit(bg, 3);
    t4 = ov96_0221D2B8;
    InitBgFromTemplate(bg, 4, &t4, 0);
    BgClearTilemapBufferAndCommit(bg, 4);
    t5 = ov96_0221D2D4;
    InitBgFromTemplate(bg, 5, &t5, 0);
    BgClearTilemapBufferAndCommit(bg, 5);
    t6 = ov96_0221D2F0;
    InitBgFromTemplate(bg, 6, &t6, 0);
    BgClearTilemapBufferAndCommit(bg, 6);
    GfGfx_EngineATogglePlanes(8, 0);
}

void ov96_02211A24(void *arg) {
    u8 *p = arg;

    GfGfxLoader_LoadCharData(0xEC, 1, *(void **)(p + 4), 1, 0, 0, FALSE, *(u32 *)(p + 0x58));
    GfGfxLoader_LoadCharData(0xEC, 3, *(void **)(p + 4), 2, 0, 0, FALSE, *(u32 *)(p + 0x58));
    GfGfxLoader_LoadCharData(0xEC, 6, *(void **)(p + 4), 5, 0, 0, FALSE, *(u32 *)(p + 0x58));
    GfGfxLoader_LoadCharData(0xEC, 7, *(void **)(p + 4), 6, 0, 0, FALSE, *(u32 *)(p + 0x58));
    GfGfxLoader_LoadScrnData(0xEC, 2, *(void **)(p + 4), 1, 0, 0, FALSE, *(u32 *)(p + 0x58));
    GfGfxLoader_LoadScrnData(0xEC, 4, *(void **)(p + 4), 2, 0, 0, FALSE, *(u32 *)(p + 0x58));
    ov96_022146C0(*(void **)(p + 0x750));
    GfGfxLoader_GXLoadPal(0xEC, 0, 0, 0, 0x80, *(u32 *)(p + 0x58));
    GfGfxLoader_GXLoadPal(0xEC, 5, 4, 0, 0x40, *(u32 *)(p + 0x58));
}
