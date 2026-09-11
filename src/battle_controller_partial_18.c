#include "battle_controller_partial_internal.h"

void ov12_02264038(BattleSystem *bsys, int battlerId) {
    u32 buf = 57;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void ov12_02264054(BattleSystem *bsys, int battlerId) {
    u32 buf = 58;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}

void BattleController_EmitPrintResultMessage(BattleSystem *bsys) {
    u32 buf = 59;
    ov12_02262240(bsys, 1, 0, &buf, sizeof(buf));
}
