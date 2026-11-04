#ifndef POKEHEARTGOLD_COMM_STATE_INTERNAL_H
#define POKEHEARTGOLD_COMM_STATE_INTERNAL_H

#include "bg_window.h"
#include "friend_roster.h"
#include "heap.h"
#include "save.h"
#include "save_link_ruleset.h"

struct WiFiPlazaPlayer;

// What the Wi-Fi match is doing
enum WifiMatchStatus {
    WIFI_MATCH_STATUS_LOBBY,
    WIFI_MATCH_STATUS_CONNECTED,
    WIFI_MATCH_STATUS_OTHER,
    WIFI_MATCH_STATUS_TIMED_OUT,
    WIFI_MATCH_STATUS_DISCONNECTED,
    WIFI_MATCH_STATUS_CANCELLED,
};

u32 CommState_GetSyncPacketSize(void);
void CommState_StartParentSession(SaveData *saveData, s8 linkMode, s8 beaconId, LinkBattleRuleset *rules);
void CommState_StartChildSession(SaveData *saveData, s8 linkMode, s8 beaconId, LinkBattleRuleset *rules);
void CommState_ConnectToSlot(int slot);
void CommState_RestartScan(void);
void CommState_RequestShutdown(void);
s32 CommState_IsLinked(void);
void CommState_StartAlternateSearch(SaveData *saveData);
void CommState_JoinParent(s8 slot);
s32 CommState_GetJoinResult(void);
s32 CommState_IsAlternateLinked(void);
s32 CommState_IsAlternateSearchReady(void);
void CommState_StopAlternateSearch(void);
void CommState_SetUnionAppLinkMode(void);
void CommState_SetUnionRoomLinkMode(void);
void CommState_StartMysteryGiftParent(SaveData *saveData, s8 linkMode);
void CommState_StartMysteryGiftChild(SaveData *saveData, s8 linkMode);
void CommState_Main(void);
void CommState_SetLinkMode13RequestMode0(void);
void CommState_ReconnectToParent(s8 slot);
void CommState_SetRecordMixingLinkMode(void);
void CommState_JoinRecordMixing(s8 slot);
void CommState_SetSpinTradeLinkMode(void);
void CommState_JoinSpinTrade(s8 slot);
void CommState_RecvJoinRequest(int netId, int size, void *data, void *context);
void CommState_RecvJoinReply(int netId, int size, void *data, void *context);
u32 CommState_GetJoinMessageSize(void);
void CommState_SetMaxEntries(int maxEntries);
void CommState_StartBeaconWatch(SaveData *saveData);
void CommState_StopBeaconWatch(void);
u8 CommState_GetSeenGames(void);
void CommState_SetWifiError(u32 error, s32 type, s32 status);
enum WifiMatchStatus CommState_GetWifiMatchStatus(void);
void CommState_RecvWifiDisconnect(int netId, int size, void *data, void *context);
void CommState_InitWfcSession(SaveData *saveData);
void CommState_FreeWfcSession(void);
void CommState_InitMysteryGiftWfcSession(SaveData *saveData);
void CommState_FreeMysteryGiftWfcSession(void);
void CommState_InitWiiMessageWfcSession(SaveData *saveData);
void CommState_FreeWiiMessageWfcSession(void);
void CommState_LeaveWifiPlaza(void);
u8 CommState_HasPlazaLobbyStarted(void);
BOOL CommState_HasPlazaLobbyFailed(void);
void CommState_StartPlazaMatch(s32 index);
void CommState_EndPlazaMatch(void);
s32 CommState_GetPlazaMatchStatus(void);
BOOL CommState_ReportsErrors(void);
void CommState_SetSelectedOrder(void *order);
void CommState_GetSelectedOrder(void *order);
void CommState_ShowErrorAndHalt(u32 errorCode);
void CommState_ShowRestartErrorAndHalt(void);
void CommState_FrameDummy(enum HeapID heapID, BgConfig *bgConfig);
void CommState_CheckLinkError(int unused);
void CommState_SetPlazaLinkMode(void);
void Comm_InitSyncedSave(s32 *state);
BOOL Comm_SyncedSave(SaveData *saveData, s32 arg1, s32 *state);
void Comm_EnsureDwcUserData(FriendRoster *wifiList);
int Comm_FindFriendSlotByKey(SaveData *saveData, u64 friendKey, int *slot);
void Comm_StoreFriendFromPlayer(SaveData *saveData, s32 netId, s32 slot, enum HeapID heapID, u32 mode);
s32 Comm_FindFriendIndexOfPlayer(SaveData *saveData, s32 netId);

#endif // POKEHEARTGOLD_COMM_STATE_INTERNAL_H
