#include "frontier_map_helpers_internal.h"

void FrontierMap_VBlank(FrontierMap *m) {
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    PaletteData_PushTransparentBuffers(m->plttData);
    DoScheduledBgGpuUpdates(m->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

void ov80_02238AAC(void) {
}

void ov80_02238AB0(u32 a0, FrontierMap *m) {
#pragma unused(a0)
    ov42_0222807C(m->unk14);
}

void ov80_02238ABC(u32 a0, FrontierMap *m) {
#pragma unused(a0)
    ov80_02238C78(m);
}
