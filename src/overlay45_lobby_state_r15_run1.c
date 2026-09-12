#include "overlay45_lobby_state_r15_private.h"

void ov45_0222B0BC(Ov45State *state) {
    if (ov45_0222AFF8(state) == 1) {
        ov45_0222BDCC(&state->data[0x1c0], *(u16 *)&state->data[0x1c4]);
    }
}

void ov45_0222B0D8(Ov45State *state, int value) {
    ov45_0222BDCC(&state->data[0x1c0], value);
}

void ov45_0222B0E8(Ov45State *state, int value) {
    ov45_0222BD94(&state->data[0x1c0], value);
}

void IncrementGameStat47(void **state) {
    GameStats_Inc(Save_GameStats_Get(*state), 47);
}

void IncrementGameStat119(void **state) {
    GameStats_Inc(Save_GameStats_Get(*state), 119);
}

void ov45_0222B118(Ov45State *state, int slot) {
    if (slot >= 8) {
        GF_AssertFail();
    }
    ((Ov45Flags *)state)->flag[slot] = 1;
}

int ov45_0222B134(Ov45State *state) {
    int i;
    int ok;
    for (i = 0; i < 8; i++) {
        if (state->data[0x3a4 + i] == 0) {
            switch (i) {
            case 0:
            case 1:
            case 2:
                if (ov45_0222A394(state) == 1) {
                    ok = 0;
                } else {
                    ok = 1;
                }
                break;
            case 3:
            case 4:
            case 5:
                if (ov45_0222A330(state) == 1) {
                    ok = 0;
                } else {
                    ok = 1;
                }
                break;
            case 6:
                if (ov45_0222A3A0(state) == 1) {
                    ok = 0;
                } else {
                    ok = 1;
                }
                break;
            case 7:
            default:
                ok = 1;
                break;
            }
            if (ok == 1) {
                return i;
            }
        }
    }
    return 8;
}

int ov45_0222B1B4(Ov45State *state) {
    int result = ov45_0222C900(&state->data[0x3ac]);
    int value = ov45_0222A53C(state);
    if (ov45_0222AB28(state, value) == 1) {
        result += 2;
    }
    return result;
}

void *ov45_0222B1DC(Ov45State *state) {
    return ov45_0222CB40(&state->data[0x49c]);
}

void *ov45_0222B1EC(Ov45State *state) {
    return ov45_0222CB3C(&state->data[0x49c]);
}

void ov45_0222B1FC(Ov45State *state, const Ov45Copy20 *src) {
    *(u32 *)&state->data[0x524] = 1;
    *(Ov45Copy20 *)&state->data[0x510] = *src;
}

BOOL ov45_0222B21C(Ov45State *state, Ov45Copy20 *dst) {
    if (*(u32 *)&state->data[0x524] == 1) {
        *dst = *(Ov45Copy20 *)&state->data[0x510];
        return TRUE;
    }
    return FALSE;
}

void ov45_0222B244(Ov45State *state) {
    if (*(void **)&state->data[0x4b8] != NULL) {
        GF_AssertFail();
    }
    *(void **)&state->data[0x4b8] = sub_02078DD8(Save_PlayerData_GetProfile(*(void **)state->data), *(void **)&state->data[0x528]);
}

void ov45_0222B270(Ov45State *state) {
    if (*(void **)&state->data[0x4b8] != NULL) {
        sub_02078E28(*(void **)&state->data[0x4b8]);
        *(void **)&state->data[0x4b8] = NULL;
    }
}

BOOL ov45_0222B28C(const u16 *values, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        if (values[i] == 0xffff) {
            return TRUE;
        }
    }
    return FALSE;
}
