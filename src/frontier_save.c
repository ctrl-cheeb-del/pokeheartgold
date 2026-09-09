#include "save_arrays.h"
#include "unk_02030A98.h"
extern FrontierSave _021D2AFC;
u32 Save_Frontier_sizeof(void);
void Save_Frontier_Init(FrontierSave *frontier);
void sub_0202D240(void *data);
void sub_0202D254(void *data);
void sub_0202D274(void *data);
void sub_02030A98(void *state);
void sub_02030C50(void *state);
void sub_02030DFC(void *state);
void sub_02030F94(void *state);
void sub_02031188(FrontierSave *frontier);
void sub_020311AC(FrontierSave *frontier, int row);
void sub_02031214(FrontierSave *frontier, int row);
u32 sub_02031228(FrontierSave *frontier, int stat, int index, u16 amount);
u32 sub_02031248(FrontierSave *frontier, int stat, int index, int amount);
u32 sub_020312A4(void);
void sub_020312AC(struct UnkStruct_02030A98 *data);
int sub_020312CC(SaveData *save, struct UnkStruct_02030A98 *data);

u32 Save_Frontier_sizeof(void) {
    return sizeof(FrontierSave);
}
void Save_Frontier_Init(FrontierSave *frontier) {
    MI_CpuFill8(frontier, 0, sizeof(*frontier));
    sub_0202D240((u8 *)frontier + 0x954);
    sub_0202D254((u8 *)frontier + 0xabc);
    sub_0202D274((u8 *)frontier + 0xadc);
    sub_02030A98((u8 *)frontier + 0x1618);
    sub_02030C50((u8 *)frontier + 0x161c);
    sub_02030DFC((u8 *)frontier + 0x1620);
    sub_02030F94((u8 *)frontier + 0x1624);
    MI_CpuCopy8(frontier, &_021D2AFC, sizeof(*frontier));
}
FrontierSave *Save_Frontier_GetStatic(SaveData *save) {
    return &_021D2AFC;
}
void Save_Frontier_Commit(SaveData *save) {
    FrontierSave *frontier = SaveArray_Get(save, 19);
    MI_CpuCopy8(&_021D2AFC, frontier, sizeof(*frontier));
}
void Save_Frontier_Load(SaveData *save) {
    FrontierSave *frontier = SaveArray_Get(save, 19);
    MI_CpuCopy8(frontier, &_021D2AFC, sizeof(*frontier));
}
u16 FrontierSave_GetStat(FrontierSave *frontier, int stat, int index) {
    if (stat < 112) {
        if (stat >= 100) {
            if (index >= 16) {
                stat++;
                index -= 16;
            }
            return (frontier->unk_000[stat] >> index) & 1;
        }
        return frontier->unk_000[stat];
    }
    if (index == -1) {
        GF_ASSERT(FALSE);
        return 0;
    }
    return frontier->unk_0E0[index][stat - 112];
}
u32 sub_02031108(FrontierSave *frontier, int stat, int index, u16 value) {
    if (value > 9999) {
        value = 9999;
    }
    if (stat < 112) {
        if (stat >= 100) {
            GF_ASSERT(index != 255);
            if (index >= 16) {
                stat++;
                index -= 16;
            }
            if (value == 0) {
                frontier->unk_000[stat] &= (1 << index) ^ 0xffff;
            } else {
                frontier->unk_000[stat] |= 1 << index;
            }
        } else {
            GF_ASSERT(index == 255);
            frontier->unk_000[stat] = value;
        }
    } else {
        GF_ASSERT(index != 255);
        frontier->unk_0E0[index][stat - 112] = value;
    }
    return value;
}
void sub_02031188(FrontierSave *frontier) {
    MI_CpuFill8(frontier->unk_0E0, 0, 2048);
    for (int i = 100; i <= 111; i++) {
        frontier->unk_000[i] = 0;
    }
}
void sub_020311AC(FrontierSave *frontier, int row) {
    GF_ASSERT(row != 255);
    for (; row < 31; row++) {
        MI_CpuCopy8(frontier->unk_0E0[row + 1], frontier->unk_0E0[row], 64);
        for (int i = 100; i < 111; i += 2) {
            sub_02031108(frontier, i, row, FrontierSave_GetStat(frontier, i, row + 1));
        }
    }
    frontier = (FrontierSave *)frontier->unk_0E0;
    MI_CpuFill8((u8 *)frontier + (31 << 6), 0, 64);
}
void sub_02031214(FrontierSave *frontier, int row) {
    MI_CpuFill8(frontier->unk_0E0[row], 0, 64);
}
u32 sub_02031228(FrontierSave *frontier, int stat, int index, u16 amount) {
    u16 value = FrontierSave_GetStat(frontier, stat, index);
    value += amount;
    return sub_02031108(frontier, stat, index, value);
}
u32 sub_02031248(FrontierSave *frontier, int stat, int index, int amount) {
    int value = FrontierSave_GetStat(frontier, stat, index) - amount;
    if (value < 0) {
        value = 0;
    }
    return sub_02031108(frontier, stat, index, (u16)value);
}
void sub_0203126C(FrontierSave *frontier, u32 stat, u32 index, u16 value) {
    u32 current = FrontierSave_GetStat(frontier, stat, index);
    if (current < value) {
        sub_02031108(frontier, stat, index, value);
    } else if (current > 9999) {
        sub_02031108(frontier, stat, index, 9999);
    }
}
u32 sub_020312A4(void) {
    return sizeof(struct UnkStruct_02030A98);
}
void sub_020312AC(struct UnkStruct_02030A98 *data) {
    MI_CpuFill8(data, 0, sizeof(*data));
    data->unk_000 = -1;
}
u32 *sub_020312C4(SaveData *save, u32 heapId, u32 *out) {
    return (u32 *)sub_02027144(save, (enum HeapID)heapId, (int *)out);
}
int sub_020312CC(SaveData *save, struct UnkStruct_02030A98 *data) {
    int result = sub_02027158(save, data);
    return SaveGameNormal(save) | result;
}
typedef struct UnkStruct_02030A98 ExtraFrontier;
u32 sub_0203132C(ExtraFrontier *data, int type, int index, u16 value);
u32 sub_02031378(SaveData *save, u32 *data, u32 type, u32 index, u16 value);
BOOL sub_020313C4(SaveData *save, int stat, int indexStat, int slot, u32 type, enum HeapID heapId, u32 *loadResult, int *saveResult);
u32 sub_020312E0(SaveData *save, u32 *buffer, u32 type, u32 index) {
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
u32 sub_0203132C(ExtraFrontier *data, int type, int index, u16 value) {
    if (value > 9999) {
        value = 9999;
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
u32 sub_02031378(SaveData *save, u32 *data, u32 type, u32 index, u16 value) {
    if (!Save_CheckExtraChunksExist(save)) {
        return 0;
    }
    u32 current = sub_020312E0(save, data, type, index);
    if (current < value) {
        return sub_0203132C((ExtraFrontier *)data, type, index, value);
    }
    if (current > 9999) {
        return sub_0203132C((ExtraFrontier *)data, type, index, 9999);
    }
    return current;
}
BOOL sub_020313C4(SaveData *save, int stat, int indexStat, int slot, u32 type, enum HeapID heapId, u32 *loadResult, int *saveResult) {
    FrontierSave *frontier;
    u16 value, index;
    BOOL changed = FALSE;
    GF_ASSERT(stat >= 34 && stat <= 60);
    GF_ASSERT(indexStat == 36 || indexStat == 48 || indexStat == 60);
    *loadResult = 1;
    *saveResult = 2;
    if (slot != 255) {
        return FALSE;
    }
    if (!Save_CheckExtraChunksExist(save)) {
        return FALSE;
    }
    frontier = Save_Frontier_GetStatic(save);
    value = FrontierSave_GetStat(frontier, stat, slot);
    index = FrontierSave_GetStat(frontier, indexStat, slot);
    u32 *data = sub_020312C4(save, heapId, loadResult);
    u32 old;
    if (*loadResult != 1) {
        old = 0;
    } else {
        old = sub_020312E0(save, data, type, index);
    }
    sub_02031378(save, data, type, index, value);
    if (value != old) {
        *saveResult = sub_020312CC(save, (struct UnkStruct_02030A98 *)data);
        changed = TRUE;
    }
    if (data != NULL) {
        Heap_Free(data);
    }
    return changed;
}
