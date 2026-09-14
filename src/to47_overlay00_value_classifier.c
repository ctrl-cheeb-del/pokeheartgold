#include "to47_overlay00_value_classifier_private.h"

s32 ov00_021E6A70(s32 value, u32 kind) {
    s32 hundreds = value / 100;
    s32 thousands = value / 1000;

    if (value == 0x4e85) {
        return 1;
    }
    if (thousands == 0x17) {
        return 1;
    }
    if (value == 0x4e8c) {
        return 2;
    }
    if (value == 0x4e8e) {
        return 3;
    }
    if (hundreds == 0x200) {
        return 4;
    }
    if (hundreds == 0x1f4) {
        return 5;
    }
    if (value == 0xc79f) {
        return 7;
    }
    if (hundreds == 0x1fe) {
        return 6;
    }
    if (hundreds == 0x1ff) {
        return 6;
    }
    if (hundreds == 0x201) {
        return 6;
    }
    if (value >= 0xcb20 && value <= 0xcb23) {
        return 8;
    }
    if (value >= 0xcb84 && value <= 0xcb87) {
        return 8;
    }
    if (value >= 0xcbe8 && value <= 0xcbeb) {
        return 8;
    }
    if (value == 0x13a2e) {
        return 9;
    }
    if (thousands == 0x14) {
        return 0;
    }
    if (hundreds == 0x208) {
        return 0;
    }
    if (hundreds == 0x209) {
        return 0;
    }
    if (hundreds == 0x20a) {
        return 0;
    }
    if (hundreds == 0x20b) {
        return 0;
    }
    if (hundreds == 0x212) {
        return 0;
    }
    if (hundreds == 0x213) {
        return 0;
    }
    if (hundreds == 0x214) {
        return 0;
    }
    if (value < 0x2710) {
        return 0xe;
    }
    if (thousands == 0x1f) {
        return 0xc;
    }
    switch (kind) {
    case 0:
    case 1:
    case 2:
        return 0xb;
    case 3:
    case 4:
    case 5:
    case 6:
        return 0xa;
    default:
        GF_AssertFail();
        break;
    case 7:
        return 0xf;
    }
    return -1;
}

int ov00_021E6BE4(int checkOnly) {
    if (checkOnly == 0) {
        switch (_0221A680->unk_1070) {
        case 5:
        case 7:
        case 8:
            if (_0221A680->unk_1090 != 0) {
                ov00_021E79CC((void *)_0221A680->unk_1090);
            }
            _0221A680->unk_1070 = 16;
            break;
        case 4:
        case 14:
        case 17:
        case 18:
            return 1;
        }
    } else {
        switch (_0221A680->unk_1070) {
        case 4:
        case 17:
        case 18:
            return 1;
        }
    }
    return 0;
}

int ov00_021E6C68(void) {
    if (_0221A680->unk_1070 == 17 || _0221A680->unk_1070 == 18 || _0221A680->unk_1070 == 4) {
        _0221A680->unk_1070 = 4;
        _0221A680->unk_1098 = -1;
        ov00_021E7130();
        return 1;
    }
    return 0;
}
