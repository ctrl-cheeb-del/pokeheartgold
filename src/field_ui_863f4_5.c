#include "field_ui_863f4_internal.h"

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define S32(s, off)       (*(int *)&(s)->raw[(off)])
#define S16(s, off)       (*(s16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])

void sub_020871C4(void *bgConfig, Window *window, int x, int y, int width, int height, int palette, int baseTile, int msg) {
    InitWindow(window);
    AddWindowParameterized(bgConfig, window, (u8)x, (u8)y, (u8)width, (u8)height, palette, 12, (u16)baseTile);
    DrawFrameAndWindow2(window, 1, 1, 11);
    FillWindowPixelBuffer(window, 15);
    CopyWindowToVram(window);
    sub_02087230(window, msg);
}

void sub_02087230(Window *window, int msgNo) {
    MsgData *msgData;
    String *string;
    FillWindowPixelBuffer(window, 15);
    msgData = NewMsgDataFromNarc(0, 0x1b, 0x26, 0x6c);
    string = NewString_ReadMsgData(msgData, msgNo);
    FillWindowPixelBuffer(window, 15);
    AddTextPrinterParameterized(window, 1, string, 0, 0, 0, 0);
    CopyWindowToVram(window);
    String_Delete(string);
    DestroyMsgData(msgData);
}
