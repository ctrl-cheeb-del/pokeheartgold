#include "overlay_98_helpers_internal.h"

void ov98_0221ECD0(Ov98TextContext *ctx, u32 window, u32 message, s32 number, u32 digits, u32 field) {
    String *source;
    BufferIntegerAsString(ctx->msgFormat, field, number, digits, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    source = NewString_ReadMsgData(ctx->msgData, message);
    StringExpandPlaceholders(ctx->msgFormat, ctx->string, source);
    ov98_0221EF14(ctx, window);
    AddTextPrinterParameterizedWithColor(&ctx->windows[window], 0, ctx->string, 0, 0, 0xFF, 0x10200, NULL);
    ScheduleWindowCopyToVram(&ctx->windows[window]);
    String_Delete(source);
}

void ov98_0221ED3C(Ov98TextContext *ctx, u32 window, u32 message) {
    ov98_0221ED48(ctx, window, message, 0, 0);
}
