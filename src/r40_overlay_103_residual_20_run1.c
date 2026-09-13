#include "global.h"

#include "r40_overlay_103_residual_20_private.h"
#define PTR(c, o) (*(void **)((c) + (o)))

void ov103_021EE644(R40Ov103Work20 *work) {
    void *tmp;
    u16 width;
    u16 width2;
    FillWindowPixelBuffer(work->ctx + 0x1B8, 0);
    ReadMsgDataIntoString(PTR(work->ctx, 0x228), 2, PTR(work->ctx, 0x230));
    ov103_021EE3E4(work->ctx + 0x1B8, PTR(work->ctx, 0x230), 0x14, 0, 0, 0x10200, 2);
    width = FontID_String_GetWidth(0, PTR(work->ctx, 0x230), 0);
    BufferIntegerAsString(PTR(work->ctx, 0x22C), 0, work->row + 1, 1, 0, 1);
    tmp = NewString_ReadMsgData(PTR(work->ctx, 0x228), 1);
    StringExpandPlaceholders(PTR(work->ctx, 0x22C), PTR(work->ctx, 0x230), tmp);
    String_Delete(tmp);
    width2 = FontID_String_GetWidth(0, PTR(work->ctx, 0x230), 0);
    ov103_021EE3E4(work->ctx + 0x1B8, PTR(work->ctx, 0x230), 0x14 - (width / 2) - width2, 0, 0, 0x10200, 0);
    BufferIntegerAsString(PTR(work->ctx, 0x22C), 0, *(u16 *)(work->ctx + 0x2E2) + 1, 1, 0, 1);
    tmp = NewString_ReadMsgData(PTR(work->ctx, 0x228), 1);
    StringExpandPlaceholders(PTR(work->ctx, 0x22C), PTR(work->ctx, 0x230), tmp);
    String_Delete(tmp);
    ov103_021EE3E4(work->ctx + 0x1B8, PTR(work->ctx, 0x230), width / 2 + 0x14, 0, 0, 0x10200, 0);
    ScheduleWindowCopyToVram(work->ctx + 0x1B8);
}
