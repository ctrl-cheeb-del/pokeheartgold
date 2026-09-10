#include "field_overlay_app_dispatch_internal.h"

void ov01_021F6830(FieldSys *fieldSystem, int a1, int a2);
void ov01_021F6840(FieldSys *fieldSystem);
void ov01_021F6864(FieldSys *fieldSystem);
BOOL ov01_021F6874(FieldSys *fieldSystem);
void ov01_021F6894(FieldSys *fieldSystem);
void ov01_021F68B8(FieldSys *fieldSystem);
BOOL ov01_021F68C0(FieldSys *fieldSystem);
SysTask *ov01_021F68DC(void *a0, void *a1, FieldSys *fieldSystem);
void ov01_021F690C(FieldSys *fieldSystem);
BOOL ov01_021F6930(FieldSys *fieldSystem);
void ov01_021F6968(AppTaskData *data);
void ov01_021F69A4(AppTaskData *data);
void ov01_021F69C0(SysTask *task, void *env);
void ov01_021F6A9C(FieldSys *fieldSystem, int a1, void *a2);
void ov01_021F6ABC(FieldSys *fieldSystem, int a1, int a2, void *a3);
u32 ov01_021F6AEC(FieldSys *fieldSystem);
u8 ov01_021F6B00(FieldSys *fieldSystem);
u8 ov01_021F6B10(FieldSys *fieldSystem);
void **ov01_021F6B20(FieldSys *fieldSystem);
void ov01_021F6B34(FieldSys *fieldSystem, void *a1, void *a2);
void ov01_021F6B50(FieldSys *fieldSystem);
void ov01_021F6B64(FieldSys *fieldSystem, int a1);
void *ov01_021F6B88(void *a0, void *a1, FieldSys *fieldSystem, void *a3);
void ov01_021F6BA0(void *a0, void *a1);
BOOL ov01_021F6BAC(void *a0);
BOOL ov01_021F6BB0(u16 a0);
BOOL ov01_021F6BD0(int a0);
BOOL ov01_021F6C28(FieldTaskCtx *ctx);
BOOL ov01_021F6C4C(FieldTaskCtx *ctx);
BOOL ov01_021F6C7C(FieldTaskCtx *ctx);
BOOL ov01_021F6CA0(FieldTaskCtx *ctx);

static const u16 ov01_02206C08[] = {
    0x0196,
    0x015E,
    0x018C,
    0x0199,
    0x019A,
    0x019B,
    0x019C,
    0x019D,
    0x0193,
    0x0194,
    0x0054,
    0x0055,
    0x0056,
    0x0057,
    0x0106,
    0x017D,
    0x011F,
    0x017B,
    0x018D,
    0x018E,
    0x018F,
    0x0190,
    0x0191,
    0x0192,
    0x0120,
    0x00B7,
    0x0121,
    0x0122,
    0x0123,
    0x0124,
    0x015D,
    0x0178,
    0x00D2,
    0x017C,
    0x00EA,
    0x0106,
    0x00FB,
    0x00FC,
    0x00FD,
    0x00FE,
    0x00FF,
    0x0100,
    0x0101,
};

static const AppEntry ov01_02206C60[] = {
    { ov27_02259F80, ov27_0225A19C, ov27_0225A2C8, (u32)-1                       },
    { ov30_0225D520, ov30_0225D64C, ov30_0225D6FC, FS_OVERLAY_ID(touch_save_app) },
    { ov31_0225D520, ov31_0225D710, ov31_0225D758, FS_OVERLAY_ID(OVY_31)         },
    { ov27_0225C250, ov27_0225C398, ov27_0225C418, (u32)-1                       },
    { ov28_0225D520, ov28_0225D5EC, ov28_0225D624, FS_OVERLAY_ID(OVY_28)         },
    { ov29_0225D520, ov29_0225D5EC, ov29_0225D61C, FS_OVERLAY_ID(OVY_29)         },
    { ov32_0225D520, ov32_0225D5CC, ov32_0225D608, FS_OVERLAY_ID(OVY_32)         },
    { ov33_0225D520, ov33_0225D5A8, ov33_0225D5CC, FS_OVERLAY_ID(OVY_33)         },
    { ov01_021F6B88, ov01_021F6BA0, ov01_021F6BAC, FS_OVERLAY_ID(OVY_34)         },
};

void ov01_021F6830(FieldSys *fieldSystem, int a1, int a2) {
    void *r0 = fieldSystem->unk04->unk14;
    if (r0 != NULL) {
        ov35_02259D80(r0, a1, a2);
    }
}

void ov01_021F6840(FieldSys *fieldSystem) {
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_27), OVY_LOAD_ASYNC);
    fieldSystem->unkD4 = ov30_0225D520(fieldSystem->unk08, &fieldSystem->unkD0, fieldSystem, NULL);
}

void ov01_021F6864(FieldSys *fieldSystem) {
    ov30_0225D64C(fieldSystem->unk08, fieldSystem->unkD4);
}

BOOL ov01_021F6874(FieldSys *fieldSystem) {
    if (ov30_0225D6FC(fieldSystem->unk08)) {
        UnloadOverlayByID(FS_OVERLAY_ID(OVY_27));
        return TRUE;
    }
    return FALSE;
}

void ov01_021F6894(FieldSys *fieldSystem) {
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_27), OVY_LOAD_ASYNC);
    fieldSystem->unkD8 = ov01_021F68DC(fieldSystem->unk08, &fieldSystem->unkD0, fieldSystem);
}

void ov01_021F68B8(FieldSys *fieldSystem) {
    ov01_021F690C(fieldSystem);
}

BOOL ov01_021F68C0(FieldSys *fieldSystem) {
    if (ov01_021F6930(fieldSystem)) {
        UnloadOverlayByID(FS_OVERLAY_ID(OVY_27));
        return TRUE;
    }
    return FALSE;
}

SysTask *ov01_021F68DC(void *a0, void *a1, FieldSys *fieldSystem) {
    SysTask *task;
    AppTaskData *data;

    task = CreateSysTaskAndEnvironment(ov01_021F69C0, 0x10, 0xA, HEAP_ID_FIELD1);
    data = SysTask_GetData(task);
    data->unk00 = fieldSystem->unk1C;
    data->unk01 = 0;
    data->unk04 = NULL;
    data->unk02 = 0;
    data->unk08 = fieldSystem;
    data->unk0C = NULL;
    return task;
}

void ov01_021F690C(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    ov01_02206C60[data->unk00].main(fieldSystem->unk08, data->unk04);
}

BOOL ov01_021F6930(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    if (ov01_02206C60[data->unk00].done(fieldSystem->unk08) == TRUE) {
        ov01_021F69A4(data);
        DestroySysTaskAndEnvironment(fieldSystem->unkD8);
        return TRUE;
    }
    return FALSE;
}

void ov01_021F6968(AppTaskData *data) {
    if (ov01_02206C60[data->unk00].ovlId != (u32)-1) {
        HandleLoadOverlay(ov01_02206C60[data->unk00].ovlId, OVY_LOAD_ASYNC);
    }
    data->unk04 = ov01_02206C60[data->unk00].init(data->unk08->unk08, &data->unk08->unkD0, data->unk08, data->unk0C);
}

void ov01_021F69A4(AppTaskData *data) {
    if (ov01_02206C60[data->unk00].ovlId != (u32)-1) {
        UnloadOverlayByID(ov01_02206C60[data->unk00].ovlId);
    }
}

void ov01_021F69C0(SysTask *task, void *env) {
    AppTaskData *data = env;
    switch (data->unk01) {
    case 0:
        ov01_021F6968(data);
        data->unk01 = 1;
        break;
    case 2:
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, 0, 2, 1, HEAP_ID_FIELD1);
        data->unk01 = 3;
        break;
    case 3:
        if (IsPaletteFadeFinished()) {
            data->unk01 = 4;
        }
        break;
    case 4:
        ov01_02206C60[data->unk00].main(data->unk08->unk08, data->unk04);
        data->unk01 = 5;
        break;
    case 5:
        if (ov01_02206C60[data->unk00].done(data->unk08->unk08) == TRUE) {
            ov01_021F69A4(data);
            data->unk00 = data->unk02;
            data->unk01 = 6;
        }
        break;
    case 6:
        ov01_021F6968(data);
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0, 2, 1, HEAP_ID_FIELD1);
        data->unk01 = 7;
        break;
    case 7:
        if (IsPaletteFadeFinished()) {
            data->unk01 = 1;
        }
        break;
    }
}

void ov01_021F6A9C(FieldSys *fieldSystem, int a1, void *a2) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    if (data->unk01 == 1) {
        data->unk01 = 2;
        data->unk02 = a1;
        data->unk0C = a2;
    }
}

void ov01_021F6ABC(FieldSys *fieldSystem, int a1, int a2, void *a3) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    AppSubData *sub = SysTask_GetData(data->unk04);
    if (a1 != ov01_021F6B00(fieldSystem)) {
        GF_AssertFail();
    }
    sub->unk00 = a2;
    sub->unk04 = a3;
}

u32 ov01_021F6AEC(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    AppSubData *sub = SysTask_GetData(data->unk04);
    return sub->unk00;
}

u8 ov01_021F6B00(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    return data->unk00;
}

u8 ov01_021F6B10(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    return data->unk01;
}

void **ov01_021F6B20(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    AppSubData *sub = SysTask_GetData(data->unk04);
    return &sub->unk0C;
}

void ov01_021F6B34(FieldSys *fieldSystem, void *a1, void *a2) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    ov27_0225C41C(data->unk04, a1, a2);
}

void ov01_021F6B50(FieldSys *fieldSystem) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    ov27_0225A2CC(data->unk04);
}

void ov01_021F6B64(FieldSys *fieldSystem, int a1) {
    AppTaskData *data = SysTask_GetData(fieldSystem->unkD8);
    if (a1 <= 0 || a1 >= 3) {
        GF_AssertFail();
    }
    ov27_0225A2EC(data->unk04, a1);
}

void *ov01_021F6B88(void *a0, void *a1, FieldSys *fieldSystem, void *a3) {
    fieldSystem->unkDC = ov34_0225D7A8(fieldSystem);
    return fieldSystem->unkDC;
}

void ov01_021F6BA0(void *a0, void *a1) {
    ov34_0225D87C(a1);
}

BOOL ov01_021F6BAC(void *a0) {
    return TRUE;
}

BOOL ov01_021F6BB0(u16 a0) {
    u32 i;
    const u16 *p = ov01_02206C08;
    for (i = 0; i < 43; i++, p++) {
        if (a0 == *p) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov01_021F6BD0(int a0) {
    if (a0 >= 7000 && a0 <= 8799) {
        return TRUE;
    }
    if (a0 >= 2800 && a0 <= 2999) {
        return TRUE;
    }
    if (a0 >= 10000 && a0 <= 10099) {
        return TRUE;
    }
    if (a0 >= 10100 && a0 <= 10149) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov01_021F6C28(FieldTaskCtx *ctx) {
    u8 r4 = ov01_021F6B00(ctx->fieldSystem);
    u8 r0 = ov01_021F6B10(ctx->fieldSystem);
    if (r4 == 6 && r0 == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov01_021F6C4C(FieldTaskCtx *ctx) {
    u8 r4 = ov01_021F6B00(ctx->fieldSystem);
    u8 r0 = ov01_021F6B10(ctx->fieldSystem);
    if (r4 == 3 && r0 == TRUE) {
        ov01_021F6ABC(ctx->fieldSystem, 3, 3, ctx->unk90);
        return TRUE;
    }
    return FALSE;
}

BOOL ov01_021F6C7C(FieldTaskCtx *ctx) {
    u8 r4 = ov01_021F6B00(ctx->fieldSystem);
    u32 r0 = ov01_021F6AEC(ctx->fieldSystem);
    if (r4 == 3 && r0 == 6) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov01_021F6CA0(FieldTaskCtx *ctx) {
    switch (ctx->state) {
    case 0:
        ov01_021F6A9C(ctx->fieldSystem, 3, NULL);
        ctx->state++;
        break;
    case 1:
        if (ov01_021F6C4C(ctx) == TRUE) {
            ctx->state++;
        }
        break;
    case 2:
        if (ov01_021F6C7C(ctx) == TRUE) {
            ctx->state = 0;
            return FALSE;
        }
        break;
    }
    return TRUE;
}
