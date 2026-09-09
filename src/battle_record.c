#include "battle/battle_setup.h"

#include "link_ruleset_data.h"
#include "math_util.h"
#include "pokemon.h"
#include "pokemon_types_def.h"
#include "save_arrays.h"
#include "system.h"
#include "unk_0202FBCC.h"

typedef struct {
    u8 order[2][4];
} BattleOrder;
typedef struct {
    u8 order[4];
} MultiOrder;
extern const BattleOrder _020F68C8;
extern const MultiOrder _020F68C4;
typedef struct {
    u16 species[12];
    u8 forms[12];
    u16 arg;
    u8 type, padding;
    LinkBattleRuleset rules;
    u8 rest[0x64 - 0x28 - sizeof(LinkBattleRuleset)];
} RecordSummary;
typedef struct {
    u16 capacity, count;
    struct UnkPokemonStruct_02072A98 mons[6];
} RecordParty;
typedef struct {
    u32 flags;
    int winFlag;
    int trainerId[4];
    Trainer trainer[4];
    BattleBg battleBg;
    Terrain terrain;
    u32 mapSection, mapNumber;
    TIMEOFDAY timeOfDay;
    u32 evolutionLocation, unk_100;
    BOOL metBill;
    u32 unk_108, weatherType;
    int levelUpFlag;
    u32 aiFlags[4];
    u32 battleSpecial;
    int safariBalls;
    BOOL fixedDamageMovesBanned;
    int unk_130;
    int positions[4];
    u16 player, unk_146;
    int unk_148;
    u8 chatot[4];
    u8 commands[4][1024];
    RecordParty parties[4];
    PlayerProfile profiles[4];
    Options options;
    u16 magic, crc;
} RecordData;

extern struct UnkStruct_0202FBCC *_021D2AF8;
u32 sub_0202FBCC(void);
void sub_0202FBD4(struct UnkStruct_0202FBCC *record);
void sub_0202FC24(void);
struct UnkStruct_0202FBCC *sub_0202FC5C(void);
void *sub_0202FC74(void);

u32 sub_0202FBCC(void) {
    return sizeof(struct UnkStruct_0202FBCC);
}
void sub_0202FBD4(struct UnkStruct_0202FBCC *record) {
    MI_CpuClear32(record, sizeof(*record));
    record->unk_0000 = -1;
}
void sub_0202FBF0(SaveData *save, enum HeapID heapId, u32 *out) {
    if (_021D2AF8 != NULL) {
        Heap_Free(_021D2AF8);
        _021D2AF8 = NULL;
    }
    _021D2AF8 = sub_0202711C(save, heapId, (int *)out, 0);
    sub_0202FBD4(_021D2AF8);
}
void sub_0202FC24(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    Heap_Free(_021D2AF8);
    _021D2AF8 = NULL;
}
BOOL sub_0202FC48(void) {
    return _021D2AF8 != NULL;
}
struct UnkStruct_0202FBCC *sub_0202FC5C(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    return _021D2AF8;
}
void *sub_0202FC74(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    return (u8 *)_021D2AF8 + 4;
}

BOOL sub_0202FC90(SaveData *save, enum HeapID heapId, int *out, void *battle, int index);
BOOL sub_0202FD28(SaveData *save, enum HeapID heapId, int *out, int index);
void sub_02030258(void *data, u32 size, u32 seed);
BOOL sub_02030154(SaveData *save, struct UnkStruct_0202FBCC *record);
BOOL sub_0203018C(SaveData *save, struct UnkStruct_0202FBCC *record);
void sub_020304F0(BattleSetup *setup, SaveData *save);
BOOL sub_0202FC90(SaveData *save, enum HeapID heapId, int *out, void *battle, int index) {
    if (_021D2AF8 != NULL) {
        Heap_Free(_021D2AF8);
        _021D2AF8 = NULL;
    }
    _021D2AF8 = sub_0202711C(save, heapId, out, index);
    if (*out != 1) {
        *out = 3;
        return TRUE;
    }
    void *data = (u8 *)_021D2AF8 + 0xe8;
    u32 crc = *(u16 *)((u8 *)data + 0x1c64);
    sub_02030258(data, 0x1c64, crc + ((crc ^ 0xffff) << 16));
    if (sub_02030154(save, _021D2AF8) == TRUE) {
        *out = 0;
        return TRUE;
    }
    if (!sub_0203018C(save, _021D2AF8)) {
        *out = 2;
        return TRUE;
    }
    if (battle != NULL) {
        sub_020304F0(battle, save);
    }
    *out = 1;
    return TRUE;
}
BOOL sub_0202FD28(SaveData *save, enum HeapID heapId, int *out, int index) {
    struct UnkStruct_0202FBCC *record = sub_0202711C(save, heapId, out, index);
    if (*out != 1) {
        *out = 3;
        Heap_Free(record);
        return FALSE;
    }
    void *data = (u8 *)record + 0xe8;
    u32 crc = *(u16 *)((u8 *)data + 0x1c64);
    sub_02030258(data, 0x1c64, crc + ((crc ^ 0xffff) << 16));
    if (sub_02030154(save, record) == TRUE) {
        *out = 0;
        Heap_Free(record);
        return FALSE;
    }
    if (!sub_0203018C(save, record)) {
        *out = 2;
        Heap_Free(record);
        return FALSE;
    }
    *out = 1;
    Heap_Free(record);
    return TRUE;
}

int sub_0202FDA4(SaveData *save, struct UnkStruct_0202FBCC *record, int index, u16 *state);
int sub_0202FDA4(SaveData *save, struct UnkStruct_0202FBCC *record, int index, u16 *state) {
    switch (*state) {
    case 0: {
        sub_0201A728(8);
        sub_0201A748((enum HeapID)11);
        int result = sub_02027134(save, record, index);
        if (result == 2) {
            Save_PrepareForAsyncWrite(save, 2);
            (*state)++;
            return 0;
        }
        sub_0201A738(8);
        return result;
    }
    case 1: {
        int result = Save_WriteFileAsync(save);
        if (result == 2 || result == 3) {
            *state = 0;
            sub_0201A774();
            sub_0201A738(8);
        }
        return result;
    }
    }
    return 0;
}

int sub_0202FE14(SaveData *save, int type, int arg, int index, u16 *state, u16 *writeState);
void sub_0202FF08(SaveData *save, void *header, void *data, int type, int arg);
void sub_02030250(void *data, u32 size, u32 seed);
int sub_0202FE14(SaveData *save, int type, int arg, int index, u16 *state, u16 *writeState) {
    switch (*state) {
    case 0: {
        if (_021D2AF8 == NULL) {
            return 3;
        }
        u8 *header = (u8 *)_021D2AF8 + 0x84;
        u8 *data = (u8 *)_021D2AF8 + 0xe8;
        sub_0202FF08(save, header, data, type, arg);
        *(u16 *)(header + 0x48) = 0xe281;
        *(u16 *)(header + 0x60) = SaveArray_CalcCRC16(save, header, 0x58);
        *(u16 *)(data + 0x1c62) = 0xe281;
        *(u16 *)(data + 0x1c64) = SaveArray_CalcCRC16(save, data, 0x1c64);
        u32 crc = *(u16 *)(data + 0x1c64);
        sub_02030250(data, 0x1c64, crc + ((crc ^ 0xffff) << 16));
        *writeState = 0;
        (*state)++;
        break;
    }
    case 1:
        return sub_0202FDA4(save, _021D2AF8, index, writeState);
    }
    return 0;
}
void sub_0202FEB8(int type, int *count, int *last);
void sub_0202FEB8(int type, int *count, int *last) {
    switch (type) {
    case 14:
    case 17:
    case 20:
    case 23:
    case 26:
    case 29:
    case 32:
        *count = 4;
        *last = 3;
        break;
    default:
        *count = 2;
        *last = 6;
        break;
    }
}

void sub_0202FF08(SaveData *save, void *header, void *recordData, int type, int arg) {
    RecordSummary *summary = header;
    RecordData *data = recordData;
    int count, partySize;
    BattleOrder order = _020F68C8;
    MultiOrder multi = _020F68C4;
    int player;
    int k;
    MI_CpuFill8(summary, 0, sizeof(*summary));
    sub_0202FEB8(type, &count, &partySize);
    k = 0;
    if (data->flags & 4) {
        if (data->flags & 128) {
            player = data->player * 2;
        } else {
            player = data->player;
        }
    } else {
        player = 0;
    }
    for (int i = 0; i < count; i++) {
        int battler;
        if ((data->flags & 8) && !(data->flags & 128)) {
            for (battler = 0; battler < count; battler++) {
                if (data->positions[battler] == order.order[data->positions[player] & 1][i]) {
                    break;
                }
            }
        } else if ((data->flags & 8) && (data->flags & 128)) {
            battler = multi.order[i];
        } else {
            battler = i;
            if (player & 1) {
                battler = i ^ 1;
            }
        }
        for (int j = 0; j < partySize; j++) {
            struct UnkPokemonStruct_02072A98 *mon = &data->parties[battler].mons[j];
            if (!mon->isEgg && !mon->checksumFailed) {
                summary->species[k] = mon->species;
                summary->forms[k] = mon->form;
            }
            k++;
        }
    }
    switch (type) {
    case 1:
    case 8:
        summary->rules = *sub_020291E8(save, 0);
        break;
    case 2:
    case 9:
        summary->rules = *sub_020291E8(save, 1);
        break;
    case 3:
    case 10:
        summary->rules = *sub_020291E8(save, 2);
        break;
    case 4:
    case 11:
        summary->rules = *sub_020291E8(save, 3);
        break;
    case 5:
    case 12:
        summary->rules = *sub_020291E8(save, 4);
        break;
    case 6:
    case 13:
        summary->rules = *sub_020291E8(save, 5);
        break;
    default:
        summary->rules = *sub_0202925C();
        break;
    }
    summary->arg = arg;
    summary->type = type;
}

BOOL sub_02030154(SaveData *save, struct UnkStruct_0202FBCC *record);
BOOL sub_0203018C(SaveData *save, struct UnkStruct_0202FBCC *record);
void sub_02030250(void *data, u32 size, u32 seed);
void sub_02030258(void *data, u32 size, u32 seed);
extern struct UnkStruct_0202FBCC *_021D2AF8;
BOOL sub_02030154(SaveData *save, struct UnkStruct_0202FBCC *record) {
    u8 *data = (u8 *)record + 0xe8;
    u8 *header = (u8 *)record + 0x84;
    if (!Save_CheckExtraChunksExist(save)) {
        return TRUE;
    }
    if (*(u16 *)(data + 0x1c62) != 0xe281 || *(u16 *)(header + 0x48) != 0xe281) {
        return TRUE;
    }
    return FALSE;
}
BOOL sub_0203018C(SaveData *save, struct UnkStruct_0202FBCC *record) {
    u8 *data = (u8 *)record + 0xe8;
    u8 *header = (u8 *)record + 0x84;
    if (*(u16 *)(data + 0x1c62) != 0xe281 || *(u16 *)(header + 0x48) != 0xe281) {
        return FALSE;
    }
    u32 crc = SaveArray_CalcCRC16(save, header, 0x58);
    if (crc != *(u16 *)(header + 0x60)) {
        return FALSE;
    }
    crc = SaveArray_CalcCRC16(save, data, 0x1c64);
    if (crc != *(u16 *)(data + 0x1c64)) {
        return FALSE;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            struct UnkPokemonStruct_02072A98 *mon = &((RecordData *)data)->parties[i].mons[j];
            if (mon->species > 495) {
                return FALSE;
            }
            if (mon->heldItem > 536) {
                return FALSE;
            }
            for (int k = 0; k < 4; k++) {
                if (mon->moves[k] > 467) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}
void sub_02030250(void *data, u32 size, u32 seed) {
    _MonEncryptSegment(data, size, seed);
}
void sub_02030258(void *data, u32 size, u32 seed) {
    _MonDecryptSegment(data, size, seed);
}
void sub_02030260(int battlerId, u32 offset, u8 value) {
    if (_021D2AF8 != NULL) {
        u8 *buffer = (u8 *)_021D2AF8 + battlerId * 1024;
        buffer += offset;
        buffer[0x238] = value;
    }
}
u8 sub_0203027C(int battlerId, u32 offset) {
    GF_ASSERT(_021D2AF8 != NULL);
    u8 *buffer = (u8 *)_021D2AF8 + battlerId * 1024;
    buffer += offset;
    return buffer[0x238];
}

void sub_020302A4(BattleSetup *setup);
void sub_020306DC(Party *party, RecordParty *record);
void sub_020302A4(BattleSetup *setup) {
    if (_021D2AF8 == NULL) {
        return;
    }
    RecordData *data = (RecordData *)((u8 *)_021D2AF8 + 0xe8);
    data->flags = setup->battleType;
    data->winFlag = setup->winFlag;
    data->battleBg = setup->battleBg;
    data->terrain = setup->terrain;
    data->mapSection = setup->mapSection;
    data->mapNumber = setup->mapNumber;
    data->timeOfDay = setup->timeOfDay;
    data->evolutionLocation = setup->evolutionLocation;
    data->unk_100 = setup->unk_164;
    data->metBill = setup->metBill;
    data->unk_108 = setup->unk_170;
    data->weatherType = setup->weatherType;
    data->levelUpFlag = setup->levelUpFlag;
    data->battleSpecial = setup->battleSpecial;
    data->safariBalls = setup->safariBalls;
    data->fixedDamageMovesBanned = setup->fixedDamaageMovesBanned;
    data->unk_130 = setup->unk_19C;
    data->player = setup->unk1B0;
    data->unk_146 = setup->unk1B3;
    data->unk_148 = setup->unk1B4;
    for (int i = 0; i < 4; i++) {
        data->trainerId[i] = setup->trainerId[i];
        data->trainer[i] = setup->trainer[i];
        if (setup->aiFlags[i] == 0) {
            data->aiFlags[i] = 320;
        } else {
            data->aiFlags[i] = setup->aiFlags[i];
        }
        data->positions[i] = setup->unk_1A0[i];
        data->chatot[i] = setup->unk1BC[i];
    }
    for (int i = 0; i < 4; i++) {
        sub_020306DC(setup->party[i], &data->parties[i]);
        PlayerProfile_Copy(setup->profile[i], &data->profiles[i]);
        data->chatot[i] = sub_02006EFC(setup->chatot[i]);
    }
    Options_Copy(setup->options, &data->options);
}
void sub_0203049C(int battlerId, u32 flags);
BOOL sub_020304B4(void);
void sub_0203049C(int battlerId, u32 flags) {
    if (_021D2AF8 != NULL) {
        ((RecordData *)((u8 *)_021D2AF8 + 0xe8))->aiFlags[battlerId] = flags;
    }
}
BOOL sub_020304B4(void) {
    if (_021D2AF8 == NULL) {
        return TRUE;
    }
    RecordData *data = (RecordData *)((u8 *)_021D2AF8 + 0xe8);
    for (int i = 0; i < 4; i++) {
        if (data->aiFlags[i] > 320) {
            return FALSE;
        }
    }
    return TRUE;
}
void sub_020304F0(BattleSetup *setup, SaveData *save);
void sub_02030724(RecordParty *record, Party *party);
void sub_020304F0(BattleSetup *setup, SaveData *save) {
    RecordData *data = (RecordData *)((u8 *)_021D2AF8 + 0xe8);
    setup->battleType = data->flags;
    setup->battleBg = data->battleBg;
    setup->terrain = data->terrain;
    setup->mapSection = data->mapSection;
    setup->mapNumber = data->mapNumber;
    setup->timeOfDay = data->timeOfDay;
    setup->evolutionLocation = data->evolutionLocation;
    setup->unk_164 = data->unk_100;
    setup->metBill = data->metBill;
    setup->unk_170 = data->unk_108;
    setup->weatherType = data->weatherType;
    setup->battleSpecial = data->battleSpecial | 16;
    setup->safariBalls = data->safariBalls;
    setup->fixedDamaageMovesBanned = data->fixedDamageMovesBanned;
    setup->unk_19C = data->unk_130;
    setup->unk1B0 = data->player;
    setup->winFlag = 0;
    setup->levelUpFlag = 0;
    Pokedex_Copy(Save_Pokedex_Get(save), setup->pokedex);
    for (int i = 0; i < 4; i++) {
        setup->trainerId[i] = data->trainerId[i];
        setup->trainer[i] = data->trainer[i];
        setup->aiFlags[i] = data->aiFlags[i];
        setup->unk_1A0[i] = data->positions[i];
        sub_02030724(&data->parties[i], setup->party[i]);
        PlayerProfile_Copy(&data->profiles[i], setup->profile[i]);
        setup->unk1BC[i] = data->chatot[i];
    }
    Options_Copy(Save_PlayerData_GetOptionsAddr(save), setup->options);
    setup->options->frame = data->options.frame;
    if (setup->options->frame >= 20) {
        setup->options->frame = 0;
    }
}
void sub_020306DC(Party *party, RecordParty *record) {
    MI_CpuFill8(record, 0, sizeof(*record));
    record->capacity = Party_GetMaxCount(party);
    record->count = Party_GetCount(party);
    for (int i = 0; i < record->count; i++) {
        sub_02072A98(Party_GetMonByIndex(party, i), &record->mons[i]);
    }
}
void sub_02030724(RecordParty *record, Party *party) {
    u8 value = 0;
    Pokemon *mon = AllocMonZeroed((enum HeapID)11);
    Party_InitWithMaxSize(party, record->capacity);
    for (int i = 0; i < record->count; i++) {
        sub_02072D64(&record->mons[i], mon);
        SetMonData(mon, 162, &value);
        Party_AddMon(party, mon);
    }
    Heap_Free(mon);
}

void *sub_0203077C(enum HeapID heapId);
void *sub_020307AC(enum HeapID heapId);
void *sub_020307DC(void);
void *sub_020307F8(void);
void sub_02030814(void *profile, void *summary, void *data, void *battle, SaveData *save);
u64 sub_0203088C(void *summary, int field, int index);
void *sub_02030920(enum HeapID heapId);
void sub_02030938(void *summary);
void sub_02030940(void *record);
void *sub_0203094C(SaveData *save);
typedef struct {
    u8 flag0 : 1, flag1 : 3, flag4 : 1, rest : 3;
    u8 value;
    u16 padding;
    u16 values4[14];
    u16 values20[4];
    u8 values28[4];
    u32 values2c[4];
    u16 values3c[4];
    u8 values44[4];
    u32 values48[4];
} FrontierRecord;
u32 sub_0203095C(FrontierRecord *record);
void sub_02030964(FrontierRecord *record, int flag);
void sub_02030978(FrontierRecord *record, int field, int index, void *value);
u32 sub_02030A24(FrontierRecord *record, int field, int index);
void *sub_0203077C(enum HeapID heapId) {
    GF_ASSERT(_021D2AF8 != NULL);
    void *result = Heap_Alloc(heapId, 0x64);
    MI_CpuCopy32((u8 *)_021D2AF8 + 0x84, result, 0x64);
    return result;
}
void *sub_020307AC(enum HeapID heapId) {
    GF_ASSERT(_021D2AF8 != NULL);
    void *result = Heap_Alloc(heapId, 0x80);
    MI_CpuCopy32((u8 *)_021D2AF8 + 4, result, 0x80);
    return result;
}
void *sub_020307DC(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    return (u8 *)_021D2AF8 + 4;
}
void *sub_020307F8(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    return (u8 *)_021D2AF8 + 0x84;
}
void sub_02030814(void *profile, void *summary, void *data, void *battle, SaveData *save) {
    GF_ASSERT(_021D2AF8 != NULL);
    MI_CpuCopy8(summary, (u8 *)_021D2AF8 + 0x84, 0x64);
    MI_CpuCopy8(data, (u8 *)_021D2AF8 + 0xe8, 0x1c68);
    MI_CpuCopy8(profile, (u8 *)_021D2AF8 + 4, 0x80);
    u32 crc = *(u16 *)((u8 *)_021D2AF8 + 0x1d4c);
    sub_02030258((u8 *)_021D2AF8 + 0xe8, 0x1c64, crc + ((crc ^ 0xffff) << 16));
    if (battle != NULL) {
        sub_020304F0(battle, save);
    }
}
u64 sub_0203088C(void *summary, int field, int index) {
    switch (field) {
    case 0:
        GF_ASSERT(index < 12);
        if (((u16 *)summary)[index] > 493) {
            return 0;
        }
        return ((u16 *)summary)[index];
    case 1:
        GF_ASSERT(index < 12);
        return ((u8 *)summary + index)[0x18];
    case 2:
        if (*(u16 *)((u8 *)summary + 0x24) > 9999) {
            return 9999;
        }
        return *(u16 *)((u8 *)summary + 0x24);
    case 3:
        if (((u8 *)summary)[0x26] >= 33) {
            return 0;
        }
        return ((u8 *)summary)[0x26];
    case 4:
        return *(u64 *)((u8 *)summary + 0x58);
    case 5:
        return ((u8 *)summary)[0x27];
    }
    GF_ASSERT(FALSE);
    return 0;
}
void *sub_02030920(enum HeapID heapId) {
    void *result = Heap_Alloc(heapId, 0x64);
    MI_CpuFill8(result, 0, 0x64);
    return result;
}
void sub_02030938(void *summary) {
    Heap_Free(summary);
}
void sub_02030940(void *record) {
    MI_CpuFill8(record, 0, 0x58);
}
void *sub_0203094C(SaveData *save) {
    return (u8 *)Save_Frontier_GetStatic(save) + 0x8e0;
}
u32 sub_0203095C(FrontierRecord *record) {
    return record->flag4;
}
void sub_02030964(FrontierRecord *record, int flag) {
    record->flag4 = (u8)flag;
}
void sub_02030978(FrontierRecord *record, int field, int index, void *value) {
    switch (field) {
    case 0:
        record->flag0 = *(u8 *)value;
        break;
    case 1:
        record->flag1 = *(u8 *)value;
        break;
    case 2:
        record->value = *(u8 *)value;
        break;
    case 3:
        record->values4[index] = *(u16 *)value;
        break;
    case 4:
        record->values20[index] = *(u16 *)value;
        break;
    case 5:
        record->values28[index] = *(u8 *)value;
        break;
    case 6:
        record->values2c[index] = *(u32 *)value;
        break;
    case 7:
        record->values3c[index] = *(u16 *)value;
        break;
    case 8:
        record->values44[index] = *(u8 *)value;
        break;
    case 9:
        record->values48[index] = *(u32 *)value;
        break;
    }
}
u32 sub_02030A24(FrontierRecord *record, int field, int index) {
    switch (field) {
    case 1:
        return record->flag1;
    case 0:
        return record->flag0;
    case 2:
        return record->value;
    case 3:
        return record->values4[index];
    case 4:
        return record->values20[index];
    case 5:
        return record->values28[index];
    case 6:
        return record->values2c[index];
    case 7:
        return record->values3c[index];
    case 8:
        return record->values44[index];
    case 9:
        return record->values48[index];
    }
    return 0;
}
