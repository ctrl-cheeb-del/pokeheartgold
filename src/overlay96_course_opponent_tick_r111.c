#include "overlay96_course_opponent_logic_r111_private.h"

void ov96_02214B84(void *course, u8 *work) {
    u32 *entry;

    if (work[0x9E] == 4) {
        return;
    }
    work[0x9A]++;
    if (work[0x9A] >= work[0x9B]) {
        *(u32 *)(work + 0x94) = 1;
        work[0x9A] = 0;
    }
    if (*(u32 *)(work + 0x94) == 0) {
        return;
    }
    entry = (u32 *)(work + (work[0x9D] + work[0x99]) * 0x24 + work[0x9C] * 8);
    if (entry[0] == 0) {
        ov96_022155A0(course, work, (void **)entry);
    } else {
        entry[0]--;
    }
    work[0x99]++;
    if (work[0x99] >= work[0x98]) {
        work[0x99] = 0;
        work[0x9C] = (work[0x9C] + 1) % 3;
        *(u32 *)(work + 0x94) = 0;
    }
}
