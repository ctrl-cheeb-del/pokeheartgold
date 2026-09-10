#include "global.h"

#include "fashion_case.h"
#include "heap.h"
#include "pm_version.h"
#include "pokemon.h"

typedef struct SaveFashionMon {
    u32 personality;
    u32 otId;
    u16 species;
    u16 nickname[11];
    u16 secondText[8];
    s8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 form;
    u8 unk_34;
} SaveFashionMon;

typedef struct FashionEntry {
    u32 magic;
    SaveFashionMon mon;
    u32 mask;
    MailMessage mailMessage;
    u8 items[10][4];
    u8 unk_70;
    u8 language;
    u8 padding_72[2];
} FashionEntry;

typedef struct FashionEntryLarge {
    u32 magic;
    u8 data[0x94];
} FashionEntryLarge;

typedef struct FashionSource {
    u32 unk_0;
    void *unk_4;
} FashionSource;

typedef struct FashionCaseReal {
    u32 regular[8];
    u32 special[2];
    u32 wallpaper[5];
    u32 padding;
} FashionCaseReal;

BOOL sub_0202B614(u32 value);
void sub_0202B6E8(SaveFashionMon *dst, Pokemon *mon, int a2);
void sub_0202B718(SaveFashionMon *dst, String *str, u8 a2);
void sub_0202B730(SaveFashionMon *src, Pokemon *mon);
void sub_0202B770(u8 *dst, u8 a1, u8 a2, u8 a3, u8 a4);
void sub_0202B784(u32 *data, int value, u8 index);
u8 sub_0202B7C8(u32 *data, u8 index);
void sub_0202B808(u32 *data, u8 value, u8 index);
u8 sub_0202B848(u32 *data, u8 index);
void sub_0202B870(u32 *data, u32 value, u8 index);
u8 sub_0202B8B4(u32 *data, u8 index);
u8 sub_0202B8D8(u32 *data);
BOOL sub_0202B8FC(u32 value);
void sub_0202B908(FashionCase *fashionCase);
void Save_FashionData_Init(SaveFashionData *fashionData);
u32 Save_FashionData_sizeof(void);
u32 sub_0202B994(void);
SaveFashionDataSub *sub_0202B998(enum HeapID heapId);
SaveFashionDataSub *sub_0202B9B8(SaveFashionData *fashionData, int index);
FashionCase *Save_FashionData_GetFashionCase(SaveFashionData *fashionData);
BOOL sub_0202BC10(SaveFashionDataSub *entry);
BOOL sub_0202BEA4(SaveFashionDataSub3FC *entry);
u8 sub_0202BAB0(FashionCase *fashionCase, int index);
void sub_0202BDA8(SaveFashionDataSub *dst, SaveFashionDataSub *src);
void sub_0202BECC(SaveFashionMon *mon, String *string);
u32 sub_02015FCC(void *ptr);
int sub_02015FF8(void *ptr);
void FashionCase_GiveContestBackground(FashionCase *fashionCase, int id);
void sub_0202BC38(SaveFashionDataSub *entry);
void sub_0202BC60(SaveFashionDataSub *entry);
void sub_0202BC88(SaveFashionDataSub *entry, Pokemon *mon, int value);
void sub_0202BCAC(SaveFashionDataSub *entry, FashionSource *source, int index);
void sub_0202BD60(SaveFashionDataSub *entry, int value);
void sub_0202BDC8(SaveFashionDataSub *entry, String *string, u8 value);
BOOL sub_0202BDEC(SaveFashionDataSub *entry, int index);
SaveFashionMon *sub_0202BE14(SaveFashionDataSub *entry);
u8 *sub_0202BE2C(SaveFashionDataSub *entry, int index);
void sub_0202BE60(SaveFashionDataSub *entry, String *string);
u8 sub_0202BE80(SaveFashionDataSub *entry);
u16 sub_0202BE98(SaveFashionDataSub *entry);
s8 sub_0202BEDC(SaveFashionMon *mon);
u8 sub_0202BEE4(SaveFashionMon *mon);
u8 sub_0202BEEC(SaveFashionMon *mon);
void sub_0202BEF4(SaveFashionMon *mon, Pokemon *pokemon);
u8 sub_0202BEFC(u8 *data);
u8 sub_0202BF00(u8 *data);
u8 sub_0202BF04(u8 *data);
s8 sub_0202BF08(s8 *data);

void sub_0202BD60(SaveFashionDataSub *entry_, int value) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    entry->unk_70 = value;
}

void sub_0202BD7C(SaveFashionDataSub *entry_, int value) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    MailMsg_Init(&entry->mailMessage);
    ((void (*)(MailMessage *, int, int))MailMsg_SetFieldI)(&entry->mailMessage, 0, value);
}

void sub_0202BDA8(SaveFashionDataSub *dst_, SaveFashionDataSub *src_) {
    FashionEntry *dst = (FashionEntry *)dst_;
    GF_ASSERT(sub_0202B614(dst->magic));
    memcpy(dst, src_, sizeof(FashionEntry));
}

void sub_0202BDC8(SaveFashionDataSub *entry_, String *string, u8 value) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    sub_0202B718(&entry->mon, string, value);
}

BOOL sub_0202BDEC(SaveFashionDataSub *entry_, int index) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(index < 10);
    GF_ASSERT(sub_0202B614(entry->magic));
    return entry->mask & (1 << index);
}

SaveFashionMon *sub_0202BE14(SaveFashionDataSub *entry_) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    return &entry->mon;
}

u8 *sub_0202BE2C(SaveFashionDataSub *entry_, int index) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(index < 10);
    GF_ASSERT(entry->mask & (1 << index));
    GF_ASSERT(sub_0202B614(entry->magic));
    return entry->items[index];
}

void sub_0202BE60(SaveFashionDataSub *entry_, String *string) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    sub_0202BECC(&entry->mon, string);
}

u8 sub_0202BE80(SaveFashionDataSub *entry_) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    return entry->unk_70;
}

u16 sub_0202BE98(SaveFashionDataSub *entry_) {
    FashionEntry *entry = (FashionEntry *)entry_;
    return MailMsg_GetFieldI(&entry->mailMessage, 0);
}

BOOL sub_0202BEA4(SaveFashionDataSub3FC *entry_) {
    FashionEntryLarge *entry = (FashionEntryLarge *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    return entry->magic == 0x2345;
}

void sub_0202BECC(SaveFashionMon *mon, String *string) {
    CopyU16ArrayToString(string, mon->secondText);
}

s8 sub_0202BEDC(SaveFashionMon *mon) {
    return mon->unk_30;
}

u8 sub_0202BEE4(SaveFashionMon *mon) {
    return mon->unk_31;
}

u8 sub_0202BEEC(SaveFashionMon *mon) {
    return mon->unk_32;
}

void sub_0202BEF4(SaveFashionMon *mon, Pokemon *pokemon) {
    sub_0202B730(mon, pokemon);
}

u8 sub_0202BEFC(u8 *data) {
    return data[0];
}

u8 sub_0202BF00(u8 *data) {
    return data[1];
}

u8 sub_0202BF04(u8 *data) {
    return data[2];
}

s8 sub_0202BF08(s8 *data) {
    return data[3];
}

void MATHi_CRC32InitTableRev(u32 *table, u32 polynomial);
u32 MATH_CalcCRC32(const u32 *table, const void *data, u32 size);
void *SaveArray_Get(SaveData *saveData, int id);
BOOL sub_0202BF10(SaveFashionData *fashionData, SaveFashionDataSub *candidate);
void sub_0202BF80(u8 count, int skip, SaveFashionData *fashionData, SaveFashionDataSub **entries);

BOOL sub_0202BF10(SaveFashionData *fashionData, SaveFashionDataSub *candidate) {
    u32 table[256];
    BOOL result = TRUE;
    u32 crc;
    int i;
    if (sub_0202BC10(candidate) == TRUE) {
        MATHi_CRC32InitTableRev(table, 0xEDB88320);
        crc = MATH_CalcCRC32(table, candidate, sizeof(SaveFashionDataSub));
        for (i = 0; i < 11; i++) {
            SaveFashionDataSub *entry = sub_0202B9B8(fashionData, i);
            u32 other;
            MATHi_CRC32InitTableRev(table, 0xEDB88320);
            other = MATH_CalcCRC32(table, entry, sizeof(SaveFashionDataSub));
            if (other == crc) {
                result = FALSE;
                break;
            }
        }
    } else {
        result = FALSE;
    }
    return result;
}
