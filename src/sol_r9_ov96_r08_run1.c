#include "sol_r9_ov96_r08_private.h"

void ov96_0221663C(SolR9Ov96R08Graphics *work) {
    GfGfxLoader_LoadCharData(0xF2, 1, work->bgConfig, 0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(0xF2, 3, work->bgConfig, 1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(0xF2, 5, work->bgConfig, 2, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(0xF2, 2, work->bgConfig, 0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(0xF2, 4, work->bgConfig, 1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(0xF2, 6, work->bgConfig, 2, 0, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPal(0xF2, 0, 0, 0, 0, work->heapId);
    LoadFontPal0(0, 0x1E0, work->heapId);
    GfGfxLoader_LoadCharData(0xF2, 9, work->bgConfig, 6, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(0xF2, 11, work->bgConfig, 4, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(0xF2, 12, work->bgConfig, 4, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(0xF2, 10, work->bgConfig, 6, 0, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPal(0xF2, 8, 4, 0, 0, work->heapId);
}
