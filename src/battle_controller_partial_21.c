#include "battle_controller_partial_internal.h"

void ov12_022645C8(BattleSystem *bsys, int a1, int a2) {
    BattleMsgBuf buf;
    MI_CpuFill8(&buf, 0, sizeof(buf));
    buf.command = 67;
    buf.unk1 = a2;
    ov12_02262240(bsys, 1, 0, &buf, sizeof(buf));
}
