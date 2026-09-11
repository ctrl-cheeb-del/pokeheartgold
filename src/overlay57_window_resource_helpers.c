#include "overlay57_window_resource_helpers_private.h"

void ov57_02239558(Ov57R7SpriteWork *work) {
    int i;
    for (i = 0; i < 12; i++) {
        ManagedSprite_TickFrame(work->slots[i].sprite);
    }
    ManagedSprite_TickFrame(*(ManagedSprite **)((u8 *)work + 0x31C));
    ManagedSprite_TickFrame(*(ManagedSprite **)((u8 *)work + 0x320));
}

void ov57_02239588(Ov57R7SpriteWork *work) {
    int i;
    for (i = 0; i < 12; i++) {
        Sprite_DeleteAndFreeResources(work->slots[i].sprite);
    }
    Sprite_DeleteAndFreeResources(*(ManagedSprite **)((u8 *)work + 0x31C));
    Sprite_DeleteAndFreeResources(*(ManagedSprite **)((u8 *)work + 0x320));
}

void ov57_022395B8(BgConfig *bgConfig, PaletteData *paletteData) {
    NNSG2dCharacterData *charData;
    void *allocation;
    void *rawData;
    u32 i;

    allocation = GfGfxLoader_GetCharData((NarcId)87, 8, TRUE, &charData, (enum HeapID)52);
    rawData = charData->pRawData;
    DC_FlushRange(rawData, charData->szByte);
    for (i = 0; i < 9; i++) {
        BG_LoadCharTilesData(bgConfig, 1, (u8 *)rawData + ov57_0223BDF4[i] * 32, 32, i + 1);
    }
    Heap_Free(allocation);
    PaletteData_LoadFromNarc(paletteData, (NarcId)87, 2, (enum HeapID)52, (PaletteBufferId)0, 0x20, 0xC0, 0x20);
    LoadUserFrameGfx1(bgConfig, (GFBgLayer)1, 0x1F, 13, 0, (enum HeapID)52);
    PaletteData_LoadNarc(paletteData, (NarcId)38, sub_0200E3D8(), (enum HeapID)52, (PaletteBufferId)0, 0x20, 0xD0);
    PaletteData_LoadNarc(paletteData, (NarcId)16, 8, (enum HeapID)52, (PaletteBufferId)0, 0x20, 0xE0);
}

void ov57_02239670(BgConfig *bgConfig, PaletteData *paletteData, int frame) {
    LoadUserFrameGfx2(bgConfig, (GFBgLayer)4, 1, 15, frame, (enum HeapID)52);
    PaletteData_LoadNarc(paletteData, (NarcId)38, sub_0200E640(frame), (enum HeapID)52, (PaletteBufferId)1, 0x20, 0xC0);
    LoadUserFrameGfx1(bgConfig, (GFBgLayer)4, 0x1F, 13, 0, (enum HeapID)52);
    PaletteData_LoadNarc(paletteData, (NarcId)38, sub_0200E3D8(), (enum HeapID)52, (PaletteBufferId)1, 0x20, 0xD0);
    PaletteData_LoadNarc(paletteData, (NarcId)16, 8, (enum HeapID)52, (PaletteBufferId)1, 0x20, 0xE0);
    PaletteData_LoadNarc(paletteData, (NarcId)16, 8, (enum HeapID)52, (PaletteBufferId)1, 0x20, 0x30);
    PaletteData_LoadNarc(paletteData, (NarcId)87, 0, (enum HeapID)52, (PaletteBufferId)1, 0x20, 0xB0);
}

void ov57_02239728(Window *window, int frame, u32 message, BOOL drawFrame) {
    MsgData *msgData;
    String *string;

    if (drawFrame) {
        if (frame == 0) {
            DrawFrameAndWindow1(window, TRUE, 1, 12);
        } else {
            DrawFrameAndWindow2(window, TRUE, 1, 12);
        }
    }
    if (message == 0xFFFF) {
        FillWindowPixelBuffer(window, 15);
        ScheduleWindowCopyToVram(window);
        return;
    }
    msgData = NewMsgDataFromNarc((MsgDataLoadType)0, (NarcId)27, 11, (enum HeapID)52);
    string = NewString_ReadMsgData(msgData, message);
    FillWindowPixelBuffer(window, 15);
    AddTextPrinterParameterized(window, (FontID)0, string, 0, 0, 0, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(string);
    DestroyMsgData(msgData);
}

void ov57_022397B0(BgConfig *bgConfig, Window *window, int bgId, int left, int top, int width, int height, int baseTile) {
    InitWindow(window);
    AddWindowParameterized(bgConfig, window, bgId, left, top, width, height, 14, baseTile);
    DrawFrameAndWindow2(window, TRUE, 1, 12);
    FillWindowPixelBuffer(window, 15);
    ScheduleWindowCopyToVram(window);
}

void ov57_02239814(BgConfig *bgConfig, Window *window, int bgId, int left, int top, int width, int height, int baseTile) {
    InitWindow(window);
    AddWindowParameterized(bgConfig, window, bgId, left, top, width, height, 14, baseTile);
    FillWindowPixelBuffer(window, 15);
}

void ov57_02239868(BgConfig *bgConfig, Window *window, int bgId, int left, int top, int width, int height, int baseTile, int palette) {
    InitWindow(window);
    AddWindowParameterized(bgConfig, window, bgId, left, top, width, height, palette, baseTile);
    FillWindowPixelBuffer(window, 15);
    ScheduleWindowCopyToVram(window);
}

void ov57_022398C4(Ov57R7Work *work) {
    ov57_02239868(work->bgConfig, &work->windows[5], 6, 3, 2, 4, 2, 0xA6, 11);
    ov57_02239868(work->bgConfig, &work->windows[6], 6, 10, 2, 4, 2, 0xAE, 11);
    ov57_02239868(work->bgConfig, &work->windows[7], 6, 3, 5, 4, 2, 0xB6, 11);
    ov57_02239868(work->bgConfig, &work->windows[8], 6, 10, 5, 4, 2, 0xBE, 11);
    ov57_02239868(work->bgConfig, &work->windows[9], 6, 3, 8, 4, 2, 0xC6, 11);
    ov57_02239868(work->bgConfig, &work->windows[10], 6, 10, 8, 4, 2, 0xCE, 11);
    ov57_02239868(work->bgConfig, &work->windows[11], 6, 3, 11, 4, 2, 0xD6, 11);
    ov57_02239868(work->bgConfig, &work->windows[12], 6, 10, 11, 4, 2, 0xDE, 11);
}

void ov57_022399F8(Ov57R7LoopWork *work) {
    int i;
    Window *window;
    u32 seal;

    window = (Window *)((u8 *)work + 0xEC);
    i = 5;
    window = (Window *)((u8 *)window + 0x50);
    for (; i < 13; i++, window++) {
        seal = work->sealIds[i];
        if (seal == 0) {
            FillWindowPixelBuffer(window, 0xEE);
            ScheduleWindowCopyToVram(window);
        } else {
            String *string;
            FillWindowPixelBuffer(window, 0);
            string = String_New(100, (enum HeapID)52);
            String16_FormatInteger(string, SealCaseInventory_GetSealQuantity(work->seals, seal - 1), 3, (PrintingMode)1, TRUE);
            AddTextPrinterParameterizedWithColor(window, (FontID)0, string, 7, 0, 0xFF, 0x00010200, NULL);
            ScheduleWindowCopyToVram(window);
            String_Delete(string);
        }
    }
}

void ov57_02239A8C(Ov57R7Work *work, int index) {
    String *string;
    Window *window;
    u8 seal;

    window = &work->windows[index + 5];
    seal = work->sealIds[index];
    if (seal == 0) {
        FillWindowPixelBuffer(window, 0xEE);
        ScheduleWindowCopyToVram(window);
        return;
    }
    FillWindowPixelBuffer(window, 0);
    string = String_New(100, (enum HeapID)52);
    String16_FormatInteger(string, SealCaseInventory_GetSealQuantity(work->seals, seal - 1), 3, (PrintingMode)1, TRUE);
    AddTextPrinterParameterizedWithColor(window, (FontID)0, string, 7, 0, 0xFF, 0x00010200, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(string);
}

void ov57_02239B0C(void *work) {
    int i;
    Window *window;

    work = (u8 *)work + 0xEC;
    window = work;
    i = 5;
    window = (Window *)((u8 *)window + 0x50);
    for (; i < 13; i++, window++) {
        ClearWindowTilemapAndScheduleTransfer(window);
        RemoveWindow(window);
    }
}

void ov57_02239B2C(Window *window, u32 message) {
    MsgData *msgData;
    String *string;

    if (message == 0xFFFF) {
        FillWindowPixelBuffer(window, 15);
        ScheduleWindowCopyToVram(window);
        return;
    }
    msgData = NewMsgDataFromNarc((MsgDataLoadType)0, (NarcId)27, 15, (enum HeapID)52);
    string = NewString_ReadMsgData(msgData, message);
    FillWindowPixelBuffer(window, 15);
    AddTextPrinterParameterized(window, (FontID)0, string, 0, 0, 0, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(string);
    DestroyMsgData(msgData);
}
