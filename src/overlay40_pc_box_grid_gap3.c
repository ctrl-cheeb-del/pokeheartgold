#include "overlay40_pc_box_grid_gap3_private.h"

#define BLEND(work, mask, coeff, color) \
    PaletteData_BlendPalettes(PTR(work, 0x28), mask, coeff, color, (u16)U32(work, 0x58))

int ov40_02230ED8(void *work) {
    switch (S32(work, 8)) {
    case 0:
        if (ov40_0222C4DC(work) == TRUE) {
            ov40_0222BF80(work, 1);
            break;
        }
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x6D);
        PaletteData_BlendPalettes(PTR(work, 0x28), 2, 0xFFFE, 0x10, (u16)ov40_0222DAF0(work));
        PaletteData_BlendPalettes(PTR(work, 0x28), 0, 0xBFFF, 0x10, (u16)ov40_0222DAF0(work));
        PaletteData_BlendPalettes(PTR(work, 0x28), 3, 0x3FFE, 0x10, (u16)ov40_0222DAF0(work));
        PaletteData_BlendPalettes(PTR(work, 0x28), 1, 0xFFFF, 0x10, (u16)ov40_0222DAF0(work));
        sub_02087A30(PTR(work, 0x6F4));
        sub_02087A30(PTR(work, 0x6F0));
        S32(work, 8)
        ++;
        break;
    case 1:
        if (!IsPaletteFadeFinished()) {
            break;
        }
        sub_02087948(PTR(work, 0x6F4), 0x80, 0x10);
        sub_020878B8(PTR(work, 0x6F4), 0x80, 0xD8);
        sub_020879E0(PTR(work, 0x6F4), 1);
        sub_020878B0(PTR(work, 0x6F4), 1);
        PlaySE(0x576);
        S32(work, 8)
        ++;
        break;
    case 2:
        S32(work, 0xC)
        ++;
        if (S32(work, 0xC) < 0x19) {
            break;
        }
        S32(work, 0xC) = 0;
        sub_02087948(PTR(work, 0x6F0), 0x80, -0x10);
        sub_020878B8(PTR(work, 0x6F0), 0x80, 0x60);
        sub_020879E0(PTR(work, 0x6F0), 1);
        sub_020878B0(PTR(work, 0x6F0), 1);
        S32(work, 8)
        ++;
        break;
    case 3:
        S32(work, 0xC)
        ++;
        if (S32(work, 0xC) < 0x12) {
            break;
        }
        ov40_02230E34(work);
        sub_020879E0(PTR(work, 0x6F4), 0);
        S32(work, 0xC) = 0;
        S32(work, 8)
        ++;
        break;
    case 4:
        if (S32(work, 0xC) < 0x10) {
            S32(work, 0xC) += 4;
            PaletteData_BlendPalettes(PTR(work, 0x28), 0, 0xF000, (u8)S32(work, 0xC), 0xFFFF);
        } else {
            S32(work, 8)
            ++;
        }
        break;
    case 5:
        if (S32(work, 0xC) > 0) {
            S32(work, 0xC) -= 4;
            PaletteData_BlendPalettes(PTR(work, 0x28), 0, 0xF000, (u8)S32(work, 0xC), 0xFFFF);
        } else {
            S32(work, 8)
            ++;
        }
        break;
    case 6:
        if (System_GetTouchHeld() == TRUE) {
            ov40_02230EB4(work);
            sub_020879E0(PTR(work, 0x6F0), 0);
            sub_02087A54(PTR(work, 0x6F4));
            sub_02087A54(PTR(work, 0x6F0));
            S32(work, 8)
            ++;
        }
        break;
    default:
        ov40_0222BF80(work, 1);
        break;
    }
    return 0;
}

int ov40_02231100(void *work) {
    switch (S32(work, 8)) {
    case 0:
        ov40_02230964(work, 1);
        ov40_0222C750(work);
        ov40_0222C884(work);
        ov40_0222CAD8(work);
        ov40_0222CCAC(work);
        ov40_0222D2A0(work);
        ov40_0222CE7C(work);
        ov40_0222CF10(work);
        ov40_02230964(work, 0);
        if (ov40_0222C4DC(work) == TRUE) {
            if (S32(work, 0) == 0) {
                GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x14), 0x45, PTR(work, 0x24), 5, 0, 0, 0, 0x6D);
            } else {
                GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x14), 0x37, PTR(work, 0x24), 5, 0, 0, 0, 0x6D);
            }
            sub_02087948(PTR(work, 0x6F0), 0x80, 0xE0);
            sub_020878B8(PTR(work, 0x6F0), 0x80, 0xE0);
            sub_020879E0(PTR(work, 0x6F0), 0);
            sub_020878B0(PTR(work, 0x6F0), 1);
            ov40_0222BF64(work, PTR(work, 0x83C), 1, PTR(work, 0x10));
            break;
        }
        PlaySE(0x573);
        S32(work, 0xC) = 0x10;
        S32(work, 8)
        ++;
        break;
    case 1:
        if (ov40_0222C4DC(work) == TRUE) {
            if (IsPaletteFadeFinished() == TRUE) {
                S32(work, 8)
                ++;
            }
            break;
        }
        if (S32(work, 0xC) != 0) {
            S32(work, 0xC) -= 2;
            PaletteData_BlendPalettes(PTR(work, 0x28), 2, 0xFFFE, (u8)S32(work, 0xC), (u16)ov40_0222DAF0(work));
            PaletteData_BlendPalettes(PTR(work, 0x28), 0, 0xFFFF, (u8)S32(work, 0xC), (u16)ov40_0222DAF0(work));
            PaletteData_BlendPalettes(PTR(work, 0x28), 3, 0x3FFE, (u8)S32(work, 0xC), (u16)ov40_0222DAF0(work));
            PaletteData_BlendPalettes(PTR(work, 0x28), 1, 0xFFFF, (u8)S32(work, 0xC), (u16)ov40_0222DAF0(work));
        } else {
            BLEND(work, 1, 2, 0x10);
            BLEND(work, 2, 0xC, 0x10);
            S32(work, 8)
            ++;
        }
        break;
    case 2:
        if (S32(work, 0) == 0) {
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x14), 0x45, PTR(work, 0x24), 5, 0, 0, 0, 0x6D);
        } else {
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x14), 0x37, PTR(work, 0x24), 5, 0, 0, 0, 0x6D);
        }
        S32(work, 8)
        ++;
        break;
    default:
        if (S32(work, 0x724) >= 3) {
            ov40_0222BF80(work, 2);
        }
        break;
    }
    return 0;
}

int ov40_0223131C(void *work) {
    switch (S32(work, 8)) {
    case 0:
        sub_02087948(PTR(work, 0x6F0), 0x80, 0x60);
        sub_020878B8(PTR(work, 0x6F0), 0x80, 0x60);
        sub_020879E0(PTR(work, 0x6F0), 1);
        sub_020878B0(PTR(work, 0x6F0), 1);
        S32(work, 0xC)
        ++;
        BLEND(work, 1, 2, (u8)(0x10 - S32(work, 0xC)));
        if (S32(work, 0xC) == 2) {
            S32(work, 0xC) = 0xF;
            S32(work, 8)
            ++;
        }
        break;
    case 1:
        BLEND(work, 1, 2, (u8)S32(work, 0xC));
        S32(work, 8)
        ++;
        break;
    case 2:
        S32(work, 0xC)
        --;
        BLEND(work, 1, 2, (u8)S32(work, 0xC));
        if (S32(work, 0xC) == 0) {
            S32(work, 8)
            ++;
        }
        break;
    default:
        ov40_0222BF80(work, 3);
        break;
    }
    return 0;
}
