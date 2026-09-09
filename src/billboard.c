#include "global.h"

#include "heap.h"
#include "unk_02023694.h"

typedef struct BillboardObject {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    fx32 scaleX;
    fx32 scaleY;
    fx32 scaleZ;
    u32 unk_18;
    u8 padding_1C[4];
    u32 unk_20;
    u8 unk_24;
    u8 padding_25[3];
    u32 unk_28;
    u32 unk_2C;
    u8 padding_30[0x54];
    u32 unk_84;
    u32 unk_88;
    u32 unk_8C;
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
    u8 unk_A0[0x10];
    u32 unk_B0;
    u8 unk_B4;
    u8 padding_B5;
    u16 unk_B6;
    u8 padding_B8[4];
    struct BillboardObject *next;
    u32 unk_C0;
} BillboardObject;

typedef struct Billboard {
    u8 initialized;
    u8 draw;
    u8 padding_02;
    u8 state;
    void *objects;
    int objectCount;
    BillboardObject root;
    u32 *unk_D0;
    u32 unk_D4;
    void *allocator;
    void *unk_DC;
} Billboard;

typedef struct BillboardListManager {
    Billboard *list;
    int count;
} BillboardListManager;

extern BillboardListManager _021D2208;

void sub_02023694(Billboard *billboard);
void sub_020236BC(BillboardObject *object);
BOOL sub_02023874(Billboard *billboard);
void sub_02023950(Billboard *billboard);

void sub_02023694(Billboard *billboard) {
    billboard->initialized = 0;
    billboard->draw = 0;
    billboard->objects = NULL;
    billboard->objectCount = 0;
    billboard->unk_D0 = NULL;
    billboard->unk_D4 = 0;
    billboard->allocator = NULL;
    billboard->unk_DC = NULL;
    billboard->state = 0;
}

void sub_020236BC(BillboardObject *object) {
    object->unk_28 = 0;
    object->unk_2C = 0;
    object->unk_84 = 0;
    object->unk_88 = 0;
    object->unk_8C = 0;
    object->unk_90 = 0;
    memset(object->unk_A0, 0, sizeof(object->unk_A0));
    object->unk_94 = 0;
    object->unk_98 = 0;
    object->unk_9C = 0;
    object->unk_B0 = 0;
    object->unk_00 = 0;
    object->unk_04 = 0;
    object->unk_08 = 0;
    object->scaleX = FX32_ONE;
    object->scaleY = FX32_ONE;
    object->scaleZ = FX32_ONE;
    object->unk_18 = 0;
    object->unk_B6 = 0;
    object->unk_B4 = 0;
    object->next = NULL;
    object->unk_C0 = 0;
    object->unk_24 = 0;
    object->unk_20 = 0;
}

void BillboardLists_Create(int count, enum HeapID heapID) {
    int i;

    GF_ASSERT(_021D2208.list == NULL);
    _021D2208.list = Heap_Alloc(heapID, count * sizeof(Billboard));
    _021D2208.count = count;
    for (i = 0; i < count; i++) {
        sub_02023694(&_021D2208.list[i]);
    }
}

void BillboardLists_Delete(void) {
    int i;

    for (i = 0; i < _021D2208.count; i++) {
        sub_02023874(&_021D2208.list[i]);
    }
    Heap_Free(_021D2208.list);
    _021D2208.list = NULL;
    _021D2208.count = 0;
}

void BillboardLists_Draw(void) {
    int i;

    for (i = 0; i < _021D2208.count; i++) {
        if (_021D2208.list[i].draw == 1) {
            sub_02023950(&_021D2208.list[i]);
        }
        if (_021D2208.list[i].state == 1) {
            _021D2208.list[i].state = 2;
        }
    }
}
