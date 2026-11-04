#ifndef POKEHEARTGOLD_SAVE_FRONTIER_H
#define POKEHEARTGOLD_SAVE_FRONTIER_H

#include "global.h"

#include "frontier_data.h"
#include "pokemon_types_def.h"

typedef struct FrontierMon {
    u16 species : 11;
    u16 form : 5;
    u16 item;
    u16 moves[4];
    u32 otId;
    u32 pid;
    union {
        struct {
            u32 hpIv : 5;
            u32 atkIv : 5;
            u32 defIv : 5;
            u32 spdIv : 5;
            u32 spAtkIv : 5;
            u32 spDefIv : 5;
            u32 hasNickname : 1;
            u32 unused : 1;
        };
        u32 ivsWord;
    };
    u8 evs[6];
    u8 ppUp;
    u8 language;
    u8 ability;
    u8 friendship;
    u16 nickname[11];
} FrontierMon;

// The Battle Tower challenge in progress (fields addressed by enum BattleTowerChallengeField).
typedef struct BattleTowerChallenge {
    u8 allyReplaceItem : 1;
    u8 saved : 1; // BattleTowerChallenge_GetSaved / SetSaved
    u8 towerMode : 3;
    u8 multiAllyId : 3;
    u8 unk1;
    u8 battleNumber;
    u8 totalTimesFainted; // 20 points each off the Wi-Fi score
    u16 totalTurns;       // 10 points each off the Wi-Fi score
    u16 totalDamage;      // the last part of the Wi-Fi score
    u8 partySlots[4];
    u8 trainers[28]; // 14 trainer ids
    u32 randomState;
    u8 multiAllyData[16];
} BattleTowerChallenge;

// The challenge in progress, saved so that it can be resumed. The facilities share one save region.
typedef struct FactoryChallenge {
    u8 levelMode : 1, type : 3, saved : 1, unused : 3;
    u8 battleNo;
    u16 padding;
    u16 trainerIds[14];
    u16 rentalSetIds[4];
    u8 rentalIvs[4];
    u32 rentalPersonalities[4];
    u16 opponentSetIds[4];
    u8 opponentIvs[4];
    u32 opponentPersonalities[4];
} FactoryChallenge;

typedef struct HallChallenge {
    u8 type : 3, saved : 1, unused : 4;
    u8 battleNo;
    u8 partySlots[2];
    u16 trainerIds[20];
    u16 setIds[20];
} HallChallenge;

typedef struct CastleChallenge {
    u8 type : 3, saved : 1, unused : 4;
    u8 battleNo, padding;
    u8 partySlots[3];
    u16 trainerIds[14];
    u16 hp[4];
    u8 pp[4][4];
    u16 padding_3A;
    u32 status[4];
    u16 heldItems[4];
    u16 setIds[16];
} CastleChallenge;

typedef struct ArcadeChallenge {
    u8 type : 3, saved : 1, randomFlag : 1, unused : 3;
    u8 battleNo, cursorSpeed;
    u8 partySlots[3];
    u16 heldItems[4];
    u16 trainerIds[14];
    u16 setIds[15];
} ArcadeChallenge;

struct FrontierData {
    u16 battlePoints;
    u8 wifiStreak;
    u8 wifiRank; // 1..10
    u32 towerSeed;

    union {
        u16 flags;

        struct {
            u16 pad : 4, wifiStreakActive : 1, pad2 : 11;
        } bits;
    } state;

    u16 towerRounds[6]; // per tower mode
    u16 wifiScore;
    FrontierMon wifiTeams[2][3];
};

// One trainer of a downloaded Wi-Fi Battle Room.
typedef struct BattleRoomTrainer {
    u8 team[0xA8];
    u16 name[16];
    u8 useDefaultName : 1, gender : 1, pad : 6;
    u8 trainerClass;
    u8 messages[24];
    u16 score;
} BattleRoomTrainer;

// One leader of a downloaded Wi-Fi Battle Room.
typedef struct BattleRoomLeader {
    u16 name[PLAYER_NAME_LENGTH + 1];
    u8 padding_10[2];
    u8 country;
    u8 region;
    u8 padding_14[4];
    u8 greeting[8];
    u8 useDefaultName : 1;
    u8 gender : 1;
    u8 unk_20_2 : 6;
    u8 unk_21;
} BattleRoomLeader;

typedef struct BattleRoomDownload {
    u32 markDate;      // year, month, day, hour of the last mark, one byte each
    u8 roomMarks[250]; // one bit per (rank 1..10, room 1..200)
    u8 hasTrainers, hasLeaders;
    u8 trainersRoom, trainersRank, leadersRoom, leadersRank;
    BattleRoomTrainer trainers[7];
    BattleRoomLeader leaders[30];
} BattleRoomDownload;

typedef struct FrontierSave {
    u16 stats[112];
    u16 rowStats[32][32];
    union {
        BattleTowerChallenge tower;
        FactoryChallenge factory;
        HallChallenge hall;
        CastleChallenge castle;
        ArcadeChallenge arcade;
    } challenge;
    FrontierData frontierData;
    MailMessage towerMessages[4];
    BattleRoomDownload battleRoomDownload;
    u8 factoryFlags[4];
    u8 hallFlags[4];
    u8 castleFlags[4];
    u8 arcadeFlags[4];
} FrontierSave; // size: 0x1628

#endif
