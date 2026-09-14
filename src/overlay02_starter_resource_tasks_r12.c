#include "overlay02_starter_resource_tasks_r12_private.h"

void ov02_02249D5C(SysTask *task, void *work) {
    int i;
    if (*(int *)((u8 *)work + 0x210) == 0) {
        for (i = 0; i < 4; i++) {
            if (((SpriteResource **)work)[0x6b + i] != NULL) {
                SpriteTransfer_CreateCharTransferTask_AllocAtEnd(((SpriteResource **)work)[0x6b + i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (((SpriteResource **)work)[0x6f + i] != NULL) {
                SpriteTransfer_CreatePlttTransferTask(((SpriteResource **)work)[0x6f + i]);
            }
        }
        if (*(void **)((u8 *)work + 0x218) != NULL) {
            ov02_0224A834(work, *(void **)((u8 *)work + 0x218));
        }
        if (*(void **)((u8 *)work + 0x21c) != NULL) {
            ov02_0224A88C(work, *(void **)((u8 *)work + 0x21c));
        }
        (*(int *)((u8 *)work + 0x210))++;
        SysTask_CreateOnVWaitQueue(ov02_02249DD8, work, 0x80);
    }
}

void ov02_02249DD8(SysTask *task, void *work) {
    int i;
    if (*(int *)((u8 *)work + 0x210) == 1) {
        for (i = 0; i < 4; i++) {
            if (((SpriteResource **)work)[0x6b + i] != NULL) {
                sub_0200A740(((SpriteResource **)work)[0x6b + i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (((SpriteResource **)work)[0x6f + i] != NULL) {
                sub_0200A740(((SpriteResource **)work)[0x6f + i]);
            }
        }
        if (*(void **)((u8 *)work + 0x218) != NULL) {
            Heap_Free(*(void **)((u8 *)work + 0x218));
            *(void **)((u8 *)work + 0x218) = NULL;
        }
        if (*(void **)((u8 *)work + 0x21c) != NULL) {
            Heap_Free(*(void **)((u8 *)work + 0x21c));
            *(void **)((u8 *)work + 0x21c) = NULL;
        }
        *(int *)((u8 *)work + 0x214) = 1;
        SysTask_Destroy(task);
    }
}

void ov02_02249E58(SysTask *task, void *work) {
    SpriteResource *res = SpriteResourceCollection_Find(*(GF_2DGfxResMan **)((u8 *)work + 0x19c), 0);
    if (*(int *)((u8 *)work + 0x210) == 0) {
        SpriteTransfer_CreateCharTransferTask_AllocAtEnd(res);
        SysTask_CreateOnVWaitQueue(ov02_02249E90, work, 0x80);
        *(int *)((u8 *)work + 0x210) = *(int *)((u8 *)work + 0x210) + 1;
    }
}

void ov02_02249E90(SysTask *task, void *work) {
    SpriteResource *res = SpriteResourceCollection_Find(*(GF_2DGfxResMan **)((u8 *)work + 0x19c), 0);
    if (*(int *)((u8 *)work + 0x210) == 1) {
        sub_0200A740(res);
        *(int *)((u8 *)work + 0x214) = 1;
        SysTask_Destroy(task);
    }
}

void ov02_02249EC0(void *work) {
    NARC *narc = ov02_0224A074();
    ov02_0224A69C(work, 0, 0xC0000, 0x1000, 0xC0000);
    ov02_0224A648(work);
    *(u16 *)((u8 *)work + 0x24) = GetBgPriority(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), 0);
    *(u16 *)((u8 *)work + 0x26) = GetBgPriority(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), 3);
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG3CNT = reg_G2_BG3CNT & ~3;
    GfGfx_EngineATogglePlanes(8, 0);
#ifdef HEARTGOLD
    ov02_0224A570(narc, 2, (NNSG2dPaletteData **)((u8 *)work + 0x6c));
    ov02_0224A598(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), narc, 0, (NNSG2dCharacterData **)((u8 *)work + 0x68));
    ov02_0224A5D0(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), narc, 1, (NNSG2dScreenData **)((u8 *)work + 0x64));
#else
    ov02_0224A570(narc, 5, (NNSG2dPaletteData **)((u8 *)work + 0x6c));
    ov02_0224A598(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), narc, 3, (NNSG2dCharacterData **)((u8 *)work + 0x68));
    ov02_0224A5D0(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), narc, 4, (NNSG2dScreenData **)((u8 *)work + 0x64));
#endif
    ov02_0224A080(work, narc);
    NARC_Delete(narc);
    *(void **)((u8 *)work + 0x1e0) = sub_020689C8(HEAP_ID_FIELD1, 0x20);
    GfGfx_EngineATogglePlanes(8, 1);
}

void ov02_02249F6C(void *work) {
    NARC *narc = ov02_0224A074();
    *(u16 *)((u8 *)work + 0x24) = GetBgPriority(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), 0);
    *(u16 *)((u8 *)work + 0x26) = GetBgPriority(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8), 3);
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG3CNT = reg_G2_BG3CNT & ~3;
    GfGfx_EngineATogglePlanes(8, 0);
    ov02_0224A080(work, narc);
    NARC_Delete(narc);
    *(void **)((u8 *)work + 0x1e0) = sub_020689C8(HEAP_ID_FIELD1, 0x20);
    GfGfx_EngineATogglePlanes(8, 1);
}

void ov02_02249FD4(void *work) {
    GfGfx_EngineATogglePlanes(8, 0);
    sub_020689F8(*(void **)((u8 *)work + 0x1e0));
    ov02_0224A63C(*(BgConfig **)((u8 *)*(void **)((u8 *)work + 0x60) + 8));
    ov02_0224A288(work);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | *(u16 *)((u8 *)work + 0x24);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | *(u16 *)((u8 *)work + 0x26);
    FieldMessage_LoadTextPalettes(0, 1);
    GfGfx_EngineATogglePlanes(8, 1);
}

void ov02_0224A028(void *work) {
    GfGfx_EngineATogglePlanes(8, 0);
    sub_020689F8(*(void **)((u8 *)work + 0x1e0));
    ov02_0224A288(work);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | *(u16 *)((u8 *)work + 0x24);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | *(u16 *)((u8 *)work + 0x26);
    FieldMessage_LoadTextPalettes(0, 1);
    GfGfx_EngineATogglePlanes(8, 1);
}
