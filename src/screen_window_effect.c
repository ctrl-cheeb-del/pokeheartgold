#include "screen_window_effect_internal.h"

void sub_02012DD8(Manager *manager, const void *config) {
    manager->work = Heap_Alloc((enum HeapID)manager->heapId, 0x4C);
    sub_02012E6C(manager->work, config, manager->unk04, manager->unk08, manager->unk10, manager->unk18, manager->unk1C, manager->heapId);
    manager->state++;
}

BOOL sub_02012E10(Manager *manager) {
    BOOL done = FALSE;
    void *work = manager->work;
    switch (manager->state) {
    case 1:
        if (sub_02012F54(work) == TRUE) {
            u32 *words = work;
            sub_02010F34(words[13], words[17], manager->unk10);
            manager->state++;
        }
        break;
    case 2:
        sub_02010EC8(work);
        Heap_Free(manager->work);
        manager->work = NULL;
        manager->state++;
        done = TRUE;
        break;
    case 3:
        done = TRUE;
        break;
    default:
        GF_AssertFail();
        break;
    }
    return done;
}
