#include "overlay96_course_event_r70_private.h"

int ov96_021F9240(void *course, u8 *state) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        if (ov96_021E637C(course)) {
            work[0x3C7] = 1;
            (*state)++;
        }
        break;
    case 1: {
        BOOL ok;
        u8 i;
        u32 total;
        ov96_021FBDBC(work);
        ok = ov96_021FA6D0(course, work);
        ov96_021FB630(course);
        if (ok) {
            total = 0;
            for (i = 0; i < 3; i++) {
                total += *(u16 *)(work + i * 0x6C + 0xE2);
            }
            ov96_021E8318(course, (u16)total);
            ov96_021FB808(work, total);
            (*state)++;
        }
        break;
    }
    case 2: {
        u8 ready = ov96_021E667C(course);
        if (ov96_021FB60C(work) && ready) {
            (*state)++;
        }
        ov96_021FBDBC(work);
        ov96_021FA6D0(course, work);
        ov96_021FB630(course);
        break;
    }
    case 3: {
        void *p;
        ov96_021FBDBC(work);
        ov96_021FB630(course);
        p = ov96_021E8A20(PokeathlonCourse_GetDataCopyArea(course));
        ((u8 *)p)[9] = 1;
        p = ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0xF0);
        if (*(u32 *)p != 0) {
            (*state)++;
            *(u32 *)(work + 0x234) = 0;
        }
        break;
    }
    case 4:
        if (++*(u32 *)(work + 0x234) > 90) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, *(u32 *)work);
            PokeathlonCourse_SetStateField07(course, 2);
        }
        break;
    }
    ov96_021FAF1C(course);
    return 0;
}
