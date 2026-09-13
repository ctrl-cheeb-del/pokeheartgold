#include "r40_unk_020627B0_private.h"

void sub_020627B0(LocalMapObject *, int, int, int);
BOOL MapObjectMovementCmd040_Step1(LocalMapObject *);

void sub_020627B0(LocalMapObject *object, int direction, int duration, int movement) {
    Movement040Work *work = (Movement040Work *)sub_0205F3C0(object, sizeof(Movement040Work));
    work->movement = movement;
    work->timer = duration + 1;
    MapObject_SetFacingDirection(object, direction);
    sub_0205F328(object, movement);
    sub_02060F78(object);
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd040_Step1(LocalMapObject *object) {
    Movement040Work *work = (Movement040Work *)sub_0205F3E4(object);
    work->timer--;
    if (work->timer > 0) {
        return FALSE;
    }
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)0x20);
    sub_0205F328(object, 0);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}
