#ifndef OVERLAY12_BATTLE_CONTROLLER_CORE_PRIVATE_H
#define OVERLAY12_BATTLE_CONTROLLER_CORE_PRIVATE_H

#include "global.h"

#include "battle/battle_controller.h"
#include "battle/battle_system.h"
#include "battle/overlay_12_0224E4FC.h"

#include "battle_link_internal.h"

BOOL BattleController_RecvData(BattleSystem *bsys, const u8 *data);
void BattleController_SendData(BattleSystem *bsys, int direction, int battlerId, const u8 *data, u8 size);
void ov12_022621C4(BattleSystem *bsys, int direction);
void ov12_02262240(BattleSystem *bsys, int direction, int battlerId, const void *data, u8 size);

#endif
