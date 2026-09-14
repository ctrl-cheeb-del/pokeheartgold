#include "to45_overlay49_r73_private.h"

#pragma require_prototypes off

void ov49_02266C6C(void *ctx, void *state) {
    VecFx32 v;
    u8 value;
    float delta;

    ov49_02259154(*(void **)((u8 *)state + 8), &v);
    value = ov49_0226A450[S8_AT(state, 0x955) - 1];
    if (value != 0) {
        delta = (float)(value << 12) + 0.5f;
    } else {
        delta = (float)(value << 12) - 0.5f;
    }
    ov49_0226540C((u8 *)state + 0xA04, v.x, v.x, v.y, v.y + (fx32)delta, v.z, v.z, 0x6C);
    ov49_022655F4((u8 *)state + 0xA2C, 0, 0x71C, 0x8000);
    ov49_0226747C(state);
    *(u16 *)((u8 *)state + 0x956) = 0;
}

void ov49_02266D04(void *ctx, void *state) {
    VecFx32 v;
    ov49_02259154(*(void **)((u8 *)state + 8), &v);
    ov49_0226540C((u8 *)state + 0xA04, v.x, v.x, v.y, v.y + 0x2000, v.z, v.z, 2);
    ov49_022655F4((u8 *)state + 0xA2C, 0, 0x71C, 0);
    ov49_02267674(state);
    *(u16 *)((u8 *)state + 0x956) = 0;
}

u32 ov49_02266D60(void *ctx, void *state) {
    if (U8_AT(state, 0x965) == 0) {
        return ov49_02266D7C(ctx, state);
    }
    return ov49_02266E78(ctx, state);
}

u32 ov49_02266D7C(void *ctx, void *state) {
    VecFx32 v;
    fx32 delta;
    u32 result;
    int i;

    result = ov49_02265434((u8 *)state + 0xA04, S16_AT(state, 0x956));
    ov49_02265628((u8 *)state + 0xA2C);
    S16_AT(state, 0x956)
    ++;
    ov49_02259154(*(void **)((u8 *)state + 8), &v);
    ov49_022655E0((u8 *)state + 0xA04, &v.x, &v.y, &v.z);
    ov49_02265660((u8 *)state + 0xA2C, &delta);
    if (result == 0) {
        v.x += delta;
    }
    ov49_02259148(*(void **)((u8 *)state + 8), &v);
    ov49_0226747C(state);
    for (i = 0; i < S8_AT(state, 0x955); i++) {
        ov49_0226789C(ctx, state, i);
    }
    if (*(void **)((u8 *)state + 8) == ov49_02258DAC(*(void **)((u8 *)ctx + 4))) {
        u32 keys = gSystem.newKeys;
        u32 direction = 4;
        UnkStruct_ov44_02232914 position;
        u32 packed;

        if (keys & 0x40) {
            direction = 0;
        }
        if (keys & 0x80) {
            direction = 1;
        }
        if (keys & 0x10) {
            direction = 3;
        }
        if (keys & 0x20) {
            direction = 2;
        }
        if (direction != 4) {
            ov49_02259160(*(void **)((u8 *)state + 8), direction);
            packed = ov49_02258E34(*(void **)((u8 *)state + 8));
            position.unk0 = (s16)packed;
            position.unk2 = (s16)(packed >> 16);
            ov49_02258E04(*(void **)((u8 *)state + 8), position, direction);
        }
    }
    return result;
}
