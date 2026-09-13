#include "r40_overlay_98_residual_6_private.h"

void ov98_0221ED48(Ov98TextContext *ctx, u32 window, u32 message, u32 x, u8 y) {
    String *str = NewString_ReadMsgData(ctx->msgData, message);
    StringExpandPlaceholders(ctx->msgFormat, ctx->string, str);
    ov98_0221EF14(ctx, window);
    AddTextPrinterParameterizedWithColor(&ctx->windows[window], 0, ctx->string, x, y, 0xFF, 0x10200, NULL);
    ScheduleWindowCopyToVram(&ctx->windows[window]);
    String_Delete(str);
}
