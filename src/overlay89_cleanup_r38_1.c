#include "global.h"

#include "gf_gfx_planes.h"
#include "overlay89_r38_private.h"

extern void DestroyMsgData(void *);
extern void FontID_Release(int);
extern void GF_DestroyVramTransferManager(void);
extern void GF_RunVramTransferTasks(void);
extern void HBlankInterruptDisable(void);
extern void Heap_Free(void *);
extern void MessageFormat_Delete(void *);
extern void NARC_Delete(void *);
extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void PaletteData_PushTransparentBuffers(void *);
extern void PaletteData_Free(void *);
extern void PaletteData_FreeBuffers(void *, int);
extern void RequestSwap3DBuffers(int, int);
extern void SpriteSystem_DrawSprites(void *);
extern void SpriteSystem_Free(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_TransferOam(void);
extern void SpriteSystem_UpdateTransfer(void);
extern void String_Delete(void *);
extern void SysTask_Destroy(void *);
extern void TextFlags_SetAutoScrollParam(int);
extern void TextFlags_SetCanABSpeedUpPrint(int);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
extern void YesNoPrompt_Destroy(void *);
extern void ov89_02259230(void *);
extern void ov89_022596DC(void *);
extern void ov89_022598A8(void *);
extern void ov89_02259BA0(void *);
extern void ov89_02259C00(void *);
extern void ov89_02259D50(void *);
extern void ov89_02259E10(void *);
extern void ov89_0225A47C(void *);
extern void ov89_02259C0C(void *);
extern void ov89_0225A5EC(void *);
extern void ov89_0225A760(void *, void *);
extern void sub_020135AC(void *);
extern void sub_02021238(void);
extern void sub_0203A914(void);
extern const GraphicsBanks ov89_0225CA78;
extern const GraphicsModes ov89_0225C9DC;
extern const Ov89BgTemplates ov89_0225CC18;
extern const Ov89BgTemplates ov89_0225CC6C;

BOOL ov89_02258F00(void *);
void ov89_02258FF4(void *, u8 *);
void ov89_0225901C(u8 *);
void ov89_0225905C(BgConfig *);

BOOL ov89_02258F00(void *manager) {
    u8 *work = OverlayManager_GetData(manager);

    SysTask_Destroy(*(void **)(work + 0x18));
    ov89_022596DC(work);
    ov89_022598A8(work);
    YesNoPrompt_Destroy(*(void **)(work + 0x24));
    ov89_0225A47C(work + 0x194);
    String_Delete(*(void **)(work + 0xC4));
    FontID_Release(2);
    sub_020135AC(*(void **)(work + 0x10));
    DestroyMsgData(*(void **)(work + 0x30));
    MessageFormat_Delete(*(void **)(work + 0x2C));
    ov89_02259D50(work);
    ov89_02259230(*(void **)(work + 8));
    Heap_Free(*(void **)(work + 8));
    SpriteSystem_FreeResourcesAndManager(*(void **)(work + 0x1C), *(void **)(work + 0x20));
    SpriteSystem_Free(*(void **)(work + 0x1C));
    PaletteData_FreeBuffers(*(void **)(work + 0xC), 0);
    PaletteData_FreeBuffers(*(void **)(work + 0xC), 1);
    PaletteData_FreeBuffers(*(void **)(work + 0xC), 2);
    PaletteData_FreeBuffers(*(void **)(work + 0xC), 3);
    PaletteData_Free(*(void **)(work + 0xC));
    ov89_02259C00(work);
    ov89_02259BA0(work);
    ov89_02259E10(*(void **)(work + 0x14));
    NARC_Delete(*(void **)(work + 0x160));
    NARC_Delete(*(void **)(work + 0x164));
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GF_DestroyVramTransferManager();
    sub_02021238();
    TextFlags_SetCanABSpeedUpPrint(0);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(0);
    sub_0203A914();
    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_125);
    return TRUE;
}

void ov89_02258FF4(void *unused, u8 *work) {
    ov89_0225A5EC(work + 0x194);
    ov89_02259C0C(work);
    SpriteSystem_DrawSprites(*(void **)(work + 0x20));
    SpriteSystem_UpdateTransfer();
    RequestSwap3DBuffers(0, 0);
}

void ov89_0225901C(u8 *work) {
    vu32 *base;

    ov89_0225A760(work + 0x194, *(void **)(work + 0x9BC));
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    PaletteData_PushTransparentBuffers(*(void **)(work + 0xC));
    DoScheduledBgGpuUpdates(*(void **)(work + 8));
    base = (vu32 *)0x027E0000;
    base[0x3FF8 / 4] |= 1;
}

void ov89_0225905C(BgConfig *bgConfig) {
    Ov89BgTemplates mainTemplates;
    Ov89BgTemplates subTemplates;
    GraphicsBanks banks;
    GraphicsModes modes;

    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    banks = ov89_0225CA78;
    GfGfx_SetBanks(&banks);
    MIi_CpuClear32(0, (u32 *)0x06000000, 0x80000);
    MIi_CpuClear32(0, (u32 *)0x06200000, 0x20000);
    MIi_CpuClear32(0, (u32 *)0x06400000, 0x40000);
    MIi_CpuClear32(0, (u32 *)0x06600000, 0x20000);
    modes = ov89_0225C9DC;
    SetBothScreensModesAndDisable(&modes);

    mainTemplates = ov89_0225CC18;
    InitBgFromTemplate(bgConfig, 1, &mainTemplates.items[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    BgSetPosTextAndCommit(bgConfig, 1, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 1, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 2, &mainTemplates.items[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    BgSetPosTextAndCommit(bgConfig, 2, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 2, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 3, &mainTemplates.items[2], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    BgSetPosTextAndCommit(bgConfig, 3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 3, BG_POS_OP_SET_Y, 0);
    reg_G2_BG0CNT = (u16)((reg_G2_BG0CNT & ~3) | 2);
    GfGfx_EngineATogglePlanes(1, 1);

    subTemplates = ov89_0225CC6C;
    InitBgFromTemplate(bgConfig, 5, &subTemplates.items[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 5);
    BgSetPosTextAndCommit(bgConfig, 5, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 5, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 6, &subTemplates.items[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 6);
    BgSetPosTextAndCommit(bgConfig, 6, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 6, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 7, &subTemplates.items[2], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 7);
    BgSetPosTextAndCommit(bgConfig, 7, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 7, BG_POS_OP_SET_Y, 0);
    BG_ClearCharDataRange(5, 0x20, 0, HEAP_ID_125);
}
