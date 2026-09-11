#include "battle_controller_partial_internal.h"

void BattleController_EmitHealthbarStatus(BattleSystem *bsys, int battlerId, int a2) {
    BattleMsgBuf buf;
    buf.command = 30;
    buf.unk1 = a2;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void BattleController_EmitPrintTrainerMessage(BattleSystem *bsys, int battlerId, int a2) {
    BattleMsgBuf buf;
    buf.command = 31;
    buf.unk1 = a2;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void BattleController_EmitSetStatus2Effect(BattleSystem *bsys, BattleContext *ctx, int battlerId, int a3) {
    u8 buf[0x58];
    ov12_022643C8(bsys, ctx, buf, 1, a3, battlerId, battlerId, 0);
    ov12_02262240(bsys, 1, battlerId, buf, sizeof(buf));
}

void BattleController_EmitCopyStatus2Effect(BattleSystem *bsys, BattleContext *ctx, int battlerId, int a3, int a4) {
    u8 buf[0x58];
    ov12_022643C8(bsys, ctx, buf, 1, a4, battlerId, a3, 0);
    ov12_02262240(bsys, 1, battlerId, buf, sizeof(buf));
}
