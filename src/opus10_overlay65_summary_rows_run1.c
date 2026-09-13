#include "opus10_overlay65_summary_rows_private.h"

int ov65_0221E740(void *p);
void ov65_0221EC34(void *p);

int ov65_0221E858(void *p) {
    if (!sub_0203A1C4(PTR(p, 4), (u8 *)p + 0x35f8, 0x1a)) {
        sub_02037AC0(0x13);
        ov65_0221FB90((u8 *)p + 0x5b4, 0x1c, 1, U32(p, 0x190), PTR(p, 0x184));
        PTR(p, 0x2220) = ov65_0221E72C;
        return 0;
    }
    PTR(p, 0x3680) = MessageFormat_New(HEAP_ID_26);
    PTR(p, 0x3684) = NewMsgDataFromNarc((MsgDataLoadType)0, (NarcId)0x1b, 0x30b, HEAP_ID_26);
    PTR(p, 0x36a0) = sub_0202C6F4(PTR(p, 4));
    PTR(p, 0x2220) = ov65_0221E740;
    return 0;
}

int ov65_0221E8EC(void *p) {
    if (U32(p, 0x6c) != 0 && U32(p, 0x70) != 0) {
        if (U32(p, 0x6c) == 1 && U32(p, 0x70) == 1) {
            PTR(p, 0x2220) = ov65_0221E858;
        } else {
            PTR(p, 0x2220) = ov65_0221E270;
        }
        U32(p, 0x6c) = 0;
        U32(p, 0x70) = 0;
        U32(p, 0x74) = 0x1d;
    }
    return 0;
}

void *ov65_0221E928(void *p, u32 numWindows, u32 y) {
    TouchscreenListMenuHeader header;
    void *menu;

    PTR(p, 0x36c4) = TouchscreenListMenuSpawner_Create(HEAP_ID_26, NULL);
    MI_CpuFill8(&header, 0, sizeof(header));
    header.template = ov65_0221FD3C;
    header.listMenuItems = PTR(p, 0x668);
    header.bgConfig = PTR(p, 0x180);
    header.numWindows = (u8)numWindows;
    menu = TouchscreenListMenu_Create(PTR(p, 0x36c4), &header, 0, 0x11, (u8)y, 0xd, 0);
    ov65_0221F890();
    return menu;
}

int ov65_0221E9A8(void *p) {
    BufferBoxMonNickname(PTR(p, 0x188), 0, Mon_GetBoxMon(Party_GetMonByIndex(PTR(p, 0x2224), U32(p, 0x94))));
    FillBgTilemapRect(PTR(p, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
    ov65_0221FB90((u8 *)p + 0x5a4, 0x10, 1, U32(p, 0x190), PTR(p, 0x188));
    PTR(p, 0x668) = ListMenuItems_New(3, HEAP_ID_26);
    ListMenuItems_AppendFromMsgData(PTR(p, 0x668), PTR(p, 0x190), 0x11, 0);
    ListMenuItems_AppendFromMsgData(PTR(p, 0x668), PTR(p, 0x190), 0x12, 1);
    ListMenuItems_AppendFromMsgData(PTR(p, 0x668), PTR(p, 0x190), 0x13, 2);
    PTR(p, 0x36c8) = ov65_0221E928(p, 3, 9);
    PTR(p, 0x2220) = ov65_0221EA74;
    return 0;
}

int ov65_0221EA74(void *p) {
    u32 input = TouchscreenListMenu_HandleInput(PTR(p, 0x36c8));

    switch (input) {
    case 0:
        FillBgTilemapRect(PTR(p, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
        ov65_0221FB90((u8 *)p + 0x594, 0xf, 1, U32(p, 0x190), PTR(p, 0x184));
        ov65_0221F4B0(p);
        ListMenuItems_Delete(PTR(p, 0x668));
        PTR(p, 0x2220) = ov65_0221E050;
        return 3;
    case 1:
        FillBgTilemapRect(PTR(p, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
        ov65_0221FB90((u8 *)p + 0x5b4, 0x14, 1, U32(p, 0x190), PTR(p, 0x184));
        ov65_0221F4B0(p);
        ListMenuItems_Delete(PTR(p, 0x668));
        PTR(p, 0x2220) = ov65_0221EB9C;
        break;
    case 2:
    case 0xfffffffe:
        FillBgTilemapRect(PTR(p, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
        ov65_0221FB90((u8 *)p + 0x594, 0xf, 1, U32(p, 0x190), PTR(p, 0x184));
        ov65_0221F4B0(p);
        ListMenuItems_Delete(PTR(p, 0x668));
        PTR(p, 0x2220) = ov65_0221E050;
        break;
    }
    return 0;
}

int ov65_0221EB9C(void *p) {
    FillBgTilemapRect(PTR(p, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
    ov65_0221FB90((u8 *)p + 0x5b4, 0x14, 1, U32(p, 0x190), PTR(p, 0x184));
    ov65_0221DE24(p, 0x18, 2);
    PTR(p, 0x2220) = ov65_0221EBF8;
    return 0;
}

int ov65_0221EBF8(void *p) {
    if (U32(p, 0x6c) != 0 && U32(p, 0x70) != 0) {
        if (U32(p, 0x6c) == 2 && U32(p, 0x70) == 2) {
            PTR(p, 0x2220) = ov65_0221EC34;
        } else {
            PTR(p, 0x2220) = ov65_0221E270;
        }
        U32(p, 0x74) = 0x18;
        U32(p, 0x6c) = 0;
        U32(p, 0x70) = 0;
    }
    return 0;
}
