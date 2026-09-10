#include "frontier_script_commands_misc_internal.h"

BOOL FrtCmd_091(void *ctx) {
    FrontierScriptContext_ReadHalfWord(ctx);
    StopBGM(GF_GetCurrentPlayingBGM(), 0);
    return FALSE;
}

BOOL FrtCmd_132(void *ctx) {
    u8 *script = ctx;
    void *args = Frontier_GetLaunchArgs(**(void ***)script);
    u16 command = FrontierScriptContext_ReadHalfWord(ctx);
    u32 value = FrontierScript_ReadVar(ctx);
    u16 *dst = FrontierScript_ReadVarPtr(ctx);
    u8 *data = Frontier_GetData(**(void ***)script);

    switch (command) {
    case 2:
        ResetSystem();
        break;
    case 0x2E:
        *dst = FrontierFieldSystem_AwardTowerBattlePoints(data);
        GameStats_Add(Save_GameStats_Get(*(void **)((u8 *)args + 8)), 0x45, *dst);
        break;
    case 0x37:
        *dst = ov80_0223558C(data, (u8)value);
        break;
    case 0x21:
        *dst = FrontierFieldSystem_GetFrontierBattleNumber(data);
        break;
    case 0x22:
        *dst = ov80_022358C4(data);
        break;
    case 0x23:
        *dst = FrontierFieldSystem_0204AC7C(data);
        break;
    case 0x24:
        *dst = ov80_022358E8(data);
        break;
    case 0x2B:
        *dst = FrontierFieldSystem_GetBattleTowerMode(data);
        break;
    case 0x28:
        ov80_022357B4(data, *(void **)((u8 *)args + 8));
        break;
    case 0x29:
        *dst = ov80_02235898(data, value);
        break;
    case 0x2C:
        ov80_022358B0(data, value);
        break;
    case 0x25:
        FrontierFieldSystem_0204AD04(data, *(void **)((u8 *)args + 8));
        break;
    case 0x26:
        FrontierFieldSystem_0204AE20(data, *(void **)((u8 *)args + 8));
        break;
    case 0x27:
        FrontierFieldSystem_0204AF2C(data);
        break;
    case 0x3A:
        MI_CpuFill8(data + 0x884, 0, 0x46);
        break;
    case 0x3B:
        data[0x8D6] = 1;
        break;
    case 0x64:
        if (data == NULL) {
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return FALSE;
}

u32 ov80_0223558C(void *data, u32 mode) {
    u8 *p = data;
    if (mode == 2) {
        return ((u32)p[0x10] << 24) >> 29;
    }
    if (mode == 1) {
        if (p[0xF] == 2) {
            return ov80_0223C034[((u32)p[0x10] << 24) >> 29];
        }
        if (p[0x12] != 0) {
            return 0x61;
        }
        return 0;
    }
    if (p[0x11] != 0) {
        return 0x61;
    }
    return 0;
}

BOOL FrtCmd_133(void *ctx) {
    u8 *script = ctx;
    u8 arg;
    u8 *data;
    Frontier_GetLaunchArgs(**(void ***)ctx);
    arg = *(*(u8 **)(script + 0x1C))++;
    data = Frontier_GetData(**(void ***)ctx);
    if (data == NULL) {
        return FALSE;
    }
    ov80_0222F458(ctx, data + 0x90 + arg * 0x110, ov80_02236B18(data[0xF]));
    return TRUE;
}

BOOL FrtCmd_134(void *ctx) {
    FrontierFieldSystem_Free(Frontier_GetData(**(void ***)ctx));
    return FALSE;
}

BOOL FrtCmd_135(void *ctx) {
    u8 *script = ctx;
    void *args = Frontier_GetLaunchArgs(**(void ***)ctx);
    u8 *data = Frontier_GetData(**(void ***)ctx);
    void *setup = ov80_0223690C(data, args);
    *(void **)(data + 0x8D0) = setup;
    Sound_SetSceneAndPlayBGM(5, 0x45D, 1);
    Frontier_LaunchApplication(**(void ***)script, gOverlayTemplate_Battle, setup, 0, 0);
    return TRUE;
}

BOOL FrtCmd_136(void *ctx) {
    u8 *script = ctx;
    u8 *data = Frontier_GetData(**(void ***)ctx);
    u16 *dst = FrontierScript_ReadVarPtr(ctx);
    void *setup = *(void **)(data + 0x8D0);
    *(u32 *)(data + 0x8CC) = IsBattleResultWin(*(u32 *)((u8 *)setup + 0x14));
    *dst = *(u32 *)(data + 0x8CC);
    BattleSetup_Delete(setup);
    return FALSE;
}

BOOL FrtCmd_137(void *ctx) {
    u32 kind;
    u32 value;
    u8 *data;
    u16 *dst;
    Frontier_GetLaunchArgs(**(void ***)ctx);
    kind = FrontierScript_ReadVar(ctx);
    value = FrontierScript_ReadVar(ctx);
    dst = FrontierScript_ReadVarPtr(ctx);
    data = Frontier_GetData(**(void ***)ctx);
    if (kind == 2) {
        ov80_02236ABC(data, value);
    } else {
        GF_AssertFail();
    }
    if (sub_02037C0C(sub_0203769C(), data + 0x83E) == 1) {
        *dst = 1;
    } else {
        *dst = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_138(void *ctx) {
    u16 first = FrontierScriptContext_ReadHalfWord(ctx);
    u16 second = FrontierScriptContext_ReadHalfWord(ctx);
    *(u16 *)((u8 *)ctx + 0x78) = first;
    *(u16 *)((u8 *)ctx + 0x7A) = second;
    FrontierScriptContext_Pause(ctx, ov80_0223573C);
    return TRUE;
}

BOOL ov80_0223573C(void *ctx) {
    void *args = Frontier_GetLaunchArgs(**(void ***)ctx);
    void *data = Frontier_GetData(**(void ***)ctx);
    return ov80_02235774(ctx, data, *(void **)((u8 *)args + 8), *(u16 *)((u8 *)ctx + 0x78), *(u16 *)((u8 *)ctx + 0x7A)) == 1;
}

BOOL ov80_02235774(void *ctx, void *data, void *fieldSystem, u32 mode, u16 value) {
    void *remote = sub_02037C44(1 - sub_0203769C());
    u16 *dst;
    if (remote == NULL) {
        return FALSE;
    }
    dst = ov80_0222BE24(ctx, value);
    if (mode == 2) {
        *dst = ov80_02236AD8(data, remote);
    } else {
        GF_AssertFail();
    }
    return TRUE;
}
