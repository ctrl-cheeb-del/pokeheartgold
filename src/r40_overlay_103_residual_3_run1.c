#include "global.h"

#include "r40_overlay_103_residual_3_private.h"

void ov103_021ECC1C(R40Ov103Work3 *work) {
    NARC *narc = NARC_New(NARC_a_2_5_0, HEAP_ID_157);
    NNSG2dCharacterData *charData;
    void *resource;
    u8 *raw;
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 5, *(BgConfig **)work->ctx, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_157);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 4, *(BgConfig **)work->ctx, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_157);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 6, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_157);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, *(BgConfig **)work->ctx, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_157);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, *(BgConfig **)work->ctx, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_157);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0, *(BgConfig **)work->ctx, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_157);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 2, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_157);
    resource = GfGfxLoader_GetCharDataFromOpenNarc(narc, 1, TRUE, &charData, HEAP_ID_157);
    raw = charData->pRawData;
    MI_CpuCopy32(raw + 0xE0, work->ctx + 8, 0x20);
    MI_CpuCopy32(raw + 0x160, work->ctx + 0x28, 0x20);
    Heap_Free(resource);
    NARC_Delete(narc);
}
