#include "field_map_object_motion_internal.h"

void ov01_021F7FC8(void *a, void *b, const s8 *c, int d) {
    LocalTrackedMotion(a, b, c, d, FX32_ONE);
}

void ov01_021F801C(void *a, void *b, const s8 *c, int d) {
    LocalTrackedMotion(a, b, c, d, 2 * FX32_ONE);
}

void ov01_021F8070(void *a, void *b, const s8 *c, int d) {
    LocalTrackedMotion(a, b, c, d, 4 * FX32_ONE);
}
