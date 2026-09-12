#include "overlay96_course_scene_r35_private.h"

u32 ov96_021EBA98(void *course, u8 *state) {
    switch (*state) {
    case 0:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)0, (enum FadeType)0, 0x7FFF, 0x5A, 1, (enum HeapID)PokeathlonCourse_GetHeapID(course));
        GF_SndStartFadeOutBGM(0, 0x5A);
        PlaySE(0x8DD);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            return 1;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_021EBAFC(void *course, u8 *state) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        if (!ov96_021E5F24(course)) {
            ov96_021EDA58(course);
        }
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)3, (enum FadeType)3, 0, 6, 1, (enum HeapID) * (u32 *)work);
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
