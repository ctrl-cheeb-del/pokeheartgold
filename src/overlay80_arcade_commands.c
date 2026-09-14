#include "overlay80_arcade_commands_private.h"

BOOL FrtCmd_178(FrontierScriptContextPrivate *ctx) {
    u8 sel = *ctx->scriptPtr++;
    u8 arg = *ctx->scriptPtr++;
    ctx->scriptPtr++;
    u16 *out = FrontierScript_ReadVarPtr(ctx);
    u8 *data = (u8 *)Frontier_GetData(*ctx->frontier);
    FrontierLaunchArgsPrivate *launchArgs = Frontier_GetLaunchArgs(*ctx->frontier);

    switch (sel) {
    case 0:
        sub_02096910((ArcadeDataPrivate *)data);
        break;
    case 1:
        *out = *(u16 *)(data + 0x86);
        break;
    case 2:
        if (arg == 1) {
            *out = 0;
            if (*(u16 *)(data + 0x76) == *(u16 *)(data + 0x86) || *(u16 *)(data + 0x76) == *(u16 *)(data + 0x88)) {
                *out = *out + 1;
            }
            if (*(u16 *)(data + 0x78) == *(u16 *)(data + 0x86) || *(u16 *)(data + 0x78) == *(u16 *)(data + 0x88)) {
                *out = *out + 2;
            }
        } else if (arg == 5) {
            if (*(u16 *)(data + 0x76) == *(u16 *)(data + 0x86)) {
                *out = 0;
            } else {
                *out = 1;
            }
        } else if (arg == 4 || arg == 6) {
            *out = 0;
            if (*(u16 *)(data + 0x76) == *(u16 *)(data + 0x86) || *(u16 *)(data + 0x76) == *(u16 *)(data + 0x88)) {
                *out = *out + 1;
            }
            if (*(u16 *)(data + 0x78) == *(u16 *)(data + 0x86) || *(u16 *)(data + 0x78) == *(u16 *)(data + 0x88)) {
                *out = *out + 2;
            }
        }
        break;
    case 3:
        *out = FrontierSave_GetStat(Save_Frontier_GetStatic(launchArgs->saveData), 0x6A, sub_0205C268(0x6A));
        break;
    case 4: {
        void *frontierSave = Save_Frontier_GetStatic(launchArgs->saveData);
        u32 stat = sub_0205C11C(3);
        *out = FrontierSave_GetStat(frontierSave, stat, sub_0205C268(sub_0205C11C(3)));
        break;
    }
    case 5:
        *out = *(u16 *)(data + arg * 2 + 0x76);
        break;
    case 6:
        sub_0204F878(launchArgs->saveData, sub_02030C5C(launchArgs->saveData), 3);
        break;
    case 7:
        data[0xA0] = arg;
        break;
    case 8:
        *out = *(u16 *)(data + 0x74);
        break;
    case 9:
        *out = data[0xA0];
        break;
    case 10:
        *out = data[0x71];
        break;
    case 11: {
        u32 idx;
        u16 stat;
        *out = 1;
        idx = ov80_022385D8(data[0xA0]);
        stat = FrontierSave_GetStat(Save_Frontier_GetStatic(*(void **)data), idx, sub_0205C268(idx));
        if (stat != *(u16 *)(data + 0x72)) {
            sub_02031108(Save_Frontier_GetStatic(*(void **)data), idx, sub_0205C268(idx), 0);
            idx = ov80_02238610(data[0xA0]);
            sub_02031108(Save_Frontier_GetStatic(*(void **)data), idx, sub_0205C268(idx), 0);
            *out = 0;
        }
        break;
    }
    case 12: {
        u32 idx = ov80_02238610(data[0xA0]);
        *out = FrontierSave_GetStat(Save_Frontier_GetStatic(*(void **)data), idx, sub_0205C268(idx));
        if (*out == 0) {
            idx = ov80_022385D8(data[0xA0]);
            sub_02031108(Save_Frontier_GetStatic(*(void **)data), idx, sub_0205C268(idx), 0);
            if (data[0xA0] == 1) {
                sub_0202D57C(Save_FrontierData_Get(*(void **)data), 6, 2);
            }
            if (data[0xA0] == 4) {
                sub_02031108(Save_Frontier_GetStatic(*(void **)data), 0x88, sub_0205C268(0x88), 0);
                sub_02031108(Save_Frontier_GetStatic(*(void **)data), 0x89, sub_0205C268(0x89), 0);
            }
            if (data[0xA0] == 2) {
                sub_02031108(Save_Frontier_GetStatic(*(void **)data), sub_0205C048(0, 3), sub_0205C268(sub_0205C048(0, 3)), 0);
            }
            if (data[0xA0] == 3) {
                sub_02031108(Save_Frontier_GetStatic(*(void **)data), sub_0205C048(1, 3), sub_0205C268(sub_0205C048(1, 3)), 0);
            }
        } else {
            sub_02031108(Save_Frontier_GetStatic(*(void **)data), idx, sub_0205C268(idx), 0);
        }
        break;
    }
    case 13: {
        s32 i;
        for (i = 0; i < 2; i++) {
            data[0xA1 + i] = 0;
        }
        data[0x9F] = 0;
        break;
    }
    }
    return FALSE;
}

BOOL FrtCmd_179(FrontierScriptContextPrivate *ctx) {
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(*ctx->frontier);
    ArcadeDataPrivate *oldData = Frontier_GetData(*ctx->frontier);
    ArcadeScriptBackup backup = *(ArcadeScriptBackup *)oldData;
    ArcadeDataPrivate *data;
    s32 i;
    u8 selection;

    ov80_02235FEC(oldData);
    data = FrontierFieldSystem_New(args->saveData, 0, 6);
    Frontier_SetData(*ctx->frontier, data);
    if (data->facility == 6) {
        ov80_0222A840(args->saveData);
    }
    for (i = 0; i < data->count; i++) {
        data->order[i] = backup.fields.order[i];
        data->valuesA[i] = backup.fields.valuesA[i];
        data->valuesB[i] = backup.fields.valuesB[i];
    }
    data->resultA = backup.fields.resultA;
    data->resultB = backup.fields.resultB;
    selection = backup.fields.selection;
    data->selection = selection;
    data->flags = (data->flags & ~0xE0) | (((u8)(selection + 5) & 7) << 5);
    if (sub_0203769C() == 0) {
        FrontierFieldSystem_SetRandomFrontierTrainers(data, args->saveData);
    }
    HealParty(SaveArray_Party_Get(args->saveData));
    sub_02096910(data);
    data->state = 0;
    return FALSE;
}
