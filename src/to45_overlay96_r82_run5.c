#include "to45_overlay96_r82_private.h"

u32 ov96_02202154(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        if (ov96_021E637C(course)) {
            (*state)++;
        }
        break;
    case 1:
        ov96_0220223C(course);
        if (ov96_022028BC(course)) {
            (*state)++;
        }
        break;
    case 2:
        ov96_0220223C(course);
        if (ov96_021E667C(course)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32_AT(work, 0x44));
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    }
    return 0;
}

u32 ov96_022021D4(void *course, u8 *state) {
    u8 *copy = PokeathlonCourse_GetDataCopyArea(course);
    u16 *values;
    int i;
    PokeathlonCourse_GetHeapAllocPtr4(course);
    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return 0;
    }
    if (ov96_021E5F24(course)) {
        return 1;
    }
    values = ov96_021E8A20(copy + 0x28);
    for (i = 0; i < 4; i++) {
        PokeathlonCourse_SetField5E0_AtIndex(course, (u8)i, values[i] & 0x3ff);
    }
    return 1;
}
