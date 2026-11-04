#include "frontier_save_access.h"

#include "frontier_data_access.h"
#include "save_arrays.h"

static int FrontierSpeciesRecords_Save(SaveData *save, struct FrontierSpeciesRecords *data);

static FrontierSave sFrontierSave;

u32 Save_Frontier_sizeof(void) {
    return sizeof(FrontierSave);
}

void Save_Frontier_Init(void *data) {
    FrontierSave *frontier = data;
    MI_CpuFill8(frontier, 0, sizeof(*frontier));
    FrontierData_Reset(&frontier->frontierData);
    TowerMessages_Init(frontier->towerMessages);
    BattleRoomDownload_Init(&frontier->battleRoomDownload);
    FactoryFlags_Init(frontier->factoryFlags);
    HallFlags_Init(frontier->hallFlags);
    CastleFlags_Init(frontier->castleFlags);
    ArcadeFlags_Init(frontier->arcadeFlags);
    MI_CpuCopy8(frontier, &sFrontierSave, sizeof(*frontier));
}

FrontierSave *Save_Frontier_GetStatic(SaveData *save) {
    return &sFrontierSave;
}

void Save_Frontier_Commit(SaveData *save) {
    FrontierSave *frontier = SaveArray_Get(save, SAVE_FRONTIER);
    MI_CpuCopy8(&sFrontierSave, frontier, sizeof(*frontier));
}

void Save_Frontier_Load(SaveData *save) {
    FrontierSave *frontier = SaveArray_Get(save, SAVE_FRONTIER);
    MI_CpuCopy8(frontier, &sFrontierSave, sizeof(*frontier));
}

u16 FrontierSave_GetStat(FrontierSave *frontier, int stat, int index) {
    if (stat < FRONTIER_STAT_PER_FRIEND) {
        if (stat >= FRONTIER_STAT_FRIEND_FLAGS) {
            if (index >= 16) {
                stat++;
                index -= 16;
            }
            return (frontier->stats[stat] >> index) & 1;
        }
        return frontier->stats[stat];
    }
    if (index == -1) {
        GF_ASSERT(FALSE);
        return 0;
    }
    return frontier->rowStats[index][stat - FRONTIER_STAT_PER_FRIEND];
}

u32 FrontierSave_SetStat(FrontierSave *frontier, int stat, int index, u16 value) {
    if (value > FRONTIER_STAT_MAX) {
        value = FRONTIER_STAT_MAX;
    }
    if (stat < FRONTIER_STAT_PER_FRIEND) {
        if (stat >= FRONTIER_STAT_FRIEND_FLAGS) {
            GF_ASSERT(index != FRONTIER_STAT_NO_FRIEND);
            if (index >= 16) {
                stat++;
                index -= 16;
            }
            if (value == 0) {
                frontier->stats[stat] &= (1 << index) ^ 0xffff;
            } else {
                frontier->stats[stat] |= 1 << index;
            }
        } else {
            GF_ASSERT(index == FRONTIER_STAT_NO_FRIEND);
            frontier->stats[stat] = value;
        }
    } else {
        GF_ASSERT(index != FRONTIER_STAT_NO_FRIEND);
        frontier->rowStats[index][stat - FRONTIER_STAT_PER_FRIEND] = value;
    }
    return value;
}

void FrontierSave_ClearRows(FrontierSave *frontier) {
    MI_CpuFill8(frontier->rowStats, 0, sizeof(frontier->rowStats));
    for (int i = FRONTIER_STAT_FRIEND_FLAGS; i <= FRONTIER_STAT_PER_FRIEND - 1; i++) {
        frontier->stats[i] = 0;
    }
}

void FrontierSave_DeleteRow(FrontierSave *frontier, int row) {
    GF_ASSERT(row != FRONTIER_STAT_NO_FRIEND);
    for (; row < 31; row++) {
        MI_CpuCopy8(frontier->rowStats[row + 1], frontier->rowStats[row], sizeof(frontier->rowStats[0]));
        for (int i = FRONTIER_STAT_FRIEND_FLAGS; i < FRONTIER_STAT_PER_FRIEND - 1; i += 2) {
            FrontierSave_SetStat(frontier, i, row, FrontierSave_GetStat(frontier, i, row + 1));
        }
    }
    MI_CpuFill8((u8 *)frontier->rowStats + 31 * sizeof(frontier->rowStats[0]), 0, sizeof(frontier->rowStats[0]));
}

void FrontierSave_ClearRow(FrontierSave *frontier, int row, int unused) {
    MI_CpuFill8(frontier->rowStats[row], 0, sizeof(frontier->rowStats[0]));
}

u32 FrontierSave_AddStat(FrontierSave *frontier, int stat, int index, int amount) {
    u16 value = FrontierSave_GetStat(frontier, stat, index);
    value += amount;
    return FrontierSave_SetStat(frontier, stat, index, value);
}

u32 FrontierSave_SubStat(FrontierSave *frontier, int stat, int index, int amount) {
    int value = FrontierSave_GetStat(frontier, stat, index) - amount;
    if (value < 0) {
        value = 0;
    }
    return FrontierSave_SetStat(frontier, stat, index, value);
}

void FrontierSave_RaiseStat(FrontierSave *frontier, u32 stat, u32 index, u16 value) {
    u32 current = FrontierSave_GetStat(frontier, stat, index);
    if (current < value) {
        FrontierSave_SetStat(frontier, stat, index, value);
    } else if (current > FRONTIER_STAT_MAX) {
        FrontierSave_SetStat(frontier, stat, index, FRONTIER_STAT_MAX);
    }
}

u32 FrontierSpeciesRecords_sizeof(void) {
    return sizeof(struct FrontierSpeciesRecords);
}

void FrontierSpeciesRecords_Init(void *data) {
    struct FrontierSpeciesRecords *records = data;
    MI_CpuFill8(records, 0, sizeof(*records));
    records->saveKey = -1;
}

u32 *FrontierSpeciesRecords_Load(SaveData *save, u32 heapId, u32 *out) {
    return (u32 *)LoadFrontierSpeciesRecords(save, (enum HeapID)heapId, (int *)out);
}

static int FrontierSpeciesRecords_Save(SaveData *save, struct FrontierSpeciesRecords *data) {
    int result = SaveFrontierSpeciesRecords(save, data);
    return SaveGameNormal(save) | result;
}
typedef struct FrontierSpeciesRecords ExtraFrontier;
static u32 FrontierSpeciesRecords_Set(ExtraFrontier *data, int type, int index, u16 value);
static u32 FrontierSpeciesRecords_Raise(SaveData *save, u32 *data, u32 type, u32 index, u16 value);

u32 FrontierSpeciesRecords_Get(SaveData *save, u32 *buffer, u32 type, u32 index) {
    ExtraFrontier *data = (ExtraFrontier *)buffer;
    if (!Save_CheckExtraChunksExist(save)) {
        return 0;
    }
    switch (type) {
    case 0:
        return data->stats[0][index];
    case 1:
        return data->stats[1][index];
    case 2:
        return data->stats[2][index];
    }
    GF_ASSERT(FALSE);
    return 0;
}

static u32 FrontierSpeciesRecords_Set(ExtraFrontier *data, int type, int index, u16 value) {
    if (value > FRONTIER_STAT_MAX) {
        value = FRONTIER_STAT_MAX;
    }
    switch (type) {
    case 0:
        data->stats[0][index] = value;
        break;
    case 1:
        data->stats[1][index] = value;
        break;
    case 2:
        data->stats[2][index] = value;
        break;
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
    return value;
}

static u32 FrontierSpeciesRecords_Raise(SaveData *save, u32 *data, u32 type, u32 index, u16 value) {
    if (!Save_CheckExtraChunksExist(save)) {
        return 0;
    }
    u32 current = FrontierSpeciesRecords_Get(save, data, type, index);
    if (current < value) {
        return FrontierSpeciesRecords_Set((ExtraFrontier *)data, type, index, value);
    }
    if (current > FRONTIER_STAT_MAX) {
        return FrontierSpeciesRecords_Set((ExtraFrontier *)data, type, index, FRONTIER_STAT_MAX);
    }
    return current;
}

BOOL FrontierSpeciesRecords_UpdateFromStat(SaveData *save, int stat, int indexStat, int slot, u32 type, enum HeapID heapId, u32 *loadResult, int *saveResult) {
    FrontierSave *frontier;
    u16 value, index;
    BOOL changed = FALSE;
    GF_ASSERT(stat >= 34 && stat <= 60);
    GF_ASSERT(indexStat == 36 || indexStat == 48 || indexStat == 60);
    *loadResult = 1;
    *saveResult = 2;
    if (slot != FRONTIER_STAT_NO_FRIEND) {
        return FALSE;
    }
    if (!Save_CheckExtraChunksExist(save)) {
        return FALSE;
    }
    frontier = Save_Frontier_GetStatic(save);
    value = FrontierSave_GetStat(frontier, stat, slot);
    index = FrontierSave_GetStat(frontier, indexStat, slot);
    u32 *data = FrontierSpeciesRecords_Load(save, heapId, loadResult);
    u32 old;
    if (*loadResult != 1) {
        old = 0;
    } else {
        old = FrontierSpeciesRecords_Get(save, data, type, index);
    }
    FrontierSpeciesRecords_Raise(save, data, type, index, value);
    if (value != old) {
        *saveResult = FrontierSpeciesRecords_Save(save, (struct FrontierSpeciesRecords *)data);
        changed = TRUE;
    }
    if (data != NULL) {
        Heap_Free(data);
    }
    return changed;
}
