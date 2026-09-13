#include "r40_overlay_80_0222BDF4_residual_25_private.h"

BOOL ov80_0222D968(void *raw) {
    Ov80R40EffectWork *work = raw;

    switch (work->state) {
    case 0:
        ov80_0223AC24(1, 0x10, -0x10, &work->ready, 2);
        work->state++;
        break;
    case 1:
        if (work->ready != 0) {
            u8 template[0x20];
            int i;
            int value;
            int offset;

            MI_CpuFill8(template, 0, sizeof(template));
            work->finished = 0;
            work->data = Heap_Alloc(0x65, sizeof(Ov80R40EffectData));
            work->data->mode = 1;
            work->data->allocation = ov80_0223B544(0x04000020, template, 0x65);
            i = 0;
            value = 0;
            offset = 0;
            for (; i < 96; i++) {
                int delta;

                *(s16 *)((u8 *)work->data + offset) = value;
                *(s16 *)((u8 *)work->data + offset + 2) = *(s16 *)((u8 *)work->data + offset) + 2;
                delta = 0x31 - i;
                *(s16 *)((u8 *)work->data + offset + 4) = delta % 8;
                *(s16 *)((u8 *)work->data + offset + 6) = delta / 4;
                *(s16 *)((u8 *)work->data + offset + 8) = 0;
                *(s16 *)((u8 *)work->data + offset + 10) = 0;
                *(void **)((u8 *)work->data + offset + 12) = ov80_0222D63C(0, 0);
                value += 2;
                offset += 0x10;
            }
            StartBrightnessTransition(0x28, -0x10, 0, 0x1e, 1);
            SysTask_CreateOnMainQueue(ov80_0222D644, work, 0x1000);
            work->state++;
        }
        break;
    case 2:
        if (IsBrightnessTransitionActive(1)) {
            work->finished = 1;
            ToggleBgLayer(3, 0);
            BgSetPosTextAndCommit(PTR(work->frontierSystem, 0), 3, 0, 0);
            BgSetPosTextAndCommit(PTR(work->frontierSystem, 0), 3, 3, 0);
            work->state++;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

BOOL ov80_0222DAAC(void *raw) {
    Ov80R40EffectWork *work = raw;

    switch (work->state) {
    case 0:
        ov80_0223AC24(1, 0x10, -0x10, &work->ready, 2);
        work->state++;
        break;
    case 1:
        if (work->ready != 0) {
            u8 template[0x20];
            int i;
            int value;
            int offset;

            MI_CpuFill8(template, 0, sizeof(template));
            work->finished = 0;
            work->data = Heap_Alloc(0x65, sizeof(Ov80R40EffectData));
            work->data->mode = 2;
            work->data->allocation = ov80_0223B544(0x04000020, template, 0x65);
            i = 0;
            value = 0;
            offset = 0;
            for (; i < 96; i++) {
                int delta;
                int x;

                *(s16 *)((u8 *)work->data + offset) = value;
                *(s16 *)((u8 *)work->data + offset + 2) = *(s16 *)((u8 *)work->data + offset) + 2;
                delta = 0x30 - i;
                x = delta / 8 + 1;
                *(s16 *)((u8 *)work->data + offset + 4) = x;
                if (i % 2 != 0) {
                    *(s16 *)((u8 *)work->data + offset + 4) *= -1;
                }
                if (i < 0x30) {
                    *(s16 *)((u8 *)work->data + offset + 6) = i;
                } else {
                    *(s16 *)((u8 *)work->data + offset + 6) = 0x60 - i;
                }
                *(s16 *)((u8 *)work->data + offset + 8) = 0;
                *(s16 *)((u8 *)work->data + offset + 10) = 0;
                *(void **)((u8 *)work->data + offset + 12) = ov80_0222D63C(0, 0);
                value += 2;
                offset += 0x10;
            }
            StartBrightnessTransition(0x28, -0x10, 0, 0x1c, 1);
            SysTask_CreateOnMainQueue(ov80_0222D644, work, 0x1000);
            work->state++;
        }
        break;
    case 2:
        if (IsBrightnessTransitionActive(1)) {
            work->finished = 1;
            ToggleBgLayer(3, 0);
            BgSetPosTextAndCommit(PTR(work->frontierSystem, 0), 3, 0, 0);
            BgSetPosTextAndCommit(PTR(work->frontierSystem, 0), 3, 3, 0);
            work->state++;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

BOOL ov80_0222DC14(void *raw) {
    u8 *work = raw;

    switch (U32_AT(work, 4)) {
    case 0:
        ov80_0223B424(work + 0x18, 0x65);
        U32_AT(work, 4)
        ++;
        break;
    case 1:
        ov80_0223B440(work + 0x18, 0, 0xbf, 0x2aa, 0x12000, 0x190, 0x0400001c, 0, 4);
        U32_AT(work, 4)
        ++;
        break;
    }
    return TRUE;
}

BOOL FrtCmd_063(void *context) {
    u8 *work = context;
    u8 *data;

    Frontier_GetLaunchArgs(PTR(PTR(context, 0), 0));
    *(u16 *)(work + 0x78) = FrontierScript_ReadVar(context);
    Sound_SetSceneAndPlayBGM(5, 0x45d, 1);
    data = Heap_Alloc(0xb, 0x30);
    PTR(data, 0x14) = Frontier_GetData(PTR(PTR(context, 0), 0));
    U32_AT(data, 4) = 0;
    U32_AT(data, 8) = *(u16 *)(work + 0x78);
    PTR(data, 0) = FrontierSystem_GetFrontierMap(PTR(context, 0));
    Frontier_SetData(PTR(PTR(context, 0), 0), data);
    FrontierScriptContext_Pause(context, ov80_0222DCF0);
    PaletteData_FillPaletteInBuffer(PTR(PTR(data, 0), 4), 0, 2, 0, 0, 1);
    return TRUE;
}

BOOL ov80_0222DCF0(void *context) {
    void *data;
    BOOL result;

    data = Frontier_GetData(PTR(PTR(context, 0), 0));
    result = ov80_0223B9EC[U32_AT(data, 8)](data);
    if (result == FALSE) {
        sub_0200FBF4(0, 0);
        sub_0200FBF4(1, 0);
        Frontier_SetData(PTR(PTR(context, 0), 0), PTR(data, 0x14));
        Heap_Free(data);
    }
    return result == FALSE;
}

BOOL FrtCmd_064(void *context) {
    u16 *result = FrontierScript_ReadVarPtr(context);
    void *launchArgs = Frontier_GetLaunchArgs(PTR(PTR(context, 0), 0));
    void *profile = Save_PlayerData_GetProfile(PTR(launchArgs, 8));

    if (PlayerProfile_GetTrainerGender(profile) == 0) {
        *result = 0;
    } else {
        *result = 0x61;
    }
    return FALSE;
}
