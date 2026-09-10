#include "field_save_stats_printer_internal.h"

void Field_SaveStatsPrinter_Print(struct SaveStatsPrinter *printer) {
    printer->window = Heap_Alloc(printer->heapId, sizeof(Window));
    AddWindowParameterized(printer->bgConfig, printer->window, printer->bgId, 1, 1, printer->width, printer->height, 0xD, 0x189);
    LoadUserFrameGfx1(printer->bgConfig, (GFBgLayer)printer->bgId, 0x3D9, 0xB, 0, printer->heapId);
    FillWindowPixelBuffer(printer->window, GetFontAttribute(0, 6));
    ov01_021F4048(printer);
    DrawFrameAndWindow1(printer->window, FALSE, 0x3D9, 0xB);
}

void Field_SaveStatsPrinter_RemoveFromScreen(struct SaveStatsPrinter *printer) {
    sub_0200E5D4(printer->window, FALSE);
    RemoveWindow(printer->window);
    Heap_Free(printer->window);
}

struct SaveStatsPrinter *Field_SaveStatsPrinter_New(FieldSystem *fieldSystem, enum HeapID heapId, int bgId) {
    struct SaveStatsPrinter *printer = Heap_Alloc(heapId, sizeof(struct SaveStatsPrinter));

    printer->fieldSystem = fieldSystem;
    printer->heapId = heapId;
    printer->bgId = bgId;
    printer->bgConfig = fieldSystem->bgConfig;
    printer->msgFmt = MessageFormat_New(heapId);
    printer->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 0x1A7, heapId);
    ov01_021F3F50(&printer->stats, printer->fieldSystem);
    ov01_021F3F9C(printer->msgFmt, &printer->stats);
    printer->width = 0xD;
    printer->height = ov01_021F4044(&printer->stats);
    return printer;
}

void Field_SaveStatsPrinter_Delete(struct SaveStatsPrinter *printer) {
    DestroyMsgData(printer->msgData);
    MessageFormat_Delete(printer->msgFmt);
    Heap_Free(printer);
}

int ov01_021F4234(Window *window, String *str, int align, int fontId) {
    int x = 0;

    switch (align) {
    case 1:
        x = window->width * 8 - FontID_String_GetWidth(fontId, str, 0);
        break;
    case 2:
        x = (int)(window->width * 8 - FontID_String_GetWidth(fontId, str, 0)) / 2;
        break;
    }
    return x;
}

void ov01_021F426C(struct SaveStatsPrinter *printer) {
    String *str;
    u32 i;
    int lineHeight;
    const struct SaveStatsRow *row;

    lineHeight = GetFontAttribute(0, 1) + GetFontAttribute(0, 3);
    row = sStatRows;
    for (i = 0; i < 9; i++, row++) {
        if (printer->stats.dexOwned == 0 && (row->msgId == 0xB || row->msgId == 7)) {
            continue;
        }
        str = ReadMsgData_ExpandPlaceholders(printer->msgFmt, printer->msgData, row->msgId, printer->heapId);
        AddTextPrinterParameterizedWithColor(printer->window, 0, str, ov01_021F4234(printer->window, str, row->align, 0), lineHeight * row->row, 0, sTextColors[row->color], NULL);
        String_Delete(str);
    }
}

void ov01_021F42F8(UnkStruct_field_021F4360 *a0) {
    struct SaveStatsPrinter *printer = (struct SaveStatsPrinter *)a0;
    printer->window = Heap_Alloc(printer->heapId, sizeof(Window));
    AddWindowParameterized(printer->bgConfig, printer->window, printer->bgId, 7, 2, printer->width, printer->height, 4, 0x10B);
    FillWindowPixelBuffer(printer->window, 0);
    ov01_021F426C(printer);
    CopyWindowToVram(printer->window);
}

void ov01_021F434C(UnkStruct_field_021F4360 *a0) {
    struct SaveStatsPrinter *printer = (struct SaveStatsPrinter *)a0;
    RemoveWindow(printer->window);
    Heap_Free(printer->window);
}

UnkStruct_field_021F4360 *ov01_021F4360(FieldSystem *fieldSystem, enum HeapID heapID, u8 a2) {
    struct SaveStatsPrinter *printer = Heap_Alloc(heapID, sizeof(struct SaveStatsPrinter));

    printer->fieldSystem = fieldSystem;
    printer->heapId = heapID;
    printer->bgId = a2;
    printer->bgConfig = fieldSystem->bgConfig;
    printer->msgFmt = MessageFormat_New(heapID);
    printer->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 0x1A7, heapID);
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    ov01_021F3F50(&printer->stats, printer->fieldSystem);
    ov01_021F3F9C(printer->msgFmt, &printer->stats);
    printer->width = 0x13;
    printer->height = ov01_021F4044(&printer->stats);
    return (UnkStruct_field_021F4360 *)printer;
}

void ov01_021F43D0(UnkStruct_field_021F4360 *a0) {
    struct SaveStatsPrinter *printer = (struct SaveStatsPrinter *)a0;
    DestroyMsgData(printer->msgData);
    MessageFormat_Delete(printer->msgFmt);
    Heap_Free(printer);
}

int Field_SaveGameNormal(FieldSystem *fieldSystem) {
    ov01_021F4404(fieldSystem);
    if (SaveGameNormal(fieldSystem->saveData) == 2) {
        return TRUE;
    }
    return FALSE;
}

void ov01_021F4404(FieldSystem *fieldSystem) {
    FieldSystem_SyncMapObjectsToSave(fieldSystem);
    ov01_021F6830(fieldSystem, 4, 0);
    fieldSystem->location->x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    fieldSystem->location->y = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    fieldSystem->location->warpId = -1;
    fieldSystem->location->direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
}

void ov01_021F4440(FieldSystem *fieldSystem) {
    if (fieldSystem == NULL) {
        GF_AssertFail();
        return;
    }
    if (fieldSystem->location->mapId != MAP_UNION
        && fieldSystem->location->mapId != MAP_WIFI_SINGLE_BATTLE_AREA
        && fieldSystem->location->mapId != MAP_WIFI_MULTI_BATTLE_AREA) {
        ov01_021F4404(fieldSystem);
    }
}
