#include "map_object_movement_internal.h"

BOOL sub_02061D50(LocalMapObject *object, u8 *state) {
    if (sub_02062428(object) == TRUE) {
        MapObject_ClearSingleMovement(object);
        if (sub_02062050(object) == TRUE) {
            sub_020620F8(object, state + 8);
        }
        state[0] = 0;
    }
    return FALSE;
}

void sub_02061D80(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 30);
}

void sub_02061D90(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 31);
}

void sub_02061DA0(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 32);
}

void sub_02061DB0(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 33);
}

void sub_02061DC0(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 34);
}

void sub_02061DD0(LocalMapObject *object) {
    sub_02061AEC(object, 2, 1, 35);
}

void sub_02061DE0(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 36);
}

void sub_02061DF0(LocalMapObject *object) {
    sub_02061AEC(object, 2, 0, 37);
}

int sub_02061E00(const int *list, int value) {
    int i = 0;
    while (list[i] != value) {
        i++;
    }
    GF_ASSERT(i != 0);
    return i;
}

int sub_02061E20(const int *list, int value) {
    int random = LCRandom();
    int count = sub_02061E00(list, value);
    return list[random % count];
}

int sub_02061E44(int tableId, int value) {
    const int *list = sub_02061E6C(tableId);
    int random = LCRandom();
    int count = sub_02061E00(list, value);
    return list[random % count];
}
