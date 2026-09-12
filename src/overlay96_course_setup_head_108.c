#include "overlay96_course_setup_108_private.h"
int ov96_02211660(void *course) {
    void *gfx;
    int i;

    PokeathlonCourse_GetHeapAllocPtr4(course);
    gfx = PokeathlonCourse_GetGraphicsSystem(course);
    ov96_021E9510(gfx);
    for (i = 0; i < 4; i++) {
        ov96_021E95F8(course, gfx, i, PokeathlonCourse_GetField5F0_AtIndex(course, (u8)i), 0, 3, 300);
    }
    ov96_021E93B4(gfx, 1);
    ov96_0221A56C(gfx, 9);
    ov96_021E952C(gfx);
    ov96_021E9570(gfx, 9);
    return 1;
}

int ov96_022116C8(void *course) {
    u8 *alloc = PokeathlonCourse_GetHeapAllocPtr4(course);
    u8 *window;
    int i;

    sub_0203A914();
    ov96_021E6550(course);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 0);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 1);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 2);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 3);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 4);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 5);
    FreeBgTilemapBuffer(*(void **)(alloc + 4), 6);
    ov96_02214234(alloc);
    ov96_022141B0(course);
    RemoveWindow(alloc + 8);
    window = alloc;
    i = 0;
    window += 0x18;
    while (i < 4) {
        RemoveWindow(window);
        i++;
        window += 0x10;
    }
    Heap_Free(*(void **)(alloc + 4));
    ov96_021EB21C(*(void **)(alloc + 0));
    ov96_021EA894(*(void **)(alloc + 0x748));
    ov96_021E9C0C(*(void **)(alloc + 0x744));
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    ov96_02214B7C(*(void **)(alloc + 0x74C));
    ov96_02214690(*(void **)(alloc + 0x750));
    FontID_Release(4);
    Main_SetVBlankIntrCB(0, 0);
    Main_SetHBlankIntrCB(0, 0);
    Heap_Free(*(void **)(alloc + 0x81C));
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    *(u16 *)0x04000050 = 0;
    Heap_Destroy(0x93);
    return 1;
}

void ov96_022117CC(void) {
    GfxBanks40 banks = ov96_0221D380;
    GfGfx_SetBanks(&banks);
}

int ov96_022117EC(void *course, u8 *state) {
    u8 *alloc = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        if (ov96_021E637C(course)) {
            (*state)++;
        }
        break;
    case 1:
        ov96_02211B94(course);
        if (ov96_02211AF0(course)) {
            (*state)++;
        }
        break;
    case 2:
        ov96_02211B94(course);
        ov96_0221236C(course);
        if (ov96_021E667C(course)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, *(void **)(alloc + 0x58));
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    }
    return 0;
}

int ov96_02211870(void *course, u8 *state) {
    int i;
    void *savedCourse = course;
    u8 *alloc = PokeathlonCourse_GetHeapAllocPtr4(course);

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return 0;
    }
    if (ov96_021E5F24(savedCourse)) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        PokeathlonCourse_SetField5E0_AtIndex(savedCourse, (u8)i, (u16) * (u32 *)(alloc + 0x6F4));
        alloc += 4;
    }
    return 1;
}
