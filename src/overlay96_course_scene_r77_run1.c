#include "overlay96_course_scene_r77_private.h"

int ov96_021FCE10(void *course) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    sub_0203A914();
    PokeathlonCourse_ResetField3A4(course);
    FreeBgTilemapBuffer(PTR(p, 0), 0);
    FreeBgTilemapBuffer(PTR(p, 0), 1);
    FreeBgTilemapBuffer(PTR(p, 0), 2);
    FreeBgTilemapBuffer(PTR(p, 0), 3);
    FreeBgTilemapBuffer(PTR(p, 0), 4);
    FreeBgTilemapBuffer(PTR(p, 0), 5);
    FreeBgTilemapBuffer(PTR(p, 0), 6);
    RemoveWindow(p + 4);
    Heap_Free(PTR(p, 0));
    ov96_021EB21C(PTR(p, 0x18));
    ov96_021EA894(PTR(p, 0x3c8));
    ov96_021E9C0C(PTR(p, 0x3c4));
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    ov96_02200EEC(PTR(p, 0x3dc));
    ov96_021FFFE8(PTR(p, 0x3e0));
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    *(volatile u16 *)0x04000050 = 0;
    Heap_Destroy(0x90);
    return 1;
}

void ov96_021FCEE0(void) {
    GfxBanks40 banks = ov96_0221C6F0;
    GfGfx_SetBanks(&banks);
}
