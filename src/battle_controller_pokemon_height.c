#include "overlay12_battle_controller_core_private.h"
#include "pokemon.h"

typedef struct BattleControllerPokemonHeight {
    u8 command;
    u8 height;
    u16 ball;
} BattleControllerPokemonHeight;

void ov12_022628A0(BattleSystem *battleSystem, s32 battlerId, s32 ball) {
    BattleControllerPokemonHeight buffer;
    int form;
    int facing;

    facing = battleSystem->opponentData[battlerId]->battlerType & 1 ? 2 : 0;
    form = battleSystem->ctx->battleMons[battlerId].form;
    buffer.command = 6;
    if (battleSystem->ctx->battleMons[battlerId].status2 & 0x200000) {
        buffer.height = GetMonPicHeightBySpeciesGenderForm(battleSystem->ctx->battleMons[battlerId].species, battleSystem->ctx->battleMons[battlerId].unk88.transformGender, facing, form, battleSystem->ctx->battleMons[battlerId].unk88.transformPersonality);
    } else {
        buffer.height = GetMonPicHeightBySpeciesGenderForm(battleSystem->ctx->battleMons[battlerId].species, battleSystem->ctx->battleMons[battlerId].gender, facing, form, battleSystem->ctx->battleMons[battlerId].personality);
    }
    buffer.ball = ball;
    ov12_02262240(battleSystem, 1, battlerId, &buffer, sizeof(buffer));
}
