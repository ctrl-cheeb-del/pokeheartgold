#include "overlay_98_helpers_internal.h"

void ov98_0221EDA4(Ov98TextContext *ctx, s32 number, u32 digits, u32 field) {
    BufferIntegerAsString(ctx->msgFormat, field, number, digits, PRINTING_MODE_RIGHT_ALIGN, TRUE);
}

void ov98_0221EDC4(Ov98TextContext *ctx, u32 window, u32 message, u32 field, PlayerProfile *profile) {
    String *source;
    BufferPlayersName(ctx->msgFormat, field, profile);
    source = NewString_ReadMsgData(ctx->msgData, message);
    StringExpandPlaceholders(ctx->msgFormat, ctx->string, source);
    ov98_0221EF14(ctx, window);
    AddTextPrinterParameterizedWithColor(&ctx->windows[window], 0, ctx->string, 0, 0, 0xFF, 0x10200, NULL);
    ScheduleWindowCopyToVram(&ctx->windows[window]);
    String_Delete(source);
}

void ov98_0221EE28(Ov98TextContext *ctx, u32 window, u32 message) {
    MsgData *msgData = ctx->msgDataFixed;
    GF_ASSERT(message <= 493);
    ReadMsgDataIntoString(msgData, message, ctx->string);
    FillWindowPixelBuffer(&ctx->windows[window], 0);
    AddTextPrinterParameterizedWithColor(&ctx->windows[window], 0, ctx->string, 0, 0, 0xFF, 0x10200, NULL);
    ScheduleWindowCopyToVram(&ctx->windows[window]);
}

void ov98_0221EE84(Ov98TextContext *ctx, u32 index) {
    ov98_0221EF14(ctx, index);
    ScheduleWindowCopyToVram(&ctx->windows[index]);
}

void ov98_0221EE9C(Ov98TextContext *ctx, u32 window, String *string, u32 x, u8 y) {
    ov98_0221EF14(ctx, window);
    AddTextPrinterParameterizedWithColor(&ctx->windows[window], 0, string, x, y, 0xFF, 0x10200, NULL);
    ScheduleWindowCopyToVram(&ctx->windows[window]);
}

void ov98_0221EEDC(Ov98TextContext *ctx, u32 index) {
    ClearWindowTilemapAndScheduleTransfer(&ctx->windows[index]);
}

void ov98_0221EEEC(Ov98TextContext *ctx, u32 index, u8 y) {
    SetWindowY(&ctx->windows[index], y);
}

void *ov98_0221EEFC(Ov98TextContext *ctx) {
    GF_ASSERT(ctx != NULL);
    GF_ASSERT(ctx->msgFormat != NULL);
    return ctx->msgFormat;
}

void ov98_0221EF14(Ov98TextContext *ctx, u32 index) {
    FillWindowPixelBuffer(&ctx->windows[index], 0);
}

BOOL ov98_0221EF24(void) {
    TouchscreenHitbox hitbox = ov98_0221F1E0;
    BOOL result = FALSE;
    if (TouchscreenHitbox_TouchNewIsIn(&hitbox) || (gSystem.newKeys & PAD_BUTTON_B)) {
        result = TRUE;
    }
    return result;
}

u32 ov98_0221EF64(u32 value) {
    if (value >= 450) {
        return 2;
    }
    if (value >= 420) {
        return 1;
    }
    return 0;
}

u8 ov98_0221EF80(s32 value) {
    u8 i = 0;
    do {
        if (ov98_0221F220[i] <= value) {
            break;
        }
        i++;
    } while (i < 10);
    return 10 - i;
}

u16 ov98_0221EFA4(u32 row, u32 column) {
    return ov98_0221F1F8[row][column];
}

BOOL ov98_0221EFB4(u32 direction, u32 column, u16 value) {
    u16 limit = ov98_0221EFA4(direction, column);
    if (value == 0xFFFF) {
        return FALSE;
    }
    if (direction == 0) {
        return value < limit;
    }
    return value > limit;
}

BOOL ov98_0221EFE8(u32 direction, u32 column, u16 value) {
    u16 limit = ov98_0221EFA4(direction, column);
    if (value == 0xFFFF) {
        return FALSE;
    }
    if (direction == 0) {
        return value <= limit;
    }
    return value >= limit;
}

u16 ov98_0221F01C(const void *records, u32 index) {
    return *(const u16 *)((const u8 *)records + index * 8);
}
