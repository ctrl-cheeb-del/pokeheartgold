#include "trainer_ai_state_queries_r9_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov10_0221E74C(AiState *state, int battler, int *lhs, int *rhs, int kind);

void ov10_0221E19C(void *bsys, AiState *state) {
    int battler;
    u8 *ptr;
    (void)bsys;
    ov10_0221EF24(state, 1);
    ptr = (u8 *)state + 2 * U8(state, 0x3d0);
    battler = *(u16 *)(ptr + 0x307c);
    ptr = (u8 *)state + 16 * battler;
    S32(state, 0x35c) = *(u8 *)(ptr + 0x3e0);
}
