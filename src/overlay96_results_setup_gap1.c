#include "global.h"

#include "pokeathlon/pokeathlon.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "poke_overlay.h"
#include "system.h"

typedef struct Ov96ResultsWork {
    PokeathlonCourseData *course;
    BgConfig *bgConfig;
    NARC *narc;
    enum HeapID heapId;
    void *spriteSystem;
    void *spriteManager;
    u32 screenMode;
    s32 animCounter;
    u8 selection;
    u8 animIndex;
    u8 participant;
    u8 padding_23;
    u32 mode;
    u32 showRecord;
    u32 flag2C;
    void *message;
    void *unk34;
    void *sprites[4];
} Ov96ResultsWork;

typedef struct Ov96BgTemplates {
    BgTemplate templates[7];
} Ov96BgTemplates;

extern const GraphicsModes ov96_0221BA44;
extern const u8 ov96_0221BA10[];
extern const u8 ov96_0221BA18[];
extern const Ov96BgTemplates ov96_0221BB98;
extern const u8 ov96_0221BB38[];
extern char SDK_OVERLAY_OVY_98_ID;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void ov96_021EF260(void);
extern u8 ov96_021EF2A0(PokeathlonCourseData *course);
extern BOOL ov96_021EF2AC(PokeathlonCourseData *course);
extern void ov96_021EF23C(void *arg);
extern void ov96_021EE644(void *arg);
extern void ov96_021EF610(Ov96ResultsWork *work);
extern void *ov98_0221EABC(enum HeapID heapId, BgConfig *bgConfig, int count, const void *templates, int arg);
extern void sub_0200FC20(u16 color);

void ov96_021EF2C0(PokeathlonCourseData *course);
void ov96_021EF3A8(Ov96ResultsWork *work);
void ov96_021EF430(Ov96ResultsWork *work, int selection);
void ov96_021EF4D0(BgConfig *bgConfig, enum HeapID heapId);
void ov96_021EF54C(Ov96ResultsWork *work);

void ov96_021EF3A8(Ov96ResultsWork *work) {
    LoadFontPal0((enum GFPalLoadLocation)6, (enum GFPalSlotOffset)0x4000, work->heapId);
    ov96_021EE644(work->unk34);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 4, (enum GFPalLoadLocation)4, GF_PAL_SLOT_0_OFFSET, 0, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 5, work->bgConfig, (GFBgLayer)4, 0, 0, TRUE, work->heapId);
    if (work->showRecord != 0) {
        GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 10, work->bgConfig, (GFBgLayer)4, 0, 0, TRUE, work->heapId);
    } else {
        GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 9, work->bgConfig, (GFBgLayer)4, 0, 0, TRUE, work->heapId);
    }
}

void ov96_021EF430(Ov96ResultsWork *work, int selection) {
    MtxFx22 matrix;

    GF_ASSERT(selection < 10);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, selection + 32, (enum GFPalLoadLocation)6, (enum GFPalSlotOffset)0x6000, 0, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, selection + 42, work->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, selection + 52, work->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, work->heapId);
    BG_SetMaskColor((GFBgLayer)4, 0);
    matrix._00 = FX32_ONE;
    matrix._01 = 0;
    matrix._10 = 0;
    matrix._11 = FX32_ONE;
    OS_WaitVBlankIntr();
    SetBgAffine(work->bgConfig, GF_BG_LYR_SUB_3, &matrix, 0, 0);
    Bg_SetTextDimAndAffineParams(work->bgConfig, GF_BG_LYR_SUB_3, BG_POS_OP_SET_Y, 0, &matrix, 0, 0);
}

void ov96_021EF4D0(BgConfig *bgConfig, enum HeapID heapId) {
    Ov96BgTemplates templates;
    GraphicsModes modes;
    int i;

    modes = ov96_0221BA44;
    SetBothScreensModesAndDisable(&modes);
    templates = ov96_0221BB98;
    for (i = 0; i < 7; i++) {
        InitBgFromTemplate(bgConfig, ov96_0221BA18[i], &templates.templates[i], ov96_0221BA10[i]);
        BgClearTilemapBufferAndCommit(bgConfig, ov96_0221BA18[i]);
        BG_ClearCharDataRange(ov96_0221BA18[i], 0x40, 0, heapId);
    }
}

void ov96_021EF54C(Ov96ResultsWork *work) {
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 4, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 5, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 6, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, work->heapId);
    if (work->mode == 0) {
        GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 5, work->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, work->heapId);
        GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 8, work->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, work->heapId);
    }
    ov96_021EF3A8(work);
    work->message = ov98_0221EABC(work->heapId, work->bgConfig, 12, ov96_0221BB38, 0x135);
    ov96_021EF610(work);
}
