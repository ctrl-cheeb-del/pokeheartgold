#include "r40_overlay_96_residual_29_private.h"

void ov96_021EAF94(Ov96PositionObject *obj, s32 x, s32 y) {
    VecFx32 matrix;
    VecFx32 position = { 0 };
    void *sprite = ov96_021E8BAC(obj->object);
    s32 tempY;
    matrix = position;
    matrix.x = x << FX32_SHIFT;
    matrix.y = y << FX32_SHIFT;
    if (obj->sprite1 != NULL) {
        Sprite_SetMatrix(obj->sprite1, &matrix);
    }
    if (obj->sprite2 != NULL) {
        Sprite_SetMatrix(obj->sprite2, &matrix);
    }
    tempY = y + obj->offsetY - 2 * obj->halfHeight;
    {
        s32 tempX = x - obj->offsetX;
        obj->x = x;
        obj->y = tempY + obj->halfHeight;
        position.x = tempX << FX32_SHIFT;
    }
    position.y = tempY << FX32_SHIFT;
    if (ov96_021E92AC(obj->object)) {
        position.y += 0x8000;
    }
    Sprite_SetMatrix(sprite, &position);
}

void ov96_021EB01C(Ov96PositionObject *obj, s32 x, s32 y, u32 arg) {
    s32 offsetX = obj->offsetX;
    s32 center = obj->center;
    s32 delta = 2 * obj->halfHeight - center;
    x -= offsetX;
    y -= center + delta / 2;
    ov96_021EAD88(obj, x, y, arg);
}

void ov96_021EB03C(Ov96PositionObject *obj, s32 x, s32 y, s32 *outX, s32 *outY) {
    s32 twiceHeight = 2 * obj->halfHeight;
    s32 center = obj->center + (twiceHeight - obj->center) / 2;
    s32 result = y - (center << FX32_SHIFT) + ((twiceHeight - obj->bottom) << FX32_SHIFT);
    *outX = x;
    *outY = result;
}

void ov96_021EB06C(Ov96PositionObject *obj, s32 x, s32 y, s32 *outX, s32 *outY) {
    s32 twiceHeight;
    s32 center;
    if (obj->sprite1 == NULL) {
        GF_AssertFail();
        return;
    }
    twiceHeight = 2 * obj->halfHeight;
    center = obj->center + (twiceHeight - obj->center) / 2;
    y -= center;
    y += twiceHeight;
    y -= obj->offsetY;
    *outX = x;
    *outY = y;
}
