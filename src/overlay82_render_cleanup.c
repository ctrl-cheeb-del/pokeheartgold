#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "palette.h"
#include "unk_0200B150.h"
#include "vram_transfer_manager.h"

extern void DoScheduledBgGpuUpdates(BgConfig *bgConfig);

typedef struct Ov82Work {
    u32 unk0;
    u32 paused;
    u8 pad08[0x40];
    BgConfig *bgConfig;
    u8 pad4C[0x48];
    PaletteData *paletteData;
} Ov82Work;

void ov82_0223EBB8(BgConfig *bgConfig);
void ov82_0223EC0C(Ov82Work *work);

void ov82_0223EBB8(BgConfig *bgConfig) {
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    GfGfx_EngineATogglePlanes(0x1F, FALSE);
    GfGfx_EngineBTogglePlanes(0x1F, FALSE);
    FreeBgTilemapBuffer(bgConfig, 3);
    FreeBgTilemapBuffer(bgConfig, 1);
    FreeBgTilemapBuffer(bgConfig, 0);
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 4);
    Heap_Free(bgConfig);
}

void ov82_0223EC0C(Ov82Work *work) {
    if (work->paused == 0) {
        if (work->paletteData != NULL) {
            PaletteData_PushTransparentBuffers(work->paletteData);
        }
        DoScheduledBgGpuUpdates(work->bgConfig);
        GF_RunVramTransferTasks();
        OamManager_ApplyAndResetBuffers();
        ((vu32 *)SDK_AUTOLOAD_DTCM_START)[0xFFE] |= 1;
    }
}
