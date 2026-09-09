#include "frontier_data.h"

#include "global.h"

#include "heap.h"
#include "mail_message.h"
#include "msgdata.h"
#include "unk_0202D230.h"
#include "unk_02030A98.h"

typedef struct FrontierRecord {
    u8 flag0 : 1, flag1 : 1, mode : 3, group : 3;
    u8 unk1, unk2, unk3;
    u16 unk4, unk6;
    u8 unk8[4];
    u8 unkC[28];
    u32 unk28;
    u8 unk2C[16];
} FrontierRecord;
struct FrontierData {
    u16 points;
    u8 streak, rank;
    u32 unk4;
    union {
        u16 flags;
        struct {
            u16 pad : 4, active : 1, pad2 : 11;
        } bits;
    } state;
    u16 stats[6];
    u16 score;
    u8 records[2][0xA8];
};
extern const MailMessageTemplate _020F682C[4];
u32 sub_0202D230(void);
void sub_0202D234(u32 addr);
void sub_0202D240(void *data);
void sub_0202D254(void *data);
void sub_0202D274(void *data);
u32 sub_0202D284(u32 addr, u32 field, void *out);
void sub_0202D308(u32 addr, u32 field, void *value);
void sub_0202D3B0(u32 addr, u8 a, u32 b, u32 c);
u32 sub_0202D3DC(u32 addr);
void sub_0202D3E4(u32 addr, u32 value);
u32 sub_0202D450(FrontierData *, u32);
u32 sub_0202D488(FrontierData *, u32);
void sub_0202D4B8(FrontierData *, u32, void *);
void sub_0202D4DC(FrontierData *, s32, UnkStruct_02069528 *);
u32 sub_0202D230(void) {
    return 0xE4;
}
void sub_0202D234(u32 addr) {
    MI_CpuFill8((void *)addr, 0, 0x3C);
}
void sub_0202D240(void *data) {
    MI_CpuFill8(data, 0, 0x168);
    ((FrontierData *)data)->rank = 1;
}
void sub_0202D254(void *data) {
    MailMessage *messages = data;
    int i;
    for (i = 0; i < 4; i++) {
        MailMsg_Init_FromTemplate(&messages[i], &_020F682C[i]);
    }
}
void sub_0202D274(void *data) {
    MI_CpuFill8(data, 0, 0xB3C);
}
u32 sub_0202D284(u32 addr, u32 field, void *out) {
    FrontierRecord *r = (FrontierRecord *)addr;
    switch (field) {
    case 0:
        return r->mode;
    case 1:
        return r->unk2;
    case 2:
        return r->unk3;
    case 3:
        return r->unk4;
    case 4:
        return r->unk6;
    case 5:
        MI_CpuCopy8(r->unk8, out, 4);
        return 0;
    case 6:
        MI_CpuCopy8(r->unk2C, out, 16);
        return 0;
    case 7:
        return r->flag0;
    case 8:
        MI_CpuCopy8(r->unkC, out, 28);
        return 0;
    case 9:
        return r->group;
    case 10:
        return r->unk28;
    }
    return 0;
}
void sub_0202D308(u32 addr, u32 field, void *value) {
    FrontierRecord *r = (FrontierRecord *)addr;
    switch (field) {
    case 0:
        r->mode = *(u8 *)value;
        break;
    case 1:
        r->unk2 = *(u8 *)value;
        break;
    case 2:
        r->unk3 = *(u8 *)value;
        break;
    case 3:
        r->unk4 = *(u16 *)value;
        break;
    case 4:
        r->unk6 = *(u16 *)value;
        break;
    case 5:
        MI_CpuCopy8(value, r->unk8, 4);
        break;
    case 6:
        MI_CpuCopy8(value, r->unk2C, 16);
        break;
    case 7:
        r->flag0 = *(u8 *)value;
        break;
    case 8:
        MI_CpuCopy8(value, r->unkC, 28);
        break;
    case 10:
        r->unk28 = *(u32 *)value;
        break;
    case 9:
        r->group = *(u8 *)value;
        break;
    }
}
void sub_0202D3B0(u32 addr, u8 a, u32 b, u32 c) {
    FrontierRecord *r = (FrontierRecord *)addr;
    int x = r->unk3 + a;
    int y;
    int z;
    if (x < 255) {
        r->unk3 = x;
    }
    y = r->unk4 + b;
    if (y < 65535) {
        r->unk4 = y;
    }
    z = r->unk6 + c;
    if (z < 65535) {
        r->unk6 = z;
    }
}
u32 sub_0202D3DC(u32 addr) {
    return ((FrontierRecord *)addr)->flag1;
}
void sub_0202D3E4(u32 addr, u32 value) {
    ((FrontierRecord *)addr)->flag1 = (u8)value;
}
u32 FrontierData_BattlePointAction(FrontierData *data, u32 param, u32 action) {
    switch (action) {
    case 1:
        if (param > 9999) {
            data->points = 9999;
        } else {
            data->points = param;
        }
        break;
    case 5: {
        int points = data->points + param;
        if (points > 9999) {
            data->points = 9999;
        } else {
            data->points = points;
        }
        break;
    }
    case 6:
        if (data->points < param) {
            data->points = 0;
        } else {
            data->points -= param;
        }
        break;
    case 0:
    case 2:
    case 3:
    case 4:
        break;
    }
    return data->points;
}
u32 sub_0202D450(FrontierData *data, u32 action) {
    switch (action) {
    case 2:
        data->streak = 0;
        data->state.flags &= ~16;
        break;
    case 3:
        if (data->state.bits.active) {
            data->streak++;
        } else {
            data->streak = 1;
            data->state.flags |= 16;
        }
        break;
    }
    return data->streak;
}
u32 sub_0202D488(FrontierData *data, u32 action) {
    switch (action) {
    case 2:
        data->rank = 1;
        break;
    case 3:
        if (data->rank < 10) {
            data->rank++;
        }
        break;
    case 4:
        if (data->rank > 1) {
            data->rank--;
        }
        break;
    }
    return data->rank;
}
void sub_0202D4B8(FrontierData *data, u32 index, void *src) {
    if (index == 0) {
        MI_CpuCopy8(src, data->records[1], 0xA8);
    } else {
        MI_CpuCopy8(src, data->records[0], 0xA8);
    }
}
void sub_0202D4DC(FrontierData *data, s32 index, UnkStruct_02069528 *dst) {
    if (index == 0) {
        MI_CpuCopy8(data->records[1], dst, 0xA8);
    } else {
        MI_CpuCopy8(data->records[0], dst, 0xA8);
    }
}
u16 sub_0202D4FC(FrontierData *, u32);
u16 sub_0202D564(FrontierData *);
u8 sub_0202D568(FrontierData *);
u32 sub_0202D57C(void *, u32, u32);
u32 sub_0202D5C4(FrontierData *, u32, u16);
u32 sub_0202D5DC(FrontierData *, u16, u32);
void sub_0202D638(FrontierData *, u32);
u32 sub_0202D63C(FrontierData *);
void sub_0202D640(SaveData *, int, MailMessage *);
MailMessage *sub_0202D660(SaveData *, u32);
u16 sub_0202D4FC(FrontierData *data, u32 addr) {
    FrontierRecord *r = (FrontierRecord *)addr;
    u16 base = 1000 * (r->unk2 - 1);
    u16 a = 10 * r->unk4;
    u16 b = 20 * r->unk3;
    u16 score;
    u16 time;
    if (a + b > 950) {
        score = 0;
    } else {
        score = 950 - (a + b);
    }
    if (r->unk6 > 970) {
        time = 0;
    } else {
        time = (1000 - r->unk6) / 30;
    }
    u16 result = (u16)(base + score + time);
    data->score = result;
    return result;
}
u16 sub_0202D564(FrontierData *data) {
    return data->score;
}
u8 sub_0202D568(FrontierData *data) {
    return data->score / 1000;
}
u32 sub_0202D57C(void *ptr, u32 index, u32 action) {
    FrontierData *data = ptr;
    if (index == 5) {
        return 0;
    }
    if (index == 6) {
        index = 5;
    }
    switch (action) {
    case 2:
        data->stats[index] = 0;
        break;
    case 3:
        if (data->stats[index] < 65534) {
            data->stats[index]++;
        }
        break;
    }
    return data->stats[index];
}
u32 sub_0202D5C4(FrontierData *data, u32 index, u16 value) {
    if (index == 5) {
        return 0;
    }
    if (index == 6) {
        index = 5;
    }
    data->stats[index] = value;
    return data->stats[index];
}
u32 sub_0202D5DC(FrontierData *data, u16 index, u32 action) {
    u16 mask = 1;
    u16 i;
    if (index >= 16) {
        GF_ASSERT(FALSE);
        return 0;
    }
    for (i = 0; i < index; i++) {
        mask <<= 1;
    }
    switch (action) {
    // Preserve the original mask calculation before reading the flags.
    case 2:
        mask ^= 0xFFFF;
        data->state.flags = mask & *(volatile u16 *)&data->state.flags;
        break;
    case 1:
        data->state.flags |= mask;
        break;
    case 0:
        return (data->state.flags >> index) & 1;
    }
    return 0;
}
void sub_0202D638(FrontierData *data, u32 value) {
    data->unk4 = value;
}
u32 sub_0202D63C(FrontierData *data) {
    return data->unk4;
}
void sub_0202D640(SaveData *save, int index, MailMessage *message) {
    MailMessage *messages = (MailMessage *)((u8 *)Save_Frontier_GetStatic(save) + 0xABC);
    MailMsg_Copy(&messages[index], message);
}
MailMessage *sub_0202D660(SaveData *save, u32 index) {
    MailMessage *messages = (MailMessage *)((u8 *)Save_Frontier_GetStatic(save) + 0xABC);
    return &messages[index];
}
typedef struct FrontierDownloadRecord {
    u8 team[0xA8];
    u16 name[16];
    u8 systemName : 1, gender : 1, pad : 6;
    u8 trainerClass;
    u8 messages[24];
    u16 score;
} FrontierDownloadRecord;
typedef struct FrontierDownload {
    u32 date;
    u8 bits[250];
    u8 availableA, availableB;
    u8 metaA0, metaA1, metaB0, metaB1;
    FrontierDownloadRecord recordsA[7];
    u8 recordsB[0x3FC];
} FrontierDownload;
typedef struct FrontierOpponent {
    u32 id;
    u16 trainerClass;
    u8 pad6[2];
    u16 name[8];
    u8 messages[24];
    u8 team[0xA8];
} FrontierOpponent;
void sub_0202D678(FrontierDownload *, u32, u32, u32 *);
void sub_0202D6DC(FrontierDownload *);
BOOL sub_0202D6F8(u32 *, u32 *);
BOOL sub_0202D720(FrontierDownload *, u32, u32, u32 *);
u32 sub_0202D7B0(u32);
u32 sub_0202D7B8(u32);
void sub_0202D7C0(FrontierDownload *, void *, u32, u32);
void sub_0202D7F0(FrontierDownload *, u8 *);
void sub_0202D804(FrontierDownload *, FrontierOpponent *, u32);
void sub_0202D8A4(FrontierDownload *, void *, u32, u32);
void sub_0202D8D0(u32, u8 *);
void *sub_0202D8E4(FrontierDownload *, enum HeapID);
u32 sub_0202D908(SaveData *);
u32 sub_0202D928(SaveData *);
void sub_0202D678(FrontierDownload *data, u32 group, u32 entry, u32 *date) {
    u8 mask = 1;
    if (entry != 0 && entry <= 200 && group != 0 && group <= 10) {
        u16 index = (entry - 1) + (group - 1) * 200;
        u8 bit = index % 8;
        u8 byte = index / 8;
        mask <<= bit;
        data->bits[byte] |= mask;
        data->date = (date[0] << 24) | ((date[1] << 24) >> 8) | ((date[2] << 24) >> 16) | date[3];
    }
}
void sub_0202D6DC(FrontierDownload *data) {
    MI_CpuFill8(data->bits, 0, 250);
    MI_CpuFill8(&data->date, 0, 4);
}
BOOL sub_0202D6F8(u32 *a, u32 *b) {
    if (a[0] > b[0]) {
        return TRUE;
    }
    if (a[1] > b[1]) {
        return TRUE;
    }
    if (a[2] > b[2]) {
        return TRUE;
    }
    return FALSE;
}
BOOL sub_0202D720(FrontierDownload *data, u32 group, u32 entry, u32 *date) {
    u8 mask = 1;
    u32 previous[4];
    u16 index;
    u8 bit;
    u8 byte;
    if (entry > 200 || group > 10) {
        return FALSE;
    }
    u32 stored = data->date;
    previous[0] = (u8)(stored >> 24);
    previous[1] = (u8)(stored >> 16);
    previous[2] = (u8)(stored >> 8);
    previous[3] = (u8)stored;
    if (sub_0202D6F8(date, previous)) {
        sub_0202D6DC(data);
        return FALSE;
    }
    index = (group - 1) * 200 + (entry - 1);
    bit = index % 8;
    byte = index / 8;
    mask <<= bit;
    if (data->bits[byte] & mask) {
        return TRUE;
    }
    return FALSE;
}
u32 sub_0202D7B0(u32 addr) {
    return ((FrontierDownload *)addr)->availableA;
}
u32 sub_0202D7B8(u32 addr) {
    return ((FrontierDownload *)addr)->availableB;
}
void sub_0202D7C0(FrontierDownload *data, void *records, u32 a, u32 b) {
    MI_CpuCopy8(records, data->recordsA, 0x63C);
    data->metaA1 = a;
    data->metaA0 = b;
    data->availableA = 1;
}
void sub_0202D7F0(FrontierDownload *data, u8 *out) {
    out[0] = data->metaA1;
    out[1] = data->metaA0;
}
void sub_0202D804(FrontierDownload *data, FrontierOpponent *out, u32 index) {
    FrontierDownloadRecord *records = data->recordsA;
    u32 offset = index * sizeof(FrontierDownloadRecord);
    u8 *messages = out->team;
    out->id = 10000;
    out->trainerClass = ((FrontierDownloadRecord *)((u8 *)records + offset))->trainerClass;
    if (((FrontierDownloadRecord *)((u8 *)records + offset))->systemName) {
        MsgData *msg = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, (NarcId)27, 28, (enum HeapID)11);
        ReadMsgDataIntoU16Array(msg, (((FrontierDownloadRecord *)((u8 *)records + offset))->gender) + 33, out->name);
        DestroyMsgData(msg);
    } else {
        MI_CpuCopy8(((FrontierDownloadRecord *)((u8 *)records + offset))->name, out->name, 16);
    }
    MI_CpuCopy8(((FrontierDownloadRecord *)((u8 *)records + offset))->messages, out->messages, 8);
    MI_CpuCopy8(((FrontierDownloadRecord *)((u8 *)records + offset))->messages + 8, out->messages + 8, 8);
    MI_CpuCopy8(((FrontierDownloadRecord *)((u8 *)records + offset))->messages + 16, out->messages + 16, 8);
    MI_CpuCopy8(((FrontierDownloadRecord *)((u8 *)records + offset))->team, messages, 0xA8);
}
void sub_0202D8A4(FrontierDownload *data, void *records, u32 a, u32 b) {
    MI_CpuCopy8(records, data->recordsB, 0x3FC);
    data->metaB1 = a;
    data->metaB0 = b;
    data->availableB = 1;
}
void sub_0202D8D0(u32 addr, u8 *out) {
    FrontierDownload *data = (FrontierDownload *)addr;
    out[0] = data->metaB1;
    out[1] = data->metaB0;
}
void *sub_0202D8E4(FrontierDownload *data, enum HeapID heapId) {
    void *out = Heap_Alloc(heapId, 0x3FC);
    MI_CpuCopy8(data->recordsB, out, 0x3FC);
    return out;
}
u32 sub_0202D908(SaveData *save) {
    return (u32)Save_Frontier_GetStatic(save) + 0x8E0;
}
FrontierData *Save_FrontierData_Get(SaveData *save) {
    return (FrontierData *)((u8 *)Save_Frontier_GetStatic(save) + 0x954);
}
u32 sub_0202D928(SaveData *save) {
    return (u32)Save_Frontier_GetStatic(save) + 0xADC;
}
