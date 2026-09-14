#include "font.h"
#include "msgdata.h"
#include "text.h"
#include "to46_overlay88_r9_private.h"

void ov88_0225967C(void *work, BgConfig **bgConfig, enum HeapID heapId) {
    int messageNo;
    MsgData *msgData;
    String *message;
    u32 lineCount;
    int x;
    void *const *data;
    const u16 *messageIds;
    Ov88TextEntry *entry;
    Window *window;
    String *line;
    const Ov88TextWindowConfig *config;

    memset(work, 0, 0x70);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, (NarcId)0x1B, 0x2F5, heapId);
    message = String_New(0x80, heapId);
    messageNo = 0;
    data = ov88_02259A68;
    config = ov88_02259980;
    messageIds = _02259A60;
    window = work;
    entry = (Ov88TextEntry *)((u8 *)work + 0x40);

    do {
        u32 i;
        int y;

        ov88_0225983C(entry, *messageIds, *data);
        AddWindowParameterized(*bgConfig, window, 0, config->left, config->top, config->width, config->height, config->palette, config->baseTile);
        FillWindowPixelBuffer(window, 0);
        ReadMsgDataIntoString(msgData, messageNo, message);
        lineCount = String_CountLines(message);
        y = config->y;
        line = String_New(String_GetLength(message) + 1, heapId);
        for (i = 0; i < lineCount; i++) {
            String_GetLineN(line, message, i);
            switch (config->alignment) {
            case 0:
                x = config->x;
                break;
            case 1:
                x = config->x - ((FontID_String_GetWidthMultiline(0, line, 0) + 1) >> 1);
                break;
            case 2:
                x = config->x - FontID_String_GetWidthMultiline(0, line, 0);
                break;
            default:
                break;
            }
            AddTextPrinterParameterizedWithColor(window, 0, line, x, y, 0xFF, config->color, NULL);
            y += 0x10;
        }
        String_Delete(line);
        ScheduleWindowCopyToVram(window);
        data++;
        config++;
        messageIds++;
        entry++;
        window++;
        messageNo++;
    } while (messageNo < 4);

    String_Delete(message);
    DestroyMsgData(msgData);
}

void ov88_022597DC(void *work) {
    Window *window;
    Ov88TextEntry *entry;
    int i;

    window = work;
    entry = (Ov88TextEntry *)work;
    i = 0;
    entry = (Ov88TextEntry *)((u8 *)entry + 0x40);
    do {
        RemoveWindow(window);
        ov88_0225985C(entry);
        i++;
        window++;
        entry++;
    } while (i < 4);
}

void ov88_02259800(void *work) {
    int i;
    Ov88TextEntry *entry;

    entry = (Ov88TextEntry *)work;
    i = 0;
    entry = (Ov88TextEntry *)((u8 *)entry + 0x40);
    do {
        ov88_02259884(entry);
        i++;
        entry++;
    } while (i < 4);
}
