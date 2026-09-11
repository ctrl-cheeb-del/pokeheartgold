#include "ov80_2238034_partial_internal.h"

void *BattleArcade_NewBattleSetup(void *ctx, void *args);

u8 BattleArcade_GetOpponentMonCount(u8 type, int mode);
u32 ov80_02238370(void);

struct ArcadeCtx38034 {
    u8 pad00[0x10];
    u8 type;
    u8 pad11[0x74 - 0x11];
    void *opponentParty;
    u8 pad78[0x330 - 0x78];
    u8 trainerData[4][0x38];
};

s32 ov80_02238498(void *ctx);

u32 ov80_02238430(void *ctx, u8 value) {
    ov80_02238498(ctx);
    if (value == 28) {
        return 1;
    }
    return 3;
}

u32 ov80_02238444(void *ctx) {
    s32 value;
    s32 result;
    if (U8AT(ctx, 0x10) == 0) {
        u16 *speciesPtr = (u16 *)((u8 *)ctx + 0x78 + U8AT(ctx, 0x11) * 2);
        u16 species = *speciesPtr;
        if ((u16)(species + 0xfec9) <= 1) {
            return 7;
        }
    }
    value = ov80_02238498(ctx);
    result = 7;
    switch (value) {
    case -1:
        break;
    case 0:
    case 1:
        result = 0;
        break;
    case 2:
    case 3:
        result = 1;
        break;
    }
    return result;
}

s32 ov80_02238498(void *ctx) {
    u16 value = U16AT(ctx, 0x1a);
    if (BattleArcade_MultiplayerCheck(U8AT(ctx, 0x10)) == 1) {
        u16 multi = U16AT(ctx, 0xa76);
        if (multi > U16AT(ctx, 0x1a)) {
            value = multi;
        }
    }
    return value;
}

u32 ov80_022384BC(u8 value) {
    if (value < 9) {
        return 0;
    }
    if (value < 18) {
        return 1;
    }
    if (value < 27) {
        return 2;
    }
    return 3;
}
