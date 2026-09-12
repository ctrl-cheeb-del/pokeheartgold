#include "overlay49_menu_graphics_private.h"

void ov49_0225A840(void *work) {
    DoScheduledBgGpuUpdates(PTR_AT(work, 0));
    OamManager_ApplyAndResetBuffers();
    GF_RunVramTransferTasks();
}
