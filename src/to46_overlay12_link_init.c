#include "to46_overlay12_link_init_private.h"

void ov12_022399D4(OverlayManager *man, BattleSetup *setup) {
    GraphicsBanks banks;
    GraphicsModes modes;
    BgTemplate bgTemplate;
    LinkInitWork *work = OverlayManager_CreateAndGetData(man, sizeof(LinkInitWork), (enum HeapID)5);
    MsgData *msgData;
    String *string;
    u32 frame;

    work->setup = setup;
    work->state0 = 0;
    work->state1 = 0;
    work->field1022 = 0;
    work->palette = PaletteData_Init((enum HeapID)5);
    PaletteData_SetAutoTransparent(work->palette, TRUE);
    PaletteData_AllocBuffers(work->palette, (PaletteBufferId)0, 0x200, (enum HeapID)5);
    PaletteData_FillPaletteInBuffer(work->palette, (PaletteBufferId)0, (PaletteSelector)2, 0, 0, 0x100);
    work->bg = BgConfig_Alloc((enum HeapID)5);
    work->window = AllocWindows((enum HeapID)5, 1);
    sub_02074EC4(work);
    GfGfx_DisableEngineAPlanes();
    banks = ov12_0226C080;
    GfGfx_SetBanks(&banks);
    MIi_CpuClear32(0, (void *)0x06000000, 0x80000);
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    MIi_CpuClear32(0, (void *)0x06400000, 0x40000);
    MIi_CpuClear32(0, (void *)0x06600000, 0x20000);
    MIi_CpuClear16(0, (void *)0x05000000, 0x200);
    modes = ov12_0226BFF8;
    SetBothScreensModesAndDisable(&modes);
    bgTemplate = ov12_0226C044;
    InitBgFromTemplate(work->bg, 1, &bgTemplate, 0);
    BgClearTilemapBufferAndCommit(work->bg, 1);
    frame = Options_GetFrame(setup->options);
    sub_0200EB80(work->bg, 1, 1, 10, (u8)frame, (enum HeapID)5);
    PaletteData_LoadNarc(work->palette, (NarcId)0x10, 8, (enum HeapID)5, (PaletteBufferId)0, 0x20, 0xB0);
    PaletteData_LoadNarc(work->palette, (NarcId)0x26, sub_0200E640(frame), (enum HeapID)5, (PaletteBufferId)0, 0x20, 0xA0);
    PaletteData_FillPaletteInBuffer(work->palette, (PaletteBufferId)0, (PaletteSelector)0, 0, 0, 0x100);
    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(0x10, TRUE);
    *(volatile u16 *)0x04000304 |= 0x8000;
    AddWindowParameterized(work->bg, work->window, 1, 2, 0x13, 0x1B, 4, 0xB, 0x1F);
    FillWindowPixelBuffer(work->window, 0xFF);
    DrawFrameAndWindow2(work->window, FALSE, 1, 0xA);
    msgData = NewMsgDataFromNarc((MsgDataLoadType)1, (NarcId)0x1B, 0xC5, (enum HeapID)5);
    string = String_New(0x100, (enum HeapID)5);
    ReadMsgDataIntoString(msgData, 0x39B, string);
    AddTextPrinterParameterized(work->window, 1, string, 0, 0, 0, NULL);
    String_Delete(string);
    DestroyMsgData(msgData);
    Main_SetVBlankIntrCB(ov12_022397E4, work);
    PaletteData_BeginPaletteFade(work->palette, 5, 0xFFFF, 0, 0x10, 0, 0);
    work->waiting = WaitingIcon_New(work->window, 1);
    ov12_0223A7A0();
}
