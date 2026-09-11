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

u8 BattleArcade_GetMonCount(u8 type, int mode) {
    switch (type) {
    case 0:
    case 1:
        return 3;
    case 2:
    case 3:
        if (mode == 0) {
            return 2;
        }
        return 4;
    default:
        GF_AssertFail();
        return 3;
    }
}

u8 BattleArcade_GetOpponentMonCount(u8 type, int mode) {
    switch (type) {
    case 0:
    case 1:
        return 3;
    case 2:
    case 3:
        if (mode == 0) {
            return 2;
        }
        return 4;
    default:
        GF_AssertFail();
        return 3;
    }
}
