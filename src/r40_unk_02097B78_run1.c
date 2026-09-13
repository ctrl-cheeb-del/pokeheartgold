#include "global.h"

#include "r40_unk_02097B78_private.h"

static int (*const sLegendaryCinematicScripts[])(void *) = {
    ScriptCinematic_HoOh,
    ScriptCinematic_Lugia,
    ScriptCinematic_Arceus,
};

BOOL LegendaryCinematic_Init(OverlayManager *man, int *state) {
    LegendaryCinematicData *data;

    Heap_Create(HEAP_ID_3, HEAP_ID_153, 0x80000);
    data = OverlayManager_CreateAndGetData(man, sizeof(LegendaryCinematicData), HEAP_ID_153);
    MI_CpuFill8(data, 0, sizeof(LegendaryCinematicData));
    data->args = OverlayManager_GetArgs(man);
    return TRUE;
}

BOOL LegendaryCinematic_Main(OverlayManager *man, int *state) {
    LegendaryCinematicData *data = OverlayManager_GetData(man);

    return !sLegendaryCinematicScripts[data->args->unk4C](data);
}

BOOL LegendaryCinematic_Exit(OverlayManager *man, int *state) {
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_153);
    return TRUE;
}
