#include "overlay_app_manager_internal.h"

BOOL sub_020192D0(OverlayManager *man, int *state) {
    UnkStruct_020192D0 *data;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    reg_GX_DISPCNT &= 0xFFFF1FFF;
    reg_GXS_DB_DISPCNT &= 0xFFFF1FFF;
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    Heap_Create(HEAP_ID_3, HEAP_ID_123, 0x28000);
    data = OverlayManager_CreateAndGetData(man, sizeof(UnkStruct_020192D0), HEAP_ID_123);
    MI_CpuFill8(data, 0, sizeof(UnkStruct_020192D0));
    data->args = OverlayManager_GetArgs(man);
    Sound_SetSceneAndPlayBGM(11, 0x47D, 1);
    return TRUE;
}

BOOL sub_0201935C(OverlayManager *man, int *state) {
    UnkStruct_020192D0 *data = OverlayManager_GetData(man);

    switch (*state) {
    case 0:
        sub_020194B4(data);
        *state = 1;
        break;
    case 1:
        if (sub_02034DB8()) {
            _021D1108 = data->unk10;
            ov00_021EC294(sub_02019520, sub_02019548);
            data->unk78 = 1;
            ++*state;
        }
        break;
    case 2:
        data->unk08 = OverlayManager_New(&_020F6288, data, HEAP_ID_123);
        ++*state;
        break;
    case 3:
        if (OverlayManager_Run(data->unk08) == TRUE) {
            OverlayManager_Delete(data->unk08);
            if (data->unk7C == 1) {
                data->unk04 = 1;
                ++*state;
            } else {
                *state = 8;
            }
        }
        break;
    case 4: {
        const OverlayManagerTemplate *tmpl = sub_02087E10(data->args->unk0C);
        data->unk08 = OverlayManager_New(tmpl, data->args->unk00, HEAP_ID_123);
        ++*state;
        break;
    }
    case 5:
        if (OverlayManager_Run(data->unk08) == TRUE) {
            OverlayManager_Delete(data->unk08);
            ++*state;
        }
        break;
    case 6:
        data->unk08 = OverlayManager_New(&_020F6288, data, HEAP_ID_123);
        ++*state;
        break;
    case 7:
        if (OverlayManager_Run(data->unk08) == TRUE) {
            OverlayManager_Delete(data->unk08);
            data->unk04 = 0;
            ++*state;
        }
        break;
    case 8:
        return TRUE;
    }

    if (data->unk78 == 1 && data->unk04 == 1 && data->unk7C == 1) {
        ov00_021ECB40();
        sub_0203A930(3 - ov00_021EC9D4());
    }
    return FALSE;
}

BOOL sub_02019490(OverlayManager *man, int *state) {
    UnkStruct_020192D0 *data = OverlayManager_GetData(man);

    sub_020194F8(data);
    Heap_Free(data->args);
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_123);
    return TRUE;
}

void sub_020194B4(UnkStruct_020192D0 *data) {
    if (data->unk78 == 0) {
        LoadDwcOverlay();
        LoadOVY38();
        sub_02039FD8(HEAP_ID_123);
        data->unk0C = Heap_Alloc(HEAP_ID_123, 0x20020);
        data->unk10 = NNS_FndCreateExpHeapEx((void *)(((u32)data->unk0C + 0x1F) & ~0x1F), 0x20000, 0);
        sub_02034D8C();
        Sys_ClearSleepDisableFlag(4);
    }
}

void sub_020194F8(UnkStruct_020192D0 *data) {
    if (data->unk78 == 1) {
        NNS_FndDestroyExpHeap(data->unk10);
        Heap_Free(data->unk0C);
        UnloadOVY38();
        UnloadDwcOverlay();
        sub_02034DE0();
        data->unk78 = 0;
    }
}

void *sub_02019520(int name, u32 size, int align) {
    void *ptr;
    OSIntrMode intrMode = OS_DisableInterrupts();
    ptr = NNS_FndAllocFromExpHeapEx(_021D1108, size, align);
    OS_RestoreInterrupts(intrMode);
    return ptr;
}

void sub_02019548(int name, void *ptr, u32 size) {
    if (ptr != NULL) {
        OSIntrMode intrMode = OS_DisableInterrupts();
        NNS_FndFreeToExpHeap(_021D1108, ptr);
        OS_RestoreInterrupts(intrMode);
    }
}
