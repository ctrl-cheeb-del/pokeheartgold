#include "overlay96_pokeathlon_shop_ui_private.h"

void ov96_021F0A5C(void) {
    GraphicsBanks banks = ov96_0221BDAC;
    GfGfx_SetBanks(&banks);
}

u32 ov96_021F0A7C(void *course, u8 *state) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        PokeathlonCourse_SetStateTransitionType(course, 0x15);
        (*state)++;
        break;
    case 1:
        BeginNormalPaletteFade(2, 3, 3, 0, 6, 1, (u32)PTR(w, 0x14));
        (*state)++;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    }
    return 0;
}
