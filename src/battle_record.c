#include "link_ruleset_data.h"
#include "math_util.h"
#include "pokemon_types_def.h"
#include "save_arrays.h"
#include "system.h"

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
    struct UnkPokemonStruct_02072A98 mons[6];
    u32 padding;
} RecordParty;
typedef struct {
    u32 flags;
    u8 filler4[0x134 - 4];
    u32 positions[4];
    u16 player;
    u8 filler146[0x1154 - 0x146];
    RecordParty parties[4];
} RecordData;

#include "unk_0202FBCC.h"
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
void sub_020304F0(void *battle, SaveData *save);
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
