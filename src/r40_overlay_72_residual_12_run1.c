#include "r40_overlay_72_residual_12_private.h"

int ov72_022393CC(u8 *p) {
    int result;
    if (ov72_02237B54()) {
        result = ov72_02237B74();
        *(u32 *)(p + 0xFD4) = 0;
        switch (result) {
        case 0:
            ov72_0223A444(p);
            switch (*(u32 *)(*(u8 **)p + 0x18)) {
            case 0:
                ov72_02238680(p, 11, 13);
                break;
            case 1:
                *(u32 *)(p + 0x1C) = 0x19;
                break;
            case 2:
                *(u32 *)(p + 0x1C) = 0x1D;
                break;
            }
            break;
        case 1:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        case -1:
        case 2:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        case -7:
        case -4:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        case -6:
        case -2:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        default:
            ov72_0223A444(p);
            sub_020399EC();
            break;
        }
    } else {
        (*(u32 *)(p + 0xFD4))++;
        if (*(u32 *)(p + 0xFD4) == 0xE10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov72_022394A4(u8 *p) {
    sub_0203189C(*(void **)(*(u8 **)p + 0xC), p + 0xF64);
    ov72_02237CF4(p + 0xF64, p + 0xFC8);
    *(u32 *)(p + 0x1C) = 10;
    *(u32 *)(p + 0xFD4) = 0;
    return 3;
}

int ov72_022394D8(u8 *p) {
    int result;
    if (ov72_02237B54()) {
        result = ov72_02237B74();
        *(u32 *)(p + 0xFD4) = 0;
        switch (result) {
        case 0:
            ov72_0223A444(p);
            switch (*(u32 *)(p + 0xFC8)) {
            case 0:
                switch (*(u32 *)(p + 0xFCC)) {
                case 0:
                    switch (*(u32 *)(*(u8 **)p + 0x18)) {
                    case 0:
                        ov72_02238680(p, 11, 13);
                        break;
                    case 1:
                        *(u32 *)(p + 0x1C) = 0x19;
                        break;
                    case 2:
                        *(u32 *)(p + 0x1C) = 0x1D;
                        break;
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    *(s32 *)(p + 0xF5C) = result;
                    *(u32 *)(p + 0x1C) = 0x35;
                    ov72_0223A444(p);
                    break;
                }
                break;
            case 1:
            case 2:
                *(s32 *)(p + 0xF5C) = result;
                *(u32 *)(p + 0x1C) = 0x35;
                ov72_0223A444(p);
                break;
            default:
                ov72_0223A444(p);
                sub_020399EC();
                break;
            }
            break;
        case 1:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        case -1:
        case 2:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        case -7:
        case -4:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        case -6:
        case -2:
            *(s32 *)(p + 0xF5C) = result;
            *(u32 *)(p + 0x1C) = 0x35;
            ov72_0223A444(p);
            break;
        default:
            ov72_0223A444(p);
            sub_020399EC();
            break;
        }
    } else {
        (*(u32 *)(p + 0xFD4))++;
        if (*(u32 *)(p + 0xFD4) == 0xE10) {
            sub_020399EC();
        }
    }
    return 3;
}
