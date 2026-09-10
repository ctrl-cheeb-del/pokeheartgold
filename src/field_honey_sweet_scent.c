#include "field_honey_sweet_scent_internal.h"

void ov01_021FC05C(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data);
void ov01_021FC0A8(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data);
void ov01_021FC0DC(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data);
void ov01_021FC0E0(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data);
void ov01_021FC10C(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data);
Field3dObjectTask *ov01_021FC110(FieldSystem *fieldSystem);
void ov01_021FC124(Field3dObjectTask *task);
int ov01_021FC12C(Field3dObjectTask *task);
Field3dObjectTask *ov01_021FC138(FieldSystem *fieldSystem);
void ov01_021FC14C(BgConfig *bgConfig);
void ov01_021FC1A4(HoneySweetScentAnim *anim, int start, int end, int frames);
BOOL ov01_021FC1B4(HoneySweetScentAnim *anim);
void ov01_021FC1E0(FieldSystem *fieldSystem);
void ov01_021FC1EC(FieldSystem *fieldSystem);
void ov01_021FC1FC(FieldSystem *fieldSystem);
void ov01_021FC260(FieldSystem *fieldSystem);
int ov01_021FC2C4(FieldSystem *fieldSystem);
BOOL ov01_021FC2C8(FieldSystem *fieldSystem);
void ov01_021FC2F0(HoneySweetScentEnv *env);

const u32 ov01_02208BC0[] = { 1, 5, 9 };

void ov01_021FC05C(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data) {
    HoneySweetScentAnim *anim = data;
    ov01_021FC14C(fieldSystem->bgConfig);
    ov01_021FC1A4(anim, 0, 10, 19);
    anim->done = 0;
    G2x_SetBlendAlpha_(0x04000050, 4, 0x29, 0, 16);
    SetBgPriority(2, 0);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
    PlaySE(SEQ_SE_DP_FW230);
}

void ov01_021FC0A8(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data) {
    HoneySweetScentAnim *anim = data;
    ov01_021FC14C(fieldSystem->bgConfig);
    ov01_021FC1A4(anim, 10, 0, 15);
    anim->done = 0;
    G2x_SetBlendAlpha_(0x04000050, 4, 0x21, 10, 6);
}

void ov01_021FC0DC(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data) {
}

void ov01_021FC0E0(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data) {
    HoneySweetScentAnim *anim = data;
    if (anim->done != TRUE) {
        if (ov01_021FC1B4(anim)) {
            anim->done = TRUE;
        }
        reg_G2_BLDALPHA = anim->cur | ((16 - anim->cur) << 8);
    }
}

void ov01_021FC10C(Field3dObjectTask *task, FieldSystem *fieldSystem, void *data) {
}

const Field3dObjectTaskTemplate ov01_02208BCC = {
    0x400,
    0x18,
    ov01_021FC05C,
    ov01_021FC0DC,
    ov01_021FC0E0,
    ov01_021FC10C,
};

const Field3dObjectTaskTemplate ov01_02208BE4 = {
    0x400,
    0x18,
    ov01_021FC0A8,
    ov01_021FC0DC,
    ov01_021FC0E0,
    ov01_021FC10C,
};

Field3dObjectTask *ov01_021FC110(FieldSystem *fieldSystem) {
    return Field3dObjectTaskManager_CreateTask(fieldSystem->unk4->field3dObjectTaskManager, &ov01_02208BCC);
}

void ov01_021FC124(Field3dObjectTask *task) {
    Field3dObjectTask_Delete(task);
}

int ov01_021FC12C(Field3dObjectTask *task) {
    HoneySweetScentAnim *anim = Field3dObjectTask_GetData(task);
    return anim->done;
}

Field3dObjectTask *ov01_021FC138(FieldSystem *fieldSystem) {
    return Field3dObjectTaskManager_CreateTask(fieldSystem->unk4->field3dObjectTaskManager, &ov01_02208BE4);
}

void ov01_021FC14C(BgConfig *bgConfig) {
    u16 color = 0x5D5F;
    void *buf;
    BG_LoadPlttData(2, &color, 2, 0xc2);
    buf = Heap_Alloc(HEAP_ID_FIELD1, 0x20);
    memset(buf, 0x11, 0x20);
    BG_LoadCharTilesData(bgConfig, 2, buf, 0x20, 1);
    Heap_Free(buf);
    BgFillTilemapBufferAndCommit(bgConfig, 2, 0x6001);
}

void ov01_021FC1A4(HoneySweetScentAnim *anim, int start, int end, int frames) {
    anim->cur = start;
    anim->start = start;
    anim->delta = end - start;
    anim->max = frames;
    anim->counter = 0;
}

BOOL ov01_021FC1B4(HoneySweetScentAnim *anim) {
    int offset = anim->delta * anim->counter / anim->max;
    anim->cur = offset + anim->start;
    if (anim->counter + 1 <= anim->max) {
        anim->counter = anim->counter + 1;
        return FALSE;
    }
    anim->counter = anim->max;
    return TRUE;
}

void ov01_021FC1E0(FieldSystem *fieldSystem) {
    BG_SetMaskColor(2, 0);
}

void ov01_021FC1EC(FieldSystem *fieldSystem) {
    BG_SetMaskColor(2, 0x7FFF);
}

void ov01_021FC1FC(FieldSystem *fieldSystem) {
    u16 color = 0x7FFF;
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    BG_LoadPlttData(2, &color, 2, 0xc4);
    BG_FillCharDataRange(fieldSystem->bgConfig, GF_BG_LYR_MAIN_2, 2, 1, 2);
    BgFillTilemapBufferAndCommit(fieldSystem->bgConfig, 2, 0x6002);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
    ov01_021FC1E0(fieldSystem);
}

void ov01_021FC260(FieldSystem *fieldSystem) {
    u16 color = 0x7FFF;
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 3;
    BG_LoadPlttData(3, &color, 2, 0xc4);
    BG_FillCharDataRange(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 2, 1, 2);
    BgFillTilemapBufferAndCommit(fieldSystem->bgConfig, 3, 0x6002);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
    ov01_021FC1E0(fieldSystem);
}

int ov01_021FC2C4(FieldSystem *fieldSystem) {
    return 0;
}

BOOL ov01_021FC2C8(FieldSystem *fieldSystem) {
    int i;
    u32 value = ov01_021EB31C(fieldSystem->unk4->weatherManager);
    for (i = 0; i < 3; i++) {
        if (value == ov01_02208BC0[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

void ov01_021FC2F0(HoneySweetScentEnv *env) {
    if (env->task != NULL) {
        ov01_021FC124(env->task);
        env->task = NULL;
    }
    Heap_Free(env);
}

u32 GetHoneySweetScentWorkSize(void) {
    return sizeof(HoneySweetScentEnv);
}

BOOL Task_HoneyOrSweetScent(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    HoneySweetScentEnv *env = TaskManager_GetEnvironment(taskManager);
    u32 x;
    u32 z;
    u8 behavior;

    switch (env->state) {
    case 0:
        if (ov01_021FC2C8(fieldSystem) == TRUE) {
            env->state = 1;
            env->useSweetScentFx = ov01_021FC2C4(fieldSystem);
            if (env->useSweetScentFx != 0) {
                ov01_021FC1EC(fieldSystem);
            }
        } else {
            env->state = 7;
            env->timer = 20;
        }
        break;
    case 1:
        env->task = ov01_021FC110(fieldSystem);
        env->state = 2;
        SetBgPriority(2, 0);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
        break;
    case 2:
        if (ov01_021FC12C(env->task) != 0) {
            env->timer = 22;
            env->state = 3;
        }
        break;
    case 3:
        env->timer--;
        if (MapHeader_HasWildEncounters(fieldSystem->location->mapId)) {
            if (env->timer < 0) {
                x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
                z = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
                behavior = GetMetatileBehavior(fieldSystem, x, z);
                if (FieldSystem_CanGenerateStepEncounter(fieldSystem, behavior)) {
                    env->state = 6;
                } else {
                    env->state = 4;
                }
            }
        } else {
            env->state = 4;
        }
        break;
    case 4:
        ov01_021FC124(env->task);
        env->task = ov01_021FC138(fieldSystem);
        env->state = 5;
        break;
    case 5:
        if (ov01_021FC12C(env->task) != 0) {
            GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
            reg_G2_BLDCNT = 0;
            SetBgPriority(2, 3);
            env->state = 8;
        }
        break;
    case 6:
        ov01_021FC2F0(env);
        if (env->useSweetScentFx != 0) {
            ov01_021FC260(fieldSystem);
        }
        GF_ASSERT(FieldSystem_PerformSweetScentEncounterCheck(fieldSystem, taskManager));
        break;
    case 7:
        env->timer--;
        if (env->timer < 0) {
            QueueScript(taskManager, 2019, NULL, NULL);
            env->state = 9;
        }
        break;
    case 8:
        QueueScript(taskManager, 2018, NULL, NULL);
        env->state = 9;
        break;
    case 9:
        ov01_021FC2F0(env);
        if (env->useSweetScentFx != 0) {
            ov01_021FC1FC(fieldSystem);
        }
        BgFillTilemapBufferAndCommit(fieldSystem->bgConfig, 2, 0);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
        return TRUE;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}
