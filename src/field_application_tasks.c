#include "field_application_tasks_internal.h"

BOOL sub_02058C80(void *p, FieldSystem *fieldSystem) {
    u8 *data = p;
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return FALSE;
    }
    MI_CpuCopy8(*(u8 **)(data + 4) + 0x30, data + 0x3D, 6);
    if ((*(u8 **)(data + 4))[0x26] == 6) {
        goto value_six;
    }
    if ((*(u8 **)(data + 4))[0x26] != 7) {
        goto value_other;
    }
    *(u32 *)(data + 0x38) = 0;
    goto value_done;
value_six:
    *(u32 *)(data + 0x38) = 1;
    goto value_done;
value_other:
    *(u32 *)(data + 0x38) = 2;
value_done:
    data[0x3C] = (*(u8 **)(data + 4))[0x26];
    Heap_Free(*(void **)(data + 4));
    *(void **)(data + 4) = NULL;
    return TRUE;
}

BOOL sub_02058CD8(void *p, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return FALSE;
    }
    *((u8 *)p + 0x3C) = *((u8 *)*(void **)p + 0x14);
    Heap_Free(*(void **)p);
    *(void **)p = NULL;
    return TRUE;
}

BOOL sub_02058D04(const void *p) {
    if (sub_020505C8(*(void **)((const u8 *)p + 0x24)) != 0) {
        FieldMap_FadeScreen(1);
        sub_02056E60();
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02058D24(void) {
    int i;
    int count = sub_02037454();
    i = 0;
    for (i = 0; i < count; i++) {
        if (sub_02037B5C(i) == 0x5E) {
            return TRUE;
        }
    }
    return FALSE;
}
