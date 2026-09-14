#include "overlay12_battle_controller_core_private.h"

typedef struct BattleControllerPokemonEncounter {
    u8 command;
    u8 gender : 2;
    u8 shiny : 1;
    u8 form : 5;
    u16 species;
    u32 personality;
    u32 battlerType;
    u16 moves[4];
    u16 movePPCur[4];
    u16 movePP[4];
    u8 data[0x18];
} BattleControllerPokemonEncounter;

typedef struct BattleControllerPokemonSlideIn {
    u8 command;
    u8 gender : 2;
    u8 shiny : 1;
    u8 form : 5;
    u16 species;
    u32 personality;
    u32 battlerType;
    u32 selectedMonIndex;
    u32 ball;
    u8 padding[4];
    u16 moves[4];
    u16 movePPCur[4];
    u16 movePP[4];
    u8 data[0x18];
    u32 partnerSelectedMonIndex;
    u8 tail[0x28];
} BattleControllerPokemonSlideIn;

void BattleController_EmitPokemonEncounter(BattleSystem *battleSystem, int battlerId) {
    BattleControllerPokemonEncounter buffer;
    int i;

    buffer.command = 2;
    buffer.gender = battleSystem->ctx->battleMons[battlerId].gender;
    buffer.shiny = battleSystem->ctx->battleMons[battlerId].shiny;
    buffer.species = battleSystem->ctx->battleMons[battlerId].species;
    buffer.personality = battleSystem->ctx->battleMons[battlerId].personality;
    buffer.battlerType = ov12_02256748(battleSystem->ctx, battlerId, ov12_0223AB0C(battleSystem, battlerId), TRUE);
    buffer.form = battleSystem->ctx->battleMons[battlerId].form;
    for (i = 0; i < 4; i++) {
        buffer.moves[i] = GetBattlerVar(battleSystem->ctx, battlerId, i + 6, NULL);
        buffer.movePPCur[i] = GetBattlerVar(battleSystem->ctx, battlerId, i + 0x1F, NULL);
        buffer.movePP[i] = GetBattlerVar(battleSystem->ctx, battlerId, i + 0x27, NULL);
    }
    GetBattlerVar(battleSystem->ctx, battlerId, 0x2D, buffer.data);
    ov12_02262240(battleSystem, 1, battlerId, &buffer, sizeof(buffer));
}

void BattleController_EmitPokemonSlideIn(BattleSystem *battleSystem, int battlerId) {
    BattleControllerPokemonSlideIn buffer;
    int i;

    buffer.command = 3;
    buffer.gender = battleSystem->ctx->battleMons[battlerId].gender;
    buffer.shiny = battleSystem->ctx->battleMons[battlerId].shiny;
    buffer.species = battleSystem->ctx->battleMons[battlerId].species;
    buffer.personality = battleSystem->ctx->battleMons[battlerId].personality;
    buffer.battlerType = ov12_02256748(battleSystem->ctx, battlerId, ov12_0223AB0C(battleSystem, battlerId), TRUE);
    buffer.selectedMonIndex = battleSystem->ctx->selectedMonIndex[battlerId];
    buffer.form = battleSystem->ctx->battleMons[battlerId].form;
    buffer.ball = battleSystem->ctx->battleMons[battlerId].ball;
    buffer.partnerSelectedMonIndex = battleSystem->ctx->selectedMonIndex[BattleSystem_GetBattlerIdPartner(battleSystem, battlerId)];
    ov12_0223B854(battleSystem, battlerId, buffer.selectedMonIndex);
    for (i = 0; i < 4; i++) {
        buffer.moves[i] = GetBattlerVar(battleSystem->ctx, battlerId, i + 6, NULL);
        buffer.movePPCur[i] = GetBattlerVar(battleSystem->ctx, battlerId, i + 0x1F, NULL);
        buffer.movePP[i] = GetBattlerVar(battleSystem->ctx, battlerId, i + 0x27, NULL);
    }
    GetBattlerVar(battleSystem->ctx, battlerId, 0x2D, buffer.data);
    ov12_02262240(battleSystem, 1, battlerId, &buffer, sizeof(buffer));
}
