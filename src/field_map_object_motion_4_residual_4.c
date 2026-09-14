#include "field_map_object_motion_4_residual_4.h"

typedef struct MotionExtra {
    Sprite *sprite;
    VecFx32 vector;
    s8 direction;
    u8 pad11[6];
    u8 active : 1;
    u8 : 7;
} MotionExtra;

void ov01_021F7810(LocalMapObject *object) {
    MotionExtra *extra = (MotionExtra *)sub_0205F40C(object);
    Sprite *sprite = extra->sprite;
    u32 direction;

    if (ov01_021FA2D4(object) == TRUE || sprite == NULL) {
        return;
    }
    if (!extra->active) {
        extra->active = TRUE;
        if (ov01_02205564(object)) {
            ov01_0220589C((void *)TRUE, object, extra->sprite);
        } else if (ov01_0220553C(object)) {
            ov01_02205808((void *)TRUE, object, sprite);
        }
    }
    direction = MapObject_GetFacingDirection(object);
    ov01_021F8D80(object, sprite, (UnkObjExtra *)extra, direction, TRUE);
    extra->direction = direction;
    ov01_021FA3E8(object, sprite);
    ov01_021F8C88(object, sprite);
}

void ov01_021F7894(LocalMapObject *object) {
    MotionExtra *extra = (MotionExtra *)sub_0205F40C(object);
    Sprite *sprite = extra->sprite;
    u32 direction;

    if (ov01_021FA2D4(object) == TRUE || sprite == NULL) {
        return;
    }
    if (!extra->active) {
        extra->active = TRUE;
        if (ov01_02205564(object)) {
            ov01_0220589C((void *)TRUE, object, extra->sprite);
        } else if (ov01_0220553C(object)) {
            ov01_02205808((void *)TRUE, object, sprite);
        }
    }
    direction = MapObject_GetFacingDirection(object);
    ov01_021F8D80(object, sprite, (UnkObjExtra *)extra, direction, TRUE);
    extra->direction = direction;
    ov01_021FA3E8(object, sprite);
    ov01_021F8C88(object, sprite);
}

void ov01_021F7918(LocalMapObject *object) {
    MotionExtra *extra = (MotionExtra *)sub_0205F40C(object);
    Sprite *sprite;

    if (ov01_021FA2D4(object) == TRUE) {
        return;
    }
    sprite = extra->sprite;
    if (sprite == NULL) {
        return;
    }
    if (!extra->active) {
        extra->active = TRUE;
        if (ov01_0220553C(object)) {
            ov01_02205808((void *)TRUE, object, sprite);
        }
    }
    ov01_021FA3E8(object, sprite);
    ov01_021F8C88(object, sprite);
}
