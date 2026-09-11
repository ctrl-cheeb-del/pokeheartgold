#include "battle_controller_partial_internal.h"

void BattleController_EmitSetBattleBackground(BattleSystem *bsys, int battlerId) {
    u32 buf = 46;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void ov12_02263E18(BattleSystem *bsys, int battlerId) {
    u32 buf = 47;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void BattleController_EmitInitStartBallGauge(BattleSystem *bsys, int battlerId) {
    u8 buf[8];
    ov12_022645F8(bsys, bsys->ctx, buf, 0x30, battlerId);
    ov12_02262240(bsys, 1, battlerId, buf, sizeof(buf));
}

void BattleController_EmitDeleteStartBallGauge(BattleSystem *bsys, int battlerId) {
    u8 buf[8];
    ov12_022645F8(bsys, bsys->ctx, buf, 0x31, battlerId);
    ov12_02262240(bsys, 1, battlerId, buf, sizeof(buf));
}

void BattleController_EmitInitBallGauge(BattleSystem *bsys, int battlerId) {
    u8 buf[8];
    ov12_022645F8(bsys, bsys->ctx, buf, 0x32, battlerId);
    ov12_02262240(bsys, 1, battlerId, buf, sizeof(buf));
}

void BattleController_EmitDeleteBallGauge(BattleSystem *bsys, int battlerId) {
    u8 buf[8];
    ov12_022645F8(bsys, bsys->ctx, buf, 0x33, battlerId);
    ov12_02262240(bsys, 1, battlerId, buf, sizeof(buf));
}

void BattleController_EmitLoadBallGfx(BattleSystem *bsys) {
    u32 buf = 52;
    ov12_02262240(bsys, 1, 0, &buf, sizeof(buf));
}

void BattleController_EmitDeleteBallGfx(BattleSystem *bsys) {
    u32 buf = 53;
    ov12_02262240(bsys, 1, 0, &buf, sizeof(buf));
}

void BattleController_EmitIncrementGameStat(BattleSystem *bsys, int battlerId, int a2, int a3) {
    BattleMsgBuf buf;
    buf.command = 54;
    buf.unk1 = a2;
    buf.unk2 = a3;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
