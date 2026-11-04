#ifndef POKEHEARTGOLD_FRONTIER_SAVE_ACCESS_H
#define POKEHEARTGOLD_FRONTIER_SAVE_ACCESS_H

#include "save.h"
#include "save_frontier.h"

struct FrontierSpeciesRecords {
    u32 saveKey;
    u16 stats[3][495];
    u16 padding;
}; // size = 0xBA0

// The challenge types of the Battle Factory, Hall, Castle and Arcade.
enum FrontierChallengeType {
    FRONTIER_CHALLENGE_SINGLE,
    FRONTIER_CHALLENGE_DOUBLE,
    FRONTIER_CHALLENGE_MULTI,
    FRONTIER_CHALLENGE_LINK_MULTI,
};

// The facilities, as the frontier records app (FrontierRecordsAppArgs.facility) and the link lobby
// (FrontierLinkLobby.facility) number them
#define FRONTIER_FACILITY_TOWER        1
#define FRONTIER_FACILITY_FACTORY_LV50 2
#define FRONTIER_FACILITY_FACTORY_OPEN 3
#define FRONTIER_FACILITY_CASTLE       4
#define FRONTIER_FACILITY_HALL         5
#define FRONTIER_FACILITY_ARCADE       6

// The field ids of the challenge records and the facility flags (*_GetField / *_SetField).
enum FactoryChallengeField {
    FACTORY_CHALLENGE_LEVEL_MODE,
    FACTORY_CHALLENGE_TYPE,
    FACTORY_CHALLENGE_BATTLE_NO,
    FACTORY_CHALLENGE_TRAINER_IDS,
    FACTORY_CHALLENGE_RENTAL_SET_IDS,
    FACTORY_CHALLENGE_RENTAL_IVS,
    FACTORY_CHALLENGE_RENTAL_PERSONALITIES,
    FACTORY_CHALLENGE_OPPONENT_SET_IDS,
    FACTORY_CHALLENGE_OPPONENT_IVS,
    FACTORY_CHALLENGE_OPPONENT_PERSONALITIES,
    FACTORY_FLAGS_HAS_STREAK,
};

enum HallChallengeField {
    HALL_CHALLENGE_TYPE,
    HALL_CHALLENGE_BATTLE_NO,
    HALL_CHALLENGE_TRAINER_IDS,
    HALL_CHALLENGE_PARTY_SLOTS,
    HALL_CHALLENGE_SET_IDS,
    HALL_FLAGS_HAS_STREAK,
};

enum CastleChallengeField {
    CASTLE_CHALLENGE_TYPE,
    CASTLE_CHALLENGE_BATTLE_NO,
    CASTLE_CHALLENGE_HP,
    CASTLE_CHALLENGE_PP,
    CASTLE_CHALLENGE_STATUS,
    CASTLE_CHALLENGE_HELD_ITEM,
    CASTLE_CHALLENGE_TRAINER_IDS,
    CASTLE_CHALLENGE_PARTY_SLOTS,
    CASTLE_CHALLENGE_SET_IDS,
    CASTLE_FLAGS_HAS_STREAK,
    CASTLE_FLAGS_ONCE,
};

enum ArcadeChallengeField {
    ARCADE_CHALLENGE_TYPE,
    ARCADE_CHALLENGE_RANDOM_FLAG,
    ARCADE_CHALLENGE_BATTLE_NO,
    ARCADE_CHALLENGE_CURSOR_SPEED,
    ARCADE_CHALLENGE_HELD_ITEMS,
    ARCADE_CHALLENGE_TRAINER_IDS,
    ARCADE_CHALLENGE_PARTY_SLOTS,
    ARCADE_CHALLENGE_SET_IDS,
    ARCADE_FLAGS_HAS_STREAK,
};

// FrontierSave_GetStat / SetStat ids: the stats below FRONTIER_STAT_FRIEND_FLAGS hold one value (index
// FRONTIER_STAT_NO_FRIEND), the ones up to FRONTIER_STAT_PER_FRIEND one bit per friend (two words per flag) and the
// ones from FRONTIER_STAT_PER_FRIEND on one value per friend roster entry.
#define FRONTIER_STAT_FRIEND_FLAGS 100
#define FRONTIER_STAT_PER_FRIEND   112
#define FRONTIER_STAT_NO_FRIEND    255
#define FRONTIER_STAT_MAX          9999

u32 Save_Frontier_sizeof(void);
void Save_Frontier_Init(void *data);
FrontierSave *Save_Frontier_GetStatic(SaveData *saveData);
void Save_Frontier_Commit(SaveData *saveData);
void Save_Frontier_Load(SaveData *save);
u16 FrontierSave_GetStat(FrontierSave *frontier, int stat, int index);
u32 FrontierSave_SetStat(FrontierSave *frontier, int stat, int index, u16 value);
void FrontierSave_ClearRows(FrontierSave *frontier);
void FrontierSave_DeleteRow(FrontierSave *frontier, int row);
void FrontierSave_ClearRow(FrontierSave *frontier, int row, int unused);
u32 FrontierSave_AddStat(FrontierSave *frontier, int stat, int index, int amount);
u32 FrontierSave_SubStat(FrontierSave *frontier, int stat, int index, int amount);
void FrontierSave_RaiseStat(FrontierSave *frontier, u32 stat, u32 index, u16 value);
u32 FrontierSpeciesRecords_sizeof(void);
void FrontierSpeciesRecords_Init(void *data);
u32 *FrontierSpeciesRecords_Load(SaveData *saveData, u32 heapId, u32 *out);
u32 FrontierSpeciesRecords_Get(SaveData *saveData, u32 *buffer, u32 type, u32 index);
BOOL FrontierSpeciesRecords_UpdateFromStat(SaveData *save, int stat, int indexStat, int slot, u32 type, enum HeapID heapId, u32 *loadResult, int *saveResult);

void FactoryFlags_Init(u8 *flags);
void FactoryFlags_SetField(u8 *flags, u32 field, u8 index, u8 *value);
u32 FactoryFlags_GetField(u8 *flags, int field, u8 index, int unused);
u8 *Save_Frontier_GetFactoryFlags(SaveData *save);
void HallChallenge_Clear(HallChallenge *challenge);
HallChallenge *Save_Frontier_GetHallChallenge(SaveData *save);
u32 HallChallenge_GetSaved(HallChallenge *challenge);
void HallChallenge_SetSaved(HallChallenge *challenge, int saved);
void HallChallenge_SetField(HallChallenge *challenge, int field, u8 index, int unused, void *value);
u32 HallChallenge_GetField(HallChallenge *challenge, int field, u8 index, int unused, int unused2);
u8 HallTypeRanks_Get(u8 cell, u8 *ranks);
void HallTypeRanks_Set(u8 cell, u8 *ranks, u8 rank);
void HallTypeRanks_Clear(u8 *ranks);
void HallFlags_Init(u8 *flags);
u8 *Save_Frontier_GetHallFlags(SaveData *save);
void HallFlags_SetField(u8 *flags, u32 field, u32 index, u32 unused, void *input);
u32 HallFlags_GetField(u8 *flags, int field, u8 index, int unused, int unused2);
void CastleChallenge_Clear(CastleChallenge *challenge);
CastleChallenge *Save_Frontier_GetCastleChallenge(SaveData *save);
u32 CastleChallenge_GetSaved(CastleChallenge *challenge);
void CastleChallenge_SetSaved(CastleChallenge *challenge, int saved);
void CastleChallenge_SetField(CastleChallenge *challenge, int field, u8 index, int column, void *value);
u32 CastleChallenge_GetField(CastleChallenge *challenge, int field, u8 index, int column, int unused);
void CastleFlags_Init(u8 *flags);
u8 *Save_Frontier_GetCastleFlags(SaveData *save);
void CastleFlags_SetField(u8 *flags, u32 field, u32 index, u32 unused, void *input);
u32 CastleFlags_GetField(u8 *flags, u32 field, u8 index, u32 unused, u32 unused2);
void ArcadeChallenge_Clear(ArcadeChallenge *challenge);
ArcadeChallenge *Save_Frontier_GetArcadeChallenge(SaveData *save);
u32 ArcadeChallenge_GetSaved(ArcadeChallenge *challenge);
void ArcadeChallenge_SetSaved(ArcadeChallenge *challenge, int saved);
void ArcadeChallenge_SetField(ArcadeChallenge *challenge, int field, u8 index, int unused, void *value);
u32 ArcadeChallenge_GetField(ArcadeChallenge *challenge, int field, u8 index, int unused, int unused2);
void ArcadeFlags_Init(u8 *flags);
u8 *Save_Frontier_GetArcadeFlags(SaveData *save);
void ArcadeFlags_SetField(u8 *flags, u32 field, u32 index, u32 unused, void *input);
u32 ArcadeFlags_GetField(u8 *flags, u32 field, u8 index, u32 unused, u32 unused2);

void FactoryChallenge_Clear(FactoryChallenge *challenge);
FactoryChallenge *Save_Frontier_GetFactoryChallenge(SaveData *save);
u32 FactoryChallenge_GetSaved(FactoryChallenge *challenge);
void FactoryChallenge_SetSaved(FactoryChallenge *challenge, int saved);
void FactoryChallenge_SetField(FactoryChallenge *challenge, int field, u8 index, void *value);
u32 FactoryChallenge_GetField(FactoryChallenge *challenge, int field, u8 index, int unused);

#endif // POKEHEARTGOLD_FRONTIER_SAVE_ACCESS_H
