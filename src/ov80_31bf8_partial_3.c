#include "ov80_31bf8_partial_internal.h"

BOOL FrtCmd_161(FrontierScriptContextPrivate *ctx) {
    u16 *out = FrontierScript_ReadVarPtr(ctx);
    *out = Frontier_GetData(FrontierObject(ctx))->result;
    return FALSE;
}

BOOL FrtCmd_162(FrontierScriptContextPrivate *ctx) {
    u32 a = FrontierScript_ReadVar(ctx);
    u32 b = FrontierScript_ReadVar(ctx);
    u16 *out = FrontierScript_ReadVarPtr(ctx);
    *out = ov80_02233280(Frontier_GetData(FrontierObject(ctx)), a, b);
    return TRUE;
}

BOOL FrtCmd_163(FrontierScriptContextPrivate *ctx) {
    ctx->asyncValue = FrontierScriptContext_ReadHalfWord(ctx);
    FrontierScriptContext_Pause(ctx, ov80_02232318);
    return TRUE;
}

BOOL ov80_02232318(FrontierScriptContextPrivate *ctx) {
    ov80_0222BE9C(ctx, ctx->asyncValue);
    FrontierDataPrivate *data = Frontier_GetData(FrontierObject(ctx));
    if (data->fieldA1A >= 2) {
        data->fieldA1A = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_165(FrontierScriptContextPrivate *ctx) {
    ctx->asyncValue = FrontierScriptContext_ReadHalfWord(ctx);
    FrontierScriptContext_Pause(ctx, ov80_02232368);
    return TRUE;
}

BOOL ov80_02232368(FrontierScriptContextPrivate *ctx) {
    u16 *out = ov80_0222BE24(ctx, ctx->asyncValue);
    FrontierDataPrivate *data = Frontier_GetData(FrontierObject(ctx));
    if (data->fieldA1B == 0) {
        return FALSE;
    }
    data->fieldA1A = 0;
    *out = data->fieldA1B;
    return TRUE;
}

BOOL FrtCmd_080(FrontierScriptContextPrivate *ctx) {
    ov80_022332D0(ctx->frontier, Frontier_GetData(FrontierObject(ctx)));
    return FALSE;
}

BOOL FrtCmd_081(FrontierScriptContextPrivate *ctx) {
    ov80_022333F0(ctx->frontier, Frontier_GetData(FrontierObject(ctx)));
    return FALSE;
}

BOOL FrtCmd_082(FrontierScriptContextPrivate *ctx) {
    ov80_02233490(ctx->frontier, Frontier_GetData(FrontierObject(ctx)));
    return FALSE;
}

BOOL FrtCmd_166(FrontierScriptContextPrivate *ctx) {
    u32 kind = FrontierScript_ReadVar(ctx);
    u16 *out = FrontierScript_ReadVarPtr(ctx);
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(FrontierObject(ctx));
    void *frontier = Save_Frontier_GetStatic(args->saveData);
    u32 stat = sub_0205C1F0((u8)kind);
    *out = FrontierSave_GetStat(frontier, stat, sub_0205C268(sub_0205C1F0((u8)kind)));
    return FALSE;
}

BOOL FrtCmd_167(FrontierScriptContextPrivate *ctx) {
    u32 kind = FrontierScript_ReadVar(ctx);
    u32 value = FrontierScript_ReadVar(ctx);
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(FrontierObject(ctx));
    ov80_02237FA4(Save_Frontier_GetStatic(args->saveData), (u8)kind, value);
    return FALSE;
}

BOOL FrtCmd_168(FrontierScriptContextPrivate *ctx) {
    u32 kind = FrontierScript_ReadVar(ctx);
    u32 value = FrontierScript_ReadVar(ctx);
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(FrontierObject(ctx));
    ov80_022331E8(args->saveData, (u8)kind, value);
    return FALSE;
}

BOOL FrtCmd_169(FrontierScriptContextPrivate *ctx) {
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(FrontierObject(ctx));
    u8 value = *ctx->scriptPtr++;
    FrontierDataPrivate *data = Frontier_GetData(FrontierObject(ctx));
    if (data == NULL) {
        return FALSE;
    }
    ov80_0222F44C(ctx, (u8 *)data + 0x64 + value * 0x110);
    return TRUE;
}
