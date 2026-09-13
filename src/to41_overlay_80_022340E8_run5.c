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

void ov80_02234B24(void *ctx, void *manager, u32 side) {
    u8 *p = ctx;
    s32 ownCount = BattleArcade_GetMonCount(p[0x10], 1);
    s32 opponentCount = BattleArcade_GetOpponentMonCount(p[0x10], 1);
    s32 i;
    if (side == 0) {
        for (i = 0; i < ownCount; i++) {
            ov80_0222F324(manager, *(void **)(p + 0x30), i);
            p += 4;
        }
    } else {
        for (i = 0; i < opponentCount; i++) {
            ov80_0222F324(manager, *(void **)(p + 0x40), ownCount);
            ownCount++;
            p += 4;
        }
    }
}

void ov80_02234B7C(void *ctx, void *unused, u32 show, s32 index) {
    u8 *p = ctx;
    if (index < (s32)BattleArcade_GetMonCount(p[0x10], 1)) {
        if (show == 1) {
            void *sprite = *(void **)(p + 0x30 + index * 4);
            Sprite_SetDrawFlag(*(void **)sprite, TRUE);
        } else {
            void *sprite = *(void **)(p + 0x30 + index * 4);
            Sprite_SetDrawFlag(*(void **)sprite, FALSE);
        }
    }
}

void ov80_02234BB4(void *ctx, void *unused, u32 show, s32 index) {
    u8 *p = ctx;
    if (index < (s32)BattleArcade_GetOpponentMonCount(p[0x10], 1)) {
        if (show == 1) {
            void *sprite = *(void **)(p + 0x40 + index * 4);
            Sprite_SetDrawFlag(*(void **)sprite, TRUE);
        } else {
            void *sprite = *(void **)(p + 0x40 + index * 4);
            Sprite_SetDrawFlag(*(void **)sprite, FALSE);
        }
    }
}
