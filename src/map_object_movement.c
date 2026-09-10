#include "map_object_movement_internal.h"

void sub_02061284(LocalMapObject *object, u32 value) {
    u8 *state = sub_0205F370(object, 8);
    *(u16 *)(state + 2) = sub_02061E20(_020FD7B8, -1);
    *(u32 *)(state + 4) = value;
    sub_0205F328(object, 0);
    MapObject_ClearSingleMovement(object);
}

void sub_020612B4(LocalMapObject *object) {
    sub_02061284(object, 0);
}

void sub_020612C0(LocalMapObject *object) {
    sub_02061284(object, 1);
}

void sub_020612CC(LocalMapObject *object) {
    sub_02061284(object, 2);
}

void sub_020612D8(LocalMapObject *object) {
    sub_02061284(object, 3);
}

void sub_020612E4(LocalMapObject *object) {
    sub_02061284(object, 4);
}

void sub_020612F0(LocalMapObject *object) {
    sub_02061284(object, 5);
}

void sub_020612FC(LocalMapObject *object) {
    sub_02061284(object, 6);
}

void sub_02061308(LocalMapObject *object) {
    sub_02061284(object, 7);
}

void sub_02061314(LocalMapObject *object) {
    sub_02061284(object, 8);
}

void sub_02061320(LocalMapObject *object) {
    sub_02061284(object, 9);
}

void sub_0206132C(LocalMapObject *object) {
    sub_02061284(object, 10);
}

void sub_02061338(LocalMapObject *object) {
    u8 *state = sub_0205F394(object);
    int direction = sub_02061F5C(object, *(u32 *)(state + 4), -1);
    if (direction != -1) {
        MapObject_SetFacingDirection(object, direction);
    } else if (*(u16 *)state == 0) {
        (*(s16 *)(state + 2))--;
        if (*(s16 *)(state + 2) <= 0) {
            *(u16 *)(state + 2) = sub_02061E20(_020FD7B8, -1);
            direction = sub_02061E44(*(u32 *)(state + 4), -1);
            MapObject_SetFacingDirection(object, direction);
        }
    }
    sub_02060F78(object);
}

void sub_0206139C(LocalMapObject *object) {
    (void)object;
}

void sub_020613A0(LocalMapObject *object) {
    sub_020613D0(object, 12, 11, 0);
}

void sub_020613B0(LocalMapObject *object) {
    sub_020613D0(object, 12, 12, 0);
}

void sub_020613C0(LocalMapObject *object) {
    sub_020613D0(object, 12, 13, 0);
}

void sub_020613D0(LocalMapObject *object, u32 first, u32 second, u32 third) {
    u32 *state = (u32 *)sub_0205F370(object, 16);
    state[1] = third;
    state[2] = first;
    state[3] = second;
    sub_0205F328(object, 0);
    MapObject_ClearSingleMovement(object);
}
