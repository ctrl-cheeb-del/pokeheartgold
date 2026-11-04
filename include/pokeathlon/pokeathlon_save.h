#ifndef POKEHEARTGOLD_POKEATHLON_SAVE_H
#define POKEHEARTGOLD_POKEATHLON_SAVE_H

#include "save.h"

typedef struct PokeathlonStatistics {
    u32 playTime;
    u32 coursesJoined;
    u32 courseFirstPlaces;
    u32 courseLastPlaces;
    u32 bonusesEarned;
    u32 monInstructions;
    u32 monFailures;
    u32 monJumps;
    u32 monPointsEarned;
    u32 monTackles;
    u32 monFalls;
    u32 monDashes;
    u32 monSwitches;
    u32 monSelfImpedes;
    u32 linkCoursesJoined;
    u32 linkCourseFirstPlaces;
    u32 linkCourseLastPlaces;
    u32 eventFirstPlaces[10];
    u32 eventLastPlaces;
    u32 fanCount;
} PokeathlonStatistics; // size: 0x74

typedef struct PokeathlonEventRecordTeam {
    u16 mons[3]; // bits 0-9: species, bits 10-14: form
} PokeathlonEventRecordTeam;

typedef struct PokeathlonEventRecordEntry {
    u16 score;
    PokeathlonEventRecordTeam team;
} PokeathlonEventRecordEntry; // size: 0x8

typedef struct Pokeathlon_RecordsSolo {
    PokeathlonEventRecordEntry entries[5];
    u8 timesPlayed[0x4];
} Pokeathlon_RecordsSolo; // size: 0x2C

typedef struct Pokeathlon_RecordsLink {
    PokeathlonEventRecordEntry entries[5];
    u8 unk_28[0x7C];
} Pokeathlon_RecordsLink; // size: 0xA4

typedef union PokeathlonSavePrefix {
    struct {
        u8 bytesDC[0xDC];
        u8 bytes1F0[0x1F0];
    } legacy;
    u16 nativeHalfwords[0x2CC / 2];
} PokeathlonSavePrefix;

typedef struct PokeathlonSave {
    PokeathlonSavePrefix prefix;           // 0x000: serialized byte and halfword views
    Pokeathlon_RecordsSolo recordsSolo[10]; // 0x2CC
    Pokeathlon_RecordsLink recordsLink[10]; // 0x484
    u8 soloEventBestPoints[0x14];                       // pointed to by PokeathlonSave_GetSoloEventBestPoints
    PokeathlonStatistics statistics;    // pointed to by PokeathlonSave_GetStatistics / PokeathlonSave_GetStatistics2
    int athletePoints;                      // 0xB74 - capped at 99999
    u32 dataCardsBought;                            // bitfield, bits 0-26 (PokeathlonSave_IsDataCardBought / PokeathlonSave_SetDataCardBought)
    u16 dailyItemsBought;                            // bitfield (PokeathlonSave_IsDailyItemBought / PokeathlonSave_SetDailyItemBought / PokeathlonSave_ResetDailyItemsBought)
    u16 unk_B7E;
} PokeathlonSave; // size: 0xB80

typedef struct PokeathlonFriendshipRoomStatueData {
    u16 species;
    u8 gender;
    u8 form;
} PokeathlonFriendshipRoomStatueData;

typedef struct PokeathlonSave_FriendshipRecords {
    PokeathlonFriendshipRoomStatueData friendshipRoomStatues[3];
    u8 unk[0x1C];
} PokeathlonSave_FriendshipRecords;

u32 PokeathlonSave_sizeof();
void PokeathlonSave_Init(PokeathlonSave *dest);
PokeathlonSave *Save_Pokeathlon_Get(SaveData *saveData);
PokeathlonSave *PokeathlonSave_dummy1(PokeathlonSave *pokeathlon);
void *PokeathlonSave_GetMonMedals(PokeathlonSave *pokeathlonSave);
Pokeathlon_RecordsSolo *PokeathlonSave_GetRecordsSolo(PokeathlonSave *pokeathlonSave);
Pokeathlon_RecordsLink *PokeathlonSave_GetRecordsLink(PokeathlonSave *pokeathlonSave);
void *PokeathlonSave_GetSoloEventBestPoints(PokeathlonSave *pokeathlonSave);
PokeathlonStatistics *PokeathlonSave_GetStatistics(PokeathlonSave *pokeathlonSave);
PokeathlonSave *PokeathlonSave_dummy2(PokeathlonSave *pokeathlon);
BOOL PokeathlonSave_MonHasMedal(PokeathlonSave *pokeathlonSave, int shift, int index);
Pokeathlon_RecordsSolo *PokeathlonSave_GetRecordsSolo2(PokeathlonSave *pokeathlonSave);
Pokeathlon_RecordsLink *PokeathlonSave_GetRecordsLink2(PokeathlonSave *pokeathlonSave);
PokeathlonStatistics *PokeathlonSave_GetStatistics2(PokeathlonSave *pokeathlonSave);
void PokeathlonSave_AddMonMedals(PokeathlonSave *pokeathlonSave, int shift, int index);
void PokeathlonSave_AddAthletePoints(PokeathlonSave *pokeathlonSave, u16 amount);
void PokeathlonSave_SubAthletePoints(PokeathlonSave *pokeathlonSave, u16 amount);
u32 PokeathlonSave_GetAthletePoints(PokeathlonSave *pokeathlonSave);
BOOL PokeathlonSave_IsDataCardBought(PokeathlonSave *pokeathlon, int idx);
void PokeathlonSave_SetDataCardBought(PokeathlonSave *pokeathlon, int idx);
BOOL PokeathlonSave_IsDailyItemBought(PokeathlonSave *pokeathlon, int idx);
void PokeathlonSave_SetDailyItemBought(PokeathlonSave *pokeathlon, int idx);
void PokeathlonSave_ResetDailyItemsBought(PokeathlonSave *pokeathlon);

u32 PokeathlonSave_FriendshipRecords_sizeof();
void PokeathlonSave_FriendshipRecords_Init(PokeathlonSave_FriendshipRecords *dest);
PokeathlonSave_FriendshipRecords *Save_Pokeathlon_FriendshipRecords_Get(SaveData *saveData);

#endif // POKEHEARTGOLD_POKEATHLON_SAVE_H
