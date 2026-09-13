#include "r40_unk_02011130_residual_4_private.h"

void sub_02011A44(int diameter, int value, int a, int b, int *left, int *right) {
    int radius = diameter / 128;
    int distance = b - a;
    fx32 radiusFx;
    fx32 distanceFx;
    fx32 height;

    if (distance < 0) {
        distance = -distance;
    }
    if (distance >= radius) {
        *left = 0;
        *right = 0;
        return;
    }

    distanceFx = distance << FX32_SHIFT;
    radiusFx = radius << FX32_SHIFT;
    height = FX_Sqrt((u32)((((s64)radiusFx * radiusFx + 0x800) >> FX32_SHIFT) - (((s64)distanceFx * distanceFx + 0x800) >> FX32_SHIFT)));
    height >>= FX32_SHIFT;
    *left = value - height;
    if (*left < 0) {
        *left = 0;
    }
    *right = *left + height * 2;
    if (*right > 0xff) {
        *right = 0xff;
    }
}

void sub_02011AD8(CircleFadeWork *work) {
    s16 *buffer = sub_02010EE0(work, 0);
    int i;

    for (i = 0; i < 192; i++) {
        int first;
        int second;

        if (i <= work->radius) {
            sub_02011A44(work->center, work->value, work->radius, i, &first, &second);
        } else if (i <= work->radius * 2) {
            first = buffer[0x180 + (work->radius * 2 - i)];
            second = buffer[0x240 + (work->radius * 2 - i)];
        } else {
            sub_02011A44(work->center, work->value, work->radius, i, &first, &second);
        }
        buffer[0x180 + i] = first;
        buffer[0x240 + i] = second;
    }
}
