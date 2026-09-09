#include "fashion_case.h"

#include "global.h"

#include "heap.h"

typedef struct FashionEntry {
    u32 magic;
    u8 data[0x70];
} FashionEntry;

typedef struct FashionEntryLarge {
    u32 magic;
    u8 data[0x94];
} FashionEntryLarge;

BOOL sub_0202B614(u32 value);
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
BOOL sub_0202BC10(SaveFashionDataSub *entry);
BOOL sub_0202BEA4(SaveFashionDataSub3FC *entry);
u8 sub_0202BAB0(FashionCase *fashionCase, int index);

u8 sub_0202B848(u32 *data, u8 index) {
    u8 word = index / 32;
    u8 shift = index % 32;
    return (data[word] >> shift) & 1;
}

void sub_0202B870(u32 *data, u32 value, u8 index) {
    u8 shift;
    u8 word;
    GF_ASSERT(value <= 18);
    shift = index % 4;
    shift *= 8;
    word = index / 4;
    data[word] &= ~(0xFF << shift);
    data[word] |= value << shift;
}

u8 sub_0202B8B4(u32 *data, u8 index) {
    u8 word = index / 4;
    u8 shift = index % 4;
    shift *= 8;
    return data[word] >> shift;
}

u8 sub_0202B8D8(u32 *data) {
    int i = 0;
    int count = i;
    for (i = 0; i < 18; i++) {
        if (sub_0202B8B4(data, (u8)i) != 18) {
            count++;
        }
    }
    return count;
}

BOOL sub_0202B8FC(u32 value) {
    if (value < 61) {
        return TRUE;
    }
    return FALSE;
}

void sub_0202B908(FashionCase *fashionCase) {
    int i;
    memset(fashionCase, 0, 0x40);
    for (i = 0; i < 18; i++) {
        sub_0202B870(&fashionCase->unk_28[0], 18, (u8)i);
    }
}

void Save_FashionData_Init(SaveFashionData *fashionData) {
    int i;
    for (i = 0; i < 11; i++) {
        memset(&fashionData->unk_000[i], 0, sizeof(SaveFashionDataSub));
        ((FashionEntry *)&fashionData->unk_000[i])->magic = 0x1234;
    }
    {
        int j = 0;
        u8 *clear = (u8 *)fashionData + 0x4FC;
        u8 *set = (u8 *)fashionData;
        u32 magic = 0x1234;
        for (; j < 5; j++) {
            memset(clear, 0, 0x98);
            *(u32 *)(set + 0x4FC) = magic;
            clear += 0x98;
            set += 0x98;
        }
    }
    sub_0202B908(&fashionData->fashionCase);
}

u32 Save_FashionData_sizeof(void) {
    return 0x834;
}

u32 sub_0202B994(void) {
    return sizeof(SaveFashionDataSub);
}

SaveFashionDataSub *sub_0202B998(enum HeapID heapId) {
    SaveFashionDataSub *entry = Heap_Alloc(heapId, sizeof(SaveFashionDataSub));
    memset(entry, 0, sizeof(SaveFashionDataSub));
    ((FashionEntry *)entry)->magic = 0x1234;
    return entry;
}

SaveFashionDataSub *sub_0202B9B8(SaveFashionData *fashionData, int index) {
    GF_ASSERT(index < 11);
    GF_ASSERT(sub_0202B614(((FashionEntry *)&fashionData->unk_000[index])->magic));
    return &fashionData->unk_000[index];
}

FashionCase *Save_FashionData_GetFashionCase(SaveFashionData *fashionData) {
    return &fashionData->fashionCase;
}

BOOL sub_0202B9EC(SaveFashionData *fashionData, int index) {
    GF_ASSERT(index < 11);
    return sub_0202BC10(&fashionData->unk_000[index]);
}

BOOL sub_0202BA08(SaveFashionData *fashionData, int index) {
    GF_ASSERT(index < 5);
    return sub_0202BEA4(&fashionData->unk_3FC[index]);
}

int sub_0202BA2C(FashionCase *fashionCase, int id, int quantity) {
    BOOL result = TRUE;
    u32 current = sub_0202BA70(fashionCase, id);
    if (sub_0202B8FC(id)) {
        if (current + quantity > 9) {
            result = FALSE;
        }
    } else if (current + quantity > 1) {
        result = FALSE;
    }
    return result;
}

int sub_0202BA5C(FashionCase *fashionCase, int index) {
    if (sub_0202BAB0(fashionCase, index) != 18) {
        return TRUE;
    }
    return FALSE;
}
