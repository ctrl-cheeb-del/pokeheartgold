#include "battle_controller_partial_internal.h"

void BattleController_EmitPlaySE(BattleSystem *bsys, int a1, int a2, int battlerId) {
    BattleMsgBuf buf;
    buf.command = 27;
    buf.unk2 = a2;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void BattleController_EmitFadeOutBattle(BattleSystem *bsys) {
    u32 buf = 28;
    ov12_02262240(bsys, 1, 0, &buf, sizeof(buf));
}
