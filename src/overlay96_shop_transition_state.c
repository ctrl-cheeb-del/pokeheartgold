#include "overlay96_shop_transition_private.h"

u32 ov96_021F0AE0(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        if (ov96_021E637C(course)) {
            (*state)++;
        }
        break;
    case 1:
        ov96_021F1170(course);
        if (ov96_021F107C(course)) {
            (*state)++;
        }
        break;
    case 2:
        if (ov96_021E667C(course)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, *(u32 *)((u8 *)work + 0x14));
            PokeathlonCourse_SetStateField07(course, 2);
        }
        break;
    }
    return 0;
}
