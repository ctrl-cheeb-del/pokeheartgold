#include "overlay96_course_ui_r101_private.h"

void ov96_0220E974(s32 *values, s32 limit) {
    s32 negLimit = -limit;

    if (values[0] > 0) {
        if (values[0] > limit) {
            values[0] = limit;
        }
    } else if (values[0] < negLimit) {
        values[0] = negLimit;
    }

    if (values[1] > 0) {
        if (values[1] > limit) {
            values[1] = limit;
        }
    } else if (values[1] < negLimit) {
        values[1] = negLimit;
    }
}
