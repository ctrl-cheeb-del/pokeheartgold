#include "overlay96_course_scene_r86_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

int ov96_02204DF8(void *course) {
    void *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    ov96_021E9510(gfx);
    for (i = 0; i < 4; i++) {
        ov96_021E95F8(course, gfx, i, PokeathlonCourse_GetField5F0_AtIndex(course, (u8)i), 0, 3, 0x124);
    }
    ov96_021E93B4(gfx, 1);
    ov96_0221A56C(gfx, 1);
    ov96_021E952C(gfx);
    ov96_021E9570(gfx, 1);
    return 1;
}

int ov96_02204E58(void *course) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    sub_0203A914();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_ResetField3A4(course);
    Heap_Free(PTR(p, 0x18));
    FreeBgTilemapBuffer(PTR(p, 0), 0);
    FreeBgTilemapBuffer(PTR(p, 0), 3);
    FreeBgTilemapBuffer(PTR(p, 0), 4);
    FreeBgTilemapBuffer(PTR(p, 0), 5);
    FreeBgTilemapBuffer(PTR(p, 0), 6);
    RemoveWindow(p + 4);
    Heap_Free(PTR(p, 0));
    ov96_021EB21C(PTR(p, 0x20));
    ov96_021EA894(PTR(p, 0x348));
    ov96_021E9C0C(PTR(p, 0x344));
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    ov96_02208B2C(PTR(p, 0x36C));
    ov96_02207D64(PTR(p, 0x370));
    FontID_Release(4);
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    *(volatile u16 *)0x04000050 = 0;
    Heap_Destroy(0x8B);
    return 1;
}

void ov96_02204F20(void) {
    GfxBanks40 banks = ov96_0221CB9C;
    GfGfx_SetBanks(&banks);
}
