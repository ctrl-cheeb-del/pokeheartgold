#include "battle_controller_partial_internal.h"

void ov12_02263D14(BattleSystem *bsys, int battlerId, int a2, int a3) {
    BattleMsgBuf buf;
    BattleBuffer_Clear(BattleSystem_GetBattleContext(bsys), battlerId);
    buf.command = 43;
    buf.unk2 = a2;
    buf.unk1 = a3;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void BattleController_EmitPlayMosaicAnimation(BattleSystem *bsys, int battlerId, int a2, int a3) {
    BattleMsgBuf8 buf;
    buf.command = 44;
    buf.unk1 = a2;
    buf.unk2 = a3;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
