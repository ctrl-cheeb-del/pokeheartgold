#include "overlay_02_legendary_internal.h"

int ov02_022462DC(void *task, void *env) {
    return ov02_02246048(*(void **)((u8 *)env + 8));
}

void ov02_022462E8(void *task) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_02246304(field);
    TaskManager_Call(task, ov02_02246330, env);
}

void *ov02_02246304(void *field) {
    void *p = Heap_Alloc(4, 0x10);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0x10);
    *(void **)((u8 *)p + 4) = field;
    *(u32 *)p = 4;
    return p;
}

int ov02_02246330(void *task) {
    u8 *p = TaskManager_GetEnvironment(task);
    switch (p[8]) {
    case 0:
        ov02_02246398(p);
        PlaySE(0x87D);
        p[8]++;
        break;
    case 1:
        if (ov02_02246490(p)) {
            u8 count = p[0xC]++;
            if (count >= 1) {
                p[8]++;
            }
        }
        break;
    case 2:
        if (!IsSEPlaying(0x87D)) {
            ov02_02246444(p);
            Heap_Free(p);
            return 1;
        }
        break;
    }
    return 0;
}

void ov02_02246398(void *data) {
    u8 *p = data;
    void *narc;
    p[0xD] = 0;
    G2x_SetBlendAlpha_(0x04000050, 2, 5, p[0xD], 0x1F - p[0xD]);
    narc = NARC_New(0xAE, *(u32 *)p);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0xC, 0, 0, 0x20, *(u32 *)p);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0xD, *(void **)((u8 *)*(void **)(p + 4) + 8), 1, 0, 0x40, 0, *(u32 *)p);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0xE, *(void **)((u8 *)*(void **)(p + 4) + 8), 1, 0, 0, 0, *(u32 *)p);
    p[0xE] = GetBgPriority(*(void **)((u8 *)*(void **)(p + 4) + 8), 0);
    p[0xF] = GetBgPriority(*(void **)((u8 *)*(void **)(p + 4) + 8), 1);
    SetBgPriority(0, 1);
    SetBgPriority(1, 0);
    GfGfx_EngineATogglePlanes(2, 1);
    NARC_Delete(narc);
}

void ov02_02246444(void *data) {
    u8 *p = data;
    GfGfx_EngineATogglePlanes(2, 0);
    SetBgPriority(0, p[0xE]);
    SetBgPriority(1, p[0xF]);
    BgClearTilemapBufferAndCommit(*(void **)((u8 *)*(void **)(p + 4) + 8), 1);
    BG_ClearCharDataRange(1, 0x40, 0, *(void **)p);
    G2x_SetBlendAlpha_(0x04000050, 0, 0, 0x1F, 0);
}

int ov02_02246490(void *data) {
    u8 *p = data;
    switch (p[9]) {
    case 0:
        p[0xB] = 0;
        p[0xA] = 0;
        p[0xD] = 0;
        p[9]++;
        break;
    case 1: {
        u8 wait = p[0xB]++;
        if (wait == 0) {
            G2x_SetBlendAlpha_(0x04000050, 2, 5, p[0xD], 0x1F - p[0xD]);
            {
                u8 step = p[0xA]++;
                if (step < 0xC) {
                    p[0xD]++;
                } else {
                    p[0xD]--;
                }
            }
            p[0xB] = 0;
            if (p[0xA] > 0x18) {
                p[9]++;
            }
        }
    } break;
    default:
        p[0xA] = 0;
        p[0xB] = 0;
        p[9] = 0;
        return 1;
    }
    return 0;
}

void *ov02_0224650C(void *field, int heap) {
    u8 *p = Heap_Alloc(heap, 0x38);
    MI_CpuFill8(p, 0, 0x38);
    *(u32 *)p = heap;
    *(void **)(p + 4) = field;
    *(void **)(p + 0x18) = Camera_New(heap);
    return p;
}

void ov02_02246534(void *data) {
    u8 *p = data;
    Camera_Delete(*(void **)(p + 0x18));
    Heap_Free(p);
}
