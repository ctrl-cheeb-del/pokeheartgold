#include "to45_overlay80_battle_record_r17_private.h"

BOOL FrtCmd_109(void *context) {
    void *state = PTR_AT(context, 0);
    u32 type = FrontierScriptContext_ReadHalfWord(context);
    u32 value = FrontierScript_ReadVar(context);
    u32 amount = FrontierScript_ReadVar(context);
    u16 *result = FrontierScript_ReadVarPtr(context);

    if (amount > 9999) {
        amount = 9999;
    }
    U16_AT(state, 0xB0) = 0;
    U16_AT(state, 0xB2) = 0;
    U16_AT(state, 0xB4) = ov80_0222CC70(type, value);
    U16_AT(state, 0xB6) = amount;
    PTR_AT(state, 0xB8) = result;
    FrontierScriptContext_Pause(context, ov80_0222CC20);
    return TRUE;
}

BOOL ov80_0222CC20(void *context) {
    void *state = PTR_AT(context, 0);
    void *args = Frontier_GetLaunchArgs(PTR_AT(state, 0));
    int result = sub_0202FE14(
        PTR_AT(args, 8),
        U16_AT(state, 0xB4),
        U16_AT(state, 0xB6),
        0,
        (u16 *)((u8 *)state + 0xB0),
        (u16 *)((u8 *)state + 0xB2));

    if ((u32)(result - 2) <= 1) {
        *(u16 *)PTR_AT(state, 0xB8) = result == 2;
        return TRUE;
    }
    return FALSE;
}
