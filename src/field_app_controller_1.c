#include "field_app_controller_internal.h"

FS_EXTERN_OVERLAY(OVY_44);
FS_EXTERN_OVERLAY(OVY_90);
FS_EXTERN_OVERLAY(OVY_91);
FS_EXTERN_OVERLAY(OVY_92);
FS_EXTERN_OVERLAY(OVY_93);

extern const u8 _0210125C[];
extern const u32 _02101260[], _02101270[], _02101280[], _02101290[], _021012A0[];

BOOL sub_02078834(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    LocalTaskData *data = TaskManager_GetEnvironment(taskManager);
    switch (data->state) {
    case 0:
        *(void **)data->appArgs = *(void **)((u8 *)fieldSystem + 0xc);
    case 1:
        data->state++;
        if (*(u32 *)(data->appArgs + 4) == 1 && sub_0203A05C(*(void **)((u8 *)fieldSystem + 0xc))) {
            data->state = 10;
            *data->result = 0;
        }
        break;
    case 2:
        CallApplicationAsTask(taskManager, _02101290, data->appArgs);
        data->state++;
        break;
    case 3:
        if (sub_0203A05C(*(void **)((u8 *)fieldSystem + 0xc))) {
            SetFlag970(Save_VarsFlags_Get(*(void **)((u8 *)fieldSystem + 0xc)));
        }
        switch (*(u32 *)(data->appArgs + 4)) {
        case 3:
            data->percent = 0;
            data->mode = 0;
            data->state = 4;
            break;
        case 1:
            data->percent = 50;
            data->mode = 0;
            data->state = 4;
            break;
        case 2:
            data->percent = 100;
            data->mode = 0;
            data->state = 4;
            break;
        case 6:
            data->percent = 0;
            data->mode = 1;
            data->state = 4;
            break;
        case 4:
            data->percent = 50;
            data->mode = 1;
            data->state = 4;
            break;
        case 5:
            data->percent = 100;
            data->mode = 1;
            data->state = 4;
            break;
        case 7:
            data->state = 6;
            break;
        case 10:
            *data->result = 1;
            data->state = 11;
            break;
        case 8:
            data->state = 9;
            break;
        case 12:
            data->state = 12;
            break;
        case 13:
            data->state = 14;
            break;
        case 14:
            data->state = 18;
            break;
        case 15:
            data->state = 22;
            break;
        case 9:
            data->state = 8;
            break;
        }
        break;
    case 4:
        CallTask_02050960(taskManager, *(u32 *)(data->appArgs + 8), data->percent, data->mode);
        data->state++;
        break;
    case 5:
        data->state = 2;
        break;
    case 6:
        CallTask_WirelessTrade(taskManager);
        data->state++;
        break;
    case 7:
        data->state = 2;
        break;
    case 8:
        Heap_Create(HEAP_ID_3, (enum HeapID)0x35, 0x40100);
        LoadOVY13();
        ov13_0221BA00(0x35);
        OS_ResetSystem(0);
        break;
    case 9:
    case 10:
    case 11:
        Heap_Free(data->appArgs);
        Heap_Free(data);
        data->state++;
        return TRUE;
    case 12:
        sub_020378E4(0);
        data->launchedArgs = sub_020968B0(fieldSystem, 0);
        data->state++;
        break;
    case 13:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            Heap_Free(data->launchedArgs);
            data->state = 2;
        }
        break;
    case 14:
        sub_02078B9C(data, fieldSystem, 11, 1);
        data->state++;
        break;
    case 15:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            data->state = sub_02078BD8(data);
        }
        break;
    case 16:
        data->launchedArgs = sub_02078C18(fieldSystem, 11, data->selection);
        data->state++;
        break;
    case 17:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            data->state = 2;
            sub_02078C60(data->launchedArgs);
        }
        break;
    case 18:
        sub_02078B9C(data, fieldSystem, 11, 2);
        data->state++;
        break;
    case 19:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            data->state = sub_02078BD8(data);
        }
        break;
    case 20:
        data->launchedArgs = sub_02078C74(fieldSystem, 11, data->selection);
        data->state++;
        break;
    case 21:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            data->state = 2;
            sub_02078CB4(data->launchedArgs);
        }
        break;
    case 22:
        sub_02078B9C(data, fieldSystem, 11, 3);
        data->state++;
        break;
    case 23:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            data->state = sub_02078BD8(data);
        }
        break;
    case 24:
        data->launchedArgs = sub_02078CC8(fieldSystem, 11, data->selection);
        data->state++;
        break;
    case 25:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            data->state = 2;
            sub_02078D10(data->launchedArgs);
        }
        break;
    default:
        return TRUE;
    }
    return FALSE;
}

LocalTaskData *sub_02078B2C(void) {
    LocalTaskData *data = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(LocalTaskData));
    MI_CpuFill8(data, 0, sizeof(LocalTaskData));
    data->appArgs = Heap_AllocAtEnd(HEAP_ID_FIELD2, 12);
    MI_CpuFill8(data->appArgs, 0, 12);
    return data;
}

void sub_02078B58(void *taskManager) {
    LocalTaskData *data = sub_02078B2C();
    *(u32 *)(data->appArgs + 4) = 2;
    TaskManager_Call(taskManager, sub_02078834, data);
}

void sub_02078B78(void *taskManager, u16 *result) {
    LocalTaskData *data = sub_02078B2C();
    *(u32 *)(data->appArgs + 4) = 1;
    data->result = result;
    TaskManager_Call(taskManager, sub_02078834, data);
}

void sub_02078B9C(LocalTaskData *data, void *fieldSystem, int heapId, int kind) {
    u8 *args = Heap_Alloc((enum HeapID)heapId, 12);
    args[0] = kind;
    args[1] = 2;
    args[2] = _0210125C[kind];
    args[3] = 0;
    args[4] = 0;
    *(void **)(args + 8) = *(void **)((u8 *)fieldSystem + 0xc);
    data->launchedArgs = args;
    FieldSystem_LaunchApplication(fieldSystem, _02101280, args);
}

u32 sub_02078BD8(LocalTaskData *data) {
    enum LocalKind {
        LOCAL_KIND_1 = 1,
        LOCAL_KIND_2,
        LOCAL_KIND_3
    };
    u8 *args = data->launchedArgs;
    if (args[3] == 1) {
        switch ((enum LocalKind)args[0]) {
        case 1:
            data->state = 0x10;
            break;
        case 2:
            data->state = 0x14;
            break;
        default:
        case 3:
            data->state = 0x18;
            break;
        }
    } else {
        data->state = 1;
    }
    data->selection = args[4];
    Heap_Free(data->launchedArgs);
    return data->state;
}

void *sub_02078C18(void *fieldSystem, int heapId, u32 selection) {
    u8 *args = Heap_Alloc((enum HeapID)heapId, 0x3c);
    memset(args, 0, 0x3c);
    args[0x38] = selection;
    args[0x39] = 0;
    *(void **)(args + 0x34) = *(void **)((u8 *)fieldSystem + 0xc);
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), 2);
    FieldSystem_LaunchApplication(fieldSystem, _02101260, args);
    return args;
}

void sub_02078C60(void *args) {
    Heap_Free(args);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
}

void *sub_02078C74(void *fieldSystem, int heapId, u32 selection) {
    u8 *args = Heap_Alloc((enum HeapID)heapId, 0x40);
    memset(args, 0, 0x40);
    *(u32 *)(args + 0x3c) = selection;
    *(u32 *)(args + 0x38) = 0;
    *(void **)(args + 0x34) = *(void **)((u8 *)fieldSystem + 0xc);
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), 2);
    FieldSystem_LaunchApplication(fieldSystem, _02101270, args);
    return args;
}

void sub_02078CB4(void *args) {
    Heap_Free(args);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
}

void *sub_02078CC8(void *fieldSystem, int heapId, u32 selection) {
    u8 *args = Heap_Alloc((enum HeapID)heapId, 0x3c);
    MI_CpuFill8(args, 0, 0x3c);
    args[0x38] = selection;
    args[0x39] = 0;
    *(void **)(args + 0x34) = *(void **)((u8 *)fieldSystem + 0xc);
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), 2);
    FieldSystem_LaunchApplication(fieldSystem, _021012A0, args);
    return args;
}

void sub_02078D10(void *args) {
    Heap_Free(args);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
}

BOOL sub_02078D24(int index) {
    struct LocalEntry {
        u8 pad[0x23];
        u8 value;
    };
    struct LocalData {
        u8 pad[0x1b];
        u8 value;
        struct LocalEntry entries[1];
    };
    struct LocalData *data = sub_020398C8();
    u8 a = data->value;
    u8 b = data->entries[index].value;
    if (a == 0xc && b == 5) {
        return TRUE;
    }
    if (a == 0xd && b == 6) {
        return TRUE;
    }
    if (a == 0xe && b == 7) {
        return TRUE;
    }
    if (a == 9 && b == 2) {
        return TRUE;
    }
    if (a == 0xa && b == 3) {
        return TRUE;
    }
    if (a == 0xb && b == 4) {
        return TRUE;
    }
    if (a == 0xf && b == 8) {
        return TRUE;
    }
    if (a == 0x13 && b == 0x12) {
        return TRUE;
    }
    if (a == 0x15 && b == 0x14) {
        return TRUE;
    }
    if (a == 0x17 && b == 0x16) {
        return TRUE;
    }
    if (a == 0x19 && b == 0x18) {
        return TRUE;
    }
    if (a == 0x1b && b == 0x1a) {
        return TRUE;
    }
    if (a == 0x10 && b == 1) {
        return TRUE;
    }
    return FALSE;
}
