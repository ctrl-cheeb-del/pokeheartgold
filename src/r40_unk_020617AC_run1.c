#include "global.h"

#include "r40_unk_020617AC_private.h"

BOOL sub_020617AC(LocalMapObject *object, s8 *state) {
    DirectionList617AC listA = _020FD754;
    DirectionList617AC listB = _020FD768;
    int i;
    DirectionList617AC *list = &listA;
    int direction;

    if (state[0] != 2) {
        list = &listB;
    }
    direction = MapObject_GetFacingDirection(object);
    i = 0;
    if (list->value[0] != -1) {
        int *p = list->value;
        do {
            if (direction == *p) {
                break;
            }
            p++;
            i++;
        } while (*p != -1);
    }
    GF_ASSERT(list->value[i] != -1);
    i++;
    if (list->value[i] == -1) {
        i = 0;
    }
    MapObject_SetFacingDirection(object, list->value[i]);
    state[2] = 0;
    return TRUE;
}
