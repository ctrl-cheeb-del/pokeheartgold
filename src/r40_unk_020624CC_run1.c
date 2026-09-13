#include "global.h"

#include "r40_unk_020624CC_private.h"

void sub_020624CC(void *object, u32 direction, u32 distance, s32 timer, u16 parameter) {
    Movement090Work *work = sub_0205F3C0(object, sizeof(Movement090Work));

    work->parameter = parameter;
    work->timer = timer;
    work->direction = direction;
    work->distance = distance;
    sub_02060F24(object, direction);
    MapObject_SetOrQueueFacing(object, direction);
    sub_0205F328(object, parameter);
    MapObject_SetFlagsBits(object, 4);
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd090_Step1(void *object) {
    Movement090Work *work = sub_0205F3E4(object);

    sub_0206101C(object, work->direction, work->distance);
    sub_02061070(object);
    work->timer--;
    if (work->timer > 0) {
        return FALSE;
    }
    MapObject_SetFlagsBits(object, 0x28);
    sub_02060F78(object);
    sub_0205F484(object);
    sub_0205F328(object, 0);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}
