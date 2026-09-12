#include "overlay96_course_scene_internal.h"

BOOL ov96_022090A8(Ov96CourseSceneRect *rect, s32 x, s32 y) {
    s32 left = rect->unk8 - 16;
    s32 right = rect->unk8 + 16;
    s32 top = rect->unkC - 16;
    s32 bottom = rect->unkC + 16;

    if (left <= x && x < right && top <= y && y < bottom) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov96_022090D8(Ov96CourseSceneRect *rect) {
    s32 y = rect->unkC;
    BOOL lower;
    BOOL upper;

    if (y < 104) {
        return FALSE;
    }
    if (y <= 392) {
        lower = rect->unk8 >= 144;
        upper = rect->unk8 <= 368;
        if (lower & upper) {
            return TRUE;
        }
    } else {
        lower = rect->unk8 >= 208;
        upper = rect->unk8 <= 304;
        if (lower & upper) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov96_02209130(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        ov96_0220A840(OV96_R92_PTR_AT(work, 0x40));
        if (ov96_0220AD34(OV96_R92_PTR_AT(work, 0x40)) == 2) {
            Ov96CourseScenePair pair;
            void *sprites;
            pair = ov96_0221CC00;
            sprites = SpriteManager_GetSpriteList(OV96_R92_PTR_AT(work, 0xC));
            ov96_021E62AC(course, 0, OV96_R92_PTR_AT(work, 0x14), sprites, 1, 1, &pair);
            (*state)++;
        }
        break;
    case 1:
        if (ov96_021E637C(course)) {
            ov96_021EB144(OV96_R92_PTR_AT(work, 0x10), 0);
            PokeathlonCourse_SetStateField07(course, 1);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}
