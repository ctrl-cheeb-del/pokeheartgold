#include "r40_overlay_48_residual_27_private.h"

extern void ov48_0225A650(void *target, s32 x, s32 y);
extern void ov48_0225AEC4(void *motion, VecFx32 *out);
extern void Sprite_SetMatrix(void *sprite, const VecFx32 *matrix);
extern const s16 FX_SinCosTable_[];

void ov48_0225AEDC(Ov48R27Motion *motion) {
    s16 endX;
    s16 startY;
    s16 startX;
    s16 sine;
    s32 amplitude;
    u16 angle;
    s64 product;
    s32 scaled;
    float amplitudeFloat;

    if (motion->wrapY == 0) {
        endX = motion->bounds[3] - 0x10;
    } else {
        endX = motion->bounds[3];
    }
    if (motion->wrapX == 0) {
        startY = motion->bounds[1] + 0x10;
    } else {
        startY = motion->bounds[1];
    }
    startX = motion->bounds[0];
    motion->x = startX + (motion->bounds[2] - startX) * motion->step / motion->bounds[4];
    motion->y = startY + (endX - startY) * motion->step / motion->bounds[4];

    angle = (u16)((0xFFFF * motion->angle) / motion->bounds[6]);
    sine = FX_SinCosTable_[(angle >> 4) * 2];
    if (motion->bounds[5] > 0) {
        amplitudeFloat = (float)(motion->bounds[5] << 12) + 0.5f;
    } else {
        amplitudeFloat = (float)(motion->bounds[5] << 12) - 0.5f;
    }
    amplitude = (s32)amplitudeFloat;
    product = (s64)amplitude * sine;
    scaled = (s32)((product + 0x800) >> 12);
    motion->x += scaled >> 12;
}

void ov48_0225AFB4(Ov48R27Motion *motion, void *target) {
    s16 bound;

    ov48_0225A650(target, 0, 0);
    if (motion->wrapX == 0) {
        bound = motion->bounds[1];
        if (motion->y > bound - 0x10) {
            ov48_0225A650(target, bound, (s16)(bound + 0x20));
        }
    }
    if (motion->wrapY == 0) {
        bound = motion->bounds[3];
        if (motion->y - 0x10 <= bound) {
            ov48_0225A650(target, (s16)(bound - 0x20), bound);
        }
    }
}

void ov48_0225B010(u8 *work, u32 index) {
    VecFx32 matrix;

    ov48_0225AEC4(work + index * 0x10, &matrix);
    Sprite_SetMatrix(*(void **)(work + 0x3C + work[0x38 + index] * 4), &matrix);
}
