#include "overlay_98_helpers_internal.h"

void ov98_0221EB84(Ov98TextContext *ctx, int count) {
    int i;
    FontID_Release(4);
    String_Delete(ctx->string);
    MessageFormat_Delete(ctx->msgFormat);
    DestroyMsgData(ctx->msgDataFixed);
    DestroyMsgData(ctx->msgData);
    for (i = 0; i < count; i++) {
        ClearWindowTilemapAndCopyToVram(&ctx->windows[i]);
        RemoveWindow(&ctx->windows[i]);
    }
    Heap_Free(ctx->windows);
    Heap_Free(ctx);
}

void ov98_0221EBD8(Ov98TextContext *ctx, u32 window, u32 message, u32 x) {
    ov98_0221EBEC(ctx, window, message, x, 0, 0);
}

void ov98_0221EBEC(Ov98TextContext *ctx, u32 window, u32 message, u32 x, u8 color, u32 font) {
    ov98_0221EC3C(ctx, window, message, x, 0, color, font, 0);
}

void ov98_0221EC08(Ov98TextContext *ctx, u32 window, u32 message, u32 color, u8 speed) {
    ov98_0221EC3C(ctx, window, message, 0, color, speed, 0, 0);
}

void ov98_0221EC24(Ov98TextContext *ctx, u32 window, u32 message, u32 font) {
    ov98_0221EC3C(ctx, window, message, 1, 0, 0, 0, font);
}
