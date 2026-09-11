#include "battle_controller_partial_internal.h"

void ov12_0226399C(BattleSystem *bsys, int battlerId) {
    u32 buf = 36;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
