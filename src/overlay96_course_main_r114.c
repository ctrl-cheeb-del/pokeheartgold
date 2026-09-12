#include "overlay96_course_main_r114_private.h"

typedef union R114Bits {
    u32 raw;
    struct {
        u32 value : 12;
        u32 pad : 20;
    } bits;
} R114Bits;

void ov96_02215958(s32 *xy, s32 limit) {
    s32 neg = -limit;
    if (xy[0] > 0) {
        if (xy[0] > limit) {
            xy[0] = limit;
        }
    } else if (xy[0] < neg) {
        xy[0] = neg;
    }
    if (xy[1] > 0) {
        if (xy[1] > limit) {
            xy[1] = limit;
        }
    } else if (xy[1] < neg) {
        xy[1] = neg;
    }
}

u32 ov96_02215984(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0x7fff, 6, 1, U32_AT(work, 0));
        (*state)++;
    case 1:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case 2:
        if (ov96_021E637C(course)) {
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_022159F0(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        ov96_02215FC8(course);
        if (ov96_02216234(course)) {
            (*state)++;
        }
        break;
    case 1:
        ov96_02215FC8(course);
        if (ov96_021E667C(course) && ov96_02215864((u8 *)work + 0x7f8)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32_AT(work, 0));
            PokeathlonCourse_SetStateField07(course, 2);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_02215A70(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            if (!ov96_021E5F24(course)) {
                int i;
                R114Bits *p;
                for (i = 0, p = (R114Bits *)((u8 *)work + 0x204); i < 4; i++, p = (R114Bits *)((u8 *)p + 0xa8)) {
                    PokeathlonCourse_SetField5E0_AtIndex(course, (u8)i, (u16)p->bits.value);
                }
            }
            return 1;
        }
    } else {
        GF_AssertFail();
    }
    return 0;
}

u32 ov96_02215AC4(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (PokeathlonCourse_GetField1ED(course)) {
    case 0:
        Heap_Create(0x5c, 0x91, 0x60000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(u32 *)0x04000000 &= 0xffffe0ff;
        *(u32 *)0x04001000 &= 0xffffe0ff;
        ov96_02215FA8();
        gSystem[0x69] = 1;
        GfGfx_SwapDisplay();
        work = PokeathlonCourse_AllocPtr4FromHeap(course, 0x814);
        MI_CpuFill8(work, 0, 0x814);
        U32_AT(work, 0) = 0x91;
        U32_AT(work, 0x438) = 0x708;
        PokeathlonCourse_IncrementField1ED(course);
        break;
    case 1:
        PTR_AT(work, 4) = BgConfig_Alloc(U32_AT(work, 0));
        ov96_021E6670(course, 8);
        ov96_0221654C(work);
        ov96_0221663C(work);
        ov96_022193E4(work);
        ov96_022162F4(work);
        ov96_02217AE4(work, course);
        PokeathlonCourse_IncrementField1ED(course);
        break;
    case 2:
        if (ov96_021EAA00(PTR_AT(work, 0x1c))) {
            ov96_022163AC(work);
            Sprite_SetDrawPriority(*ov96_021E61D8(course, 0, PTR_AT(work, 0x18), SpriteManager_GetSpriteList(PTR_AT(work, 0xc))), 0);
            PokeathlonCourse_IncrementField1ED(course);
        }
        break;
    case 3: {
        u8 flag = (u8)ov96_021E5F24(course);
        PTR_AT(work, 0x184) = ov96_02219F7C(course, U32_AT(work, 0));
        PTR_AT(work, 0x180) = ov96_022194C4(PTR_AT(work, 8), PTR_AT(work, 0xc), PTR_AT(work, 0x18), PTR_AT(work, 4), PTR_AT(work, 0x14), PTR_AT(work, 0x10), flag, PTR_AT(work, 0), course);
        PokeathlonCourse_IncrementField1ED(course);
        break;
    }
    case 4:
        ov96_02217B84(work, course);
        ov96_022195C8(PTR_AT(work, 0x180));
        ov96_02217544((u8 *)work + 0x43c, PTR_AT(work, 8), PTR_AT(work, 0xc), PTR_AT(work, 0x180), PTR_AT(work, 0x1c), PTR_AT(work, 0));
        PokeathlonCourse_SetVBlankIntrCB(PTR_AT(work, 4));
        ov96_0221587C((u8 *)work + 0x7f8, PTR_AT(work, 4), PTR_AT(work, 8));
        PokeathlonCourse_SetField1F4(course, 1);
        if (ov96_021E5F24(course) == 0) {
            void *p = ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0x28);
            U32_AT(p, 0x20) = (0xfff80007 & U32_AT(p, 0x20)) | ((u16)U32_AT(work, 0x438) << 3);
            ov96_02218330((u8 *)work + 0x188, course);
        }
        sub_0203A994(2);
        GfGfx_EngineATogglePlanes(0x10, 1);
        GfGfx_EngineBTogglePlanes(0x10, 1);
        return 1;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_02215CD0(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    if (work == NULL) {
        GF_AssertFail();
    }
    SpriteSystem_DrawSprites(PTR_AT(work, 0xc));
    return 1;
}

u32 ov96_02215CE8(void *course) {
    void *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    ov96_021E9510(gfx);
    for (i = 0; i < 4; i++) {
        ov96_021E95F8(course, gfx, i, PokeathlonCourse_GetField5F0_AtIndex(course, (u8)i), 0, 3, 0x12a);
    }
    ov96_021E93B4(gfx, 1);
    ov96_0221A56C(gfx, 7);
    ov96_021E952C(gfx);
    ov96_021E9570(gfx, 7);
    return 1;
}

u32 ov96_02215D4C(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_02219FDC(PTR_AT(work, 0x184));
    ov96_022195E8(PTR_AT(work, 0x180));
    ov96_022177D8((u8 *)work + 0x43c);
    ov96_02217DBC(work);
    ov96_02216390(work);
    ov96_022165FC(work);
    sub_0203A914();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    Heap_Destroy(0x91);
    return 1;
}
