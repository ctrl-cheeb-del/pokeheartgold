#include "overlay96_pokeathlon_shop_ui_private.h"

u32 ov96_021F08F4(void *course) {
    void *gfx;
    int i;
    PokeathlonCourse_GetHeapAllocPtr4(course);
    gfx = PokeathlonCourse_GetGraphicsSystem(course);
    ov96_021E9510(gfx);
    for (i = 0; i < 4; i++) {
        ov96_021E95F8(course, gfx, i, PokeathlonCourse_GetField5F0_AtIndex(course, (u8)i), 0, 3, 0x125);
    }
    ov96_021E93B4(gfx, 1);
    ov96_0221A56C(gfx, 2);
    ov96_021E952C(gfx);
    ov96_021E9570(gfx, 2);
    return 1;
}
