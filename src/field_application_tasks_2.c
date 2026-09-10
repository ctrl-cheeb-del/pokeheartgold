#include "field_application_tasks_internal.h"

void sub_02059650(void *p) {
    u8 *data = p;
    if (*(void **)(data + 0x50)) {
        Heap_Free(*(void **)(data + 0x50));
    }
    if (*(void **)(data + 0x4C)) {
        Heap_Free(*(void **)(data + 0x4C));
    }
    if (*(void **)(data + 0x48)) {
        Heap_Free(*(void **)(data + 0x48));
    }
    DestroyMsgData(*(void **)(data + 0x2C));
    MessageFormat_Delete(*(void **)(data + 0x28));
    String_Delete(*(void **)(data + 0xC));
    String_Delete(*(void **)(data + 0x10));
    DestroyListMenuCursorObj(*(void **)(data + 0x78));
    sub_020594C8(p, TRUE);
}

void *sub_0205969C(const void *p) {
    return TaskManager_GetEnvironment(*(TaskManager **)((const u8 *)p + 0x10));
}

void sub_020596A8(void *p, void *marker) {
    u8 *data = p;
    void *party = SaveArray_Party_Get(*(void **)((u8 *)*(void **)(data + 0x24) + 0xC));
    u8 *buffer = *(u8 **)(data + 0x4C);
    u32 size = sub_02070D90();
    int i;
    *(void **)(buffer + size * 3) = marker;
    if (*(void **)(buffer + size * 3) != NULL) {
        for (i = 0; i < 3; i++) {
            void *mon = Party_GetMonByIndex(party, data[0x3D + i] - 1);
            MI_CpuCopy8(mon, buffer, size);
            buffer += size;
        }
    }
}
