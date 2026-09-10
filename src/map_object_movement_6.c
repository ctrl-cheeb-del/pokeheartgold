#include "map_object_movement_internal.h"

BOOL sub_02061ABC(LocalMapObject *object, u8 *state) {
    if (sub_02062428(object) == TRUE) {
        MapObject_ClearSingleMovement(object);
        if (sub_02062050(object) == TRUE) {
            sub_020620F8(object, state + 4);
        }
        *(u16 *)state = 0;
    }
    return FALSE;
}

void sub_02061AEC(LocalMapObject *object, u32 first, u32 second, u32 value) {
    u8 *state = sub_0205F370(object, 12);
    state[2] = first;
    state[3] = second;
    *(u32 *)(state + 4) = value;
    if (sub_02062050(object) == TRUE) {
        sub_02062064(object, state + 8);
    }
}

void sub_02061B1C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 14);
}

void sub_02061B2C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 15);
}

void sub_02061B3C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 16);
}

void sub_02061B4C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 17);
}

void sub_02061B5C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 18);
}

void sub_02061B6C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 19);
}

void sub_02061B7C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 20);
}

void sub_02061B8C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 21);
}

void sub_02061B9C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 22);
}

void sub_02061BAC(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 23);
}

void sub_02061BBC(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 24);
}

void sub_02061BCC(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 25);
}

void sub_02061BDC(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 26);
}

void sub_02061BEC(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 27);
}

void sub_02061BFC(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 28);
}

void sub_02061C0C(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 29);
}

void sub_02061C1C(LocalMapObject *object) {
    u8 *state = sub_0205F394(object);
    while (_020FD4EC[state[0]](object, state) == TRUE) {}
}
