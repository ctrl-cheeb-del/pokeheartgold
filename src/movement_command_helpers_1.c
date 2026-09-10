#include "movement_command_helpers_internal.h"

void sub_02062F48(void *mapObject, u32 parameter) {
    Movement075WorkPrivate *work = sub_0205F3C0(mapObject, 8);
    work->parameter = parameter;
    work->effect = ov01_02200540(mapObject, parameter, 1);
    MapObject_IncrementMovementStep(mapObject);
}

BOOL MapObjectMovementCmd075_Step1(void *mapObject, void *unused) {
    Movement075WorkPrivate *work;
    (void)unused;
    work = sub_0205F3E4(mapObject);
    if (ov01_022003F4(work->effect) == TRUE) {
        sub_02068B48(work->effect);
        MapObject_IncrementMovementStep(mapObject);
        return TRUE;
    }
    return FALSE;
}

BOOL MapObjectMovementCmd075_Step0(void *mapObject, void *unused) {
    (void)unused;
    sub_02062F48(mapObject, 0);
    return FALSE;
}

BOOL MapObjectMovementCmd103_Step0(void *mapObject, void *unused) {
    (void)unused;
    sub_02062F48(mapObject, 1);
    return FALSE;
}

void sub_02062FAC(void *mapObject, u32 facing, u32 count, u32 field2) {
    MovementPathWorkPrivate *work = sub_0205F3C0(mapObject, 8);
    work->facing = facing;
    work->field2 = field2;
    work->count = count;
    sub_02060F24(mapObject, facing);
    MapObject_SetOrQueueFacing(mapObject, facing);
    sub_0205F328(mapObject, field2);
    MapObject_SetFlagsBits(mapObject, 4);
    MapObject_IncrementMovementStep(mapObject);
}

BOOL sub_02062FEC(void *mapObject, const u32 *values) {
    MovementPathWorkPrivate *work = sub_0205F3E4(mapObject);
    sub_0206101C(mapObject, work->facing, values[work->index]);
    sub_02061070(mapObject);
    work->index++;
    if (work->index < work->count) {
        return FALSE;
    }
    MapObject_SetFlagsBits(mapObject, 0x28);
    sub_02060F78(mapObject);
    sub_0205F484(mapObject);
    sub_0205F328(mapObject, 0);
    MapObject_IncrementMovementStep(mapObject);
    return TRUE;
}
