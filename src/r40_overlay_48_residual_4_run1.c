#include "r40_overlay_48_residual_4_private.h"

void ov48_02259650(void *p) {
    int i;

    for (i = 0; i < 5; i++) {
        FreeBgTilemapBuffer(PTRAT(p, 0), ov48_0225B1B0[i]);
    }
    Heap_Free(PTRAT(p, 0));
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
}

void ov48_02259688(void *p, u32 heapId) {
    int i;
    u32 offset;

    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7E, 0, 0x1F, 0, 0x7E, 0, 0x1F, heapId);
    ObjCharTransfer_InitEx(ov48_0225B1A0, 0x10, 0x10);
    ObjPlttTransfer_Init(0x20, heapId);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    G2dRenderer_SetObjCharTransferReservedRegion(1, 0x10);
    G2dRenderer_SetPlttTransferReservedRegion(1);
    PTRAT(p, 4) = G2dRenderer_Init(0x20, ADD(p, 8), heapId);
    G2dRenderer_SetSubSurfaceCoords(ADD(p, 8), 0, 1 << 20);
    offset = 0x130;
    for (i = 0; i < 4; i++) {
        PTRAT(p, offset) = Create2DGfxResObjMan(0x20, i, heapId);
        p = ADD(p, 4);
    }
    sub_0203A880();
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}
