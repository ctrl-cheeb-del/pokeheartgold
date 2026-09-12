#include "overlay96_course_results_r62_private.h"

void ov96_021F7DA8(void *work) {
    GfGfxLoader_LoadCharData(0xa0, 3, PTR(work, 0xc), 4, 0, 0, 0, *(u32 *)work);
    GfGfxLoader_LoadScrnData(0xa0, 5, PTR(work, 0xc), 4, 0, 0, 0, *(u32 *)work);
    GfGfxLoader_LoadCharData(0xa0, 3, PTR(work, 0xc), 5, 0, 0, 0, *(u32 *)work);
    GfGfxLoader_LoadScrnData(0xa0, 4, PTR(work, 0xc), 5, 0, 0, 0, *(u32 *)work);
    GfGfxLoader_GXLoadPal(0xa0, 0, 4, 0, 0, *(u32 *)work);
    GfGfxLoader_LoadCharData(0xa0, 2, PTR(work, 0xc), 0, 0, 0, 0, *(u32 *)work);
    GfGfxLoader_LoadScrnData(0xa0, 1, PTR(work, 0xc), 0, 0, 0, 0, *(u32 *)work);
    GfGfxLoader_GXLoadPal(0xa0, 0, 0, 0, 0, *(u32 *)work);
}

int ov96_021F7E64(void *course) {
    return U8(ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0xf0), 2);
}
