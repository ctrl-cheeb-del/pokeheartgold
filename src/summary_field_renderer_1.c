#include "summary_field_renderer_internal.h"

void sub_020887C4(SummaryGraphicsWork *work, int unused, NARC *narc) {
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x200, HEAP_ID_19);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, work->bgConfig, GF_BG_LYR_MAIN_3, 0, 0x4400, FALSE, HEAP_ID_19);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 13, work->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, HEAP_ID_19);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x200, HEAP_ID_19);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0x4400, FALSE, HEAP_ID_19);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 20, work->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_19);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 21, work->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_19);
}
