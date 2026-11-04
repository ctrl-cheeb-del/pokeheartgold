#ifndef POKEHEARTGOLD_FRONTIER_DATA_ACCESS_H
#define POKEHEARTGOLD_FRONTIER_DATA_ACCESS_H

#include "frontier_wifi_upload_record.h"
#include "scrcmd_9.h"

// The Wi-Fi download of one room: its trainers (BattleRoomDownload_SetTrainers) and leaders (_SetLeaders).
typedef struct BattleRoomDownloadData {
    BattleRoomTrainer trainers[7];
    BattleRoomLeader leaders[30];
} BattleRoomDownloadData;

enum BattleTowerChallengeField {
    TOWER_CHALLENGE_MODE,
    TOWER_CHALLENGE_BATTLE_NO,
    TOWER_CHALLENGE_TIMES_FAINTED,
    TOWER_CHALLENGE_TURNS,
    TOWER_CHALLENGE_DAMAGE,
    TOWER_CHALLENGE_PARTY_SLOTS,
    TOWER_CHALLENGE_ALLY_DATA,
    TOWER_CHALLENGE_ALLY_REPLACE_ITEM,
    TOWER_CHALLENGE_TRAINERS,
    TOWER_CHALLENGE_ALLY_ID,
    TOWER_CHALLENGE_RANDOM_STATE,
};

u32 BattleRoomTrainer_sizeof(void);
void BattleTowerChallenge_Clear(BattleTowerChallenge *challenge);
void FrontierData_Reset(FrontierData *frontierData);
void TowerMessages_Init(MailMessage *messages);
void BattleRoomDownload_Init(BattleRoomDownload *download);
u32 BattleTowerChallenge_GetField(BattleTowerChallenge *challenge, enum BattleTowerChallengeField field, void *out);
void BattleTowerChallenge_SetField(BattleTowerChallenge *challenge, enum BattleTowerChallengeField field, void *value);
void BattleTowerChallenge_AddWifiScoreCounters(BattleTowerChallenge *challenge, u8 timesFainted, u32 turns, u32 damage);
u32 BattleTowerChallenge_GetSaved(BattleTowerChallenge *challenge);
void BattleTowerChallenge_SetSaved(BattleTowerChallenge *challenge, u32 value);
u32 FrontierData_WifiStreakAction(FrontierData *frontierData, enum FrontierDataAction action);
u32 FrontierData_WifiRankAction(FrontierData *frontierData, enum FrontierDataAction action);
void FrontierData_SetWifiTeam(FrontierData *frontierData, u32 index, const FrontierMon *src);
void FrontierData_GetWifiTeam(FrontierData *frontierData, s32 index, FrontierWifiUploadRecord *dst);
u16 FrontierData_CalcWifiScore(FrontierData *frontierData, BattleTowerChallenge *challenge);
u16 FrontierData_GetWifiScore(FrontierData *frontierData);
u8 FrontierData_GetWifiWinCount(FrontierData *data);
u32 FrontierData_TowerRoundAction(FrontierData *data, u32 towerMode, enum FrontierDataAction action);
u32 FrontierData_SetTowerRound(FrontierData *frontierData, u32 towerMode, u16 round);
u32 FrontierData_FlagAction(FrontierData *frontierData, u16 flag, enum FrontierDataAction action);
void FrontierData_SetTowerSeed(FrontierData *data, u32 value);
u32 FrontierData_GetTowerSeed(FrontierData *data);
void Save_Frontier_SetTowerMessage(SaveData *saveData, int index, MailMessage *mailMessage);
MailMessage *Save_Frontier_GetTowerMessage(SaveData *save, u32 index);
void BattleRoomDownload_MarkRoom(BattleRoomDownload *download, u32 rank, u32 room, const RTCDate *date);
BOOL BattleRoomDownload_IsRoomMarked(BattleRoomDownload *download, u32 rank, u32 room, const RTCDate *date);
u32 BattleRoomDownload_HasTrainers(BattleRoomDownload *download);
u32 BattleRoomDownload_HasLeaders(BattleRoomDownload *download);
void BattleRoomDownload_SetTrainers(BattleRoomDownload *download, const BattleRoomTrainer *trainers, u32 rank, u32 room);
void BattleRoomDownload_GetTrainersRoom(BattleRoomDownload *download, u8 *out);
void BattleRoomDownload_GetTrainer(BattleRoomDownload *download, FrontierTrainer *trainer, int index);
void BattleRoomDownload_SetLeaders(BattleRoomDownload *download, const BattleRoomLeader *leaders, u32 rank, u32 room);
void BattleRoomDownload_GetLeadersRoom(BattleRoomDownload *download, u8 *out);
BattleRoomLeader *BattleRoomDownload_CopyLeaders(BattleRoomDownload *download, enum HeapID heapID);
BattleTowerChallenge *Save_BattleTowerChallenge_Get(SaveData *saveData);
BattleRoomDownload *Save_BattleRoomDownload_Get(SaveData *saveData);

#endif // POKEHEARTGOLD_FRONTIER_DATA_ACCESS_H
