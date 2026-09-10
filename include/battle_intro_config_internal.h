#ifndef POKEHEARTGOLD_BATTLE_INTRO_CONFIG_INTERNAL_H
#define POKEHEARTGOLD_BATTLE_INTRO_CONFIG_INTERNAL_H
#include "global.h"

typedef struct BattleSetupLite {
    u32 battleType;
    u8 pad_004[4];
    void *enemyParty; /* 0x008 */
    u8 pad_00c[0x51];
    u8 trainerClass; /* 0x05d */
    u8 pad_05e[0xfa];
    u32 mapId; /* 0x158 */
    u8 pad_15c[0x64];
    void *saveData; /* 0x1c0 */
} BattleSetupLite;

typedef struct BattleIntroMusic {
    u16 transition;
    u16 music;
} BattleIntroMusic;

typedef struct PackedBattleParam {
    u16 key : 10;
    u16 param : 6;
} PackedBattleParam;

extern const PackedBattleParam _020FC3B4[11];
extern const PackedBattleParam _020FC3CA[32];
extern const BattleIntroMusic _020FC40A[45];

void GF_AssertFail(void);
u32 ov01_021F0D20(BattleSetupLite *);
void *Save_VarsFlags_Get(void *);
BOOL Save_VarsFlags_FlypointFlagAction(void *, int, int);
u32 MapHeader_GetRegionNo(u32);
void *GetFirstAliveMonInParty_CrashIfNone(void *);
u32 GetMonData(void *, int, void *);

u32 BattleSetup_GetTransitionAndMusicParam(BattleSetupLite *);
u32 BattleStartGetTransition(u32, BattleSetupLite *);
u32 BattleStartGetMusic(u32, BattleSetupLite *);
u32 BattleSetup_GetWildTransitionEffect(BattleSetupLite *);
BOOL sub_020517F8(u32);
u32 BattleSetup_GetWildBattleMusic(BattleSetupLite *);
u32 NPCTrainerGetBattleIntroAndMusicParam(u32);
u32 WildPokemonGetBattleIntroAndMusicParam(void *, u32);
#endif
