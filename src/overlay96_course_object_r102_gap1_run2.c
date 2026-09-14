#include "overlay96_course_object_r102_gap1_run2_private.h"

void ov96_0220F8C8(Ov96ObjectGroup *groups, void *course) {
    int row;
    ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0x28);
    for (row = 0; row < 4; row++, groups++) {
        Ov96Object *object;
        int i;
        {
            Ov96ClearEntry *clear = (Ov96ClearEntry *)((u8 *)groups + 0x48);
            u32 group = groups->flags.bits.group;
            clear[group].flags &= ~0x08000000;
        }
        if (groups->flags.bits.flag14) {
            u8 direction = ov96_0220DAA0(groups->objects, groups->x, groups->y);
            if (direction != 12) {
                groups->flags.bits.flag29 = 1;
                groups->flags.bits.group = direction;
            }
        } else if (groups->flags.bits.flag15) {
            if (groups->flags.bits.flag29 == 1) {
                object = &groups->objects[groups->flags.bits.group];
                {
                    s16 objectX = object->previous.x >> 12;
                    s16 objectY = object->previous.y >> 12;
                    if (object->state == 3) {
                        groups->flags.bits.flag29 = 0;
                    } else if ((groups->x - objectX < 0 ? -(groups->x - objectX) : groups->x - objectX) > 8 || (groups->y - objectY < 0 ? -(groups->y - objectY) : groups->y - objectY) > 8) {
                        ov96_0220D6B0(object, (s16 *)groups);
                        object->flags = (object->flags & 0xDFFFFFFF) | (((u32)ov96_0220D8C4(object, object->position.x, object->position.y) << 31) >> 2);
                    }
                }
            }
        } else {
            if (groups->flags.bits.flag29 == 1) {
                u8 direction;
                object = &groups->objects[groups->flags.bits.group];
                direction = ov96_0220DAA0(groups->objects, groups->x, groups->y);
                if (object->state == 2 && direction == groups->flags.bits.group && groups->flags.bits.counter <= 5) {
                    ov96_0220D630(object);
                }
            }
            groups->flags.raw &= ~0x20000000;
        }
        object = (Ov96Object *)groups;
        i = 0;
        object = (Ov96Object *)((u8 *)object + 8);
        for (; i < 3; i++, object++) {
            ov96_0220D9A4(object, course);
        }
    }
    ov96_0220F710(course);
}
