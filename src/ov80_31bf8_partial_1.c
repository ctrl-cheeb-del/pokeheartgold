#include "ov80_31bf8_partial_internal.h"

BOOL FrtCmd_151(FrontierScriptContextPrivate *ctx) {
    u32 a = FrontierScript_ReadVar(ctx);
    u32 b = FrontierScript_ReadVar(ctx);
    u32 c = FrontierScript_ReadVar(ctx);
    u32 d = FrontierScript_ReadVar(ctx);
    u32 e = FrontierScript_ReadVar(ctx);
    u16 *out = FrontierScript_ReadVarPtr(ctx);
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(FrontierObject(ctx));
    u32 result = ov80_022324C4(args->saveData, a, (u8)b, c, d, e, out);
    Frontier_SetData(FrontierObject(ctx), result);
    return FALSE;
}

BOOL FrtCmd_152(FrontierScriptContextPrivate *ctx) {
    u32 value = FrontierScript_ReadVar(ctx);
    ov80_02232824(Frontier_GetData(FrontierObject(ctx)), value);
    return FALSE;
}

BOOL FrtCmd_153(FrontierScriptContextPrivate *ctx) {
    ov80_02232ABC(Frontier_GetData(FrontierObject(ctx)));
    return FALSE;
}

BOOL FrtCmd_154(FrontierScriptContextPrivate *ctx) {
    return LaunchArgsApp(ctx, ov80_0223BE34);
}

BOOL FrtCmd_164(FrontierScriptContextPrivate *ctx) {
    return LaunchArgsApp(ctx, ov80_0223BE24);
}

BOOL FrtCmd_155(FrontierScriptContextPrivate *ctx) {
    FrontierDataPrivate *data = Frontier_GetData(FrontierObject(ctx));
    void *battle = *(void **)((u8 *)data + 0xc);
    Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(data->party, 0, Party_GetMonByIndex(*(void **)((u8 *)battle + 4), 0));
    Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(data->party, 1, Party_GetMonByIndex(*(void **)((u8 *)battle + 4), 1));
    if (!ov80_02237D8C(data->type)) {
        Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(data->party, 2, Party_GetMonByIndex(*(void **)((u8 *)battle + 4), 2));
    } else {
        Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(data->party, 2, Party_GetMonByIndex(*(void **)((u8 *)battle + 0xc), 0));
        Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(data->party, 3, Party_GetMonByIndex(*(void **)((u8 *)battle + 0xc), 1));
    }
    data->result = IsBattleResultWin(*(u32 *)((u8 *)battle + 0x14));
    BattleSetup_Delete(battle);
    return FALSE;
}

BOOL FrtCmd_156(FrontierScriptContextPrivate *ctx) {
    FrontierLaunchArgsPrivate *args = Frontier_GetLaunchArgs(FrontierObject(ctx));
    FrontierDataPrivate *data = Frontier_GetData(FrontierObject(ctx));
    void *battle = ov80_02237B8C(data, args);
    *(void **)((u8 *)data + 0xc) = battle;
    Frontier_LaunchApplication(FrontierObject(ctx), gOverlayTemplate_Battle, battle, 0, NULL);
    return TRUE;
}

BOOL FrtCmd_157(FrontierScriptContextPrivate *ctx) {
    return LaunchArgsApp(ctx, ov80_0223BE44);
}
