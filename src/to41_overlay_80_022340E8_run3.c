#include "to41_overlay_80_022340E8_private.h"

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

u8 ov80_02234764(void *ctx) {
    u8 *p = ctx;
    p[0x11]++;
    return p[0x11];
}

u8 ov80_02234770(const void *ctx) {
    return ((const u8 *)ctx)[0x11];
}

void ov80_02234774(void *ctx, u32 index) {
    u8 work[0x30];
    u8 *p = ctx;
    u8 item = ov80_022347A8(ctx, index);
    void *allocated = ov80_02229F04(work, *(u16 *)(p + 0x78 + item * 2), 11, 0xCC);
    Heap_Free(allocated);
    ov80_0222A30C((u8) * (u16 *)(work + 4));
}

u16 ov80_022347A8(const void *ctx, u32 index) {
    return (u16)(((const u8 *)ctx)[0x11] + index * 7);
}

void ov80_022347B8(void *ctx) {
    ov80_02234588(ctx, 1);
}

void ov80_022347C4(void *ctx) {
    u8 *p = ctx;
    p[0x2F] = 1;
    if (*(u16 *)(p + 0x1A) < 8) {
        (*(u16 *)(p + 0x1A))++;
    }
    p[0x11] = 0;
    ov80_02234588(ctx, 0);
}

void BattleArcade_SetPartyBeforeBattle(void *ctx) {
    ov80_022383C0(ctx);
}

void BattleArcade_SetPartyAfterBattle(void *ctx) {
    u8 *p = ctx;
    u8 index = p[0x11];
    u32 count = BattleArcade_GetOpponentMonCount(p[0x10], 1);
    u32 multiplayer;
    void *lastPtr;
    multiplayer = BattleArcade_MultiplayerCheck(p[0x10]);
    lastPtr = p + 0x320;
    ov80_0222A6B8(count, *(u16 *)(p + 0x78 + index * 2), *(u16 *)(p + 0x78 + (index + 7) * 2), p + 0x314, p + 0x330, p + 0x31C, lastPtr, multiplayer);
    ov80_022383C0(ctx);
}

u32 BattleArcade_GetWonBattlePoints(void *ctx, void *party, void *otherParty, s32 rank) {
    u8 *p = ctx;
    u32 result = 0;
    u32 count = BattleArcade_GetMonCount(p[0x10], 0);
    s32 i;
    result += ov80_02234894(ctx, party, otherParty, count);
    for (i = 0; i < 5; i++) {
        if (rank < ov80_0223BE9E[i * 2]) {
            result += ov80_0223BE9E[i * 2 + 1];
            break;
        }
    }
    return result;
}
