#include "r40_unk_02062958_private.h"

void sub_02062958(LocalMapObject *object, s8 direction, int distance, s8 speed, u16 parameter, s16 extra, u16 limit) {
    MoveData *data = sub_0205F3C0(object, sizeof(MoveData));
    data->direction = direction;
    data->distance = distance;
    data->speed = speed;
    data->parameter = parameter;
    data->extra = extra;
    data->limit = limit;
    if (distance == 0) {
        sub_02060F78(object);
    } else {
        sub_02060F24(object, direction);
    }
    MapObject_SetFlagsBits(object, 0x10004);
    MapObject_SetOrQueueFacing(object, direction);
    sub_0205F328(object, parameter);
    MapObject_IncrementMovementStep(object);
    if (!MapObject_CheckVisible(object)) {
        PlaySE(1546);
    }
}
