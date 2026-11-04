#include "scrcmd_battle_hall.h"

#include "global.h"

#include "constants/game_stats.h"

#include "assert.h"
#include "bag.h"
#include "field_system.h"
#include "frontier_data.h"
#include "game_stats.h"
#include "heap.h"
#include "launch_application.h"
#include "mail.h"
#include "party.h"
#include "party_menu.h"
#include "player_avatar.h"
#include "player_data.h"
#include "pokedex_util.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "save_special_ribbons.h"
#include "scrcmd.h"
#include "script.h"
#include "script_manager.h"
#include "task.h"
#include "frontier_save_access.h"
#include "communication_core.h"
#include "field_misc_util.h"
#include "frontier_stat_ids_legacy.h"
#include "pokemon_summary.h"
#include "field_comm_cmds.h"

typedef enum BattleHallChallengeType {
    BATTLE_HALL_CHALLENGE_TYPE_SINGLE,
    BATTLE_HALL_CHALLENGE_TYPE_DOUBLE,
    BATTLE_HALL_CHALLENGE_TYPE_MULTI,
} BattleHallChallengeType;

typedef struct BattleHallSelectMonsEnv {
    u32 state;
    u8 challengeType;
    u8 partySlot;
    u8 selectedMons[2];
    void **appArgs;
} BattleHallSelectMonsEnv;

typedef struct WinStreakBP {
    u32 winStreakTarget;
    u32 bp;
} WinStreakBP;

static const WinStreakBP battleHallWinStreakBP[] = {
    { 10,     1    },
    { 30,     3    },
    { 50,     5    },
    { 100,    5    },
    { 150,    5    },
    { 200,    5    },
    { 250,    5    },
    { 300,    5    },
    { 350,    5    },
    { 400,    5    },
    { 450,    5    },
    { 500,    10   },
    { 600,    10   },
    { 700,    10   },
    { 800,    10   },
    { 900,    10   },
    { 1000,   10   },
    { 1200,   30   },
    { 1400,   30   },
    { 1600,   30   },
    { 1800,   30   },
    { 2000,   50   },
    { 2500,   50   },
    { 3000,   50   },
    { 3500,   50   },
    { 4000,   50   },
    { 4500,   50   },
    { 5000,   50   },
    { 5500,   50   },
    { 6000,   50   },
    { 6500,   50   },
    { 7000,   50   },
    { 7500,   50   },
    { 8000,   50   },
    { 8500,   50   },
    { 9000,   50   },
    { 9500,   50   },
    { 10000,  100  },
    { 20000,  200  },
    { 30000,  300  },
    { 40000,  400  },
    { 50000,  500  },
    { 60000,  600  },
    { 70000,  700  },
    { 80000,  800  },
    { 90000,  900  },
    { 100000, 1000 },
};

static BOOL BattleHall_DoesPartyContainEligibleMons(s32, SaveData *);
static void BattleHall_StartSpeciesCheck(TaskManager *, u16, u16 *);
static BOOL Task_BattleHallSpeciesCheck(TaskManager *);
static void BattleHall_StartSelectMons(TaskManager *, void *, BattleHallChallengeType);
static BOOL Task_BattleHallSelectMons(TaskManager *);
static u32 BattleHallSelectMons_OpenPartyMenu(BattleHallSelectMonsEnv *, FieldSystem *, enum HeapID);
static u32 BattleHallSelectMons_WaitPartyMenu(BattleHallSelectMonsEnv *, FieldSystem *);
static u32 BattleHallSelectMons_OpenSummary(BattleHallSelectMonsEnv *, FieldSystem *, enum HeapID);
static u32 BattleHallSelectMons_WaitSummary(BattleHallSelectMonsEnv *, FieldSystem *);

const u8 sBattleHallSummaryPages[] = {
    0,
    1,
    2,
    3,
    4,
};

// Essentially a nop
BOOL ScrCmd_NopVar490(ScriptContext *ctx) {
    u16 *unused = ScriptGetVarPointer(ctx);
    return FALSE;
}

// Essentially a nop
BOOL ScrCmd_Dummy491(ScriptContext *ctx) {
    u16 *unused = ScriptGetVarPointer(ctx);
    return FALSE;
}

// same as ScrCmd_BattleHallResetStreak, but battle factory
BOOL ScrCmd_BattleFactoryResetStreak(ScriptContext *ctx) {
    u16 type = ScriptGetVar(ctx);
    u16 levelMode = ScriptGetVar(ctx);
    u8 *factoryFlags = Save_Frontier_GetFactoryFlags(ctx->fieldSystem->saveData);
    u8 s = 0;
    FactoryFlags_SetField(factoryFlags, 0xa, levelMode * 4 + type, &s);
    if (type == 3) {
        u32 stat;
        if (levelMode == 0) {
            stat = 0x66;
        } else {
            stat = 0x68;
        }
        FrontierSave_SetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), stat, FrontierStat_GetFriendIndex(stat), 0);
    }
    FrontierSave_SetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), BattleFactory_GetWinStreakStat(levelMode, type), FrontierStat_GetFriendIndex(BattleFactory_GetWinStreakStat(levelMode, type)), 0);
    FrontierSave_SetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), BattleFactory_GetTradeCountStat(levelMode, type), FrontierStat_GetFriendIndex(BattleFactory_GetTradeCountStat(levelMode, type)), 0);
    return FALSE;
}

BOOL ScrCmd_BattleHallAction(ScriptContext *ctx) {
    u16 action = ScriptReadHalfword(ctx);
    u16 type = ScriptGetVar(ctx);
    u16 *resultPtr = ScriptGetVarPointer(ctx);
    Save_Frontier_GetHallChallenge(ctx->fieldSystem->saveData);
    u8 *hallFlags = Save_Frontier_GetHallFlags(ctx->fieldSystem->saveData);
    void *appArgs = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    switch (action) {
    case 0:
        *resultPtr = BattleHall_DoesPartyContainEligibleMons(type, ctx->fieldSystem->saveData);
        break;
    case 1:
        if (type == 3) {
            *resultPtr = FrontierSave_GetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), 0x6a, FrontierStat_GetFriendIndex(0x6a));
        } else {
            *resultPtr = HallFlags_GetField(hallFlags, 5, type, 0, 0);
        }
        break;
    case 2:
        *resultPtr = FrontierSave_GetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), BattleHall_GetSpeciesStat(type), FrontierStat_GetFriendIndex(BattleHall_GetSpeciesStat(type)));
        break;
    case 3:
        BattleHall_ResetStreak(ctx->fieldSystem->saveData, hallFlags, type);
        break;
    case 4: {
        BattleHallChallengeType challengeType;
        if (type == 0) {
            challengeType = BATTLE_HALL_CHALLENGE_TYPE_SINGLE;
        } else if (type == 1) {
            challengeType = BATTLE_HALL_CHALLENGE_TYPE_DOUBLE;
        } else {
            challengeType = BATTLE_HALL_CHALLENGE_TYPE_MULTI;
        }
        BattleHall_StartSelectMons(ctx->taskman, appArgs, challengeType);
        return TRUE;
    }
    default:
        GF_ASSERT(FALSE);
        *resultPtr = 0;
    }
    return FALSE;
}

static BOOL BattleHall_DoesPartyContainEligibleMons(s32 numRequiredMons, SaveData *saveData) {
    u8 i;
    u8 numEligibleMons;
    u16 species;
    u16 level;
    u16 form;
    Party *party = SaveArray_Party_Get(saveData);
    u8 partyCount = Party_GetCount(party);
    if (partyCount < numRequiredMons) {
        return FALSE;
    }
    u16 arr[6];
    for (i = 0; i < 6; i++) {
        arr[i] = SPECIES_NONE;
    }
    for (i = 0, numEligibleMons = 0; i < partyCount; i++) {
        Pokemon *mon = Party_GetMonByIndex(party, i);
        species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        level = GetMonData(mon, MON_DATA_LEVEL, NULL);
        form = GetMonData(mon, MON_DATA_FORM, NULL);
        if (GetMonData(mon, MON_DATA_IS_EGG, NULL) == FALSE
            && level >= 30
            && IsPokemonBannedFromBattleFrontier(species, form) != TRUE) {
            numEligibleMons++;
            arr[i] = species;
        }
    }
    if (numRequiredMons == 2) {
        for (u8 j = 0; j < partyCount; j++) {
            for (i = 0; i < partyCount; i++) {
                if (j != i && arr[j] != SPECIES_NONE && arr[j] == arr[i]) {
                    return TRUE;
                }
            }
        }
        return FALSE;
    }
    return numEligibleMons >= numRequiredMons;
}

// upon continuing battle hall challenge without previously saving
BOOL ScrCmd_BattleHallResetStreak(ScriptContext *ctx) {
    u16 type = ScriptGetVar(ctx);
    u8 *hallFlags = Save_Frontier_GetHallFlags(ctx->fieldSystem->saveData);
    BattleHall_ResetStreak(ctx->fieldSystem->saveData, hallFlags, type);
    return FALSE;
}

// returns whether the player and partner chose different mons for battle hall
BOOL ScrCmd_BattleHallCheckSpecies(ScriptContext *ctx) {
    u16 playerSpecies = ScriptGetVar(ctx);
    u16 *resultPtr = ScriptGetVarPointer(ctx);
    BattleHall_StartSpeciesCheck(ctx->taskman, playerSpecies, resultPtr);
    return TRUE;
}

static void BattleHall_StartSpeciesCheck(TaskManager *taskManager, u16 playerSpecies, u16 *resultPtr) {
    BattleHallSpeciesCheck *speciesCheck = Heap_Alloc(HEAP_ID_FIELD2, sizeof(BattleHallSpeciesCheck));
    memset(speciesCheck, 0, sizeof(BattleHallSpeciesCheck));
    speciesCheck->playerTeam = playerSpecies;
    speciesCheck->result = resultPtr;
    FieldComm_RegisterCommands((FieldSystem *)speciesCheck);
    TaskManager_Call(taskManager, Task_BattleHallSpeciesCheck, speciesCheck);
}

static BOOL Task_BattleHallSpeciesCheck(TaskManager *taskManager) {
    BattleHallSpeciesCheck *speciesCheck = TaskManager_GetEnvironment(taskManager);
    switch (speciesCheck->state) {
    case 0:
        if (Comm_SendCommand(0x84, speciesCheck, sizeof(BattleHallSpeciesCheck)) == 1) {
            speciesCheck->state++;
        }
        break;
    case 1:
        if (speciesCheck->numReceived >= 2) {
            if (speciesCheck->playerTeam == speciesCheck->partnerTeam) {
                *(speciesCheck->result) = FALSE;
            } else {
                *(speciesCheck->result) = TRUE;
            }
            speciesCheck->state++;
        }
        break;
    case 2:
        Heap_Free(speciesCheck);
        return TRUE;
    }
    return FALSE;
}

static void BattleHall_StartSelectMons(TaskManager *taskManager, void *appArgs, BattleHallChallengeType challengeType) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    BattleHallSelectMonsEnv *env = Heap_Alloc(HEAP_ID_FIELD2, sizeof(BattleHallSelectMonsEnv));
    MI_CpuFill8(env, 0, sizeof(BattleHallSelectMonsEnv));
    env->challengeType = challengeType;
    env->appArgs = appArgs;
    TaskManager_Call(fieldSystem->taskman, Task_BattleHallSelectMons, env);
}

static BOOL Task_BattleHallSelectMons(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    BattleHallSelectMonsEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        env->state = BattleHallSelectMons_OpenPartyMenu(env, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 1:
        env->state = BattleHallSelectMons_WaitPartyMenu(env, fieldSystem);
        break;
    case 2:
        env->state = BattleHallSelectMons_OpenSummary(env, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 3:
        env->state = BattleHallSelectMons_WaitSummary(env, fieldSystem);
        break;
    case 4:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

static u32 BattleHallSelectMons_OpenPartyMenu(BattleHallSelectMonsEnv *env, FieldSystem *fieldSystem, enum HeapID unused) {
    PartyMenuArgs *partyMenuArgs = Heap_Alloc(HEAP_ID_FIELD2, sizeof(PartyMenuArgs));
    MIi_CpuClearFast(0, (u32 *)partyMenuArgs, sizeof(PartyMenuArgs));
    partyMenuArgs->party = SaveArray_Party_Get(fieldSystem->saveData);
    partyMenuArgs->bag = Save_Bag_Get(fieldSystem->saveData);
    partyMenuArgs->mailbox = Save_Mailbox_Get(fieldSystem->saveData);
    partyMenuArgs->options = Save_PlayerData_GetOptionsAddr(fieldSystem->saveData);
    partyMenuArgs->panelLayout = 0;
    partyMenuArgs->context = PARTY_MENU_CONTEXT_BATTLE_HALL;
    partyMenuArgs->fieldSystem = fieldSystem;
    partyMenuArgs->partySlot = env->partySlot;
    for (u8 i = 0; i < 2; i++) {
        partyMenuArgs->selectedOrder[i] = env->selectedMons[i];
    }
    partyMenuArgs->maxLevel = 30;
    partyMenuArgs->minMonsToSelect = 1;
    partyMenuArgs->maxMonsToSelect = 1;
    partyMenuArgs->menuInputStatePtr = &fieldSystem->menuInputState;
    if (env->challengeType == BATTLE_HALL_CHALLENGE_TYPE_DOUBLE) {
        partyMenuArgs->minMonsToSelect = 2;
        partyMenuArgs->maxMonsToSelect = 2;
    }
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PartyMenu, partyMenuArgs);
    *(env->appArgs) = partyMenuArgs;
    return 1;
}

static u32 BattleHallSelectMons_WaitPartyMenu(BattleHallSelectMonsEnv *env, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 1;
    }
    PartyMenuArgs *partyMenu = *(env->appArgs);
    switch (partyMenu->partySlot) {
    case 7:
        return 4;
    case 6:
        return 4;
    default:
        MI_CpuCopy8(partyMenu->selectedOrder, env->selectedMons, 2);
        env->partySlot = partyMenu->partySlot;
        Heap_Free(partyMenu);
        *(env->appArgs) = NULL;
        return 2;
    }
}

static u32 BattleHallSelectMons_OpenSummary(BattleHallSelectMonsEnv *env, FieldSystem *fieldSystem, enum HeapID heapID) {
    SaveData *saveData = fieldSystem->saveData;
    PokemonSummaryArgs *args = Heap_AllocAtEnd(heapID, sizeof(PokemonSummaryArgs));
    MI_CpuFill8(args, 0, sizeof(PokemonSummaryArgs));
    args->options = Save_PlayerData_GetOptionsAddr(saveData);
    args->party = SaveArray_Party_Get(saveData);
    args->natDexEnabled = SaveArray_IsNatDexEnabled(saveData);
    args->unk2C = PokemonSummary_GetDefaultUnk2C(saveData);
    args->monDataType = 1;
    args->partySlot = env->partySlot;
    args->partyCount = Party_GetCount(args->party);
    args->moveToLearn = MOVE_NONE;
    args->mode = 0;
    args->ribbons = Save_SpecialRibbons_Get(saveData);
    args->isFlag982Set = PokemonSummary_IsPokeathlonUnlocked(saveData);
    PokemonSummary_SetPages(args, sBattleHallSummaryPages);
    PokemonSummaryArgs_SetPlayer(args, Save_PlayerData_GetProfile(saveData));
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PokemonSummary, args);
    *(env->appArgs) = args;
    return 3;
}

static u32 BattleHallSelectMons_WaitSummary(BattleHallSelectMonsEnv *env, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 3;
    }
    PokemonSummaryArgs *pokemonSummaryArgs = *(env->appArgs);
    env->partySlot = pokemonSummaryArgs->partySlot;
    Heap_Free(pokemonSummaryArgs);
    *(env->appArgs) = NULL;
    return 0;
}

BOOL ScrCmd_BufferBattleHallStreak(ScriptContext *ctx) {
    u32 i;
    void *records;
    FieldSystem *fieldSystem = ctx->fieldSystem;
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 strIdxWinStreak = ScriptReadByte(ctx);
    u8 strIdxCurrWinStreakTarget = ScriptReadByte(ctx);
    u8 strIdxNextWinStreakTarget = ScriptReadByte(ctx);
    u8 strIdxBP = ScriptReadByte(ctx);
    u16 *winStreakLevel = ScriptGetVarPointer(ctx);
    u16 *result = ScriptGetVarPointer(ctx);
    u32 winStreak = 0;
    u32 loadResult = 1;
    if (Save_CheckExtraChunksExist(fieldSystem->saveData) == FALSE) {
        *result = 0;
        return FALSE;
    }
    records = FrontierSpeciesRecords_Load(fieldSystem->saveData, 0x20, &loadResult);
    if (loadResult != 1) {
        winStreak = 0;
    } else {
        for (i = 0; i < MAX_SPECIES; i++) {
            winStreak += FrontierSpeciesRecords_Get(fieldSystem->saveData, records, 0, i);
        }
    }
    if (records != NULL) {
        Heap_Free(records);
    }
    BufferIntegerAsString(*messageFormat, strIdxWinStreak, winStreak, CountDigits(winStreak), PRINTING_MODE_RIGHT_ALIGN, TRUE);
    u16 battlePoints = 0;
    u32 currWinStreakLevel = 0;
    u16 prevWinStreakLevel = *winStreakLevel;
    for (i = *winStreakLevel; i < NELEMS(battleHallWinStreakBP); i++) {
        if (battleHallWinStreakBP[i].winStreakTarget <= winStreak) {
            battlePoints += battleHallWinStreakBP[i].bp;
            (*winStreakLevel)++;
            currWinStreakLevel = i;
        }
    }
    GameStats_Add(Save_GameStats_Get(ctx->fieldSystem->saveData), GAME_STAT_BATTLE_POINTS_RECEIVED, battlePoints);
    if (battlePoints) {
        FrontierData_BattlePointAction(Save_FrontierData_Get(ctx->fieldSystem->saveData), battlePoints, FRONTIER_DATA_ADD);
    }
    if (winStreak == 0) {
        *result = 0;
    } else {
        if (prevWinStreakLevel != *winStreakLevel) {
            *result = 1;
        } else {
            *result = 2;
        }
        if (prevWinStreakLevel >= NELEMS(battleHallWinStreakBP)) {
            *result = 3;
            return FALSE;
        }
    }
    u32 currWinStreakTarget = battleHallWinStreakBP[currWinStreakLevel].winStreakTarget;
    BufferIntegerAsString(*messageFormat, strIdxCurrWinStreakTarget, currWinStreakTarget, CountDigits(currWinStreakTarget), PRINTING_MODE_RIGHT_ALIGN, TRUE);
    BufferIntegerAsString(*messageFormat, strIdxNextWinStreakTarget, battleHallWinStreakBP[*winStreakLevel].winStreakTarget, CountDigits(battleHallWinStreakBP[*winStreakLevel].winStreakTarget), PRINTING_MODE_RIGHT_ALIGN, TRUE);
    BufferIntegerAsString(*messageFormat, strIdxBP, battlePoints, CountDigits(battlePoints), PRINTING_MODE_RIGHT_ALIGN, TRUE);
    return FALSE;
}

BOOL ScrCmd_BattleHallCountUsedSpecies(ScriptContext *ctx) {
    u32 i;
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *result = ScriptGetVarPointer(ctx);
    u32 numSpecies = 0;
    u32 loadResult = 1;
    if (!Save_CheckExtraChunksExist(fieldSystem->saveData)) {
        *result = 0;
        return FALSE;
    }
    void *records = FrontierSpeciesRecords_Load(fieldSystem->saveData, 0x20, &loadResult);
    if (loadResult != 1) {
        numSpecies = 0;
    } else {
        for (i = 0; i < MAX_SPECIES; i++) {
            u32 winStreak = 0;
            winStreak += FrontierSpeciesRecords_Get(fieldSystem->saveData, records, 0, i);
            winStreak += FrontierSpeciesRecords_Get(fieldSystem->saveData, records, 1, i);
            winStreak += FrontierSpeciesRecords_Get(fieldSystem->saveData, records, 2, i);
            if (winStreak > 0) {
                numSpecies++;
            }
        }
    }
    if (records != NULL) {
        Heap_Free(records);
    }
    *result = numSpecies;
    return FALSE;
}

#define BATTLE_HALL_MAX_WIN_STREAK (10000)

BOOL ScrCmd_BattleHallGetTotalStreak(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *result = ScriptGetVarPointer(ctx);
    u32 winStreak = 0;
    u32 loadResult = 1;
    if (!Save_CheckExtraChunksExist(fieldSystem->saveData)) {
        *result = 0;
        return FALSE;
    }
    void *records = FrontierSpeciesRecords_Load(fieldSystem->saveData, 0x20, &loadResult);
    if (loadResult == 1) {
        for (u32 i = 0; i < MAX_SPECIES; i++) {
            winStreak += FrontierSpeciesRecords_Get(fieldSystem->saveData, records, 0, i);
        }
    }
    if (records != NULL) {
        Heap_Free(records);
    }
    if (winStreak > BATTLE_HALL_MAX_WIN_STREAK) {
        winStreak = BATTLE_HALL_MAX_WIN_STREAK;
    }
    *result = winStreak;
    return FALSE;
}

// Unused
BOOL ScrCmd_CheckBattleHallStreakIs50(ScriptContext *ctx) {
    u16 *result = ScriptGetVarPointer(ctx);
    FrontierSave_GetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), BattleHall_GetSpeciesStat(0), 0xff);
    u32 winStreak = FrontierSave_GetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), BattleHall_GetWinStreakStat(0), 0xff);
    *result = 0;
    if (winStreak == 50) {
        *result = 1;
    }
    return FALSE;
}

void BattleHall_RecvPartnerSpecies(u32 netId, u32 unused, BattleHallSpeciesCheck *received, BattleHallSpeciesCheck *speciesCheck) {
    speciesCheck->numReceived++;
    if (Comm_GetLocalNetId() != netId) {
        speciesCheck->partnerTeam = received->playerTeam;
    }
}

void BattleHall_ResetStreak(SaveData *saveData, u8 *hallFlags, u8 challengeType) {
    u8 unk0;
    unk0 = 0;
    HallFlags_SetField(hallFlags, 5, challengeType, 0, &unk0);
    if (challengeType == 3) {
        FrontierSave_SetStat(Save_Frontier_GetStatic(saveData), 0x6a, FrontierStat_GetFriendIndex(0x6a), 0);
    }
    FrontierSave_SetStat(Save_Frontier_GetStatic(saveData), BattleHall_GetWinStreakStat(challengeType), FrontierStat_GetFriendIndex(BattleHall_GetWinStreakStat(challengeType)), 0);
}
