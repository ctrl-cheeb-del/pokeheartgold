#include "to45_overlay96_r82_private.h"

void ov96_0220144C(s32 *value, s32 delta) {
    *value += delta;
    if (*value >= 1024) {
        *value -= 1024;
    } else if (*value < 0) {
        *value += 1024;
    }
}
