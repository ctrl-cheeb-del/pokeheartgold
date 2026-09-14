#include "to45_overlay65_r11_private.h"

void ov65_0221F0D8(void *arg, u32 row, u32 message) {
    u8 *work = arg;
    FillBgTilemapRect(PTR_AT(work, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
    ov65_0221FB90(work + 0x444 + row * 0x10, message, 1, U32_AT(work, 0x190), PTR_AT(work, 0x184));
}

u32 ov65_0221F120(void *arg) {
    u8 *work = arg;
    u32 result = ov65_0221FC54(PTR_AT(work, 0x180), work + 0x664, work + 0x670, work + 0x36c0, 0);

    switch (result) {
    case 1:
    case 3:
        if (ov65_0221F79C(work)) {
            switch (ov65_0221F7E0(work)) {
            case 0:
                if (U32_AT(work, 0x6a8 + U32_AT(work, 0x94) * 0x10) == 0) {
                    ov65_0221F0C4(work);
                    ov65_0221F0D8(work, 0x17, 0x14);
                    PTR_AT(work, 0x2220) = ov65_0221F354;
                } else {
                    PTR_AT(work, 0x2220) = ov65_0221F258;
                }
                break;
            case 1:
                ov65_0221F0D8(work, 0x17, 0x25);
                PTR_AT(work, 0x2220) = ov65_0221F354;
                ov65_0221DE24(work, 0x18, 4);
                break;
            case 2:
                ov65_0221F0D8(work, 0x17, 0x26);
                PTR_AT(work, 0x2220) = ov65_0221F354;
                ov65_0221DE24(work, 0x18, 4);
                break;
            }
        } else {
            PTR_AT(work, 0x2220) = ov65_0221F354;
            ov65_0221DE24(work, 0x18, 4);
        }
        break;
    case 2:
    case 4:
        FillBgTilemapRect(PTR_AT(work, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
        ov65_0221FB90(work + 0x5b4, 0x14, 1, U32_AT(work, 0x190), PTR_AT(work, 0x184));
        PTR_AT(work, 0x2220) = ov65_0221F354;
        ov65_0221DE24(work, 0x18, 4);
        break;
    }
    return 0;
}

u32 ov65_0221F258(void *arg) {
    u8 *work = arg;
    FillBgTilemapRect(PTR_AT(work, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
    ov65_0221FB90(work + 0x5b4, 0x24, 1, U32_AT(work, 0x190), PTR_AT(work, 0x188));
    PTR_AT(work, 0x2220) = ov65_0221F2A8;
    return 0;
}

u32 ov65_0221F2A8(void *arg) {
    u8 *work = arg;
    u32 result = ov65_0221FC54(PTR_AT(work, 0x180), work + 0x664, work + 0x670, work + 0x36c0, 0);

    switch (result) {
    case 1:
    case 3:
        ov65_0221F0C4(work);
        ov65_0221F0D8(work, 0x17, 0x14);
        PTR_AT(work, 0x2220) = ov65_0221F354;
        break;
    case 2:
    case 4:
        FillBgTilemapRect(PTR_AT(work, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
        ov65_0221FB90(work + 0x5b4, 0x14, 1, U32_AT(work, 0x190), PTR_AT(work, 0x184));
        PTR_AT(work, 0x2220) = ov65_0221F354;
        ov65_0221DE24(work, 0x18, 4);
        break;
    }
    return 0;
}

u32 ov65_0221F354(void *arg) {
    u8 *work = arg;
    if (U32_AT(work, 0x6c) != 0 && U32_AT(work, 0x70) != 0) {
        if (U32_AT(work, 0x6c) == 3 && U32_AT(work, 0x70) == 3) {
            U32_AT(work, 0x36a4)
            ++;
            PTR_AT(work, 0x2220) = ov65_0221F3B0;
        } else {
            PTR_AT(work, 0x2220) = ov65_0221E270;
        }
        U32_AT(work, 0x6c) = 0;
        U32_AT(work, 0x70) = 0;
        if (ov65_0221F79C(work)) {
            U32_AT(work, 0x74) = 0x18;
        } else {
            U32_AT(work, 0x74) = 0x22;
        }
    }
    return 0;
}

u32 ov65_0221F3B0(void *arg) {
    u8 *work = arg;
    sub_02034AEC(PTR_AT(work, 4), 1);
    ov65_0221F5A0(PTR_AT(work, 0x2224), PTR_AT(work, 0x2228), U32_AT(work, 0x94), U32_AT(work, 0x98) - 6, PTR_AT(work, 8));
    PTR_AT(work, 0x2220) = ov65_0221E270;
    return 2;
}

u32 ov65_0221F3F4(void *arg) {
    u8 *work = arg;
    void *mon = Party_GetMonByIndex(PTR_AT(work, 0x2228), U32_AT(work, 0x94) - 6);
    BufferBoxMonNickname(PTR_AT(work, 0x188), 0, Mon_GetBoxMon(mon));
    FillBgTilemapRect(PTR_AT(work, 0x180), 0, 0, 0, 0, 0x20, 0x18, 0);
    ov65_0221FB90(work + 0x5a4, 0x10, 1, U32_AT(work, 0x190), PTR_AT(work, 0x188));
    PTR_AT(work, 0x668) = ListMenuItems_New(2, 0x1a);
    ListMenuItems_AppendFromMsgData(PTR_AT(work, 0x668), PTR_AT(work, 0x190), 0x11, 0);
    ListMenuItems_AppendFromMsgData(PTR_AT(work, 0x668), PTR_AT(work, 0x190), 0x13, 1);
    PTR_AT(work, 0x36c8) = ov65_0221E928(work, 2, 0xc);
    PTR_AT(work, 0x2220) = ov65_0221F4D4;
    return 0;
}
