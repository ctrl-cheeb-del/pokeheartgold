#include "save_arrays.h"

#include "global.h"

#include "bag.h"
#include "daycare.h"
#include "easy_chat.h"
#include "friend_group.h"
#include "game_stats.h"
#include "hall_of_fame.h"
#include "mystery_gift.h"
#include "palPark_migration.h"
#include "photo_album.h"
#include "pokedex.h"
#include "pokemon_storage_system.h"
#include "pokewalker.h"
#include "roamer.h"
#include "safari_zone.h"
#include "sav_chatot.h"
#include "sav_system_info.h"
#include "save.h"
#include "save_follow_mon.h"
#include "save_link_ruleset.h"
#include "save_local_field_data.h"
#include "save_misc_data.h"
#include "save_palpad.h"
#include "save_pokegear.h"
#include "save_rankings.h"
#include "save_special_ribbons.h"
#include "save_trainer_card.h"
#include "save_trainer_house.h"
#include "save_vars_flags.h"
#include "save_wifi_history.h"
#include "save_block_23.h"
#include "frontier_save_access.h"

// These macros are temporary. As the respective sources
// are decompiled, the calls should be phased out.
#define DECL_CHUNK(prefix)            \
    extern u32 prefix##_sizeof(void); \
    extern void prefix##_Init(void *);
#define DECL_CHUNK_EX(sizefn, initfn) \
    extern u32 sizefn(void);          \
    extern void initfn(void *);

DECL_CHUNK(Save_FashionData)
DECL_CHUNK(Save_Frontier)
DECL_CHUNK_EX(Save_Gts_sizeof, Save_Gts_Init)
DECL_CHUNK_EX(SaveBlock23_sizeof, SaveBlock23_Init)
DECL_CHUNK_EX(Save_FriendRoster_sizeof, Save_FriendRoster_Init)
DECL_CHUNK_EX(PokeathlonSave_FriendshipRecords_sizeof, PokeathlonSave_FriendshipRecords_Init)
DECL_CHUNK_EX(Save_WiiMessage_sizeof, Save_WiiMessage_Init)
DECL_CHUNK_EX(Save_PlazaSurvey_sizeof, Save_PlazaSurvey_Init)
DECL_CHUNK(PokeathlonSave)
DECL_CHUNK(Save_ApricornBox)

const struct SaveChunkHeader gSaveChunkHeaders[] = {
    {
     SAVE_SYSINFO,
     0,
     (SAVESIZEFN)Save_SysInfo_sizeof,
     (SAVEINITFN)Save_SysInfo_Init,
     },
    {
     SAVE_PLAYERDATA,
     0,
     (SAVESIZEFN)Save_PlayerData_sizeof,
     (SAVEINITFN)Save_PlayerData_Init,
     },
    {
     SAVE_PARTY,
     0,
     (SAVESIZEFN)SaveArray_Party_sizeof,
     (SAVEINITFN)SaveArray_Party_Init,
     },
    {
     SAVE_BAG,
     0,
     (SAVESIZEFN)Save_Bag_sizeof,
     (SAVEINITFN)Save_Bag_Init,
     },
    {
     SAVE_FLAGS,
     0,
     (SAVESIZEFN)Save_VarsFlags_sizeof,
     (SAVEINITFN)Save_VarsFlags_Init,
     },
    {
     SAVE_LOCAL_FIELD_DATA,
     0,
     (SAVESIZEFN)Save_LocalFieldData_sizeof,
     (SAVEINITFN)Save_LocalFieldData_Init,
     },
    {
     SAVE_POKEDEX,
     0,
     (SAVESIZEFN)Save_Pokedex_sizeof,
     (SAVEINITFN)Save_Pokedex_Init,
     },
    {
     SAVE_DAYCARE,
     0,
     (SAVESIZEFN)Save_Daycare_sizeof,
     (SAVEINITFN)Save_Daycare_Init,
     },
    {
     SAVE_PALPAD,
     0,
     (SAVESIZEFN)Save_PalPad_sizeof,
     (SAVEINITFN)Save_PalPad_Init,
     },
    {
     SAVE_MISC,
     0,
     (SAVESIZEFN)Save_Misc_sizeof,
     (SAVEINITFN)Save_Misc_Init,
     },
    {
     SAVE_MAP_OBJECTS,
     0,
     (SAVESIZEFN)Save_MapObjects_sizeof,
     (SAVEINITFN)Save_MapObjects_Init,
     },
    {
     SAVE_LINK_BATTLE_RULESET,
     0,
     (SAVESIZEFN)Save_LinkBattleRuleset_sizeof,
     (SAVEINITFN)Save_LinkBattleRuleset_Init,
     },
    {
     SAVE_DRESSUP_DATA,
     0,
     (SAVESIZEFN)Save_FashionData_sizeof,
     (SAVEINITFN)Save_FashionData_Init,
     },
    {
     SAVE_MAILBOX,
     0,
     (SAVESIZEFN)Save_Mailbox_sizeof,
     (SAVEINITFN)Save_Mailbox_Init,
     },
    {
     SAVE_FRIEND_GROUP,
     0,
     (SAVESIZEFN)Save_FriendGroup_sizeof,
     (SAVEINITFN)Save_FriendGroup_Init,
     },
    {
     SAVE_TRAINER_CARD,
     0,
     (SAVESIZEFN)Save_TrainerCard_sizeof,
     (SAVEINITFN)Save_TrainerCard_Init,
     },
    {
     SAVE_GAMESTATS,
     0,
     (SAVESIZEFN)GameStats_sizeof,
     (SAVEINITFN)GameStats_Init,
     },
    {
     SAVE_SEAL_CASE,
     0,
     (SAVESIZEFN)Save_SealCase_sizeof,
     (SAVEINITFN)Save_SealCase_Init,
     },
    {
     SAVE_CHATOT,
     0,
     (SAVESIZEFN)Save_Chatot_sizeof,
     (SAVEINITFN)Save_Chatot_Init,
     },
    {
     SAVE_FRONTIER,
     0,
     (SAVESIZEFN)Save_Frontier_sizeof,
     (SAVEINITFN)Save_Frontier_Init,
     },
    {
     SAVE_SPECIAL_RIBBONS,
     0,
     (SAVESIZEFN)Save_SpecialRibbons_sizeof,
     (SAVEINITFN)Save_SpecialRibbons_Init,
     },
    {
     SAVE_ROAMER,
     0,
     (SAVESIZEFN)Save_Roamers_sizeof,
     (SAVEINITFN)Save_Roamers_Init,
     },
    {
     SAVE_GTS,
     0,
     (SAVESIZEFN)Save_Gts_sizeof,
     (SAVEINITFN)Save_Gts_Init,
     },
    {
     SAVE_UNK_23,
     0,
     (SAVESIZEFN)SaveBlock23_sizeof,
     (SAVEINITFN)SaveBlock23_Init,
     },
    {
     SAVE_RANKINGS,
     0,
     (SAVESIZEFN)Save_Rankings_sizeof,
     (SAVEINITFN)Save_Rankings_Init,
     },
    {
     SAVE_FRIEND_ROSTER,
     0,
     (SAVESIZEFN)Save_FriendRoster_sizeof,
     (SAVEINITFN)Save_FriendRoster_Init,
     },
    {
     SAVE_WIFI_HISTORY,
     0,
     (SAVESIZEFN)Save_WiFiHistory_sizeof,
     (SAVEINITFN)Save_WiFiHistory_Init,
     },
    {
     SAVE_MYSTERY_GIFT,
     0,
     (SAVESIZEFN)Save_MysteryGift_sizeof,
     (SAVEINITFN)Save_MysteryGift_Init,
     },
    {
     SAVE_UNK_28,
     0,
     (SAVESIZEFN)MigratedPokemon_GetSize,
     (SAVEINITFN)MigratedPokemon_Init,
     },
    {
     SAVE_POKEATHLON_FRIENDSHIP_RECORDS,
     0,
     (SAVESIZEFN)PokeathlonSave_FriendshipRecords_sizeof,
     (SAVEINITFN)PokeathlonSave_FriendshipRecords_Init,
     },
    {
     SAVE_EASY_CHAT,
     0,
     (SAVESIZEFN)Save_EasyChat_sizeof,
     (SAVEINITFN)Save_EasyChat_Init,
     },
    {
     SAVE_UNK_31,
     0,
     (SAVESIZEFN)Save_WiiMessage_sizeof,
     (SAVEINITFN)Save_WiiMessage_Init,
     },
    {
     SAVE_PLAZA_SURVEY,
     0,
     (SAVESIZEFN)Save_PlazaSurvey_sizeof,
     (SAVEINITFN)Save_PlazaSurvey_Init,
     },
    {
     SAVE_FOLLOW_MON,
     0,
     (SAVESIZEFN)Save_FollowMon_sizeof,
     (SAVEINITFN)Save_FollowMon_Init,
     },
    {
     SAVE_POKEGEAR,
     0,
     (SAVESIZEFN)SaveData_Pokegear_sizeof,
     (SAVEINITFN)SaveData_Pokegear_Init,
     },
    {
     SAVE_SAFARI_ZONE,
     0,
     (SAVESIZEFN)Save_SafariZone_sizeof,
     (SAVEINITFN)Save_SafariZone_Init,
     },
    {
     SAVE_PHOTO_ALBUM,
     0,
     (SAVESIZEFN)Save_PhotoAlbum_sizeof,
     (SAVEINITFN)Save_PhotoAlbum_Init,
     },
    {
     SAVE_POKEATHLON,
     0,
     (SAVESIZEFN)PokeathlonSave_sizeof,
     (SAVEINITFN)PokeathlonSave_Init,
     },
    {
     SAVE_APRICORN_BOX,
     0,
     (SAVESIZEFN)Save_ApricornBox_sizeof,
     (SAVEINITFN)Save_ApricornBox_Init,
     },
    {
     SAVE_POKEWALKER,
     0,
     (SAVESIZEFN)Pokewalker_sizeof,
     (SAVEINITFN)Pokewalker_Init,
     },
    {
     SAVE_TRAINER_HOUSE,
     0,
     (SAVESIZEFN)Save_TrainerHouse_sizeof,
     (SAVEINITFN)Save_TrainerHouse_Init,
     },
    {
     SAVE_PCSTORAGE,
     1,
     (SAVESIZEFN)PCStorage_sizeof,
     (SAVEINITFN)PCStorage_Init,
     },
};
const int gNumSaveChunkHeaders = NELEMS(gSaveChunkHeaders);

SaveBlock23 *Save_Block23_Get(SaveData *saveData) { // Save_SafariZone_Get? conflicts with other one
    SaveSubstruct_AssertCRC(SAVE_UNK_23);
    return SaveArray_Get(saveData, SAVE_UNK_23);
}

PCStorage *SaveArray_PCStorage_Get(SaveData *saveData) {
    return SaveArray_Get(saveData, SAVE_PCSTORAGE);
}

MysteryGiftSave *Save_MysteryGift_Get(SaveData *saveData) {
    SaveSubstruct_AssertCRC(SAVE_MYSTERY_GIFT);
    return SaveArray_Get(saveData, SAVE_MYSTERY_GIFT);
}

MigratedPokemon *Save_MigratedPokemon_Get(SaveData *saveData) {
    return SaveArray_Get(saveData, SAVE_UNK_28);
}

DECL_CHUNK_EX(FrontierSpeciesRecords_sizeof, FrontierSpeciesRecords_Init)
DECL_CHUNK_EX(BattleRecord_sizeof, BattleRecord_Init)

const struct ExtraSaveChunkHeader gExtraSaveChunkHeaders[] = {
    {
     0,
     SAVE_PAGE_MAX,
     (SAVESIZEFN)Save_HOF_sizeof,
     (SAVEINITFN)Save_HOF_Init,
     },
    {
     1,
     SAVE_PAGE_MAX + 3,
     (SAVESIZEFN)FrontierSpeciesRecords_sizeof,
     (SAVEINITFN)FrontierSpeciesRecords_Init,
     },
    {
     2,
     SAVE_PAGE_MAX + 4,
     (SAVESIZEFN)BattleRecord_sizeof,
     (SAVEINITFN)BattleRecord_Init,
     },
    {
     3,
     SAVE_PAGE_MAX + 6,
     (SAVESIZEFN)BattleRecord_sizeof,
     (SAVEINITFN)BattleRecord_Init,
     },
    {
     4,
     SAVE_PAGE_MAX + 8,
     (SAVESIZEFN)BattleRecord_sizeof,
     (SAVEINITFN)BattleRecord_Init,
     },
    {
     5,
     SAVE_PAGE_MAX + 10,
     (SAVESIZEFN)BattleRecord_sizeof,
     (SAVEINITFN)BattleRecord_Init,
     },
};

const int gNumExtraSaveChunkHeaders = NELEMS(gExtraSaveChunkHeaders);

HallOfFame *LoadHallOfFame(SaveData *saveData, enum HeapID heapID, int *ret_p) {
    return ReadExtraSaveChunk(saveData, heapID, 0, ret_p);
}

int SaveHallOfFame(SaveData *saveData, HallOfFame *hallOfFame) {
    return WriteExtraSaveChunk(saveData, 0, hallOfFame);
}

struct BattleRecord *LoadBattleRecord(SaveData *saveData, enum HeapID heapID, int *ret_p, int idx) {
    int keysUpdated;
    return ReadExtraSaveChunkKeyed(saveData, heapID, idx + 2, ret_p, &keysUpdated);
}

int SaveBattleRecord(SaveData *saveData, struct BattleRecord *data, int idx) {
    return WriteExtraSaveChunkKeyed(saveData, idx + 2, data);
}

struct FrontierSpeciesRecords *LoadFrontierSpeciesRecords(SaveData *saveData, enum HeapID heapID, int *ret_p) {
    int keysUpdated;
    return ReadExtraSaveChunkKeyed(saveData, heapID, 1, ret_p, &keysUpdated);
}

int SaveFrontierSpeciesRecords(SaveData *saveData, struct FrontierSpeciesRecords *data) {
    return WriteExtraSaveChunkKeyed(saveData, 1, data);
}

u32 PCStorage_GetSizeOfBox(void) {
    return PCBox_sizeof();
}

u32 PCStorage_GetNumBoxes(void) {
    return NUM_BOXES;
}

u32 Save_GetPCBoxModifiedFlags(SaveData *saveData) {
    PCStorage *pcStorage = SaveArray_Get(saveData, SAVE_PCSTORAGE);
    return PCStorage_GetBoxModifiedFlags(pcStorage);
}

void Save_ResetPCBoxModifiedFlags(SaveData *saveData) {
    PCStorage *pcStorage = SaveArray_Get(saveData, SAVE_PCSTORAGE);
    PCStorage_ResetBoxModifiedFlags(pcStorage);
}

void Save_SetAllPCBoxesModified(SaveData *saveData) {
    PCStorage *pcStorage = SaveArray_Get(saveData, SAVE_PCSTORAGE);
    PCStorage_SetAllBoxesModified(pcStorage);
}

void Save_PCStorage_ClearBoxPadding(SaveData *saveData) {
    PCStorage *pcStorage = SaveArray_Get(saveData, SAVE_PCSTORAGE);
    PCStorage_ClearBoxPadding(pcStorage);
}
