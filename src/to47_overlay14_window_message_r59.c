#include "to47_overlay14_window_message_r59_private.h"

void ov14_021F6338(Ov14R59Context *ctx, u32 windowIndex, u32 messageId, u32 unused) {
    Window *window = &ctx->windows[windowIndex];
    u8 x;

    FillWindowPixelBuffer(window, 0xD);
    x = GetWindowWidth(window) * 8 / 2;
    ov14_021F4F84(ctx, ctx->msgData, windowIndex, messageId, x, 0, 4, 0x00090A0D, 2);
    CopyWindowPixelsToVram_TextMode(window);
}
