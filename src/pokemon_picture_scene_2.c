#include "pokemon_picture_scene_internal.h"

void sub_0208DF9C(const UnkAnimVec *src, UnkVec3s *dst, int t) {
    if (t == 0xFF) {
        dst->x = src->a[0];
        dst->y = src->a[1];
        dst->z = src->a[2];
        return;
    }
    if (t == 0) {
        dst->x = src->b[0];
        dst->y = src->b[1];
        dst->z = src->b[2];
        return;
    }
    dst->x = ((const UnkAnimVecS *)src)->b[0] + ((const UnkAnimVecS *)src)->c[0] * t;
    dst->y = ((const UnkAnimVecS *)src)->b[1] + ((const UnkAnimVecS *)src)->c[1] * t;
    dst->z = ((const UnkAnimVecS *)src)->b[2] + ((const UnkAnimVecS *)src)->c[2] * t;
}
