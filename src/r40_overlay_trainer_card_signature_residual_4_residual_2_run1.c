#include "global.h"

#include "bg_window.h"
#include "r40_overlay_trainer_card_signature_residual_4_residual_2_candidate_private.h"
#include "unk_02013534.h"

extern void DC_FlushRange(const void *, u32);
extern void GX_LoadOBJ(const void *, u32, u32);
extern u32 ov52_021E8994(void *, void *, u32, int, u32);
extern void ov52_021E925C(void *, int, u32, void *);
extern u32 FontID_String_GetWidth(u32, void *, u32);
extern u8 AddTextPrinterParameterizedWithColor(void *, int, void *, u32, u32, u32, u32, void *);

void ov52_021E89D4(void *arg) {
    u8 *p = arg;
    int i;
    int x;
    int width;
    u32 dst;
    u8 *buf;

    AddWindowParameterized(*(BgConfig **)p, (Window *)(p + 0x2D4), 0, 2, 1, 0x1B, 4, 0xD, 0x28);
    FillWindowPixelBuffer((Window *)(p + 0x2D4), 0xF);
    AddWindowParameterized(*(BgConfig **)p, (Window *)(p + 0x2C4), 1, 4, 9, 0x18, 8, 1, 1);
    FillWindowPixelBuffer((Window *)(p + 0x2C4), 2);
    AddWindowParameterized(*(BgConfig **)p, (Window *)(p + 0x2E4), 1, 0x1A, 0x15, 8, 2, 2, 0xC1);
    FillWindowPixelBuffer((Window *)(p + 0x2E4), 0);
    DC_FlushRange((void *)ov52_021E8994(p + 0x2E4, *(void **)(p + 0x2C), 1, 2, 0xE0702), 0x200);

    i = 0;
    x = 0;
    dst = x;
    buf = p + 0x5B9C;
    for (; i < 2; i++) {
        sub_02013A50((Window *)(p + 0x2E4), 4, 2, x, 0, buf);
        DC_FlushRange(buf, 0x100);
        GX_LoadOBJ(buf, dst, 0x100);
        dst += 0x100;
        x += 4;
    }

    AddWindowParameterized(*(BgConfig **)p, (Window *)(p + 0x2F4), 1, 2, 2, 0x1C, 2, 0xD, 0xD1);
    width = FontID_String_GetWidth(1, *(void **)(p + 0x30), 0);
    FillWindowPixelBuffer((Window *)(p + 0x2F4), 0);
    AddTextPrinterParameterizedWithColor((Window *)(p + 0x2F4), 1, *(void **)(p + 0x30), (0xE0 - width) / 2, 0, 0, 0x10200, NULL);

    {
        Window *win;
        int baseTile;
        int palette;
        i = 0;
        baseTile = 1;
        palette = 3;
        win = (Window *)(p + 0x274);
        for (; i < 5; i++) {
            AddWindowParameterized(*(BgConfig **)p, win, 4, 5, palette, 10, 2, 0xD, baseTile);
            FillWindowPixelBuffer(win, 0);
            baseTile += 0x14;
            palette += 4;
            win++;
        }
    }
    ov52_021E925C(p + 0x274, 0, 0xE0D0F, p);
}
