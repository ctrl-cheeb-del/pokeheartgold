#ifndef TO30_OVERLAY_12_02265E28_PRIVATE_H
#define TO30_OVERLAY_12_02265E28_PRIVATE_H

#include "global.h"

#include "battle/battle.h"
#include "battle/battle_system.h"

#include "filesystem.h"
#include "palette.h"
#include "sprite_system.h"

extern const u16 ov12_0226E0A0[24];
extern const u16 ov12_0226E0D0[24];
extern const ManagedSpriteTemplate ov12_0226E100[2];
extern const u16 ov12_0226E168[];

void ov12_02265E28(UnkBattleSystemSub17C *work);
void ov12_02265F34(UnkBattleSystemSub17C *work);
void ov12_02265F68(UnkBattleSystemSub17C *work);
void ov12_02265F7C(UnkBattleSystemSub17C *work);
void ov12_02265FC4(UnkBattleSystemSub17C *work, s32 draw);
void ov12_02265FD4(UnkBattleSystemSub17C *work, BattleSystem *battleSystem, int side, int battler);
void ov12_02266008(UnkBattleSystemSub17C *work);

#endif
