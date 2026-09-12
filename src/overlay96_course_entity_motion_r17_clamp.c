#include "overlay96_course_entity_motion_r17_private.h"

void ov96_02219174(void **p, int amount) {
    ((int *)p[1])[2] -= amount;
    if (((int *)p[1])[2] < 0) {
        ((int *)p[1])[2] = 0;
    }
}
