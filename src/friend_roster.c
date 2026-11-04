#include "friend_roster.h"

#include "global.h"

#include "dwc/dwc_account_internal.h"

#include "gf_rtc.h"
#include "pm_string.h"
#include "to90_login_callback_private.h"

#define FRIEND_ROSTER_RECORD_MAX 9999

typedef struct FriendEntry {
    u16 groupName[8], playerName[8];
    u32 trainerId;
    u16 wins, losses, trades, year;
    u8 month, day, gender, avatar;
    u16 poffinSessions, plazaGame0Plays, plazaGame1Plays, plazaGame2Plays;
} FriendEntry;

typedef struct FriendEntryArray {
    FriendEntry entries[FRIEND_ROSTER_MAX];
} FriendEntryArray;

struct FriendRoster {
    W41287Account header;
    DwcAccData friendData[FRIEND_ROSTER_MAX];
    FriendEntryArray roster;
};

static void FriendRoster_MoveFriend(FriendRoster *data, int dest, int src);

void Comm_EnsureDwcUserData(FriendRoster *data);

static FriendRoster sFriendRoster;

u32 Save_FriendRoster_sizeof(void) {
    return sizeof(FriendRoster);
}

void Save_FriendRoster_Init(FriendRoster *data) {
    int i;
    MI_CpuClearFast(data, sizeof(*data));
    for (i = 0; i < FRIEND_ROSTER_MAX; i++) {
        data->roster.entries[i].playerName[0] = 0xFFFF;
        data->roster.entries[i].groupName[0] = 0xFFFF;
        data->roster.entries[i].gender = FRIEND_ROSTER_GENDER_UNKNOWN;
    }
    Comm_EnsureDwcUserData(data);
    MI_CpuCopy8(data, &sFriendRoster, sizeof(*data));
}

void *FriendRoster_GetUserData(FriendRoster *data) {
    return data;
}

s32 FriendRoster_GetEntryField(FriendRoster *data, s32 index, s32 field) {
    int value;
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    switch (field) {
    case FRIEND_ROSTER_FIELD_TRAINER_ID:
        value = data->roster.entries[index].trainerId;
        break;
    case FRIEND_ROSTER_FIELD_WINS:
        value = data->roster.entries[index].wins;
        break;
    case FRIEND_ROSTER_FIELD_LOSSES:
        value = data->roster.entries[index].losses;
        break;
    case FRIEND_ROSTER_FIELD_TRADES:
        value = data->roster.entries[index].trades;
        break;
    case FRIEND_ROSTER_FIELD_YEAR:
        value = data->roster.entries[index].year;
        break;
    case FRIEND_ROSTER_FIELD_MONTH:
        value = data->roster.entries[index].month;
        break;
    case FRIEND_ROSTER_FIELD_DAY:
        value = data->roster.entries[index].day;
        break;
    case FRIEND_ROSTER_FIELD_GENDER:
        value = data->roster.entries[index].gender;
        break;
    case FRIEND_ROSTER_FIELD_AVATAR:
        value = data->roster.entries[index].avatar;
        break;
    case FRIEND_ROSTER_FIELD_POFFIN_SESSIONS:
        value = data->roster.entries[index].poffinSessions;
        break;
    case FRIEND_ROSTER_FIELD_PLAZA_GAME0_PLAYS:
        value = data->roster.entries[index].plazaGame0Plays;
        break;
    case FRIEND_ROSTER_FIELD_PLAZA_GAME1_PLAYS:
        value = data->roster.entries[index].plazaGame1Plays;
        break;
    case FRIEND_ROSTER_FIELD_PLAZA_GAME2_PLAYS:
        value = data->roster.entries[index].plazaGame2Plays;
        break;
    }
    return value;
}

void FriendRoster_SetEntryField(FriendRoster *data, int index, enum FriendRosterField field, u8 value) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    switch (field) {
    case FRIEND_ROSTER_FIELD_TRAINER_ID:
        data->roster.entries[index].trainerId = value;
        break;
    case FRIEND_ROSTER_FIELD_WINS:
        GF_ASSERT(FALSE);
        break;
    case FRIEND_ROSTER_FIELD_LOSSES:
        GF_ASSERT(FALSE);
        break;
    case FRIEND_ROSTER_FIELD_TRADES:
        GF_ASSERT(FALSE);
        break;
    case FRIEND_ROSTER_FIELD_YEAR:
        data->roster.entries[index].year = value;
        break;
    case FRIEND_ROSTER_FIELD_MONTH:
        data->roster.entries[index].month = value;
        break;
    case FRIEND_ROSTER_FIELD_DAY:
        data->roster.entries[index].day = value;
        break;
    case FRIEND_ROSTER_FIELD_GENDER:
        data->roster.entries[index].gender = value;
        break;
    case FRIEND_ROSTER_FIELD_AVATAR:
        data->roster.entries[index].avatar = value;
        break;
    case FRIEND_ROSTER_FIELD_POFFIN_SESSIONS:
        GF_ASSERT(FALSE);
        break;
    }
}

void *FriendRoster_GetDwcFriendData(FriendRoster *data, int index) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    return &data->friendData[index];
}

u16 *FriendRoster_GetPlayerName(FriendRoster *data, s32 index) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    return data->roster.entries[index].playerName;
}

void FriendRoster_SetPlayerName(FriendRoster *data, int index, String *name) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    CopyStringToU16Array(name, data->roster.entries[index].playerName, 16);
}

u16 *FriendRoster_GetGroupName(FriendRoster *data, s32 index) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    return data->roster.entries[index].groupName;
}

void FriendRoster_SetGroupName(FriendRoster *data, int index, String *name) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    CopyStringToU16Array(name, data->roster.entries[index].groupName, 16);
}

BOOL FriendRoster_IsFriendValid(FriendRoster *data, int index) {
    GF_ASSERT(index < FRIEND_ROSTER_MAX);
    return DWC_IsValidFriendData(&data->friendData[index]);
}

int FriendRoster_CountFriends(FriendRoster *data) {
    int i, count = 0;
    for (i = 0; i < FRIEND_ROSTER_MAX; i++) {
        if (FriendRoster_IsFriendValid(data, i)) {
            count++;
        }
    }
    return count;
}

int FriendRoster_GetUsedSlotCount(FriendRoster *data) {
    int end = 0, i;
    for (i = 0; i < FRIEND_ROSTER_MAX; i++) {
        if (FriendRoster_IsFriendValid(data, i)) {
            end = i + 1;
        }
    }
    return end;
}

void FriendRoster_RemoveFriend(FriendRoster *data, int index) {
    int i;
    if (index >= 0 && index < FRIEND_ROSTER_MAX) {
        for (i = index; i < FRIEND_ROSTER_MAX - 1; i++) {
            MI_CpuCopy8(&data->roster.entries[i + 1], &data->roster.entries[i], sizeof(FriendEntry));
            MI_CpuCopy8(&data->friendData[i + 1], &data->friendData[i], sizeof(DwcAccData));
        }
        MI_CpuClearFast((u8 *)&data->roster + 0x6C8, sizeof(FriendEntry));
        MI_CpuClearFast((u8 *)&data->friendData + 0x174, sizeof(DwcAccData));
        ((FriendEntry *)((u8 *)&data->roster + 0x6C8))->playerName[0] = 0xFFFF;
        ((FriendEntry *)((u8 *)&data->roster + 0x6C8))->groupName[0] = 0xFFFF;
        ((FriendEntry *)((u8 *)&data->roster + 0x6C8))->gender = FRIEND_ROSTER_GENDER_UNKNOWN;
    }
}

static void FriendRoster_MoveFriend(FriendRoster *data, int dest, int src) {
    if (dest >= 0 && dest < FRIEND_ROSTER_MAX && src >= 0 && src < FRIEND_ROSTER_MAX) {
        MI_CpuCopy8(&data->roster.entries[src], &data->roster.entries[dest], sizeof(FriendEntry));
        MI_CpuCopy8(&data->friendData[src], &data->friendData[dest], sizeof(DwcAccData));
        MI_CpuClearFast(&data->roster.entries[src], sizeof(FriendEntry));
        MI_CpuClearFast(&data->friendData[src], sizeof(DwcAccData));
        data->roster.entries[src].playerName[0] = 0xFFFF;
        data->roster.entries[src].groupName[0] = 0xFFFF;
        data->roster.entries[src].gender = FRIEND_ROSTER_GENDER_UNKNOWN;
    }
}

void FriendRoster_Compact(FriendRoster *data) {
    int i, empty = -1;
    for (i = 0; i < FRIEND_ROSTER_MAX; i++) {
        if (FriendRoster_IsFriendValid(data, i)) {
            if (empty != -1) {
                FriendRoster_MoveFriend(data, empty, i);
                i = -1;
                empty = -1;
            }
        } else if (empty == -1) {
            empty = i;
        }
    }
}

void FriendRoster_UpdateDate(FriendRoster *data, s32 index) {
    RTCDate date;
    GF_RTC_CopyDate(&date);
    if (index >= 0 && index < FRIEND_ROSTER_MAX) {
        data->roster.entries[index].year = date.year + 2000;
        data->roster.entries[index].month = date.month;
        data->roster.entries[index].day = date.day;
    }
}

void FriendRoster_AddWinsLossesTrades(FriendRoster *data, s32 index, s32 wins, s32 losses, s32 trades) {
    if (index >= 0 && index < FRIEND_ROSTER_MAX) {
        data->roster.entries[index].wins += wins;
        if (data->roster.entries[index].wins > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[index].wins = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[index].losses += losses;
        if (data->roster.entries[index].losses > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[index].losses = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[index].trades += trades;
        if (data->roster.entries[index].trades > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[index].trades = FRIEND_ROSTER_RECORD_MAX;
        }
        FriendRoster_UpdateDate(data, index);
    }
}

void FriendRoster_AddPlazaGame0Plays(FriendRoster *data, s32 index, s32 value) {
    if (index >= 0 && index < FRIEND_ROSTER_MAX) {
        data->roster.entries[index].plazaGame0Plays += value;
        if (data->roster.entries[index].plazaGame0Plays > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[index].plazaGame0Plays = FRIEND_ROSTER_RECORD_MAX;
        }
        FriendRoster_UpdateDate(data, index);
    }
}

void FriendRoster_AddPlazaGame1Plays(FriendRoster *data, s32 index, s32 value) {
    if (index >= 0 && index < FRIEND_ROSTER_MAX) {
        data->roster.entries[index].plazaGame1Plays += value;
        if (data->roster.entries[index].plazaGame1Plays > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[index].plazaGame1Plays = FRIEND_ROSTER_RECORD_MAX;
        }
        FriendRoster_UpdateDate(data, index);
    }
}

void FriendRoster_AddPlazaGame2Plays(FriendRoster *data, s32 index, s32 value) {
    if (index >= 0 && index < FRIEND_ROSTER_MAX) {
        data->roster.entries[index].plazaGame2Plays += value;
        if (data->roster.entries[index].plazaGame2Plays > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[index].plazaGame2Plays = FRIEND_ROSTER_RECORD_MAX;
        }
        FriendRoster_UpdateDate(data, index);
    }
}

void FriendRoster_MergeFriend(FriendRoster *data, s32 src, s32 dest) {
    if (dest >= 0 && dest < FRIEND_ROSTER_MAX && src >= 0 && src < FRIEND_ROSTER_MAX) {
        data->roster.entries[dest].wins += data->roster.entries[src].wins;
        if (data->roster.entries[dest].wins > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].wins = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[dest].losses += data->roster.entries[src].losses;
        if (data->roster.entries[dest].losses > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].losses = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[dest].trades += data->roster.entries[src].trades;
        if (data->roster.entries[dest].trades > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].trades = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[dest].poffinSessions += data->roster.entries[src].poffinSessions;
        if (data->roster.entries[dest].poffinSessions > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].poffinSessions = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[dest].plazaGame0Plays += data->roster.entries[src].plazaGame0Plays;
        if (data->roster.entries[dest].plazaGame0Plays > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].plazaGame0Plays = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[dest].plazaGame1Plays += data->roster.entries[src].plazaGame1Plays;
        if (data->roster.entries[dest].plazaGame1Plays > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].plazaGame1Plays = FRIEND_ROSTER_RECORD_MAX;
        }
        data->roster.entries[dest].plazaGame2Plays += data->roster.entries[src].plazaGame2Plays;
        if (data->roster.entries[dest].plazaGame2Plays > FRIEND_ROSTER_RECORD_MAX) {
            data->roster.entries[dest].plazaGame2Plays = FRIEND_ROSTER_RECORD_MAX;
        }
        MI_CpuCopyFast(data->roster.entries[src].groupName, data->roster.entries[dest].groupName, sizeof(data->roster.entries[src].groupName));
        MI_CpuClearFast(&data->roster.entries[src], sizeof(FriendEntry));
        data->roster.entries[src].playerName[0] = 0xFFFF;
        data->roster.entries[src].groupName[0] = 0xFFFF;
        data->roster.entries[src].gender = FRIEND_ROSTER_GENDER_UNKNOWN;
    }
}

FriendRoster *Save_FriendRoster_Get(SaveData *saveData) {
    return &sFriendRoster;
}

void Save_FriendRoster_LoadFromSave(SaveData *saveData) {
    FriendRoster *data = SaveArray_Get(saveData, SAVE_FRIEND_ROSTER);
    MI_CpuCopy8(data, &sFriendRoster, sizeof(FriendRoster));
}

void Save_FriendRoster_StoreToSave(SaveData *saveData) {
    FriendRoster *data = SaveArray_Get(saveData, SAVE_FRIEND_ROSTER);
    MI_CpuCopy8(&sFriendRoster, data, sizeof(FriendRoster));
}
