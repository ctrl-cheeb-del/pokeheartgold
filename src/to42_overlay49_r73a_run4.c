#include "to42_overlay49_r73a_private.h"

#pragma require_prototypes off

u32 ov49_0226786C(void *ctx, void *state, u32 idx, u8 val) {
    if (val != U8_AT((u8 *)state + 0x960, idx)) {
        U8_AT((u8 *)state + 0x960, idx) = val;
        U8_AT((u8 *)state + idx, 0x95C) = 0;
        ov49_02265BE8(ctx, state, idx, 0, val << 13);
        return 1;
    }
    return 0;
}

void ov49_0226789C(void *ctx, void *state, u32 idx) {
    u8 kind = U8_AT((u8 *)state + idx, 0x960);
    u8 *timer = (u8 *)state + 0x95C;
    u32 value;

    if (timer[idx] == 0) {
        value = ov49_02265C40(ctx, state, idx, 0);
        if (value == (kind << 13)) {
            value = (kind << 13) + 0x1000;
        } else if (kind != 4) {
            value = kind << 13;
        } else {
            sub_020182A0(&OV49_ENTRIES(state)[idx], 0);
        }
        ov49_02265BE8(ctx, state, idx, 0, value);
        timer[idx] = 8;
    }
    timer[idx]--;
}

void ov49_02267908(void *ctx, void *state, u32 count) {
    VecFx32 base;
    VecFx32 a;
    VecFx32 b;
    u32 i;
    int j;

    ov49_02259154((void *)U32_AT(state, 8), &base);
    for (i = 0; i < count; i++) {
        u32 baseIdx = i * 4;
        u32 tableIdx = i + 13;
        if (tableIdx > 15) {
            tableIdx = 15;
        }
        for (j = 0; j < 4; j++) {
            u32 idx = j + baseIdx;
            ov49_02265980(ctx, state, idx, &ov49_0226A70C[tableIdx]);
            VEC_Add(&base, &ov49_0226A4D8[j], &a);
            VEC_Add(&a, &ov49_0226A508[j], &b);
            sub_020182A8(&OV49_ENTRIES(state)[idx], a.x, a.y, a.z);
            sub_020182A0(&OV49_ENTRIES(state)[idx], 0);
            U8_AT((u8 *)state + 0x958, idx) = 0;
            ov49_0226540C((u8 *)state + 0x968 + idx * 0x28, a.x, b.x, a.y, b.y, a.z, b.z, 14);
        }
    }
    U8_AT(state, 0x956) = count;
    U8_AT(state, 0x955) = 0;
    U8_AT(state, 0x954) = 0;
    U8_AT(state, 0x957) = 0;
}
