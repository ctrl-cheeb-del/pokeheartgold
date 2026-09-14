#include "to47_overlay83_menu_builders_private.h"

void ov83_022469E4(void *p, u8 count, int c, int d, u8 e) {
    Ov83MenuRect rect;
    Ov83MenuTemplate tmpl;
    u16 y, x;
    int n;

    ov83_02247988(&y, &x);
    rect = *(const Ov83MenuRect *)&ov83_02248018[0];
    rect.d = y;
    rect.e = y + x - 0x1B;
    rect.f = x;
    tmpl.rect = rect;
    tmpl.items = *(ListMenuItem **)((u8 *)p + 0x5FC);
    tmpl.msgData = *(MsgData **)((u8 *)p + 0x4C);
    tmpl.count = count;
    *(void **)((u8 *)p + 0x5F8) = ov83_02247CCC(*(void **)((u8 *)p + 0x5F4), &tmpl.rect, c, d, e);
    ((u8 *)p)[0xF] |= 4;
    n = ov80_02237B24(((u8 *)p)[9], 1);
    ov83_0224773C((Ov83SpriteWrap **)((u8 *)p + 0x4E4), n, 1);
    ov83_0224773C((Ov83SpriteWrap **)((u8 *)p + 0x4F4), n, 1);
}

void ov83_02246AA4(u8 *p) {
    u16 count;
    u8 mode;
    int index;

    count = 0;
    *(ListMenuItem **)(p + 0x5FC) = ListMenuItems_New(4, HEAP_ID_107);
    mode = ov83_0224777C(*(void **)(p + 0x2BC), p[9], 2);
    index = ov83_02247768(p[0x14], p[0xD]);
    if ((*(u8 **)(p + 0x54C))[index] == 0) {
        ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 8, 0);
        count++;
    }
    ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 9, 1);
    count++;
    if ((*(u8 **)(p + 0x554))[index] == 0 || (*(u8 **)(p + 0x558))[index] == 0 || mode != 2) {
        ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 0xA, 2);
        count++;
    }
    ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 0xB, LIST_CANCEL);
    count++;
    ov83_022469E4(p, count, 0x11, ov83_02248010[count], 0xD);
}

void ov83_02246B6C(u8 *p) {
    u16 count;
    u8 mode;
    int index;

    count = 0;
    *(ListMenuItem **)(p + 0x5FC) = ListMenuItems_New(4, HEAP_ID_107);
    mode = ov83_0224777C(*(void **)(p + 0x2BC), p[9], 2);
    index = ov83_02247768(p[0x14], p[0xD]);
    if ((*(u8 **)(p + 0x554))[index] == 0) {
        ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 0x21, 3);
        count++;
    }
    if (mode != 1 && (*(u8 **)(p + 0x558))[index] == 0) {
        ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 0x22, 4);
        count++;
    }
    if (mode != 2) {
        ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 0x23, 5);
        count++;
    }
    ListMenuItems_AppendFromMsgData(*(ListMenuItem **)(p + 0x5FC), *(MsgData **)(p + 0x20), 0x24, LIST_CANCEL);
    count++;
    ov83_022469E4(p, count, 0x11, ov83_02248010[count], 0xD);
}
