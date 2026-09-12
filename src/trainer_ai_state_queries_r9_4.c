#include "trainer_ai_state_queries_r9_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov10_0221E74C(AiState *state, int battler, int *lhs, int *rhs, int kind);

void ov10_0221E5B0(void *bsys, AiState *state) {
    int battler;
    int i;
    s8 *ptr;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battler = ov10_0221EF34(state, (u8)ov10_0221EEF0(state));
    S32(state, 0x35c) = 0;
    ptr = (s8 *)state + 0xc0 * battler;
    for (i = 0; i < 8; i++) {
        int value = *(ptr + 0x2d58);
        if (value > 6) {
            S32(state, 0x35c) += value - 6;
        }
        ptr++;
    }
}

void ov10_0221E600(void *bsys, AiState *state) {
    int source;
    int slot;
    int battler;
    s8 *lhs;
    s8 *rhs;
    (void)bsys;
    ov10_0221EF24(state, 1);
    source = ov10_0221EEF0(state);
    slot = ov10_0221EEF0(state);
    battler = ov10_0221EF34(state, (u8)source);
    lhs = state->fields.mons[battler].stages;
    rhs = state->fields.mons[U8(state, 0x3cf)].stages;
    S32(state, 0x35c) = lhs[slot] - rhs[slot];
}

void ov10_0221E650(void *bsys, AiState *state) {
    int battlerCode, kind, result, battler, lhs, rhs;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battlerCode = ov10_0221EEF0(state);
    kind = ov10_0221EEF0(state);
    result = ov10_0221EEF0(state);
    battler = ov10_0221EF34(state, (u8)battlerCode);
    ov10_0221E74C(state, battler, &lhs, &rhs, kind);
    if (lhs < rhs) {
        ov10_0221EF24(state, result);
    }
}

void ov10_0221E6A4(void *bsys, AiState *state) {
    int battlerCode, kind, result, battler, lhs, rhs;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battlerCode = ov10_0221EEF0(state);
    kind = ov10_0221EEF0(state);
    result = ov10_0221EEF0(state);
    battler = ov10_0221EF34(state, (u8)battlerCode);
    ov10_0221E74C(state, battler, &lhs, &rhs, kind);
    if (lhs > rhs) {
        ov10_0221EF24(state, result);
    }
}

void ov10_0221E6F8(void *bsys, AiState *state) {
    int battlerCode, kind, result, battler, lhs, rhs;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battlerCode = ov10_0221EEF0(state);
    kind = ov10_0221EEF0(state);
    result = ov10_0221EEF0(state);
    battler = ov10_0221EF34(state, (u8)battlerCode);
    ov10_0221E74C(state, battler, &lhs, &rhs, kind);
    if (lhs == rhs) {
        ov10_0221EF24(state, result);
    }
}

void ov10_0221E74C(AiState *state, int battler, int *lhs, int *rhs, int kind) {
    switch (kind) {
    case 0: {
        *lhs = state->fields.mons[U8(state, 0x3cf)].value0;
        *rhs = state->fields.mons[battler].value0;
        break;
    }
    case 1: {
        *lhs = state->fields.mons[U8(state, 0x3cf)].hp;
        *rhs = state->fields.mons[battler].hp;
        break;
    }
    case 2: {
        *lhs = state->fields.mons[U8(state, 0x3cf)].maxHp;
        *rhs = state->fields.mons[battler].maxHp;
        break;
    }
    case 4: {
        *lhs = state->fields.mons[U8(state, 0x3cf)].stat4;
        *rhs = state->fields.mons[battler].stat4;
        break;
    }
    case 5: {
        *lhs = state->fields.mons[U8(state, 0x3cf)].stat5;
        *rhs = state->fields.mons[battler].stat5;
        break;
    }
    case 3: {
        *lhs = state->fields.mons[U8(state, 0x3cf)].stat3;
        *rhs = state->fields.mons[battler].stat3;
        break;
    }
    default:
        GF_AssertFail();
        break;
    }
}
