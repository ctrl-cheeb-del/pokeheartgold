#include "overlay96_course_bg_r36_private.h"

void ov96_021EC3D8(void *bgConfig, u32 heapId) {
    GfGfxLoader_LoadCharData(0x9a, 3, bgConfig, 0, 0, 0, 0, heapId);
    GfGfxLoader_LoadCharData(0x9a, 1, bgConfig, 5, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(0x9a, 6, bgConfig, 0, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(0x9a, 4, bgConfig, 5, 0, 0, 0, heapId);
    GfGfxLoader_GXLoadPal(0x9a, 0, 0, 0, 0, heapId);
    GfGfxLoader_GXLoadPal(0x9a, 0, 4, 0, 0, heapId);
}

void ov96_021EC458(void *bgConfig, u32 heapId) {
    GfGfxLoader_LoadCharData(0x9a, 3, bgConfig, 1, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(0x9a, 7, bgConfig, 1, 0, 0, 0, heapId);
}
