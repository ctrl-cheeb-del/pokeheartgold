#include "global.h"

#include "frontier/frontier.h"
#include "frontier/frontier_link_lobby.h"
#include "frontier/frontier_map.h"
#include "frontier/frontier_scrcmd.h"
#include "frontier/frontier_script_commands.h"
#include "frontier/frontier_script_context.h"
#include "frontier/frontier_trainers.h"

#include "battle_frontier_communication.h"
#include "communication_core.h"
#include "frontier_data.h"
#include "frontier_data_access.h"
#include "frontier_field_system.h"
#include "frontier_save_access.h"
#include "frontier_stat_ids_legacy.h"
#include "heap.h"
#include "link_synchronization_internal.h"
#include "party.h"
#include "party_menu.h"
#include "player_avatar.h"
#include "scrcmd_9.h"
#include "scrcmd_battle_hall.h"
#include "use_item_on_mon.h"

// Script commands of the frontier link lobby and of the link
// Battle Tower started from it (FrontierFieldSystem).

static BOOL FrontierScriptNative_WaitLinkLobbyReceive(FrontierScriptContext *ctx);
static BOOL FrontierScriptNative_WaitLinkLobbyReceiveOrAbort(FrontierScriptContext *ctx);
static BOOL FrontierScriptNative_WaitTowerLinkReceive(FrontierScriptContext *ctx);

BOOL FrtCmd_LinkLobbyAlloc(FrontierScriptContext *ctx) {
    FrontierLinkLobby *lobby = FrontierLinkLobby_New(Frontier_GetLaunchArgs(ctx->frontierSystem->frontierWork)->saveData);
    Frontier_SetData(ctx->frontierSystem->frontierWork, lobby);
    return FALSE;
}

BOOL FrtCmd_LinkLobbyFree(FrontierScriptContext *ctx) {
    FrontierLinkLobby_Free(Frontier_GetData(ctx->frontierSystem->frontierWork));
    return FALSE;
}

BOOL FrtCmd_LinkLobbySend(FrontierScriptContext *ctx) {
    u16 kind = FrontierScript_ReadVar(ctx);
    u16 value = FrontierScript_ReadVar(ctx);
    u16 secondValue = FrontierScript_ReadVar(ctx);
    u16 *result = FrontierScript_ReadVarPtr(ctx);
    *result = FrontierLinkLobby_Send(Frontier_GetData(ctx->frontierSystem->frontierWork), kind, value, secondValue);
    return TRUE;
}

BOOL FrtCmd_LinkLobbyWaitReceive(FrontierScriptContext *ctx) {
    ctx->data[0] = FrontierScriptContext_ReadHalfWord(ctx);
    FrontierScriptContext_Pause(ctx, FrontierScriptNative_WaitLinkLobbyReceive);
    return TRUE;
}

static BOOL FrontierScriptNative_WaitLinkLobbyReceive(FrontierScriptContext *ctx) {
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    if (lobby->receiveCount >= 2) {
        lobby->receiveCount = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_LinkLobbyWaitReceiveOrAbort(FrontierScriptContext *ctx) {
    ctx->data[0] = FrontierScriptContext_ReadHalfWord(ctx);
    FrontierScriptContext_Pause(ctx, FrontierScriptNative_WaitLinkLobbyReceiveOrAbort);
    return TRUE;
}

static BOOL FrontierScriptNative_WaitLinkLobbyReceiveOrAbort(FrontierScriptContext *ctx) {
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    if (lobby->receiveCount >= 2) {
        lobby->receiveCount = 0;
        return TRUE;
    }
    if (LinkSync_GetPlayerState(Comm_GetLocalNetId() ^ 1) == 0xAF) {
        ctx->frontierSystem->syncAborted = TRUE;
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_LinkLobbyCheckPartnerFacility(FrontierScriptContext *ctx) {
    u16 facility = FrontierScript_ReadVar(ctx);
    u16 *result = FrontierScript_ReadVarPtr(ctx);
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    *result = facility == lobby->partnerFacility;
    return FALSE;
}

BOOL FrtCmd_LinkLobbyRunPartyApp(FrontierScriptContext *ctx) {
    FrontierLinkLobby *lobby;
    u16 kind;
    u16 *result;
    FrontierScript_ReadVar(ctx);
    kind = FrontierScript_ReadVar(ctx);
    result = FrontierScript_ReadVarPtr(ctx);
    lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    lobby->fieldSystem = Frontier_GetLaunchArgs(ctx->frontierSystem->frontierWork)->fieldSystem;
    lobby->resultVar = result;
    FrontierLinkLobby_RunPartyApp(ctx->frontierSystem->frontierWork, lobby, kind);
    return TRUE;
}

BOOL FrtCmd_LinkLobbyGetPartyMenuResult(FrontierScriptContext *ctx) {
    u16 *first = FrontierScript_ReadVarPtr(ctx);
    u16 *second = FrontierScript_ReadVarPtr(ctx);
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    if (lobby->partyMenuArgs->partySlot == 7) {
        s32 i;
        *first = 0xFF;
        for (i = 0; i < 2; i++) {
            lobby->selectedOrder[i] = 0;
        }
    } else if (lobby->partyMenuArgs->partySlot == 6) {
        *first = lobby->partyMenuArgs->selectedOrder[0];
        (*first)--;
        *second = lobby->partyMenuArgs->selectedOrder[1];
        if (*second != 0) {
            (*second)--;
        }
    }
    Heap_Free(lobby->partyMenuArgs);
    lobby->partyMenuArgs = NULL;
    return FALSE;
}

BOOL FrtCmd_LinkLobbyGetPartnerChoice(FrontierScriptContext *ctx) {
    u16 *result = FrontierScript_ReadVarPtr(ctx);
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    *result = lobby->partnerChoice;
    return FALSE;
}

BOOL FrtCmd_LinkLobbyAction(FrontierScriptContext *ctx) {
    u8 action = FrontierScriptContext_ReadByte(ctx);
    u8 arg = FrontierScriptContext_ReadByte(ctx);
    ctx->scriptPtr++;
    u16 *result = FrontierScript_ReadVarPtr(ctx);
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    FrontierLaunchArgs *launchArgs = Frontier_GetLaunchArgs(ctx->frontierSystem->frontierWork);

    switch (action) {
    case 0:
        FrontierLink_RegisterCommands(lobby);
        break;
    case 1:
        *result = lobby->partnerSpecies[0];
        break;
    case 2:
        if (arg == FRONTIER_FACILITY_TOWER) {
            *result = 0;
            if (lobby->species[0] == lobby->partnerSpecies[0] || lobby->species[0] == lobby->partnerSpecies[1]) {
                *result = *result + 1;
            }
            if (lobby->species[1] == lobby->partnerSpecies[0] || lobby->species[1] == lobby->partnerSpecies[1]) {
                *result = *result + 2;
            }
        } else if (arg == FRONTIER_FACILITY_HALL) {
            if (lobby->species[0] == lobby->partnerSpecies[0]) {
                *result = 0;
            } else {
                *result = 1;
            }
        } else if (arg == FRONTIER_FACILITY_CASTLE || arg == FRONTIER_FACILITY_ARCADE) {
            *result = 0;
            if (lobby->species[0] == lobby->partnerSpecies[0] || lobby->species[0] == lobby->partnerSpecies[1]) {
                *result = *result + 1;
            }
            if (lobby->species[1] == lobby->partnerSpecies[0] || lobby->species[1] == lobby->partnerSpecies[1]) {
                *result = *result + 2;
            }
        }
        break;
    case 3:
        *result = FrontierSave_GetStat(Save_Frontier_GetStatic(launchArgs->saveData), 0x6A, FrontierStat_GetFriendIndex(0x6A));
        break;
    case 4: {
        FrontierSave *frontierSave = Save_Frontier_GetStatic(launchArgs->saveData);
        u32 stat = BattleHall_GetSpeciesStat(FRONTIER_CHALLENGE_LINK_MULTI);
        *result = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleHall_GetSpeciesStat(FRONTIER_CHALLENGE_LINK_MULTI)));
        break;
    }
    case 5:
        *result = lobby->species[arg];
        break;
    case 6:
        BattleHall_ResetStreak(launchArgs->saveData, Save_Frontier_GetHallFlags(launchArgs->saveData), FRONTIER_CHALLENGE_LINK_MULTI);
        break;
    case 7:
        lobby->facility = arg;
        break;
    case 8:
        *result = lobby->partnerValue74;
        break;
    case 9:
        *result = lobby->facility;
        break;
    case 10:
        *result = lobby->partnerValue71;
        break;
    case 11: {
        u32 stat;
        u16 streak;
        *result = 1;
        stat = FrontierLinkLobby_GetWinStreakStat(lobby->facility);
        streak = FrontierSave_GetStat(Save_Frontier_GetStatic(lobby->saveData), stat, FrontierStat_GetFriendIndex(stat));
        if (streak != lobby->partnerStreak) {
            FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), stat, FrontierStat_GetFriendIndex(stat), 0);
            stat = FrontierLinkLobby_GetStreakActiveStat(lobby->facility);
            FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), stat, FrontierStat_GetFriendIndex(stat), 0);
            *result = 0;
        }
        break;
    }
    case 12: {
        u32 stat = FrontierLinkLobby_GetStreakActiveStat(lobby->facility);
        *result = FrontierSave_GetStat(Save_Frontier_GetStatic(lobby->saveData), stat, FrontierStat_GetFriendIndex(stat));
        if (*result == 0) {
            stat = FrontierLinkLobby_GetWinStreakStat(lobby->facility);
            FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), stat, FrontierStat_GetFriendIndex(stat), 0);
            if (lobby->facility == FRONTIER_FACILITY_TOWER) {
                FrontierData_TowerRoundAction(Save_FrontierData_Get(lobby->saveData), TOWER_MODE_6, FRONTIER_DATA_RESET);
            }
            if (lobby->facility == FRONTIER_FACILITY_CASTLE) {
                FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), 0x88, FrontierStat_GetFriendIndex(0x88), 0);
                FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), 0x89, FrontierStat_GetFriendIndex(0x89), 0);
            }
            if (lobby->facility == FRONTIER_FACILITY_FACTORY_LV50) {
                FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), BattleFactory_GetTradeCountStat(0, FRONTIER_CHALLENGE_LINK_MULTI), FrontierStat_GetFriendIndex(BattleFactory_GetTradeCountStat(0, FRONTIER_CHALLENGE_LINK_MULTI)), 0);
            }
            if (lobby->facility == FRONTIER_FACILITY_FACTORY_OPEN) {
                FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), BattleFactory_GetTradeCountStat(1, FRONTIER_CHALLENGE_LINK_MULTI), FrontierStat_GetFriendIndex(BattleFactory_GetTradeCountStat(1, FRONTIER_CHALLENGE_LINK_MULTI)), 0);
            }
        } else {
            FrontierSave_SetStat(Save_Frontier_GetStatic(lobby->saveData), stat, FrontierStat_GetFriendIndex(stat), 0);
        }
        break;
    }
    case 13: {
        s32 i;
        for (i = 0; i < 2; i++) {
            lobby->selectedOrder[i] = 0;
        }
        lobby->partySlot = 0;
        break;
    }
    }
    return FALSE;
}

BOOL FrtCmd_LinkLobbyStartTower(FrontierScriptContext *ctx) {
    FrontierLaunchArgs *args = Frontier_GetLaunchArgs(ctx->frontierSystem->frontierWork);
    FrontierLinkLobby *lobby = Frontier_GetData(ctx->frontierSystem->frontierWork);
    FrontierLinkLobby backup = *lobby;
    FrontierFieldSystem *frontierFsys;
    s32 i;

    FrontierLinkLobby_Free(lobby);
    frontierFsys = FrontierFieldSystem_New(args->saveData, FALSE, TOWER_MODE_6);
    Frontier_SetData(ctx->frontierSystem->frontierWork, frontierFsys);
    if (frontierFsys->towerMode == TOWER_MODE_6) {
        Frontier_RecordLinkPlayerLocations(args->saveData);
    }
    for (i = 0; i < frontierFsys->numMons; i++) {
        frontierFsys->partyMonIndexes[i] = backup.partySlots[i];
        frontierFsys->partyMonSpecies[i] = backup.species[i];
        frontierFsys->partyMonItems[i] = backup.items[i];
    }
    frontierFsys->linkAllyMonSpecies[0] = backup.partnerSpecies[0];
    frontierFsys->linkAllyMonSpecies[1] = backup.partnerSpecies[1];
    frontierFsys->linkAllyGender = backup.partnerGender;
    frontierFsys->multiBattleAllyID = frontierFsys->linkAllyGender + 5;
    if (Comm_GetLocalNetId() == 0) {
        FrontierFieldSystem_SetRandomFrontierTrainers(frontierFsys, args->saveData);
    }
    HealParty(SaveArray_Party_Get(args->saveData));
    FrontierLink_RegisterCommands(frontierFsys);
    frontierFsys->linkReceiveCount = 0;
    return FALSE;
}

BOOL FrtCmd_TowerLinkSendTrainers(FrontierScriptContext *ctx) {
    u16 *result = FrontierScript_ReadVarPtr(ctx);
    *result = BattleTowerLink_SendTrainers(Frontier_GetData(ctx->frontierSystem->frontierWork));
    return TRUE;
}

BOOL FrtCmd_TowerLinkWaitReceive(FrontierScriptContext *ctx) {
    FrontierScriptContext_Pause(ctx, FrontierScriptNative_WaitTowerLinkReceive);
    return TRUE;
}

static BOOL FrontierScriptNative_WaitTowerLinkReceive(FrontierScriptContext *ctx) {
    FrontierFieldSystem *frontierFsys = Frontier_GetData(ctx->frontierSystem->frontierWork);
    if (frontierFsys->linkReceiveCount < 2) {
        return FALSE;
    }
    frontierFsys->linkReceiveCount = 0;
    return TRUE;
}

BOOL FrtCmd_TowerFree(FrontierScriptContext *ctx) {
    FrontierFieldSystem_Free(Frontier_GetData(ctx->frontierSystem->frontierWork));
    return FALSE;
}
