#include "global.h"

#include "fashion_case.h"
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

BOOL sub_0202B614(u32 value);
void sub_0202B6E8(SaveFashionMon *dst, Pokemon *mon, int value);
void sub_0202B784(u32 *data, int value, u8 index);
u8 sub_0202B7C8(u32 *data, u8 index);
void sub_0202B808(u32 *data, u8 value, u8 index);
u8 sub_0202B848(u32 *data, u8 index);
void sub_0202B870(u32 *data, u32 value, u8 index);
u8 sub_0202B8B4(u32 *data, u8 index);
u8 sub_0202B8D8(u32 *data);
BOOL sub_0202B8FC(u32 value);
u32 sub_0202BA70(FashionCase *fashionCase, int id);
u8 sub_0202BAB0(FashionCase *fashionCase, int index);
void FashionCase_GiveContestBackground(FashionCase *fashionCase, int id);
BOOL sub_0202BC10(SaveFashionDataSub *entry);
void sub_0202BC38(SaveFashionDataSub *entry);
void sub_0202BC60(SaveFashionDataSub *entry);
void sub_0202BC88(SaveFashionDataSub *entry, Pokemon *mon, int value);

u32 sub_0202BA70(FashionCase *fashionCase, int id) {
    GF_ASSERT((u32)id < 100);
    if (sub_0202B8FC(id)) {
        return sub_0202B7C8(fashionCase->unk_00, (u8)id);
    }
    GF_ASSERT((u32)id >= 61);
    id = (u8)(id - 61);
    return sub_0202B848(&fashionCase->unk_00[8], (u8)id);
}

u8 sub_0202BAB0(FashionCase *fashionCase, int index) {
    GF_ASSERT((u32)index < 18);
    return sub_0202B8B4(&fashionCase->unk_28[0], (u8)index);
}

u32 FashionCase_CountAccessories(FashionCase *fashionCase) {
    int i = 0;
    u32 count = i;
    for (i = 0; i < 100; i++) {
        count += sub_0202BA70(fashionCase, i);
    }
    return count;
}

u32 FashionCase_CountWallpapers(FashionCase *fashionCase) {
    int i = 0;
    u32 count = i;
    for (i = 0; i < 18; i++) {
        if (sub_0202BAB0(fashionCase, i) != 18) {
            count++;
        }
    }
    return count;
}

void FashionCase_GiveFashionItem(FashionCase *fashionCase, int id, int quantity) {
    GF_ASSERT((u32)id < 100);
    if (sub_0202B8FC(id)) {
        u8 count = sub_0202B7C8(fashionCase->unk_00, (u8)id);
        count += quantity;
        if (count > 9) {
            count = 9;
        }
        sub_0202B784(fashionCase->unk_00, count, (u8)id);
    } else {
        u8 count = sub_0202B848(&fashionCase->unk_00[8], (u8)id);
        count += quantity;
        if (count > 1) {
            count = 1;
        }
        GF_ASSERT((u32)id >= 61);
        id = (u8)(id - 61);
        sub_0202B808(&fashionCase->unk_00[8], count, (u8)id);
    }
}

void sub_0202BB7C(FashionCase *fashionCase, int id, int quantity) {
    GF_ASSERT((u32)id < 100);
    if (sub_0202B8FC(id)) {
        u8 count = sub_0202B7C8(fashionCase->unk_00, (u8)id);
        if ((u32)count > (u32)quantity) {
            count -= quantity;
        } else {
            count = 0;
        }
        sub_0202B784(fashionCase->unk_00, count, (u8)id);
    } else {
        GF_ASSERT((u32)id >= 61);
        id = (u8)(id - 61);
        sub_0202B808(&fashionCase->unk_00[8], 0, (u8)id);
    }
}

void FashionCase_GiveContestBackground(FashionCase *fashionCase, int id) {
    GF_ASSERT((u32)id < 18);
    if (sub_0202B8B4(&fashionCase->unk_28[0], (u8)id) == 18) {
        u8 count = sub_0202B8D8(&fashionCase->unk_28[0]);
        sub_0202B870(&fashionCase->unk_28[0], count, (u8)id);
    }
}

BOOL sub_0202BC10(SaveFashionDataSub *entry_) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    return entry->magic == 0x2345;
}

void sub_0202BC38(SaveFashionDataSub *entry_) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    entry->magic = 0x2345;
    entry->language = gGameLanguage;
}

void sub_0202BC60(SaveFashionDataSub *entry_) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    memset(entry, 0, sizeof(FashionEntry));
    entry->magic = 0x1234;
}

void sub_0202BC88(SaveFashionDataSub *entry_, Pokemon *mon, int value) {
    FashionEntry *entry = (FashionEntry *)entry_;
    GF_ASSERT(sub_0202B614(entry->magic));
    sub_0202B6E8(&entry->mon, mon, value);
}
