#include "battle_controller_partial_internal.h"

void ov12_02263360(BattleSystem *bsys, int battlerId, u32 msg) {
    ov12_02262240(bsys, 0, battlerId, &msg, sizeof(msg));
}
