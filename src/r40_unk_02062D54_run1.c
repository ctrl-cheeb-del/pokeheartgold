#include "r40_unk_02062D54_private.h"

void sub_02062D54(LocalMapObject *object, s32 duration) {
    s32 *work = (s32 *)sub_0205F3C0(object, sizeof(s32));

    *work = duration;
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd064_Step1(LocalMapObject *object) {
    s32 *work = (s32 *)sub_0205F3E4(object);

    if (*work != 0) {
        (*work)--;
        return FALSE;
    }
    MapObject_IncrementMovementStep(object);
    return TRUE;
}
