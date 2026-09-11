#include "overlay72_anim_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov72AnimCtl {
    u8 mode;
    u8 state;
    u8 layer;
    u8 timer;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u16 first;
    u16 second;
} Ov72AnimCtl;

void ov72_0223AD20(void *window, void *msgData, int msgNo) {
    void *str = NewString_ReadMsgData(msgData, msgNo);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 4, str, 0, 0, 0, 0xF0200, NULL);
    CopyWindowToVram(window);
    String_Delete(str);
}

void ov72_0223AD64(void *p) {
    int i;
    u8 *window = (u8 *)p + 0x1328;
    for (i = 0; i < 3; i++) {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        window += 0x10;
    }
    RemoveWindow((u8 *)p + 0x1318);
}
