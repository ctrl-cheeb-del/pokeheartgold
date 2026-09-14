#include "to45_overlay96_r82_private.h"

u32 ov96_02201B18(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_02203CE4(PTR_AT(work, 0x5e0));
    ov96_021EB5BC(PTR_AT(work, 0x48));
    return 1;
}

u32 ov96_02201B34(void *course) {
    void *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    ov96_021E9510(gfx);
    for (i = 0; i < 4; i++) {
        ov96_021E95F8(course, gfx, i, PokeathlonCourse_GetField5F0_AtIndex(course, (u8)i), 0, 3, 0x12b);
    }
    ov96_021E93B4(gfx, 1);
    ov96_0221A56C(gfx, 8);
    ov96_021E952C(gfx);
    ov96_021E9570(gfx, 8);
    return 1;
}
