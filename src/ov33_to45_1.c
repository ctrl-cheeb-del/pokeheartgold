#include "ov33_to45_private.h"

const TouchscreenHitbox ov33_0225DA2C[] = {
    { 0x50, 0x7F, 0x00, 0xFF },
    { 0xFF, 0x00, 0x00, 0x00 },
};

const WindowTemplate ov33_0225DA24[] = {
    { 4, 1, 12, 30, 2, 4, 1 },
};

const TouchscreenHitbox ov33_0225DA34[] = {
    { 0x28, 0x57, 0x00, 0xFF },
    { 0x60, 0x8F, 0x00, 0xFF },
    { 0xFF, 0x00, 0x00, 0x00 },
};

const WindowTemplate ov33_0225DA40[] = {
    { 4, 1, 7,  30, 2, 4, 1    },
    { 4, 1, 14, 30, 2, 4, 0x3D },
};

const Ov33Entry ov33_0225DA50[] = {
    { ov33_0225DA24, ov33_0225DA2C, 0, 10, 0 },
    { ov33_0225DA40, ov33_0225DA34, 0, 5,  1 },
};

void ov33_0225D5A8(void *a0, SysTask *task) {
    Ov33Env *env = SysTask_GetData(task);
    ov33_0225D820(env);
    ov33_0225D7B8(env->bgConfig);
    DestroySysTaskAndEnvironment(task);
    Heap_Destroy(HEAP_ID_8);
}

BOOL ov33_0225D5CC(void) {
    return TRUE;
}

void ov33_0225D5D0(SysTask *task, void *data) {
    Ov33Env *env = data;
    const Ov33Entry *entry = &ov33_0225DA50[env->count - 1];

    if (env->state < 2) {
        if (env->args->unk5 == 1) {
            env->state = 2;
        } else if (env->args->unk5 == 2) {
            env->state = 4;
        }
    }

    switch (env->state) {
    case 0:
        env->touchIdx = TouchscreenHitbox_FindRectAtTouchNew(entry->hitboxes);
        if (env->touchIdx != -1) {
            ov33_0225D9D4(env, 1);
            env->args->selection = env->touchIdx;
            env->state = 1;
        }
        break;
    case 1: {
        int touch = TouchscreenHitbox_FindRectAtTouchHeld(entry->hitboxes);
        env->args->selection = 0xFFFF;
        if (touch != env->touchIdx) {
            ov33_0225D9D4(env, 0);
            env->state = 0;
        }
        break;
    }
    case 2:
        BgClearTilemapBufferAndCommit(env->bgConfig, GF_BG_LYR_SUB_0);
        BgClearTilemapBufferAndCommit(env->bgConfig, GF_BG_LYR_SUB_1);
        ScheduleBgTilemapBufferTransfer(env->bgConfig, GF_BG_LYR_SUB_0);
        ScheduleBgTilemapBufferTransfer(env->bgConfig, GF_BG_LYR_SUB_1);
        env->state = 3;
        break;
    case 3:
        break;
    case 4:
        BgClearTilemapBufferAndCommit(env->bgConfig, GF_BG_LYR_SUB_0);
        BgClearTilemapBufferAndCommit(env->bgConfig, GF_BG_LYR_SUB_1);
        ScheduleBgTilemapBufferTransfer(env->bgConfig, GF_BG_LYR_SUB_0);
        ScheduleBgTilemapBufferTransfer(env->bgConfig, GF_BG_LYR_SUB_1);
        env->state = 5;
        break;
    case 5:
        if (gSystem.touchHeld) {
            gSystem.simulatedInputs = 1;
        }
        break;
    }
}

void ov33_0225D6F8(void) {
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xFFCFFFEF) | 0x10;
}

void ov33_0225D720(BgConfig *bgConfig) {
    GXS_SetGraphicsMode(GX_BGMODE_0);

    {
        BgTemplate template = {
            0, 0, 0x800, 0, 1, 0, 15, 0, 0, 0, 0, 0, 0
        };
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &template, 0);
        BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_8);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    }

    {
        BgTemplate template = {
            0, 0, 0x800, 0, 1, 0, 14, 1, 0, 1, 0, 0, 0
        };
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &template, 0);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    }

    {
        BgTemplate template = {
            0, 0, 0x800, 0, 1, 0, 13, 1, 0, 2, 0, 0, 0
        };
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &template, 0);
    }
}

static void ov33_0225D7B8(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
}

void ov33_0225D7D4(Ov33Env *env) {
    u32 i;
    const Ov33Entry *entry = &ov33_0225DA50[env->count - 1];

    for (i = 0; i < env->count; i++) {
        AddWindow(env->bgConfig, &env->windows[i], &entry->windows[i]);
        FillWindowPixelBuffer(&env->windows[i], 0);
    }
}

static void ov33_0225D820(Ov33Env *env) {
    u32 i;

    for (i = 0; i < env->count; i++) {
        RemoveWindow(&env->windows[i]);
    }
}

void ov33_0225D84C(Ov33Env *env) {
    NNSG2dScreenData *scrnData;
    void *raw;
    NARC *narc = NARC_New(NARC_a_2_3_7, HEAP_ID_8);

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0xA0, HEAP_ID_8);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, env->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_8);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 9, env->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, HEAP_ID_8);
    raw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 10, FALSE, &scrnData, HEAP_ID_8);
    MIi_CpuCopy16((u16 *)((u8 *)scrnData->rawData + 0x180), env->tilemap, 0x180);
    Heap_Free(raw);
    NARC_Delete(narc);
}
