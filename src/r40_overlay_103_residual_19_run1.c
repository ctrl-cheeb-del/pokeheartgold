#include "global.h"

#include "r40_overlay_103_residual_19_private.h"
#define PTR(c, o) (*(void **)((c) + (o)))

void ov103_021EE468(R40Ov103Work19 *work, u32 menuIndex, u32 column, u32 mailIndex) {
    u8 *window = work->ctx + 0x48 + column * 16;
    void *mail = PTR(work->ctx + mailIndex * 4, 0x27C);
    CopyU16ArrayToString(PTR(work->ctx, 0x230), Mail_GetAuthorNamePtr(mail));
    u32 i;
    u32 y = 0;
    for (i = 0; i < 8; i++) {
        BlitBitmapRectToWindow((Window *)window, work->ctx + 8, 0, 0, 8, 8, (u16)y, 0, 8, 8);
        BlitBitmapRectToWindow((Window *)window, work->ctx + 0x28, 0, 0, 8, 8, (u16)y, 8, 8, 8);
        y += 8;
    }
    if (Mail_GetAuthorGender(mail) == 0) {
        ov103_021EE3E4(window, PTR(work->ctx, 0x230), 0, 0, 4, 0x30200, 0);
    } else {
        ov103_021EE3E4(window, PTR(work->ctx, 0x230), 0, 0, 4, 0x50400, 0);
    }
    CopyWindowPixelsToVram_TextMode((Window *)window);
    sub_02019A60(PTR(work->ctx, 4), menuIndex, window);
}

void ov103_021EE550(R40Ov103Work19 *work) {
    FillWindowPixelBuffer((Window *)(work->ctx + 0x1D8), 0);
    ov103_021EE430(work->ctx, PTR(work->ctx, 0x228), 25, 0, 44, 0, 0, 0x10200, 2);
    ScheduleWindowCopyToVram((Window *)(work->ctx + 0x1D8));
    FillWindowPixelBuffer((Window *)(work->ctx + 0x198), 0);
    ov103_021EE430(work->ctx, PTR(work->ctx, 0x228), 21, 3, 24, 0, 4, 0xF0100, 2);
    ScheduleWindowCopyToVram((Window *)(work->ctx + 0x198));
    FillWindowPixelBuffer((Window *)(work->ctx + 0x1A8), 0);
    ov103_021EE430(work->ctx, PTR(work->ctx, 0x228), 22, 4, 24, 0, 4, 0xF0100, 2);
}
