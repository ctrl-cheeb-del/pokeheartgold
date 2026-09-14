#include "to45_overlay80_battle_record_r17_private.h"

BOOL FrtCmd_110(void *context) {
    void *args = Frontier_GetLaunchArgs(PTR_AT(PTR_AT(context, 0), 0));
    void *battleSetup = Heap_Alloc(11, 0x1D4);
    int result;

    MI_CpuFill8(battleSetup, 0, 0x1D4);
    sub_0202FC90(PTR_AT(args, 8), 11, &result, battleSetup, 0);
    Sound_SetSceneAndPlayBGM(5, 0x45D, 1);
    Frontier_LaunchApplication(PTR_AT(PTR_AT(context, 0), 0), gOverlayTemplate_Battle, battleSetup, 1, NULL);
    return TRUE;
}
