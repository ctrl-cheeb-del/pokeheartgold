#include "map_object_trainer_behavior_internal.h"

void sub_02063E50(LMO *obj) {
    AppriState *state = (AppriState *)sub_0205F3E8(obj, 0x18);
    state->unk0 = 0x106;
    state->unk4 = 0;
    sub_0205F484(obj);
}

void sub_02063E70(LMO *obj) {
    Unk394 *r7 = sub_0205F394(obj);
    AppriState *state = sub_0205F40C(obj);
    int apricorn = sub_02055780(MapObject_GetFieldSystem(obj), obj);
    if (ov01_021FA2D4(obj) == TRUE) {
        return;
    }
    if (state->unk8 == NULL) {
        state->unk0 = sub_020640A4(FieldSystem_ApricornTree_TryGetApricorn(MapObject_GetFieldSystem(obj), obj), apricorn);
        MapObject_SetSpriteID(obj, state->unk0);
        ov01_021F94C0(obj, &state->unk8, state->unk0);
    } else if (apricorn != state->unk4) {
        ov01_021F95CC(obj, &state->unk8, state->unk0);
        state->unk0 = sub_020640A4(FieldSystem_ApricornTree_TryGetApricorn(MapObject_GetFieldSystem(obj), obj), apricorn);
        MapObject_SetSpriteID(obj, state->unk0);
        if (state->unk0 != 0xFFFF) {
            if (apricorn == 1) {
                ov01_021FE66C(obj);
            }
            ov01_021F94C0(obj, &state->unk8, state->unk0);
        } else {
            GF_AssertFail();
        }
        r7->unk2 = 0;
    }
    state->unk4 = apricorn;
    if (ov01_021FA2D4(obj) == TRUE) {
        return;
    }
    if (state->unk8 == NULL) {
        return;
    }
    ov01_021FA3E8(obj, state->unk8);
    if (ov01_021F9344(obj) == 0) {
        switch (sub_0205F330(obj)) {
        case 0:
            if (sub_02023EF4(state->unk8) != 0) {
                sub_02023EE0(state->unk8, 0);
                sub_02023F40(state->unk8, 0);
            }
            break;
        case 1:
            if (sub_02023EF4(state->unk8) != 1) {
                sub_02023EE0(state->unk8, 1);
                sub_02023F40(state->unk8, 0);
            }
            break;
        case 2:
            if (sub_02023EF4(state->unk8) != 2) {
                sub_02023EE0(state->unk8, 2);
                sub_02023F40(state->unk8, 0);
            }
            break;
        default:
            GF_AssertFail();
            if (sub_02023EF4(state->unk8) != 0) {
                sub_02023EE0(state->unk8, 0);
                sub_02023F40(state->unk8, 0);
            }
            break;
        }
        sub_02023F04(state->unk8, 1 << 12);
    }
    ov01_021FA40C(obj, state->unk8);
}

void sub_02063FE4(LMO *obj) {
    AppriState *state = sub_0205F40C(obj);
    ov01_021F95CC(obj, &state->unk8, state->unk0);
}

void sub_02063FFC(LMO *obj) {
    AppriState *state = sub_0205F40C(obj);
    if (state->unk8 != NULL) {
        ov01_021F9610(state->unk8, &state->unkC);
    }
    ov01_021F95CC(obj, &state->unk8, state->unk0);
    MapObject_SetFlagsBits(obj, 2 << 20);
}

void sub_0206402C(LMO *obj) {
    AppriState *state = sub_0205F40C(obj);
    if (ov01_021FA2D4(obj) == TRUE) {
        return;
    }
    if (state->unk8 == NULL) {
        if (state->unk0 != 0xFFFF) {
            ov01_021F94C0(obj, &state->unk8, state->unk0);
        } else {
            GF_AssertFail();
        }
    }
    if (state->unk8 == NULL) {
        return;
    }
    ov01_021F9630(state->unk8, &state->unkC);
    ov01_021FA3E8(obj, state->unk8);
    MapObject_ClearFlagsBits(obj, 2 << 20);
}

void *sub_02064084(LMO *obj) {
    if (ov01_021FA2D4(obj) == TRUE) {
        GF_AssertFail();
        return NULL;
    }
    return sub_0205F40C(obj)->unk8;
}

u32 sub_020640A4(int a0, int a1) {
    if (a1 == 0) {
        return 0x106;
    }
    if (a0 == 0) {
        GF_AssertFail();
    }
    return ov01_02207274[a0];
}
