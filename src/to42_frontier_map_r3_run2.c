#include "to42_frontier_map_r3_private.h"

void FrontierMap_Update(u32 a0, FrontierMap *m);
void FrontierMap_Scroll(FrontierMap *m);
void ov80_02238B7C(FrontierMap *m);
void ov80_02238C78(FrontierMap *m);
void FrontierMap_SetVramBank(void *bgConfig, u32 mode);

void FrontierMap_LoadPaletteData(FrontierMap *m) {
    PaletteData_LoadNarc(m->plttData, 0x10, 7, 0x65, 0, 0x20, 0xE0);
    PaletteData_LoadNarc(m->plttData, 0x10, 8, 0x65, 0, 0x20, 0xD0);
    LoadUserFrameGfx2(m->bgConfig, 1, 0x3E2, 0xB, (u8)Options_GetFrame(*(void **)((u8 *)Frontier_GetLaunchArgs(m->unk08) + 4)), 0x65);
    PaletteData_LoadPaletteSlotFromHardware(m->plttData, 0, 0xB0, 0x20);
    LoadUserFrameGfx1(m->bgConfig, 1, 0x3D9, 0xC, 0, 0x65);
    PaletteData_LoadPaletteSlotFromHardware(m->plttData, 0, 0xC0, 0x20);
}

void ov80_02238FA0(FrontierMap *m) {
    void *narc = NARC_New(0xB7, 0x65);

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x81, m->bgConfig, 4, 0, 0, 1, 0x65);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x82, m->bgConfig, 4, 0, 0, 1, 0x65);
    PaletteData_LoadNarc(m->plttData, 0xB7, 0xBE, 0x65, 1, 0x20, 0);
    NARC_Delete(narc);
}

void ov80_02239004(FrontierMap *m, u32 mode, void *profile) {
    FrontierMapUnk11 tmpl;
    FmPlttData *plttA;
    FmPlttData *plttB;
    void *raw;
    s32 narcId;
    void *narc;
    u32 v;
    u32 w;

    m->unk14 = ov42_02228010(0x20, 0x65);
    m->unk18 = ov42_02227EE0(0x10, 0x10, 0x65);
    ov42_02229394(&m->unk1C);
    m->unk20 = ov42_02228F24(SpriteManager_GetSpriteList(m->unk38), m->plttData, 0x20, ov80_0222A7EC(profile), 0, 1, 0x65);
    tmpl = ov80_0223D554;
    tmpl.f08 = (u8)ov80_0222ACA0(mode, 5);
    tmpl.f09 = (u8)ov80_0222ACA0(mode, 6);
    v = ov80_0222ACA0(mode, 12);
    if (v == 0) {
        m->unk24 = ov42_022293B8(SpriteSystem_GetRenderer(m->unk34), m->bgConfig, &tmpl, 0x65);
    }
    if (ov80_0222ACA0(mode, 9) != 0xFFFF) {
        tmpl.f09 = (u8)ov80_0222ACA0(mode, 9);
        tmpl.f01 = 2;
        tmpl.f03 = 1;
        tmpl.f04 = 8;
        tmpl.f06 = 1;
        if (v == 0) {
            m->unk28 = ov42_022293B8(SpriteSystem_GetRenderer(m->unk34), m->bgConfig, &tmpl, 0x65);
        }
    }
    m->unk2C = ov42_02229A40(0x80, 0x65);
    m->unk30 = ov42_02229974(0x80, 0x65);
    ov42_02227F48(m->unk18, ov80_0223D654);
    w = ov80_0222ACA0(mode, 0);
    narcId = ov80_0222ACA0(mode, 5);
    narc = NARC_New(narcId, 0x65);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, ov80_0222ACA0(mode, 7), m->bgConfig, 3, 0, 0, 1, 0x65);
    if (w == 0) {
        PaletteData_LoadNarc(m->plttData, narcId, ov80_0222ACA0(mode, 8), 0x65, 0, 0x160, 0);
    } else {
        raw = GfGfxLoader_GetPlttDataFromOpenNarc(narc, ov80_0222ACA0(mode, 8), &plttA, 0x65);
        DC_FlushRange(plttA->pRawData, plttA->szByte);
        GX_BeginLoadBGExtPltt();
        GX_LoadBGExtPltt(plttA->pRawData, 0x6000, 0x2000);
        GX_EndLoadBGExtPltt();
        Heap_Free(raw);
    }
    PaletteData_FillPaletteInBuffer(m->plttData, 0, 2, 0, 0, 1);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, ov80_0222ACA0(mode, 6), m->bgConfig, 3, 0, 0, 1, 0x65);
    if (ov80_0222ACA0(mode, 9) != 0xFFFF) {
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, ov80_0222ACA0(mode, 10), m->bgConfig, 2, 0, 0, 1, 0x65);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, ov80_0222ACA0(mode, 9), m->bgConfig, 2, 0, 0, 1, 0x65);
        if (w != 0) {
            void *raw2 = GfGfxLoader_GetPlttDataFromOpenNarc(narc, ov80_0222ACA0(mode, 11), &plttB, 0x65);
            DC_FlushRange(plttB->pRawData, plttB->szByte);
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(plttB->pRawData, 0x4000, 0x4000 / 2);
            GX_EndLoadBGExtPltt();
            Heap_Free(raw2);
        }
    }
    ScheduleBgTilemapBufferTransfer(m->bgConfig, 3);
    NARC_Delete(narc);
}
