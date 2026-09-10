#include "map_object_movement_internal.h"

void sub_02061648(LocalMapObject *object, u32 direction) {
    u32 *state = (u32 *)sub_0205F370(object, 8);
    state[0] = direction;
    sub_0205F328(object, 0);
    MapObject_ClearSingleMovement(object);
    sub_02060F78(object);
}

void sub_0206166C(LocalMapObject *object) {
    u32 *state = (u32 *)sub_0205F394(object);
    switch (state[1]) {
    case 0:
        MapObject_SetFacingDirection(object, state[0]);
        state[1]++;
        break;
    case 1:
        break;
    }
}

void sub_02061690(LocalMapObject *object) {
    sub_02061648(object, 0);
}

void sub_0206169C(LocalMapObject *object) {
    sub_02061648(object, 1);
}

void sub_020616A8(LocalMapObject *object) {
    sub_02061648(object, 2);
}

void sub_020616B4(LocalMapObject *object) {
    sub_02061648(object, 3);
}

void sub_020616C0(LocalMapObject *object, u32 value) {
    u8 *state = sub_0205F370(object, 8);
    state[0] = value;
    sub_0205F328(object, 0);
    MapObject_ClearSingleMovement(object);
    sub_02060F78(object);
}

void sub_020616E4(LocalMapObject *object) {
    sub_020616C0(object, 2);
}

void sub_020616F0(LocalMapObject *object) {
    sub_020616C0(object, 3);
}
