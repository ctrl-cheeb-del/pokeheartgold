#include "overlay96_course_scene_r35_private.h"

void ov96_021EB6A8(void) {
    GraphicsBanks banks = ov96_0221B030;

    GfGfx_SetBanks(&banks);
}

u32 ov96_021EB6C8(void *course, u8 *state) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        if (!ov96_021E5F24(course)) {
            ov96_021ED8DC(course);
        }
        BeginNormalPaletteFade((enum FadeMode)4, (enum FadeType)3, (enum FadeType)3, 0, 6, 1, (enum HeapID) * (u32 *)work);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}
