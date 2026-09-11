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

u32 ov80_02238370(void) {
    return 50;
}

BOOL BattleArcade_MultiplayerCheck(u8 type) {
    switch (type) {
    case 2:
    case 3:
        return TRUE;
    default:
        return FALSE;
    }
}

void ov80_02238384(void *ctx, void *mon) {
    void *profile = Save_PlayerData_GetProfile(PAT(ctx, 4));
    sub_0207217C(mon, profile, 4, 0, 0, 11);
}

void ov80_022383A8(void *ctx, void *party, void *mon) {
    ov80_02238384(ctx, mon);
    Party_AddMon(party, mon);
}
