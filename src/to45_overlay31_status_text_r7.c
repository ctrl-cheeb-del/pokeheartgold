#include "global.h"

#include "pokeathlon/pokeathlon_save.h"

#include "bg_window.h"
#include "font.h"
#include "msgdata.h"
#include "player_data.h"
#include "text.h"

typedef struct Ov31BgOp {
    u8 kind, x, y, unk3, width, height, value, pad;
} Ov31BgOp;

extern const Ov31BgOp ov31_0225EF48[][4];

void ov31_0225DE24(MessageFormat *format, MsgData *msgData, Window *window, s32 value, int kind);
void ov31_0225DE84(void *work);
void ov31_0225DF98(void *work);
void ov31_0225E060(BgConfig *bgConfig, int bgId, int screen);

void ov31_0225DE24(MessageFormat *format, MsgData *msgData, Window *window, s32 value, int kind) {
    int msgId = 0x12;
    String *string;
    if ((u32)(kind - 3) <= 1) {
        msgId = 0x13;
    }
    BufferIntegerAsString(format, 0, value, 4, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(format, msgData, msgId, HEAP_ID_8);
    AddTextPrinterParameterizedWithColor(window, 0, string, 0x24, 0x10, 0xff, 0x00010200, NULL);
    String_Delete(string);
}

void ov31_0225DE84(void *work) {
    u8 *w = work;
    String *label;
    String *value;
    String *expanded;
    u32 amount;
    int width;
    FillWindowPixelBuffer((Window *)(w + 0x74), 0);
    {
        u8 type = (*(u8 **)(w + 0x14))[0x283];
        type += 0xfd;
        if (type <= 1) {
            label = NewString_ReadMsgData(*(MsgData **)(w + 0x158), 0x21);
        } else {
            label = NewString_ReadMsgData(*(MsgData **)(w + 0x158), 0x1e);
        }
    }
    AddTextPrinterParameterizedWithColor((Window *)(w + 0x74), 0, label, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(label);
    expanded = String_New(0x10, HEAP_ID_FIELD2);
    {
        u8 type = (*(u8 **)(w + 0x14))[0x283];
        type += 0xfd;
        if (type <= 1) {
            value = NewString_ReadMsgData(*(MsgData **)(w + 0x158), 0x20);
            amount = PokeathlonSave_GetAthletePoints(*(PokeathlonSave **)(w + 0x16c));
        } else {
            value = NewString_ReadMsgData(*(MsgData **)(w + 0x158), 0x1f);
            amount = PlayerProfile_GetMoney(*(PlayerProfile **)(w + 0x168));
        }
    }
    BufferIntegerAsString(*(MessageFormat **)(w + 0x154), 0, amount, 6, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    StringExpandPlaceholders(*(MessageFormat **)(w + 0x154), expanded, value);
    width = FontID_String_GetWidth(0, expanded, 0);
    AddTextPrinterParameterizedWithColor((Window *)(w + 0x74), 0, expanded, 0x48 - width, 0x10, 0xff, 0x000f0e00, NULL);
    String_Delete(value);
    String_Delete(expanded);
    ScheduleWindowCopyToVram((Window *)(w + 0x74));
}

void ov31_0225DF98(void *work) {
    u8 *w = work;
    u8 *args;
    String *expanded;
    String *formatString;
    int first;
    int second;
    int raw;
    FillWindowPixelBuffer((Window *)(w + 0x54), 0);
    expanded = String_New(6, HEAP_ID_FIELD2);
    formatString = NewString_ReadMsgData(*(MsgData **)(w + 0x158), 0x2b);
    args = *(u8 **)(w + 0x14);
    first = (args[0x271] + 6) / 6;
    raw = args[0x270];
    second = raw / 6;
    if (raw % 6 != 0) {
        second++;
    }
    BufferIntegerAsString(*(MessageFormat **)(w + 0x154), 0, first, 2, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    BufferIntegerAsString(*(MessageFormat **)(w + 0x154), 1, second, 2, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    StringExpandPlaceholders(*(MessageFormat **)(w + 0x154), expanded, formatString);
    AddTextPrinterParameterizedWithColor((Window *)(w + 0x54), 0, expanded, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(formatString);
    String_Delete(expanded);
    ScheduleWindowCopyToVram((Window *)(w + 0x54));
}

void ov31_0225E060(BgConfig *bgConfig, int bgId, int screen) {
    void *tilemap = GetBgTilemapBuffer(bgConfig, (u8)bgId);
    int i;
    const Ov31BgOp *op;
    if (screen == 6) {
        return;
    }
    op = ov31_0225EF48[screen];
    for (i = 0; i < 4; i++, op++) {
        if (op->kind == 1) {
            LoadRectToBgTilemapRect(bgConfig, (u8)bgId, (u8 *)tilemap + (op->x + op->y * 32) * 2, op->unk3, op->width, op->height, op->value);
        } else if (op->kind == 2) {
            FillBgTilemapRect(bgConfig, (u8)bgId, 0, op->unk3, op->width, op->height, op->value, 0);
        }
    }
}
