#include "field_map_object_motion_internal.h"

void ov01_021F856C(void *u, void *o, const s8 *s, int i) {
    LocalFalling(o, s, i, 0);
}

void ov01_021F85BC(void *u, void *o, const s8 *s, int i) {
    LocalMotion(o, s, i, 1, ov01_022089F8);
}
