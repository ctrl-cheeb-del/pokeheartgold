#include "to47_overlay49_manager_r4_private.h"

Ov49ManagerR4 *ov49_02258AB4(u32 count, u32 value, void *arg, enum HeapID heapId, u32 extra) {
    Ov49ManagerR4 *manager = Heap_Alloc(heapId, sizeof(Ov49ManagerR4));
    u32 bytes;

    memset(manager, 0, sizeof(Ov49ManagerR4));
    manager->object0 = ov42_02228010(count, heapId);
    manager->object4 = ov45_02230498(count, value, heapId, extra);
    manager->iterator = ov42_02229A40(0x20, heapId);
    bytes = sizeof(Ov49EntryR4) * count;
    manager->count = count;
    manager->entries = Heap_Alloc(heapId, bytes);
    memset(manager->entries, 0, bytes);
    manager->arg = arg;
    manager->value = value;
    ov49_022591D8(manager);
    return manager;
}

void ov49_02258B20(Ov49ManagerR4 *manager) {
    Heap_Free(manager->entries);
    ov42_02229A78(manager->iterator);
    ov45_02230638(manager->object4);
    ov42_02228050(manager->object0);
    Heap_Free(manager);
}

void ov49_02258B44(Ov49ManagerR4 *manager) {
    ov42_0222807C(manager->object0);
    ov49_02259A54(manager->sub18, manager->object4);
}

void ov49_02258B5C(Ov49ManagerR4 *manager) {
    int i;
    int offset;
    void *value;
    UnkStruct_ov42_02228CDC b;
    UnkStruct_ov42_02228EB0 a;

    i = 0;
    if (i < manager->count) {
        offset = 0;
        do {
            if (ov49_022593FC((Ov49EntryR4 *)((u8 *)manager->entries + offset)) == 0) {
                Ov49EntryR4 *current = (Ov49EntryR4 *)((u8 *)manager->entries + offset);
                current->callback(current, manager);
            }
            i++;
            offset += sizeof(Ov49EntryR4);
        } while (i < manager->count);
    }
    value = ov49_02258AB0(manager->arg);
    if (ov42_02229AC8(manager->iterator, &b) == 1) {
        do {
            if (ov42_02228C80(value, manager->object0, &b, &a) == 1) {
                ov42_02228068(manager->object0, &a);
            }
        } while (ov42_02229AC8(manager->iterator, &b) == 1);
    }
    ov45_02230680(manager->object4);
}
