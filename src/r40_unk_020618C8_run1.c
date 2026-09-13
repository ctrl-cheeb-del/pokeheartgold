#include "r40_unk_020618C8_private.h"

BOOL sub_020618C8(LocalMapObject *object, MovementState618C8 *state) {
    typedef struct DirectionOrder {
        int values[5];
    } DirectionOrder;
    DirectionOrder orderA = *(const DirectionOrder *)_020FD77C;
    DirectionOrder orderB = *(const DirectionOrder *)_020FD7A4;
    int i;
    int direction;
    int *order;
    int *alternate;

    order = orderA.values;
    alternate = orderB.values;
    if (state->state != 2) {
        order = alternate;
    }

    direction = MapObject_GetFacingDirection(object);
    i = 0;
    if (order[i] != -1) {
        do {
            if (direction == order[i]) {
                break;
            }
            i++;
        } while (order[i] != -1);
    }
    GF_ASSERT(order[i] != -1);
    i++;
    if (order[i] == -1) {
        i = 0;
    }
    MapObject_SetFacingDirection(object, order[i]);

    direction = MapObject_GetFacingDirection(object);
    if (direction == MapObject_GetInitialFacingDirection(object)) {
        state->state = sub_020611F4(state->state);
    }
    state->flag = 0;
    return TRUE;
}
