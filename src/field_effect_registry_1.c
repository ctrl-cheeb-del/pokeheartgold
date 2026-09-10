#include "field_effect_registry_internal.h"

Ov01HeapManager *ov01_021FC4C4(u32 parentHeapId, u32 heapId, u32 heapSize, u32 capacity) {
    Ov01HeapManager *manager;
    u32 entriesSize = capacity * sizeof(Ov01HeapEntry);
    u32 totalSize = heapSize + entriesSize + sizeof(Ov01HeapManager);

    if (Heap_Create(parentHeapId, heapId, totalSize) != TRUE) {
        GF_AssertFail();
    }
    heapSize = totalSize - heapSize;
    manager = Heap_Alloc(heapId, heapSize);
    if (manager == NULL) {
        GF_AssertFail();
    }
    memset(manager, 0, heapSize);
    manager->parentHeapId = parentHeapId;
    manager->heapId = heapId;
    manager->capacity = capacity;
    manager->heapSize = totalSize;
    manager->entriesSize = entriesSize;
    manager->entries = (Ov01HeapEntry *)(manager + 1);
    return manager;
}

void ov01_021FC520(Ov01HeapManager *manager) {
    u32 count = manager->capacity;
    Ov01HeapEntry *entry = manager->entries;

    while (count != 0) {
        if (entry->data != NULL) {
            ov01_021FC588(manager, entry->id);
        }
        count--;
        entry++;
    }
    {
        u32 heapId = manager->heapId;
        Heap_Free(manager);
        Heap_Destroy(heapId);
    }
}

void *ov01_021FC554(Ov01HeapManager *manager, u32 id, u32 size, BOOL atEnd) {
    Ov01HeapEntry *entry = ov01_021FC644(manager);
    void *data;

    if (entry == NULL) {
        GF_AssertFail();
    }
    data = ov01_021FC5FC(manager, size, atEnd);
    ov01_021FC65C(entry, id, data);
    return data;
}

void ov01_021FC588(Ov01HeapManager *manager, u32 id) {
    Ov01HeapEntry *entry = ov01_021FC624(manager, id);
    if (entry == NULL) {
        GF_AssertFail();
    }
    ov01_021FC61C(entry->data);
    ov01_021FC664(entry);
}

void *ov01_021FC5A4(Ov01HeapManager *manager, u32 id) {
    Ov01HeapEntry *entry = ov01_021FC624(manager, id);
    if (entry == NULL) {
        GF_AssertFail();
    }
    return entry->data;
}

BOOL ov01_021FC5B8(Ov01HeapManager *manager, u32 id) {
    if (ov01_021FC624(manager, id) != NULL) {
        return TRUE;
    }
    return FALSE;
}

void *ov01_021FC5CC(Ov01HeapManager *manager, u32 id, void *narc, u32 member, BOOL atEnd) {
    u32 size = NARC_GetMemberSize(narc, member);
    void *data = ov01_021FC554(manager, id, size, atEnd);
    NARC_ReadWholeMember(narc, member, data);
    return data;
}

void *ov01_021FC5FC(Ov01HeapManager *manager, u32 size, BOOL atEnd) {
    void *data;
    if (atEnd == FALSE) {
        data = Heap_Alloc(manager->heapId, size);
    } else {
        data = Heap_AllocAtEnd(manager->heapId, size);
    }
    if (data == NULL) {
        GF_AssertFail();
    }
    return data;
}

void ov01_021FC61C(void *ptr) {
    Heap_Free(ptr);
}

Ov01HeapEntry *ov01_021FC624(Ov01HeapManager *manager, u32 id) {
    u32 count = manager->capacity;
    Ov01HeapEntry *entry = manager->entries;

    while (count != 0) {
        if (entry->data != NULL && entry->id == id) {
            return entry;
        }
        entry++;
        count--;
    }
    return NULL;
}

Ov01HeapEntry *ov01_021FC644(Ov01HeapManager *manager) {
    u32 count = manager->capacity;
    Ov01HeapEntry *entry = manager->entries;

    while (count != 0) {
        if (entry->data == NULL) {
            return entry;
        }
        entry++;
        count--;
    }
    return NULL;
}

void ov01_021FC65C(Ov01HeapEntry *entry, u32 id, void *data) {
    entry->data = data;
    entry->id = id;
}

void ov01_021FC664(Ov01HeapEntry *entry) {
    entry->data = NULL;
    entry->id = 0;
}
