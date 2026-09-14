#include "to45_overlay96_r59b_private.h"

u32 ov96_021F5650(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        ov96_021F5B60(course);
        PokeathlonCourse_SetStateTransitionType(course, 0x14);
        (*state)++;
        break;
    case 1:
        ov96_021F5B60(course);
        BeginNormalPaletteFade(2, 3, 3, 0, 6, 1, U32_AT(work, 0x54));
        (*state)++;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        ov96_021F5B60(course);
        break;
    case 3:
        ov96_021F5B60(course);
        if (ov96_021E637C(course)) {
            (*state)++;
        }
        break;
    case 4:
        ov96_021F5BA0(course);
        if (ov96_021F5A88(course)) {
            (*state)++;
        }
        break;
    case 5:
        if (ov96_021E667C(course)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32_AT(work, 0x54));
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    }
    return 0;
}
