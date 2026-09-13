#include "constants/battle.h"

#include "battle/battle_022378C0.h"
#include "battle/battle_022378C0_tail_private.h"
#include "battle/battle_controller_player.h"
#include "battle/battle_system.h"
#include "battle/overlay_12_0224E4FC.h"

#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "palette.h"
#include "render_window.h"
#include "unk_0200FA24.h"

void ov12_02237D00(BattleSystem *battleSystem);
void ov12_02237ED0(BattleSystem *battleSystem, int a1);
void ov12_022387AC(BattleSystem *battleSystem, BgConfig *bgConfig);
void ov12_022389B8(BattleSystem *battleSystem);

BOOL ov12_02238358(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_GetData(man);
    int i;

    if ((battleSystem->battleType & BATTLE_TYPE_LINK) && !(battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING)) {
        if (battleSystem->unk23FC) {
            BattleContext_Main(battleSystem, battleSystem->ctx);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            ov12_02258E54(battleSystem, battleSystem->opponentData[i]);
        }
    } else {
        if (battleSystem->unk23FC) {
            battleSystem->unk23FE = BattleContext_Main(battleSystem, battleSystem->ctx);
            ov12_022621C4(battleSystem, 1);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            ov12_02258E54(battleSystem, battleSystem->opponentData[i]);
            ov12_022621C4(battleSystem, 0);
        }
        if (!battleSystem->unk23FE) {
            if (battleSystem->unk23FC) {
                battleSystem->unk23FE = BattleContext_Main(battleSystem, battleSystem->ctx);
                ov12_022621C4(battleSystem, 1);
            }
            for (i = 0; i < battleSystem->maxBattlers; i++) {
                ov12_02258E54(battleSystem, battleSystem->opponentData[i]);
                ov12_022621C4(battleSystem, 0);
            }
        }
    }

    return battleSystem->unk23FE;
}
