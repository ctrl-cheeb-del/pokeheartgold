#include "battle_controller_partial_internal.h"

void ov12_02263A00(BattleSystem *bsys, int battlerId) {
    u32 buf = 1;
    ov12_02262240(bsys, 0, battlerId, &buf, sizeof(buf));
}
