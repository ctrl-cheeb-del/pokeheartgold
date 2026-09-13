#ifndef POKEHEARTGOLD_BATTLE_022378C0_TAIL_PRIVATE_H
#define POKEHEARTGOLD_BATTLE_022378C0_TAIL_PRIVATE_H

#include "battle/battle.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
#include "overlay_manager.h"
#include "poke_overlay.h"

FS_EXTERN_OVERLAY(OVY_7);
FS_EXTERN_OVERLAY(OVY_10);

typedef struct BattleBgTemplateSet {
    BgTemplate templates[3];
} BattleBgTemplateSet;

extern const BattleBgTemplateSet ov12_0226C120;
extern const BattleBgTemplateSet ov12_0226C174;
extern const GraphicsBanks ov12_0226C0A8;
extern const GraphicsModes ov12_0226BFE8;

void ov12_02239730(void *arg);

void ov12_02265FD4(UnkBattleSystemSub17C *dest, BattleSystem *battleSystem, s32 idx, s32 terrain);
void ov12_02258DB0(BattleSystem *battleSystem, OpponentData *opponentData, u16 ball, int a3);
void ov12_02258E54(BattleSystem *battleSystem, OpponentData *opponentData);
void ov12_022621C4(BattleSystem *battleSystem, int a1);
void ov12_0223A7A0(void);
void ov12_022387AC(BattleSystem *battleSystem, BgConfig *bgConfig);
void BgConfig_InitBattleMenuBackgrounds(BgConfig *bgConfig);
void sub_0200EB80(BgConfig *bgConfig, u8 bgId, u16 baseTile, u8 color, u8 type, enum HeapID heapId);
u32 sub_0200E640(u32 frame);
void ov12_022389B8(BattleSystem *battleSystem);

#endif
