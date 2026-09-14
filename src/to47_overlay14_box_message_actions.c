#include "to47_overlay14_box_message_actions_private.h"

void ov14_021F685C(void *p, u32 a, u32 kind, u32 v) {
    u32 id;

    switch (kind) {
    case 0:
        id = 0x12;
        break;
    case 1:
        id = 0;
        BufferBoxMonNickname(PTR_AT(PTR_AT(p, 0x34), 0x24), 0, ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21)));
        break;
    case 2:
        id = 5;
        break;
    case 3:
        id = 0x13;
        break;
    case 4:
        id = 0xd;
        break;
    case 5:
        id = 0x1d;
        break;
    case 6:
        id = 0x1e;
        break;
    }

    ov14_021F6698(p, id, v);
}

void ov14_021F68C0(void *p, u32 kind, u32 v) {
    u32 id;

    switch (kind) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        id = 0x1a;
        BufferItemName(PTR_AT(PTR_AT(p, 0x34), 0x24), 0, U16_AT(PTR_AT(p, 0x34), 0x88c8));
        break;
    case 3:
        id = 0x1b;
        BufferItemName(PTR_AT(PTR_AT(p, 0x34), 0x24), 0, U16_AT(PTR_AT(p, 0x34), 0x88c8));
        break;
    case 4:
        id = 0x18;
        break;
    case 5:
        id = 0x22;
        break;
    case 6:
        id = 0xe;
        break;
    case 7:
        id = 0x3b;
        break;
    }

    ov14_021F6698(p, id, v);
}

void ov14_021F6928(void *p, u32 idx, u32 kind) {
    void *msgData = ov14_021F6628();
    void *str;

    switch (kind) {
    case 0:
        kind = 0x24;
        break;
    case 1:
        kind = 0x25;
        break;
    case 2:
        kind = 0x26;
        break;
    case 3:
        kind = 0x27;
        break;
    case 4:
        kind = 0x1c;
        break;
    case 5:
        kind = 0x19;
        BufferItemName(PTR_AT(PTR_AT(p, 0x34), 0x24), 0, U16_AT(PTR_AT(p, 0x34), 0x88c8));
        break;
    case 6:
        kind = 0x38;
        break;
    case 7:
        kind = 0x39;
        break;
    case 8:
        kind = 0x3a;
        break;
    case 9:
        kind = 0x3b;
        break;
    case 10:
        kind = 0x3c;
        break;
    }

    str = NewString_ReadMsgData(msgData, kind);
    StringExpandPlaceholders(PTR_AT(PTR_AT(p, 0x34), 0x24), PTR_AT(PTR_AT(p, 0x34), 0x28), str);
    String_Delete(str);
    FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + idx * 16, 0xf);
    AddTextPrinterParameterizedWithColor((u8 *)PTR_AT(p, 0x34) + 0x30 + idx * 16, 1, PTR_AT(PTR_AT(p, 0x34), 0x28), 0, 0, 0xff, 0x1020f, NULL);
    DestroyMsgData(msgData);
}
