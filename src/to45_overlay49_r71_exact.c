#include "to45_overlay49_r71_private.h"
#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void ov49_02265CB0(void *ctx, void *state) {
    VecFx32 pos;
    int i = 0;
    u8 *entry = state;
    entry += 0xC;
    for (; i < 3; i++, entry += 0x78) {
        ov49_02265980(ctx, state, i, &ov49_0226A70C[i + 3]);
        ov49_02259154(PTR(state, 8), &pos);
        pos.y += 0x8000;
        sub_020182A8(entry, pos.x, pos.y, pos.z);
        sub_020182A0(entry, 0);
    }
    WORD(state, 0x954) = 0xFF;
}

void ov49_02265D10(void *ctx, void *state) {
    VecFx32 a;
    VecFx32 b;

    ov49_02265980(ctx, state, 1, ov49_0226A730);
    ov49_02265980(ctx, state, 0, ov49_0226A73C);
    sub_020182A0((u8 *)state + 0x84, 0);
    ov49_02259154(PTR(state, 8), &a);
    a.y += 0x10000;
    a.x += 0x8000;
    b = a;
    b.y += 0x10000;
    WORD(state, 0x958) = 8;

    switch (ov49_02258E60(PTR(state, 8), 6)) {
    case 0:
        a.z -= 0x1C000;
        b.z -= 0xE000;
        sub_020182E0((u8 *)state + 0x84, 0xBFFF, 1);
        break;
    case 1:
        a.z += 0x18000;
        b.z += 0xB000;
        sub_020182E0((u8 *)state + 0x84, 0x3FFF, 1);
        break;
    case 2:
        a.x -= 0x17000;
        b.x -= 0x7000;
        b.z += 0x8000;
        sub_020182E0((u8 *)state + 0x84, 0, 1);
        break;
    case 3:
        a.x += 0x17000;
        b.x += 0x7000;
        b.z += 0x8000;
        sub_020182E0((u8 *)state + 0x84, 0x7FFF, 1);
        break;
    }
    sub_020182A8((u8 *)state + 0x84, a.x, a.y, a.z);
    sub_020182A8((u8 *)state + 0xC, b.x, b.y, b.z);
}

void ov49_02265E54(void *ctx, void *state) {
    VecFx32 a;
    VecFx32 b;

    ov49_02265980(ctx, state, 1, ov49_0226A730);
    ov49_02265980(ctx, state, 0, ov49_0226A73C);
    ov49_02265980(ctx, state, 2, ov49_0226A734);
    sub_020182A0((u8 *)state + 0x84, 0);
    ov49_02259154(PTR(state, 8), &a);
    a.y += 0x10000;
    a.x += 0x8000;
    b = a;
    b.y += 0x10000;
    WORD(state, 0x958) = 8;
    WORD(state, 0x95C) = 8;

    switch (ov49_02258E60(PTR(state, 8), 6)) {
    case 0:
        a.z -= 0x1C000;
        b.z -= 0xE000;
        sub_020182E0((u8 *)state + 0x84, 0xA38D, 1);
        sub_020182E0((u8 *)state + 0xFC, 0xDC70, 1);
        sub_020182A8((u8 *)state + 0x84, a.x + 0x8000, a.y, a.z);
        sub_020182A8((u8 *)state + 0xFC, a.x - 0x8000, a.y, a.z);
        break;
    case 1:
        a.z += 0x18000;
        b.z += 0xB000;
        sub_020182E0((u8 *)state + 0x84, 0x238E, 1);
        sub_020182E0((u8 *)state + 0xFC, 0x5C71, 1);
        sub_020182A8((u8 *)state + 0x84, a.x - 0x8000, a.y, a.z);
        sub_020182A8((u8 *)state + 0xFC, a.x + 0x8000, a.y, a.z);
        break;
    case 2:
        a.x -= 0x17000;
        b.x -= 0x7000;
        b.z += 0x8000;
        sub_020182E0((u8 *)state + 0x84, 0xE38F, 1);
        sub_020182E0((u8 *)state + 0xFC, 0x1C71, 1);
        sub_020182A8((u8 *)state + 0x84, a.x, a.y, a.z - 0x8000);
        sub_020182A8((u8 *)state + 0xFC, a.x, a.y, a.z + 0x8000);
        break;
    case 3:
        a.x += 0x17000;
        b.x += 0x7000;
        b.z += 0x8000;
        sub_020182E0((u8 *)state + 0x84, 0x638D, 1);
        sub_020182E0((u8 *)state + 0xFC, 0x9C71, 1);
        sub_020182A8((u8 *)state + 0x84, a.x, a.y, a.z + 0x8000);
        sub_020182A8((u8 *)state + 0xFC, a.x, a.y, a.z - 0x8000);
        break;
    }
    sub_020182A8((u8 *)state + 0xC, b.x, b.y, b.z);
}

void ov49_02266088(void *ctx, void *state) {
    VecFx32 a;
    VecFx32 b;

    ov49_02265980(ctx, state, 1, ov49_0226A730);
    ov49_02265980(ctx, state, 0, ov49_0226A73C);
    ov49_02265980(ctx, state, 2, ov49_0226A734);
    ov49_02265980(ctx, state, 3, ov49_0226A738);
    sub_020182A0((u8 *)state + 0x84, 0);
    WORD(state, 0x958) = 8;
    WORD(state, 0x95C) = 8;
    WORD(state, 0x960) = 8;
    ov49_02259154(PTR(state, 8), &a);
    a.y += 0x10000;
    a.x += 0x8000;
    b = a;
    b.y += 0x10000;

    switch (ov49_02258E60(PTR(state, 8), 6)) {
    case 0:
        a.z -= 0x1C000;
        b.z -= 0xE000;
        sub_020182E0((u8 *)state + 0x84, 0xA38D, 1);
        sub_020182E0((u8 *)state + 0xFC, 0xDC70, 1);
        sub_020182E0((u8 *)state + 0x174, 0xBFFF, 1);
        sub_020182A8((u8 *)state + 0x84, a.x + 0x8000, a.y, a.z);
        sub_020182A8((u8 *)state + 0xFC, a.x - 0x8000, a.y, a.z);
        sub_020182A8((u8 *)state + 0x174, a.x, a.y, a.z);
        break;
    case 1:
        a.z += 0x18000;
        b.z += 0xB000;
        sub_020182E0((u8 *)state + 0x84, 0x238E, 1);
        sub_020182E0((u8 *)state + 0xFC, 0x5C71, 1);
        sub_020182E0((u8 *)state + 0x174, 0x3FFF, 1);
        sub_020182A8((u8 *)state + 0x84, a.x - 0x8000, a.y, a.z);
        sub_020182A8((u8 *)state + 0xFC, a.x + 0x8000, a.y, a.z);
        sub_020182A8((u8 *)state + 0x174, a.x, a.y, a.z);
        break;
    case 2:
        a.x -= 0x17000;
        b.x -= 0x7000;
        b.z += 0x8000;
        sub_020182E0((u8 *)state + 0x84, 0xE38F, 1);
        sub_020182E0((u8 *)state + 0xFC, 0x1C71, 1);
        sub_020182E0((u8 *)state + 0x174, 0, 1);
        sub_020182A8((u8 *)state + 0x84, a.x, a.y, a.z - 0x8000);
        sub_020182A8((u8 *)state + 0xFC, a.x, a.y, a.z + 0x8000);
        sub_020182A8((u8 *)state + 0x174, a.x, a.y, a.z);
        break;
    case 3:
        a.x += 0x17000;
        b.x += 0x7000;
        b.z += 0x8000;
        sub_020182E0((u8 *)state + 0x84, 0x638D, 1);
        sub_020182E0((u8 *)state + 0xFC, 0x9C71, 1);
        sub_020182E0((u8 *)state + 0x174, 0x7FFF, 1);
        sub_020182A8((u8 *)state + 0x84, a.x, a.y, a.z + 0x8000);
        sub_020182A8((u8 *)state + 0xFC, a.x, a.y, a.z - 0x8000);
        sub_020182A8((u8 *)state + 0x174, a.x, a.y, a.z);
        break;
    }
    sub_020182A8((u8 *)state + 0xC, b.x, b.y, b.z);
}
