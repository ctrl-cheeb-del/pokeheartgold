#include "overlay96_pokeathlon_medal_grid_private.h"

void ov96_021FB6C8(void *a, u8 *p) {
    Ov96R71Tbl3 tbl = ov96_0221C428;
    s32 v;
    if (U32AT(p, 0x28) != 1 && p[8] == 0) {
        if (U32AT(p, 0x28) == 2) {
            v = 0x18;
        } else {
            switch (p[9]) {
            case 0:
                v = 8;
                break;
            case 1:
                v = 6;
                break;
            case 2:
                v = 6;
                break;
            case 3:
                v = 6;
                break;
            case 4:
                v = 4;
                break;
            default:
                GF_AssertFail();
                v = 8;
                break;
            }
        }
        U16AT(p, 0x6A)
        ++;
        if (U16AT(p, 0x6A) >= v) {
            VecFx32 vec = { 0, 0, 0 };
            U16AT(p, 0x6A) = 0;
            vec.x = (tbl.v[p[0x18]] + (LCRandom() % 7 - 3)) << 12;
            vec.y = 0x188000;
            ov96_021FC698(PAT(a, 0xDC), p[0x18], &vec);
        }
    }
}

u8 ov96_021FB784(void *unused, s32 y, s32 x) {
    Ov96R71Tbl3 t = ov96_0221C41C;
    u8 i;
    for (i = 0; i < 3; i++) {
        s32 d = t.v[i] - 0x18;
        if (d < y && y < d + 0x30 && x > 0x58 && x < 0xA8) {
            return i;
        }
    }
    return 3;
}

void ov96_021FB7C8(void *p) {
    AddWindow(PAT(p, 4), (u8 *)p + 8, ov96_0221C3FC);
    BG_FillCharDataRange(PAT(p, 4), 3, 0, 1, 0);
    LoadFontPal0(0, 0x1E0, PAT(p, 0));
    FillWindowPixelBuffer((u8 *)p + 8, 0);
}

void ov96_021FB808(void *p, s32 v) {
    void *msg = NewMsgDataFromNarc(1, 0x1B, 0x135, PAT(p, 0));
    void *mf = MessageFormat_New(PAT(p, 0));
    void *str;
    BufferIntegerAsString(mf, 0, v / 30, 3, 0, 1);
    BufferIntegerAsString(mf, 1, 10 * (v % 30) / 30, 1, 0, 1);
    str = ReadMsgData_ExpandPlaceholders(mf, msg, 0x9C, PAT(p, 0));
    AddTextPrinterParameterizedWithColor((u8 *)p + 8, 4, str, 0, 0, 0xFF, 0x000F0E00, 0);
    String_Delete(str);
    MessageFormat_Delete(mf);
    DestroyMsgData(msg);
    CopyWindowToVram((u8 *)p + 8);
}

void ov96_021FB8B4(void *p, s32 x) {
    f32 f;
    if (x < 0) {
        x = 0;
    }
    f = (f32)((100.0 + x * 2.0) / 100.0);
    ov96_021EB10C(PAT(p, 0), f, f);
}

void ov96_021FB8FC(u8 *p, u32 flag) {
    f32 f;
    if (flag != 0) {
        f = (f32)(100.0 - 10.0 * (U16AT(p, 0x38) - (u8)(p[0xC] - 1)));
    } else {
        f = (f32)(100.0 - 10.0 * (u8)(p[0xC] - 1));
        if (f < 0.0f) {
            f = 10.0f;
        }
    }
    f = (f32)(f / 100.0);
    ov96_021EB10C(PAT(p, 0), f, f);
}
