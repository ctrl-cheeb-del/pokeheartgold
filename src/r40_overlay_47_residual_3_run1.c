#include "r40_overlay_47_residual_3_private.h"

void ov47_02258BB4(void *arg, int heapId) {
    u8 *work = arg;
    int i;
    u32 offset;
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7E, 0, 0x1F, 0, 0x7E, 0, 0x1F, heapId);
    ObjCharTransfer_InitEx(ov47_02259E58, 0x10, 0x10);
    ObjPlttTransfer_Init(0x20, heapId);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    G2dRenderer_SetObjCharTransferReservedRegion(1, 0x10);
    G2dRenderer_SetPlttTransferReservedRegion(1);
    *(void **)(work + 4) = G2dRenderer_Init(0x20, work + 8, heapId);
    offset = 0x130;
    for (i = 0; i < 4; i++) {
        *(void **)(work + offset) = Create2DGfxResObjMan(0x20, i, heapId);
        work += 4;
    }
    sub_0203A880();
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}
