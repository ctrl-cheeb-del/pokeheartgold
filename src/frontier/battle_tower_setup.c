#include "frontier/battle_tower_setup.h"

#include "global.h"

#include "constants/battle.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"

#include "battle/battle_setup.h"
#include "frontier/frontier.h"
#include "frontier/frontier_trainer_record.h"
#include "frontier/frontier_trainers.h"
#include "msgdata/msg.naix"

#include "assert.h"
#include "communication_player_state.h"
#include "filesystem.h"
#include "frontier_data_access.h"
#include "frontier_field_system.h"
#include "heap.h"
#include "msgdata.h"
#include "party.h"
#include "player_data.h"
#include "pm_version.h"
#include "pokemon.h"
#include "scrcmd_9.h"

static u32 BattleTower_PickTrainerMonSets(FrontierFieldSystem *tower, FrontierTrainerEntry *sets, u16 trainerId, FrontierMon *mons, u8 count, u16 *partySpecies, u16 *partyItems, FrontierMultiBattleAllyData *allyData, enum HeapID heapID);
static void BattleTower_GetSampleRoomTrainer(FrontierTrainer *trainer, int index);
static u32 BattleTower_GenerateFrontierMon(FrontierFieldSystem *tower, FrontierMon *mon, u16 setId, u32 otId, u32 pid, u8 iv, u8 itemIndex, BOOL replaceItem, enum HeapID heapID);
static void BattleTower_AddTrainerToBattle(BattleSetup *setup, FrontierTrainer *trainer, int count, int battler, enum HeapID heapID);
static u32 BattleTower_GetBattleType(u32 towerMode);
static NarcId BattleTower_GetMonSetNarc(u32 towerMode);
static NarcId BattleTower_GetTrainerNarc(u32 towerMode);
static BOOL BattleTower_UsesNewSetNarcs(u32 towerMode);

// The Battle Tower of the Battle Frontier: opponent trainers and their Pokemon generated from the Battle
// Tower sets, the sample Wi-Fi room used when no room has been downloaded, and the battle setup of a tower battle.
// Linked games only use the newer trainer and set narcs when both players have a known version.

u32 BattleTower_GenerateTrainerMons(FrontierFieldSystem *tower, FrontierTrainer *trainer, u16 trainerId, u32 count, u16 *partySpecies, u16 *partyItems, FrontierMultiBattleAllyData *allyData, enum HeapID heapID) {
    FrontierTrainerEntry *sets;
    u32 replaceItem;

    sets = FrontierTrainer_Load((FrontierTrainerRecord *)trainer, trainerId, heapID, BattleTower_GetTrainerNarc(tower->towerMode));
    replaceItem = BattleTower_PickTrainerMonSets(tower, sets, trainerId, trainer->frontierMons, count, partySpecies, partyItems, allyData, heapID);
    Heap_Free(sets);
    return replaceItem;
}

static u32 BattleTower_PickTrainerMonSets(FrontierFieldSystem *tower, FrontierTrainerEntry *sets, u16 trainerId, FrontierMon *mons, u8 count, u16 *partySpecies, u16 *partyItems, FrontierMultiBattleAllyData *allyData, enum HeapID heapID) {
    int i;
    int j;
    int numMons;
    u8 iv;
    u32 otId;
    u32 setId;
    int failedItemAttempts;
    BOOL replaceItem;
    u32 *setIdPtr;
    u32 *cursor;
    u32 setIds[4];
    u32 pids[4];
    FrontierMonSet other;
    FrontierMonSet candidate;

    replaceItem = FALSE;
    GF_ASSERT(count <= 4);
    numMons = count;
    i = failedItemAttempts = 0;
    if (numMons != 0) {
        cursor = setIds;
        do {
            setId = sets->setIds[(u8)(FrontierFieldSystem_NextRandom(tower) % sets->numSets)];
            FrontierData_ReadMember(&candidate, setId, BattleTower_GetMonSetNarc(tower->towerMode));
            for (j = 0; j < i; j++) {
                FrontierData_ReadMember(&other, setIds[j], BattleTower_GetMonSetNarc(tower->towerMode));
                if (other.species == candidate.species) {
                    break;
                }
            }
            if (j != i) {
                continue;
            }
            if (partySpecies != NULL) {
                for (j = 0; j < numMons; j++) {
                    if (candidate.species == partySpecies[j]) {
                        break;
                    }
                }
                if (j != numMons) {
                    continue;
                }
            }
            if (failedItemAttempts < 50) {
                for (j = 0; j < i; j++) {
                    FrontierData_ReadMember(&other, setIds[j], BattleTower_GetMonSetNarc(tower->towerMode));
                    if (other.item != ITEM_NONE && other.item == candidate.item) {
                        break;
                    }
                }
                if (j != i) {
                    failedItemAttempts++;
                    continue;
                }
                if (partyItems != NULL) {
                    for (j = 0; j < numMons; j++) {
                        if (candidate.item == partyItems[j] && partyItems[j] != ITEM_NONE) {
                            break;
                        }
                    }
                    if (j != numMons) {
                        failedItemAttempts++;
                        continue;
                    }
                }
            }
            i++;
            *cursor++ = setId;
        } while (i != numMons);
    }
    iv = GetFrontierTrainerIVs(trainerId);
    otId = FrontierFieldSystem_NextRandom(tower) | (FrontierFieldSystem_NextRandom(tower) << 16);
    if (failedItemAttempts >= 50) {
        replaceItem = TRUE;
    }
    j = 0;
    if (i > 0) {
        setIdPtr = setIds;
        do {
            pids[j] = BattleTower_GenerateFrontierMon(tower, &mons[j], *setIdPtr, otId, 0, iv, j, replaceItem, heapID);
            setIdPtr++;
            j++;
        } while (j < i);
    }
    if (allyData == NULL) {
        return replaceItem;
    }
    allyData->otId = otId;
    for (j = 0; j < 2; j++) {
        allyData->frontierMonIDs[j] = setIds[j];
        allyData->frontierMonPIDs[j] = pids[j];
    }
    return replaceItem;
}

void BattleTower_GetRoomTrainer(SaveData *saveData, FrontierTrainer *trainer, int index) {
    BattleRoomDownload *download;

    MI_CpuFill8(trainer, 0, sizeof(FrontierTrainer));
    download = Save_BattleRoomDownload_Get(saveData);
    if (!BattleRoomDownload_HasTrainers(download)) {
        BattleTower_GetSampleRoomTrainer(trainer, index);
    } else {
        BattleRoomDownload_GetTrainer(download, trainer, index);
    }
}

static void BattleTower_GetSampleRoomTrainer(FrontierTrainer *trainer, int index) {
    const BattleTowerSampleTrainer *sample;
    const FrontierMon *mons;
    FrontierMon *dest;
    int i;

    MI_CpuFill8(trainer, 0, sizeof(FrontierTrainer));
    sample = &gBattleTowerSampleTrainers[index];
    mons = gBattleTowerSampleMons;
    MI_CpuCopy8(&gBattleTowerSampleTrainerHeaders[index * offsetof(FrontierTrainer, frontierMons)], trainer, offsetof(FrontierTrainer, frontierMons));
    *(u16 *)trainer->filler06 = gBattleTowerSampleTrainers[index].unk_00;
    dest = trainer->frontierMons;
    for (i = 0; i < 4; i++) {
        MI_CpuCopy8(&mons[sample->monIndexes[i]], dest, sizeof(FrontierMon));
        dest++;
    }
}

static u32 BattleTower_GenerateFrontierMon(FrontierFieldSystem *tower, FrontierMon *mon, u16 setId, u32 otId, u32 pid, u8 iv, u8 itemIndex, BOOL replaceItem, enum HeapID heapID) {
    FrontierMonSet set;
    u32 friendship;
    u32 newPid;
    int i;
    int count;
    u8 ev;
    int evs;
    int ability;

    MI_CpuFill8(mon, 0, sizeof(FrontierMon));
    FrontierData_ReadMember(&set, setId, BattleTower_GetMonSetNarc(tower->towerMode));
    mon->species = set.species;
    mon->form = set.form;
    if (replaceItem) {
        mon->item = gBattleTowerReplacementItems[itemIndex];
    } else {
        mon->item = set.item;
    }
    friendship = FRIENDSHIP_MAX;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        mon->moves[i] = set.moves[i];
        if (set.moves[i] == MOVE_FRUSTRATION) {
            friendship = 0;
        }
    }
    mon->otId = otId;
    newPid = pid;
    if (newPid == 0) {
        do {
            u16 lo = FrontierFieldSystem_NextRandom(tower);
            u16 hi = FrontierFieldSystem_NextRandom(tower);
            newPid = lo | (hi << 16);
        } while (set.nature != GetNatureFromPersonality(newPid) || CalcShininessByOtIdAndPersonality(otId, newPid) == TRUE);
        mon->pid = newPid;
    } else {
        mon->pid = newPid;
    }
    mon->hpIv = iv;
    mon->atkIv = iv;
    mon->defIv = iv;
    mon->spdIv = iv;
    mon->spAtkIv = iv;
    mon->spDefIv = iv;
    count = 0;
    for (i = 0; i < NUM_STATS; i++) {
        if (MaskOfFlagNo(i) & set.evMask) {
            count++;
        }
    }
    evs = MAX_EV_SUM / count;
    if (evs > 255) {
        evs = 255;
    }
    i = 0;
    ev = evs;
    for (; i < NUM_STATS; i++) {
        if (MaskOfFlagNo(i) & set.evMask) {
            mon->evs[i] = ev;
        }
    }
    mon->ppUp = 0;
    mon->language = gGameLanguage;
    ability = GetMonBaseStat(mon->species, BASE_ABILITY_2);
    if (ability != 0) {
        if (mon->pid & 1) {
            mon->ability = ability;
        } else {
            mon->ability = GetMonBaseStat(mon->species, BASE_ABILITY_1);
        }
    } else {
        mon->ability = GetMonBaseStat(mon->species, BASE_ABILITY_1);
    }
    mon->friendship = friendship;
    GetSpeciesNameIntoArray(mon->species, heapID, mon->nickname);
    return newPid;
}

BattleSetup *BattleTower_NewBattleSetup(FrontierFieldSystem *tower, FrontierLaunchArgs *args) {
    BattleSetup *setup;
    Party *party;
    Pokemon *mon;
    int i;
    u32 exp;

    setup = BattleSetup_New(tower->heapID, BattleTower_GetBattleType(tower->towerMode));
    party = SaveArray_Party_Get(args->saveData);
    BattleSetup_InitFromSaveData(setup, NULL, args->saveData, args->mapId, args->bagCursor, args->keyPressedSave);
    setup->battleBg = BATTLE_BG_BATTLE_TOWER;
    setup->terrain = TERRAIN_BATTLE_TOWER;
    mon = AllocMonZeroed(tower->heapID);
    Party_InitWithMaxSize(setup->party[BATTLER_PLAYER], tower->numMons);
    for (i = 0; i < tower->numMons; i++) {
        CopyPokemonToPokemon(Party_GetMonByIndex(party, tower->partyMonIndexes[i]), mon);
        if (GetMonData(mon, MON_DATA_LEVEL, NULL) > 50) {
            exp = GetMonExpBySpeciesAndLevel(GetMonData(mon, MON_DATA_SPECIES, NULL), 50);
            SetMonData(mon, MON_DATA_EXPERIENCE, &exp);
            CalcMonLevelAndStats(mon);
        }
        BattleSetup_AddMonToParty(setup, mon, BATTLER_PLAYER);
    }
    Heap_Free(mon);
    BattleSetup_SetAllySideBattlersToPlayer(setup);
    BattleTower_AddTrainerToBattle(setup, &tower->opponents[0], tower->numMons, BATTLER_ENEMY, tower->heapID);
    for (i = 0; i < BATTLER_MAX; i++) {
        setup->trainer[i].data.aiFlags = 7;
    }
    switch (tower->towerMode) {
    case TOWER_MODE_MULTI:
        BattleTower_AddTrainerToBattle(setup, &tower->frontierStatTrainers[tower->multiBattleAllyID], tower->numMons, BATTLER_PLAYER2, tower->heapID);
        // fallthrough
    case TOWER_MODE_LINK:
    case TOWER_MODE_6:
        BattleTower_AddTrainerToBattle(setup, &tower->opponents[1], tower->numMons, BATTLER_ENEMY2, tower->heapID);
        break;
    }
    return setup;
}

static void BattleTower_AddTrainerToBattle(BattleSetup *setup, FrontierTrainer *trainer, int count, int battler, enum HeapID heapID) {
    Pokemon *mon;
    int i;

    FrontierTrainer_SetBattleTrainer(setup, (FrontierTrainerRecord *)trainer, count, battler, heapID);
    mon = AllocMonZeroed(heapID);
    for (i = 0; i < count; i++) {
        FrontierMon_ToPokemon(&trainer->frontierMons[i], mon, 120);
        Party_AddMon(setup->party[battler], mon);
    }
    Heap_Free(mon);
}

static u32 BattleTower_GetBattleType(u32 towerMode) {
    u32 battleType = BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER;

    switch (towerMode) {
    case TOWER_MODE_SINGLE:
    case TOWER_MODE_WIFI:
        return BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER;
    case TOWER_MODE_DOUBLE:
        return BATTLE_TYPE_FRONTIER | BATTLE_TYPE_DOUBLES | BATTLE_TYPE_TRAINER;
    case TOWER_MODE_MULTI:
        return BATTLE_TYPE_FRONTIER | BATTLE_TYPE_AI | BATTLE_TYPE_MULTI | BATTLE_TYPE_DOUBLES | BATTLE_TYPE_TRAINER;
    case TOWER_MODE_LINK:
    case TOWER_MODE_6:
        return BATTLE_TYPE_FRONTIER | BATTLE_TYPE_MULTI | BATTLE_TYPE_LINK | BATTLE_TYPE_DOUBLES | BATTLE_TYPE_TRAINER;
    case TOWER_MODE_WIFI_PRACTICE:
        break;
    }
    return battleType;
}

void BattleTowerSetup_SetLinkFlag(FrontierFieldSystem *tower, u32 value) {
    tower->linkFlag = value;
    tower->linkSendBuffer[0] = value;
}

BOOL BattleTowerSetup_IsLinkFlagSetByEither(FrontierFieldSystem *tower, const u16 *remote) {
    if (tower->linkFlag || *remote != 0) {
        return TRUE;
    }
    return FALSE;
}

static NarcId BattleTower_GetMonSetNarc(u32 towerMode) {
    if (BattleTower_UsesNewSetNarcs(towerMode) == FALSE) {
        return NARC_a_1_2_9;
    }
    return NARC_a_2_0_3;
}

static NarcId BattleTower_GetTrainerNarc(u32 towerMode) {
    if (BattleTower_UsesNewSetNarcs(towerMode) == FALSE) {
        return NARC_a_1_2_8;
    }
    return NARC_a_2_0_2;
}

u32 BattleTower_GetTrainerMessageBank(u32 towerMode) {
    if (BattleTower_UsesNewSetNarcs(towerMode) == FALSE) {
        return NARC_msg_msg_0723_bin;
    }
    return NARC_msg_msg_0724_bin;
}

static BOOL BattleTower_UsesNewSetNarcs(u32 towerMode) {
    int version0;
    int version1;
    PlayerProfile *profile0;
    PlayerProfile *profile1;

    if (towerMode == TOWER_MODE_LINK || towerMode == TOWER_MODE_6) {
        profile0 = CommPlayerInfo_GetProfile(0);
        GF_ASSERT(profile0 != NULL);
        profile1 = CommPlayerInfo_GetProfile(1);
        GF_ASSERT(profile1 != NULL);
        version0 = PlayerProfile_GetVersion(profile0);
        version1 = PlayerProfile_GetVersion(profile1);
        if (version0 == 0 || version1 == 0) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}
