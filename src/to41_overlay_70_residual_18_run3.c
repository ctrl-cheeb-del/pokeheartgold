#include "to41_overlay_70_residual_18_private.h"

int ov70_0223B12C(R14Work *w) {
    Sprite_SetDrawFlag(P(w, 0xf0c), 0);
    if (U32(w, 0x24) != 0xf) {
        if (U32(w, 0x24) == 6) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x3d);
        } else {
            BeginNormalPaletteFade(3, 0, 0, 0, 6, 1, 0x3d);
        }
    }
    U32(w, 0x2c) = 0;
    return 4;
}

int ov70_0223B188(R14Work *w) {
    P(w, 0x11c8) = ov70_02238C2C(P(w, 4), 10, 0x12e, 3, 4, 1);
    U32(w, 0x2c) = 5;
    return 3;
}

int ov70_0223B1B8(R14Work *w) {
    int result = ov70_02238C8C(w);
    if (result == 1) {
        YesNoPrompt_Destroy(P(w, 0x11c8));
        U32(w, 0x2c) = 2;
        ov70_02238E50(w, 5, 6);
        ov70_0223B3BC(P(w, 0xba0), w + 0x1138, 0x4d);
        ov70_0223B3BC(P(w, 0xba0), w + 0x10e8, 0x51);
        ov70_0223B258(w);
    } else if (result == 2) {
        YesNoPrompt_Destroy(P(w, 0x11c8));
        ClearFrameAndWindow2(w + 0xf18, 0);
        U32(w, 0x2c) = 1;
        ov70_0223B3EC(P(w, 0xba0), w + 0xf58, 0x58);
        ov70_0223B3EC(P(w, 0xba0), w + 0xf68, 0x6d);
    }
    return 3;
}

void ov70_0223B258(R14Work *w) {
    GfGfxLoader_LoadScrnData(0x64, 0x24, P(w, 4), 1, 0, 0x600, 1, 0x3d);
    ov70_0223B484(w + 0x10f8, P(w, 0xbc4), P(w, 0xbc8));
    ov70_0223B41C(w + 0x1148, P(w, 0xba0), P(w, 0xba4), w + 0x350 + U32(w, 0x12c) * 0x124);
}

int ov70_0223B2C0(R14Work *w) {
    ov70_0223B258(w);
    U32(w, 0x2c) = 1;
    return 3;
}

int ov70_0223B2D0(R14Work *w) {
    U32(w, 0xf14)
    ++;
    if (IsPaletteFadeFinished()) {
        U32(w, 0xf14) = 0;
        U32(w, 0x2c) = 1;
        Sprite_SetDrawFlag(P(w, 0xf0c), 1);
    }
    return 3;
}

int ov70_0223B300(R14Work *w) {
    U32(w, 0xf14)
    --;
    if (IsPaletteFadeFinished()) {
        *(vu16 *)0x04000304 &= 0xFFFF7FFF;
        U32(w, 0x2c) = 2;
        ov70_02238E50(w, 4, 15);
        U32(w, 0xf14) = 0x10;
    }
    return 3;
}

int ov70_0223B344(R14Work *w) {
    if (!TextPrinterCheckActive((u8)U32(w, 0xbf0))) {
        U32(w, 0x2c) = U32(w, 0x30);
    }
    return 3;
}

void ov70_0223B364(R14Work *w, u32 id, u32 speed) {
    ReadMsgDataIntoString(P(w, 0xba0), id, P(w, 0xbbc));
    FillWindowPixelBuffer(w + 0xf18, 15);
    DrawFrameAndWindow2(w + 0xf18, 0, 1, 2);
    U32(w, 0xbf0) = AddTextPrinterParameterized(w + 0xf18, 1, P(w, 0xbbc), 0, 0, speed, NULL);
}

void ov70_0223B3BC(void *msg, void *win, u32 id) {
    void *s = NewString_ReadMsgData(msg, id);
    ov70_02245084(win, s, 0, 0, 0, 0x000f0200);
    String_Delete(s);
}

void ov70_0223B3EC(void *msg, void *win, u32 id) {
    void *s = NewString_ReadMsgData(msg, id);
    ov70_022450B8(win, s, 0, 0, 1, 0x000f0200);
    String_Delete(s);
}

void ov70_0223B41C(void *window, void *str1, void *str2, void *data) {
    int width;

    FillWindowPixelBuffer(window, 0);
    ov70_0223F20C(window, str2, *(s16 *)data, 0, 0x10200);
    ov70_0223F324(window, str1, *((s8 *)data + 2), 0, 0x49, 0, 0x10200);
    width = ov70_0223F864(*((s8 *)data + 3), *((s8 *)data + 4), 0);
    ov70_0223F38C(window, str1, width, 0, 0x68, 0, 0x10200, 0);
}

void ov70_0223B484(void *window, void *str1, void *str2) {
    FillWindowPixelBuffer(window, 0);
    FillWindowPixelBuffer((u8 *)window + 0x10, 0);
    if (str1 != NULL) {
        ov70_02245084(window, str1, 0, 0, 0, 0x10200);
    }
    if (str2 != NULL) {
        ov70_02245084((u8 *)window + 0x10, str2, 0, 0, 0, 0x10200);
    }
}

void ov70_0223B4D4(R14Work *w) {
    BgSetPosTextAndCommit(P(w, 4), 0, 3, U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 1, 3, U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 2, 3, U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 3, 3, U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 4, 3, -U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 5, 3, -0x20 - U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 6, 3, -U32(w, 0xf14));
    BgSetPosTextAndCommit(P(w, 4), 7, 3, -U32(w, 0xf14));
}
