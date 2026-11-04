// clang-format off
#include "constants/comm_type.h"

#include "comm_state_private.h"
// clang-format on

#include "comm_state_internal.h"
#include "comm_wireless.h"
#include "communication_command.h"
#include "communication_error.h"
#include "communication_player_state.h"
#include "dwcaccount.h"
#include "link_synchronization.h"
#include "network_overlay_loader.h"
#include "overlay_00_thumb.h"
#include "overlay_13_arm_2.h"
#include "sound_playback.h"
#include "system.h"
#include "wifi_connection_result.h"
#include "wireless_manager.h"
#include "wireless_status_icon.h"

typedef struct CommStateWork {
    WifiClubStatusData *wifiClubData;
    u8 selectedOrder[8];
    MATHRandContext32 mathRandContext;
    void (*stateFunc)(void);
    SaveData *saveData;
    PlayerProfile *profile;
    LinkBattleRuleset *rules;
    u32 wifiError;
    s32 wifiErrorArg1;
    s32 wifiErrorArg2;
    s32 shutdownTimer;
    s32 timer;
    u16 joinRetries;
    u8 maxEntries;
    u8 memberCount;
    u8 joinReply;
    u8 slot;
    u8 linkMode;
    u8 beaconId;
    u8 waitHostDisconnect;
    s8 matchFriendIndex;
    u8 renewTgid;
    u8 watchMembers;
    u8 reportErrors;
    u8 unk55;
    u8 errorScreen;
    u8 refuseJoins;
    u8 seenGames;
    u8 unk59[3];
    u8 peerDisconnected;
    u8 errorKind;
    u8 unk5E;
    u8 unkEF;
    const struct WiFiPlazaPlayer *plazaPlayer;
    u8 plazaLobbyStarted;
} CommStateWork;

static void CommState_Init(SaveData *saveData, s8 linkMode);
static void CommState_Free(void);
static void CommState_ShutdownWait(void);
static void CommState_SetState(void (*stateFunc)(), int timer);
static void CommState_EndWireless(void);
static void CommState_StopWireless(void);
static void CommState_ParentStart(void);
static void CommState_WaitLinked(void);
static void CommState_ParentLinked(void);
static void CommState_ChildStartScan(void);
static void CommState_ChildScanning(void);
static void CommState_ChildConnecting(void);
static void CommState_ChildWaitLinked(void);
static void CommState_ChildRescanStop(void);
static void CommState_ChildRescan(void);
static void CommState_ChildLinked(void);
static void CommState_RestartScanStop(void);
static void CommState_RestartScanStart(void);
static void CommState_Idle(void);
static void CommState_FreeWhenDone(void);
static void CommState_ResumeParentWaitAlone(void);
static void CommState_ResumeChildStop(void);
static void CommState_ShutdownWaitStopped(void);
static void CommState_AlternateInit(void);
static void CommState_AlternateScan(void);
static void CommState_AlternateWaitStopped(void);
static void CommState_AlternateStartParent(void);
static void CommState_AlternateParentWait(void);
static void CommState_AlternateStartScan(void);
static void CommState_JoinWaitStopped(void);
static void CommState_JoinStartScan(void);
static void CommState_JoinConnect(void);
static void CommState_JoinWaitLinked(void);
static void CommState_JoinWaitReply(void);
static void CommState_Joined(void);
static void CommState_JoinFailed(void);
static void CommState_JoinRetry(void);
static void CommState_AlternateLinked(void);
static void CommState_RestartIdle(void);
static void CommState_ReconnectStop(void);
static void CommState_ReconnectScan(void);
static void CommState_ReconnectWaitParent(void);
static void CommState_ReconnectWaitLinked(void);
static void CommState_BeaconWatch(void);
static void CommState_OnBeacon(u32 ggid, s32 info);
static void CommState_BeaconWatchScan(void);
static void CommState_BeaconWatchInit(void);
static void CommState_MysteryGiftParentStart(void);
static void CommState_MysteryGiftChildStart(void);
static void CommState_WifiFailed(void);
static void CommState_WifiTimedOut(void);
static void CommState_WifiDisconnected(void);
static void CommState_WifiCancelled(void);
static void CommState_WifiConnected(void);
static void CommState_WifiLobby(void);
static void CommState_WifiStartMatch(void);
static void CommState_WifiJoinLobby(void);
static void CommState_WifiDisconnect(void);
static void CommState_WifiShutdown(void);
static BOOL CommState_CheckDwcError(void);
static void CommState_WifiLogin(void);
static void CommState_WifiClubStart(void);
static void CommState_SetErrorScreen(s8 errorScreen);
static void CommState_PlazaStart(void);
static void CommState_PlazaWaitLobby(void);
static void CommState_PlazaLobby(void);
static s32 CommState_PlazaCheckWifiResult(s32 result);
static s32 CommState_PlazaUpdateLobby(void);
static int CommState_PlazaUpdate(void);
static void CommState_PlazaUpdateMatch(s32 *matchResult);
static void CommState_PlazaLogout(void);
static void CommState_PlazaWaitLogout(void);
static void CommState_PlazaLobbyFailed(void);
static void CommState_PlazaMatchConnected(void);
static void CommState_PlazaMatching(void);
static void CommState_PlazaEndMatch(void);
static void CommState_PlazaTimedOut(void);

static CommStateWork *sCommState = NULL;

void (*const gCommLinkedStates[3])(void) = { CommState_ParentLinked, CommState_ChildLinked, NULL };

static u8 sJoinAccepted[] = " GAME";
static u8 sJoinRequest[] = "FREAK";
static u8 sJoinRefused[] = " FULL";

u32 CommState_GetSyncPacketSize(void) {
    return 70;
}

static void CommState_Init(SaveData *saveData, s8 linkMode) {
    if (sCommState == NULL) {
        GF_ASSERT(saveData);
        CommWireless_StartUp();
        sCommState = Heap_Alloc(HEAP_ID_15, sizeof(CommStateWork));
        ;
        MI_CpuClear8(sCommState, sizeof(CommStateWork));
        sCommState->timer = 50;
        sCommState->renewTgid = 1;
        sCommState->saveData = saveData;
        sCommState->profile = Save_PlayerData_GetProfile(saveData);
        sCommState->maxEntries = 2;
        sCommState->joinReply = 0;
        sCommState->refuseJoins = 0;
        sCommState->linkMode = linkMode;
        CommRandom_Init(&sCommState->mathRandContext);
        Comm_RegisterCommandTable(0, 0, 0);
        if ((linkMode != COMM_TYPE_UNION) && (linkMode != COMM_TYPE_PARTY) && (linkMode != COMM_TYPE_MYSTERY_GIFT)) {
            WirelessStatusIcon_Create();
        }
    }
}

static void CommState_Free(void) {
    if (sCommState) {
        Comm_FreeCommandTable();
        if (sCommState->wifiClubData) {
            Heap_Free(sCommState->wifiClubData);
        }
        if (CommState_IsWifi()) {
            Heap_Destroy(HEAP_ID_48);
        }
        WirelessStatusIcon_Destroy();
        CommWireless_Terminate();
        Heap_Free(sCommState);
        Heap_Destroy(HEAP_ID_15);
        sCommState = NULL;
    }
}

BOOL CommState_Exists(void) {
    return sCommState ? TRUE : FALSE;
}

void CommState_StartParentSession(SaveData *saveData, s8 linkMode, s8 beaconId, LinkBattleRuleset *rules) {
    if (!Comm_IsActive()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800);
        CommState_Init(saveData, linkMode);
        sCommState->beaconId = beaconId;
        sCommState->rules = rules;
        CommState_SetState(CommState_ParentStart, 0);
    }
}

void CommState_StartChildSession(SaveData *saveData, s8 linkMode, s8 beaconId, LinkBattleRuleset *rules) {
    if (!Comm_IsActive()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800);
        CommState_Init(saveData, linkMode);
        sCommState->beaconId = beaconId;
        sCommState->rules = rules;
        CommState_SetState(CommState_ChildStartScan, 0);
    }
}

void CommState_ConnectToSlot(int slot) {
    sCommState->slot = slot;
    CommState_SetState(CommState_ChildConnecting, 0);
}

void CommState_RestartScan(void) {
    Comm_ResetWorkAndParents();
    CommState_SetState(CommState_RestartScanStop, 0);
}

static void CommState_ShutdownWait(void) {
    if (sCommState->shutdownTimer > 0) {
        sCommState->shutdownTimer--;
    } else if (!sCommState->shutdownTimer) {
        CommState_ShowRestartErrorAndHalt();
    }
    if (sCommState->timer) {
        sCommState->timer--;
    }
    if (CommWireless_Stop() && !sCommState->timer) {
        Comm_Shutdown();
        CommState_SetState(CommState_FreeWhenDone, 0);
    }
}

void CommState_RequestShutdown(void) {
    if (sCommState) {
        sCommState->shutdownTimer = 1800;
        CommState_SetState(CommState_ShutdownWait, 5);
    }
}

void CommState_SetEntry(u32 enabled) {
    Wireless_SetEntry(enabled);
}

s32 CommState_IsLinked(void) {
    void (*const linkedStates[3])(void);
    ARRAY_ASSIGN(linkedStates, gCommLinkedStates);
    void (*func)(void) = sCommState->stateFunc;
    if (!sCommState) {
        return 0;
    }
    for (int i = 0; linkedStates[i] != NULL; i++) {
        if (func == linkedStates[i]) {
            return 1;
        }
    }
    return 0;
}

void CommState_StartAlternateSearch(SaveData *saveData) {
    if (sCommState == NULL) {
        if (!Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800)) {
            CommState_ShowRestartErrorAndHalt();
        }
        CommState_Init(saveData, 9);
        sCommState->linkMode = COMM_TYPE_UNION;
        sCommState->beaconId = 0;
        CommState_SetState(CommState_AlternateInit, 0);
    }
}

void CommState_JoinParent(s8 slot) {
    sCommState->slot = slot;
    sCommState->joinRetries = 3;
    Wireless_SetEntryLocked(1);
    WirelessStatusIcon_Create();
    CommState_SetState(CommState_JoinWaitStopped, 0);
}

s32 CommState_GetJoinResult(void) {
    if (sCommState == NULL) {
        return -1;
    }
    if (sCommState->stateFunc == CommState_Joined) {
        return 1;
    }
    if (sCommState->stateFunc == CommState_JoinFailed) {
        return -1;
    } else {
        return 0;
    }
}

s32 CommState_IsAlternateLinked(void) {
    if (sCommState == NULL) {
        return 0;
    }
    if (sCommState->stateFunc == CommState_AlternateLinked) {
        return 1;
    }
    return 0;
}

void CommState_ResumeAlternateSearch(void) {
    Wireless_SetEntryLocked(0);
    if ((sCommState->watchMembers != 1) || (sCommState->reportErrors != 1) || (sCommState->linkMode == COMM_TYPE_UNION)) {
        CommState_SetErrorWatch(FALSE, FALSE);
    }
    WirelessStatusIcon_Destroy();
    sCommState->linkMode = COMM_TYPE_UNION;
    sCommState->refuseJoins = 0;
    Wireless_SetMaxEntries(sCommState->maxEntries);
    if (!Comm_GetLocalNetId()) {
        Wireless_SetEntryClosed(1);
        CommState_SetState(CommState_ResumeParentWaitAlone, 15);
    } else {
        CommState_SetState(CommState_ResumeChildStop, 5);
    }
}

s32 CommState_IsAlternateSearchReady(void) {
    if (sCommState == NULL) {
        return 1;
    } else if (sCommState->stateFunc != CommState_AlternateWaitStopped) {
        return 1;
    }
    return 0;
}

void CommState_StopAlternateSearch(void) {
    if (sCommState) {
        CommState_SetState(CommState_ShutdownWaitStopped, 5);
    }
}

void CommState_RefuseJoins(void) {
    if (sCommState) {
        sCommState->refuseJoins = 1;
        Wireless_SetEntryLocked(1);
    }
}

void CommState_RefuseJoinsAndRestart(void) {
    if (sCommState) {
        sCommState->refuseJoins = 1;
        Wireless_SetEntryLocked(1);
        CommState_SetState(CommState_RestartIdle, 0);
    }
}

void CommState_SetUnionAppLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_UNION_APP;
}

void CommState_SetUnionRoomLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_UNION;
}

void CommState_StartMysteryGiftParent(SaveData *saveData, s8 linkMode) {
    if (!Comm_IsActive()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800);
        CommState_Init(saveData, linkMode);
        CommState_SetState(CommState_MysteryGiftParentStart, 0);
    }
}

void CommState_StartMysteryGiftChild(SaveData *saveData, s8 linkMode) {
    if (!Comm_IsActive()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800);
        CommState_Init(saveData, linkMode);
        CommState_SetState(CommState_MysteryGiftChildStart, 0);
    }
}

void CommState_Main(void) {
    if (sCommState && sCommState->stateFunc) {
        sCommState->stateFunc();
    }
    if (CommState_IsWifi()) {
        WirelessStatusIcon_SetLevel(3 - DWC_GetLinkLevel());
    } else if (CommWireless_Exists()) {
        WirelessStatusIcon_SetLevel(3 - WM_GetLinkLevel());
    }
}

static void CommState_SetState(void (*stateFunc)(), int timer) {
    sCommState->stateFunc = stateFunc;
    sCommState->timer = timer;
}

static void CommState_EndWireless(void) {
    if (!CommState_IsWifi()) {
        if (!CommWireless_IsIdle()) {
            return;
        } else {
            Comm_EnableKeySync();
            CommWireless_SetManagerEnded(TRUE);
        }
    }
    CommState_SetState(CommState_Idle, 0);
}

static void CommState_StopWireless(void) {
    if (CommWireless_Stop()) {
        Comm_ResetWork();
        CommState_SetState(CommState_EndWireless, 0);
    }
}

static void CommState_ParentStart(void) {
    if (CommWireless_IsStartedUp()) {
        CommWireless_Init(sCommState->profile, 1);
        CommPlayerInfo_Init(sCommState->saveData, sCommState->rules);
        if (Comm_StartParent(1, 1, 512, 1)) {
            Comm_RequestTransferMode1();
            CommState_SetState(CommState_WaitLinked, 0);
        }
    }
}

static void CommState_WaitLinked(void) {
    if (Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        CommState_SetState(CommState_ParentLinked, 0);
    }
}

static void CommState_ParentLinked(void) {
    if (!Comm_IsActive()) {
        CommState_SetState(CommState_FreeWhenDone, 0);
    }
}

static void CommState_ChildStartScan(void) {
    if (CommWireless_IsStartedUp()) {
        CommWireless_Init(sCommState->profile, 1);
        CommPlayerInfo_Init(sCommState->saveData, sCommState->rules);
        if (Comm_StartScan(1, 1, 512)) {
            Comm_RequestTransferMode1();
            CommState_SetState(CommState_ChildScanning, 0);
        }
    }
}

static void CommState_ChildScanning(void) {
    CommWireless_UpdateParents();
}

static void CommState_ChildConnecting(void) {
    CommWireless_UpdateParents();
    if (Comm_ConnectToParent(sCommState->slot)) {
        CommState_SetState(CommState_ChildWaitLinked, 10);
    }
}

static void CommState_ChildWaitLinked(void) {
    if (Comm_HasLinkError()) {
        CommState_SetState(CommState_ChildRescanStop, 0);
    }
    if (Comm_IsNetIdConnected(Comm_GetLocalNetId()) && Comm_GetLocalNetId()) {
        CommState_SetState(CommState_ChildLinked, 0);
    }
}

static void CommState_ChildRescanStop(void) {
    CommWireless_Stop();
    CommState_SetState(CommState_ChildRescan, 2);
}

static void CommState_ChildRescan(void) {
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    if (CommWireless_IsIdle() && Comm_StartScan(0, 1, 512)) {
        Comm_RequestTransferMode1();
        CommState_SetState(CommState_ChildConnecting, 10);
    }
}

static void CommState_ChildLinked(void) {
    if (!Comm_IsActive()) {
        CommState_SetState(CommState_FreeWhenDone, 0);
    }
}

static void CommState_RestartScanStop(void) {
    CommWireless_Stop();
    CommState_SetState(CommState_RestartScanStart, 2);
}

static void CommState_RestartScanStart(void) {
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    if (CommWireless_IsIdle() && Comm_StartScan(0, 1, 512)) {
        Comm_RequestTransferMode1();
        CommState_SetState(CommState_ChildScanning, 10);
    }
}

static void CommState_Idle(void) {
}

static void CommState_FreeWhenDone(void) {
    if (!Comm_IsActive()) {
        CommState_Free();
    }
}

static void CommState_ResumeParentWaitAlone(void) {
    if (Comm_CountConnected() <= 1) {
        Wireless_SetEntryClosed(0);
        Comm_ResetInTransferMode1();
        CommState_SetState(CommState_AlternateWaitStopped, 0);
    }
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    Wireless_SetEntryClosed(0);
    Comm_ResetInTransferMode1();
    CommState_SetState(CommState_AlternateWaitStopped, 0);
}

static void CommState_ResumeChildStop(void) {
    if (CommWireless_Stop()) {
        Comm_ResetWork();
        CommState_SetState(CommState_AlternateWaitStopped, 0);
    }
}

static void CommState_ShutdownWaitStopped(void) {
    if (sCommState->timer) {
        sCommState->timer--;
    }
    if (CommWireless_Stop() && !sCommState->timer) {
        Comm_Shutdown();
        CommState_SetState(CommState_FreeWhenDone, 0);
    }
}

static void CommState_AlternateInit(void) {
    if (CommWireless_IsStartedUp()) {
        CommWireless_Init(sCommState->profile, 1);
        Wireless_SetMaxEntries(sCommState->maxEntries);
        CommPlayerInfo_Init(sCommState->saveData, 0);
        if (Comm_StartScan(1, 1, 512)) {
            Comm_RequestTransferMode1();
            CommState_SetState(CommState_AlternateScan, 64);
        }
    }
}

static void CommState_AlternateScan(void) {
    CommWireless_UpdateParents();
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    if (CommWireless_Stop()) {
        CommState_SetState(CommState_AlternateStartParent, 0);
    }
}

static void CommState_AlternateWaitStopped(void) {
    if (CommWireless_Stop()) {
        CommState_SetState(CommState_AlternateStartParent, 0);
    }
}

static void CommState_AlternateStartParent(void) {
    if (CommWireless_IsIdle() && Comm_StartParent(0, sCommState->renewTgid, 512, 1)) {
        // Equivalent to MATH_Rand32(&sCommState->mathRandContext, 0);
        MATHRandContext32 *mathRandContext = &sCommState->mathRandContext;
        mathRandContext->x = (mathRandContext->mul * mathRandContext->x) + mathRandContext->add;
        //
        Comm_RequestTransferMode1();
        sCommState->renewTgid = 0;
        CommState_SetState(&CommState_AlternateParentWait, 10000);
    }
}

static void CommState_AlternateParentWait(void) {
    if (!CommWireless_HasSentBeacons()) {
        if (Comm_GetConnectedChildren()) {
            sCommState->renewTgid = 1;
            WirelessStatusIcon_Create();
            CommState_SetState(CommState_AlternateLinked, 0);
            return;
        }
        if (sCommState->timer) {
            sCommState->timer--;
            return;
        }
    }
    if (CommWireless_Stop()) {
        CommState_SetState(CommState_AlternateStartScan, 0);
    }
}

static void CommState_AlternateStartScan(void) {
    if (CommWireless_IsIdle() && Comm_StartScan(0, 0, 512)) {
        Comm_RequestTransferMode1();
        // Equivalent to u32 rand = MATH_Rand32(&sCommState->mathRandContext, 32)
        MATHRandContext32 *mathRandContext = &sCommState->mathRandContext;
        u64 nextX = (mathRandContext->mul * mathRandContext->x) + mathRandContext->add;
        mathRandContext->x = nextX;
        u32 rand = (u32)(((mathRandContext->x >> 32) * 32) >> 32);
        //
        CommState_SetState(CommState_AlternateScan, rand);
    }
}

static void CommState_JoinWaitStopped(void) {
    if (CommWireless_Stop()) {
        CommState_SetState(CommState_JoinStartScan, 0);
    }
}

static void CommState_JoinStartScan(void) {
    if (CommWireless_IsIdle() && Comm_StartScan(0, 0, 512)) {
        Comm_RequestTransferMode1();
        CommState_SetState(CommState_JoinConnect, 100);
    }
}

static void CommState_JoinConnect(void) {
    if (CommWireless_GetParentMemberCount(sCommState->slot) && Comm_ConnectToParent(sCommState->slot)) {
        CommState_SetState(CommState_JoinWaitLinked, 100);
        return;
    }
    if (Comm_HasLinkError()) {
        CommState_SetState(CommState_JoinRetry, 0);
        return;
    }
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    CommState_SetState(CommState_JoinRetry, 0);
}

static void CommState_JoinWaitLinked(void) {
    if (Comm_HasLinkError()) {
        CommState_SetState(CommState_JoinRetry, 0);
        return;
    }
    if (Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        sCommState->joinReply = 0;
        CommState_SetState(CommState_JoinWaitReply, 120);
        return;
    }
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    CommState_SetState(CommState_JoinRetry, 0);
}

static void CommState_JoinWaitReply(void) {
    if (Comm_HasLinkError()) {
        CommState_SetState(CommState_JoinRetry, 0);
        return;
    }
    if (sCommState->joinReply == 2) {
        CommState_SetState(CommState_JoinFailed, 0);
        return;
    }
    if (sCommState->joinReply == 1) {
        CommPlayerInfo_SendLocal();
        CommState_SetState(CommState_Joined, 0);
        return;
    }
    if (sCommState->timer > 110) {
        Comm_SendFixedCommand(6, sJoinRequest);
    }
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    CommState_SetState(CommState_JoinRetry, 0);
}

static void CommState_Joined(void) {
    if (Comm_HasLinkError()) {
        CommState_SetState(CommState_JoinRetry, 0);
    }
}

static void CommState_JoinFailed(void) {
}

static void CommState_JoinRetry(void) {
    sCommState->joinReply = 0;
    if (CommWireless_Stop()) {
        if (sCommState->joinRetries) {
            sCommState->joinRetries--;
            CommState_SetState(CommState_JoinStartScan, 0);
            return;
        }
        CommState_SetState(CommState_JoinFailed, 0);
    }
}

static void CommState_AlternateLinked(void) {
    if (!Comm_GetConnectedChildren()) {
        if (!CommState_ReportsErrors() && CommWireless_Stop()) {
            CommState_SetState(CommState_AlternateStartScan, 0);
        }
    } else if (!Comm_GetLocalNetId()) {
        CommPlayerInfo_HostRedistribute();
    }
    if (Comm_HasLinkError() && !CommState_ReportsErrors()) {
        CommState_SetState(CommState_JoinRetry, 0);
    }
}

static void CommState_RestartIdle(void) {
    if (CommWireless_IsIdle() && Comm_StartParent(0, sCommState->renewTgid, 512, 0)) {
        Comm_RequestTransferMode1();
        CommState_SetState(CommState_Idle, 0);
    }
}

void CommState_SetLinkMode13RequestMode0(void) {
    u8 sp[2];
    sCommState->linkMode = COMM_TYPE_13;
    if (!Comm_GetLocalNetId()) {
        sp[1] = 0;
        Comm_SendFixedCommand(10, &sp[1]);
        return;
    }
    sp[0] = 0;
    Comm_SendFixedCommand(10, sp);
}

void CommState_ReconnectToParent(s8 slot) {
    sCommState->slot = slot;
    sCommState->joinRetries = 3;
    CommState_SetState(CommState_ReconnectStop, 0);
}

void CommState_SetRecordMixingLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_MIX_RECORDS;
}

void CommState_JoinRecordMixing(s8 slot) {
    sCommState->slot = slot;
    sCommState->linkMode = COMM_TYPE_MIX_RECORDS;
    sCommState->joinRetries = 3;
    WirelessStatusIcon_Create();
    CommState_SetState(CommState_JoinWaitStopped, 0);
}

void CommState_SetSpinTradeLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_SPIN_TRADE;
}

void CommState_JoinSpinTrade(s8 slot) {
    sCommState->slot = slot;
    sCommState->linkMode = COMM_TYPE_SPIN_TRADE;
    sCommState->joinRetries = 3;
    WirelessStatusIcon_Create();
    CommState_SetState(CommState_JoinWaitStopped, 0);
}

static void CommState_ReconnectStop(void) {
    if (CommWireless_Stop()) {
        CommState_SetState(CommState_ReconnectScan, 0);
    }
}

static void CommState_ReconnectScan(void) {
    if (CommWireless_IsIdle()) {
        sCommState->linkMode = COMM_TYPE_13;
        if (Comm_StartScan(0, 0, 512)) {
            Comm_RequestTransferMode0();
            CommState_SetState(CommState_ReconnectWaitParent, 100);
        }
    }
}

static void CommState_ReconnectWaitParent(void) {
    if (CommWireless_GetParentMemberCount(sCommState->slot) && Comm_ConnectToParent(sCommState->slot)) {
        CommState_SetState(CommState_ReconnectWaitLinked, 100);
        return;
    }
    if (Comm_HasLinkError() || !sCommState->timer) {
        sCommState->joinRetries--;
        if (!sCommState->joinRetries) {
            CommState_SetState(CommState_JoinFailed, 0);
            return;
        }
        CommState_SetState(CommState_ReconnectStop, 0);
        return;
    }
    if (sCommState->timer) {
        sCommState->timer--;
    }
}

static void CommState_ReconnectWaitLinked(void) {
    if (sCommState->timer > 90) {
        sCommState->timer--;
        return;
    }
    if (Comm_HasLinkError()) {
        sCommState->joinRetries--;
        if (!sCommState->joinRetries) {
            CommState_SetState(CommState_JoinFailed, 0);
            return;
        }
        CommState_SetState(CommState_ReconnectStop, 0);
        return;
    }
    if (Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        CommState_SetState(CommState_Joined, 0);
        return;
    }
    if (sCommState->timer) {
        sCommState->timer--;
        return;
    }
    sCommState->joinRetries--;
    if (!sCommState->joinRetries) {
        CommState_SetState(CommState_JoinFailed, 0);
        return;
    }
    CommState_SetState(CommState_ReconnectStop, 0);
}

void CommState_RecvJoinRequest(int netId, int size, void *data, void *context) {
    const u8 *request = data;
    u32 i;
    if (!Comm_GetLocalNetId()) {
        BOOL matches = TRUE;
        for (i = 0; i < NELEMS(sJoinRequest); i++) {
            if (sJoinRequest[i] != request[i]) {
                matches = FALSE;
                break;
            }
        }
        if (matches && !sCommState->refuseJoins) {
            sJoinAccepted[0] = netId;
            Comm_SendFixedParentCommand(7, sJoinAccepted);
        } else {
            sJoinRefused[0] = netId;
            Comm_SendFixedParentCommand(7, sJoinRefused);
        }
    }
}

void CommState_RecvJoinReply(int netId, int size, void *data, void *context) {
    const u8 *reply = data;
    u32 i;
    BOOL matches = TRUE;
    for (i = 1; i < NELEMS(sJoinAccepted); i++) {
        if (sJoinAccepted[i] != reply[i]) {
            matches = FALSE;
            break;
        }
    }
    if (matches) {
        u8 acceptedNetId = *reply;
        if (acceptedNetId == Comm_GetLocalNetId()) {
            sCommState->joinReply = 1;
        }
    } else {
        matches = TRUE;
        for (i = 1; i < NELEMS(sJoinRefused); i++) {
            if (sJoinRefused[i] != reply[i]) {
                matches = FALSE;
                break;
            }
        }
        if (matches) {
            u8 refusedNetId = *reply;
            u8 localNetId = Comm_GetLocalNetId();
            if (refusedNetId == localNetId) {
                sCommState->joinReply = 2;
            }
        }
    }
}

u32 CommState_GetJoinMessageSize(void) {
    return 6;
}

void CommState_SetMaxEntries(int maxEntries) {
    if (sCommState) {
        sCommState->maxEntries = maxEntries;
        Wireless_SetMaxEntries(maxEntries);
    }
}

static void CommState_BeaconWatch(void) {
    CommWireless_UpdateParents();
}

static void CommState_OnBeacon(u32 ggid, s32 info) {
    switch (ggid) {
    case 0x333:
        if (info == 15) {
            sCommState->seenGames = (1 | sCommState->seenGames);
        }
        break;
    case 0x400318:
        sCommState->seenGames = (1 | sCommState->seenGames);
        break;
    case 0x400131:
        sCommState->seenGames = (2 | sCommState->seenGames);
        break;
    case 0x400286:
        sCommState->seenGames = (4 | sCommState->seenGames);
        break;
    }
}

static void CommState_BeaconWatchScan(void) {
    if (Comm_StartScan(1, 1, 32)) {
        Comm_RequestTransferMode1();
        CommState_SetState(CommState_BeaconWatch, 0);
    }
}

static void CommState_BeaconWatchInit(void) {
    if (CommWireless_IsStartedUp()) {
        CommWireless_Init(sCommState->profile, 0);
        CommPlayerInfo_Init(sCommState->saveData, 0);
        Wireless_SetBeaconCallback(CommState_OnBeacon);
        CommState_SetState(CommState_BeaconWatchScan, 0);
    }
}

void CommState_StartBeaconWatch(SaveData *saveData) {
    if (!Comm_IsActive()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 0x7000);
        CommState_Init(saveData, 17);
        sCommState->beaconId = 0;
        CommState_SetState(CommState_BeaconWatchInit, 0);
    }
}

void CommState_StopBeaconWatch(void) {
    if (sCommState) {
        CommState_SetState(CommState_ShutdownWaitStopped, 5);
    }
}

u8 CommState_GetSeenGames(void) {
    return sCommState->seenGames;
}

BOOL CommState_StopForReset(void) {
    Comm_StopFrameUpdate();
    if (sCommState == NULL) {
        return TRUE;
    }
    if ((sCommState->linkMode == COMM_TYPE_24) || (sCommState->linkMode == COMM_TYPE_25) || (sCommState->linkMode == COMM_TYPE_EMAIL_WIFI)) {
        WifiConnection_Shutdown();
        return TRUE;
    }
    if (CommState_IsWifi()) {
        if (sCommState->linkMode == COMM_TYPE_WIFI_PLAZA) {
            CommState_SetState(CommState_PlazaLogout, 0);
        } else {
            CommState_SetState(CommState_WifiShutdown, 0);
        }
    } else {
        CommState_SetState(CommState_StopWireless, 0);
    }
    return FALSE;
}

static void CommState_MysteryGiftParentStart(void) {
    if (CommWireless_IsStartedUp()) {
        CommWireless_Init(sCommState->profile, 1);
        CommPlayerInfo_Init(sCommState->saveData, 0);
        if (Comm_StartParent(1, 1, 512, 1)) {
            Comm_RequestTransferMode1();
            CommState_SetState(CommState_WaitLinked, 0);
        }
    }
}

static void CommState_MysteryGiftChildStart(void) {
    if (CommWireless_IsStartedUp()) {
        CommWireless_Init(sCommState->profile, 1);
        CommPlayerInfo_Init(sCommState->saveData, 0);
        if (Comm_StartScan(1, 1, 512)) {
            Comm_RequestTransferMode1();
            CommState_SetState(CommState_ChildScanning, 0);
        }
    }
}

static void CommState_WifiFailed(void) {
}

static void CommState_WifiTimedOut(void) {
    if (WifiConnection_Update(0) < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    }
}

static void CommState_WifiDisconnected(void) {
}

static void CommState_WifiCancelled(void) {
}

static void CommState_WifiConnected(void) {
    Comm_SetWifiConnected(1);
    s32 status = WifiConnection_Update(0);
    if ((status >= 10) && (status < 20)) {
        CommState_SetState(CommState_WifiCancelled, 0);
    } else if (status < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    } else if (status == WIFI_CONNECTION_RESULT_TIMED_OUT) {
        CommState_SetState(CommState_WifiTimedOut, 0);
    } else if (status == WIFI_CONNECTION_RESULT_DISCONNECTED) {
        if (sCommState->watchMembers) {
            CommState_SetState(CommState_WifiFailed, 0);
        } else {
            CommState_SetState(CommState_WifiDisconnected, 0);
        }
    } else if (status == WIFI_CONNECTION_RESULT_CANCELLED) {
        if (sCommState->watchMembers) {
            CommState_SetState(CommState_WifiFailed, 0);
        } else {
            CommState_SetState(CommState_WifiDisconnected, 0);
        }
    }
    if (sCommState->watchMembers && (sCommState->memberCount != Comm_CountConnected())) {
        CommState_SetState(CommState_WifiFailed, 0);
    }
}

void CommState_SetWifiError(u32 error, s32 type, s32 status) {
    if (sCommState) {
        if (error - 25 > 1) {
            error = -error;
        }
        sCommState->wifiError = error;
        sCommState->wifiErrorArg1 = type;
        sCommState->wifiErrorArg2 = status;
    }
}

static void CommState_WifiLobby(void) {
    s32 status = WifiConnection_Update(0);
    if ((status >= 10) && (status < 20)) {
        CommState_SetState(CommState_WifiCancelled, 0);
    } else if (status < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    } else if (status == WIFI_CONNECTION_RESULT_CONNECTED) {
        CommState_SetState(CommState_WifiConnected, 0);
    } else if (status == WIFI_CONNECTION_RESULT_CANCELLED) {
        CommState_SetState(CommState_WifiDisconnected, 0);
    } else if (status == WIFI_CONNECTION_RESULT_CANCELLED_BY_PEER) {
        CommState_SetState(CommState_WifiCancelled, 0);
    } else if (status == WIFI_CONNECTION_RESULT_DISCONNECTED) {
        CommState_SetState(CommState_WifiDisconnected, 0);
    }
}

static void CommState_WifiStartMatch(void) {
    if (WifiConnection_Update(1) < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
        return;
    }
    u32 result = WifiConnection_StartMatchmaking(sCommState->matchFriendIndex, Comm_GetMaxChildren(sCommState->linkMode) + 1, 0) + 3;
    switch (result) {
    case 3:
        Comm_ResetWork();
        CommState_SetState(CommState_WifiLobby, 0);
        return;
    case 0:
        CommState_SetState(CommState_WifiFailed, 0);
    case 1:
    case 2:
        return;
    }
}

s32 CommState_StartWifiMatch(s32 friendIndex) {
    if (sCommState->stateFunc != CommState_WifiLobby) {
        return 0;
    }
    WifiConnection_SetReceiveCallbacks(&Comm_RecvChildFrameCallback, &Comm_RecvParentFrameCallback);
    sCommState->matchFriendIndex = friendIndex;
    CommState_SetState(CommState_WifiStartMatch, 0);
    return 1;
}

enum WifiMatchStatus CommState_GetWifiMatchStatus(void) {
    if (sCommState->stateFunc == CommState_WifiLobby) {
        return WIFI_MATCH_STATUS_LOBBY;
    }
    if (sCommState->stateFunc == CommState_WifiConnected) {
        return WIFI_MATCH_STATUS_CONNECTED;
    }
    if (sCommState->stateFunc == &CommState_WifiTimedOut) {
        return WIFI_MATCH_STATUS_TIMED_OUT;
    }
    if (sCommState->stateFunc == CommState_WifiDisconnected) {
        return WIFI_MATCH_STATUS_DISCONNECTED;
    }
    if (sCommState->stateFunc == CommState_WifiCancelled) {
        return WIFI_MATCH_STATUS_CANCELLED;
    }
    if (sCommState->stateFunc == CommState_PlazaMatching) {
        return WIFI_MATCH_STATUS_LOBBY;
    }
    if (sCommState->stateFunc == CommState_PlazaMatchConnected) {
        return WIFI_MATCH_STATUS_CONNECTED;
    }
    if (sCommState->stateFunc == CommState_PlazaTimedOut) {
        return WIFI_MATCH_STATUS_TIMED_OUT;
    }
    return WIFI_MATCH_STATUS_OTHER;
}

static void CommState_WifiJoinLobby(void) {
    WifiConnection_SetReceiveCallbacks(&Comm_RecvChildFrameCallback, &Comm_RecvParentFrameCallback);
    switch (WifiConnection_StartMatchmaking(-1, 4, 1) + 4) {
    case 4:
        sCommState->peerDisconnected = 0;
        Comm_ResetWork();
        CommState_SetState(CommState_WifiLobby, 0);
        break;
    case 1:
        CommState_SetState(CommState_WifiFailed, 0);
        break;
    case 0:
        return;
    case 2:
        break;
    }
    s32 error = WifiConnection_CheckError();
    if (error < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    } else if (error == WIFI_CONNECTION_RESULT_FORCED_ERROR) {
        CommState_SetState(CommState_WifiFailed, 0);
    }
}

static void CommState_WifiDisconnect(void) {
    Comm_SetWifiConnected(0);
    if (WifiConnection_Disconnect(sCommState->waitHostDisconnect) && WifiConnection_FinishDisconnect()) {
        CommPlayerInfo_Free();
        CommState_SetState(CommState_WifiJoinLobby, 0);
    } else if (WifiConnection_Update(0) < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    }
}

void CommState_RecvWifiDisconnect(int netId, int size, void *data, void *context) {
    if (!Comm_GetLocalNetId()) {
        sCommState->waitHostDisconnect = 0;
        CommState_SetState(CommState_WifiDisconnect, 0);
    } else {
        sCommState->waitHostDisconnect = 1;
        CommState_SetState(CommState_WifiDisconnect, 0);
    }
    sCommState->peerDisconnected = 1;
}

u8 CommState_WasWifiDisconnected(void) {
    return sCommState->peerDisconnected;
}

BOOL CommState_IsWifiJoiningLobby(void) {
    if (sCommState->stateFunc == CommState_WifiJoinLobby) {
        return TRUE;
    }
    if (sCommState->stateFunc == CommState_PlazaLobby) {
        return TRUE;
    }
    return FALSE;
}

BOOL CommState_IsWifiInLobby(void) {
    if (sCommState->stateFunc == CommState_WifiLobby) {
        return TRUE;
    }
    if (sCommState->stateFunc == CommState_WifiJoinLobby) {
        return TRUE;
    }
    if (sCommState->stateFunc == CommState_PlazaLobby) {
        return TRUE;
    }
    return FALSE;
}

u32 *CommState_GetWifiError(void) {
    GF_ASSERT(sCommState);
    return &sCommState->wifiError;
}

static void CommState_WifiShutdown(void) {
    Comm_SetWifiConnected(0);
    if (WifiConnection_Disconnect(0)) {
        WifiConnection_FinishDisconnect();
        CommState_SetState(CommState_ShutdownWaitStopped, 0);
    }
    if (WifiConnection_Update(0) < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    }
}

void CommState_EndWifiSession(void) {
    if (sCommState) {
        Sys_ClearSoftResetDisableFlag(1);
        CommPlayerInfo_Free();
        CommState_SetState(CommState_ShutdownWaitStopped, 5);
    }
}

void CommState_LeaveWifiMatch(void) {
    if (sCommState) {
        sCommState->waitHostDisconnect = 0;
        CommState_SetState(CommState_WifiDisconnect, 0);
    }
}

void CommState_EndWifiMatch(void) {
    if (sCommState) {
        CommState_SetErrorWatch(FALSE, TRUE);
        if (!Comm_GetLocalNetId()) {
            sCommState->waitHostDisconnect = 0;
        } else {
            sCommState->waitHostDisconnect = 1;
        }
        CommState_SetState(CommState_WifiDisconnect, 0);
    }
}

void CommState_SendWifiDisconnect(void) {
    u8 netId = Comm_GetLocalNetId();
    Comm_SendFixedCommand(21, &netId);
}

BOOL CommState_HasWifiFailed(void) {
    if (sCommState) {
        void (*func)() = sCommState->stateFunc;
        if (func == CommState_WifiFailed) {
            return TRUE;
        }
        if (func == CommState_WifiTimedOut && sCommState->watchMembers) {
            return TRUE;
        }
        if (func == CommState_PlazaTimedOut && sCommState->watchMembers) {
            return TRUE;
        }
    }
    return FALSE;
}

void CommState_InitWfcSession(SaveData *saveData) {
    if (sCommState == NULL) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 256);
        sCommState = Heap_Alloc(HEAP_ID_15, sizeof(CommStateWork));
        MI_CpuClear8(sCommState, sizeof(CommStateWork));
        sCommState->linkMode = COMM_TYPE_24;
        sCommState->unk55 = 1;
        sCommState->saveData = saveData;
        CommState_SetErrorWatch(FALSE, TRUE);
        Sys_SetSoftResetDisableFlag(1);
    }
}

void CommState_FreeWfcSession(void) {
    if (sCommState) {
        Sys_ClearSoftResetDisableFlag(1);
        CommState_SetErrorWatch(FALSE, FALSE);
        Heap_Free(sCommState);
        sCommState = NULL;
        Heap_Destroy(HEAP_ID_15);
    }
}

void CommState_InitMysteryGiftWfcSession(SaveData *saveData) {

    if (sCommState == NULL) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 256);
        sCommState = Heap_Alloc(HEAP_ID_15, sizeof(CommStateWork));
        MI_CpuClear8(sCommState, sizeof(CommStateWork));
        sCommState->linkMode = COMM_TYPE_25;
        sCommState->unk55 = 1;
        sCommState->saveData = saveData;
        CommState_SetErrorWatch(FALSE, TRUE);
        Sys_SetSoftResetDisableFlag(1);
    }
}

void CommState_FreeMysteryGiftWfcSession(void) {
    if (sCommState) {
        Sys_ClearSoftResetDisableFlag(1);
        CommState_SetErrorWatch(FALSE, FALSE);
        Heap_Free(sCommState);
        sCommState = NULL;
        Heap_Destroy(HEAP_ID_15);
    }
}

void CommState_InitWiiMessageWfcSession(SaveData *saveData) {
    if (sCommState == NULL) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 256);
        sCommState = Heap_Alloc(HEAP_ID_15, sizeof(CommStateWork));
        MI_CpuClear8(sCommState, sizeof(CommStateWork));
        sCommState->linkMode = COMM_TYPE_EMAIL_WIFI;
        sCommState->unk55 = 1;
        sCommState->saveData = saveData;
        CommState_SetErrorWatch(FALSE, TRUE);
        Sys_SetSoftResetDisableFlag(1);
    }
}

void CommState_FreeWiiMessageWfcSession(void) {
    if (sCommState) {
        Sys_ClearSoftResetDisableFlag(1);
        CommState_SetErrorWatch(FALSE, FALSE);
        Heap_Free(sCommState);
        sCommState = NULL;
        Heap_Destroy(HEAP_ID_15);
    }
}

static BOOL CommState_CheckDwcError(void) {
    if (sCommState == NULL) {
        return FALSE;
    }
    s32 errorCode;
    s32 errorCategory;
    if (sCommState->linkMode == COMM_TYPE_24 || sCommState->linkMode == COMM_TYPE_EMAIL_WIFI) {
        if (DWC_GetLastErrorEx(&errorCode, &errorCategory)) {
            DWC_ClearError();
            return TRUE;
        }
    } else if ((sCommState->linkMode == COMM_TYPE_25) && DWC_GetLastErrorEx(&errorCode, &errorCategory) && (errorCategory == 7)) {
        return TRUE;
    }
    return FALSE;
}

static void CommState_WifiLogin(void) {
    s32 loginState = WifiConnection_UpdateLogin();
    sCommState->timer--;
    if (loginState == WIFI_CONNECTION_RESULT_LOGGED_IN) {
        if (sCommState->linkMode == COMM_TYPE_WIFI_PLAZA) {
            if (WiFiPlazaLobbyClient_Initialize(sCommState->plazaPlayer) == TRUE) {
                sCommState->plazaLobbyStarted = 1;
                CommState_SetState(CommState_PlazaWaitLobby, sCommState->timer);
            } else {
                CommState_SetState(CommState_PlazaLobbyFailed, 0);
            }
        } else {
            CommState_SetState(CommState_WifiJoinLobby, 0);
        }
    } else {
        if (loginState) {
            CommState_SetState(CommState_WifiFailed, 0);
        }
        if (sCommState->timer <= 0) {
            CommState_SetState(CommState_WifiFailed, 0);
        }
    }
}

static void CommState_WifiClubStart(void) {
    if (CommWireless_IsStartedUp()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_48, 0x35400);
        if (Comm_StartParent(1, 1, 512, 1)) {
            WifiConnection_Init(sCommState->saveData, 48, 0x2C400, Comm_GetMaxChildren(sCommState->linkMode) + 1);
            WifiConnection_SetErrorCallback(CommState_ShowErrorAndHalt);
            Comm_RequestTransferMode1();
            CommState_SetState(CommState_WifiLogin, 3600);
        }
    }
}

WifiClubStatusData *CommState_StartWifiClub(SaveData *saveData, u32 dataSize) {
    Save_PlayerData_GetProfile(saveData);
    if (Comm_IsActive()) {
        return NULL;
    }
    Sys_SetSoftResetDisableFlag(1);
    Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800);
    CommState_Init(saveData, 23);
    sCommState->wifiClubData = Heap_Alloc(HEAP_ID_15, dataSize);
    MI_CpuClear8(sCommState->wifiClubData, dataSize);
    sCommState->beaconId = 0;
    sCommState->saveData = saveData;
    CommState_SetState(CommState_WifiClubStart, 0);
    return sCommState->wifiClubData;
}

void CommState_StartWifiPlaza(SaveData *saveData, const struct WiFiPlazaPlayer *player) {
    Save_PlayerData_GetProfile(saveData);
    if (!Comm_IsActive()) {
        Sys_SetSoftResetDisableFlag(1);
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_15, 28800);
        CommState_Init(saveData, 33);
        sCommState->wifiClubData = NULL;
        sCommState->plazaPlayer = player;
        sCommState->plazaLobbyStarted = 0;
        sCommState->beaconId = 0;
        sCommState->saveData = saveData;
        CommState_SetState(CommState_PlazaStart, 0);
    }
}

void CommState_LeaveWifiPlaza(void) {
    if (sCommState) {
        CommState_SetState(CommState_PlazaLogout, 0);
    }
}

u8 CommState_HasPlazaLobbyStarted(void) {
    if (sCommState == NULL) {
        return 0;
    }
    return sCommState->plazaLobbyStarted;
}

BOOL CommState_HasPlazaLobbyFailed(void) {
    if (sCommState && (sCommState->stateFunc == CommState_PlazaLobbyFailed)) {
        return TRUE;
    }
    return FALSE;
}

void CommState_StartPlazaMatch(s32 index) {
    GF_ASSERT(sCommState);
    GF_ASSERT(CommState_IsWifiInLobby() == 1);
    if (!WiFiPlazaLobbyClient_IsMatchActive(index)) {
        WiFiPlazaLobbyClient_HostMatch(index, 4);
        CommState_SetState(CommState_PlazaMatching, 0);
    } else {
        WiFiPlazaLobbyClient_JoinMatch(index);
        CommState_SetState(CommState_PlazaMatching, 0);
    }
}

void CommState_EndPlazaMatch(void) {
    if (WiFiPlazaLobbyClient_IsMatchHost() == 1) {
        WiFiPlazaLobbyClient_StopMatch();
    }
    WiFiPlazaLobbyClient_EndMatch();
    CommState_SetState(CommState_PlazaEndMatch, 0);
}

s32 CommState_GetPlazaMatchStatus(void) {
    if (sCommState) {
        if (sCommState->stateFunc == CommState_PlazaMatchConnected) {
            return 2;
        }
        if (sCommState->stateFunc == CommState_PlazaMatching) {
            return 1;
        }
        if (sCommState->stateFunc == CommState_PlazaEndMatch) {
            return 3;
        }
    }
    return 0;
}

WifiClubStatusData *CommState_GetWifiClubData(void) {
    return sCommState->wifiClubData;
}

void CommState_SetErrorWatch(BOOL watchMembers, BOOL reportErrors) {
    if (sCommState) {
        sCommState->watchMembers = watchMembers;
        sCommState->reportErrors = reportErrors;
        if (watchMembers) {
            sCommState->memberCount = Comm_CountConnected();
        } else {
            sCommState->memberCount = 0;
        }
    }
    CommWireless_SetLostWhenAlone(watchMembers);
    CommWireless_SetDetectDrops(watchMembers);
}

BOOL CommState_ReportsErrors(void) {
    if (sCommState) {
        if (sCommState->errorKind) {
            return TRUE;
        }
        return sCommState->reportErrors;
    }
    return FALSE;
}

u8 CommState_GetLinkMode(void) {
    if (sCommState) {
        return sCommState->linkMode;
    }
    return 1;
}

u8 CommState_GetBeaconId(void) {
    if (sCommState) {
        return sCommState->beaconId;
    }
    return 0;
}

void CommState_SetSelectedOrder(void *order) {
    MI_CpuCopy8(order, &sCommState->selectedOrder, 6);
}

void CommState_GetSelectedOrder(void *order) {
    MI_CpuCopy8(&sCommState->selectedOrder, order, 6);
}

int CommState_IsWifi(void) {
    return Comm_IsWifiLinkMode(CommState_GetLinkMode());
}

static void CommState_SetErrorScreen(s8 errorScreen) {
    if (sCommState) {
        sCommState->errorScreen = errorScreen;
    }
}

u8 CommState_GetErrorScreen(void) {
    if (Sys_IsAsyncSaveInProgress()) {
        return 0;
    }
    if (sCommState) {
        return sCommState->errorScreen;
    }
    return 0;
}

void CommState_ShowErrorAndHalt(u32 errorCode) {
    ShowCommunicationError(HEAP_ID_DEFAULT, 1, errorCode);
    while (TRUE) {}
}

void CommState_ShowRestartErrorAndHalt(void) {
    ShowCommunicationError(HEAP_ID_DEFAULT, 4, 0);
    while (TRUE) {}
}

void CommState_FrameDummy(enum HeapID heapID, BgConfig *bgConfig) {
#pragma unused(heapID, bgConfig)
}

void CommState_CheckLinkError(int unused) {
    if (CommState_ReportsErrors() && (Comm_HasLinkError() || CommState_HasWifiFailed() || CommState_CheckDwcError() || sCommState->errorKind || CommState_HasPlazaLobbyFailed()) && !Sys_IsAsyncSaveInProgress() && !CommState_GetErrorScreen()) {
        Sound_Stop();
        Save_Cancel(sCommState->saveData);
        gSystem.touchpadReadAuto = TRUE;
        if (sCommState->errorKind == 3) {
            CommState_SetErrorScreen(3);
            return;
        }
        if (sCommState->errorKind == 5) {
            CommState_SetErrorScreen(5);
            return;
        }
        if ((sCommState->linkMode == COMM_TYPE_25) || (sCommState->linkMode == COMM_TYPE_MYSTERY_GIFT) || (sCommState->linkMode == COMM_TYPE_EMAIL_WIFI)) {
            CommState_SetErrorScreen(2);
            return;
        }
        CommState_SetErrorScreen(1);
    }
}

BOOL CommState_IsLinkDown(void) {
    if (CommWireless_IsManagerEnded() || !CommState_Exists()) {
        return TRUE;
    }
    if (!CommWireless_IsInitialized()) {
        return TRUE;
    }
    if (Wireless_HasFatalError()) {
        return TRUE;
    }
    return FALSE;
}

BOOL CommState_SetError(int errorKind) {
    if (sCommState) {
        sCommState->errorKind = errorKind;
        Comm_StopFrameUpdate();
        return TRUE;
    }
    return FALSE;
}

void CommState_SetWifiPeerLinkMode29(void) {
    sCommState->linkMode = COMM_TYPE_29;
    WifiConnection_SetReceiveCallbacks(&Comm_RecvPeerFrameCallback, &Comm_RecvPeerFrameCallback);
}

void CommState_SetClubWifiLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_CLUB_WIFI;
    WifiConnection_SetReceiveCallbacks(&Comm_RecvPeerFrameCallback, &Comm_RecvPeerFrameCallback);
}

void CommState_SetPlazaLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_WIFI_PLAZA;
    WifiConnection_SetReceiveCallbacks(&Comm_RecvPeerFrameCallback, &Comm_RecvPeerFrameCallback);
}

void CommState_SetWifiClubLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_LOGIN_WIFI;
    WifiConnection_SetReceiveCallbacks(&Comm_RecvChildFrameCallback, &Comm_RecvParentFrameCallback);
}

void CommState_SetSingleBattleWifiLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_SINGLE_BATTLE_WIFI;
    WifiConnection_SetReceiveCallbacks(&Comm_RecvChildFrameCallback, &Comm_RecvParentFrameCallback);
}

static void CommState_PlazaStart(void) {
    if (CommWireless_IsStartedUp()) {
        Heap_CreateAtEnd(HEAP_ID_3, HEAP_ID_48, 0x60000);
        if (Comm_StartParent(1, 1, 512, 1)) {
            WifiConnection_Init(sCommState->saveData, 48, 0x58000, Comm_GetMaxChildren(sCommState->linkMode) + 1);
            WifiConnection_SetErrorCallback(CommState_ShowErrorAndHalt);
            Comm_RequestTransferMode1();
            WifiConnection_SetVoiceChatEnabled(0);
            Comm_SetWifiContinuousSend(0);
            CommState_SetState(CommState_WifiLogin, 3600);
        }
    }
}

static void CommState_PlazaWaitLobby(void) {
    sCommState->timer--;
    if (sCommState->timer <= 0) {
        CommState_SetState(CommState_WifiFailed, 0);
        return;
    }
    Comm_SetWifiConnected(1);
    if (CommState_PlazaUpdate() && WiFiPlazaLobbyClient_IsInLobby()) {
        CommState_SetState(CommState_PlazaLobby, 0);
    }
}

static void CommState_PlazaLobby(void) {
    if (CommState_PlazaUpdate()) {
        return;
    }
}

static s32 CommState_PlazaCheckWifiResult(s32 result) {
    s32 ok = 1;
    if ((result >= 10) && (result < 20)) {
        CommState_SetState(CommState_WifiCancelled, 0);
        ok = 0;
    } else if (result < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
        ok = 0;
    } else if (result == WIFI_CONNECTION_RESULT_TIMED_OUT) {
        CommState_SetState(CommState_PlazaTimedOut, 0);
        ok = 0;
    } else if (result == WIFI_CONNECTION_RESULT_DISCONNECTED) {
        ok = 0;
        if (sCommState->watchMembers) {
            CommState_SetState(CommState_WifiFailed, 0);
        } else {
            CommState_SetState(CommState_WifiDisconnected, 0);
        }
    }
    if (sCommState->watchMembers && (sCommState->memberCount != Comm_CountConnected())) {
        CommState_SetState(CommState_WifiFailed, 0);
        ok = 0;
    }
    return ok;
}

static s32 CommState_PlazaUpdateLobby(void) {
    s32 ok = 1;
    u32 lobbyState = WiFiPlazaLobbyClient_Update();
    switch (lobbyState) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        CommState_SetState(CommState_PlazaLobbyFailed, 0);
        ok = 0;
        break;
    }
    return ok;
}

static int CommState_PlazaUpdate(void) {
    s32 ret = CommState_PlazaCheckWifiResult(WifiConnection_Update(0));
    if (ret) {
        return CommState_PlazaUpdateLobby();
    }
    return ret;
}

static void CommState_PlazaUpdateMatch(s32 *matchResult) {
    s32 status = WifiConnection_Update(0);
    if (status >= WIFI_CONNECTION_RESULT_CONNECTED) {
        *matchResult = status;
    } else {
        *matchResult = 0;
        if (!CommState_PlazaCheckWifiResult(status)) {
            return;
        }
    }
    CommState_PlazaUpdateLobby();
}

static void CommState_PlazaLogout(void) {
    WiFiPlazaLobbyClient_Shutdown();
    CommState_SetState(CommState_PlazaWaitLogout, 0);
}

static void CommState_PlazaWaitLogout(void) {
    WifiConnection_Update(0);
    CommState_PlazaUpdateLobby();
    if (WiFiPlazaLobbyClient_IsDisconnected()) {
        Sys_ClearSoftResetDisableFlag(1);
        CommPlayerInfo_Free();
        CommState_SetState(CommState_ShutdownWaitStopped, 5);
        Comm_SetWifiConnected(0);
    }
}

static void CommState_PlazaLobbyFailed(void) {
}

static void CommState_PlazaMatchConnected(void) {
    CommState_PlazaUpdate();
    if (WiFiPlazaLobbyClient_WasMatchCancelled() == 1) {
        WiFiPlazaLobbyClient_EndMatch();
        CommState_SetState(CommState_PlazaEndMatch, 0);
    }
}

static void CommState_PlazaMatching(void) {

    if (WiFiPlazaLobbyClient_WasMatchCancelled() == 1) {
        WiFiPlazaLobbyClient_EndMatch();
        CommState_SetState(CommState_PlazaEndMatch, 0);
        return;
    }
    s32 matchResult;
    CommState_PlazaUpdateMatch(&matchResult);
    if (matchResult) {
        if (matchResult == 20) {
            CommState_SetState(CommState_PlazaMatchConnected, 0);
            return;
        }
        WiFiPlazaLobbyClient_EndMatch();
        CommState_SetState(CommState_PlazaLobby, 0);
    }
}

static void CommState_PlazaEndMatch(void) {
    if (WifiConnection_Update(1) < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
        return;
    }
    if (CommState_PlazaUpdateLobby() && WifiConnection_Disconnect(0) && WifiConnection_FinishDisconnect()) {
        Comm_ResetWork();
        Comm_SetWifiContinuousSend(0);
        CommState_SetState(CommState_PlazaLobby, 0);
    }
}

static void CommState_PlazaTimedOut(void) {
    if (WifiConnection_Update(0) < 0) {
        CommState_SetState(CommState_WifiFailed, 0);
    }
    CommState_PlazaUpdateLobby();
}

void CommState_SetFrontierWifiLinkMode(void) {
    sCommState->linkMode = COMM_TYPE_FRONTIER_WIFI;
}

void Comm_InitSyncedSave(s32 *state) {
    *state = 0;
}

BOOL Comm_SyncedSave(SaveData *saveData, s32 arg1, s32 *state) {
    switch (*state) {
    case 0:
        LinkSync_StartSync(111);
        *state = 1;
    default:
        break;
    case 1:
        if (LinkSync_IsSynced(111)) {
            Save_PrepareForAsyncWrite(saveData, arg1);
            *state = 2;
        }
        break;
    case 2:
        s32 result = Save_WriteFileAsync(saveData);
        GF_ASSERT(result != 2);
        if (result == 1) {
            *state = 3;
            LinkSync_StartSync(112);
        } else if (result == 3) {
            *state = 7;
        }
        break;
    case 3:
        if (LinkSync_IsSynced(112)) {
            *state = 4;
        }
        break;
    case 4:
        result = Save_WriteFileAsync(saveData);
        GF_ASSERT(result != 1);
        if (result == 2) {
            *state = 5;
        } else if (result == 3) {
            *state = 7;
        }
        break;
    case 5:
        *state = 6;
        break;
    case 6:
        return TRUE;
    }
    return FALSE;
}

void Comm_RecordPlayerLocations(SaveWiFiHistory *wifiHistory) {
    s32 connectedCount = Comm_CountConnected();
    if (CommPlayerInfo_GetProfile(0)) {
        for (int i = 0; i < connectedCount; i++) {
            if (i != Comm_GetLocalNetId()) {
                Comm_MarkLocationSeen(wifiHistory, CommPlayerInfo_GetCountry(i), CommPlayerInfo_GetRegion(i), PlayerProfile_GetLanguage(CommPlayerInfo_GetProfile(i)));
            }
        }
    }
}

void Comm_MarkLocationSeen(SaveWiFiHistory *history, s32 country, s32 region, u8 language) {
    if (!WiFiHistory_GetLocationSeenState(history, country, region)) {
        WiFiHistory_SetLocationSeenState(history, country, region, 1);
    }
}

s32 Comm_InitDwc(enum HeapID heapID) {
    void *work = Heap_Alloc(heapID, 1824);
    s32 result = DWC_Init(((u32)work + 31) & ~31);
    Heap_Free(work);
    return result;
}

s32 Comm_LoadAndInitDwc(enum HeapID heapID) {
    LoadDwcOverlay();
    LoadOVY38();
    s32 result = Comm_InitDwc(heapID);
    UnloadDwcOverlay();
    UnloadOVY38();
    return result;
}

void Comm_EnsureDwcUserData(WiFiList *wifiList) {

    DWCUserData *userData = FriendRoster_GetUserData(wifiList);
    if (!DWC_CheckUserData(userData)) {
        DWC_CreateUserData(userData, 0x4144414A);
        DWC_ClearDirtyFlag(userData);
    }
}

int Comm_GetOwnGsProfileId(WiFiList *wifiList) {
    DWCUserData *userData = FriendRoster_GetUserData(wifiList);
    DWCFriendData friendData;
    DWC_CreateExchangeToken(userData, &friendData);
    return DWC_GetGsProfileId(userData, &friendData);
}

BOOL Comm_HasWifiProfile(SaveData *saveData) {
    DWCUserData *userData = FriendRoster_GetUserData(Save_FriendRoster_Get(saveData));
    if (DWC_CheckHasProfile(userData) && DWC_CheckValidConsole(userData)) {
        return TRUE;
    }
    return FALSE;
}

s32 Comm_FindFriendSlot(SaveData *saveData, DWCFriendData *exchangeToken, s32 *slot) {
    int i;
    DWCUserData *userData = FriendRoster_GetUserData(Save_FriendRoster_Get(saveData));
    DWCFriendData *friendData = FriendRoster_GetDwcFriendData(Save_FriendRoster_Get(saveData), 0);
    *slot = -1;
    if (!DWC_IsValidFriendData(exchangeToken)) {
        return 3;
    }
    for (i = 0; i < 32; i++) {
        if (DWC_IsEqualFriendData(exchangeToken, &friendData[i])) {
            *slot = i;
            return 0;
        }
        if (DWC_GetGsProfileId(userData, exchangeToken) > 0) {
            if (DWC_GetGsProfileId(userData, exchangeToken) == DWC_GetGsProfileId(userData, &friendData[i])) {
                *slot = i;
                return 1;
            }
        }
        if ((*slot < 0) && !DWC_IsValidFriendData(&friendData[i])) {
            *slot = i;
        }
    }
    return 2;
}

int Comm_FindFriendSlotByKey(SaveData *saveData, u64 friendKey, int *slot) {
    int i;
    DWCUserData *userData = FriendRoster_GetUserData(Save_FriendRoster_Get(saveData));
    DWCFriendData *friendData = FriendRoster_GetDwcFriendData(Save_FriendRoster_Get(saveData), 0);
    if (!DWC_CheckFriendKey(userData, friendKey)) {
        return 3;
    }
    DWCFriendData newFriendData;
    DWC_CreateFriendKeyToken(&newFriendData, friendKey);
    if (DWC_GetGsProfileId(userData, &newFriendData) <= 0) {
        return 3;
    }
    *slot = -1;
    for (i = 0; i < 32; i++) {
        if (DWC_GetGsProfileId(userData, &newFriendData) == DWC_GetGsProfileId(userData, &friendData[i])) {
            *slot = i;
            return 0;
        }
        if ((*slot < 0) && !DWC_IsValidFriendData(&friendData[i])) {
            *slot = i;
        }
    }
    return 2;
}

s32 Comm_RegisterLinkedFriends(SaveData *saveData, s32 *results, enum HeapID heapID) {
    s32 hasNewFriend = 0;
    DWCFriendData *friendData = FriendRoster_GetDwcFriendData(Save_FriendRoster_Get(saveData), 0);
    for (int i = 0; i < Comm_CountConnected(); i++) {
        if (i != Comm_GetLocalNetId()) {
            DWCFriendData *exchangeToken = CommPlayerInfo_GetExchangeToken(i);
            if (exchangeToken) {
                s32 slot;
                results[i] = Comm_FindFriendSlot(saveData, exchangeToken, &slot);
                GF_ASSERT(results[i] != 3);
                if (results[i] == 0) {
                    Comm_StoreFriendFromPlayer(saveData, i, slot, heapID, 2);
                    CommPlayerInfo_SaveRecords(saveData);
                } else if (results[i] == 1) {
                    if (!CommState_IsWifi()) {
                        Comm_StoreFriendFromPlayer(saveData, i, slot, heapID, 1);
                        MI_CpuCopy8(exchangeToken, &friendData[slot], sizeof(DWCFriendData));
                        CommPlayerInfo_SaveRecords(saveData);
                    }
                } else if (results[i] == 2) {
                    hasNewFriend = 1;
                }
            }
        }
    }
    return hasNewFriend;
}

void Comm_StoreFriendFromPlayer(SaveData *saveData, s32 netId, s32 slot, enum HeapID heapID, u32 mode) {
    WiFiList *wifiList = Save_FriendRoster_Get(saveData);
    DWCFriendData *friendData = FriendRoster_GetDwcFriendData(wifiList, slot);
    PlayerProfile *playerProfile = CommPlayerInfo_GetProfile(netId);
    if (mode != 2) {
        MI_CpuCopy8(CommPlayerInfo_GetExchangeToken(netId), friendData, 12);
    }
    if (mode == 0) {
        String *string = PlayerProfile_GetPlayerName_NewString(playerProfile, heapID);
        FriendRoster_SetPlayerName(wifiList, slot, string);
        String_Delete(string);
        FriendRoster_SetEntryField(wifiList, slot, FRIEND_ROSTER_FIELD_GENDER, PlayerProfile_GetTrainerGender(playerProfile));
        FriendRoster_SetEntryField(wifiList, slot, FRIEND_ROSTER_FIELD_TRAINER_ID, PlayerProfile_GetTrainerID(playerProfile));
    } else if (((mode - 1) <= 1) && (FriendRoster_GetEntryField(wifiList, slot, FRIEND_ROSTER_FIELD_GENDER) == FRIEND_ROSTER_GENDER_UNKNOWN)) {
        FriendRoster_SetEntryField(wifiList, slot, FRIEND_ROSTER_FIELD_GENDER, PlayerProfile_GetTrainerGender(playerProfile));
        FriendRoster_SetEntryField(wifiList, slot, FRIEND_ROSTER_FIELD_TRAINER_ID, PlayerProfile_GetTrainerID(playerProfile));
    }
    String *string = String_New(120, heapID);
    CopyU16ArrayToString(string, CommPlayerInfo_GetGroupName(netId));
    FriendRoster_SetGroupName(wifiList, slot, string);
    String_Delete(string);
    FriendRoster_SetEntryField(wifiList, slot, FRIEND_ROSTER_FIELD_AVATAR, PlayerProfile_GetAvatar(playerProfile));
    CommPlayerInfo_SaveRecords(saveData);
}

s32 Comm_FindFriendIndexOfPlayer(SaveData *saveData, s32 netId) {
    int i;
    DWCFriendData *friendData = CommPlayerInfo_GetExchangeToken(netId);
    WiFiList *wifiList = Save_FriendRoster_Get(saveData);

    for (i = 0; i < 32; i++) {
        if (DWC_IsEqualFriendData(friendData, FriendRoster_GetDwcFriendData(wifiList, i))) {
            return i;
        }
    }
    return 32;
}
