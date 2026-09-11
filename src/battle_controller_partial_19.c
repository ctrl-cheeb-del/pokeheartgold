#include "battle_controller_partial_internal.h"

void BattleController_EmitPlaySong(BattleSystem *bsys, int battlerId, int a2) {
    BattleMsgBuf buf;
    buf.command = 64;
    buf.unk2 = a2;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
