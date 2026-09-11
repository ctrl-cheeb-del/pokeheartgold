#include "ov80_35900_partial_internal.h"

BOOL FrtCmd_170(void *ctx) {
    void *data = ov80_02235FC8(*(void **)((u8 *)Frontier_GetLaunchArgs(**(void ***)ctx) + 8));
    Frontier_SetData(**(void ***)ctx, data);
    return FALSE;
}

BOOL FrtCmd_171(void *ctx) {
    ov80_02235FEC(Frontier_GetData(**(void ***)ctx));
    return FALSE;
}

BOOL FrtCmd_172(void *ctx) {
    u32 a = FrontierScript_ReadVar(ctx);
    u32 b = FrontierScript_ReadVar(ctx);
    u32 c = FrontierScript_ReadVar(ctx);
    u16 *dst = FrontierScript_ReadVarPtr(ctx);
    *dst = ov80_02235FF8(Frontier_GetData(**(void ***)ctx), a, b, c);
    return TRUE;
}

BOOL FrtCmd_173(void *ctx) {
    *(u16 *)((u8 *)ctx + 0x78) = FrontierScriptContext_ReadHalfWord(ctx);
    FrontierScriptContext_Pause(ctx, ov80_02235990);
    return TRUE;
}

BOOL ov80_02235990(void *ctx) {
    u8 *data = Frontier_GetData(**(void ***)ctx);
    if (data[0x6F] >= 2) {
        data[0x6F] = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_202(void *ctx) {
    *(u16 *)((u8 *)ctx + 0x78) = FrontierScriptContext_ReadHalfWord(ctx);
    FrontierScriptContext_Pause(ctx, ov80_022359D4);
    return TRUE;
}

BOOL ov80_022359D4(void *ctx) {
    u8 *data = Frontier_GetData(**(void ***)ctx);
    if (data[0x6F] >= 2) {
        data[0x6F] = 0;
        return TRUE;
    }
    if (sub_02037B5C(sub_0203769C() ^ 1) == 0xAF) {
        (*(u8 **)ctx)[0x39] = 1;
        return TRUE;
    }
    return FALSE;
}

BOOL FrtCmd_174(void *ctx) {
    u32 value = FrontierScript_ReadVar(ctx);
    u16 *dst = FrontierScript_ReadVarPtr(ctx);
    u8 *data = Frontier_GetData(**(void ***)ctx);
    *dst = value == data[0x6E];
    return FALSE;
}

BOOL FrtCmd_175(void *ctx) {
    void *data;
    u32 value;
    u16 *dst;
    FrontierScript_ReadVar(ctx);
    value = FrontierScript_ReadVar(ctx);
    dst = FrontierScript_ReadVarPtr(ctx);
    data = Frontier_GetData(**(void ***)ctx);
    *(void **)((u8 *)data + 0x98) = *(void **)((u8 *)Frontier_GetLaunchArgs(**(void ***)ctx) + 0x24);
    *(u16 **)((u8 *)data + 0xB0) = dst;
    ov80_02236040(**(void ***)ctx, data, value);
    return TRUE;
}

BOOL FrtCmd_176(void *ctx) {
    u16 *first = FrontierScript_ReadVarPtr(ctx);
    u16 *second = FrontierScript_ReadVarPtr(ctx);
    u8 *data = Frontier_GetData(**(void ***)ctx);
    if ((*(u8 **)(data + 0xA8))[0x26] == 7) {
        s32 i;
        *first = 0xFF;
        for (i = 0; i < 2; i++) {
            data[0xA1 + i] = 0;
        }
    } else if ((*(u8 **)(data + 0xA8))[0x26] == 6) {
        *first = (*(u8 **)(data + 0xA8))[0x30];
        (*first)--;
        *second = (*(u8 **)(data + 0xA8))[0x31];
        if (*second != 0) {
            (*second)--;
        }
    }
    Heap_Free(*(void **)(data + 0xA8));
    *(void **)(data + 0xA8) = NULL;
    return FALSE;
}

BOOL FrtCmd_177(void *ctx) {
    u16 *dst = FrontierScript_ReadVarPtr(ctx);
    u8 *data = Frontier_GetData(**(void ***)ctx);
    *dst = data[0x59];
    return FALSE;
}
