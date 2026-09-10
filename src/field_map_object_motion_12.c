#include "field_map_object_motion_internal.h"

void ov01_021F8804(void *u, void *o, const s8 *s, int i) {
    LocalMotion(o, s, i, 0, ov01_02208A18);
}

void ov01_021F883C(void *u, void *o, const s8 *s, int i) {
    LocalMotion(o, s, i, 1, ov01_02208A18);
}
