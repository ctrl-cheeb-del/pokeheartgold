#include "overlay12_2265e28_sol_partial_internal.h"

void ov12_02265F34(UnkBattleSystemSub17C *work) {
    SpriteSystem *spriteSystem = BattleSystem_GetSpriteSystem(work->battleSystem);
    SpriteManager *spriteManager = BattleSystem_GetSpriteManager(work->battleSystem);
    work->unk0 = SpriteSystem_NewSprite(spriteSystem, spriteManager, &ov12_0226E100[work->unk8]);
    Sprite_TickFrame(work->unk0->sprite);
}

void ov12_02265F68(UnkBattleSystemSub17C *work) {
    if (work->unk0 != NULL) {
        Sprite_DeleteAndFreeResources(work->unk0);
        work->unk0 = NULL;
    }
}

void ov12_02265F7C(UnkBattleSystemSub17C *work) {
    SpriteManager *spriteManager = BattleSystem_GetSpriteManager(work->battleSystem);
    u32 charId;
    u32 cellAnimId;

    if (work->unk8 == 0) {
        charId = 0x4E2D;
    } else {
        charId = 0x4E2E;
    }
    cellAnimId = charId - 8;
    SpriteManager_UnloadCharObjById(spriteManager, charId);
    SpriteManager_UnloadPlttObjById(spriteManager, 0x4E29);
    SpriteManager_UnloadCellObjById(spriteManager, cellAnimId);
    SpriteManager_UnloadAnimObjById(spriteManager, cellAnimId);
}

void ov12_02265FC4(UnkBattleSystemSub17C *work, s32 draw) {
    if (work->unk0 != NULL) {
        ManagedSprite_SetDrawFlag(work->unk0, draw);
    }
}

void ov12_02265FD4(UnkBattleSystemSub17C *work, BattleSystem *battleSystem, int side, int battler) {
    MI_CpuClearFast(work, sizeof(*work));
    work->battleSystem = battleSystem;
    work->unk8 = side;
    work->unk9 = battler;
    if (battler >= 24) {
        GF_AssertFail();
        work->unk9 = 0;
    }
    ov12_02265E28(work);
    ov12_02265F34(work);
}

void ov12_02266008(UnkBattleSystemSub17C *work) {
    ov12_02265F68(work);
    ov12_02265F7C(work);
    MI_CpuClearFast(work, sizeof(*work));
}
