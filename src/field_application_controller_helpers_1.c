#include "field_application_controller_helpers_internal.h"

u8 sub_02059478(void *data, void *message) {
    u8 *work = data;
    void *window = work + 0x14;
    void *options;
    if (!WindowIsInUse(window)) {
        DialogBox_AddWindowToLayer3(*(void **)(*(u8 **)(work + 0x24) + 8), window, 3);
        options = Save_PlayerData_GetOptionsAddr(*(void **)(*(u8 **)(work + 0x24) + 0xc));
        DialogBox_LoadFrame(window, options);
    } else {
        DialogBox_Clear(window);
    }
    options = Save_PlayerData_GetOptionsAddr(*(void **)(*(u8 **)(work + 0x24) + 0xc));
    return DialogBox_PrintMessage(window, message, options, 1);
}

void sub_020594C8(void *data, BOOL clearFrame) {
    u8 *work = data;
    if (WindowIsInUse(work + 0x14)) {
        if (clearFrame) {
            ClearFrameAndWindow2(work + 0x14, 0);
            ClearWindowTilemapAndCopyToVram(work + 0x14);
        }
        RemoveWindow(work + 0x14);
        InitWindow(work + 0x14);
    }
    if (WindowIsInUse(work + 0x54)) {
        RemoveWindow(work + 0x54);
        InitWindow(work + 0x54);
    }
    if (WindowIsInUse(work + 0x64)) {
        RemoveWindow(work + 0x64);
        InitWindow(work + 0x64);
    }
}

void sub_02059538(void *fieldSystem, void *callback) {
    u8 *work;
    u32 size;
    if (*(void **)((u8 *)fieldSystem + 0x10) != NULL) {
        return;
    }
    work = Heap_AllocAtEnd(11, 0x8c);
    MI_CpuFill8(work, 0, 0x8c);
    work[0x43] = 5;
    *(void **)(work + 0x24) = fieldSystem;
    *(void **)(work + 8) = callback;
    *(void **)(work + 0x28) = MessageFormat_New(11);
    *(void **)(work + 0x2c) = NewMsgDataFromNarc(0, 0x1b, 0xe, 11);
    *(void **)(work + 0xc) = String_New(200, 11);
    *(void **)(work + 0x10) = String_New(200, 11);
    InitWindow(work + 0x14);
    InitWindow(work + 0x54);
    InitWindow(work + 0x64);
    *(void **)(work + 0x78) = ListMenuCursorNew(11);
    work[0x88] = sub_0203993C();
    *(u32 *)(work + 0x4c) = 0;
    *(u32 *)(work + 0x48) = 0;
    *(u32 *)(work + 0x50) = 0;
    work[0x89] = 0;
    *(u16 *)(work + 0x86) = sub_0203769C();
    *(void **)(work + 0x74) = sub_02034818(1 ^ *(u16 *)(work + 0x86));
    switch (work[0x88]) {
    case 3:
        size = sub_02059B08();
        *(void **)(work + 0x4c) = Heap_AllocAtEnd(11, size);
        *(void **)(work + 0x48) = Heap_AllocAtEnd(11, size);
        *(void **)(work + 0x50) = SaveArray_Party_Alloc(11);
        Party_InitWithMaxSize(*(void **)(work + 0x50), 3);
        work[0x44] = 5;
        *(u32 *)(work + 0x34) = 0x17;
        break;
    case 4:
        *(u32 *)(work + 0x34) = 9;
        break;
    default:
        if (*(void **)(*(u8 **)(work + 0x24) + 0xa4) != NULL) {
            *(u32 *)(work + 0x34) = 9;
        } else {
            *(u32 *)(work + 0x34) = 0;
        }
        break;
    }
    FieldSystem_CreateTask(fieldSystem, sub_02058D4C, work);
}
