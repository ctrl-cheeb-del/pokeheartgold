#include "map_object_trainer_behavior_internal.h"

void sub_02063AFC(LMO *obj) {
}

int sub_02063B00(LMO *obj) {
    return 0;
}

int sub_02063B04(LMO *obj) {
    return 0;
}

void sub_02063B08(LMO *obj) {
    TrState *state = (TrState *)sub_0205F398(obj, 9);
    state->unk3 = MapObject_GetParam(obj, 1);
}

BOOL sub_02063B20(LMO *obj) {
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
