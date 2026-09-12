#include "trainer_ai_state_queries_r9_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov10_0221E74C(AiState *state, int battler, int *lhs, int *rhs, int kind);

void ov10_0221E290(void *bsys, AiState *state) {
    int battler;
    (void)bsys;
    ov10_0221EF24(state, 1);
    battler = ov10_0221EF34(state, (u8)ov10_0221EEF0(state));
    S32(state, 0x35c) = S32(state, 0x150) - *(s32 *)((u8 *)state + 0xc0 * battler + 0x2dd4);
}
