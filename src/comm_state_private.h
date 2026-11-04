#ifndef POKEHEARTGOLD_DWCACCOUNT_H
#define POKEHEARTGOLD_DWCACCOUNT_H

#include "global.h"

#include "save_link_ruleset.h"

typedef struct DWCUserData DWCUserData;

typedef struct DWCFriendData {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} DWCFriendData;

BOOL DWC_CheckValidConsole(DWCUserData *userData);
BOOL DWC_CheckHasProfile(DWCUserData *userData);
int DWC_IsValidFriendData(DWCFriendData *friendData);
void DWC_CreateExchangeToken(DWCUserData *, DWCFriendData *);
void DWC_CreateFriendKeyToken(DWCFriendData *friendData, u64 friendKey);
int DWC_CheckFriendKey(DWCUserData *userData, u64 friendKey);
int DWC_GetGsProfileId(DWCUserData *userData, DWCFriendData *friendData);
void DWC_CreateUserData(DWCUserData *userData, s32 gameCode);
void DWC_ClearDirtyFlag(DWCUserData *userData);
int DWC_CheckUserData(DWCUserData *userData);
int DWC_Init(int);
int DWC_IsEqualFriendData(DWCFriendData *friendData0, DWCFriendData *friendData1);

#endif // POKEHEARTGOLD_DWCACCOUNT_H

#ifndef POKEHEARTGOLD_FRIEND_ROSTER_H
#define POKEHEARTGOLD_FRIEND_ROSTER_H

#include "constants/friend_roster.h"
#include "pm_string.h"
#include "save.h"

typedef struct FriendRoster FriendRoster;
typedef FriendRoster WiFiList;

void Save_FriendRoster_LoadFromSave(SaveData *saveData);
void Save_FriendRoster_StoreToSave(SaveData *saveData);
WiFiList *Save_FriendRoster_Get(SaveData *saveData);
int FriendRoster_CountFriends(WiFiList *data);
DWCUserData *FriendRoster_GetUserData(WiFiList *data);
u16 *FriendRoster_GetPlayerName(WiFiList *data, s32 index);
u16 *FriendRoster_GetGroupName(WiFiList *data, s32 index);
s32 FriendRoster_GetEntryField(WiFiList *data, s32 index, s32 field);
void FriendRoster_Compact(WiFiList *data);
void FriendRoster_UpdateDate(WiFiList *data, s32 index);
u16 FriendRoster_GetUsedSlotCount(WiFiList *data);
void FriendRoster_SetEntryField(WiFiList *data, int index, enum FriendRosterField field, u32 value);
void Save_FriendRoster_Init(WiFiList *data);
void FriendRoster_SetGroupName(WiFiList *data, int index, String *name);
void FriendRoster_SetPlayerName(WiFiList *data, int index, String *name);
DWCFriendData *FriendRoster_GetDwcFriendData(WiFiList *data, int index);

#endif // POKEHEARTGOLD_FRIEND_ROSTER_H

#ifndef POKEHEARTGOLD_COMM_STATE_PRIVATE_H
#define POKEHEARTGOLD_COMM_STATE_PRIVATE_H

#include "friend_roster.h"
#include "save.h"
#include "save_wifi_history.h"
#include "wifi_club_app.h"

struct WiFiPlazaPlayer;

BOOL Comm_IsNetIdConnected(u16 slot);
int Comm_CountConnected(void);
BOOL Comm_IsActive(void);
void Comm_EnableKeySync(void);
u16 Comm_GetLocalNetId(void);
BOOL Comm_HasLinkError(void);

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

void CommRandom_Init(MATHRandContext32 *seed);
void Comm_FreeCommandTable(void);
void CommWireless_Terminate(void);
void Comm_ResetWorkAndParents(void);
int CommWireless_Stop(void);
void Comm_Shutdown(void);
int DWC_GetLinkLevel(void);
s32 WM_GetLinkLevel(void);
int CommWireless_IsIdle(void);
void CommWireless_SetManagerEnded(int end);
void Comm_ResetWork(void);
void CommWireless_Init(PlayerProfile *playerProfile, int mode);
int Comm_StartParent(int arg0, int arg1, int arg2, int arg3);
void Comm_RequestTransferMode1(void);
int Comm_StartScan(int arg0, int arg1, int arg2);
void CommWireless_UpdateParents(void);
int Comm_ConnectToParent(int value);
void Comm_ResetInTransferMode1(void);
int Comm_GetConnectedChildren(void);
int CommWireless_GetParentMemberCount(int slot);
void Comm_SendFixedCommand(int command, u8 *data);
void Comm_RequestTransferMode0(void);
void Comm_SendFixedParentCommand(int command, u8 *data);
void Wireless_SetBeaconCallback(void *callback);
void Comm_StopFrameUpdate(void);
void WifiConnection_Shutdown(void);
int WifiConnection_Update(int success);
void Comm_SetWifiConnected(int value);
u32 WifiConnection_StartMatchmaking(s32 friendIndex, s32 maxPlayers, s32 alternate);
void WifiConnection_SetReceiveCallbacks(void (*func0)(), void (*func1)());
s32 WifiConnection_CheckError(void);
int WifiConnection_Disconnect(int checkOnly);
int WifiConnection_FinishDisconnect(void);
int DWC_GetLastErrorEx(s32 *code, s32 *category);
void DWC_ClearError(void);
s32 WifiConnection_UpdateLogin(void);
BOOL WiFiPlazaLobbyClient_Initialize(const struct WiFiPlazaPlayer *player);
void WifiConnection_Init(SaveData *saveData, int heapId, int heapSize, int maxPlayers);
void WifiConnection_SetErrorCallback(void (*func)(u32));
int WiFiPlazaLobbyClient_IsMatchActive(int index);
void WiFiPlazaLobbyClient_HostMatch(int index, int maxPlayers);
void WiFiPlazaLobbyClient_JoinMatch(int index);
void CommWireless_SetDetectDrops(int value);
BOOL CommWireless_IsManagerEnded(void);
BOOL CommWireless_IsInitialized(void);
int Wireless_HasFatalError(void);
void Comm_SetWifiContinuousSend(int value);
int WiFiPlazaLobbyClient_IsInLobby(void);
int WiFiPlazaLobbyClient_Update(void);
int WiFiPlazaLobbyClient_IsDisconnected(void);

void CommState_Init(SaveData *saveData, s8 linkMode);
void CommState_Free(void);
BOOL CommState_Exists(void);
void CommState_ShutdownWait(void);
void CommState_SetEntry(u32 enabled);
void CommState_ResumeAlternateSearch(void);
void CommState_RefuseJoins(void);
void CommState_RefuseJoinsAndRestart(void);
void CommState_SetState(void (*func)(), int timer);
void CommState_EndWireless(void);
void CommState_StopWireless(void);
void CommState_ParentStart(void);
void CommState_WaitLinked(void);
void CommState_ParentLinked(void);
void CommState_ChildStartScan(void);
void CommState_ChildScanning(void);
void CommState_ChildConnecting(void);
void CommState_ChildWaitLinked(void);
void CommState_ChildRescanStop(void);
void CommState_ChildRescan(void);
void CommState_ChildLinked(void);
void CommState_RestartScanStop(void);
void CommState_RestartScanStart(void);
void CommState_Idle(void);
void CommState_FreeWhenDone(void);
void CommState_ResumeParentWaitAlone(void);
void CommState_ResumeChildStop(void);
void CommState_ShutdownWaitStopped(void);
void CommState_AlternateInit(void);
void CommState_AlternateScan(void);
void CommState_AlternateWaitStopped(void);
void CommState_AlternateStartParent(void);
void CommState_AlternateParentWait(void);
void CommState_AlternateStartScan(void);
void CommState_JoinWaitStopped(void);
void CommState_JoinStartScan(void);
void CommState_JoinConnect(void);
void CommState_JoinWaitLinked(void);
void CommState_JoinWaitReply(void);
void CommState_Joined(void);
void CommState_JoinFailed(void);
void CommState_JoinRetry(void);
void CommState_AlternateLinked(void);
void CommState_RestartIdle(void);
void CommState_ReconnectStop(void);
void CommState_ReconnectScan(void);
void CommState_ReconnectWaitParent(void);
void CommState_ReconnectWaitLinked(void);
void CommState_BeaconWatch(void);
void CommState_OnBeacon(u32 ggid, s32 info);
void CommState_BeaconWatchScan(void);
void CommState_BeaconWatchInit(void);
BOOL CommState_StopForReset(void);
void CommState_MysteryGiftParentStart(void);
void CommState_MysteryGiftChildStart(void);
void CommState_WifiFailed(void);
void CommState_WifiTimedOut(void);
void CommState_WifiDisconnected(void);
void CommState_WifiCancelled(void);
void CommState_WifiConnected(void);

void CommState_WifiLobby(void);
void CommState_WifiStartMatch(void);
s32 CommState_StartWifiMatch(s32 friendIndex);
void CommState_WifiJoinLobby(void);
void CommState_WifiDisconnect(void);
u8 CommState_WasWifiDisconnected(void);
BOOL CommState_IsWifiJoiningLobby(void);
BOOL CommState_IsWifiInLobby(void);
u32 *CommState_GetWifiError(void);
void CommState_WifiShutdown(void);
void CommState_EndWifiSession(void);
void CommState_LeaveWifiMatch(void);
void CommState_EndWifiMatch(void);
void CommState_SendWifiDisconnect(void);
BOOL CommState_HasWifiFailed(void);
BOOL CommState_CheckDwcError(void);
void CommState_WifiLogin(void);
void CommState_WifiClubStart(void);
WifiClubStatusData *CommState_StartWifiClub(SaveData *saveData, u32 dataSize);
void CommState_StartWifiPlaza(SaveData *saveData, const struct WiFiPlazaPlayer *player);
WifiClubStatusData *CommState_GetWifiClubData(void);
void CommState_SetErrorWatch(BOOL watchMembers, BOOL reportErrors);
u8 CommState_GetLinkMode(void);
u8 CommState_GetBeaconId(void);
int CommState_IsWifi(void);

void CommState_SetErrorScreen(s8 errorScreen);
u8 CommState_GetErrorScreen(void);
BOOL CommState_IsLinkDown(void);
BOOL CommState_SetError(int errorKind);
void CommState_SetWifiPeerLinkMode29(void);
void CommState_SetClubWifiLinkMode(void);
void CommState_SetWifiClubLinkMode(void);
void CommState_SetSingleBattleWifiLinkMode(void);
void CommState_PlazaStart(void);
void CommState_PlazaWaitLobby(void);
void CommState_PlazaLobby(void);
s32 CommState_PlazaCheckWifiResult(s32 result);
s32 CommState_PlazaUpdateLobby(void);
int CommState_PlazaUpdate(void);
void CommState_PlazaUpdateMatch(s32 *matchResult);
void CommState_PlazaLogout(void);
void CommState_PlazaWaitLogout(void);
void CommState_PlazaLobbyFailed(void);
void CommState_PlazaMatchConnected(void);
void CommState_PlazaMatching(void);
void CommState_PlazaEndMatch(void);
void CommState_PlazaTimedOut(void);
void CommState_SetFrontierWifiLinkMode(void);
void Comm_RecordPlayerLocations(SaveWiFiHistory *wifiHistory);
void Comm_MarkLocationSeen(SaveWiFiHistory *history, s32 country, s32 region, u8 language);
s32 Comm_InitDwc(enum HeapID heapID);
s32 Comm_LoadAndInitDwc(enum HeapID heapID);
int Comm_GetOwnGsProfileId(WiFiList *wifiList);
BOOL Comm_HasWifiProfile(SaveData *saveData);
s32 Comm_FindFriendSlot(SaveData *saveData, DWCFriendData *exchangeToken, s32 *slot);
s32 Comm_RegisterLinkedFriends(SaveData *saveData, s32 *results, enum HeapID heapID);

int WiFiPlazaLobbyClient_IsMatchHost(void);
void WiFiPlazaLobbyClient_StopMatch(void);
void WiFiPlazaLobbyClient_EndMatch(void);
void WiFiPlazaLobbyClient_Shutdown(void);
int WiFiPlazaLobbyClient_WasMatchCancelled(void);

void Comm_RecvParentFrameCallback(void);
void Comm_RecvChildFrameCallback(void);
void Comm_RecvPeerFrameCallback(void);

#endif // POKEHEARTGOLD_COMM_STATE_PRIVATE_H
