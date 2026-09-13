#include "r40_unk_020619FC_private.h"

int sub_020619FC(void *mapObject, Unk020619FCState *state) {
    int direction;
    int result;
    int kind;

    if (state->turn != 0) {
        int initialX = MapObject_GetInitialX(mapObject);
        int initialZ = MapObject_GetInitialZ(mapObject);
        int x = MapObject_GetXCoord(mapObject);
        int z = MapObject_GetZCoord(mapObject);

        if (initialX == x && initialZ == z) {
            direction = sub_020611F4(MapObject_GetNextFacingDirection(mapObject));
            MapObject_SetNextFacingDirection(mapObject, direction);
            if (sub_02062050(mapObject) == 0) {
                MapObject_SetFacingDirection(mapObject, direction);
            }
            state->turn = 0;
        }
    }
    direction = MapObject_GetNextFacingDirection(mapObject);
    result = sub_02060BB8(mapObject, direction);
    if (result & 1) {
        state->turn = 1;
        direction = sub_020611F4(direction);
        result = sub_02060BB8(mapObject, direction);
    }
    kind = 0xc;
    if (result != 0) {
        kind = 0x20;
    }
    result = sub_0206234C(direction, kind);
    MapObject_ForceSetHeldMovement(mapObject, result);
    if (sub_02062050(mapObject) == 1) {
        sub_0206207C(mapObject, state->data);
    }
    MapObject_SetSingleMovement(mapObject);
    state->state = 2;
    return 1;
}
