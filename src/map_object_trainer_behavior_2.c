#include "map_object_trainer_behavior_internal.h"

void sub_02063C88(LMO *obj) {
    TrState *state = (TrState *)sub_0205F398(obj, 9);
    state->unk3 = MapObject_GetParam(obj, 1);
    state->unk5 = (MapObject_GetType(obj) != 5);
}

BOOL sub_02063CB4(LMO *obj) {
    TrState *state = (TrState *)sub_0205F3BC(obj);
    switch (state->unk0) {
    case 0:
        if (sub_02063A94(obj) == TRUE) {
            state->unk0++;
        }
        break;
    case 1:
        if (sub_02063AC8(obj) == 0) {
            break;
        }
        state->unk2++;
        if (state->unk2 < state->unk3) {
            state->unk0 = 0;
            break;
        }
        state->unk0++;
    case 2:
        if (MapObject_CheckSingleMovement(obj) == TRUE) {
            break;
        }
        state->unk0++;
        state->unk2 = 0;
        state->unk1 = 0;
    case 3:
        return TRUE;
    }
    return FALSE;
}
