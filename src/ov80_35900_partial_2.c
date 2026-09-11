#include "ov80_35900_partial_internal.h"

BOOL FrtCmd_180(void *ctx) {
    u16 *dst = FrontierScript_ReadVarPtr(ctx);
    *dst = sub_02096998(Frontier_GetData(**(void ***)ctx));
    return TRUE;
}

BOOL FrtCmd_181(void *ctx) {
    FrontierScriptContext_Pause(ctx, ov80_02235F90);
    return TRUE;
}

BOOL ov80_02235F90(void *ctx) {
    u8 *data = Frontier_GetData(**(void ***)ctx);
    if (data[0x8D4] < 2) {
        return FALSE;
    }
    data[0x8D4] = 0;
    return TRUE;
}

BOOL FrtCmd_182(void *ctx) {
    FrontierFieldSystem_Free(Frontier_GetData(**(void ***)ctx));
    return FALSE;
}
