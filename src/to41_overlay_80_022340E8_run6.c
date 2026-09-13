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

void ov80_02234CB0(void *ctx, void *manager, u32 side) {
    u8 *p = ctx;
    s32 ownCount = BattleArcade_GetMonCount(p[0x10], 1);
    s32 opponentCount = BattleArcade_GetOpponentMonCount(p[0x10], 1);
    s32 i;
    if (side == 0) {
        for (i = 0; i < ownCount; i++) {
            ov80_0222F440(manager, *(void **)(p + 0x50));
            p += 4;
        }
    } else {
        for (i = 0; i < opponentCount; i++) {
            ov80_0222F440(manager, *(void **)(p + 0x60));
            p += 4;
        }
    }
}

void ov80_02234D04(void *ctx, void *unused, u32 side, s32 index, u16 enabled) {
    u8 *p = ctx;
    s32 ownCount = BattleArcade_GetMonCount(p[0x10], 1);
    s32 opponentCount = BattleArcade_GetOpponentMonCount(p[0x10], 1);
    if (side == 0) {
        if (index < ownCount) {
            u32 species = GetMonData(Party_GetMonByIndex(*(void **)(p + 0x70), index), 6, NULL);
            if (enabled == 1) {
                if (species == 0) {
                    Sprite_SetDrawFlag(**(void ***)(p + 0x50 + index * 4), FALSE);
                } else {
                    Sprite_SetDrawFlag(**(void ***)(p + 0x50 + index * 4), TRUE);
                }
            } else {
                Sprite_SetDrawFlag(**(void ***)(p + 0x50 + index * 4), FALSE);
            }
        }
    } else {
        if (index < opponentCount) {
            u32 species = GetMonData(Party_GetMonByIndex(*(void **)(p + 0x74), index), 6, NULL);
            if (enabled == 1) {
                if (species == 0) {
                    Sprite_SetDrawFlag(**(void ***)(p + 0x60 + index * 4), FALSE);
                } else {
                    Sprite_SetDrawFlag(**(void ***)(p + 0x60 + index * 4), TRUE);
                }
            } else {
                Sprite_SetDrawFlag(**(void ***)(p + 0x60 + index * 4), FALSE);
            }
        }
    }
}
