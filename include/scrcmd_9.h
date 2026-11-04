#ifndef POKEHEARTGOLD_SCRCMD_9_H
#define POKEHEARTGOLD_SCRCMD_9_H

#include "frontier_data.h"
#include "mail_message.h"
#include "save.h"
#include "save_frontier.h"

#define TOWER_MODE_SINGLE        0
#define TOWER_MODE_DOUBLE        1
#define TOWER_MODE_MULTI         2
#define TOWER_MODE_LINK          3
#define TOWER_MODE_WIFI          4
#define TOWER_MODE_WIFI_PRACTICE 5
#define TOWER_MODE_6             6

typedef struct FrontierTrainer {
    u32 index;
    u16 trainerClass;
    u8 filler06[2];
    u16 name[8];
    MailMessage introMessage;
    MailMessage winMessage;
    MailMessage loseMessage;
    FrontierMon frontierMons[4];
} FrontierTrainer; // size: 0x110

typedef struct FrontierMultiBattleAllyData {
    u32 otId;
    u16 frontierMonIDs[2];
    u32 frontierMonPIDs[2];
} FrontierMultiBattleAllyData;

typedef struct FrontierFieldSystem {
    u32 initMagicNumber;
    enum HeapID heapID;
    u32 randomState;
    u8 currentBattleNumber; // Total battles won on current streak.
    u8 curWinStreak;
    u8 numMons;
    u8 towerMode;
    u8 wonSet : 1;
    u8 palmerDefeated : 2;
    u8 linkFlag : 1;
    u8 ribbonEarned : 1;
    u8 multiBattleAllyID : 3;
    u8 trainerGender;
    u8 linkAllyGender;
    u8 filler13;
    u16 linkAllyRound; // Takes precedence over currentRound in Link Mode if it is higher.
    u16 linkAllyMonSpecies[2];
    u16 currentBattleInSession; // Battles won in this session.
    u16 currentRound;           // Rounds (sets of 7 battles) won in the current streak.
    u8 filler1e[2];
    u32 totalTowerWins;
    u16 totalTurns;
    u16 totalDamage;
    u16 totalTimesFainted;
    u8 partyMonIndexes[4];
    u16 partyMonSpecies[4];
    u16 partyMonItems[4];
    u16 trainersInCurrentRound[14];
    u8 filler5a[0x13];
    struct BattleTowerChallenge *challenge; // Seems to be some sort of frontier save data.
    FrontierData *frontierData;
    FrontierTrainer opponents[2];
    FrontierTrainer frontierStatTrainers[5];
    FrontierMultiBattleAllyData multiBattleAllyData[5];
    u8 allyReplaceItems[5]; // Related to multi battle allies' replaced items.
    u8 filler83d;
    u16 linkSendBuffer[0x23]; // Related to linkFlag somehow. Also player gender? Also species??? these seem to be some sort of struct?
    u16 unk884[0x23]; // Seemingly never set. Probably relates to tag partner somehow.
    u8 filler8CA[2];
    u32 battleWon;
    struct BattleSetup *battleSetup;
    u8 linkReceiveCount;
    u8 partnerCheckKind;
    u8 filler8D6[2];
    u16 partnerCheckResult;
    u16 resultVar;
} FrontierFieldSystem;

#endif // POKEHEARTGOLD_SCRCMD_9_H
