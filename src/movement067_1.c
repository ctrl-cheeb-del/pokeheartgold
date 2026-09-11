#include "movement067_internal.h"
typedef struct Move067 {
    s32 pos;
    s32 delta;
} Move067;

BOOL MapObjectMovementCmd067_Step0(LocalMapObject *obj) {
    Move067 *m = (Move067 *)sub_0205F3C0(obj, 8);
    m->delta = 0x10000;
    sub_0205F328(obj, 0);
    MapObject_IncrementMovementStep(obj);
    return TRUE;
}

BOOL MapObjectMovementCmd067_Step1(LocalMapObject *obj) {
    Move067 *m = (Move067 *)sub_0205F3E4(obj);
    m->pos += m->delta;
    VecFx32 v = { 0, 0, 0 };
    v.y = m->pos;
    MapObject_SetFacingVector(obj, &v);
    if ((m->pos / 0x8000) < 40) {
        return FALSE;
    }
    MapObject_IncrementMovementStep(obj);
    return TRUE;
}

BOOL MapObjectMovementCmd068_Step0(LocalMapObject *obj) {
    Move067 *m = (Move067 *)sub_0205F3C0(obj, 8);
    m->pos = 0x140000;
    m->delta = -0x10000;
    sub_0205F328(obj, 0);
    MapObject_IncrementMovementStep(obj);
    return TRUE;
}

BOOL MapObjectMovementCmd068_Step1(LocalMapObject *obj) {
    Move067 *m = (Move067 *)sub_0205F3E4(obj);
    m->pos += m->delta;
    if (m->pos < 0) {
        m->pos = 0;
    }
    VecFx32 v = { 0, 0, 0 };
    v.y = m->pos;
    MapObject_SetFacingVector(obj, &v);
    if (m->pos > 0) {
        return FALSE;
    }
    MapObject_IncrementMovementStep(obj);
    return TRUE;
}
