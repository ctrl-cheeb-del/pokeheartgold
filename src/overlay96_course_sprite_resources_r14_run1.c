#include "global.h"

#include "overlay96_course_sprite_resources_r14_private.h"

void ov96_02203CE4(void *p) {
    int offset;

    if (U8_AT(p, 0x70) != 0) {
        U8_AT(p, 0x71)
        ++;
        offset = -((U8_AT(p, 0x71) % 2) << 3);
        if (U8_AT(p, 0x71) >= 10) {
            U8_AT(p, 0x70) = 0;
            U8_AT(p, 0x71) = 0;
            offset = 0;
        }
        ScheduleSetBgPosText(PTR_AT(p, 8), 4, BG_POS_OP_SET_Y, offset);
        ScheduleSetBgPosText(PTR_AT(p, 8), 5, BG_POS_OP_SET_Y, offset);
        ScheduleSetBgPosText(PTR_AT(p, 8), 6, BG_POS_OP_SET_Y, offset);
    } else {
        ScheduleSetBgPosText(PTR_AT(p, 8), 4, BG_POS_OP_SET_Y, 0);
        ScheduleSetBgPosText(PTR_AT(p, 8), 5, BG_POS_OP_SET_Y, 0);
        ScheduleSetBgPosText(PTR_AT(p, 8), 6, BG_POS_OP_SET_Y, 0);
    }
}
