#include "overlay_80_02235390_internal.h"

BOOL FrtCmd_085(void *ctx) {
    PlaySE(FrontierScript_ReadVar(ctx));
    return FALSE;
}

BOOL FrtCmd_086(void *ctx) {
    StopSE(FrontierScript_ReadVar(ctx), 0);
    return FALSE;
}

BOOL ov80_022353D0(FrontierScriptContext35390 *ctx);

BOOL FrtCmd_087(FrontierScriptContext35390 *ctx) {
    ctx->soundId = FrontierScript_ReadVar(ctx);
    FrontierScriptContext_Pause(ctx, (BOOL (*)(void *))ov80_022353D0);
    return TRUE;
}

BOOL ov80_022353D0(FrontierScriptContext35390 *ctx) {
    if (!IsSEPlaying(ctx->soundId)) {
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_088(void *ctx) {
    PlayFanfare(FrontierScriptContext_ReadHalfWord(ctx));
    return FALSE;
}

BOOL ov80_02235408(void *ctx);

BOOL FrtCmd_089(void *ctx) {
    FrontierScriptContext_Pause(ctx, ov80_02235408);
    return TRUE;
}

BOOL ov80_02235408(void *ctx) {
    if (!IsFanfarePlaying()) {
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_090(void *ctx) {
    u32 seq = FrontierScriptContext_ReadHalfWord(ctx);
    Sound_SetFieldBGM(seq);
    PlayBGM(seq);
    return FALSE;
}
