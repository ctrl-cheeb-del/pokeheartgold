#include "overlay72_event_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

int ov72_0223A1AC(void *p) {
    if (!TextPrinterCheckActive((u8)U32(p, 0xBF4))) {
        U32(p, 0x1C) = U32(p, 0x20);
    }
    return 3;
}

int ov72_0223A1CC(void *p) {
    if (!TextPrinterCheckActive((u8)U32(p, 0xBF4))) {
        if (S32(p, 0xF60) > 0x1E) {
            U32(p, 0x1C) = U32(p, 0x20);
        }
        U32(p, 0xF60)
        ++;
    }
    return 3;
}

int ov72_0223A200(Ov72Work *p) {
    if (!TextPrinterCheckActive((u8)U32(p, 0xBF4))) {
        p->cfg.value = U32(p, 0xE14);
        p->cfg.source = U32(p, 4);
        p->cfg.kind = 0x43;
        p->cfg.b28 = 0;
        p->cfg.b2A = 10;
        p->cfg.b2B = 6;
        p->cfg.b2E = 4;
        p->cfg.b2C = 11;
        p->cfg.b2D = 1;
        p->cfg.final = 0x100;
        ov72_0223AF1C(&p->cfg);
        U32(p, 0x1C) = U32(p, 0x20);
    }
    return 3;
}

void ov72_0223A280(void *p, void *msgData, int msgNo, int speed) {
    void *str = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(PTR(p, 0xBD0), PTR(p, 0xBE0), str);
    FillWindowPixelBuffer((u8 *)p + 0xE18, 15);
    DrawFrameAndWindow2((u8 *)p + 0xE18, 0, 1, 14);
    U32(p, 0xBF4) = AddTextPrinterParameterized((u8 *)p + 0xE18, 1, PTR(p, 0xBE0), 0, 0, speed, NULL);
    String_Delete(str);
}

int ov72_0223A2E8(void *p) {
    void *x = ov00_021E6A70(-U32(p, 0xF54), U32(p, 0xF58));
    ov72_0223A4DC(p, x, -U32(p, 0xF54));
    U32(p, 0x1C) = 0x38;
    return 3;
}

int ov72_0223A314(void *p) {
    if ((gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B) || gSystem.touchNew) {
        sub_0200E5D4((u8 *)p + 0xE58, 0);
        U32(p, 0x1C) = 0;
    }
    return 3;
}

void ov72_0223A350(void *p, void *msgData, int msgNo, int speed, int unused) {
    ReadMsgDataIntoString(msgData, msgNo, PTR(p, 0xBE0));
    FillWindowPixelBuffer((u8 *)p + 0xE18, 15);
    DrawFrameAndWindow2((u8 *)p + 0xE18, 0, 1, 14);
    U32(p, 0xBF4) = AddTextPrinterParameterized((u8 *)p + 0xE18, 1, PTR(p, 0xBE0), 0, 0, speed, NULL);
}

int ov72_0223A3A8(const u8 *window, const void *str, int x, int mode, int unused, int fontId) {
    int width;
    switch (mode) {
    case 1:
        width = FontID_String_GetWidth(fontId, str, 0);
        x = ((window[7] << 3) - width) / 2;
        break;
    case 2:
        width = FontID_String_GetWidth(fontId, str, 0);
        x = (window[7] << 3) - width;
        break;
    }
    return x;
}

void ov72_0223A3E0(void *window, const void *str, int x, int y, int mode, u32 color) {
    x = ov72_0223A3A8(window, str, x, mode, color, 1);
    AddTextPrinterParameterizedWithColor(window, 1, str, x, y, 0, color, NULL);
}
