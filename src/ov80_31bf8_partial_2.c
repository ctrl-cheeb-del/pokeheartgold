#include "ov80_31bf8_partial_internal.h"

void ov80_02231E94(AppArgsPrivate *args) {
    ov80_02232AEC(args->frontierData, args);
    Heap_Free(args);
}

BOOL FrtCmd_158(FrontierScriptContextPrivate *ctx) {
    ov80_02232F00(Frontier_GetData(FrontierObject(ctx)));
    return FALSE;
}

BOOL FrtCmd_159(FrontierScriptContextPrivate *ctx) {
    ov80_02232F08(Frontier_GetData(FrontierObject(ctx)));
    return FALSE;
}
