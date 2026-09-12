#include "trainer_ai_state_queries_r9_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov10_0221E74C(AiState *state, int battler, int *lhs, int *rhs, int kind);

void ov10_0221E9A4(void *bsys, AiState *state) {
    int battlerCode, result;
    u32 mask;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battlerCode = ov10_0221EEF0(state);
    result = ov10_0221EEF0(state);
    if (battlerCode == 1) {
        GF_AssertFail();
    }
    if (battlerCode == 0) {
        GF_AssertFail();
    }
    mask = MaskOfFlagNo(ov10_0221EF34(state, (u8)battlerCode));
    if ((mask & U8(state, 0x3108)) != 0) {
        ov10_0221EF24(state, result);
    }
}

void ov10_0221E9F4(void *bsys, AiState *state) {
    int battlerCode, result;
    u32 mask;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battlerCode = ov10_0221EEF0(state);
    result = ov10_0221EEF0(state);
    if (battlerCode == 1) {
        GF_AssertFail();
    }
    if (battlerCode == 0) {
        GF_AssertFail();
    }
    mask = MaskOfFlagNo(ov10_0221EF34(state, (u8)battlerCode));
    if ((mask & U8(state, 0x3108)) == 0) {
        ov10_0221EF24(state, result);
    }
}

void ov10_0221EA44(void *bsys, AiState *state) {
    int battler;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battler = ov10_0221EF34(state, (u8)ov10_0221EEF0(state));
    S32(state, 0x35c) = state->fields.mons[battler].flags;
}

void ov10_0221EA7C(void *bsys, AiState *state) {
    int battler;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battler = ov10_0221EF34(state, (u8)ov10_0221EEF0(state));
    if (*(s32 *)((u8 *)state + 0xc0 * battler + 0x2dd4) < S32(state, 0x150)) {
        S32(state, 0x35c) = 0;
    } else {
        S32(state, 0x35c) = 1;
    }
}
