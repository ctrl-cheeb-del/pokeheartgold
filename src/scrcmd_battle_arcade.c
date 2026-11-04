#include "scrcmd_battle_arcade.h"

#include "global.h"

#include "assert.h"
#include "bag.h"
#include "field_system.h"
#include "frontier_data.h"
#include "game_stats.h"
#include "heap.h"
#include "launch_application.h"
#include "mail.h"
#include "message_format.h"
#include "party.h"
#include "party_menu.h"
#include "player_avatar.h"
#include "player_data.h"
#include "pokedex_util.h"
#include "save.h"
#include "save_special_ribbons.h"
#include "scrcmd.h"
#include "script.h"
#include "script_manager.h"
#include "task.h"
#include "frontier_save_access.h"
#include "communication_core.h"
#include "frontier_field_system.h"
#include "field_misc_util.h"
#include "frontier_stat_ids_legacy.h"
#include "pokemon_summary.h"
#include "field_comm_cmds.h"

typedef enum BattleArcadeChallengeType {
    BATTLE_ARCADE_CHALLENGE_TYPE_SINGLE,
    BATTLE_ARCADE_CHALLENGE_TYPE_DOUBLE,
    BATTLE_ARCADE_CHALLENGE_TYPE_MULTI,
} BattleArcadeChallengeType;

typedef struct FrontierSelectMonsEnv {
    u32 state;
    u8 challengeType;
    u8 partySlot;
    u8 selectedOrder[3];
    u8 filler[2];
    void **appArgs;
} FrontierSelectMonsEnv;

static void BattleArcade_ResetStreak(SaveData *, u8 *, u8);
static void BattleArcade_StartSelectMons(TaskManager *, void *, BattleArcadeChallengeType);
static BOOL Task_BattleArcadeSelectMons(TaskManager *);
static void BattleArcade_StartTeamCheck(TaskManager *, u16, u16, u16 *);
static BOOL Task_BattleArcadeTeamCheck(TaskManager *);
static u32 BattleArcadeSelectMons_OpenPartyMenu(FrontierSelectMonsEnv *, FieldSystem *, u32);
static u32 BattleArcadeSelectMons_WaitPartyMenu(FrontierSelectMonsEnv *, FieldSystem *);
static u32 BattleArcadeSelectMons_OpenSummary(FrontierSelectMonsEnv *, FieldSystem *, enum HeapID);
static u32 BattleArcadeSelectMons_WaitSummary(FrontierSelectMonsEnv *, FieldSystem *);

static const u8 sBattleArcadeSummaryPages[] = {
    0,
    1,
    2,
    3,
    4,
};

BOOL ScrCmd_BattleArcadeAction(ScriptContext *ctx) {
    u16 command = ScriptReadHalfword(ctx);
    u16 arg = ScriptGetVar(ctx);
    u16 *result = ScriptGetVarPointer(ctx);
    Save_Frontier_GetArcadeChallenge(ctx->fieldSystem->saveData);
    u8 *arcadeFlags = Save_Frontier_GetArcadeFlags(ctx->fieldSystem->saveData);
    void *appArgs = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    switch (command) {
    case 0:
        *result = PartyIsValidForFrontier(arg, ctx->fieldSystem->saveData, 0);
        break;
    case 1: // Unused
        if (arg == 3) {
            *result = FrontierSave_GetStat(Save_Frontier_GetStatic(ctx->fieldSystem->saveData), 110, FrontierStat_GetFriendIndex(110));
        } else {
            *result = ArcadeFlags_GetField(arcadeFlags, 8, arg, 0, 0);
        }
        break;
    case 3: // Unused
        BattleArcade_ResetStreak(ctx->fieldSystem->saveData, arcadeFlags, arg);
        break;
    case 4: {
        BattleArcadeChallengeType challengeType;
        if (arg == 0) {
            challengeType = BATTLE_ARCADE_CHALLENGE_TYPE_SINGLE;
        } else if (arg == 1) {
            challengeType = BATTLE_ARCADE_CHALLENGE_TYPE_DOUBLE;
        } else {
            challengeType = BATTLE_ARCADE_CHALLENGE_TYPE_MULTI;
        }
        BattleArcade_StartSelectMons(ctx->taskman, appArgs, challengeType);
        return TRUE;
    }
    default:
        GF_ASSERT(FALSE);
        *result = 0;
        break;
    }
    return FALSE;
}

BOOL ScrCmd_BattleArcadeResetStreak(ScriptContext *ctx) {
    u16 challengeType = ScriptGetVar(ctx);
    BattleArcade_ResetStreak(ctx->fieldSystem->saveData, Save_Frontier_GetArcadeFlags(ctx->fieldSystem->saveData), challengeType);
    return FALSE;
}

static void BattleArcade_ResetStreak(SaveData *saveData, u8 *arcadeFlags, u8 challengeType) {
    u8 streak;
    streak = 0;
    ArcadeFlags_SetField(arcadeFlags, 8, challengeType, 0, &streak);
    if (challengeType == 3) {
        FrontierSave_SetStat(Save_Frontier_GetStatic(saveData), 110, FrontierStat_GetFriendIndex(110), 0);
    }
    FrontierSave_SetStat(Save_Frontier_GetStatic(saveData), BattleArcade_GetWinStreakStat(challengeType), FrontierStat_GetFriendIndex(BattleArcade_GetWinStreakStat(challengeType)), 0);
}

BOOL ScrCmd_BattleArcadeCheckTeam(ScriptContext *ctx) {
    u16 firstMon = ScriptGetVar(ctx);
    u16 secondMon = ScriptGetVar(ctx);
    u16 *result = ScriptGetVarPointer(ctx);
    BattleArcade_StartTeamCheck(ctx->taskman, firstMon, secondMon, result);
    return TRUE;
}

static void BattleArcade_StartTeamCheck(TaskManager *taskManager, u16 firstMon, u16 secondMon, u16 *result) {
    BattleArcadeTeamCheck *teamCheck = Heap_Alloc(HEAP_ID_FIELD2, sizeof(BattleArcadeTeamCheck));
    memset(teamCheck, 0, sizeof(BattleArcadeTeamCheck));
    teamCheck->playerTeam[0] = firstMon;
    teamCheck->playerTeam[1] = secondMon;
    teamCheck->result = result;
    FieldComm_RegisterCommands(teamCheck);
    TaskManager_Call(taskManager, Task_BattleArcadeTeamCheck, teamCheck);
}

static BOOL Task_BattleArcadeTeamCheck(TaskManager *taskManager) {
    BattleArcadeTeamCheck *teamCheck = TaskManager_GetEnvironment(taskManager);
    switch (teamCheck->state) {
    case 0:
        if (Comm_SendCommand(134, teamCheck, 16) == 1) {
            teamCheck->state++;
        }
        break;
    case 1:
        if (teamCheck->numReceived >= 2) {
            *teamCheck->result = 0;
            if (teamCheck->playerTeam[0] == teamCheck->partnerTeam[0] || teamCheck->playerTeam[0] == teamCheck->partnerTeam[1]) {
                *teamCheck->result += 1;
            }
            if (teamCheck->playerTeam[1] == teamCheck->partnerTeam[0] || teamCheck->playerTeam[1] == teamCheck->partnerTeam[1]) {
                *teamCheck->result += 2;
            }
            teamCheck->state++;
        }
        break;
    case 2:
        Heap_Free(teamCheck);
        return TRUE;
    }
    return FALSE;
}

static void BattleArcade_StartSelectMons(TaskManager *taskManager, void *appArgs, BattleArcadeChallengeType challengeType) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FrontierSelectMonsEnv *env = Heap_Alloc(HEAP_ID_FIELD2, sizeof(FrontierSelectMonsEnv));
    MI_CpuFill8(env, 0, sizeof(FrontierSelectMonsEnv));
    env->challengeType = challengeType;
    env->appArgs = appArgs;
    TaskManager_Call(fieldSystem->taskman, Task_BattleArcadeSelectMons, env);
}

static BOOL Task_BattleArcadeSelectMons(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FrontierSelectMonsEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        env->state = BattleArcadeSelectMons_OpenPartyMenu(env, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 1:
        env->state = BattleArcadeSelectMons_WaitPartyMenu(env, fieldSystem);
        break;
    case 2:
        env->state = BattleArcadeSelectMons_OpenSummary(env, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 3:
        env->state = BattleArcadeSelectMons_WaitSummary(env, fieldSystem);
        break;
    case 4:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

static u32 BattleArcadeSelectMons_OpenPartyMenu(FrontierSelectMonsEnv *env, FieldSystem *fieldSystem, u32 heapID) {
    PartyMenuArgs *partyMenu = Heap_Alloc(HEAP_ID_FIELD2, sizeof(PartyMenuArgs));
    MIi_CpuClearFast(0, (u32 *)partyMenu, sizeof(PartyMenuArgs));
    partyMenu->party = SaveArray_Party_Get(fieldSystem->saveData);
    partyMenu->bag = Save_Bag_Get(fieldSystem->saveData);
    partyMenu->mailbox = Save_Mailbox_Get(fieldSystem->saveData);
    partyMenu->options = Save_PlayerData_GetOptionsAddr(fieldSystem->saveData);
    partyMenu->panelLayout = 0;
    partyMenu->context = PARTY_MENU_CONTEXT_23;
    partyMenu->fieldSystem = fieldSystem;
    partyMenu->partySlot = env->partySlot;
    for (u8 i = 0; i < 3; i++) {
        partyMenu->selectedOrder[i] = env->selectedOrder[i];
    }
    partyMenu->maxLevel = 100;
    partyMenu->minMonsToSelect = 3;
    partyMenu->maxMonsToSelect = 3;
    partyMenu->menuInputStatePtr = &(fieldSystem->menuInputState);
    if (env->challengeType == BATTLE_ARCADE_CHALLENGE_TYPE_MULTI) {
        partyMenu->minMonsToSelect = 2;
        partyMenu->maxMonsToSelect = 2;
    }
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PartyMenu, partyMenu);
    *(env->appArgs) = partyMenu;
    return 1;
}

static u32 BattleArcadeSelectMons_WaitPartyMenu(FrontierSelectMonsEnv *env, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return TRUE;
    }
    PartyMenuArgs *partyMenu = *(env->appArgs);
    switch (partyMenu->partySlot) {
    case 7:
        return 4;
    case 6:
        return 4;
    }
    MI_CpuCopy8(partyMenu->selectedOrder, env->selectedOrder, 3);
    env->partySlot = partyMenu->partySlot;
    Heap_Free(partyMenu);
    *(env->appArgs) = NULL;
    return 2;
}

static u32 BattleArcadeSelectMons_OpenSummary(FrontierSelectMonsEnv *env, FieldSystem *fieldSystem, enum HeapID heapID) {
    SaveData *saveData = fieldSystem->saveData;
    PokemonSummaryArgs *summaryArgs = Heap_AllocAtEnd(heapID, sizeof(PokemonSummaryArgs));
    MI_CpuFill8(summaryArgs, 0, sizeof(PokemonSummaryArgs));
    summaryArgs->options = Save_PlayerData_GetOptionsAddr(saveData);
    summaryArgs->party = SaveArray_Party_Get(saveData);
    summaryArgs->natDexEnabled = SaveArray_IsNatDexEnabled(saveData);
    summaryArgs->unk2C = PokemonSummary_GetDefaultUnk2C(saveData);
    summaryArgs->monDataType = 1;
    summaryArgs->partySlot = env->partySlot;
    summaryArgs->partyCount = Party_GetCount(summaryArgs->party);
    summaryArgs->moveToLearn = MOVE_NONE;
    summaryArgs->mode = 0;
    summaryArgs->ribbons = Save_SpecialRibbons_Get(saveData);
    summaryArgs->isFlag982Set = PokemonSummary_IsPokeathlonUnlocked(saveData);
    PokemonSummary_SetPages(summaryArgs, sBattleArcadeSummaryPages);
    PokemonSummaryArgs_SetPlayer(summaryArgs, Save_PlayerData_GetProfile(saveData));
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PokemonSummary, summaryArgs);
    *(env->appArgs) = summaryArgs;
    return 3;
}

static u32 BattleArcadeSelectMons_WaitSummary(FrontierSelectMonsEnv *env, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 3;
    }
    PokemonSummaryArgs *pokemonSummaryArgs = *(env->appArgs);
    env->partySlot = pokemonSummaryArgs->partySlot;
    Heap_Free(pokemonSummaryArgs);
    *(env->appArgs) = NULL;
    return 0;
}

void BattleArcade_RecvPartnerTeam(u32 netId, u32 unused, BattleArcadeTeamCheck *received, BattleArcadeTeamCheck *teamCheck) {
    teamCheck->numReceived++;
    if (Comm_GetLocalNetId() != netId) {
        teamCheck->partnerTeam[0] = received->playerTeam[0];
        teamCheck->partnerTeam[1] = received->playerTeam[1];
    }
}
