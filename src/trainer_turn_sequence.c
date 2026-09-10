#include "trainer_turn_sequence_internal.h"

BOOL sub_02063B9C(LMO *obj) {
    TrState *state = (TrState *)sub_0205F3BC(obj);
    switch (state->unk1) {
    case 0: {
        FourValues dirTable = _020FE0C4;
        int dir = MapObject_GetFacingDirection(obj);
        state->unk4 = dir;
        state->unk5 = dirTable.values[dir];
        state->unk1++;
    }
    case 1: {
        TwoByTwoValues moveTable = _020FE0D4;
        MapObject_ForceSetHeldMovement(obj, sub_0206234C(moveTable.values[state->unk5][state->unk6], 0));
        state->unk1++;
    }
    case 2:
        if (sub_02062428(obj) == 0) {
            return TRUE;
        }
        state->unk1++;
    case 3:
        state->unk8++;
        if (state->unk8 < 8) {
            return TRUE;
        }
        state->unk8 = 0;
        state->unk7++;
        if (state->unk7 < 4) {
            state->unk6 = (state->unk6 + 1) & 1;
            state->unk1 = 1;
            return TRUE;
        }
        MapObject_SetFacingDirection(obj, state->unk4);
        state->unk1++;
        state->unk7 = 0;
        state->unk0 = 0;
    }
    return FALSE;
}
