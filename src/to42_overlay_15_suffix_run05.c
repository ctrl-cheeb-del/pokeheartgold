#include "global.h"

#include "constants/sndseq.h"

#include "bg_window.h"
#include "font.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "player_data.h"
#include "pm_string.h"
#include "render_text.h"
#include "render_window.h"
#include "sprite_system.h"
#include "string_util.h"
#include "text.h"
#include "to42_overlay_15_suffix_private.h"
#include "unk_02005D10.h"
#include "yes_no_prompt.h"

void ov15_021FEA5C(BagWorkRaw *);
void ov15_021FE9F0(BagWorkRaw *, Window *, u16, BOOL);
void ov15_021FEB64(BagWorkRaw *);
void ov15_021FECA0(BagWorkRaw *, Window *, u32);
void ov15_021FECC4(BagWorkRaw *, Window *);
void ov15_021FECD8(BagWorkRaw *, Window *, u32);
void ov15_021FED24(BagWorkRaw *);
void ov15_021FED3C(BagWorkRaw *);
void ov15_021FED58(BagWorkRaw *);
void ov15_021FED60(BagWorkRaw *);
void ov15_021FEDEC(BagWorkRaw *, u32);
u8 ov15_021FEF48(BagWorkRaw *, BOOL);
void ov15_021FEEA4(BagWorkRaw *);
void ov15_021FF058(BagWorkRaw *);
void ov15_021FF004(BagWorkRaw *);
BOOL ov15_021FEFC4(TextPrinterTemplate *, u16);
void ov15_021FF29C(BagWorkRaw *, BOOL);
void ov15_021FF4EC(BagWorkRaw *, s32, s32);
void ov15_021FF1E0(BagWorkRaw *);
void ov15_021FF0FC(BagWorkRaw *, BOOL);
void ov15_021FF068(BagWorkRaw *);
void ov15_021FF560(BagWorkRaw *);
void ov15_021FF6BC(BagWorkRaw *, s32, s32, s32);
void ov15_021FF7AC(Window *);
void ov15_021FF758(Window *, String **, u32);
void ov15_021FF7C4(BagWorkRaw *);
void ov15_021FF7FC(BagWorkRaw *);
void ov15_021FF834(BagWorkRaw *);
void ov15_021FF844(BagWorkRaw *);
void ov15_021FF894(BagWorkRaw *);
void ov15_021FF8D4(BagWorkRaw *);
void ov15_021FF950(BagWorkRaw *);
void ov15_021FF964(BagWorkRaw *);
void ov15_021FFEC0(BagWorkRaw *);
void ov15_021FFECC(BagWorkRaw *, s32);
void ov15_021FFF24(BagWorkRaw *);
void ov15_021FFFDC(BagWorkRaw *, s32);
void ov15_02200030(BagWorkRaw *, s32);
void ov15_02200294(BagWorkRaw *);
void ov15_0220005C(BagWorkRaw *, s32, s32, BOOL);
void ov15_022000F4(BagWorkRaw *);
void ov15_0220023C(BagWorkRaw *, const u8 *);
void ov15_022002B4(BagWorkRaw *, s32);
s32 ov15_022002EC(s32);
void ov15_02200428(BagWorkRaw *);
void ov15_02200458(BagWorkRaw *, BOOL);
void ov15_022004DC(BagWorkRaw *, BOOL);
void ov15_021FF97C(BagWorkRaw *, u16, BOOL);

void ov15_021FF0FC(BagWorkRaw *work, BOOL skipLabel) {
    String *dest = String_New(0x100, HEAP_ID_6);
    Window *window = (Window *)&work->raw[0x214];
    if (skipLabel == FALSE) {
        FillWindowPixelBuffer(window, 0);
        String *label = NewString_ReadMsgData(*(MsgData **)&work->raw[0x2F0], 0x50);
        AddTextPrinterParameterizedWithColor(window, 0, label, 4, 0, 0xFF, 0x00010200, NULL);
        String_Delete(label);
    } else {
        FillWindowPixelRect(window, 0, 0, 0x10, 0x48, 0x10);
    }
    String *source = NewString_ReadMsgData(*(MsgData **)&work->raw[0x2F0], 0x51);
    u32 money = PlayerProfile_GetMoney(*(PlayerProfile **)&work->raw[0x23C]);
    BufferIntegerAsString(*(MessageFormat **)&work->raw[0x2F4], 0, money, 6, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    StringExpandPlaceholders(*(MessageFormat **)&work->raw[0x2F4], dest, source);
    u32 width = FontID_String_GetWidth(0, dest, 0);
    AddTextPrinterParameterizedWithColor(window, 0, dest, 0x44 - (width + 8), 0x10, 0xFF, 0x00010200, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(source);
    String_Delete(dest);
}

void ov15_021FF1E0(BagWorkRaw *work) {
    Window *window = (Window *)&work->raw[0x54];
    FillWindowPixelBuffer(window, 0xF);
    DrawFrameAndWindow1(window, TRUE, 0x3F7, 0xE);
    String *string = NewString_ReadMsgData(*(MsgData **)&work->raw[0x2F0], 0x73);
    AddTextPrinterParameterized(window, 0, string, 0, 0, 0xFF, NULL);
    String_Delete(string);
    string = NewString_ReadMsgData(*(MsgData **)&work->raw[0x2F0], 0x74);
    BufferIntegerAsString(*(MessageFormat **)&work->raw[0x2F4], 0, 0, 3, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    StringExpandPlaceholders(*(MessageFormat **)&work->raw[0x2F4], *(String **)&work->raw[0x5E4], string);
    String_Delete(string);
    u32 width = FontID_String_GetWidth(0, *(String **)&work->raw[0x5E4], 0);
    AddTextPrinterParameterized(window, 0, *(String **)&work->raw[0x5E4], 0x58 - width, 0x10, 0xFF, NULL);
    ScheduleWindowCopyToVram(window);
}

void ov15_021FF29C(BagWorkRaw *work, BOOL left) {
    String *string = NewString_ReadMsgData(*(MsgData **)&work->raw[0x2F0], 8);
    FillWindowPixelBuffer((Window *)&work->raw[0x74], 0);
    if (left == FALSE) {
        u32 width = FontID_String_GetWidth(0, string, 0);
        AddTextPrinterParameterizedWithColor((Window *)&work->raw[0x74], 0, string, ((0x30 - width) / 2) + 8, 0, 0xFF, 0x000F0E00, NULL);
    } else {
        AddTextPrinterParameterizedWithColor((Window *)&work->raw[0x74], 0, string, 5, 0, 0xFF, 0x000F0E00, NULL);
    }
    ScheduleWindowCopyToVram((Window *)&work->raw[0x74]);
    String_Delete(string);
}
