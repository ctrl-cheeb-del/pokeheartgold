#include "overlay49_state_dispatch_r40_30_private.h"

extern void ov49_0225BA20(u8 *state, u32 value);
extern void ov49_0225C970(void *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void ov49_0225CA30(void *work, u32 a1, u32 a2, u32 a3, u32 a4);

void ov49_0225B9AC(u8 *state, u32 a1, u32 a2, u32 a3, u32 a4) {
    if (state[1] == 1 || state[1] == 3 || state[1] == 4) {
        ov49_0225BA20(state, a1);
    }
    ov49_0225C970(state + 0x114, a1, a2, a4, *(u32 *)(state + 0x14C), a3);
    state[1] = 1;
}

void ov49_0225B9F0(u8 *state, u32 a1, u32 a2, u32 a3) {
    if (state[1] == 3) {
        ov49_0225BA20(state, a1);
    }
    ov49_0225CA30(state + 0x114, a1, a3, *(u32 *)(state + 0x14C), a2);
    state[1] = 3;
}
