#include "battle_controller_partial_internal.h"

void BattleController_EmitBackgroundSlideIn(BattleSystem *bsys, int battlerId) {
    u32 buf = 40;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void ov12_02263CCC(BattleSystem *bsys, int battlerId) {
    u32 buf = 41;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
