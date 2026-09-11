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

u32 ov80_02238034(u32 a0, u32 row, u32 column) {
    u16 low;
    s32 range;

    if (a0 == 0) {
        u32 index = column + 1;
        index += row * 7;
        if (index == 21) {
            return 311;
        }
        if (index == 49) {
            return 312;
        }
    }
    if (row >= 8) {
        row = 7;
    }
    if (column == 6 || column == 13) {
        low = ov80_0223D518[row * 4];
        range = ov80_0223D51A[row * 4] - low;
    } else {
        low = ov80_0223D514[row * 4];
        range = ov80_0223D516[row * 4] - low;
    }
    return low + LCRandom() % range;
}
