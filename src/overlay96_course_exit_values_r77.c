#include "global.h"

void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
BOOL IsPaletteFadeFinished(void);
BOOL ov96_021E5F24(void *course);
void PokeathlonCourse_SetField5E0_AtIndex(void *course, u8 index, u16 value);

int ov96_021FD46C(void *course, u8 *state);

int ov96_021FD46C(void *course, u8 *state) {
    int i;
    void *savedCourse = course;
    u8 *item = PokeathlonCourse_GetHeapAllocPtr4(course);

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return 0;
    }
    if (ov96_021E5F24(savedCourse)) {
        return 1;
    }
    for (i = 0, item += 0x30; i < 4; i++, item += 0xd4) {
        PokeathlonCourse_SetField5E0_AtIndex(
            savedCourse, (u8)i, (u16)(*(s32 *)(item + 0x7c) / 4096 + (item[0x9c] << 10)));
    }
    return 1;
}
