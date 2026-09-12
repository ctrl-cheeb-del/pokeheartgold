#include "overlay70_ui_render_residual26_7_private.h"

void ov70_0223F38C(void *dst, void *msgData, int index, int a3, int a4, int a5, int a6, int useAlt) {
    const Ov70MsgEntry26 *table;
    String *str;
    if (index != -1) {
        table = useAlt == 0 ? ov70_02245A4C : ov70_022459F4;
        str = NewString_ReadMsgData(msgData, table[index].msgId);
        ov70_02245084(dst, str, a4, a5, a3, a6);
        String_Delete(str);
    }
}

void ov70_0223F3D8(void *msgData, void *arg1, void *unused, void *windows, int a4, int a5, int a6) {
    String *header;
    int i;
    u8 *window;

    header = NewString_ReadMsgData(msgData, 0x65);
    ov70_02245084(windows, header, 0, 0, 0, 0xF0200);
    window = windows;
    i = 1;
    window += 0x10;
    do {
        FillWindowPixelBuffer((Window *)window, 0);
        i++;
        window += 0x10;
    } while (i < 3);
    ov70_0223F1D8((u8 *)windows + 0x10, arg1, a4, 0, 0, 0x10200);
    if ((u32)(a5 - 1) <= 1) {
        ov70_0223F2BC((u8 *)windows + 0x10, msgData, a5, 0, 0, 0x46, 0x10200);
    }
    ov70_0223F370((u8 *)windows + 0x20, msgData, a6, 2, 0, 0x10200, 0);
    String_Delete(header);
}

void ov70_0223F470(void *msgData, void *arg1, void *unused, void *windows, int a4, int a5, int a6) {
    String *header;
    int i;
    u8 *window;

    header = NewString_ReadMsgData(msgData, 0x65);
    ov70_02245084(windows, header, 0, 0, 0, 0xF0200);
    window = windows;
    i = 1;
    window += 0x10;
    do {
        FillWindowPixelBuffer((Window *)window, 0);
        i++;
        window += 0x10;
    } while (i < 3);
    ov70_0223F1D8((u8 *)windows + 0x10, arg1, a4, 0, 0, 0x10200);
    if ((u32)(a5 - 1) <= 1) {
        ov70_0223F2BC((u8 *)windows + 0x10, msgData, a5, 0, 0, 0x46, 0x10200);
    }
    ov70_0223F370((u8 *)windows + 0x20, msgData, a6, 0, 0, 0x10200, 0);
    String_Delete(header);
}
