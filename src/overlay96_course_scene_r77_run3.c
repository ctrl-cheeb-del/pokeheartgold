#include "overlay96_course_scene_r77_private.h"

int ov96_021FD3EC(void *course, u8 *state) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        if (ov96_021E637C(course)) {
            (*state)++;
        }
        break;
    case 1:
        ov96_021FD4D0(course);
        if (ov96_021FDB64(course)) {
            (*state)++;
        }
        break;
    case 2:
        ov96_021FD4D0(course);
        if (ov96_021E667C(course)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, PTR(p, 0x14));
            PokeathlonCourse_SetStateField07(course, 2);
        }
        break;
    }
    return 0;
}
