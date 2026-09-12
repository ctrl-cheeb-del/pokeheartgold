#include "overlay49_battle_effects_r80_private.h"

void ov49_022693A4(BOOL suppress, BOOL special, BOOL player, u32 value) {
    if (suppress != FALSE) {
        if (special == FALSE) {
            return;
        }
        if (player) {
            sub_0200606C(value, 5);
            return;
        } else {
            PlaySE(value);
            return;
        }
    }
    PlaySE(value);
}

void ov49_022693D4(BOOL suppress, BOOL special, BOOL unused, u32 species) {
    if (suppress != FALSE) {
        if (special == FALSE) {
            return;
        }
        PlayCry(species, 0);
        return;
    }
    PlayCry(species, 0);
}

BOOL ov49_022693F8(u16 *state, u32 index, void *a, void *b) {
    if (index >= 2) {
        GF_AssertFail();
    }
    if (state[0] == 1) {
        return FALSE;
    }
    state[1] = index;
    state[0] = 1;
    ov49_0226A8D4[index](state, a, b);
    return TRUE;
}

BOOL ov49_02269430(u16 *state, void *a, int index) {
    if (state[0] != 0) {
        if (ov49_0226A8CC[state[1]](state, a, index) == TRUE) {
            u8 *p = (u8 *)state;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
            p[7] = 0;
            p[8] = 0;
            p[9] = 0;
            p[10] = 0;
            p[11] = 0;
            p[12] = 0;
            p[13] = 0;
        }
        return TRUE;
    }
    return FALSE;
}

void ov49_02269474(s16 *state) {
    state[2] = 0;
    state[3] = 8;
    state[4] = GF_DegreeToSinCosIdx(5);
    state[5] = 2;
    state[6] = 4;
}

void ov49_02269494(s16 *state) {
    state[2] = 0;
    state[3] = 16;
    state[4] = GF_DegreeToSinCosIdx(10);
    state[5] = 4;
    state[6] = 2;
}
