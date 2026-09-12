#include "overlay70_network_state_44_private.h"

int ov70_02244954(Ov70Work *work) {
    int a;
    int b;
    int result;

    switch (ov00_021ECDC8()) {
    case 3:
        U32(work, 0x2c) = 6;
        break;
    case 0:
    case 4:
    case 5:
        ov70_02238F80(work);
        result = ov00_021EC11C(&a, &b);
        U32(work, 0x40) = result;
        S32(work, 0x44) = a;
        ov00_021EC210();
        ov00_021EC8D8();
        U32(work, 0x2c) = 0x17;
        switch (b) {
        case 1:
        case 2:
            U32(work, 0x2c) = 0x17;
            break;
        case 4:
            ov00_021FA0D8();
            U32(work, 0x2c) = 0x17;
            break;
        case 6:
            U32(work, 0x2c) = 0x17;
            break;
        case 3:
            ov00_021ED9B4();
            U32(work, 0x2c) = 0x17;
            break;
        case 5:
        case 7:
            sub_020399EC();
            break;
        }
        if (a < -20000 && a >= -29999) {
            U32(work, 0x2c) = 0x17;
        }
        break;
    }
    return 3;
}

int ov70_02244A04(Ov70Work *work) {
    u32 id;
    u32 profileId;

    id = sub_0202C08C(PTR(PTR(work, 0), 0x14));
    if (Save_SysInfo_GetDwcProfileId(PTR(PTR(work, 0), 4)) == 0) {
        Save_SysInfo_SetDwcProfileId(PTR(PTR(work, 0), 4), U32(PTR(work, 0), 0x34));
    }
    profileId = Save_SysInfo_GetDwcProfileId(PTR(PTR(work, 0), 4));
    {
        u64 key = DWC_CreateFriendKey(id);
        ov70_022378C0(profileId, (u32)key, (u32)(key >> 32));
    }
    U32(work, 0x2c) = 7;
    return 3;
}

int ov70_02244A4C(Ov70Work *work) {
    ov70_022382C0(work);
    U32(work, 0x2c) = 8;
    U32(work, 0x1604) = 0;
    return 3;
}

int ov70_02244A68(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        U32(work, 0x1604) = 0;
        switch (result + 15) {
        case 15:
            U32(work, 0x2c) = 9;
            break;
        case 16:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        case 14:
        case 17:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        case 0:
        case 3:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        case 1:
        case 13:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        default:
            ov70_02238F80(work);
            sub_020399EC();
            break;
        }
    } else {
        U32(work, 0x1604)
        ++;
        if (U32(work, 0x1604) == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_02244B20(Ov70Work *work) {
    sub_0203189C(PTR(PTR(work, 0), 0x20), work + 0x1260);
    ov70_02238304(work + 0x1260, work + 0x12c4);
    U32(work, 0x2c) = 0xa;
    U32(work, 0x1604) = 0;
    return 3;
}

int ov70_02244B54(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        U32(work, 0x1604) = 0;
        switch (result + 15) {
        case 15:
            ov70_02238F80(work);
            switch (U32(work, 0x12c4)) {
            case 0:
                switch (U32(work, 0x12c8)) {
                case 0:
                    ov70_02238E50(work, 1, 0);
                    U32(work, 0x2c) = 0xb;
                    break;
                case 3:
                    S32(work, 0x3c) = -5003;
                    U32(work, 0x2c) = 0x15;
                    break;
                case 1:
                    S32(work, 0x3c) = -5000;
                    U32(work, 0x2c) = 0x15;
                    break;
                case 2:
                    S32(work, 0x3c) = -5001;
                    U32(work, 0x2c) = 0x15;
                    break;
                default:
                    sub_020399EC();
                    break;
                }
                break;
            case 1:
                S32(work, 0x3c) = -5004;
                U32(work, 0x2c) = 0x15;
                break;
            case 2:
                S32(work, 0x3c) = -5005;
                U32(work, 0x2c) = 0x15;
                break;
            default:
                ov70_02238F80(work);
                sub_020399EC();
                break;
            }
            break;
        case 16:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        case 14:
        case 17:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        case 0:
        case 3:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        case 1:
        case 13:
            ov70_02238F80(work);
            S32(work, 0x3c) = result;
            U32(work, 0x2c) = 0x15;
            break;
        default:
            ov70_02238F80(work);
            sub_020399EC();
            break;
        }
    } else {
        U32(work, 0x1604)
        ++;
        if (U32(work, 0x1604) == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_02244CA8(Ov70Work *work) {
    int value = ov00_021E6A70(-S32(work, 0x44), S32(work, 0x48));
    ov70_022451A8(work, value, -S32(work, 0x44));
    U32(work, 0x2c) = 0x18;
    return 3;
}

int ov70_02244CCC(Ov70Work *work) {
    if ((U32(gSystem, 0x48) & 1) || (U32(gSystem, 0x48) & 2) || *(u16 *)(gSystem + 0x64) != 0) {
        sub_0200E5D4(work + 0xf48, 0);
        U32(work, 0x2c) = 0;
    }
    return 3;
}

int ov70_02244D08(Ov70Work *work) {
    sub_0203A914();
    ov70_02238F80(work);
    BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x3d);
    U32(work, 0x2c) = 0;
    U32(work, 0x11fc) = 1;
    return 4;
}

int ov70_02244D44(Ov70Work *work) {
    int result = ov70_02238C8C(work);
    if (result == 1) {
        YesNoPrompt_Destroy(PTR(work, 0x11c8));
        ov70_02238E50(work, 0, 0);
        U32(work, 0x2c) = 0xb;
    } else if (result == 2) {
        YesNoPrompt_Destroy(PTR(work, 0x11c8));
        U32(work, 0x2c) = 0;
    }
    return 3;
}

int ov70_02244D80(Ov70Work *work) {
    int msg;

    switch (S32(work, 0x3c)) {
    case 1:
        msg = 0x96;
        break;
    case -1:
    case 2:
        msg = 0x97;
        break;
    case -14:
    case -2:
        msg = 0x9c;
        break;
    case -15:
    case -12:
    case -5:
    case -3:
    default:
        msg = 0x9b;
        break;
    case -5003:
        msg = 0xb9;
        break;
    case -5000:
        msg = 0xb6;
        break;
    case -5001:
        msg = 0xb6;
        break;
    case -5004:
        msg = 0xb7;
        break;
    case -5005:
        msg = 0xb8;
        break;
    }
    ov70_02244FA4(work, PTR(work, 0xba0), msg, 1, 0xf0f);
    ov70_02238D84(work, 0xc, 0x16);
    return 3;
}

int ov70_02244E44(Ov70Work *work) {
    switch (S16(work, 0x1600)) {
    case 0:
        ov70_02244FA4(work, PTR(work, 0xba0), 0xba, 1, 0xf0f);
        S16(work, 0x1600)
        ++;
        break;
    case 1:
        if (!TextPrinterCheckActive((u8)U32(work, 0xbf0))) {
            sub_0203946C();
            ov00_021EC8D8();
            S16(work, 0x1600)
            ++;
        }
        break;
    case 2:
        ov70_02244FA4(work, PTR(work, 0xba0), 0xbb, 1, 0xf0f);
        S16(work, 0x1600)
        ++;
        break;
    case 3:
        if (!TextPrinterCheckActive((u8)U32(work, 0xbf0))) {
            S16(work, 0x1600)
            ++;
        }
        break;
    default:
        S16(work, 0x1602)
        ++;
        if (S16(work, 0x1602) > 0x1e) {
            ov70_02238E50(work, 0, 0);
            U32(work, 0x2c) = 0xb;
        }
        break;
    }
    return 3;
}

int ov70_02244F14(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)U32(work, 0xbf0))) {
        U32(work, 0x2c) = U32(work, 0x30);
    }
    return 3;
}

int ov70_02244F34(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)U32(work, 0xbf0))) {
        if (S32(work, 0x11c0) > 0x1e) {
            U32(work, 0x2c) = U32(work, 0x30);
        }
        S32(work, 0x11c0)
        ++;
    }
    return 3;
}

int ov70_02244F68(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)U32(work, 0xbf0))) {
        PTR(work, 0x11c8) = ov70_02238C14(PTR(work, 4), 10, 0x234, 8, 0);
        U32(work, 0x2c) = U32(work, 0x30);
    }
    return 3;
}

void ov70_02244FA4(Ov70Work *work, void *msgData, int msgId, int speed, int color) {
    void *str = NewString_ReadMsgData(msgData, msgId);
    StringExpandPlaceholders(PTR(work, 0xb9c), PTR(work, 0xbbc), str);
    String_Delete(str);
    FillWindowPixelBuffer(work + 0xf18, 0xf);
    DrawFrameAndWindow2(work + 0xf18, 0, 1, 0xe);
    U32(work, 0xbf0) = AddTextPrinterParameterized(work + 0xf18, 1, PTR(work, 0xbbc), 0, 0, speed, NULL);
    U32(work, 0x11c0) = 0;
}

int ov70_02245018(void *window, void *str, int x, int align, int unused, int font) {
    switch (align) {
    case 1:
        x = ((*(u8 *)((u8 *)window + 7) << 3) - FontID_String_GetWidth(font, str, 0)) / 2;
        break;
    case 2:
        x = (*(u8 *)((u8 *)window + 7) << 3) - FontID_String_GetWidth(font, str, 0);
        break;
    }
    return x;
}

void ov70_02245050(void *window, void *str, int x, int y, int align, int color) {
    x = ov70_02245018(window, str, x, align, color, 1);
    AddTextPrinterParameterizedWithColor(window, 1, str, x, y, 0, color, NULL);
}

void ov70_02245084(void *window, void *str, int x, int y, int align, int color) {
    x = ov70_02245018(window, str, x, align, color, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, x, y, 0, color, NULL);
}

void ov70_022450B8(void *window, void *str, int x, int y, int align, int color) {
    x = ov70_02245018(window, str, x, align, color, 0);
    AddTextPrinterParameterizedWithColor(window, 4, str, x, y, 0, color, NULL);
}

void ov70_022450EC(void *window, void *msgData, int index) {
    void *str = NewString_ReadMsgData(msgData, ov70_0224600C[index]);
    ov70_02245084(window, str, 0, 0, 0, 0x10200);
    String_Delete(str);
}
