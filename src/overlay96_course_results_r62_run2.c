#include "overlay96_course_results_r62_private.h"

int ov96_021F7C4C(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EB5BC(PTR(work, 0x10));
    SpriteSystem_DrawSprites(PTR(work, 0x98));
    ov96_021F87D0(PTR(work, 0x1c));
    return 1;
}

int ov96_021F7C70(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    int i;

    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    FontID_Release(4);
    G2x_SetBlendBrightness_((volatile u16 *)0x04000050, 0x3f, 0);
    ov96_021EE5E0(PTR(work, 0x80));
    RemoveWindow((u8 *)work + 0x84);
    ov96_021EE808(PTR(work, 0x18));
    for (i = 0; i < 6; i++) {
        FreeBgTilemapBuffer(PTR(work, 0xc), ov96_0221C290[i]);
    }
    ov96_021F8F0C(PTR(work, 0x14));
    ov96_021F8728(PTR(work, 0x1c));
    ov96_021EB21C(PTR(work, 0x10));
    ov96_021F84E4(work);
    Heap_Free(PTR(work, 0xc));
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    U8(gSystem, 0x69) = 0;
    GfGfx_SwapDisplay();
    Heap_Destroy(0x89);
    sub_0203A914();
    return 1;
}

void ov96_021F7D10(void) {
    struct Ov96Banks banks = ov96_0221C310;
    GfGfx_SetBanks(&banks);
}
