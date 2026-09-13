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

void BattleArcadeData_Init(void *ctx, u32 mode) {
    if (mode == 0) {
        ov80_02234390(ctx);
    } else {
        ov80_02234424(ctx);
    }
}

void ov80_02234390(void *ctx) {
    u8 *p = ctx;
    s32 rank = ov80_02238498(ctx);
    u8 index;
    u32 count;
    u32 multiplayer;
    void *lastPtr;
    u32 i;
    ov80_022380A0(p[0x10], rank, p + 0x78, 14);
    index = p[0x11];
    count = BattleArcade_GetOpponentMonCount(p[0x10], 1);
    multiplayer = BattleArcade_MultiplayerCheck(p[0x10]);
    lastPtr = p + 0x320;
    ov80_0222A6B8(count, *(u16 *)(p + 0x78 + index * 2), *(u16 *)(p + 0x78 + (index + 7) * 2), p + 0x314, p + 0x330, p + 0x31C, lastPtr, multiplayer);
    rank = ov80_02238498(ctx);
    for (i = 0; i < 3; i++) {
        if (rank >= ov80_0223BE98[i * 2]) {
            p[0x1C] = ov80_0223BE98[i * 2 + 1];
            return;
        }
    }
}
