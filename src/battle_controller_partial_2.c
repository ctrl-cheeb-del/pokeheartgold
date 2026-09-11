#include "battle_controller_partial_internal.h"

void BattleController_EmitTrainerSlideOut(BattleSystem *bsys, int battlerId) {
    u32 buf = 10;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
