#include "r40_unk_02063D30_private.h"

BOOL sub_02063D30(LMO *obj) {
    DirectionMovementTable sp0 = _020FE0E4;
    volatile TrState *state = (TrState *)sub_0205F3BC(obj);
    int i;
    int dir;
    switch (state->unk1) {
    case 0:
        dir = MapObject_GetFacingDirection(obj);
        i = 0;
        goto search_check;
search_next:
        i++;
search_check:
        if (i < 4) {
            if (dir != sp0.values[state->unk5][i]) {
                goto search_next;
            }
        }
        if (i >= 4) {
            GF_AssertFail();
        }
        state->unk4 = dir;
        state->unk6 = (i + 1) % 4;
        state->unk1++;
    case 1:
        MapObject_ForceSetHeldMovement(obj, sub_0206234C(sp0.values[state->unk5][state->unk6], 0));
        state->unk1++;
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
            state->unk6 = (state->unk6 + 1) % 4;
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
