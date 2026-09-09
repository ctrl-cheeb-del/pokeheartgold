#include "global.h"

#include "billboard_internal.h"
#include "heap.h"
#include "unk_02023694.h"

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
    object->owner = 0;
    object->unk_2C = 0;
    object->modelSet = 0;
    object->model = 0;
    object->texture = 0;
    object->resourceHeader = 0;
    memset(&object->resourceData, 0, sizeof(object->resourceData));
    object->texKey = 0;
    object->tex4x4Key = 0;
    object->paletteKey = 0;
    object->unk_B0 = 0;
    object->position.x = 0;
    object->position.y = 0;
    object->position.z = 0;
    object->scale.x = FX32_ONE;
    object->scale.y = FX32_ONE;
    object->scale.z = FX32_ONE;
    object->rotation = 0;
    object->unk_B6 = 0;
    object->type = 0;
    object->next = NULL;
    object->prev = 0;
    object->visible = 0;
    object->callback = 0;
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
