#include "overlay96_course_event_r70_private.h"

extern BOOL IsPaletteFadeFinished(void);
extern int ov96_021F9380(void *, u8 *);

int ov96_021F9380(void *course, u8 *state) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    float q;
    int j;
    int k;
    int count;
    int sum;
    int leader;
    int i;
    int total;
    u8 *q2;

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return 0;
    }
    leader = ov96_021E5F24(course);
    total = 0;
    for (i = 0, q2 = work; i < 3; i++, q2 += 0x6C) {
        total += *(u16 *)(q2 + 0xE2);
    }
    PokeathlonCourse_SetField5E0_AtIndex(course, (u8)leader, (u16)ov96_021FBDEC(total));
    if (leader == 0) {
        count = PokeathlonCourse_GetParticipantCount(course);
        for (j = count; j < 4; j++) {
            sum = 0;
            for (k = 0; k < 3; k++) {
                float f;
                int n;
                u8 *e = work + ((j - count) * 3 + k) * 0x28;
                if (*(u32 *)(e + 0x250) == 0) {
                    f = *(float *)(e + 0x240);
                    if (f < *(float *)(e + 0x248)) {
                        f = *(float *)(e + 0x248);
                    }
                    q = (float)(0x1000 - *(int *)(e + 0x258)) / f;
                    n = (int)q;
                    if (q - (float)n > 0.0f) {
                        n++;
                    }
                    *(u32 *)(e + 0x254) = *(u32 *)(work + 0x230) + n;
                }
                sum += *(u32 *)(e + 0x254);
            }
            PokeathlonCourse_SetField5E0_AtIndex(course, (u8)j, (u16)ov96_021FBDEC(sum));
        }
    }
    return 1;
}
