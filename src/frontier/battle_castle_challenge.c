#include "global.h"

#include "constants/game_stats.h"
#include "constants/items.h"
#include "constants/pokemon.h"

#include "frontier/battle_castle_data.h"
#include "frontier/battle_castle_setup.h"
#include "frontier/frontier_link_messages.h"
#include "frontier/frontier_map.h"
#include "frontier/frontier_system.h"
#include "frontier/frontier_trainer_record.h"
#include "frontier/frontier_trainers.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0031.h"

#include "bg_window.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "filesystem_files_def.h"
#include "frontier_save_access.h"
#include "frontier_stat_ids.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "party.h"
#include "player_avatar.h"
#include "pokemon.h"
#include "render_window.h"
#include "save.h"
#include "save_vars_flags.h"
#include "sys_vars.h"
#include "text.h"

// The Battle Castle's script data: the challenge (party, opponents, saved records),
// the castle points and their windows.

void FrontierTrainer_GenerateMons(int count, u16 trainerId, u16 partnerTrainerId, u16 *setIds, FrontierMon *mons, u8 *ivs, u32 *personalities, u8 hasPartner);

static void BattleCastleData_SetupNewChallenge(BattleCastleData *data);
static void BattleCastleData_RestoreChallenge(BattleCastleData *data);
static void BattleCastleData_RestoreParty(BattleCastleData *data);
static u16 BattleCastleAppArgs_GetSelection(BattleCastleAppArgs *args, u32 index);
static void BattleCastle_DrawPointsWindowFrame(BgConfig *bgConfig, Window *window);
static void BattleCastle_PrintPlayerPoints(FrontierSystem *system, Window *window, PlayerProfile *profile, u16 points);

static const u8 sBattleCastleRoundValues_Single[12] = { 0, 3, 3, 4, 4, 5, 5, 7, 7 };

static const u8 sBattleCastleRoundValues_Multi[12] = { 0, 8, 9, 11, 12, 14, 15, 18, 18 };

BattleCastleData *BattleCastleData_Alloc(SaveData *saveData, BOOL resume, u8 type, int slot0, u16 slot1, u16 slot2, u16 *resultVar) {
    static BattleCastleData *sBattleCastleData;
    BattleCastleData *data;
    CastleChallenge *challenge;
    Party *party;
    Pokemon *mon;
    FrontierSave *frontierSave;
    u8 *castleFlags;
    u16 i;
    u32 item, exp, stat;
    int count;

    sBattleCastleData = Heap_Alloc(HEAP_ID_FIELD2, sizeof(BattleCastleData));
    MI_CpuFill8(sBattleCastleData, 0, sizeof(BattleCastleData));
    data = sBattleCastleData;
    data->challenge = Save_Frontier_GetCastleChallenge(saveData);
    data->saveData = saveData;
    data->heapId = HEAP_ID_FIELD2;
    data = sBattleCastleData;
    data->playerParty = SaveArray_Party_Alloc(HEAP_ID_FIELD2);
    data->opponentParty = SaveArray_Party_Alloc(HEAP_ID_FIELD2);
    data->resultVar = resultVar;
    challenge = data->challenge;
    castleFlags = Save_Frontier_GetCastleFlags(saveData);
    if (!resume) {
        u8 hasStreak;
        data = sBattleCastleData;
        data->type = type;
        data->battleNo = 0;
        CastleChallenge_Clear(challenge);
        if (sBattleCastleData->type == FRONTIER_CHALLENGE_LINK_MULTI) {
            hasStreak = Save_VarsFlags_GetVar4052(Save_VarsFlags_Get(sBattleCastleData->saveData));
        } else {
            hasStreak = CastleFlags_GetField(castleFlags, CASTLE_FLAGS_HAS_STREAK, sBattleCastleData->type, 0, 0);
        }
        if (hasStreak == 1) {
            frontierSave = Save_Frontier_GetStatic(sBattleCastleData->saveData);
            stat = BattleCastle_GetWinStreakStat(sBattleCastleData->type);
            sBattleCastleData->winStreak = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetWinStreakStat(sBattleCastleData->type)));
        } else {
            data = sBattleCastleData;
            data->winStreak = 0;
            frontierSave = Save_Frontier_GetStatic(data->saveData);
            stat = BattleCastle_GetPointsStat(sBattleCastleData->type);
            FrontierSave_SetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)), 0);
            frontierSave = Save_Frontier_GetStatic(sBattleCastleData->saveData);
            stat = BattleCastle_GetSpentPointsStat(type);
            FrontierSave_SetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetSpentPointsStat(type)), 0);
            for (i = 0; i < 3; i++) {
                frontierSave = Save_Frontier_GetStatic(sBattleCastleData->saveData);
                stat = BattleCastle_GetRankStat(sBattleCastleData->type, i);
                FrontierSave_SetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetRankStat(sBattleCastleData->type, i)), 1);
            }
        }
        data = sBattleCastleData;
        data->round = data->winStreak / 7;
        data->unk_018 = 0;
        data->partySlots[0] = slot0;
        data->partySlots[1] = slot1;
        data->partySlots[2] = slot2;
        frontierSave = Save_Frontier_GetStatic((*(BattleCastleData *volatile *)&sBattleCastleData)->saveData);
        stat = BattleCastle_GetPointsStat(sBattleCastleData->type);
        data->points = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)));
        frontierSave = Save_Frontier_GetStatic(sBattleCastleData->saveData);
        stat = BattleCastle_GetPointsStat(sBattleCastleData->type);
        FrontierSave_AddStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)), 10);
    } else {
        BattleCastleData *saved;
        u32 zero = 0;
        data = sBattleCastleData;
        data->type = CastleChallenge_GetField(challenge, zero, zero, zero, zero);
        data->battleNo = CastleChallenge_GetField(challenge, CASTLE_CHALLENGE_BATTLE_NO, zero, zero, zero);
        saved = sBattleCastleData;
        frontierSave = Save_Frontier_GetStatic(saved->saveData);
        stat = BattleCastle_GetWinStreakStat(sBattleCastleData->type);
        saved->winStreak = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetWinStreakStat(data->type)));
        saved->round = saved->winStreak / 7;
        for (i = 0; i < 3; i++) {
            u8 slot = CastleChallenge_GetField(challenge, CASTLE_CHALLENGE_PARTY_SLOTS, i, zero, zero);
            sBattleCastleData->partySlots[i] = slot;
        }
    }
    for (i = 0; i < 3; i++) {
        data = sBattleCastleData;
        mon = Party_GetMonByIndex(SaveArray_Party_Get(data->saveData), data->partySlots[i]);
        data = sBattleCastleData;
        data->heldItems[i] = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    }
    party = SaveArray_Party_Get(data->saveData);
    count = BattleCastle_GetPartySize(sBattleCastleData->type, 0);
    for (i = 0; i < count; i++) {
        mon = Party_GetMonByIndex(party, sBattleCastleData->partySlots[i]);
        Party_AddMon(sBattleCastleData->playerParty, mon);
        mon = Party_GetMonByIndex(sBattleCastleData->playerParty, i);
        item = ITEM_NONE;
        SetMonData(mon, MON_DATA_HELD_ITEM, &item);
        if (GetMonData(mon, MON_DATA_LEVEL, NULL) > 50) {
            exp = GetMonExpBySpeciesAndLevel(GetMonData(mon, MON_DATA_SPECIES, NULL), 50);
            SetMonData(mon, MON_DATA_EXPERIENCE, &exp);
            CalcMonLevelAndStats(mon);
        }
    }
    if (BattleCastle_IsMultiType(sBattleCastleData->type) == TRUE) {
        Frontier_RecordLinkPlayerLocations(sBattleCastleData->saveData);
    }
    return sBattleCastleData;
}

void BattleCastleData_Init(BattleCastleData *data, u32 resume) {
    if (!resume) {
        BattleCastleData_SetupNewChallenge(data);
    } else {
        BattleCastleData_RestoreChallenge(data);
    }
}

static void BattleCastleData_SetupNewChallenge(BattleCastleData *data) {
    int count = (u8)Party_GetCount(data->playerParty), i, battleNo;
    Pokemon *mon;
    int monCount;
    u32 isLink;

    for (i = 0; i < count; i++) {
        mon = Party_GetMonByIndex(data->playerParty, i);
        data->startPP[i][0] = GetMonData(mon, MON_DATA_MOVE1_PP, NULL);
        data->startPP[i][1] = GetMonData(mon, MON_DATA_MOVE2_PP, NULL);
        data->startPP[i][2] = GetMonData(mon, MON_DATA_MOVE3_PP, NULL);
        data->startPP[i][3] = GetMonData(mon, MON_DATA_MOVE4_PP, NULL);
    }
    BattleCastle_GetRoundTrainerIds(data->type, BattleCastle_GetRound(data), data->trainerIds, 14);
    battleNo = data->battleNo;
    monCount = BattleCastle_GetOpponentMonCount(data->type, 1);
    isLink = BattleCastle_IsMultiType(data->type);
    FrontierTrainer_GenerateMons(monCount, data->trainerIds[battleNo], data->trainerIds[battleNo + 7], data->opponentSetIds, data->opponentMons, data->opponentIVs, data->opponentPersonalities, isLink);
}

static void BattleCastleData_RestoreChallenge(BattleCastleData *data) {
    struct {
        u8 ivs[8];
        u32 personalities[6];
        u16 setIds[6];
        FrontierMon mons[6];
    } opponents;
    int i, j;
    u16 *setId;
    Pokemon *mon;

    BattleCastleData_RestoreParty(data);
    for (i = 0; i < 14; i++) {
        data->trainerIds[i] = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_TRAINER_IDS, i, 0, 0);
    }
    j = 0;
    setId = opponents.setIds;
    for (; j < 4; setId++, j++) {
        *setId = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_SET_IDS, j, 0, 0);
        data->opponentSetIds[j] = *setId;
    }
    FrontierMon_GenerateList(opponents.mons, opponents.setIds, opponents.ivs, NULL, opponents.personalities, 4, HEAP_ID_FIELD2, NARC_a_2_0_3);
    mon = AllocMonZeroed(HEAP_ID_FIELD2);
    for (i = 0; i < 4; i++) {
        FrontierMon_ToPokemon(&opponents.mons[i], mon, BattleCastle_GetMonLevel(data));
        BattleCastle_AddMonToParty(data, data->opponentParty, mon);
    }
    Heap_Free(mon);
}

static void BattleCastleData_RestoreParty(BattleCastleData *data) {
    int count = (u8)Party_GetCount(data->playerParty);
    int i;
    u8 byteValue;
    u16 halfValue;
    u32 wordValue;
    for (i = 0; i < count; i++) {
        Pokemon *mon = Party_GetMonByIndex(data->playerParty, i);
        halfValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_HP, i, 0, 0);
        SetMonData(mon, MON_DATA_HP, &halfValue);
        byteValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_PP, i, 0, 0);
        SetMonData(mon, MON_DATA_MOVE1_PP, &byteValue);
        byteValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_PP, i, 1, 0);
        SetMonData(mon, MON_DATA_MOVE2_PP, &byteValue);
        byteValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_PP, i, 2, 0);
        SetMonData(mon, MON_DATA_MOVE3_PP, &byteValue);
        byteValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_PP, i, 3, 0);
        SetMonData(mon, MON_DATA_MOVE4_PP, &byteValue);
        wordValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_STATUS, i, 0, 0);
        SetMonData(mon, MON_DATA_STATUS, &wordValue);
        halfValue = CastleChallenge_GetField(data->challenge, CASTLE_CHALLENGE_HELD_ITEM, i, 0, 0);
        SetMonData(mon, MON_DATA_HELD_ITEM, &halfValue);
    }
}

void BattleCastleData_Free(BattleCastleData *data) {
    if (data != NULL) {
        if (data->playerParty != NULL) {
            Heap_Free(data->playerParty);
        }
        if (data->opponentParty != NULL) {
            Heap_Free(data->opponentParty);
        }
        MI_CpuFill8(data, 0, sizeof(BattleCastleData));
        Heap_Free(data);
    }
}

void BattleCastleData_ReadAppResult(BattleCastleData *data, BattleCastleAppArgs *args) {
    int i;
    for (i = 0; i < 6; i++) {
        data->selections[i] = BattleCastleAppArgs_GetSelection(args, (u8)i);
    }
    for (i = 0; i < 4; i++) {
        data->opponentChecked[i] = args->checked[i];
        data->opponentLevelChanges[i] = args->levelChanges[i];
        data->opponentStatsBought[i] = args->statsBought[i];
        data->opponentMovesBought[i] = args->movesBought[i];
    }
    data->partnerPoints = args->partnerPoints;
}

static u16 BattleCastleAppArgs_GetSelection(BattleCastleAppArgs *args, u32 index) {
    if (index >= 6) {
        GF_ASSERT(FALSE);
        return 0;
    }
    return args->selection;
}

void BattleCastleData_Save(BattleCastleData *data, int mode) {
    u32 count;
    u8 *castleFlags = Save_Frontier_GetCastleFlags(data->saveData);
    FrontierSave *frontierSave = Save_Frontier_GetStatic(data->saveData);
    struct {
        u16 half;
        u8 padding_02[6];
        u8 byte;
        u8 padding_09[3];
        u32 word;
        u8 padding_10[12];
    } value;
    u16 i;
    u32 best;
    u32 oldBest, points, stat;
    BattleCastle_GetOpponentMonCount(data->type, 1);
    value.byte = data->type;
    CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_TYPE, 0, 0, &value.byte);
    CastleChallenge_SetSaved(data->challenge, 1);
    value.byte = data->battleNo;
    CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_BATTLE_NO, 0, 0, &value.byte);
    stat = BattleCastle_GetWinStreakStat(data->type);
    FrontierSave_SetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetWinStreakStat(data->type)), data->winStreak);
    if (mode != 2) {
        stat = BattleCastle_GetBestStreakStat(data->type);
        oldBest = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetBestStreakStat(data->type)));
        stat = BattleCastle_GetBestStreakStat(data->type);
        FrontierSave_RaiseStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetBestStreakStat(data->type)), data->winStreak);
        stat = BattleCastle_GetBestStreakStat(data->type);
        best = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetBestStreakStat(data->type)));
        stat = BattleCastle_GetPointsStat(data->type);
        points = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)));
        if (data->winStreak == oldBest) {
            stat = BattleCastle_GetBestStreakPointsStat(data->type);
            FrontierSave_RaiseStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetBestStreakPointsStat(data->type)), points);
        } else if (oldBest < best) {
            stat = BattleCastle_GetBestStreakPointsStat(data->type);
            FrontierSave_SetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetBestStreakPointsStat(data->type)), points);
        }
        value.byte = data->hasStreak;
        CastleFlags_SetField(castleFlags, CASTLE_FLAGS_HAS_STREAK, data->type, 0, &value.byte);
        if (data->type == FRONTIER_CHALLENGE_LINK_MULTI) {
            FrontierSave_SetStat(frontierSave, 108, FrontierStat_GetFriendIndex(108), data->hasStreak);
        }
    }
    for (i = 0; i < 14; i++) {
        value.half = data->trainerIds[i];
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_TRAINER_IDS, i, 0, &value.half);
    }
    for (i = 0; i < 3; i++) {
        value.byte = data->partySlots[i];
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_PARTY_SLOTS, i, 0, &value.byte);
    }
    count = Party_GetCount(data->playerParty);
    for (i = 0; i < count; i++) {
        Pokemon *mon = Party_GetMonByIndex(data->playerParty, i);
        value.half = GetMonData(mon, MON_DATA_HP, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_HP, i, 0, &value.half);
        value.byte = GetMonData(mon, MON_DATA_MOVE1_PP, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_PP, i, 0, &value.byte);
        value.byte = GetMonData(mon, MON_DATA_MOVE2_PP, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_PP, i, 1, &value.byte);
        value.byte = GetMonData(mon, MON_DATA_MOVE3_PP, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_PP, i, 2, &value.byte);
        value.byte = GetMonData(mon, MON_DATA_MOVE4_PP, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_PP, i, 3, &value.byte);
        value.word = GetMonData(mon, MON_DATA_STATUS, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_STATUS, i, 0, &value.word);
        value.half = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_HELD_ITEM, i, 0, &value.half);
    }
    count = Party_GetCount(data->opponentParty);
    for (i = 0; i < count; i++) {
        Party_GetMonByIndex(data->opponentParty, i);
        value.half = data->opponentSetIds[i];
        CastleChallenge_SetField(data->challenge, CASTLE_CHALLENGE_SET_IDS, i, 0, &value.half);
    }
}

u8 BattleCastleData_NextBattle(BattleCastleData *data) {
    data->battleNo++;
    return data->battleNo;
}

u8 BattleCastleData_GetBattleNo(BattleCastleData *data) {
    return data->battleNo;
}

u32 BattleCastleData_GetTrainerSprite(BattleCastleData *data, u32 index) {
    FrontierTrainerRecord trainer;
    u8 trainerNo = data->battleNo + index * 7;
    void *record = FrontierTrainer_Load(&trainer, data->trainerIds[trainerNo], HEAP_ID_FIELD2, NARC_a_2_0_2);
    Heap_Free(record);
    return FrontierTrainer_GetClassSprite(trainer.trainerClass);
}

void BattleCastleData_ResetRanks(BattleCastleData *data) {
    int i;
    for (i = 0; i < 3; i++) {
        FrontierSave *frontierSave = Save_Frontier_GetStatic(data->saveData);
        u32 stat = BattleCastle_GetRankStat(data->type, i);
        u32 substat = FrontierStat_GetFriendIndex(BattleCastle_GetRankStat(data->type, i));
        FrontierSave_SetStat(frontierSave, stat, substat, 1);
    }
    BattleCastleData_Save(data, 1);
}

void BattleCastleData_EndRound(BattleCastleData *data) {
    data->hasStreak = TRUE;
    if (data->round < 8) {
        data->round++;
    }
    data->battleNo = 0;
    BattleCastleData_Save(data, 0);
}

void BattleCastleData_SetPartyBeforeBattle(BattleCastleData *data) {
    BattleCastle_SetOpponentParty(data);
}

void BattleCastleData_GenerateOpponents(BattleCastleData *data) {
    int monCount;
    BOOL isLink;
    int battleNo = data->battleNo;
    monCount = BattleCastle_GetOpponentMonCount(data->type, 1);
    isLink = BattleCastle_IsMultiType(data->type);
    FrontierTrainer_GenerateMons(monCount,
        data->trainerIds[battleNo],
        data->trainerIds[battleNo + 7],
        data->opponentSetIds,
        data->opponentMons,
        data->opponentIVs,
        data->opponentPersonalities,
        isLink);
    BattleCastle_SetOpponentParty(data);
}

void BattleCastleData_RecordLinkPartyPP(BattleCastleData *data) {
    s32 start = Comm_GetLocalNetId() == 0 ? 0 : 2;
    s32 count = BattleCastle_GetPartySize(data->type, 0);
    s32 end;
    s32 i;
    Party_GetCount(data->playerParty);
    i = start;
    end = count + start;
    for (; i < end; i++) {
        Pokemon *mon = Party_GetMonByIndex(data->playerParty, i);
        data->startPP[i - start][0] = GetMonData(mon, MON_DATA_MOVE1_PP, NULL);
        data->startPP[i - start][1] = GetMonData(mon, MON_DATA_MOVE2_PP, NULL);
        data->startPP[i - start][2] = GetMonData(mon, MON_DATA_MOVE3_PP, NULL);
        data->startPP[i - start][3] = GetMonData(mon, MON_DATA_MOVE4_PP, NULL);
    }
    BattleCastle_ReviveParty(data->playerParty);
    for (i = 0; i < 4; i++) {
        data->opponentChecked[i] = 0;
        data->opponentLevelChanges[i] = 0;
        data->opponentStatsBought[i] = 0;
        data->opponentMovesBought[i] = 0;
    }
}

// Castle points earned by the last battle: from the party's HP, status and PP left (and data->unk_374).
int BattleCastleData_CalcPointsEarned(BattleCastleData *data) {
    int points;
    int ppLeft;
    int i, j, k;
    int start;
    int end;
    int numMons;
    int numOpponents;
    int ppTotal;
    int ppUsed;
    Pokemon *mon;
    u32 hp, maxHp;
    u8 counts[20];

    points = 0;
    for (i = 0; i < 20; i++) {
        counts[i] = 0;
    }
    ppLeft = 0;
    data->monFainted = FALSE;
    if (Comm_GetLocalNetId() == 0) {
        start = 0;
    } else {
        start = 2;
    }
    numMons = BattleCastle_GetPartySize(data->type, 0);
    numOpponents = BattleCastle_GetOpponentMonCount(data->type, 1);
    end = numMons + start;
    for (i = start; i < end; i++) {
        mon = Party_GetMonByIndex(data->playerParty, i);
        if (GetMonData(mon, MON_DATA_SPECIES_EXISTS, NULL) == 0) {
            continue;
        }
        hp = GetMonData(mon, MON_DATA_HP, NULL);
        maxHp = GetMonData(mon, MON_DATA_MAX_HP, NULL);
        if (hp != 0) {
            counts[0]++;
            if (hp == maxHp) {
                counts[1]++;
            } else if (hp >= maxHp / 2) {
                counts[2]++;
            } else {
                counts[3]++;
            }
            if (GetMonData(mon, MON_DATA_STATUS, NULL) == 0) {
                counts[4]++;
            }
        } else {
            data->monFainted = TRUE;
        }
        ppLeft += GetMonData(mon, MON_DATA_MOVE1_PP, NULL);
        ppLeft += GetMonData(mon, MON_DATA_MOVE2_PP, NULL);
        ppLeft += GetMonData(mon, MON_DATA_MOVE3_PP, NULL);
        ppLeft += GetMonData(mon, MON_DATA_MOVE4_PP, NULL);
    }
    for (i = 0; i < numOpponents; i++) {
        if (data->opponentLevelChanges[i] == 1) {
            counts[8]++;
        }
    }
    ppTotal = 0;
    for (j = 0; j < numMons; j++) {
        for (k = 0; k < MAX_MON_MOVES; k++) {
            ppTotal += data->startPP[j][k];
        }
    }
    ppUsed = ppTotal - ppLeft;
    if (ppUsed <= 5) {
        counts[5]++;
    } else if (ppUsed <= 10) {
        counts[6]++;
    } else if (ppUsed <= 15) {
        counts[7]++;
    }
    points += counts[0] * 3;
    points += counts[1] * 3;
    points += counts[2] * 2;
    points += counts[3];
    points += counts[4];
    points += counts[5] * 8;
    points += counts[6] * 6;
    points += counts[7] * 4;
    points += counts[8] * 7;
    if (points <= 0) {
        points = 1;
    }
    return points;
}

void BattleCastle_AddPoints(SaveData *saveData, u32 type, s32 amount) {
    FrontierSave *frontierSave = Save_Frontier_GetStatic(saveData);
    u32 stat = BattleCastle_GetPointsStat(type);
    u32 substat = FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(type));
    {
        s32 points = FrontierSave_GetStat(frontierSave, stat, substat);
        points += amount;
        if (points > 9999) {
            frontierSave = Save_Frontier_GetStatic(saveData);
            stat = BattleCastle_GetPointsStat(type);
            substat = FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(type));
            FrontierSave_SetStat(frontierSave, stat, substat, 9999);
        } else {
            frontierSave = Save_Frontier_GetStatic(saveData);
            stat = BattleCastle_GetPointsStat(type);
            substat = FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(type));
            FrontierSave_AddStat(frontierSave, stat, substat, amount);
        }
    }
    GameStats_Add(Save_GameStats_Get(saveData), GAME_STAT_UNK66, amount);
}

BOOL BattleCastleData_SendLinkMessage(BattleCastleData *data, u32 kind, u16 value) {
    switch (kind) {
    case 0:
        BattleCastleLink_SendRecord(data);
        break;
    case 1:
        BattleCastleLink_SendTrainerIds(data);
        break;
    case 2:
        BattleCastleLink_SendChoice(data);
        break;
    case 3:
        BattleCastleLink_SendOpponentMons(data);
        break;
    case 4:
        BattleCastleLink_SendValueA(data, value);
        break;
    case 5:
        BattleCastleLink_SendValueB(data, value);
        break;
    case 6:
        BattleCastleLink_SendPartyMons(data);
        break;
    }
}

void BattleCastle_ShowPointsWindows(FrontierSystem *system, BattleCastleData *data) {
    FrontierMap *map = FrontierSystem_GetFrontierMap(system);
    GF_ASSERT(system->castlePointsWindows[0] == NULL);
    GF_ASSERT(system->castlePointsWindows[1] == NULL);
    if (!BattleCastle_IsMultiType(data->type)) {
        system->castlePointsWindows[0] = AllocWindows(HEAP_ID_FIELD2, 1);
        AddWindowParameterized(map->bgConfig, system->castlePointsWindows[0], GF_BG_LYR_MAIN_1, 1, 1, 10, 4, 14, 595);
        BattleCastle_DrawPointsWindowFrame(map->bgConfig, system->castlePointsWindows[0]);
    } else {
        system->castlePointsWindows[0] = AllocWindows(HEAP_ID_FIELD2, 1);
        system->castlePointsWindows[1] = AllocWindows(HEAP_ID_FIELD2, 1);
        AddWindowParameterized(map->bgConfig, system->castlePointsWindows[0], GF_BG_LYR_MAIN_1, 1, 1, 10, 4, 14, 595);
        AddWindowParameterized(map->bgConfig, system->castlePointsWindows[1], GF_BG_LYR_MAIN_1, 21, 1, 10, 4, 14, 555);
        BattleCastle_DrawPointsWindowFrame(map->bgConfig, system->castlePointsWindows[0]);
        BattleCastle_DrawPointsWindowFrame(map->bgConfig, system->castlePointsWindows[1]);
    }
    BattleCastle_PrintPoints(system, data);
}

static void BattleCastle_DrawPointsWindowFrame(BgConfig *bgConfig, Window *window) {
    DrawFrameAndWindow1(window, TRUE, 0x3D9, 12);
    FillWindowPixelBuffer(window, 15);
}

void BattleCastle_HidePointsWindows(FrontierSystem *system, BattleCastleData *data) {
    Window *first;
    Window *second;
    if (!BattleCastle_IsMultiType(data->type)) {
        GF_ASSERT(system->castlePointsWindows[0] != NULL);
        first = system->castlePointsWindows[0];
        EraseFrameAndWindow1(first, FALSE);
        WindowArray_Delete(first, 1);
    } else {
        GF_ASSERT(system->castlePointsWindows[0] != NULL);
        GF_ASSERT(system->castlePointsWindows[1] != NULL);
        if (Comm_GetLocalNetId() == 0) {
            first = system->castlePointsWindows[0];
            second = system->castlePointsWindows[1];
        } else {
            first = system->castlePointsWindows[1];
            second = system->castlePointsWindows[0];
        }
        EraseFrameAndWindow1(first, FALSE);
        WindowArray_Delete(first, 1);
        EraseFrameAndWindow1(second, FALSE);
        WindowArray_Delete(second, 1);
    }
    system->castlePointsWindows[0] = NULL;
    system->castlePointsWindows[1] = NULL;
}

void BattleCastle_PrintPoints(FrontierSystem *system, BattleCastleData *data) {
    FrontierSave *frontierSave;
    int stat;
    u16 points, partnerPoints;
    if (!BattleCastle_IsMultiType(data->type)) {
        GF_ASSERT(system->castlePointsWindows[0]);
        frontierSave = Save_Frontier_GetStatic(data->saveData);
        stat = BattleCastle_GetPointsStat(data->type);
        points = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)));
        BattleCastle_PrintPlayerPoints(system, system->castlePointsWindows[0], Save_PlayerData_GetProfile(data->saveData), points);
    } else {
        GF_ASSERT(system->castlePointsWindows[0]);
        GF_ASSERT(system->castlePointsWindows[1]);
        if (!Comm_GetLocalNetId()) {
            frontierSave = Save_Frontier_GetStatic(data->saveData);
            stat = BattleCastle_GetPointsStat(data->type);
            points = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)));
            partnerPoints = data->partnerPoints;
        } else {
            points = data->partnerPoints;
            frontierSave = Save_Frontier_GetStatic(data->saveData);
            stat = BattleCastle_GetPointsStat(data->type);
            partnerPoints = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(data->type)));
        }
        BattleCastle_PrintPlayerPoints(system, system->castlePointsWindows[0], CommPlayerInfo_GetProfile(0), points);
        BattleCastle_PrintPlayerPoints(system, system->castlePointsWindows[1], CommPlayerInfo_GetProfile(1), partnerPoints);
    }
}

static void BattleCastle_PrintPlayerPoints(FrontierSystem *system, Window *window, PlayerProfile *profile, u16 points) {
    String *tmp = String_New(20, system->heapId);
    String *buf = String_New(20, system->heapId);
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0031_bin, HEAP_ID_FIELD2);

    BufferIntegerAsString(system->msgFormat, 0, points, 4, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    ReadMsgDataIntoString(msgData, msg_0031_00002, tmp);
    StringExpandPlaceholders(system->msgFormat, buf, tmp);
    AddTextPrinterParameterized(window, 0, buf, 16, 16, TEXT_SPEED_NOTRANSFER, NULL);
    BufferPlayersName(system->msgFormat, 0, profile);
    ReadMsgDataIntoString(msgData, msg_0031_00000, tmp);
    StringExpandPlaceholders(system->msgFormat, buf, tmp);
    AddTextPrinterParameterized(window, 0, buf, 0, 0, TEXT_SPEED_INSTANT, NULL);
    String_Delete(tmp);
    String_Delete(buf);
    DestroyMsgData(msgData);
    CopyWindowToVram(window);
}

// Value of the current round from sBattleCastleRoundValues_Single / sBattleCastleRoundValues_Multi (0x14 at 21 / 49 wins of the single challenge).
u32 BattleCastleData_GetRoundTableValue(BattleCastleData *data) {
    u32 type = data->type;
    u32 round = data->round;
    u32 result;
    if (type <= FRONTIER_CHALLENGE_DOUBLE) {
        result = round >= 8 ? 7 : sBattleCastleRoundValues_Single[round];
    } else {
        result = round >= 8 ? 0x12 : sBattleCastleRoundValues_Multi[round];
    }
    if (type == FRONTIER_CHALLENGE_SINGLE) {
        u16 winStreak = data->winStreak;
        if (winStreak == FRONTIER_BRAIN_BATTLE_SILVER || winStreak == FRONTIER_BRAIN_BATTLE_GOLD) {
            result = 0x14;
        }
    }
    return result;
}
