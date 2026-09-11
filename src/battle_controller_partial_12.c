#include "battle_controller_partial_internal.h"

void BattleController_EmitPrintEncounterMessage(BattleSystem *bsys, int a1, int battlerId) {
    u32 buf = 34;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
