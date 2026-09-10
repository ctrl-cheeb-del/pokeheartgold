#include "field_player_effect_internal.h"

Manager *sub_0205AC88(void *fieldSystem) {
    Manager *manager = Heap_Alloc((enum HeapID)0x1F, sizeof(Manager));
    MIi_CpuClearFast(0, (u32 *)manager, sizeof(Manager));
    manager->fieldSystem = fieldSystem;
    manager->enabled = 1;
    manager->task = SysTask_CreateOnMainQueue(sub_0205AD60, manager, 11);
    manager->remote = sub_0205A1F0(fieldSystem);
    manager->palPad = SaveArray_Get(((RemoteState *)manager->remote)->saveData, 8);
    manager->avatar = ((RemoteState *)manager->remote)->avatar;
    Heap_CreateAtEnd((enum HeapID)11, (enum HeapID)0x57, 0x2710);
    manager->messages = sub_0205B3B8(0x57);
    sub_0205AD24(manager);
    return manager;
}

void sub_0205AD0C(Manager *manager) {
    int i;
    for (i = 0; i < 51; i++) {
        if (manager->slots[i].state != 0) {
            manager->slots[i].unk0 = 3;
        }
    }
}

void sub_0205AD24(Manager *manager) {
    int i;
    for (i = 0; i < 51; i++) {
        manager->slots[i].unk0 = 0;
        manager->slots[i].state = 0;
        manager->slots[i].effect = 0;
        manager->slots[i].trigger = 0;
    }
}

void sub_0205AD3C(Manager *manager) {
    SysTask_Destroy(manager->task);
    sub_0205B3CC(manager->messages);
    Heap_Destroy((enum HeapID)0x57);
    Heap_Free(manager);
}

void sub_0205AD60(SysTask *task, void *data) {
    Manager *manager = data;
    void *fieldSystem = manager->fieldSystem;
    (void)task;

    if (!FieldSystem_TaskIsRunning((FieldSystem *)manager->remote)) {
        manager->avatar = ((RemoteState *)manager->remote)->avatar;
        sub_0205AEA8(manager, fieldSystem, ((RemoteState *)manager->remote)->objectManager, manager->palPad);
        sub_0205AF78(manager, ((RemoteState *)manager->remote)->objectManager);
    }
}
