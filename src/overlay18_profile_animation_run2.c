#include "overlay18_profile_animation_internal.h"

void ov18_021F4F98(void *p, int idx, u16 angle, s16 x, s16 y) {
    ov18_021F4EB0(angle, &x, &y);
    ov18_021F1294(p, idx, x, y, 1);
}
