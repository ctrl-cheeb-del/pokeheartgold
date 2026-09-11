#include "battle_controller_partial_internal.h"

void BattleController_EmitBlankMessage(BattleSystem *bsys) {
    u32 buf = 66;
    ov12_02262240(bsys, 1, 0, &buf, sizeof(buf));
}

void ov12_0226430C(BattleSystem *bsys, int battlerId, int a2) {
    BattleMsgBuf buf;
    buf.command = a2;
    buf.unk1 = sub_0203769C();
    ov12_02262240(bsys, 2, battlerId, &buf, sizeof(buf));
}
