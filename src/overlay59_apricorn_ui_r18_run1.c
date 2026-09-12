#include "overlay59_apricorn_ui_r18_private.h"

int ov59_0223858C(u8 *work) {
    if (ov59_022385AC(work)) {
        ov59_02238D74(work);
        ov59_02238C24(work);
        return 4;
    }
    return 15;
}

int ov59_022385AC(u8 *work) {
    if (R18_U8(work, 0x47) != 0xFF && TextPrinterCheckActive(R18_U8(work, 0x47))) {
        return FALSE;
    }
    if (System_GetTouchNew()) {
        PlaySE(0x5DC);
        R18_U32(work, 0x40) = 1;
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
        R18_U8(work, 0x47) = 0xFF;
        return TRUE;
    }
    if (R18_U32(gSystem, 0x48) & 0xCF3) {
        R18_U32(work, 0x40) = 0;
    }
    if (R18_U32(gSystem, 0x48) & 3) {
        PlaySE(0x5DC);
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
        R18_U8(work, 0x47) = 0xFF;
        return TRUE;
    }
    return FALSE;
}

void ov59_02238624(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    sub_0200FBF4(0, 0);
    sub_0200FBF4(1, 0);
    ResetVisibleHardwareWindows(0);
    ResetVisibleHardwareWindows(1);
}

void ov59_02238674(u8 *work) {
    ov59_02239428(work);
    ov59_02239604(work);
    ov59_02239704(work);
    ov59_022397E4(work);
    ov59_022398CC(work);
    ov59_022399F0(work);
    Main_SetVBlankIntrCB(ov59_022393D4, work);
}

void ov59_022386A8(u8 *work) {
    ov59_02239A08(work);
    ov59_02239918(work);
    ov59_022398A0(work);
    ov59_0223978C(work);
    ov59_022396E4(work);
    ov59_022395B8(work);
}

void ov59_022386D0(u8 *work) {
    int i;
    int width;
    int x;
    u8 state;

    ov59_022387D0(work, 0);
    ov59_022388C4(work);
    ReadMsgDataIntoString(R18_PTR(work, 0x5C), 0, R18_PTR(work, 0x64));
    width = (u8)FontID_String_GetWidth(0, R18_PTR(work, 0x64), 0);
    x = (80 - width) / 2;
    AddTextPrinterParameterizedWithColor(work + 0x158, 0, R18_PTR(work, 0x64), x, 0, 0, 0xF0200, 0);
    for (i = 0; i < 7; i++) {
        ov59_0223892C(work, i);
    }
    state = R18_U8(work, 0x44);
    switch (state) {
    case 1:
        ov59_02238C24(work);
        return;
    case 2:
        ov59_02238C40(work, 10);
        return;
    case 0:
    default:
        break;
    }
    ov59_02238C40(work, 0);
}

void ov59_02238768(u8 *work) {
    int i;

    R18_U8(work, 0x18) = sub_02031C08(R18_PTR(work, 0x10));
    R18_U8(work, 0x14) = sub_02031CE8(R18_PTR(work, 0x10));
    sub_02031CEC(R18_PTR(work, 0x10), 8, work + 0x22);
    R18_U8(work, 0x16) = R18_U8(work, 0x24);
    R18_U8(work, 0x17) = sub_02031FE8(work + 0x22);
    R18_U8(work, 0x15) = sub_02031D80(work + 0x22);
    sub_02031DA0(work + 0x22, work + 0x2A);
    R18_U8(work, 0x19) = sub_02031CA0(R18_PTR(work, 0x10));
    for (i = 0; i < 7; i++) {
        R18_U8(work + i, 0x1A) = ApricornBox_CountApricorn(R18_PTR(work, 0x10), i);
    }
}

void ov59_022387D0(u8 *work, int sequence) {
    u32 width;

    Sprite_SetAnimCtrlSeq(R18_PTR(work, 0x254), sequence);
    Sprite_ResetAnimCtrlState(R18_PTR(work, 0x254));
    FillWindowPixelBuffer(work + 0x148, 0);
    width = FontID_String_GetWidth(4, R18_PTR(work, 0x6C), 0);
    AddTextPrinterParameterizedWithColor(work + 0x148, 4, R18_PTR(work, 0x6C), (48 - width) >> 1, 0, 0xFF, 0x10200, 0);
    ScheduleWindowCopyToVram(work + 0x148);
}

void ov59_02238834(u8 *work, int index, int sequence) {
    struct {
        int value;
    } width;
    void *window = work + 0x128 + (index + 6) * 16;
    int spriteOffset;

    FillWindowPixelBuffer(window, 0);
    ReadMsgDataIntoString(R18_PTR(work, 0x5C), index + 5, R18_PTR(work, 0x68));
    width.value = FontID_String_GetWidth(4, R18_PTR(work, 0x68), 0);
    AddTextPrinterParameterizedWithColor(window, 4, R18_PTR(work, 0x68), (48 - width.value) / 2, 0, 0xFF, _0223CB80[index], 0);
    ScheduleWindowCopyToVram(window);
    work += 0x254;
    spriteOffset = (index + 9) * 4;
    Sprite_SetAnimCtrlSeq(R18_PTR(work, spriteOffset), sequence + (index * 2 + 0x1C));
    Sprite_ResetAnimCtrlState(R18_PTR(work, spriteOffset));
}

void ov59_022388C4(u8 *work) {
    int index = ov59_02239EA8(work);
    s16 x;
    s16 y;

    switch (index) {
    case 7:
        x = 200;
        y = 92;
        ov59_02238C24(work);
        break;
    case 8:
        x = 240;
        y = 168;
        break;
    default:
        x = ov59_0223C6C4[index * 2] + 4;
        y = ov59_0223C6C6[index * 2] - 16;
        break;
    }
    Sprite_SetPositionXY(R18_PTR(work, 0x258), x, y);
    ov59_02238C7C(work);
}

void ov59_0223891C(u8 *work, int active) {
    Sprite_SetAnimActiveFlag(R18_PTR(work, 0x258), active);
}

void ov59_0223892C(u8 *work, u8 index) {
    u8 *counts;
    int windowOffset;
    u8 *windowBase;
    void **spriteSlot;
    u8 width;

    windowBase = work + 0x128;
    windowOffset = (index + 11) * 16;
    counts = work + 0x1A;
    if (counts[index] == 0) {
        spriteSlot = &((void **)(work + 0x254))[index + 2];
        Sprite_SetDrawFlag(*spriteSlot, FALSE);
        ClearWindowTilemapAndScheduleTransfer(windowBase + windowOffset);
    } else {
        spriteSlot = &((void **)(work + 0x254))[index + 2];
        Sprite_SetDrawFlag(*spriteSlot, TRUE);
        FillWindowPixelBuffer(windowBase + windowOffset, 0);
        BufferIntegerAsString(R18_PTR(work, 0x60), 0, counts[index], 2, 1, 1);
        StringExpandPlaceholders(R18_PTR(work, 0x60), R18_PTR(work, 0x64), R18_PTR(work, 0x74));
        width = FontID_String_GetWidth(0, R18_PTR(work, 0x64), 0);
        AddTextPrinterParameterizedWithColor(windowBase + windowOffset, 0, R18_PTR(work, 0x64), (16 - width) / 2, 0, 0xFF, 0x10200, 0);
        ScheduleWindowCopyToVram(windowBase + windowOffset);
    }
    Sprite_SetPositionXY(*spriteSlot, ov59_0223C6C4[index * 2], ov59_0223C6C6[index * 2]);
}
