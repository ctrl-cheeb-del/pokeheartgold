#include "field_friendship_exchange_internal.h"

BOOL ov01_021F6CFC(FieldFriendCtx *ctx);
BOOL ov01_021F6D78(FieldFriendCtx *ctx);
BOOL ov01_021F6E44(FieldFriendCtx *ctx);
BOOL ov01_021F6E68(FieldFriendCtx *ctx);
BOOL ov01_021F6ED8(FieldFriendCtx *ctx);
BOOL ov01_021F6EFC(FieldFriendCtx *ctx);
BOOL ov01_021F6F44(FieldFriendCtx *ctx);
BOOL ov01_021F6F68(FieldFriendCtx *ctx);
BOOL ov01_021F6F94(FieldFriendCtx *ctx);
BOOL ov01_021F6FDC(FieldFriendCtx *ctx);
BOOL ov01_021F7060(FieldFriendCtx *ctx);
BOOL ov01_021F7084(FieldFriendCtx *ctx);
BOOL ov01_021F7100(TaskManager *taskman);
void ov01_021F71C4(FieldFriendCtx *ctx, u32 msgId);
void ov01_021F722C(FieldFriendCtx *ctx);
void ov01_021F7268(FieldFriendCtx *ctx);
void ov01_021F729C(FieldSystem *fieldSystem);

BOOL ov01_021F6CFC(FieldFriendCtx *ctx) {
    sub_0202C23C(sub_0202C6F4(ctx->saveData), 0);
    if (!sub_0203A1C4(ctx->saveData, ctx->unk48, HEAP_ID_FIELD1)) {
        return TRUE;
    }
    ctx->unk88 = 0;
    LoadUserFrameGfx2(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x1E2, 0xA, (u8)Options_GetFrame(Save_PlayerData_GetOptionsAddr(ctx->saveData)), HEAP_ID_FIELD1);
    LoadUserFrameGfx1(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 0xB, 0, HEAP_ID_FIELD1);
    ctx->state = 1;
    return FALSE;
}

BOOL ov01_021F6D78(FieldFriendCtx *ctx) {
    UnkStruct_021D2230 *roster;
    int i;

    ctx->unk88 = (u32)-1;
    i = 0;
    if (sub_02037454() > 0) {
        do {
            if (ctx->unk48[i] == 2) {
                ctx->unk88 = i;
                ctx->unk48[i] = 0;
                break;
            }
            i++;
        } while (i < sub_02037454());
    }
    if (ctx->unk88 == (u32)-1) {
        return TRUE;
    }
    if (Bag_HasItem(Save_Bag_Get(ctx->saveData), 0x1B5, 1, HEAP_ID_FIELD1) == 1) {
        BufferPlayersName(ctx->msgFmt, 0, (void *)sub_02034818(ctx->unk88));
        ov01_021F71C4(ctx, 0x3E);
        ctx->state = 2;
        return FALSE;
    }
    roster = sub_0202C6F4(ctx->saveData);
    for (i = 0; i < 0x20; i++) {
        if (!sub_0202C2DC(roster, i)) {
            sub_0203A280(ctx->saveData, ctx->unk88, i, 4, 0);
            break;
        }
    }
    ctx->state = 1;
    return FALSE;
}

BOOL ov01_021F6E44(FieldFriendCtx *ctx) {
    if (!TextPrinterCheckActive((u8)ctx->printerId)) {
        ctx->unk98 = 0;
        ctx->state = 3;
    }
    return FALSE;
}

BOOL ov01_021F6E68(FieldFriendCtx *ctx) {
    int i;
    UnkStruct_021D2230 *roster;

    if (!ov01_021F6CA0(ctx)) {
        if (ctx->unk90 == 0) {
            roster = sub_0202C6F4(ctx->saveData);
            for (i = 0; i < 0x20; i++) {
                if (!sub_0202C2DC(roster, i)) {
                    sub_0203A280(ctx->saveData, ctx->unk88, i, 4, 0);
                    break;
                }
            }
            if (i == 0x20) {
                ov01_021F71C4(ctx, 0x3F);
                ctx->state = 4;
                return FALSE;
            }
        }
        ctx->state = 1;
        return FALSE;
    }
    return FALSE;
}

BOOL ov01_021F6ED8(FieldFriendCtx *ctx) {
    if (!TextPrinterCheckActive((u8)ctx->printerId)) {
        ctx->unk98 = 0;
        ctx->state = 5;
    }
    return FALSE;
}

BOOL ov01_021F6EFC(FieldFriendCtx *ctx) {
    if (!ov01_021F6CA0(ctx)) {
        if (ctx->unk90 == 0) {
            ctx->unk9a = 0;
            ctx->state = 8;
        } else {
            BufferPlayersName(ctx->msgFmt, 0, (void *)sub_02034818(ctx->unk88));
            ov01_021F71C4(ctx, 0x40);
            ctx->state = 6;
        }
    }
    return FALSE;
}

BOOL ov01_021F6F44(FieldFriendCtx *ctx) {
    if (!TextPrinterCheckActive((u8)ctx->printerId)) {
        ctx->unk98 = 0;
        ctx->state = 7;
    }
    return FALSE;
}

BOOL ov01_021F6F68(FieldFriendCtx *ctx) {
    if (!ov01_021F6CA0(ctx)) {
        if (ctx->unk90 == 0) {
            ctx->state = 0xC;
        } else {
            ov01_021F71C4(ctx, 0x3F);
            ctx->state = 4;
        }
    }
    return FALSE;
}

BOOL ov01_021F6F94(FieldFriendCtx *ctx) {
    switch (ctx->unk9a) {
    case 0:
        ov01_021F6A9C(ctx->fieldSystem, 6, &ctx->unk94);
        ctx->unk9a++;
        break;
    case 1:
        if (ov01_021F6C28(ctx) == 1) {
            ctx->unk9a = 0;
            ctx->state = 9;
        }
        break;
    }
    return FALSE;
}

BOOL ov01_021F6FDC(FieldFriendCtx *ctx) {
    UnkStruct_021D2230 *roster;
    void *profile;

    switch (ctx->unk94) {
    case -2:
        BufferPlayersName(ctx->msgFmt, 0, (void *)sub_02034818(ctx->unk88));
        ov01_021F71C4(ctx, 0x40);
        ctx->state = 6;
        break;
    case -1:
        break;
    default:
        ctx->unk8c = ctx->unk94;
        roster = sub_0202C6F4(ctx->saveData);
        profile = PlayerProfile_New(HEAP_ID_FIELD1);
        Save_Profile_PlayerName_Set(profile, sub_0202C254(roster, ctx->unk8c));
        BufferPlayersName(ctx->msgFmt, 0, profile);
        Heap_Free(profile);
        ov01_021F71C4(ctx, 0x41);
        ctx->state = 0xA;
        break;
    }
    return FALSE;
}

BOOL ov01_021F7060(FieldFriendCtx *ctx) {
    if (!TextPrinterCheckActive((u8)ctx->printerId)) {
        ctx->unk98 = 0;
        ctx->state = 0xB;
    }
    return FALSE;
}

BOOL ov01_021F7084(FieldFriendCtx *ctx) {
    UnkStruct_021D2230 *roster = sub_0202C6F4(ctx->saveData);

    if (!ov01_021F6CA0(ctx)) {
        if (ctx->unk90 == 0) {
            sub_020311AC(Save_Frontier_GetStatic(ctx->saveData), ctx->unk8c);
            sub_0202C338(roster, ctx->unk8c);
            sub_0203A280(ctx->saveData, ctx->unk88, 0x1F, 4, 0);
            ctx->state = 1;
        } else {
            BufferPlayersName(ctx->msgFmt, 0, (void *)sub_02034818(ctx->unk88));
            ov01_021F71C4(ctx, 0x40);
            ctx->state = 6;
        }
    }
    return FALSE;
}

BOOL ov01_021F7100(TaskManager *taskman) {
    FieldFriendCtx *ctx = TaskManager_GetEnvironment(taskman);
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);

#pragma unused(fieldSystem)
    switch (ctx->state) {
    case 0:
        if (ov01_021F6CFC(ctx)) {
            ctx->state = 0xC;
        }
        break;
    case 1:
        if (ov01_021F6D78(ctx)) {
            ctx->state = 0xC;
        }
        break;
    case 2:
        ov01_021F6E44(ctx);
        break;
    case 3:
        ov01_021F6E68(ctx);
        break;
    case 4:
        ov01_021F6ED8(ctx);
        break;
    case 5:
        ov01_021F6EFC(ctx);
        break;
    case 6:
        ov01_021F6F44(ctx);
        break;
    case 7:
        ov01_021F6F68(ctx);
        break;
    case 8:
        ov01_021F6F94(ctx);
        break;
    case 9:
        ov01_021F6FDC(ctx);
        break;
    case 10:
        ov01_021F7060(ctx);
        break;
    case 11:
        ov01_021F7084(ctx);
        break;
    case 12:
        ov01_021F7268(ctx);
        Heap_Free(ctx);
        sub_0203E30C();
        return TRUE;
    }
    return FALSE;
}

void ov01_021F71C4(FieldFriendCtx *ctx, u32 msgId) {
    if (WindowIsInUse((Window *)ctx->window)) {
        RemoveWindow((Window *)ctx->window);
    }
    ReadMsgDataIntoString(ctx->msgData, msgId, ctx->msg);
    StringExpandPlaceholders(ctx->msgFmt, ctx->expanded, ctx->msg);
    DialogBox_AddWindowToLayer3(ctx->fieldSystem->bgConfig, ctx->window, 3);
    DialogBox_LoadFrame(ctx->window, Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData));
    ctx->printerId = DialogBox_PrintMessage(ctx->window, ctx->expanded, Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData), 1);
}

void ov01_021F722C(FieldFriendCtx *ctx) {
    MI_CpuFill8(ctx, 0, 0x9C);
    ctx->msgFmt = MessageFormat_New(HEAP_ID_FIELD1);
    ctx->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, (NarcId)0x1B, 0x30B, HEAP_ID_FIELD1);
    ctx->expanded = String_New(0x6E, HEAP_ID_FIELD1);
    ctx->msg = String_New(0x6E, HEAP_ID_FIELD1);
}

void ov01_021F7268(FieldFriendCtx *ctx) {
    DestroyMsgData(ctx->msgData);
    MessageFormat_Delete(ctx->msgFmt);
    String_Delete(ctx->expanded);
    String_Delete(ctx->msg);
    if (WindowIsInUse((Window *)ctx->window)) {
        RemoveWindow((Window *)ctx->window);
    }
}

void ov01_021F729C(FieldSystem *fieldSystem) {
    TaskManager *taskman = fieldSystem->taskman;
    FieldFriendCtx *ctx = Heap_AllocAtEnd(HEAP_ID_FIELD2, 0x9C);

    ov01_021F722C(ctx);
    ctx->fieldSystem = fieldSystem;
    ctx->saveData = fieldSystem->saveData;
    ctx->state = 0;
    if (taskman == NULL) {
        FieldSystem_CreateTask(fieldSystem, ov01_021F7100, ctx);
    } else {
        TaskManager_Call(taskman, ov01_021F7100, ctx);
    }
}
